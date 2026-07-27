# BUG-04　NEMU GPU：调试用的 printf 留在了每帧必经的热路径上

| 项 | 值 |
| --- | --- |
| 文件 | `abstract-machine/am/src/platform/nemu/ioe/gpu.c` |
| 函数 | `__am_gpu_fbdraw()` |
| 缺陷类型 | 调试残留（debug leftover）→ 性能塌陷 + 输出污染 |
| 严重度 | 🟠 中——不会算错，但会让人误判成别的 bug |
| 引入于 | `0168dce` "device"（PA2 接 VGA 时） |
| 存活时长 | 约 7 周，跨越 10 余次 commit |
| 发现于 | 2026-07-27 abstract-machine 全量复盘 |

---

## 一、题目

```c
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  /* ...裁剪、逐行 memcpy 到 framebuffer... */

  if (ctl->sync) {
    printf("SYNC triggered at x=%d y=%d\n", ctl->x, ctl->y);
    outl(SYNC_ADDR, 1);
  }
}
```

这段代码功能完全正确。它的问题是什么？

<details>
<summary>答案</summary>

`ctl->sync` 为真，意味着"这一帧画完了，提交显示"。也就是说**这行 printf 每帧执行一次**。而在裸机上，`printf` 的每一个字符都要经过 `putch` 写 MMIO 串口寄存器——这是整个系统最慢的操作之一。

</details>

---

## 二、后果

### 2.1 输出污染

跑任何图形程序（`am-kernels` 的 `slider`、`typing-game`，或 navy-apps 上的 NanoS-lite 应用），串口会被这一行刷屏。真正有用的输出——你自己的 `printf` 调试信息、`assert` 失败信息、panic 消息——全部淹没在里面。

**更糟的是它污染了 `make run` 的判定。** 很多自动化检查是 `grep` 串口输出的，多出来的几万行会让你无法判断程序到底跑对没有。

### 2.2 性能塌陷（这才是重点）

估一下量级。以 400×300 的屏幕、每秒 30 帧计：

| 环节 | 代价 |
| --- | --- |
| 一次 `printf` 输出约 30 个字符 | 30 次 `putch` |
| 每次 `putch` = 一次 MMIO 写 | NEMU 里要走完整的 mmio 派发路径 |
| 每帧 1 次 → 每秒 30 次 | ~900 次 MMIO 写/秒 |

在 NEMU 上这只是慢一点。**但同一份 AM 代码的 NPC 版本，MMIO 写要经过总线状态机、几十个周期一次，帧率会直接掉到个位数。**

于是就出现了本次复盘最想强调的那个后果 👇

### 2.3 它会把你引向错误的排查方向

想象半年后的场景：你在 NPC 上跑打字游戏，发现画面卡顿。你的怀疑顺序大概率是：

1. 是不是 VGA 控制器的时序不对？
2. 是不是 framebuffer 的 memcpy 太慢，要不要加 DMA？
3. 是不是 CPU 流水线在这个访存模式下 stall 太多？
4. 是不是总线仲裁器有问题？

**你会花几天时间去测 RTL，而真正的原因是 C 代码里一行忘了删的 printf。**

这就是调试残留的真正危害：它不制造错误的结果，它制造**错误的因果直觉**。你所有的性能测量都被它污染，而它长得太像"正常的日志"，review 时眼睛会直接滑过去。

---

## 三、原理：为什么它能活 7 周

这行代码是在调试"VGA 同步到底有没有被触发"时加的，当时完全合理。它活下来是因为三个原因叠加：

1. **它不会导致失败。** 编译通过、程序跑对、测试通过。任何"以能跑为准"的验收都拦不住它。
2. **它长得像正常代码。** `printf("SYNC triggered...")` 和一条正常的日志在视觉上没有区别，不像 `// TODO` 或 `#if 0` 那样自带记号。
3. **提交它的 commit 叫 "device"。** 一个包含大量改动的笼统 commit，diff 太长，review 时不会逐行看。

同一个文件里的第二处残留佐证了这一点：

```c
void __am_gpu_init() {
  // int i;
  // uint32_t wh = inl(VGACTL_ADDR);
  // ...
  // for (i = 0; i < w * h; i ++) fb[i] = i;
  // outl(SYNC_ADDR, 1);
}
```

这是 PA2 讲义里那段"往 framebuffer 里填花屏，验证显示通路"的验证代码，验证完注释掉了。**注释掉 ≠ 删掉**——它现在只是噪声，而且会让下一个读代码的人（包括半年后的自己）花时间去想"这段为什么被注释了，是不是还有用？"

---

## 四、修复

```c
#include <am.h>
#include <nemu.h>
#include <klib.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
}

/* ... */

  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}
```

三处改动：

1. **删掉 `printf` 那一行。**
2. **删掉 `__am_gpu_init` 里注释掉的验证代码。** 它已经完成了历史使命（证明显示通路是通的），要留就该留在 note 里，不该留在源码里。git 会记住它，需要时 `git log -p` 挖得出来。
3. **`#include <stdio.h>` / `<string.h>` 改成 `<klib.h>`。** 前者只是为了那个 printf 才加的，删了 printf 就没用了；后者是为了 `memcpy`。

第 3 点值得单独说一句 👇

### 为什么 `<stdio.h>` 在这里是错的

AM 的 CFLAGS 里没有 `-nostdinc`：

```
CFLAGS += -O2 -MMD -Wall -Werror $(INCFLAGS) ... -fno-builtin -fno-stack-protector
```

所以 `#include <stdio.h>` **能编过**——它拉到的是交叉工具链自带的 newlib 头文件。但这是在一个 freestanding 的裸机环境里引入了一份 hosted 环境的声明。风险：

- newlib 的 `printf` 原型可能带上你没有的属性或声明；
- 拉进来一大堆 `FILE`、`fpos_t` 之类根本不存在的类型；
- 将来某天真的加了 `-nostdinc`（应该加），这里会突然编不过，而原因很难一眼看出。

**AM 的规矩是：klib 提供的东西一律从 `<klib.h>` 拿。** `printf` / `memcpy` / `strlen` 都在里面。

同一次修复里，`ioe/input.c` 也有一个同样多余的 `#include <stdio.h>`，一并删掉。

---

## 五、举一反三

### 给自己立的规矩

- **调试用的 `printf` 当场就写成可关的形式**，而不是"等下删"。AM/NEMU 里已经有现成的机制：
  ```c
  #ifdef CONFIG_GPU_TRACE
    printf("SYNC at x=%d y=%d\n", ctl->x, ctl->y);
  #endif
  ```
  这样它既留得住（下次调试直接开），又不会静默拖慢系统。NEMU 的 `Log()` 宏、`itrace`/`mtrace`/`ftrace` 就是这个思路——**你在 NEMU 侧已经做对了，只是没把这个习惯带到 AM 侧。**

- **注释掉的代码一律删。** 版本控制的存在就是为了让你敢删。留在源码里的注释代码只有两个作用：增加阅读负担、让人怀疑它是不是还有用。

- **"能跑通"不是提交标准。** 提交前 `git diff --cached` 逐行看一遍——本次这个 bug，只要在提交 `0168dce` 前看过 diff 就一定会发现。

### 排查性能问题时的第一步

以后在 NPC 上遇到"某个功能莫名很慢"，**在动 RTL 之前先做这一步**：把这条路径上所有的 `printf` 数一遍。裸机上一次串口输出的代价远超直觉，一行日志足以让性能数据完全失真。

---

## 六、待办：把这类残留变成能自动发现的

单靠 review 抓不住调试残留（本次就活了 7 周）。可以加的机械手段：

- [ ] 在 `make` 的某个目标里 grep 源码中的可疑模式（`printf("SYNC`、`printf("DEBUG`、`// int i;` 之类），出现就警告——粗糙但有效；
- [ ] 给 AM 加 `-nostdinc`，让"引错头文件"变成编译错误而不是隐患；
- [ ] 把 AM 侧的调试输出统一到一个带开关的宏，从机制上杜绝"裸 printf 留在库里"。

记在 `note/todo/`。

---

**相关**：本文件的裁剪逻辑（`__am_gpu_fbdraw` 的边界处理）本身写得是对的，且和 `am/src/riscv/npc/gpu.c` 几乎逐字相同——那个**双平台复制粘贴**的问题见复盘报告第 9 条，是比本 bug 更值得处理的结构性隐患。
