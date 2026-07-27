// 本文件与 am/src/platform/nemu/ioe/timer.c 是同一套逻辑的两份拷贝，
// 改一处必须改另一处。二者无法合并的原因见那份文件顶部的说明。
// 两份自下方标记行起逐字相同，可用 diff 比对以检出漂移。

#include <am.h>
#include <npc.h>
#include <klib-macros.h>

/* ==== 以下内容两份必须完全一致 ==== */

// 系统启动时的基准时间，uptime 以它为零点
static uint64_t start_us = 0;

// 读一次 64 位的 RTC。
// 必须先读低 32 位再读高 32 位：设备在低位被读时才刷新整个时间快照，读序反了
// 会拿到"新的高位配旧的低位"，在低位回绕的那一刻算出跳变的时间（撕裂读）。
static uint64_t read_rtc_us(void) {
  uint32_t low  = inl(RTC_ADDR);
  uint32_t high = inl(RTC_ADDR + 4);
  return ((uint64_t)high << 32) | low;
}

void __am_timer_init() {
  start_us = read_rtc_us();
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = read_rtc_us() - start_us;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  // 完整的年月日时分秒 PA 阶段用不到，按 AM 的约定填一个固定值即可
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
