#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdint>
#include <cassert>

#include "Vtop.h"
#include "config.h"

// ANSI 颜色
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_NONE       "\33[0m"

// NPC 运行状态机
enum NPCState {
    NPC_RUNNING,
    NPC_STOP,
    NPC_END,
    NPC_ABORT
};

// 全局变量声明
extern Vtop* top;
extern NPCState npc_state;
extern uint64_t sim_time;

// 核心仿真控制
void npc_quit();
void cpu_exec(uint64_t n);

// DPI-C trap（Verilog 侧调用）
extern "C" void trap(int code, int pc);

// ============ 子系统头文件 ============
#include "memory/memory.h"
#include "device/device.h"
#include "isa/isa.h"
#include "utils/utils.h"
#include "sdb/sdb.h"
#include "difftest/difftest.h"

#endif // __COMMON_H__
