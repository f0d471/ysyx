#ifndef __UTILS_H__
#define __UTILS_H__

#include <cstdint>
#include "config.h"

// ==================== trace 共享接口 ====================
void init_trace(const char *filename);
void trace_close();

// iringbuf — I/M/D 三个 trace 共用的环形缓冲区
void iringbuf_push(const char *fmt, ...);

// ==================== itrace ====================
#ifdef CONFIG_ITRACE
extern "C" void init_disasm();
extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
void log_itrace();
#endif

// ==================== mtrace ====================
#ifdef CONFIG_MTRACE
void log_mtrace(uint32_t addr, uint32_t data, int is_write);
#endif

// ==================== dtrace ====================
#ifdef CONFIG_DTRACE
void log_dtrace(char type, uint32_t addr, int len, uint32_t data);
#endif

// ==================== ftrace ====================
#ifdef CONFIG_FTRACE
void init_ftrace(const char *elf_file);
void ftrace_on_commit(uint32_t pc, uint32_t inst);
void ftrace_buf_flush(FILE *fp);
#endif

#endif
