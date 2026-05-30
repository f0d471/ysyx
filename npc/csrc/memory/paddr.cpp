#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include "Vtop.h"
#include "common.h"

static uint8_t pmem[CONFIG_MSIZE] = {};
size_t img_size = 0;

// 检查地址是否在合法范围内
static inline bool in_pmem(uint32_t addr) {
    return addr >= CONFIG_MBASE && addr < CONFIG_MBASE + CONFIG_MSIZE;
}

// 检查是否为外设 (MMIO) 地址空间
static inline bool is_mmio(uint32_t addr) {
    return addr >= 0xa0000000 && addr <= 0xa1ffffff;
}

// 地址转换 
uint8_t* guest_to_host(uint32_t paddr) {
    return pmem + paddr - CONFIG_MBASE;
}

// 越界处理 
static void out_of_bound(uint32_t addr, bool is_write) {
    printf(ANSI_FG_RED "Memory %s out of bound at address = 0x%08x\n" ANSI_NONE, 
           is_write ? "WRITE" : "READ", addr);
    npc_state = NPC_ABORT;
    npc_quit();
}

void init_mem() {
    memset(pmem, 0, sizeof(pmem));
    printf("Physical memory initialized at [" ANSI_FG_GREEN "0x%08x" ANSI_NONE ", " ANSI_FG_GREEN "0x%08x" ANSI_NONE "]\n",
           CONFIG_MBASE, CONFIG_MBASE + CONFIG_MSIZE - 1);
}

void load_bin(const char *bin_file) {
    if (bin_file == NULL) return;
    
    FILE *fp = fopen(bin_file, "rb");
    assert(fp != NULL);

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    img_size = size;
    fseek(fp, 0, SEEK_SET);

    size_t ret = fread(guest_to_host(CONFIG_MBASE), size, 1, fp);
    assert(ret == 1);

    fclose(fp);
    printf("Loaded binary file: %s (size: %ld bytes)\n", bin_file, size);
}

uint32_t pmem_read(uint32_t addr, int len) {
    if (in_pmem(addr)) {
        uint32_t data = 0;
        switch (len) {
            case 1: data = *(uint8_t  *)guest_to_host(addr); break;
            case 2: data = *(uint16_t *)guest_to_host(addr); break;
            case 4: data = *(uint32_t *)guest_to_host(addr); break;
            default: assert(0);
        }

        #ifdef CONFIG_MTRACE
        // 只有当访问的地址不是当前取指地址时，才认为是 Load 访存
        if (addr != top->debug_pc) { 
            log_mtrace(addr, data, 0); 
        }
        #endif

        return data;
    } else {
        out_of_bound(addr, false);
        return 0;
    }
}

void pmem_write(uint32_t addr, uint32_t wmask, uint32_t data) {
    if (in_pmem(addr)) {
        uint8_t *p = (uint8_t *)guest_to_host(addr);
        if (wmask & 1) p[0] = (uint8_t)(data);
        if (wmask & 2) p[1] = (uint8_t)(data >> 8);
        if (wmask & 4) p[2] = (uint8_t)(data >> 16);
        if (wmask & 8) p[3] = (uint8_t)(data >> 24);

        #ifdef CONFIG_MTRACE
        log_mtrace(addr, data, 1);
        #endif

    } else {
        out_of_bound(addr, true);
    }
}

extern "C" uint32_t paddr_read(uint32_t addr) {
  if (addr == 0) return 0; // 保护一下，防止取指地址为 0 报错

  uint32_t aligned = addr & ~3u;
  if (__builtin_expect(in_pmem(aligned), 1)) return pmem_read(aligned, 4);

  #ifdef CONFIG_DEVICE
    if (is_mmio(addr)) {
      uint32_t ret = mmio_read(addr, 4);
      #ifdef CONFIG_DTRACE
        log_dtrace('R', addr, 4, ret);
      #endif
      #ifdef CONFIG_DIFFTEST
        difftest_skip_ref();
      #endif

      return ret;
    }
  #endif

  out_of_bound(addr, false);
  return 0;
}

extern "C" void paddr_write(uint32_t addr, uint32_t wmask, uint32_t data) {
  uint32_t aligned = addr & ~3u;
  if (__builtin_expect(in_pmem(aligned), 1)) {
      pmem_write(aligned, wmask, data);
      return;
  }

  #ifdef CONFIG_DEVICE
    if (is_mmio(addr)) {
        uint32_t unshifted = data >> (8 * (addr & 3));
        int len = (wmask == 0x1 || wmask == 0x2 || wmask == 0x4 || wmask == 0x8) ? 1 :
                  (wmask == 0x3 || wmask == 0xC) ? 2 : 4;
        mmio_write(addr, len, unshifted);
        #ifdef CONFIG_DTRACE
          log_dtrace('W', addr, len, unshifted);
        #endif
        #ifdef CONFIG_DIFFTEST
          difftest_skip_ref();
        #endif

        return;
    }
  #endif

  out_of_bound(addr, true);
}
