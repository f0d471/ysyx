#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdint>
#include <cassert>

#include "Vtop.h" 
#include "config.h"

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

// 寄存器接口
void isa_reg_display(); 
uint32_t isa_reg_str2val(const char *s, bool *success); 

// ================= 内存配置宏 =================
#define CONFIG_MSIZE 0x8000000  // 128MB 
#define CONFIG_MBASE 0x80000000

// ================= 内存接口声明 =================
void init_mem();
void load_bin(const char *bin_file);

// 供 SDB 使用的 C 环境接口
uint32_t pmem_read(uint32_t addr, int len);
void pmem_write(uint32_t addr, int len, uint32_t data);

// 供 DPI-C 调用的硬件接口
extern "C" void trap(int code, int pc);
extern "C" uint32_t paddr_read(uint32_t addr);
extern "C" void paddr_write(uint32_t addr, int len, uint32_t data);

// sdb 
#ifdef CONFIG_SDB
void init_sdb();
void sdb_mainloop();
#endif

// difftest
#ifdef CONFIG_DIFFTEST

struct DiffContext {
    uint32_t gpr[16]; 
    uint32_t pc;
};

void difftest_init(const char *so_file);
void difftest_memcpy(uint32_t addr, void *buf, size_t n, int direction);
void difftest_regcpy(void *dut, int direction);
void difftest_step();
#endif

#ifdef CONFIG_ITRACE
extern "C" void init_disasm();
extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
void init_trace(const char *filename);
void trace_close();
void log_itrace();
#endif

#ifdef CONFIG_MTRACE
void init_trace(const char *filename);
void trace_close();
void log_mtrace(uint32_t addr, uint32_t data, int len, int is_write);
#endif


#endif // __COMMON_H__