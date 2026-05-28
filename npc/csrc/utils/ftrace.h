#ifndef __FTRACE_H__
#define __FTRACE_H__

#include <cstdint>
#include <cstdio>
#include "config.h"

#ifdef CONFIG_FTRACE

void init_ftrace(const char *elf_file);
void ftrace_on_commit(uint32_t pc, uint32_t inst);
void ftrace_buf_flush(FILE *fp);

#endif
#endif
