// ⚠️ 本文件与 am/src/riscv/npc/gpu.c 是同一套逻辑的两份拷贝，改一处必须改另一处。
// 二者无法合并：本文件属于跨 ISA 共享的 nemu 平台层（x86 / mips / loongarch 也在用
// 它，那些 ISA 的 inl/outl 是端口指令而非访存），npc 那份则是 RISC-V 专用的。
// 背景与判断依据见 note/bug/abstract-machine/06-*。
//
// 两份自下方标记行起**逐字相同**，可用 diff 检出漂移，命令见上述文档。

#include <am.h>
#include <nemu.h>
#include <klib.h>

void __am_gpu_init() {
}

/* ==== 以下内容两份必须完全一致 ==== */

#define SYNC_ADDR (VGACTL_ADDR + 4)

// 显示控制器把屏幕尺寸打包在一个 32 位寄存器里：高 16 位是宽，低 16 位是高
static void read_screen_size(int *w, int *h) {
  uint32_t wh = inl(VGACTL_ADDR);
  *w = wh >> 16;
  *h = wh & 0xffff;
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  int w, h;
  read_screen_size(&w, &h);
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = w, .height = h,
    .vmemsz = w * h * sizeof(uint32_t)
  };
}

// 把 ctl->pixels 指向的 w×h 图像贴到屏幕 (x, y) 处，超出屏幕的部分要裁掉。
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int screen_w, screen_h;
  read_screen_size(&screen_w, &screen_h);

  int dst_x = ctl->x, dst_y = ctl->y;   // 目标矩形在屏幕上的左上角
  int src_x = 0,      src_y = 0;        // 裁剪后从源图像的哪个位置开始取
  int w = ctl->w,     h = ctl->h;
  int src_stride = ctl->w;              // 源图像一行有多少像素（裁剪不改变它）

  // 左/上越界：把超出的部分从源图像里跳过去，目标坐标夹到 0
  if (dst_x < 0) { src_x = -dst_x; w -= src_x; dst_x = 0; }
  if (dst_y < 0) { src_y = -dst_y; h -= src_y; dst_y = 0; }

  // 右/下越界：能画多少画多少
  int copy_w = (w < screen_w - dst_x) ? w : screen_w - dst_x;
  int copy_h = (h < screen_h - dst_y) ? h : screen_h - dst_y;

  bool drawable = ctl->pixels != NULL
               && dst_x < screen_w && dst_y < screen_h
               && copy_w > 0 && copy_h > 0;

  if (drawable) {
    uint32_t *fb     = (uint32_t *)(uintptr_t)FB_ADDR;
    uint32_t *pixels = (uint32_t *)(uintptr_t)ctl->pixels;
    // 源与屏幕的行宽不同，只能逐行搬
    for (int row = 0; row < copy_h; row++) {
      uint32_t *src = pixels + (src_y + row) * src_stride + src_x;
      uint32_t *dst = fb     + (dst_y + row) * screen_w   + dst_x;
      memcpy(dst, src, copy_w * sizeof(uint32_t));
    }
  }

  // 单一出口：无论画没画成，sync 请求都必须应答，否则上层会一直等这一帧
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
