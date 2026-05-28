#ifndef __ITRACE_H__
#define __ITRACE_H__

#include <cstdint>
#include "config.h"

#ifdef CONFIG_ITRACE

extern "C" void init_disasm();
extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

void log_itrace();
void iringbuf_dump();

#endif
#endif
