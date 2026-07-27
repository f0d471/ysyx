# BUG-06　cte.c：现成的 `GPR1` 抽象被绕开，RV32E 下读越界导致 yield 失效

| 项 | 值 |
| --- | --- |
| 文件 | `abstract-machine/am/src/riscv/{nemu,npc}/cte.c`（已合并为 `am/src/riscv/cte.c`） |
| 函数 | `__am_irq_handle()` |
| 缺陷类型 | 结构体越界读 → 事件误判 |
| 严重度 | 🔴 高（仅在 `-mabi=ilp32e` 下发作，但那正是 NPC 用的 ABI） |
| 引入于 | `0168dce` "device" 与 `2ebdf4c` "yield-os bug" |
| 发现于 | 2026-07-27 abstract-machine 第二轮复盘 |

---

## 〇、前置知识

### 系统调用是怎么发生的

用户代码想让操作系统干活（读文件、退出、让出 CPU），不能直接调函数——OS 在另一个特权级。RISC-V 的做法是执行一条 **`ecall`** 指令，它会**主动触发一个异常**：

1. CPU 把当前 PC 存进 **`mepc`**（machine exception program counter）；
2. 把"为什么陷进来"的编号存进 **`mcause`**；
3. 跳到 **`mtvec`** 指定的入口，也就是 AM 的 `__am_asm_trap`。

`mcause = 11` 表示 "Environment call from M-mode"，即机器模式下执行了 `ecall`。

### 参数放在哪：ABI 寄存器命名

RISC-V 有 32 个通用寄存器 `x0`~`x31`，但汇编里几乎没人这么写，而是用 **ABI 名**（应用二进制接口约定的角色名）：

| ABI 名 | 寄存器 | 用途 |
| --- | --- | --- |
| `zero` | `x0` | 恒为 0，写入被丢弃 |
| `sp` | `x2` | 栈指针 |
| `a0`~`a7` | `x10`~`x17` | 函数参数 / 返回值；**系统调用号按惯例放 `a7`** |

所以"检查系统调用号"在代码里就写成 `c->gpr[17]`——`a7` 就是 `x17`。

### RV32E：寄存器只有一半

**RV32E**（E = Embedded，嵌入式）是 RISC-V 为极小面积场景定义的变体：**只有 `x0`~`x15` 共 16 个通用寄存器**，比标准的 RV32I 少一半。

后果是 `a7`（`x17`）**在 RV32E 里根本不存在**。这个 ABI 只有 `a0`~`a5`（`x10`~`x15`），系统调用号只能改放 **`a5`（`x15`）**。

> 📌 本仓库里 `scripts/riscv32e-npc.mk` 与 `minirv-npc.mk` 都是 `-march=rv32e_zicsr -mabi=ilp32e`——**NPC 用的正是 RV32E**。

### AM 早就为这个差异准备了抽象

`am/include/arch/riscv.h` 里：

```c
#ifdef __riscv_e
#define GPR1 gpr[15] // a5
#else
#define GPR1 gpr[17] // a7
#endif
```

`GPR1` 的含义是「**本 ISA 上放系统调用号的那个寄存器**」。它不只 RISC-V 有，每个架构都定义了自己的：

| 架构 | `GPR1` |
| --- | --- |
| x86 | `eax` |
| MIPS | `gpr[2]`（`v0`） |
| LoongArch | `gpr[11]`（`a7`） |
| RISC-V | `gpr[17]` 或 `gpr[15]` |

**上层代码正是靠它做到与 ISA 无关的**——`nanos-lite/src/syscall.c:5` 写的就是 `a[0] = c->GPR1;`，一行代码通吃所有架构。

---

## 一、题目

下面是两个平台的 `__am_irq_handle`，做的是同一件事：判断这次 `ecall` 是 yield 还是普通系统调用。

```c
/* am/src/riscv/nemu/cte.c */
case 11:
  // 必须检查 a7 (gpr[17]) 的值是否为 -1
  if (c->gpr[17] == -1) {
    ev.event = EVENT_YIELD;
  } else {
    ev.event = EVENT_SYSCALL;
  }
  c->mepc += 4;
  break;
```

```c
/* am/src/riscv/npc/cte.c */
case 11:
  // 根据架构选择检查 a7 还是 a5
  #ifdef __riscv_e
    if (c->gpr[15] == -1) {
  #else
    if (c->gpr[17] == -1) {
  #endif
    ev.event = EVENT_YIELD;
  } else {
    ev.event = EVENT_SYSCALL;
  }
  c->mepc += 4;
  break;
```

两处各有什么问题？

<details>
<summary>答案</summary>

1. **两处都绕开了现成的 `GPR1` 抽象**——npc 那份等于把 `arch/riscv.h` 里已有的 `#ifdef` 又抄了一遍；
2. **nemu 那份在 RV32E 下是越界读**：`NR_REGS` 只有 16，`gpr[17]` 已经出了数组。

而 `scripts/riscv32e-nemu.mk` 恰恰是存在的架构，且它引用的正是 `riscv/nemu/cte.c`。

</details>

---

## 二、`gpr[17]` 到底读到了什么

`Context` 的布局是：

```c
struct Context {
  union { void *pdir; uintptr_t gpr[NR_REGS]; };
  uintptr_t mcause, mstatus, mepc;
};
```

RV32E 下 `NR_REGS = 16`，每个字 4 字节，于是：

```
偏移:   0   4   8  ...  60 │  64      68       72
字段: gpr[0..15]          │ mcause  mstatus   mepc
越界:                       gpr[16]  gpr[17]
                                        ↑
                                  代码读的是这里
```

**`c->gpr[17]` 读到的是 `mstatus`。**

于是执行链条变成：

1. `yield()` 在 RV32E 下发的是 `li a5, -1; ecall`——号码正确地放进了 `a5`；
2. handler 却去比 `mstatus == -1`；
3. `mstatus` 是状态寄存器，永远不可能等于全 1；
4. 判断落到 `else` → 事件变成 **`EVENT_SYSCALL`** 而不是 `EVENT_YIELD`。

**结果：`ARCH=riscv32e-nemu` 上 yield 完全失效。** PA3 的 `yield-os`、PA4 的进程切换都建立在它之上。

> ⚠️ 这里还有个更隐蔽的性质：**它不会崩溃**。越界读的是同一个结构体内的合法内存，不触发任何异常，只是安静地给出错误答案。

---

## 三、原理：抽象存在却被绕开，是怎么发生的

这个缺陷值得单独写一篇，不是因为它多难修（改一行），而是因为**它的成因非常典型**。

### 3.1 现象：一个抽象，三种用法

| 使用者 | 写法 | 评价 |
| --- | --- | --- |
| `nanos-lite/src/syscall.c` | `c->GPR1` | ✅ 正确 |
| 上游 `native/cte.c`、`x86/qemu/cte.c` | `c->GPR1` | ✅ 正确 |
| 自己写的 `riscv/npc/cte.c` | 手写 `#ifdef __riscv_e` | ⚠️ 对，但重复 |
| 自己写的 `riscv/nemu/cte.c` | 硬编码 `gpr[17]` | ❌ 错 |

**抽象是现成的，甚至你自己的上层代码已经在用了，唯独 AM 这一层没用。**

### 3.2 为什么会绕开

推测的过程是这样的：

1. 写 `riscv/nemu/cte.c` 时，讲义说"系统调用号在 a7"，于是查表得到 `a7 = x17`，写下 `gpr[17]`。**在 RV32I 下这完全正确**，测试也过。
2. 后来做 NPC（RV32E），发现挂了，于是在 `riscv/npc/cte.c` 里补了个 `#ifdef __riscv_e`。**问题解决了，但解决在错误的层次上**。
3. `riscv/nemu/cte.c` 无人问津——因为当时用的是 `riscv32-nemu`（RV32I），它没坏。

第 2 步是关键：**当你发现"这段代码需要按 ISA 分情况"时，正确的反应是去找"这个分情况有没有人已经做过了"**，而不是就地写一个 `#ifdef`。前者会让你翻到 `arch/riscv.h`，看见 `GPR1` 就在那里；后者让同一个知识在代码库里有了第二份拷贝——而两份拷贝必然漂移。

### 3.3 复制粘贴让它无法被发现

如果只有一份 `cte.c`，第 2 步的修复会自动惠及所有平台，这个 bug 从来不会存在。**它能存在，前提就是有两份。**

同期发现的另外两处漂移是同一个故事：

| 位置 | npc | nemu |
| --- | --- | --- |
| `trap.S` 把 sp 存进 `OFFSET_SP` | ✅ 有 | ❌ 宏定义了却从不写入 → `c->gpr[2]` 是垃圾 |
| `cte.c` 的 RV32E 分支 | ✅ 有 | ❌ 没有（本条） |
| `timer.c` 的 RTC 读序 | low→high | high→low |

第三条最刺眼：有一个 commit `3458446` 标题写着 *"fix: swap RTC read order to prevent torn reads"*——**只改了一边**。

---

## 四、修复

### 4.1 用抽象，不要重写抽象

```c
// AM 的约定：系统调用号为 -1 时表示 yield，其余交给上层当作系统调用。
// 号码放在 GPR1 里——具体是哪个寄存器由 ISA 决定（RV32I 是 a7，RV32E 是 a5），
// arch/riscv.h 已经把这个差异封装好，此处不要再手写 gpr[17]。
#define SYSCALL_YIELD ((uintptr_t)-1)

case MCAUSE_ECALL_M:
  ev.event = (c->GPR1 == SYSCALL_YIELD) ? EVENT_YIELD : EVENT_SYSCALL;
  c->mepc += ECALL_INSTR_LEN;
  break;
```

顺带消灭同一段里的四个魔数：

| 原来 | 现在 | 含义 |
| --- | --- | --- |
| `case 11` | `MCAUSE_ECALL_M` | mcause 的 "M 模式 ecall" 编码 |
| `gpr[17]` | `GPR1` | 系统调用号寄存器（随 ISA 变化） |
| `-1` | `SYSCALL_YIELD` | AM 约定的 yield 号 |
| `+= 4` | `+= ECALL_INSTR_LEN` | ecall 是 32 位指令 |
| `0x1800` | `MODE_M << 11` | `mstatus.MPP = 机器模式`（`MODE_M` 来自 `riscv/riscv.h`） |

### 4.2 根治：把两份合成一份

只改一行，下次照样会漂移。真正的修复是**让两份代码不再存在**：

```
删除  am/src/riscv/nemu/cte.c    am/src/riscv/nemu/trap.S
删除  am/src/riscv/npc/cte.c     am/src/riscv/npc/trap.S
新增  am/src/riscv/cte.c         am/src/riscv/trap.S
```

依据是：**陷入与上下文切换是纯粹的 ISA 行为，与外设、内存布局无关**。7 个 RISC-V 架构（`riscv32-nemu`、`riscv32e-nemu`、`riscv64-nemu`、`minirv-nemu`、`minirv-logisim`、`riscv32e-npc`、`minirv-npc`）此后共用同一份。

唯一的平台差异是 `trap.S` 里那段"设置 `mstatus.MPRV` 以通过 difftest"——NEMU 需要，NPC 的自研 CSR 不保证有这一位。用 `#ifndef __PLATFORM_NPC__` 隔开，行为与合并前逐架构一致。

**为此要先解决一个障碍**：顶层 Makefile 的 `ASFLAGS` 不含 `-D__PLATFORM_*`，汇编看不到平台宏。把那串 `-D` 提取成 `ARCHFLAGS`，同时给 `CFLAGS` 和 `ASFLAGS`：

```make
ARCHFLAGS = -D__ISA__=\"$(ISA)\" ... -D__PLATFORM_$(shell echo $(PLATFORM) | tr a-z A-Z | tr - _)
CFLAGS   += ... $(ARCHFLAGS) ...
ASFLAGS  += -MMD $(INCFLAGS) $(ARCHFLAGS)
```

---

## 五、为什么另外三个文件没有合并

`gpu.c` / `input.c` / `timer.c` 也是两份拷贝，但**没有**合并，理由需要写清楚，否则下次会有人以为是漏了：

- `am/src/riscv/npc/*.c` 是 **RISC-V 专用**的；
- `am/src/platform/nemu/ioe/*.c` 属于 **跨 ISA 共享的 nemu 平台层**——x86、MIPS、LoongArch 的 NEMU 也在用它。而在 x86 上 `inl/outl` 是**端口 I/O 指令**，不是访存。

把它们合并就意味着重构上游的 platform 分层，波及 5 个架构，代价与收益不成比例。

采取的替代措施是**让漂移可被机械检出**：两份文件从 `/* ==== 以下内容两份必须完全一致 ==== */` 标记行起写成**逐字相同**，于是一条 `diff` 就能查：

```bash
cd abstract-machine
M='/==== 以下内容/,$p'
for pair in "am/src/riscv/npc/gpu.c   am/src/platform/nemu/ioe/gpu.c" \
            "am/src/riscv/npc/input.c am/src/platform/nemu/ioe/input.c" \
            "am/src/riscv/npc/timer.c am/src/platform/nemu/ioe/timer.c"; do
  set -- $pair
  diff <(sed -n "$M" "$1") <(sed -n "$M" "$2") && echo "OK $(basename $1)"
done
```

> ⚠️ 写这个检查时踩了一脚：最初把 `diff` 命令本身写进了源文件顶部的注释里，而命令中含有标记文本 `==== 以下`，于是 `sed` 匹配到了**注释自己**，共享段的起点被算到了文件开头。**自引用的标记会失效**——命令因此挪到了本文档，源码里只留一句指向这里的短提示。

这是一个折中：它不能像"合成一份"那样从结构上消灭问题，但把"必须靠人记得"降级成了"一条命令能查出来"。

---

## 六、举一反三

### 自查清单

- [ ] 我正准备写 `#ifdef <架构宏>`——**这个分情况，代码库里有没有人已经封装过了？**
- [ ] 我正准备写一个寄存器下标 / 偏移 / 魔数——它在别处有没有符号名？
- [ ] 我正在复制一段代码到另一个平台——**这段逻辑真的与平台有关吗？** 如果无关，它就不该有第二份。
- [ ] 我刚修好一个 bug——**这段代码在别处还有拷贝吗？**（`git grep` 一个特征串就知道）

### 一条更硬的原则

> **当同一个知识在代码库里有第二份拷贝时，它们迟早会漂移；漂移的那一天，你只会发现其中一份。**

本轮三处漂移全部符合这个模式，且全部是"修一处忘另一处"，没有一处是有意为之。

### 与其他档案的关系

这条和 [BUG-02 第六节](./02-append-char-size-underflow.md#六更深一层不变量不该手写两遍)、[BUG-03](./03-malloc-freelist-null-double-meaning.md) 是同一个家族：

- BUG-02：同一个**不变量**手写了两遍，只维护了一处；
- BUG-03：同一个**变量**编码了两种语义；
- BUG-06：同一个**知识**存在两份实现，只修了一处。

三者的解法方向也一致：**让它只有一份。**

---

## 七、遗留

1. **`gpu.c` / `input.c` / `timer.c` 仍是两份**，靠 diff 检查兜底。彻底解决需要重构 upstream 的 platform 分层，记在 `note/todo/`。
2. **那条 diff 检查没有接进 `make`**。目前要人工执行，理想状态是挂在某个 target 上自动跑。
3. **`riscv32e-nemu` 尚未实测**。本轮修复是静态分析 + 合并的结果，回归测试里的 yield 用例在 `riscv32-nemu` 上恒过；真正检验这条修复必须跑 `ARCH=riscv32e-nemu`。
4. **`c->gpr[2]`（sp）此前在 NEMU 平台上是垃圾**，本轮随 `trap.S` 合并一并修好，但目前没有任何代码读它——要到 PA4 构造用户上下文时才会用上，届时值得单独验一次。
