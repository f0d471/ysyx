#include <am.h>
#include <nemu.h>

static uint64_t start_us = 0;
void __am_timer_init() {
  uint32_t low = inl(RTC_ADDR);
  uint32_t high = inl(RTC_ADDR + 4);
  start_us = (uint64_t)high << 32 | low;
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t curr_low = inl(RTC_ADDR);
  uint32_t curr_high = inl(RTC_ADDR + 4);
  uint64_t curr_us = (uint64_t)curr_high << 32 | curr_low;
  uptime->us = curr_us - start_us;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}