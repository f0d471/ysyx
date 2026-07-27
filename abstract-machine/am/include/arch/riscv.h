#ifndef ARCH_H__
#define ARCH_H__

#ifdef __riscv_e
#define NR_REGS 16
#else
#define NR_REGS 32
#endif

// 陷入时保存的现场。布局必须与 am/src/riscv/trap.S 里的 OFFSET_* 保持一致。
//
// pdir 与 gpr[0] 共用同一个槽位是有意为之：gpr[0] 对应 x0，而 RISC-V 的 x0 恒为零、
// 永远不需要保存，trap.S 的寄存器列表也确实是从 f(1) 开始的。于是这个槽位空着，
// 正好借给页目录指针用，省下一个字。改动此结构时务必同步 trap.S 的 CONTEXT_SIZE。
struct Context {
  union {
    void *pdir;
    uintptr_t gpr[NR_REGS];
  };
  uintptr_t mcause, mstatus, mepc;
};

#ifdef __riscv_e
#define GPR1 gpr[15] // a5
#else
#define GPR1 gpr[17] // a7
#endif

#define GPR2 gpr[0]
#define GPR3 gpr[0]
#define GPR4 gpr[0]
#define GPRx gpr[0]

#endif
