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

## 验证记录

2026-07-27，Debian 虚拟机，`riscv32-nemu`（difftest 对 spike 开启）：

- **BUG-01 / 02 / 03 / 05**：临时回归测试 `am-kernels/tests/cpu-tests/tests/klib-bugfix.c` 15 条断言全部通过，`HIT GOOD TRAP`。验证后该文件已删除，其设计要点（尤其 BUG-03 怎么在 128MB 堆上快速触达触发点）保留在 [03 第五节](./03-malloc-freelist-null-double-meaning.md#五怎么测它比修它更难)。
- **BUG-04**：跑 `am-kernels/kernels/slider`，12.5 亿条指令、63 秒，串口输出中 `SYNC triggered` 已完全消失。

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

## 已知但本次未处理

只修"错的"，不动"丑的"和"没做的"。以下已确认存在，但属于重构或待办，不在本批修复范围：

- **klib/stdio 缺少 sink 抽象** —— `printf` 用 2048 字节栈缓冲，超长静默截断，格式化引擎与输出目标耦合。→ BUG-02 第六节
- **npc / nemu 两个平台的 AM 代码是复制粘贴的，且已开始漂移** —— `trap.S` 存 sp、`cte.c` 的 `__riscv_e` 分支、`timer.c` 的 RTC 读序，三处都只改了一边。这是当前最值得处理的结构性隐患。
- **`cte.c` 的魔数** —— `case 11`、`gpr[17]`、`-1`、`0x1800` 四个魔数挤在一起，无符号常量。
- **`Context` 的 union 缺注释** —— `pdir` 借用 `gpr[0]` 槽位的技巧，成立前提（x0 恒零、trap.S 从 `f(1)` 开始）没有写下来。
- **malloc 的若干弱点** —— heap.start 未对齐、用符号位当分配标志、free 无校验。→ BUG-03 第六节
- **CFLAGS 建议加 `-Wextra` 和 `-nostdinc`** —— 前者能静态抓出 BUG-02 那一类，后者能让"引错头文件"变成编译错误。
- **风格** —— `npc/timer.c` 4 空格缩进（AM 全仓 2 空格）、多个文件缺行尾换行、`npc.h` 用相对路径 `../../riscv.h` 逃出 include 目录。

以上逐条记在 `note/todo/`。
