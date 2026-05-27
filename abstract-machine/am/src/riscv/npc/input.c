#include <am.h>
#include <npc.h>

#define KEYDOWN_MASK 0x8000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  uint32_t raw = *(volatile uint32_t *)KBD_ADDR;
  if (raw == AM_KEY_NONE) {
    kbd->keydown = 0;
    kbd->keycode = AM_KEY_NONE;
  } else {
    kbd->keydown = (raw & KEYDOWN_MASK) ? 1 : 0;
    kbd->keycode = raw & (~KEYDOWN_MASK);
  }
}
