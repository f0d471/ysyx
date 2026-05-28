#ifndef __DIFFTEST_H__
#define __DIFFTEST_H__

#include <cstdint>
#include "config.h"

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
#endif
