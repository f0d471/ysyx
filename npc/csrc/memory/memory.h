#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <cstdint>

#define CONFIG_MSIZE 0x10000000
#define CONFIG_MBASE 0x80000000

void init_mem();
void load_bin(const char *bin_file);

extern size_t img_size;

uint8_t* guest_to_host(uint32_t paddr);

uint32_t pmem_read(uint32_t addr, int len);
void pmem_write(uint32_t addr, uint32_t wmask, uint32_t data);

extern "C" uint32_t paddr_read(uint32_t addr);
extern "C" void paddr_write(uint32_t addr, uint32_t wmask, uint32_t data);

#endif
