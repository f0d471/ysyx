#include <am.h>
#include <npc.h>
#include <klib-macros.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

void halt(int code) {
  // NPC 约定：ebreak 结束仿真，退出码放在 a0。
  // 用 register 变量把 code 直接绑定到 a0，而不是写成
  //   asm volatile ("mv a0, %0; ebreak" : : "r"(code));
  // ——后者在汇编里改写了 a0 却没把它列进 clobber list，编译器仍认为 a0 保持原值。
  // 此处因为 halt 不返回而侥幸无事，但这是"靠运气对"，换个上下文就会咬人。
  register int a0 asm("a0") = code;
  asm volatile ("ebreak" : : "r"(a0));
  while (1);
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}
