# 参考资料索引

这里放的是**经典著作、官方规范与学术论文**，用来把一生一芯各个环节背后的通用知识补齐。
一生一芯的讲义在 `../ysyx/`，讲的是"这个项目怎么做"；这里的材料讲的是"这类问题工业界和
学术界怎么想"。

## 取用方式

```bash
bash docs/refs/fetch.sh            # 抓全部
bash docs/refs/fetch.sh os         # 只抓某一类：isa / arch / toolchain / os / hdl
```

下载的 PDF **不纳入 git**（见 `.gitignore`）。原因不是体积，而是再分发：
RISC-V 规范是 CC-BY、GNU 手册是 GFDL，转发没问题；但 OSTEP 与 xv6 讲义作者只授权
免费阅读下载，未授权第三方转发。脚本进仓库、文件不进仓库，既可复现又不替作者做决定。

---

## 与一生一芯各环节的对应关系

| ysyx 环节 | 你实际在做的事 | 对应材料 |
|---|---|---|
| **Makefile / 构建系统** | AM 的多层 Makefile、`$(AM_HOME)/Makefile` 的变量展开与递归 make | `3-toolchain-link/GNU-Make-Manual.pdf` |
| **NEMU 模拟器** | 逐条指令译码执行、difftest 的行为基准 | `1-isa-riscv/RISC-V-ISA-Manual.pdf` |
| **NPC 处理器设计** | 五级流水、冒险处理、AXI4 总线、SoC 集成 | `1-isa-riscv/`、`2-arch-cpu/`、`5-hdl-verif/` |
| **AM 运行时环境** | linker script、`_start`、TRM/CTE/IOE、objcopy 出裸镜像 | `3-toolchain-link/GNU-ld-Linker-Manual.pdf`、`ELF-Format-Spec.pdf`、`RISC-V-ELF-psABI.pdf` |
| **ftrace / 符号表** | 从 ELF 里解析符号、调用栈还原 | `3-toolchain-link/ELF-Format-Spec.pdf`、`DWARF5-Debugging-Format.pdf` |
| **nanos-lite / RT-Thread** | 上下文切换、系统调用、内存管理、文件系统 | `4-os/OSTEP/`、`4-os/xv6-*.pdf` |

---

## 已收录（免费/开放许可）

### 1-isa-riscv —— 指令集规范

| 文件 | 说明 | 许可 |
|---|---|---|
| `RISC-V-ISA-Manual.pdf` | RISC-V 官方 ISA 手册（新版已合并 unprivileged 与 privileged 两卷）。写 NEMU 指令和 NPC 译码器时的唯一判据 | CC-BY-4.0 |
| `RISC-V-ELF-psABI.pdf` | 处理器专属 ABI：寄存器用途约定、调用约定、重定位类型。AM 的 `start.S` 和链接脚本为什么那样写，答案在这里 | CC-BY-4.0 |
| `RISC-V-Assembly-Manual.pdf` | 汇编语法与伪指令展开 | CC-BY-4.0 |
| `RISC-V手册-中文版.pdf` | 《RISC-V 手册：一本开源指令集的指南》，Patterson & Waterman 著，中科院译。官方免费发布的中文版，入门首选 | 官方免费发布 |

### 2-arch-cpu —— 处理器与体系结构

| 文件 | 说明 |
|---|---|
| `Instruction-Sets-Should-Be-Free-The-Case-for-RISC-V.pdf` | Asanović & Patterson, UCB/EECS-2014-146。RISC-V 为什么存在、为什么长成这样。理解"指令集设计取舍"的入口 |
| `Berkeley-RISC-V-Tech-Report.pdf` | 伯克利 RISC-V 技术报告 |

### 3-toolchain-link —— 编译、汇编、链接、调试信息

| 文件 | 说明 |
|---|---|
| `GNU-Make-Manual.pdf` | GNU Make 官方手册。AM 那套 Makefile 里的 `$(shell)`、模式规则、二次展开，都在这本里 |
| `GNU-ld-Linker-Manual.pdf` | 链接器手册，重点看 linker script 一章——AM 的 `linker.ld` 与 `--defsym=_pmem_start` 直接对应 |
| `GNU-as-Assembler-Manual.pdf` | 汇编器手册与伪操作 |
| `ELF-Format-Spec.pdf` | ELF 目标文件格式。搞懂 section/segment 的区别，才明白 objcopy 为什么能从 ELF 抠出裸 bin |
| `DWARF5-Debugging-Format.pdf` | 调试信息格式。ftrace 解析函数名、将来做行号级 trace 的基础 |
| `GNU-C-Manual.pdf` | GNU C 语言参考 |

### 4-os —— 操作系统

| 文件 | 说明 |
|---|---|
| `xv6-a-simple-Unix-like-teaching-OS.pdf` | MIT 6.1810 的 xv6-riscv 讲义。一个能跑的完整类 Unix 内核，RISC-V 版本，和 nanos-lite 的思路可直接对照 |
| `OSTEP/` | 《Operating Systems: Three Easy Pieces》全 68 章。按虚拟化/并发/持久化三条线组织，讲清楚"为什么这么设计"而不只是"怎么实现"。做 nanos-lite 的进程、内存、文件系统时按需查 |

### 5-hdl-verif —— HDL 编码与验证

| 文件 | 说明 |
|---|---|
| `lowRISC-Verilog-Coding-Style.md` | lowRISC 的 Verilog/SystemVerilog 编码规范，工业界实际在用的一套。两段式状态机、`unique case`、复位风格等都有明确条款 |

---

## 纸质书单（有版权，需自行购买或图书馆借阅）

这些是各领域公认的经典，但都是商业出版物，不提供下载。

| 书 | 对应环节 | 一句话 |
|---|---|---|
| 《深入理解计算机系统》(CSAPP) | 贯穿全部 | 这套课的思想母本。第 7 章链接、第 8 章异常控制流，与 AM 和 CTE 直接对应。配套 Lab 在 [csapp.cs.cmu.edu](http://csapp.cs.cmu.edu/3e/labs.html) 免费 |
| 《计算机组成与设计：RISC-V 版》 | NPC 处理器设计 | Patterson & Hennessy。五级流水线、冒险、前递的标准教材写法 |
| 《计算机体系结构：量化研究方法》 | 进阶 | Hennessy & Patterson。等 NPC 跑通了要提性能时再读 |
| 《数字设计与计算机体系结构：RISC-V 版》 | RTL 设计 | Harris & Harris。从逻辑门一路搭到处理器，比上面两本更贴近 RTL |
| 《编译原理》（龙书） | 编译 | Aho 等。做表达式求值、想理解 GCC 在干什么时的参考 |
| 《程序员的自我修养——链接、装载与库》 | AM / 链接 | 俞甲子等。中文世界讲 ELF、链接、装载最透的一本，与 AM 的裸机启动强相关 |

## 免费在线阅读（不下载，链接备查）

| 资源 | 说明 |
|---|---|
| [Crafting Interpreters](https://craftinginterpreters.com/) | 免费在线全文。想理解"从源码到执行"的完整链条 |
| [nand2tetris](https://www.nand2tetris.org/) | 从与非门搭到操作系统，课程材料免费 |
| [Verilator 手册](https://verilator.org/guide/latest/) | 官方文档，只有 HTML |
| [Chisel Bootcamp](https://github.com/freechipsproject/chisel-bootcamp) | ysyxSoC 用 Chisel 写的，要读懂 rocket-chip 需要 |
| [RT-Thread 文档中心](https://www.rt-thread.org/document/site/) | RT-Thread 官方文档 |
| [ysyx 官方讲义](https://ysyx.oscc.cc/docs/) | 一生一芯在线版（离线副本在 `../ysyx/`） |
