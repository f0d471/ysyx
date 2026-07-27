// ⚠️ 本文件与 am/src/riscv/npc/input.c 是同一套逻辑的两份拷贝，改一处必须改另一处。
// 二者无法合并：本文件属于跨 ISA 共享的 nemu 平台层（x86 / mips / loongarch 也在用
// 它，那些 ISA 的 inl/outl 是端口指令而非访存），npc 那份则是 RISC-V 专用的。
// 背景与判断依据见 note/bug/abstract-machine/06-*。
// 两份自下方标记行起**逐字相同**，可用 diff 检出漂移，命令见该文档。

#include <am.h>
#include <nemu.h>

/* ==== 以下内容两份必须完全一致 ==== */

// 键盘寄存器的第 15 位表示按下(1)还是抬起(0)，低位是扫描码
#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t raw = inl(KBD_ADDR);
  if (raw == AM_KEY_NONE) {
    kbd->keydown = 0;
    kbd->keycode = AM_KEY_NONE;
  } else {
    kbd->keydown = (raw & KEYDOWN_MASK) ? 1 : 0;
    kbd->keycode = raw & ~KEYDOWN_MASK;
  }
}
