#include <cstdio>

#include "common.h"

#define SERIAL_PORT 0xa00003f8

// 为串口分配一个 8 字节的模拟物理空间
static uint8_t serial_base[8];

// 核心回调：当总线向这个空间读写时，会跳到这里
static void serial_io_handler(uint32_t offset, int len, bool is_write) {
    // 只有当程序向 offset == 0 写入时，才是向串口发字符
    if (is_write && offset == 0) {
        char ch = serial_base[0];
        putc(ch, stderr);   // 输出到宿主机的终端
        fflush(stderr);     // 立即刷新，防止缓冲导致看不到字符
    }
}

void init_serial() {
    // 把 0xa00003f8 开始的 8 字节注册到 MMIO 总线上
    add_mmio_map("serial", SERIAL_PORT, serial_base, 8, serial_io_handler);
}

// 统一的设备初始化入口
void init_device() {
    init_serial();
    // 未来如果开发了 RTC，可以在这里加 init_rtc();
}