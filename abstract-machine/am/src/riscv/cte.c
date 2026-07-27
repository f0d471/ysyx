// nemu / npc / logisim 各平台共用的唯一一份 CTE 实现——陷入与上下文切换是纯粹的
// ISA 行为，与外设、内存布局无关，不按平台分立。平台差异只在 trap.S 里有一处。

#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

// mcause 的异常编码。RISC-V 特权级规范 Table "Machine cause register values"
#define MCAUSE_ECALL_M   11   // Environment call from M-mode

// AM 的约定：系统调用号为 -1 时表示 yield，其余交给上层当作系统调用。
// 号码放在 GPR1 里——具体是哪个寄存器由 ISA 决定（RV32I 是 a7，RV32E 是 a5），
// arch/riscv.h 已经把这个差异封装好，此处不要再手写 gpr[17]。
#define SYSCALL_YIELD    ((uintptr_t)-1)

#define ECALL_INSTR_LEN  4    // ecall 是 32 位指令，返回时 mepc 要跳过它

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case MCAUSE_ECALL_M:
        ev.event = (c->GPR1 == SYSCALL_YIELD) ? EVENT_YIELD : EVENT_SYSCALL;
        // ecall 的 mepc 指向 ecall 本身，若原样返回会无限重入
        c->mepc += ECALL_INSTR_LEN;
        break;
      default:
        ev.event = EVENT_ERROR;
        break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context*(*handler)(Event, Context*)) {
  // 设置异常入口地址
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

  // 注册事件处理回调
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  // 上下文放在内核栈的顶端，trap.S 返回时 sp 会正好落回 kstack.end
  Context *c = (Context *)((uintptr_t)kstack.end - sizeof(Context));
  memset(c, 0, sizeof(Context));

  c->mepc = (uintptr_t)entry;   // mret 之后从 entry 开始执行
  c->gpr[10] = (uintptr_t)arg;  // a0 = x10，即 entry 的第一个参数

  // MPP = M：mret 之后仍留在机器模式。MODE_M 由 riscv/riscv.h 给出，
  // 不要写成裸的 0x1800
  c->mstatus = MODE_M << 11;

  return c;
}

void yield() {
#ifdef __riscv_e
  asm volatile("li a5, -1; ecall");
#else
  asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
