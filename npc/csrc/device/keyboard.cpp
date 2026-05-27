#include <cstdio>
#include <cassert>
#include <SDL2/SDL.h>

#include "common.h"

#define MAP(c, f) c(f)

#define KEYDOWN_MASK 0x8000
#define KEY_QUEUE_LEN 1024

// SDL scancode -> AM keycode 映射表
#define NEMU_KEYS(f) \
  f(ESCAPE) f(F1) f(F2) f(F3) f(F4) f(F5) f(F6) f(F7) f(F8) f(F9) f(F10) f(F11) f(F12) \
  f(GRAVE) f(1) f(2) f(3) f(4) f(5) f(6) f(7) f(8) f(9) f(0) f(MINUS) f(EQUALS) f(BACKSPACE) \
  f(TAB) f(Q) f(W) f(E) f(R) f(T) f(Y) f(U) f(I) f(O) f(P) f(LEFTBRACKET) f(RIGHTBRACKET) f(BACKSLASH) \
  f(CAPSLOCK) f(A) f(S) f(D) f(F) f(G) f(H) f(J) f(K) f(L) f(SEMICOLON) f(APOSTROPHE) f(RETURN) \
  f(LSHIFT) f(Z) f(X) f(C) f(V) f(B) f(N) f(M) f(COMMA) f(PERIOD) f(SLASH) f(RSHIFT) \
  f(LCTRL) f(APPLICATION) f(LALT) f(SPACE) f(RALT) f(RCTRL) \
  f(UP) f(DOWN) f(LEFT) f(RIGHT) f(INSERT) f(DELETE) f(HOME) f(END) f(PAGEUP) f(PAGEDOWN)

#define _KEYS(f) f(A) f(B) f(C) f(D) f(E) f(F) f(G) f(H) f(I) f(J) f(K) f(L) f(M) \
  f(N) f(O) f(P) f(Q) f(R) f(S) f(T) f(U) f(V) f(W) f(X) f(Y) f(Z)

#define NEMU_KEY_NAME(k) NEMU_KEY_##k,
enum {
  NEMU_KEY_NONE = 0,
  MAP(NEMU_KEYS, NEMU_KEY_NAME)
};

#define SDL_KEYMAP(k) keymap[SDL_SCANCODE_##k] = NEMU_KEY_##k;
static uint32_t keymap[256] = {};

static void init_keymap() {
  MAP(NEMU_KEYS, SDL_KEYMAP)
}

// 按键队列
static int key_queue[KEY_QUEUE_LEN] = {};
static int key_f = 0, key_r = 0;

static void key_enqueue(uint32_t am_scancode) {
  key_queue[key_r] = am_scancode;
  key_r = (key_r + 1) % KEY_QUEUE_LEN;
  assert(key_r != key_f);
}

static uint32_t key_dequeue() {
  uint32_t key = NEMU_KEY_NONE;
  if (key_f != key_r) {
    key = key_queue[key_f];
    key_f = (key_f + 1) % KEY_QUEUE_LEN;
  }
  return key;
}

void send_key(uint8_t scancode, bool is_keydown) {
  if (npc_state == NPC_RUNNING && keymap[scancode] != NEMU_KEY_NONE) {
    uint32_t am_scancode = keymap[scancode] | (is_keydown ? KEYDOWN_MASK : 0);
    key_enqueue(am_scancode);
  }
}

// MMIO 空间
#define KBD_ADDR 0xa0000060
static uint32_t kbd_data;

static void kbd_io_handler(uint32_t offset, int len, bool is_write) {
  if (!is_write && offset == 0) {
    kbd_data = key_dequeue();
  }
}

void init_keyboard() {
  kbd_data = NEMU_KEY_NONE;
  init_keymap();
  add_mmio_map("keyboard", KBD_ADDR, (uint8_t *)&kbd_data, 4, kbd_io_handler);
  printf("Keyboard device initialized at 0x%08x\n", KBD_ADDR);
}
