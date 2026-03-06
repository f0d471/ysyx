#include <cstdio>
#include <cstdlib>
#include <cassert>

#include "common.h"

#define NR_MAP 16

// 映射表结构
struct IOMap {
    const char *name;
    uint32_t low;
    uint32_t high;
    uint8_t *space;
    io_callback_t callback;
} maps[NR_MAP];

static int nr_map = 0;

// 注册外设
void add_mmio_map(const char *name, uint32_t addr, uint8_t *space, uint32_t len, io_callback_t callback) {
    assert(nr_map < NR_MAP);
    maps[nr_map] = (IOMap){ name, addr, addr + len - 1, space, callback };
    nr_map++;
}

// 查找目标设备
static IOMap* fetch_mmio_map(uint32_t addr) {
    for (int i = 0; i < nr_map; i++) {
        if (addr >= maps[i].low && addr <= maps[i].high) {
            return &maps[i];
        }
    }
    return NULL;
}

// 执行读操作
uint32_t mmio_read(uint32_t addr, int len) {
    IOMap *map = fetch_mmio_map(addr);
    if (!map) {
        fprintf(stderr, "MMIO Read out of bound: addr=0x%08x\n", addr);
        return 0;
    }
    
    uint32_t offset = addr - map->low;
    // 1. NEMU 规则：读操作先触发回调（如果有需要更新状态的设备）
    if (map->callback) map->callback(offset, len, false);
    
    // 2. 从设备的局部空间读取数据
    uint32_t data = 0;
    switch (len) {
        case 1: data = *(uint8_t  *)(map->space + offset); break;
        case 2: data = *(uint16_t *)(map->space + offset); break;
        case 4: data = *(uint32_t *)(map->space + offset); break;
        default: assert(0);
    }
    return data;
}

// 执行写操作
void mmio_write(uint32_t addr, int len, uint32_t data) {
    IOMap *map = fetch_mmio_map(addr);
    if (!map) {
        fprintf(stderr, "MMIO Write out of bound: addr=0x%08x\n", addr);
        return;
    }

    uint32_t offset = addr - map->low;
    // 1. 将数据写入设备的局部空间
    switch (len) {
        case 1: *(uint8_t  *)(map->space + offset) = (uint8_t)data;  break;
        case 2: *(uint16_t *)(map->space + offset) = (uint16_t)data; break;
        case 4: *(uint32_t *)(map->space + offset) = (uint32_t)data; break;
        default: assert(0);
    }
    
    // 2. 触发回调，让设备干活
    if (map->callback) map->callback(offset, len, true);
}