#ifndef __ISA_H__
#define __ISA_H__

#include <cstdint>

void isa_reg_display();
uint32_t isa_reg_str2val(const char *s, bool *success);

#endif
