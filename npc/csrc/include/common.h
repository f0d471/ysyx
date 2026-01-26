#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdint>
#include <cassert>
#include "Vtop.h" 

// 颜色
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_NONE       "\33[0m"

// NPC 运行状态机 
enum NPCState {
    NPC_RUNNING, // 运行
    NPC_STOP,    // 暂停
    NPC_END,     // 正常结束 
    NPC_ABORT    // 异常结束 
};

// 仿真收尾 
void npc_quit();

// 全局变量声明 
extern Vtop* top;
extern NPCState npc_state;
extern uint64_t sim_time;

// 核心仿真控制 
void cpu_exec(uint64_t n); 

// 内存与寄存器接口 
uint32_t pmem_read(uint32_t addr, int len); 
void isa_reg_display(Vtop* top);

// SDB 
void init_sdb();
void sdb_mainloop();

#endif // __COMMON_H__