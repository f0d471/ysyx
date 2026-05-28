#ifndef __MTRACE_H__
#define __MTRACE_H__

#include <cstdint>
#include "config.h"

#ifdef CONFIG_MTRACE
void log_mtrace(uint32_t addr, uint32_t data, int is_write);
#endif

#endif
