#include <cstdio>
#include <cstdint>

#include "utils.h"

#ifdef CONFIG_DTRACE

void log_dtrace(char type, uint32_t addr, int len, uint32_t data) {
    const char* dev_name = "unknown";
    if (addr == 0xa00003f8) dev_name = "serial";
    else if (addr == 0xa0000048) dev_name = "rtc";

    iringbuf_push("[dtrace] %c  addr=0x%08x len=%d val=0x%08x device=%s\n",
                  type, addr, len, data, dev_name);
}

#endif // CONFIG_DTRACE
