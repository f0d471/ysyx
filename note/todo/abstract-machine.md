# abstract-machine 待办

来自 2026-07-27 两轮全量复盘。已修复的见 `note/bug/abstract-machine/`，这里只列**明确决定暂不做**的，每条附理由与触发条件（什么时候该把它捡起来）。

## 重构

### R1　klib/stdio 的 sink 抽象
**现状**：`printf` 先格式化进 2048 字节栈缓冲区，再逐字符 `putch`。
**代价**：裸机上 2KB 栈帧偏重；超过 2047 字符静默截断；格式化引擎与输出目标耦合，同一套"还能不能写"的判断在 `append_char` 和收尾处各写了一遍（BUG-02 正是漏改其中一处）。
**方案**：把输出目标抽象成 `sink_t { char *buf; size_t cap; size_t pos; }`，`buf == NULL` 时直接 `putch`。于是 `printf` 零缓冲、无长度上限，不变量只有一份。
**为什么没做**：改动覆盖全部五个入口函数，属重构；第二轮已经动了格式化引擎（新增一批转换符），不宜同批再动结构。
**触发条件**：下次要动 stdio 时一并做；或出现 >2KB 的单次输出需求时。
→ [BUG-02 第六节](../bug/abstract-machine/02-append-char-size-underflow.md)

### R2　`gpu.c` / `input.c` / `timer.c` 的双份实现
**现状**：`am/src/riscv/npc/` 与 `am/src/platform/nemu/ioe/` 各一份，逻辑相同。
**为什么不能像 CTE 那样合并**：后者是**跨 ISA 共享的 nemu 平台层**，x86 / MIPS / LoongArch 也在用，而那些 ISA 的 `inl/outl` 是端口 I/O 指令不是访存。合并意味着重构上游的 platform 分层，波及 5 个架构。
**已采取的替代措施**：两份自 `/* ==== 以下内容两份必须完全一致 ==== */` 起写成逐字相同，漂移可被一条 `diff` 检出（命令见 BUG-06 第五节）。
**触发条件**：若将来还要新增第三个 RISC-V 平台，就到了必须重构分层的时候。
→ [BUG-06 第五节](../bug/abstract-machine/06-cte-gpr1-abstraction-bypassed.md)

### R3　把上面那条 diff 检查接进 `make`
**现状**：要人工执行，等于又回到"靠人记得"。
**方案**：挂在 `abstract-machine` 的某个 target 上，或做成一个独立的 `make check-dup`。
**难点**：AM 的 Makefile 是给"编译一个内核"用的，没有天然的位置放仓库自检；放 CI 更合适，但本仓库没有 CI。

## 构建配置

### B1　CFLAGS 加 `-Wextra`
**收益**：能静态抓出 BUG-02 / BUG-07 第二条那一类有符号-无符号混用（`-Wsign-compare` 不在 `-Wall` 里）。
**为什么没做**：会一次性引出一批既有告警（含上游代码），配合 `-Werror` 会直接编译不过。需要先评估告警量，可能要配 `-Wno-unused-parameter` 之类压噪。

### B2　CFLAGS 加 `-nostdinc`
**收益**：让"在 freestanding 环境里误引 hosted 头文件"变成编译错误而非隐患。第一轮就发现 `nemu/ioe/gpu.c`、`input.c` 引了交叉工具链的 `<stdio.h>`/`<string.h>`（已改为 `<klib.h>`），但没有机制阻止下次再犯。
**风险**：可能有其他文件在依赖工具链头文件，需要逐个排查。

### B3　cpu-tests 的 PASS/FAIL 不可信
**现象**：`NEMUFLAGS` 没有 `-b`，`make run` 掉进交互式 sdb；而 `is_exit_status_bad()` 把 `NEMU_QUIT` 算作 good，于是手敲 `q` 一律记 PASS。
**注意**：上游基线同样缺 `-b`，非自己引入。
**候选方案**：
- A：`nemu.mk` 加 `NEMUFLAGS += -b`。`make run` 变批处理，调试改用 `make gdb`。
- B：只在 cpu-tests 的 Makefile 里给 `run` 目标加 `-b`。批量回归无人值守，单跑仍可交互。**（倾向此方案）**
- C：不动，只在文档里记明"真正的信号是 HIT GOOD/BAD TRAP"。
**未决**：等用户表态。

## 功能缺口（等有调用方再补）

| 项 | 说明 |
| --- | --- |
| `%X` 输出大写 | `print_num` 的数字表写死小写，补个 upper 参数即可 |
| `%.Ns` 精度 | 目前只支持宽度不支持精度 |
| `%+` `%#` 标志 | 正号强制显示、`0x`/`0` 前缀 |
| `strtoul` / `atol` / `atoll` | `strtol` 已有，其余照抄即可 |
| `errno` | `strtol` 溢出时按标准应设 `ERANGE`，klib 没有 errno，目前只钳位不报告 |

## malloc 的已知弱点

均属"能用但不严谨"，见 [BUG-03 第七节](../bug/abstract-machine/03-malloc-freelist-null-double-meaning.md)：

1. **`heap.start` 未对齐**就直接当作第一个 `BlockHeader` 的地址。链接脚本目前给的是对齐值，所以没事——属于"靠外部保证"而非"自己保证"。
2. **用 `size` 的符号位表示已分配**。让一个字段身兼两职，与 BUG-03 的根因同类。更清晰的做法是用最低位（8 字节对齐，低 3 位本就恒零）。
3. **`free` 无有效性校验**。只防了重复 free，对野指针、指向块中间的指针毫无防御。加个 magic 字段可在 debug 构建下抓到大部分误用。
4. **`insert_free` 只合并直接相邻的前后各一块**。正确但不彻底，长期运行会碎片化。
5. **`int size` 限制堆 < 2GB**。在 NPC/NEMU（128MB）上无所谓。

## 需要人工确认的改动（第二轮引入）

1. **`trap.S` 现在会把陷入前的 sp 存进 `c->gpr[2]`**——NEMU 平台此前是垃圾值。目前无人读它，要到 PA4 构造用户上下文时才用得上，届时值得单独验一次。
2. **`mstatus.MPRV` 改为 `#ifndef __PLATFORM_NPC__` 条件编译**。逐架构行为应与合并前一致，但 `minirv-logisim` 无从验证。
3. **`riscv32e-nemu` 尚未实测**。BUG-06 的修复是静态分析结果，只有跑这个架构才能真正检验。
