// RISC-V 的异常入口汇编：保存现场 → 调 C 处理函数 → 恢复现场 → mret。
//
// 与 riscv/cte.c 一样，这是各平台共用的唯一一份实现。平台差异只有一处
// （mstatus.MPRV），用 __PLATFORM_* 宏区分；该宏由顶层 Makefile 的 ARCHFLAGS
// 同时给到 CFLAGS 与 ASFLAGS。

#define concat_temp(x, y) x ## y
#define concat(x, y) concat_temp(x, y)
#define MAP(c, f) c(f)

#if __riscv_xlen == 32
#define LOAD  lw
#define STORE sw
#define XLEN  4
#else
#define LOAD  ld
#define STORE sd
#define XLEN  8
#endif

// 注意 x0 与 x2 不在列表里：x0 恒零无需保存；x2 是 sp，此刻已被 addi 改过，
// 必须单独算出陷入前的值再存（见下方 OFFSET_SP）
#define REGS_LO16(f) \
      f( 1)       f( 3) f( 4) f( 5) f( 6) f( 7) f( 8) f( 9) \
f(10) f(11) f(12) f(13) f(14) f(15)
#ifndef __riscv_e
#define REGS_HI16(f) \
                                    f(16) f(17) f(18) f(19) \
f(20) f(21) f(22) f(23) f(24) f(25) f(26) f(27) f(28) f(29) \
f(30) f(31)
#define NR_REGS 32
#else
#define REGS_HI16(f)
#define NR_REGS 16
#endif

#define REGS(f) REGS_LO16(f) REGS_HI16(f)

#define PUSH(n) STORE concat(x, n), (n * XLEN)(sp);
#define POP(n)  LOAD  concat(x, n), (n * XLEN)(sp);

// 必须与 arch/riscv.h 里 struct Context 的布局一致：
//   union { void *pdir; uintptr_t gpr[NR_REGS]; }; uintptr_t mcause, mstatus, mepc;
// pdir 与 gpr[0] 共用同一个槽位，所以总大小是 NR_REGS + 3 个字
#define CONTEXT_SIZE  ((NR_REGS + 3) * XLEN)
#define OFFSET_SP     ( 2 * XLEN)
#define OFFSET_CAUSE  ((NR_REGS + 0) * XLEN)
#define OFFSET_STATUS ((NR_REGS + 1) * XLEN)
#define OFFSET_EPC    ((NR_REGS + 2) * XLEN)

.align 3
.globl __am_asm_trap
__am_asm_trap:
  addi sp, sp, -CONTEXT_SIZE

  MAP(REGS, PUSH)

  // 补上 x2(sp)：REGS 列表里没有它，而 c->gpr[2] 应当是陷入发生前的 sp。
  // PA4 构造用户上下文时要读这个值，缺了它会拿到栈上的垃圾。
  addi t0, sp, CONTEXT_SIZE
  STORE t0, OFFSET_SP(sp)

  csrr t0, mcause
  csrr t1, mstatus
  csrr t2, mepc

  STORE t0, OFFSET_CAUSE(sp)
  STORE t1, OFFSET_STATUS(sp)
  STORE t2, OFFSET_EPC(sp)

// 置上 mstatus.MPRV 以通过 difftest。这不是功能需要——C5 讲义明确说 mstatus
// "目前我们都不需要使用, 只需要正确初始化通过DiffTest即可"——所以它是参照实现
// 的产物，只有对着 NEMU/spike 做 difftest 的平台才需要。
//
// 这里刻意用白名单而非 #ifndef __PLATFORM_NPC__：往未实现的 CSR 位写值是
// 安静的硬件误动作，而 difftest 不匹配是响亮的、可查的失败。新平台（例如 B 阶段
// 要接的 ysyxSoC）默认落在"不设置"一侧，需要时自己显式加进来。
#if defined(__PLATFORM_NEMU__) || defined(__PLATFORM_LOGISIM__)
  li a0, (1 << 17)
  or t1, t1, a0
  csrw mstatus, t1
#endif

  mv a0, sp
  call __am_irq_handle

  // 处理函数可能返回另一个上下文（yield / 进程切换），故以返回值为准
  mv sp, a0

  LOAD t1, OFFSET_STATUS(sp)
  LOAD t2, OFFSET_EPC(sp)
  csrw mstatus, t1
  csrw mepc, t2

  MAP(REGS, POP)

  // sp 不在 POP 列表里，靠这一句回到 CONTEXT 之上
  addi sp, sp, CONTEXT_SIZE
  mret
