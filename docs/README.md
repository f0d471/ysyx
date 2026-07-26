# 知识库指引

这个仓库是一生一芯的原生工程环境，但在这里真正要学的不是"做完一生一芯"，而是
**一整套从晶体管到应用程序的方法论**：数字设计、指令集、微架构、总线、外设驱动、
验证、后端、编译链接、操作系统、图形多媒体。

一生一芯讲义告诉你"这一步该做什么"，但很少讲"这类问题在工业界和学术界是怎么想的"。
这个知识库补的是后者。

```
docs/
├── README.md              ← 你在读的这份指引
├── fetch.sh               ← 一键抓取，可按领域抓
├── ysyx/                  ← 一生一芯 + NJU PA 官方讲义离线副本
│   ├── PA/                    PA0 ~ PA4
│   └── YSYX/                  B ~ F 阶段
│
├── 01-isa-riscv/          指令集规范
├── 02-digital-hdl/        数字设计与 HDL 编码规范
├── 03-arch-cpu/           处理器微架构与体系结构
├── 04-bus-soc/            总线协议与 SoC 互连
├── 05-embedded-periph/    嵌入式外设与驱动
├── 06-verification/       验证方法学
├── 07-backend-eda/        数字后端与 EDA 流程
├── 08-toolchain-link/     编译、汇编、链接、调试信息
├── 09-os-rtos/            操作系统与实时系统
├── 10-graphics-media/     图形、字体与多媒体
└── 11-sim-model/          模拟器与建模方法学
```

## 取用

```bash
bash docs/fetch.sh              # 全部
bash docs/fetch.sh 05           # 按编号
bash docs/fetch.sh embedded     # 或按关键字
```

下载的资料**不纳入 git**，只有 `fetch.sh` 和这份 README 进仓库。原因不是体积，而是
**再分发权**：RISC-V 规范是 CC-BY、GNU 手册是 GFDL，转发无碍；但 OSTEP 与 xv6 讲义
作者只授权免费下载阅读，未授权第三方转发。脚本可复现，就不必替作者做分发决定。

---

## 一、按你手上的工程找资料

这张表是这个知识库的**主入口**。左边是你在仓库里实际动的文件，右边是遇到问题该翻什么。

| 你在动什么 | 具体在干的事 | 该查哪里 |
|---|---|---|
| `nemu/src/isa/riscv32/inst.c` | 逐条实现指令语义 | `01` ISA 手册 |
| `npc/vsrc/decoder.sv` `execute.sv` | 译码、ALU、分支判断 | `01` ISA 手册 · `03` 微架构 |
| `npc/vsrc/*.sv` 的写法本身 | 两段式 FSM、复位风格、位宽 | `02` lowRISC 编码规范 |
| `npc/vsrc/axi4.sv` `axi_arbiter.sv` | AXI4 握手、仲裁、outstanding | `04` 总线规范 |
| `ysyxSoC/perip/*` | UART/SPI/PSRAM/SDRAM 驱动 | `05` 外设与驱动 |
| `npc/csrc/difftest/` | 对拍、golden model | `06` 验证方法学 · `11` 建模 |
| ysyx 后期：综合、时序、布局布线 | STA、面积功耗 | `07` 后端与 EDA |
| `abstract-machine/Makefile` 那一套 | 变量展开、模式规则、递归 make | `08` GNU Make 手册 |
| `abstract-machine/scripts/linker.ld` | 段布局、符号定义、装载地址 | `08` ld 手册 · ELF 规范 |
| `npc/csrc/utils/ftrace.cpp` | 从 ELF 解析符号、还原调用栈 | `08` ELF · DWARF |
| `nanos-lite/src/proc.c` `mm.c` `fs.c` | 进程、内存、文件系统 | `09` OSTEP · xv6 |
| `navy-apps/libs/libminiSDL` 等 | 帧缓冲、字体、音频解码 | `10` 图形与多媒体 |
| NEMU 本身、想理解 QEMU/gem5 | 模拟器的层次与取舍 | `11` 模拟器与建模 |

---

## 二、各领域收录了什么

### 01-isa-riscv —— 指令集规范

写 NEMU 指令、写 NPC 译码器、difftest 判对错，**唯一判据在这里，不要靠猜也不要靠试**。

| 文件 | 说明 | 许可 |
|---|---|---|
| `RISC-V-ISA-Manual.pdf` | 官方 ISA 手册，新版已合并 unprivileged 与 privileged 两卷 | CC-BY-4.0 |
| `RISC-V-ELF-psABI.pdf` | 寄存器用途约定、调用约定、重定位类型。AM 的 `start.S` 和链接脚本为什么那样写，答案在这 | CC-BY-4.0 |
| `RISC-V-Assembly-Manual.pdf` | 汇编语法与伪指令展开 | CC-BY-4.0 |
| `RISC-V手册-中文版.pdf` | Patterson & Waterman 著、中科院译，官方免费发布。入门首选 | 官方免费 |

### 02-digital-hdl —— 数字设计与 HDL 编码规范

| 文件 | 说明 |
|---|---|
| `lowRISC-Verilog-Coding-Style.md` | 工业界实际在用的一套。两段式状态机、`unique case`、复位风格、命名都有明确条款 |

### 03-arch-cpu —— 处理器微架构与体系结构

| 文件 | 说明 |
|---|---|
| `Instruction-Sets-Should-Be-Free-The-Case-for-RISC-V.pdf` | Asanović & Patterson, UCB/EECS-2014-146。RISC-V 为什么存在、为什么长成这样，理解"指令集设计取舍"的入口 |
| `Berkeley-RISC-V-Tech-Report.pdf` | 伯克利 RISC-V 技术报告 |

### 04-bus-soc —— 总线协议与 SoC 互连

你正在重构 AXI4，`ysyxSoC/perip/amba/` 里也躺着 `axi4_delayer.v` 和 `apb_delayer.v`。
**总线的坑几乎都是协议细节没吃透**——比如 VALID 举起后不得撤销、发出的读事务必须收完。

| 文件 | 说明 |
|---|---|
| `TileLink-Spec-1.7.pdf` | SiFive 开放的总线规范。**ysyxSoC 内部的 rocket-chip 用的就是 TileLink**，要读懂 SoC 内部必看 |
| `Wishbone-B4-Spec.pdf` | OpenCores 的开放总线，`ysyxSoC/perip/` 下多个外设是 Wishbone 接口 |

> **AXI4 规范不在这里**：ARM 的 AMBA AXI（IHI 0022）可以免费下载，但要先接受 ARM
> 的许可条款，再分发受限。自己去 [developer.arm.com](https://developer.arm.com/documentation/ihi0022/latest/) 取。

### 05-embedded-periph —— 嵌入式外设与驱动

PLAN.md 的 Phase 6~10 全在这一层：UART 输出字符 → Flash XIP → PSRAM QSPI → SDRAM 时序。
这是**标准的嵌入式开发链**：读 datasheet → 算寄存器映射 → 写裸机驱动 → 抽象成 HAL
(AM 的 IOE) → 再上是 OS 设备框架 (nanos-lite / RT-Thread)。

| 文件 | 说明 |
|---|---|
| `RISC-V-PLIC-Spec.adoc` | 平台级中断控制器。外部设备中断怎么进 CPU |
| `RISC-V-ACLINT-Spec.adoc` | 核内本地中断：定时器中断、软件中断 |

**仓库里本来就有的 datasheet**（不重复下载，直接去这两个路径读）：

| 路径 | 说明 |
|---|---|
| `ysyxSoC/perip/uart16550/doc/UART_spec.pdf` | 16550 是几十年的工业标准 UART。divisor latch、LCR/LSR、轮询与中断两种用法 |
| `ysyxSoC/perip/spi/doc/spi.pdf` | SPI 控制器。Flash XIP 的基础 |

### 06-verification —— 验证方法学

你已经掌握了 difftest（lockstep 对拍），但那只是工业界验证手段里的一种。

| 文件 | 说明 |
|---|---|
| `UVM-1.2-Users-Guide.pdf` | Accellera 官方。工业界 IC 验证的事实标准框架：约束随机、覆盖率驱动、scoreboard、factory |
| `SymbiYosys-Formal-Verification.pdf` | 开源形式验证。和仿真互补——仿真只能证明"这些激励下没错"，形式验证能证明"所有情况下都没错" |

### 07-backend-eda —— 数字后端与 EDA 流程

ysyx 后期阶段（E5「从 RTL 代码到可流片版图」）会用到。

| 文件 | 说明 |
|---|---|
| `OpenROAD-Flow-Docs.pdf` | 全开源的 RTL-to-GDSII 流程：综合、布局、CTS、布线、STA。商业 EDA 那套流程的开源对照物 |

### 08-toolchain-link —— 编译、汇编、链接、调试信息

| 文件 | 说明 |
|---|---|
| `GNU-Make-Manual.pdf` | AM 那套 Makefile 里的 `$(shell)`、模式规则、二次展开、递归 make，都在这本里 |
| `GNU-ld-Linker-Manual.pdf` | 重点看 linker script 一章，与 AM 的 `linker.ld` 和 `--defsym=_pmem_start` 直接对应 |
| `GNU-as-Assembler-Manual.pdf` | 汇编器手册与伪操作 |
| `ELF-Format-Spec.pdf` | 搞懂 section 与 segment 的区别，才明白 objcopy 凭什么能从 ELF 抠出裸 bin |
| `DWARF5-Debugging-Format.pdf` | 调试信息格式。ftrace 现在靠符号表，想做到行号级就得看它 |
| `GNU-C-Manual.pdf` | GNU C 语言参考 |

### 09-os-rtos —— 操作系统与实时系统

| 文件 | 说明 |
|---|---|
| `xv6-a-simple-Unix-like-teaching-OS.pdf` | MIT 6.1810 的 xv6-riscv 讲义。一个能跑的完整类 Unix 内核，RISC-V 版，和 nanos-lite 可直接对照 |
| `OSTEP/` | 《Operating Systems: Three Easy Pieces》全 68 章。按虚拟化/并发/持久化组织，讲"为什么这么设计"而不只是"怎么实现" |

### 10-graphics-media —— 图形、字体与多媒体

`navy-apps/libs/` 下整整一层：`libminiSDL` `libSDL_image` `libSDL_ttf` `libSDL_mixer`
`libvorbis` `libbdf` `libbmp` `libfixedptc`。`nplayer` `nwm` `nterm` `pal` `onscripter`
就是拿它们搭起来的。

| 文件 | 说明 |
|---|---|
| `Vorbis-I-Audio-Codec-Spec.pdf` | Xiph 官方。`libvorbis` 在解什么，音频压缩的基本原理 |
| `BDF-Bitmap-Font-Spec.pdf` | Adobe 位图字体格式。`libbdf` 渲染字符的依据 |

### 11-sim-model —— 模拟器与建模方法学

QEMU / gem5 / SystemC-TLM / C-model 这一族，抽象层次从高到低：

| 层次 | 代表 | 建模什么 | 回答什么问题 |
|---|---|---|---|
| 功能级 ISA 模拟 | QEMU、Spike、**NEMU** | 只保证指令语义，不管周期 | 程序跑对了吗 |
| 周期级微架构 | gem5 | 流水线/Cache/内存的时序 | 这个设计快不快 |
| 事务级系统建模 | SystemC + TLM | 模块、端口、事务 | 整个 SoC 能不能先跑起来 |
| 参考模型 | C-model | 位精确的标准答案 | RTL 写对了吗 |

**你已经在做其中两件**：NEMU 就是功能级 ISA 模拟器（QEMU 的教学简化版，解释执行而非
动态翻译）；difftest 就是标准的 C-model lockstep 对拍。

| 文件 | 说明 |
|---|---|
| `The-gem5-Simulator-Version-20-Plus.pdf` | gem5 官方论文（arXiv 版）。学术界体系结构研究的事实标准，用于在**没有 RTL 时**评估微架构 |
| `SystemC-TLM-2.0-Whitepaper.pdf` | Accellera 官方。TLM-2.0 的 LT/AT 两档建模，虚拟原型的基础 |
| `SystemC-Synthesis-Subset.pdf` | SystemC 的可综合子集，高层次综合的边界在哪 |

---

## 三、纸质书单（有版权，需自行购买或图书馆借阅）

这些是各领域公认的经典，但都是商业出版物，不提供下载。

| 书                       | 对应领域      | 一句话                                                                                                              |
| ----------------------- | --------- | ---------------------------------------------------------------------------------------------------------------- |
| 《深入理解计算机系统》(CSAPP)      | 贯穿全部      | 这套课的思想母本。第 7 章链接、第 8 章异常控制流，与 AM 和 CTE 直接对应。配套 Lab 在 [csapp.cs.cmu.edu](http://csapp.cs.cmu.edu/3e/labs.html) 免费 |
| 《计算机组成与设计：硬件/软件接口 RISC-V 版》 | `03` 微架构 | Patterson & Hennessy，简称 COD。五级流水线、冒险、前递的标准教材写法。买 RISC-V 版，别买 MIPS/ARM 版 |
| 《计算机体系结构：量化研究方法》        | `03` 进阶   | Hennessy & Patterson。等 NPC 跑通了要提性能时再读                                                                            |
| 《数字设计与计算机体系结构：RISC-V 版》 | `02` RTL 设计 | Harris & Harris。从逻辑门一路搭到处理器，比上面两本更贴近 RTL                                                                         |
| 《编译原理》（龙书）              | `08` 编译   | Aho 等。做表达式求值、想理解 GCC 在干什么时的参考                                                                                    |
| 《程序员的自我修养——链接、装载与库》     | `08` 链接   | 俞甲子等。中文世界讲 ELF、链接、装载最透的一本，与 AM 的裸机启动强相关                                                                          |
| 《嵌入式实时操作系统 RT-Thread 设计与实现》 | `05` `09` 嵌入式与 RTOS | 邱祎等。和这个仓库里的 ysyx-rtthread 直接对口 |
| 《Making Embedded Systems》 | `05` 嵌入式 | Elecia White。嵌入式工程实践，讲怎么读 datasheet、怎么组织裸机代码 |
| 《SystemVerilog for Verification》 | `06` 验证 | Chris Spear。UVM 之前必读的 SV 验证特性 |
| 《Hard Real-Time Computing Systems》 | `09` 实时 | Buttazzo。实时调度 RMS/EDF、优先级反转与继承、WCET |
| 《CMOS VLSI Design》 | `07` 后端 | Weste & Harris。想往物理设计走再读 |

## 四、免费在线阅读（不下载，链接备查）

| 资源 | 对应领域 | 说明 |
|---|---|---|
| [AMBA AXI 规范](https://developer.arm.com/documentation/ihi0022/latest/) | `04` | 免费但需接受 ARM 许可，自行下载 |
| [Verilator 手册](https://verilator.org/guide/latest/) | `02` `06` | 官方文档，只有 HTML |
| [Yosys 手册](https://yosyshq.readthedocs.io/projects/yosys/en/latest/) | `07` | 开源综合工具 |
| [QEMU 文档](https://www.qemu.org/docs/master/) | `11` | 动态二进制翻译的工业级实现 |
| [gem5 文档](https://www.gem5.org/documentation/) | `11` | 上手教程与配置脚本 |
| [Crafting Interpreters](https://craftinginterpreters.com/) | `08` `11` | 免费在线全文。从源码到执行的完整链条，通向 JIT |
| [nand2tetris](https://www.nand2tetris.org/) | 贯穿 | 从与非门搭到操作系统，课程材料免费 |
| [Chisel Bootcamp](https://github.com/freechipsproject/chisel-bootcamp) | `02` `03` | ysyxSoC 是 Chisel 写的，读懂 rocket-chip 需要 |
| [RT-Thread 文档中心](https://www.rt-thread.org/document/site/) | `09` | RT-Thread 官方文档 |
| [SDL 2 Wiki](https://wiki.libsdl.org/) | `10` | `libminiSDL` 在模仿的那套 API |
| [ysyx 官方讲义](https://ysyx.oscc.cc/docs/) | — | 在线版，离线副本在 `ysyx/` |

---

## 五、怎么用这个知识库

遇到问题时的一般顺序：

1. **先看 `ysyx/`** —— 讲义要求你做什么、验收标准是什么
2. **涉及"到底该是什么行为"，查规范** —— ISA 手册、总线规范、ELF、psABI。
   这类问题规范是唯一判据，**不要靠试**。上一次 AXI4 重构里两个死锁，
   本质就是"VALID 举起后不得撤销"和"发出的读事务必须收完"这两条协议规则没有兜底
3. **涉及"为什么这么设计"，读经典** —— OSTEP、xv6、CSAPP、那两篇 RISC-V 论文。
   讲义通常只给结论不给来龙去脉
4. **涉及"工业界还有什么手段"，读方法学** —— UVM、形式验证、TLM 建模。
   这部分一生一芯完全不涉及，但决定了你和工业界的差距在哪
