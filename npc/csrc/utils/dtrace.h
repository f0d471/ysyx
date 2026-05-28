#ifndef __DTRACE_H__
#define __DTRACE_H__

#include <cstdint>
#include "config.h"

#ifdef CONFIG_DTRACE
void log_dtrace(char type, uint32_t addr, int len, uint32_t data);
#endif

#endif
