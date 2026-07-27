# abstract-machine 缺陷档案

对 `abstract-machine/` 从上游基线 `c04da8c`（NJU-ProjectN ics2024 initialized）到当前 HEAD 的全量复盘中，确认并修复的缺陷。

## 每份档案怎么读

一个缺陷一份，结构固定，**从零开始不需要预备知识**：

| 节 | 内容 |
| --- | --- |
| **〇、前置知识** | 涉及的函数/概念是什么、名字怎么来的、中文叫什么、**标准规定的行为是什么**。不熟悉的话从这里读起 |
| 一、题目 | 只给代码，自己先找问题（答案折叠着） |
| 二、复现 | 最小触发用例 |
| 三、原理 | 为什么会这样、为什么难查 |
| 四、修复 | 改法，以及**为什么不用别的改法** |
| 五～ | 举一反三、同类模式自查清单、本次刻意未处理的遗留 |

前置知识各篇不重复：`printf` 一家子在 [01](./01-vsnprintf-trailing-percent.md)，`size_t` 与无符号运算在 [02](./02-append-char-size-underflow.md)，分配器原理在 [03](./03-malloc-freelist-null-double-meaning.md)，MMIO 与帧缓冲在 [04](./04-gpu-debug-printf-in-hotpath.md)，`atoi` 与字符串转数值在 [05](./05-atoi-missing-sign.md)。

> C 标准条款号按 **C99（ISO/IEC 9899:1999）** 给出。正式文本收费，公开草案 **N1256**（C99 + 三份技术勘误）与 **N1570**（C11）内容足够用。本地 `docs/` 暂无副本，`docs/08-toolchain-link/GNU-C-Manual.pdf` 可作旁证。

## 索引

| # | 标题 | 位置 | 类型 | 严重度 |
| --- | --- | --- | --- | --- |
| [01](./01-vsnprintf-trailing-percent.md) | 格式串以 `%` 结尾会扫出字符串之外 | `klib/src/stdio.c` `vsnprintf` | 越界读 | 🔴 |
| [02](./02-append-char-size-underflow.md) | `n == 0` 时 `n - 1` 无符号下溢，缓冲区被击穿 | `klib/src/stdio.c` `append_char` | 越界写 | 🔴 |
| [03](./03-malloc-freelist-null-double-meaning.md) | `free_list == NULL` 身兼两职，堆耗尽后二次分配 | `klib/src/stdlib.c` `malloc` | 堆破坏 | 🔴 |
| [04](./04-gpu-debug-printf-in-hotpath.md) | 调试 printf 留在每帧必经的热路径上 | `am/.../nemu/ioe/gpu.c` | 调试残留 | 🟠 |
| [05](./05-atoi-missing-sign.md) | 不识别正负号，`atoi("-5")` 返回 0 | `klib/src/stdlib.c` `atoi` | 功能不完整 | 🟠 |
| [06](./06-cte-gpr1-abstraction-bypassed.md) | 现成的 `GPR1` 抽象被绕开，RV32E 下读越界致 yield 失效 | `am/src/riscv/*/cte.c` | 越界读 | 🔴 |
| [07](./07-misc-round2.md) | 第二轮零散修复合辑（6 组） | 多处 | 混合 | 🟠 |

### 分轮次

- **第一轮**（01~05）：逐文件对比上游基线，找"写错了"的地方。
- **第二轮**（06~07）：处理第一轮列出但未动的架构与规范问题，含一次结构性去重（riscv 的 CTE/trap 由两份合并为一份）。

## 验证记录

### 第一轮　2026-07-27，Debian 虚拟机，`riscv32-nemu`（difftest 对 spike 开启）

- **BUG-01 / 02 / 03 / 05**：临时回归测试 15 条断言全部通过，`HIT GOOD TRAP`。验证后测试文件已删除，其设计要点（尤其 BUG-03 怎么在 128MB 堆上快速触达触发点）保留在 [03 第五节](./03-malloc-freelist-null-double-meaning.md#五怎么测它比修它更难)。
- **BUG-04**：跑 `am-kernels/kernels/slider`，12.5 亿条指令、63 秒，串口输出中 `SYNC triggered` 已完全消失。

### 第二轮　待验证

改动面比第一轮大得多（合并了 CTE/trap、重写了格式化引擎、新增 `strtol`/`calloc`/`realloc`），且触及全部 7 个 RISC-V 架构的构建配置。回归测试重新加回 `am-kernels/tests/cpu-tests/tests/klib-bugfix.c`，约 40 条断言。

```bash
cd am-kernels/tests/cpu-tests
make run ARCH=riscv32-nemu  ALL=klib-bugfix    # 主回归
make run ARCH=riscv32e-nemu ALL=klib-bugfix    # 🔴 唯一能真正检验 BUG-06 的架构
make run ARCH=riscv32-nemu                     # 全量 cpu-tests，确认合并没打破基本盘
cd ../../kernels/yield-os && make run ARCH=riscv32-nemu   # CTE 合并后的上下文切换
```

⚠️ 两处**改了但没有对应自动断言**，需人工确认：

1. **`trap.S` 现在会把陷入前的 sp 存进 `c->gpr[2]`**（NEMU 平台此前是垃圾）。目前无人读它，要到 PA4 构造用户上下文时才用得上。
2. **`mstatus.MPRV` 改为按平台条件编译**。逐架构行为应与合并前一致，但 `minirv-logisim` 无从验证。

### ⚠️ 顺带发现：cpu-tests 的 PASS/FAIL 目前不可信

`abstract-machine/scripts/platform/nemu.mk` 的 `NEMUFLAGS` 里没有 `-b`（批处理），`make run` 每次都会掉进交互式 sdb 监视器。而 `nemu/src/utils/state.c`：

```c
int is_exit_status_bad() {
  int good = (nemu_state.state == NEMU_END && nemu_state.halt_ret == 0) ||
    (nemu_state.state == NEMU_QUIT);          // 手动 q 一律算 good
  return !good;
}
```

手敲的 `q` 会把状态置成 `NEMU_QUIT`，退出码 0，于是 Makefile 一律记 PASS。首轮验证中测试明明报了 `1 check(s) FAILED` 且 `HIT BAD TRAP`，末尾仍打印 `[klib-bugfix] PASS`，即为实证。

**上游基线 `c04da8c` 同样没有 `-b`，非本次改动引入。** 但它意味着：只要是手动 `c` 然后 `q`，整个 cpu-tests 的 PASS 列永远是 PASS，真正的信号只有 `HIT GOOD/BAD TRAP`。处理方案待定，记在 `note/todo/`。

## 复盘中提炼出的通用模式

按"下次还会犯"的可能性排序：

1. **同一个不变量被手写多遍，只维护了其中一处**（BUG-02、BUG-03）
   `append_char` 和收尾代码都在维护「可写范围是 `[0, n-1)`」，只有一处判了 `n > 0`。根治办法是把不变量收进单一抽象（sink 结构体 / 单一初始化入口），而不是靠自觉。

2. **用一个正常运行中会自然出现的值当哨兵**（BUG-03）
   `free_list == NULL` 既表示"未初始化"又表示"堆耗尽"。两个独立的是非题就该有两个变量。

3. **`size_t` 参与减法前没证明被减数够大**（BUG-02）
   无符号回绕是标准定义的良好行为，编译器不会警告。`-Wall` 不够，要 `-Wextra`。

4. **状态机在循环体内多次前进，却只在入口检查了终止条件**（BUG-01）
   写任何解析器都要数一遍"循环体内 `p++` 出现了几次，每次之前能否保证 `*p != '\0'`"。

5. **"能跑通"被当成了提交标准**（BUG-04）
   调试残留不会导致失败，所以任何以运行结果为准的验收都拦不住它。只能靠提交前逐行看 `git diff --cached`，或把调试输出从一开始就写成带开关的宏。

6. **继承来的代码 ≠ 验证过的代码**（BUG-05）
   上游骨架给的是"够用就行"的简化实现，且不写明自己简化了什么。"官方给的所以肯定对"是危险假设。

7. **简化可以，但必须写在注释里**（BUG-05、BUG-01 第七节）
   裸机上不背标准库全部包袱是对的；不写明简化了什么，取舍就退化成了缺陷。

8. **同一个知识有第二份实现，就一定会漂移，而且只会修好其中一份**（BUG-06）
   三处漂移全是"修一处忘另一处"，无一处是有意为之。**当发现自己要写 `#ifdef <架构宏>` 时，先去找这个分情况有没有人已经封装过**——`GPR1` 就摆在 `arch/riscv.h` 里，`nanos-lite` 早就在用了。

9. **批量格式化必须限定在本次真正改动的文件范围内**（BUG-07 第六节）
   第二轮清理行尾空格时图省事，对全部 AM 文件跑了一遍 `sed`，一次改动 130 个文件、绝大多数是无关的上游代码。这正是第一轮批评过的第 13 条（注释翻译混进功能 commit）的同一种错误。已全部回退。

## 已修复的架构问题（第二轮）

第一轮列为"已知但未处理"的项目，第二轮处理掉的：

- ✅ **riscv 的 CTE/trap 由两份合并为一份** —— `am/src/riscv/{cte.c,trap.S}`，7 个 RISC-V 架构共用。为此顺带把顶层 Makefile 的 `-D__PLATFORM_*` 提取成 `ARCHFLAGS` 并给到 `ASFLAGS`（原先汇编看不到平台宏）。
- ✅ **cte.c 的魔数** —— `MCAUSE_ECALL_M` / `GPR1` / `SYSCALL_YIELD` / `ECALL_INSTR_LEN` / `MODE_M << 11`。
- ✅ **`Context` 的 union 注释**、**`npc.h` 的相对路径**、**`npc.mk` 的 gdb 目标**、**缩进与行尾**。
- ✅ **klib 格式符缺口** —— `%u` `%X` `%ld` `%lld` `%zu` `%hd` `%-`，`%p` 补 `0x` 前缀，`%d` 修正 `INT_MIN` 取反溢出。
- ✅ **`strtol` / `calloc` / `realloc`**，`atoi` 退化为 `strtol` 的薄包装（顺带解决其 `INT_MIN` 与溢出遗留）。

## 仍未处理

- **klib/stdio 缺少 sink 抽象** —— `printf` 仍用 2048 字节栈缓冲，超长静默截断。→ BUG-02 第六节
- **`gpu.c`/`input.c`/`timer.c` 仍是两份** —— 合并需重构上游 platform 分层，波及 5 个架构，代价与收益不成比例。已改为"共享段逐字相同 + 一条 diff 可检出漂移"。→ BUG-06 第五节
- **那条 diff 检查未接进 `make`** —— 目前要人工执行。
- **CFLAGS 加 `-Wextra` / `-nostdinc`** —— 会引出一批既有告警，单独处理。
- **malloc 的若干弱点** —— `heap.start` 未对齐、用符号位当分配标志、`free` 无校验。→ BUG-03 第七节
- **`%X` 仍输出小写** —— `print_num` 的数字表写死小写，补个 upper 参数即可，但目前无调用方。
- **cpu-tests 的 `-b`** —— 见上文，处理方案待定。

以上逐条记在 `note/todo/`。
