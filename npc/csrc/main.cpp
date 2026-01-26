#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include <cstdio>
#include <cstdint>

#include "common.h"
#include "config.h"

// 全局变量
Vtop* top = nullptr;
VerilatedVcdC* tfp = nullptr;
uint64_t sim_time = 0;
NPCState npc_state = NPC_STOP;

// 时钟
static void single_cycle() {
    top->clk = 0; 
    top->eval();
    if (tfp) tfp->dump(sim_time++);

    top->clk = 1; 
    top->eval();
    if (tfp) tfp->dump(sim_time++);
}

// 复位
static void reset(int n) {
    top->rst = 1;
    while (n-- > 0) {
        top->clk = 0; 
        top->eval(); 
        if (tfp) tfp->dump(sim_time++);

        top->clk = 1; 
        top->eval(); 
        if (tfp) tfp->dump(sim_time++);
    }
    top->rst = 0;
}

void init_sim(int argc, char** argv) {
    // 基础环境初始化
    Verilated::commandArgs(argc, argv);
    top = new Vtop;

    // 初始化波形
    #ifdef CONFIG_WAVE
        Verilated::traceEverOn(true);
        tfp = new VerilatedVcdC;
        top->trace(tfp, 99);
        tfp->open("wave.vcd");
        printf("VCD Waveform enabled.\n");
    #endif

    // 硬件复位
    reset(10);
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
    // --- ITRACE ---
    #ifdef CONFIG_ITRACE
        log_itrace(); 
    #endif

    single_cycle(); 

    // --- DIFFTEST ---
    #ifdef CONFIG_DIFFTEST
        difftest_step();
    #endif

    executed++;
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