/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
* http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

#ifdef CONFIG_IRINGBUF

  #define IRB_N 128
  typedef struct {
    vaddr_t pc;
    uint32_t inst;
    char disasm[128];
  } IRBEntry;

  static IRBEntry irb[IRB_N];
  static int irb_head = 0;
  static int irb_cnt  = 0;

  static inline void irb_record(vaddr_t pc, uint32_t inst, const char *disasm) {
    IRBEntry *e = &irb[irb_head];
    e->pc   = pc;
    e->inst = inst;
    // 安全复制，防止溢出
    snprintf(e->disasm, sizeof(e->disasm), "%.*s", (int)sizeof(e->disasm)-1, disasm);
    irb_head = (irb_head + 1) % IRB_N;
    if (irb_cnt < IRB_N) irb_cnt++;
  }

  static void irb_dump(vaddr_t bad_pc) {
    if (irb_cnt == 0) return;
    int start = (irb_head - irb_cnt + IRB_N) % IRB_N;
    
    TRACE_LOG("----- recent %d instructions (IRingBuf) -----\n", irb_cnt);
    for (int i = 0; i < irb_cnt; i++) {
      IRBEntry *e = &irb[(start + i) % IRB_N];
      // 标记出错的那条指令
      const char *mark = (e->pc == bad_pc) ? "-->" : "   ";
      // 注意：TRACE_LOG 内部用的是 fprintf，所以末尾必须自己加上 \n
      TRACE_LOG("%s " FMT_WORD ": %08x %s\n", mark, e->pc, e->inst, e->disasm);
    }
    TRACE_LOG("----- end IRingBuf dump -----\n");
  }

#endif // CONFIG_IRINGBUF

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { 
    TRACE_LOG("[ITRACE] %s\n", _this->logbuf); 
  }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
}

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst;
#ifdef CONFIG_ISA_x86
  for (i = 0; i < ilen; i ++) {
#else
  for (i = ilen - 1; i >= 0; i --) {
#endif
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst, ilen);
#endif
#ifdef CONFIG_IRINGBUF
  // 如果 ITRACE 已经算好了，就直接抄；否则自己算一遍。
  #ifdef CONFIG_ITRACE
    // 情况 A: ITRACE 开了，直接复用 logbuf，省性能
    irb_record(s->pc, s->isa.inst, s->logbuf);
  #else
    // 情况 B: ITRACE 没开，我们需要自己反汇编（这是必须的代价）
    char temp_buf[128];
    char *p_irb = temp_buf;
    p_irb += snprintf(p_irb, 128, FMT_WORD ":", s->pc);
    
    int ilen_irb = s->snpc - s->pc;
    uint8_t *inst_irb = (uint8_t *)&s->isa.inst;
    for (int i = ilen_irb - 1; i >= 0; i --) {
      p_irb += snprintf(p_irb, 4, " %02x", inst_irb[i]);
    }
    int space_len_irb = (4 - ilen_irb) * 3 + 1; // 简化处理，假设 max=4
    if (space_len_irb > 0) {
      memset(p_irb, ' ', space_len_irb);
      p_irb += space_len_irb;
    }

    void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
    disassemble(p_irb, temp_buf + 128 - p_irb, 
        MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst, ilen_irb);
    
    irb_record(s->pc, s->isa.inst, temp_buf);
  #endif
#endif
}

static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT: case NEMU_QUIT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);

      #ifdef CONFIG_IRINGBUF
        irb_dump(nemu_state.halt_pc);
      #endif

      // fall through
    case NEMU_QUIT: statistic();
  }
}