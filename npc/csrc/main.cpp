#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <string>

#include "common.h"

// 全局变量
Vtop* top = nullptr;
VerilatedVcdC* tfp = nullptr;
uint64_t sim_time = 0;
const char *img_file = NULL;
NPCState npc_state = NPC_STOP;

// 批处理模式（命令行 -b）：跑完即退出，不进入交互式 sdb，供无人值守的批量回归使用
static bool batch_mode = false;
// 客户程序通过 ebreak 传回的退出码，决定进程的退出状态
static int halt_ret = 0;

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

//  DPI-C: Trap  
extern "C" void trap(int code, int pc) {
    if (code == 0) {
        printf(ANSI_FG_GREEN "HIT GOOD TRAP" ANSI_NONE " at pc = 0x%08x\n", pc);
    } else {
        printf(ANSI_FG_RED "HIT BAD TRAP" ANSI_NONE " at pc = 0x%08x, code = %d\n", pc, code);
    }
    // 必须按 code 区分：此处原本无条件置 NPC_END，导致 BAD TRAP 也被记成正常结束，
    // npc_quit() 随后打印 "HIT GOOD TRAP"，批量回归也就永远是 PASS
    halt_ret = code;
    npc_state = (code == 0) ? NPC_END : NPC_ABORT;
    Verilated::gotFinish(true);
}

//  初始化  
void init_sim(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-b") == 0) batch_mode = true;
        else if (img_file == NULL)      img_file = argv[i];
    }
    if (img_file == NULL) {
        fprintf(stderr, "Usage: %s <bin_file> [-b]\n", argv[0]);
        exit(1);
    }

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
    #if defined(CONFIG_ITRACE) || defined(CONFIG_MTRACE) || defined(CONFIG_DTRACE) || defined(CONFIG_FTRACE)
      init_trace("npc-trace.txt");
    #endif

    // 初始化 反汇编库
    #ifdef CONFIG_ITRACE
      init_disasm();
    #endif

    // 初始化 ftrace
    #ifdef CONFIG_FTRACE
      std::string elf_path(img_file);
      size_t dot = elf_path.rfind('.');
      if (dot != std::string::npos && elf_path.substr(dot) == ".bin") {
          elf_path.replace(dot, 4, ".elf");
      }
      init_ftrace(elf_path.c_str());
    #endif

    // 初始化 difftest
    #ifdef CONFIG_DIFFTEST
      difftest_init("/home/normal/ysyx-workbench/npc/csrc/difftest/riscv32-nemu-interpreter-so");
      difftest_memcpy(0x80000000, guest_to_host(0x80000000), img_size, 1);
    #endif

    // 复位
    reset(10);

    // 调用difftest
    #ifdef CONFIG_DIFFTEST
      DiffContext ctx;
      for (int i = 0; i < 16; i++) ctx.gpr[i] = top->debug_regs[i];
      ctx.pc = CONFIG_MBASE;
      difftest_regcpy(&ctx, 1);
    #endif
}

//  退出  
void npc_quit() {
    if (npc_state == NPC_END) {
        printf(ANSI_FG_GREEN "Simulation Ended: HIT GOOD TRAP\n" ANSI_NONE);
    } else if (npc_state == NPC_ABORT) {
        printf(ANSI_FG_RED "Simulation Aborted: HIT BAD TRAP\n" ANSI_NONE);
    } else {
        printf("Simulation Exited by User.\n");
    }

    #ifdef CONFIG_WAVE
        if (tfp) {
            tfp->flush();
            tfp->close();
            delete tfp;
            tfp = nullptr;
        }
    #endif

    if (top) {
        delete top;
        top = nullptr;
    }

    #ifdef CONFIG_DEVICE
      device_exit();
    #endif

    trace_close();

    if (npc_state == NPC_END) {
        exit(0);
    } else {
        exit(1);
    }
}

//  主执行循环  
void cpu_exec(uint64_t n) {
    if (npc_state == NPC_END || npc_state == NPC_ABORT) {
        printf("Program execution has ended. Restart NPC to run again.\n");
        return;
    }

    npc_state = NPC_RUNNING;
    uint64_t executed = 0;

    while (!Verilated::gotFinish() && executed < n) {

        single_cycle();

        if (top->debug_have) {
            uint32_t commit_pc   = top->debug_pc;
            uint32_t commit_inst = top->debug_instr;

            #ifdef CONFIG_ITRACE
              log_itrace();
            #endif

            #ifdef CONFIG_FTRACE
              ftrace_on_commit(commit_pc, commit_inst);
            #endif

            #ifdef CONFIG_DIFFTEST
              difftest_commit(commit_pc, top->debug_regs);
            #endif

            executed++;
        }

        if (npc_state != NPC_RUNNING) break;

        #ifdef CONFIG_DEVICE
          device_poll();
        #endif
    }

    // trap() 可能已把状态定性为 END 或 ABORT，这里不能覆盖它——原写法一律置
    // NPC_END，是 BAD TRAP 被抹平的第二处
    if (npc_state == NPC_RUNNING) {
        npc_state = Verilated::gotFinish() ? NPC_END : NPC_STOP;
    }
}

// 与 NEMU 的 is_exit_status_bad() 同一套判据：只有"正常结束且退出码为 0"才算成功。
// 用户从 sdb 主动退出(NPC_STOP)不算失败——此时无从判断被测程序的对错。
static int is_exit_status_bad() {
    int good = (npc_state == NPC_END && halt_ret == 0) || (npc_state == NPC_STOP);
    return !good;
}

int main(int argc, char **argv) {
    init_sim(argc, argv);

    #ifdef CONFIG_SDB
        init_sdb();
        if (batch_mode) cpu_exec(-1);
        else            sdb_mainloop();
    #else
        cpu_exec(-1);
    #endif

    npc_quit();
    // 必须把结果反映到进程退出码上，否则上层的批量回归无从判断 PASS/FAIL
    return is_exit_status_bad();
}
