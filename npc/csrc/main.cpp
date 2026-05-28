#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include <cstdio>
#include <cstdint>
#include <string>

#include "common.h"

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

//  DPI-C: Trap  
extern "C" void trap(int code, int pc) {
    if (code == 0) {
        printf(ANSI_FG_GREEN "HIT GOOD TRAP" ANSI_NONE " at pc = 0x%08x\n", pc);
    } else {
        printf(ANSI_FG_RED "HIT BAD TRAP" ANSI_NONE " at pc = 0x%08x, code = %d\n", pc, code);
    }
    npc_state = NPC_END;
    Verilated::gotFinish(true);
}

//  初始化  
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
      std::string elf_path(img_file);
      size_t dot = elf_path.rfind('.');
      if (dot != std::string::npos && elf_path.substr(dot) == ".bin") {
          elf_path.replace(dot, 4, ".elf");
      }
      init_ftrace(elf_path.c_str());
    #endif

    // 初始化 difftest
    #ifdef CONFIG_DIFFTEST
      difftest_init("/home/normal/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so");
      difftest_memcpy(0x80000000, guest_to_host(0x80000000), CONFIG_MSIZE, 1);
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
