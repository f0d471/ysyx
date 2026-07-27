// 本文件与 am/src/platform/nemu/ioe/input.c 是同一套逻辑的两份拷贝，
// 改一处必须改另一处。二者无法合并的原因见那份文件顶部的说明。
// 两份自下方标记行起逐字相同，可用 diff 比对以检出漂移。

#include <am.h>
#include <npc.h>

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
