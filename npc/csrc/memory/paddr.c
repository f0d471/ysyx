#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <time.h>

#include "common.h"

static uint8_t pmem[CONFIG_MSIZE] = {};

// 检查地址是否在合法范围内
static inline bool in_pmem(uint32_t addr) {
    return addr >= CONFIG_MBASE && addr < CONFIG_MBASE + CONFIG_MSIZE;
}

// 地址转换 
static inline uint8_t* guest_to_host(uint32_t paddr) {
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
    srand((unsigned int)time(NULL));

    uint32_t *p = (uint32_t *)pmem;
    for (int i = 0; i < CONFIG_MSIZE / sizeof(uint32_t); i++) {
        p[i] = rand();
    }
    printf("Physical memory initialized at [" ANSI_FG_GREEN "0x%08x" ANSI_NONE ", " ANSI_FG_GREEN "0x%08x" ANSI_NONE "]\n", 
           CONFIG_MBASE, CONFIG_MBASE + CONFIG_MSIZE - 1);
}

void load_bin(const char *bin_file) {
    if (bin_file == NULL) return;
    
    FILE *fp = fopen(bin_file, "rb");
    assert(fp != NULL);

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    size_t ret = fread(guest_to_host(CONFIG_MBASE), size, 1, fp);
    assert(ret == 1);

    fclose(fp);
    printf("Loaded binary file: %s (size: %ld bytes)\n", bin_file, size);
}

// ====================== C 环境内存接口 ==========================
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
        if (addr != top->pc) { 
            log_mtrace(addr, data, 0); 
        }
        #endif

        return data;
    } else {
        out_of_bound(addr, false);
        return 0;
    }
}

void pmem_write(uint32_t addr, int len, uint32_t data) {
    if (in_pmem(addr)) {
        switch (len) {
            case 1: *(uint8_t  *)guest_to_host(addr) = (uint8_t)data;  break;
            case 2: *(uint16_t *)guest_to_host(addr) = (uint16_t)data; break;
            case 4: *(uint32_t *)guest_to_host(addr) = (uint32_t)data; break;
            default: assert(0);
        }

        #ifdef CONFIG_MTRACE
        log_mtrace(addr, data, 1); 
        #endif

    } else {
        out_of_bound(addr, true); 
    }
}

// ================= 硬件DPI-C调用接口 ================================
extern "C" uint32_t paddr_read(uint32_t  addr) {
  if (__builtin_expect(in_pmem(addr), 1)) return pmem_read(addr, 4);
  // IFDEF(CONFIG_DEVICE, return mmio_read(addr, 4));
  out_of_bound(addr,false);
  return 0;
}

extern "C" void paddr_write(uint32_t  addr, int len, uint32_t data) {
  if (__builtin_expect(in_pmem(addr), 1)) { pmem_write(addr, len, data); return; }
  // IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr,true);
}
