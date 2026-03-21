#include "common.h"

#ifdef CONFIG_DIFFTEST

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

static void (*ref_memcpy)(uint32_t addr, void *buf, size_t n, int direction) = NULL;
static void (*ref_regcpy)(void *dut, int direction) = NULL;
static void (*ref_exec)(uint64_t n) = NULL;
static void (*ref_raise_intr)(int NO) = NULL;
static void *handle = NULL;

void difftest_init(const char *so_file) {
  handle = dlopen(so_file, RTLD_NOW);
  if (!handle) {
    fprintf(stderr, "dlopen error: %s\n", dlerror());
    npc_state = NPC_ABORT; 
    npc_quit();  }

  ref_memcpy     = (void (*)(uint32_t, void*, size_t, int)) dlsym(handle, "difftest_memcpy");
  ref_regcpy     = (void (*)(void*, int))                   dlsym(handle, "difftest_regcpy");
  ref_exec       = (void (*)(uint64_t))                     dlsym(handle, "difftest_exec");
  ref_raise_intr = (void (*)(int))                          dlsym(handle, "difftest_raise_intr");

  if (!ref_memcpy || !ref_regcpy || !ref_exec) {
    fprintf(stderr, "dlsym error\n");
    npc_state = NPC_ABORT; 
    npc_quit();  }

  printf("DiffTest REF loaded: %s\n", so_file);
}

void difftest_memcpy(uint32_t addr, void *buf, size_t n, int direction) {
  ref_memcpy(addr, buf, n, direction);
}

void difftest_regcpy(void *dut, int direction) {
  ref_regcpy(dut, direction);
}

void difftest_exec(uint64_t n) {
  ref_exec(n);
}

bool difftest_skip = false;
void difftest_skip_ref() {
  difftest_skip = true;
}

void difftest_step(uint32_t commit_pc) {
  // 执行前校验：NEMU 的 PC 应该和 DUT 提交的 PC 一致
  DiffContext ref_before;
  difftest_regcpy(&ref_before, false);
  if (ref_before.pc != commit_pc) {
    printf("[DiffTest] PC sync error! DUT commit_pc=0x%08x, "
           "NEMU pc=0x%08x\n", commit_pc, ref_before.pc);
    npc_state = NPC_ABORT; 
    npc_quit();
  }
 
  // 让 NEMU 执行一条指令
  difftest_exec(1);
 
  // 比较 GPR
  DiffContext ref;
  difftest_regcpy(&ref, false); 
  for (int i = 0; i < 16; i++) {
    if (top->regs[i] != ref.gpr[i]) {
      printf("[DiffTest] Reg x%d mismatch: DUT=0x%08x REF=0x%08x "
             "at commit_pc=0x%08x\n",
             i, top->regs[i], ref.gpr[i], commit_pc);
      npc_state = NPC_ABORT; 
      npc_quit();
    }
  }
  // ★ 不比较 top->pc（IF 级 PC ≠ 提交 PC）
  // PC 同步性在下一次 commit 的 ref_before 检查中隐式保证
}

#endif