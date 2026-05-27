#include <cstdio>
#include <cstring>
#include <SDL2/SDL.h>

#include "common.h"

#define SCREEN_W 400
#define SCREEN_H 300

// VGACTL 寄存器布局: [0] = wh (高16位=w, 低16位=h), [1] = sync
#define VGACTL_ADDR 0xa0000100
#define FB_ADDR     0xa1000000

static uint32_t vgactl_port_base[2];
static uint32_t *vmem = nullptr;
static bool sdl_ready = false;

static SDL_Renderer *renderer = nullptr;
static SDL_Texture *texture = nullptr;
static SDL_Window *window = nullptr;

static void init_screen() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(SCREEN_W * 2, SCREEN_H * 2, 0, &window, &renderer);
  SDL_SetWindowTitle(window, "NPC - Typing Game");
  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
      SDL_TEXTUREACCESS_STATIC, SCREEN_W, SCREEN_H);
  sdl_ready = true;
  printf("VGA screen initialized: %dx%d\n", SCREEN_W, SCREEN_H);
}

void vga_update_screen() {
  if (!sdl_ready) return;
  if (vgactl_port_base[1] == 0) return;

  SDL_UpdateTexture(texture, NULL, vmem, SCREEN_W * sizeof(uint32_t));
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
  vgactl_port_base[1] = 0;
}

void init_vga() {
  vmem = new uint32_t[SCREEN_W * SCREEN_H];
  memset(vmem, 0, SCREEN_W * SCREEN_H * sizeof(uint32_t));

  vgactl_port_base[0] = (SCREEN_W << 16) | SCREEN_H;
  vgactl_port_base[1] = 0;

  add_mmio_map("vgactl", VGACTL_ADDR, (uint8_t *)vgactl_port_base, 8, nullptr);
  add_mmio_map("vmem", FB_ADDR, (uint8_t *)vmem, SCREEN_W * SCREEN_H * sizeof(uint32_t), nullptr);

  init_screen();
}
