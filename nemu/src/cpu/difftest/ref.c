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

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>
#include <string.h>

// 内存同步接口
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  if (direction == DIFFTEST_TO_REF) {
    memcpy(guest_to_host(addr), buf, n);
  } else {
    memcpy(buf, guest_to_host(addr), n);
  }
}

// 寄存器同步接口 
__EXPORT void difftest_regcpy(void *dut, bool direction) {
  word_t *ctx = (word_t *)dut;
  
  int gpr_num = MUXDEF(CONFIG_RVE, 16, 32);

  if (direction == DIFFTEST_TO_REF) {
    for (int i = 0; i < gpr_num; i++) {
      cpu.gpr[i] = ctx[i];
    }
    cpu.pc = ctx[gpr_num]; 
  } else {
    for (int i = 0; i < gpr_num; i++) {
      ctx[i] = cpu.gpr[i];
    }
    ctx[gpr_num] = cpu.pc;
  }
}

// 执行接口
__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

// 中断接口 
__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

// 初始化接口
__EXPORT void difftest_init(int port) {
  extern void init_mem();
  extern void init_isa();
  init_mem();
  init_isa();
}