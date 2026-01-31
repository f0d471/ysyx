#include <am.h>
#include <nemu.h>
#include <stdio.h>
#include <string.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
  // int i;
  // uint32_t wh = inl(VGACTL_ADDR); 
  // int w = wh >> 16;               
  // int h = wh & 0xffff;            
  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // for (i = 0; i < w * h; i ++) fb[i] = i;
  // outl(SYNC_ADDR, 1);
}

// AM显示控制器信息
void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t wh = inl(VGACTL_ADDR);
  int w = wh >> 16;
  int h = wh & 0xffff;
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = w, .height = h,
    .vmemsz = w * h * sizeof(uint32_t)
  };
}

// AM帧缓冲控制器
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t wh = inl(VGACTL_ADDR);
  int screen_w = wh >> 16;
  int screen_h = wh & 0xffff;

  if (ctl->w == 0 || ctl->h == 0 || ctl->pixels == NULL) {
    if (ctl->sync) outl(SYNC_ADDR, 1);
    return;
  }

  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  uint32_t *pixels = (uint32_t *)(uintptr_t)ctl->pixels;

  int dst_x = ctl->x;
  int dst_y = ctl->y;
  int src_x = 0;
  int src_y = 0;
  int src_stride = ctl->w;
  int w = ctl->w;
  int h = ctl->h;

  if (dst_x < 0) {
    src_x = -dst_x;
    w -= src_x;
    dst_x = 0;
  }
  if (dst_y < 0) {
    src_y = -dst_y;
    h -= src_y;
    dst_y = 0;
  }

  if (dst_x >= screen_w || dst_y >= screen_h) {
    if (ctl->sync) outl(SYNC_ADDR, 1);
    return;
  }
  int copy_w = (w < (screen_w - dst_x)) ? w : (screen_w - dst_x);
  int copy_h = (h < (screen_h - dst_y)) ? h : (screen_h - dst_y);
  if (copy_w <= 0 || copy_h <= 0) {
    if (ctl->sync) outl(SYNC_ADDR, 1);
    return;
  }

  for (int row = 0; row < copy_h; row++) {
    uint32_t *src = pixels + (src_y + row) * src_stride + src_x;
    uint32_t *dst = fb + (dst_y + row) * screen_w + dst_x;
    memcpy(dst, src, copy_w * sizeof(uint32_t));
  }

  if (ctl->sync) {
    printf("SYNC triggered at x=%d y=%d\n", ctl->x, ctl->y);
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}