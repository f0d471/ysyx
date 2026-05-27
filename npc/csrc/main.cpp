#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include <cstdio>
#include <cstdint>
#include <SDL2/SDL.h>

#include "common.h"
#include "config.h"

void send_key(uint8_t scancode, bool is_keydown);
void vga_update_screen();

static void device_update() {
  static uint64_t last = 0;
  uint64_t now = sim_time;
  if (now - last < 1000) return;
  last = now;

  vga_update_screen();

  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        npc_state = NPC_END;
        Verilated::gotFinish(true);
        break;
      case SDL_KEYDOWN:
      case SDL_KEYUP: {
        uint8_t k = event.key.keysym.scancode;
        bool is_keydown = (event.key.type == SDL_KEYDOWN);
        send_key(k, is_keydown);
        break;
      }
      default: break;
    }
  }
}

// 全局变量
Vtop* top = nullptr;
VerilatedVcdC* tfp = nullptr;
uint64_t sim_time = 0;
const char *img_file = NULL;
NPCState npc_state = NPC_STOP;

// 时钟
static void single_cycle() {
    top->clk = 0;
    top->eval();
    if (tfp) tfp->dump(sim_time);
    sim_time++;

    top->clk = 1;
    top->eval();
    if (tfp) tfp->dump(sim_time);
    sim_time++;
}

// 复位
static void reset(int n) {
    top->rst_n = 0;
    while (n-- > 0) {
        top->clk = 0; 
        top->eval(); 
        if (tfp) tfp->dump(sim_time++);

        top->clk = 1; 
        top->eval(); 
        if (tfp) tfp->dump(sim_time++);
    }
    top->rst_n = 1;
}

// =================== DPI-C: Trap =================== //
extern "C" void trap(int code, int pc) {
    if (code == 0) {
        printf("\33[1;32mHIT GOOD TRAP\33[0m at pc = 0x%08x\n", pc);
    } else {
        printf("\33[1;31mHIT BAD TRAP\33[0m at pc = 0x%08x, code = %d\n", pc, code);
    }
    npc_state = NPC_END; 
    Verilated::gotFinish(true);
}

void init_sim(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <bin_file>\n", argv[0]);
        exit(1);
    }
    img_file = argv[1];

    // 初始化 基础环境
    Verilated::commandArgs(argc, argv);
    top = new Vtop;

    // 初始化外设
    #ifdef CONFIG_DEVICE
      init_device();
    #endif

    // 初始化 内存 & 加载程序
    init_mem();
    load_bin(img_file);

    // 初始化 波形
    #ifdef CONFIG_WAVE
      Verilated::traceEverOn(true);
      tfp = new VerilatedVcdC;
      top->trace(tfp, 99);
      tfp->open("wave.vcd");
      printf("VCD Waveform enabled.\n");
    #endif

    // 初始化 踪迹
    #if defined(CONFIG_ITRACE) || defined(CONFIG_MTRACE) || defined(CONFIG_DTRACE)
      init_trace("npc-trace.txt");
    #endif

    // 初始化 反汇编库
    #ifdef CONFIG_ITRACE
      init_disasm(); 
    #endif
    
    // 初始化 ftrace 
    #ifdef CONFIG_FTRACE
      char elf_file[256];
      strncpy(elf_file, img_file, sizeof(elf_file));
      char *ext = strrchr(elf_file, '.');
      if (ext && strcmp(ext, ".bin") == 0) {
          strcpy(ext, ".elf"); // 魔术：把 .bin 强行改成 .elf
      }
      init_ftrace(elf_file);
    #endif

    // 初始化 difftest
    #ifdef CONFIG_DIFFTEST
      // 加载 NEMU 的动态库
      difftest_init("/home/normal/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so");
      // 把 NPC 的内存数据同步给 NEMU , direction = 1 表示从 NPC 复制到 NEMU
      difftest_memcpy(0x80000000, guest_to_host(0x80000000), CONFIG_MSIZE, 1);   
    #endif

    // 复位
    reset(10);

    // 调用difftest
    #ifdef CONFIG_DIFFTEST
      DiffContext ctx;
      for (int i = 0; i < 16; i++) ctx.gpr[i] = top->regs[i]; 
      ctx.pc = top->pc;  // 此时 top->pc 应该是正确的复位地址 (例如 0x80000000)
      difftest_regcpy(&ctx, 1); 
    #endif
}

void npc_quit() {
    // 打印仿真结果
    if (npc_state == NPC_END) {
        printf(ANSI_FG_GREEN "Simulation Ended: HIT GOOD TRAP\n" ANSI_NONE);
    } else if (npc_state == NPC_ABORT) {
        printf(ANSI_FG_RED "Simulation Aborted: HIT BAD TRAP\n" ANSI_NONE);
    } else {
        printf("Simulation Exited by User.\n");
    }

    // 强制刷新并关闭波形文件
    #ifdef CONFIG_WAVE
        if (tfp) {
            tfp->flush(); 
            tfp->close();
            delete tfp;
            tfp = nullptr;
        }
    #endif

    // 释放 Verilator 顶层对象
    if (top) {
        delete top;
        top = nullptr;
    }

    SDL_Quit();

    // 根据状态返回给操作系统不同的退出码
    if (npc_state == NPC_END) {
        exit(0);
    } else {
        exit(1);
    }
}

void cpu_exec(uint64_t n) {
    if (npc_state == NPC_END || npc_state == NPC_ABORT) {
        printf("Program execution has ended. Restart NPC to run again.\n");
        return;
    }

    npc_state = NPC_RUNNING;
    uint64_t executed = 0;

    while (!Verilated::gotFinish() && executed < n) { 

        single_cycle(); 

        if (top->debug_wb_have) {
            uint32_t cpc   = top->debug_wb_pc;
            uint32_t cinst = top->debug_wb_instr;

            #ifdef CONFIG_ITRACE
            {
                char asm_buf[128];
                disassemble(asm_buf, sizeof(asm_buf), cpc, 
                           (uint8_t *)&cinst, 4);
                TRACE_LOG("[itrace] 0x%08x: 0x%08x  %s\n", 
                         cpc, cinst, asm_buf);
            }
            #endif

            #ifdef CONFIG_FTRACE
            {
                static uint32_t last_pc = 0, last_inst = 0;
                static bool has_last = false;
                if (has_last) {
                    do_ftrace(last_pc, cpc, last_inst);
                }
                last_pc = cpc;
                last_inst = cinst;
                has_last = true;
            }
            #endif

            #ifdef CONFIG_DIFFTEST
              if (difftest_skip) {
                  DiffContext ctx;
                  for (int i = 0; i < 16; i++) ctx.gpr[i] = top->regs[i]; 
                  ctx.pc = top->pc;
                  difftest_regcpy(&ctx, 1);
                  difftest_skip = false;
              } else {
                  difftest_step(cpc);
              }
            #endif

            executed++;
        }

        if (npc_state != NPC_RUNNING) break;

        device_update();
    }

    if (Verilated::gotFinish()) {
        npc_state = NPC_END;
    } 
    else if (npc_state == NPC_RUNNING) {
        npc_state = NPC_STOP; 
    }
}

int main(int argc, char **argv) {
    init_sim(argc, argv);

    #ifdef CONFIG_SDB
        init_sdb();
        sdb_mainloop(); 
    #else
        cpu_exec(-1);
    #endif

    npc_quit();
    return 0;
}