#ifndef ARCH_H__
#define ARCH_H__

#ifdef __riscv_e
#define NR_REGS 16
#else
#define NR_REGS 32
#endif

struct Context {
  // [Fix] 调整顺序以匹配 trap.S 的压栈顺序
  // 1. gpr[NR_REGS] 放在最前面 (Offset: 0 ~ 31*4)
  uintptr_t gpr[NR_REGS]; 
  
  // 2. 紧接着是 mcause, mstatus, mepc (Offset: 32*4, 33*4, 34*4)
  uintptr_t mcause, mstatus, mepc; 
  
  void *pdir; // 地址空间指针 (DiffTest 用，通常放在最后)
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
