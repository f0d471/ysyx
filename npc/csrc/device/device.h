#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <cstdint>

typedef void(*io_callback_t)(uint32_t offset, int len, bool is_write);

void add_mmio_map(const char *name, uint32_t addr, uint8_t *space, uint32_t len, io_callback_t callback);
uint32_t mmio_read(uint32_t addr, int len);
void mmio_write(uint32_t addr, int len, uint32_t data);
void init_device();
void device_poll();
void device_exit();

#endif
