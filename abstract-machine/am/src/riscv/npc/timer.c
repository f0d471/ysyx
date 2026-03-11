#include <am.h>
#include <npc.h>
#include <klib-macros.h>

// 记录系统启动时的基准时间
static uint64_t start_us = 0;

void __am_timer_init() {
    // 读取当前时间作为基准时间
    // 根据我们在 NPC 里的实现，必须先读低 32 位触发时间刷新，再读高 32 位
    uint32_t low = inl(RTC_ADDR);
    uint32_t high = inl(RTC_ADDR + 4);
    start_us = ((uint64_t)high << 32) | low;
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
    // 读取当前系统的时间
    uint32_t low = inl(RTC_ADDR);
    uint32_t high = inl(RTC_ADDR + 4);
    uint64_t curr_us = ((uint64_t)high << 32) | low;
    
    // 运行时间 = 当前时间 - 启动时的基准时间
    uptime->us = curr_us - start_us;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
    // 实时时钟日期时间（PA2 通常不需要完整实现，填 0 即可）
    rtc->second = 0;
    rtc->minute = 0;
    rtc->hour   = 0;
    rtc->day    = 0;
    rtc->month  = 0;
    rtc->year   = 1900;
}