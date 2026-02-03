#include "common.h"

#ifdef CONFIG_SDB

#include <cstdio>
#include <cstring>


const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"
};

// 打印所有寄存器的值
void isa_reg_display() {
  printf("General Purpose Registers:\n");
  for (int i = 0; i < 16; i++) {
    printf("%-4s: 0x%08x  ", regs[i], top->regs[i]);
    if ((i + 1) % 4 == 0) printf("\n");
  }
  printf("pc  : 0x%08x\n", top->pc);
}

// 将寄存器名转换为对应的值
uint32_t isa_reg_str2val(const char *s, bool *success) {
  *success = true;

  if (strcmp(s, "pc") == 0) return top->pc;

  for (int i = 0; i < 16; i++) {
    if (strcmp(s, regs[i]) == 0) {
      return top->regs[i];
    }
  }

  *success = false;
  return 0;
}
#endif