/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>
#include <cpu/difftest.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static inline void log_mtrace(char type, paddr_t addr, int len, word_t data) {
#ifdef CONFIG_MTRACE
    // 这里利用了短路求值，如果未定义 MTRACE，编译器会优化掉整个块
    if (likely(!MTRACE_COND)) return;

    if (type == 'R' && addr == cpu.pc) {
        return;
    }
    
    // 格式化与记录逻辑封装在此
    TRACE_LOG("[Mtrace] %c  addr=" FMT_PADDR " len=%d val=" FMT_WORD "\n", 
              type, addr, len, data);
#endif
}

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
  word_t ret = 0;

  if (likely(in_pmem(addr))) {
    ret = pmem_read(addr, len);
  } else {
    #ifdef CONFIG_DEVICE
      IFDEF(CONFIG_DIFFTEST, difftest_skip_ref());
      ret = mmio_read(addr, len);
    #else
      out_of_bound(addr);
      return 0;
    #endif
  }

  log_mtrace('R', addr, len, ret);
  return ret;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  log_mtrace('W', addr, len, data);

  if (likely(in_pmem(addr))) {
    pmem_write(addr, len, data);
    return;
  }

  #ifdef CONFIG_DEVICE
    IFDEF(CONFIG_DIFFTEST, difftest_skip_ref());
    mmio_write(addr, len, data);
    return;
  #endif

  out_of_bound(addr);
}