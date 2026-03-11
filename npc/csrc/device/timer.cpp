#include <cstdio>
#include <sys/time.h>
#include "common.h"

#define RTC_ADDR 0xa0000048 // 与 npc.h 中定义的地址保持一致

static uint32_t rtc_port_base[2];

// 获取宿主机当前时间（微秒）
static uint64_t get_time_internal() {
    struct timeval now;
    gettimeofday(&now, NULL);
    return now.tv_sec * 1000000ULL + now.tv_usec;
}

// RTC 的 MMIO 回调函数
static void rtc_io_handler(uint32_t offset, int len, bool is_write) {
    // 借鉴 NEMU：当程序读取 RTC 的地址时，实时更新 rtc_port_base 里的时间
    // 为了防止低32位和高32位读取时发生不同步，我们在读偏移为 0 (低32位) 时统一更新
    if (!is_write && offset == 0) {
        uint64_t us = get_time_internal();
        rtc_port_base[0] = (uint32_t)us;         // 低 32 位
        rtc_port_base[1] = (uint32_t)(us >> 32); // 高 32 位
    }
}

void init_timer() {
    // RTC 占据 8 个字节的空间，注册到 MMIO 总线
    add_mmio_map("rtc", RTC_ADDR, (uint8_t *)rtc_port_base, 8, rtc_io_handler);
}