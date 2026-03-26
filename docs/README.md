# 一生一芯（ysyx）知识库

> 本知识库由自动爬虫从 [ysyx 官网](https://ysyx.oscc.cc) 爬取整理，内容版权归原作者所有。
> 爬取时间：2026-03-27 | 版本：v24.07

---

## 目录结构

本知识库按照一生一芯课程的阶段划分，共分为以下几个目录：

| 目录 | 阶段 | 说明 |
|------|------|------|
| `00_intro/` | 概览 | 课程主页与总体介绍 |
| `F_prestudy/` | F阶段（预学习） | 报名前的预学习任务，包括 Logisim、数字逻辑、RISC-V 基础 |
| `E_basic/` | E阶段（入学准备） | C语言、HDL、Linux、编译工具链等基础知识 |
| `D_nemu/` | D阶段（基础阶段） | 实现 NEMU 模拟器、AM 运行时环境、RTL 基础 |
| `C_npc/` | C阶段（NPC阶段） | 实现单周期 NPC、调试技巧、ELF 文件、异常处理 |
| `B_soc/` | B阶段（SoC阶段） | 总线、SoC 系统、时序优化、缓存、流水线 |
| `PA_ics/` | PA讲义 | 南京大学计算机系统基础实验（PA0~PA4） |

---

## F阶段（预学习）

F阶段是报名前的预学习阶段，目标是让同学们了解课程的基本内容和要求。

| 文件 | 标题 | 简介 |
|------|------|------|
| [F1_ask_question.md](F_prestudy/F1_ask_question.md) | F1 如何科学地提问 | 学习提问的智慧，STFW/RTFM/RTFSC |
| [F2_logisim.md](F_prestudy/F2_logisim.md) | F2 Logisim安装和使用 | 数字电路仿真工具 Logisim 的安装与基本使用 |
| [F3_digital_logic.md](F_prestudy/F3_digital_logic.md) | F3 数字逻辑电路基础 | 组合逻辑、时序逻辑、有限状态机 |
| [F4_state_machine.md](F_prestudy/F4_state_machine.md) | F4 计算机系统的状态机模型 | 用状态机模型理解计算机系统 |
| [F5_simple_processor.md](F_prestudy/F5_simple_processor.md) | F5 支持数列求和的简单处理器 | 在 Logisim 中实现一个简单处理器 |
| [F6_mini_riscv.md](F_prestudy/F6_mini_riscv.md) | F6 功能完备的迷你RISC-V处理器 | 实现支持 RV32E 的迷你 RISC-V 处理器 |

---

## E阶段（入学准备）

E阶段是入学前的基础知识准备阶段，需要完成 PA1 并提交入学答辩申请。

| 文件 | 标题 | 简介 |
|------|------|------|
| [E1_c_programming.md](E_basic/E1_c_programming.md) | E1 C语言程序设计 | C 语言基础，为后续实验做准备 |
| [E2_hdl.md](E_basic/E2_hdl.md) | E2 硬件描述语言 | Verilog/SystemVerilog 基础 |
| [E3_linux.md](E_basic/E3_linux.md) | E3 Linux系统安装和基本使用 | Linux 环境配置与基本命令 |
| [E4_c_to_binary.md](E_basic/E4_c_to_binary.md) | E4 从C代码到二进制程序 | 编译、汇编、链接全流程 |
| [E5_rtl_to_layout.md](E_basic/E5_rtl_to_layout.md) | E5 从RTL代码到可流片版图 | RTL 综合、布局布线到 GDSII 全流程 |
| [E6_pa1.md](E_basic/E6_pa1.md) | E6 完成PA1 | 完成 PA1 实验 |
| [E7_admission.md](E_basic/E7_admission.md) | E7 提交入学答辩申请 | 入学答辩流程与要求 |

---

## D阶段（基础阶段）

D阶段是正式入学后的基础阶段，核心任务是实现 NEMU 模拟器和简单的 RTL 处理器。

| 文件 | 标题 | 简介 |
|------|------|------|
| [D1_nemu.md](D_nemu/D1_nemu.md) | D1 支持RV32IM的NEMU | 实现 RISC-V 指令集模拟器 NEMU |
| [D2_machine_level.md](D_nemu/D2_machine_level.md) | D2 程序的机器级表示 | 汇编语言与机器码的对应关系 |
| [D3_am.md](D_nemu/D3_am.md) | D3 运行时环境（AM） | AbstractMachine 运行时环境 |
| [D4_rtl_riscv.md](D_nemu/D4_rtl_riscv.md) | D4 用RTL实现迷你RISC-V处理器 | 用 Verilog 实现 RISC-V 处理器 |
| [D5_io.md](D_nemu/D5_io.md) | D5 设备和输入输出 | 外设驱动与 I/O 机制 |
| [D6_tapeout.md](D_nemu/D6_tapeout.md) | D6 D阶段流片准备 | D 阶段流片前的准备工作 |

---

## C阶段（NPC阶段）

C阶段的核心任务是实现一个完整的单周期 NPC（New Processor Core）。

| 文件 | 标题 | 简介 |
|------|------|------|
| [C1_tools.md](C_npc/C1_tools.md) | C1 工具和基础设施 | 开发工具链与基础设施搭建 |
| [C2_npc.md](C_npc/C2_npc.md) | C2 支持RV32E的单周期NPC | 实现完整的单周期处理器 |
| [C3_debug.md](C_npc/C3_debug.md) | C3 调试技巧 | 硬件调试方法与技巧 |
| [C4_elf.md](C_npc/C4_elf.md) | C4 ELF文件和链接 | ELF 文件格式与链接器工作原理 |
| [C5_exception.md](C_npc/C5_exception.md) | C5 异常处理和RT-Thread | 异常/中断机制与 RTOS |

---

## B阶段（SoC阶段）

B阶段的目标是将 NPC 接入 SoC 系统，并通过性能优化提升处理器性能。

| 文件 | 标题 | 简介 |
|------|------|------|
| [B1_bus.md](B_soc/B1_bus.md) | B1 总线 | AXI/APB 总线协议与实现 |
| [B2_soc.md](B_soc/B2_soc.md) | B2 SoC计算机系统 | 完整 SoC 系统设计 |
| [B3_timing.md](B_soc/B3_timing.md) | B3 时序分析和优化 | 静态时序分析与关键路径优化 |
| [B4_cache.md](B_soc/B4_cache.md) | B4 性能优化和简易缓存 | Cache 设计与性能分析 |
| [B5_pipeline.md](B_soc/B5_pipeline.md) | B5 流水线处理器 | 五级流水线处理器实现 |

---

## PA讲义（南京大学计算机系统基础实验）

PA 讲义是一生一芯课程的重要组成部分，来源于南京大学的计算机系统基础实验课程。

| 文件 | 标题 | 简介 |
|------|------|------|
| [PA0_home.md](PA_ics/PA0_home.md) | PA 讲义首页 | PA 实验总体介绍 |
| [PA0_env.md](PA_ics/PA0_env.md) | PA0 世界诞生的前夜 | 开发环境配置（预计10小时） |
| [PA1_simple_computer.md](PA_ics/PA1_simple_computer.md) | PA1 开天辟地的篇章 | 最简单的计算机（预计30小时） |
| [PA2_von_neumann.md](PA_ics/PA2_von_neumann.md) | PA2 简单复杂的机器 | 冯诺依曼计算机系统（预计60小时） |
| [PA3_batch.md](PA_ics/PA3_batch.md) | PA3 穿越时空的旅程 | 批处理系统（预计60小时） |
| [PA4_multitask.md](PA_ics/PA4_multitask.md) | PA4 虚实交错的魔法 | 分时多任务（预计60小时） |

---

## 课程阶段总览

```
F阶段（预学习）→ E阶段（入学准备）→ 入学答辩
    ↓
D阶段（基础）→ C阶段（NPC）→ B阶段（SoC）→ A阶段 → S阶段
    ↑
PA讲义（贯穿 D/C/B 阶段）
```

一生一芯课程官网：[https://ysyx.oscc.cc](https://ysyx.oscc.cc)
