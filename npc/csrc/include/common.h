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

#ifdef CONFIG_SDB
  #include "sdb/sdb.h"
  void init_sdb();
  void sdb_mainloop();
#endif

#ifdef CONFIG_DIFFTEST
struct DiffContext {
    uint32_t gpr[16];
    uint32_t pc;
};

void difftest_init(const char *so_file);
void difftest_memcpy(uint32_t addr, void *buf, size_t n, int direction);
void difftest_regcpy(void *dut, int direction);
void difftest_skip_ref();
void difftest_commit(uint32_t commit_pc, uint32_t *regs);
#endif

#endif // __COMMON_H__
