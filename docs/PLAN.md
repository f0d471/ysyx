# NPC → ysyxSoC 实施计划

## 当前状态

- 五级流水线 RV32I 处理器（IF/ID/EX/MEM/WB）
- SimpleBus 握手（reqValid/reqReady/respValid/respReady）
- IFU/LSU 独立端口，LFSR 随机延迟仿真
- CSR 支持（ecall/mret/csrrw/csrrs）
- AXI4 协议定义已完成（axi4.sv）
- AXI4 仲裁器已完成（axi_arbiter.sv）
- ysyxSoC 顶层包装已完成（ysyx_250309.sv）
- ysyxSoCFull.v 已生成

## 阶段划分

### Phase 1：AXI4 基础接入 ✅ 已完成

- [x] axi4.sv — 协议定义（参数、结构体、默认值）
- [x] axi_arbiter.sv — SimpleBus → AXI4 仲裁器
- [x] ysyx_250309.sv — 顶层包装（对齐 cpu-interface.md）

### Phase 2：错误处理与异常 ← 当前

- [ ] fetch.sv — 状态机增加 rresp 检查
- [ ] mem.sv — 状态机增加 rresp/bresp 检查
- [ ] core_top.sv — 新增 ifu_rresp / lsu_rresp / lsu_bresp 输入端口
- [ ] execute.sv — 新增 Access Fault 异常（mcause=1 取指/5 load/7 store）
- [ ] define.sv — 新增 TRAP_CAUSE_ACCESS_FAULT 常量
- [ ] ysyx_250309.sv — 将 rresp/bresp 连入 core

### Phase 3：AXI4 仿真验证

- [ ] sim_top.sv — 改造为 AXI4 Slave 存储器模型（替换 DPI-C）
- [ ] 实现单次传输（len=0, size=4B, burst=INCR）
- [ ] 验证取指流程：core → arbiter → AXI4 slave → 返回指令
- [ ] 验证 load 流程：core → arbiter → AXI4 slave → 返回数据
- [ ] 验证 store 流程：core → arbiter → AXI4 slave → 写回复
- [ ] LFSR 随机延迟测试通过
- [ ] 运行 cpu-tests 验证

### Phase 4：接入 ysyxSoC

- [ ] 编译选项添加 ysyxSoC 的 Verilog 文件列表
- [ ] 添加 --timescale "1ns/1ns" 和 --no-timing
- [ ] 修改 ysyxSoCFull.v 中的 ysyx_00000000 为 ysyx_250309
- [ ] 添加 flash_read / mrom_read DPI-C 函数
- [ ] 添加 Verilated::commandArgs(argc, argv)
- [ ] 验证 NPC 在 SoC 环境中能正常取指执行

### Phase 5：MROM 取指验证

- [ ] 修改复位 PC 为 0x2000_0000（MROM 地址）
- [ ] 实现 mrom_read() 函数
- [ ] 验证从 MROM 取出 ebreak 指令并结束仿真

### Phase 6：UART 输出

- [ ] 编写 char-test 程序
- [ ] 通过 UART16550（0x1000_0000）输出字符
- [ ] 实现 putch() 函数
- [ ] 设置 UART 除数寄存器
- [ ] 轮询 UART 状态寄存器

### Phase 7：AM 运行时环境

- [ ] 创建 riscv32e-ysyxsoc AM
- [ ] 实现 TRM API（堆区、halt、putch）
- [ ] 运行 cpu-tests 中的 dummy 测试
- [ ] 实现 bootloader 将数据段从 MROM 加载到 SRAM
- [ ] 重新添加 DiffTest（NEMU 添加 MROM/SRAM）

### Phase 8：Flash 支持

- [ ] 实现 flash_read() 通过 SPI 读取 flash
- [ ] 实现 XIP 模式（在 spi_top_apb.v 中）
- [ ] 用 flash 替代 MROM（复位 PC 改为 0x3000_0000）
- [ ] 运行 coremark 等程序

### Phase 9：PSRAM 支持

- [ ] 实现 PSRAM 颗粒仿真模型（QSPI 协议）
- [ ] 将数据段分配到 PSRAM（0x8000_0000）
- [ ] 运行 microbench test 规模

### Phase 10：SDRAM 支持

- [ ] 实现 SDRAM 颗粒仿真模型
- [ ] 扩展 SDRAM 控制器到 32 位数据位宽
- [ ] 将程序加载到 SDRAM 执行

## 依赖关系

```
Phase 1 (AXI4 定义) ──► Phase 2 (错误处理) ──► Phase 3 (仿真验证)
                                                      │
                                                      ▼
                                              Phase 4 (接入 SoC)
                                                      │
                              ┌───────────────┬───────┼───────┬──────────┐
                              ▼               ▼       ▼       ▼          ▼
                        Phase 5 (MROM)  Phase 6 (UART)  Phase 7 (AM)
                                                      │
                                              ┌───────┼───────┐
                                              ▼       ▼       ▼
                                        Phase 8   Phase 9  Phase 10
                                        (Flash)   (PSRAM)  (SDRAM)
```

## 关键里程碑

| 里程碑 | 验证标准 | 预计阶段 |
|--------|----------|----------|
| AXI4 仿真通过 | cpu-tests 全部通过（带随机延迟） | Phase 3 |
| SoC 取指成功 | NPC 在 ysyxSoC 中取出 ebreak 并结束 | Phase 5 |
| 字符输出 | char-test 输出 'A' | Phase 6 |
| AM 程序运行 | dummy 测试通过 | Phase 7 |
| 完整程序 | coremark / microbench 可运行 | Phase 8-9 |
| RT-Thread | RT-Thread 可启动 | Phase 9 |
