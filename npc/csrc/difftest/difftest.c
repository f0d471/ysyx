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

// ★★★ 多周期版本的 difftest_step ★★★
// 改动：
//   1. 接收 commit_pc 参数（提交指令的 PC），用于定位出错位置
//   2. 不再比较 top->pc（那是 IF 级 PC，流水线中领先提交好几拍）
//   3. 只比较 GPR（寄存器堆在 WB 写回后，是"已提交"的架构状态）
//   4. 可选：用 commit_pc 与 NEMU 执行前的 PC 做同步校验
void difftest_step(uint32_t commit_pc) {
  // ★ 可选：在 NEMU 执行前，检查 NEMU 的 PC 是否和 DUT commit_pc 一致
  //   如果不一致，说明两边的执行序列已经分叉
  DiffContext ref_before;
  difftest_regcpy(&ref_before, false);  // direction=false: 从 NEMU 读出
  if (ref_before.pc != commit_pc) {
    printf("[DiffTest] PC sync error! DUT committing pc=0x%08x, "
           "but NEMU is at pc=0x%08x\n", commit_pc, ref_before.pc);
    npc_state = NPC_ABORT; 
    npc_quit();
  }
 
  // 让 NEMU 执行一条指令
  difftest_exec(1);
 
  // 读出 NEMU 执行后的状态
  DiffContext ref;
  difftest_regcpy(&ref, false); 
 
  // ★ 比较 GPR（DUT 的 regs 是 WB 写回后的架构状态）
  for (int i = 0; i < 16; i++) {
    if (top->regs[i] != ref.gpr[i]) {
      printf("[DiffTest] Reg x%d mismatch: DUT=0x%08x REF=0x%08x "
             "at commit_pc=0x%08x\n",
             i, top->regs[i], ref.gpr[i], commit_pc);
      npc_state = NPC_ABORT; 
      npc_quit();
    }
  }
 
  // ★ 注意：这里不再比较 top->pc 和 ref.pc
  //   因为 top->pc 是 IF 级的 PC（已经跑到后面好几条了），
  //   而 ref.pc 是 NEMU 的下一条要执行的 PC。
  //   两者在流水线中不同步是正常的。
  //   如果需要比较 PC，应该在下一次 commit 时检查 commit_pc == ref.pc
  //   （就是上面 ref_before.pc 的检查做的事情）
}

#endif