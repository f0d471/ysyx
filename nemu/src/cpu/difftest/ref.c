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

// 1. 内存同步接口
__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
  // DiffTest 规定只会拷贝物理内存段，不会拷贝设备地址
  // 所以直接使用 guest_to_host 是安全且高效的
  if (direction == DIFFTEST_TO_REF) {
    memcpy(guest_to_host(addr), buf, n);
  } else {
    memcpy(buf, guest_to_host(addr), n);
  }
}

// 2. 寄存器同步接口 (核心修改点：消除硬编码)
__EXPORT void difftest_regcpy(void *dut, bool direction) {
  // 巧妙的做法：dut 其实就是一串连续的内存（GPRs + PC）
  // 我们直接把它当成 word_t 数组来处理，不用在 REF 里定义死板的结构体
  word_t *ctx = (word_t *)dut;
  
  // 动态获取当前 NEMU 配置的寄存器数量 (RV32E 为 16，RV32I 为 32)
  int gpr_num = MUXDEF(CONFIG_RVE, 16, 32);

  if (direction == DIFFTEST_TO_REF) {
    // 将 NPC 传来的状态覆盖给 NEMU
    for (int i = 0; i < gpr_num; i++) {
      cpu.gpr[i] = ctx[i];
    }
    cpu.pc = ctx[gpr_num]; // 协议规定：PC 紧跟在最后一个 GPR 后面
  } else {
    // 将 NEMU 的状态拷回给 NPC 用于对比
    for (int i = 0; i < gpr_num; i++) {
      ctx[i] = cpu.gpr[i];
    }
    ctx[gpr_num] = cpu.pc;
  }
}

// 3. 执行接口
__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);
}

// 4. 中断接口 (OS 实验才会用到)
__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

// 5. 初始化接口
__EXPORT void difftest_init(int port) {
  extern void init_mem();
  extern void init_isa();
  // 初始化物理内存阵列
  init_mem();
  // 初始化架构相关状态 (比如把 PC 设置到复位地址)
  init_isa();
}