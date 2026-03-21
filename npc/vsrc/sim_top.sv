`include "define.sv"

// ===================================================================
//  sim_top (阶段 A)：薄包装层
//
//  当前阶段：只是透传，不改任何时序
//  DPI-C 仍在 core 内部的 fetch.sv / mem.sv 中
//
//  后续阶段 B/C：
//    - core 内部去掉 DPI-C，fetch/mem 改为 SimpleBus 端口
//    - 在这里添加仿真 memory slave（带 1 周期延迟）
// ===================================================================

module top (
    input  logic        clk,
    input  logic        rst_n,

    // 暴露给 C++ testbench
    output logic [31:0] pc,
    output logic [31:0] instr,
    output logic [31:0] regs [15:0],

    // debug / commit（C++ 用这些做 trace 和 difftest）
    output logic        debug_wb_have,
    output logic [31:0] debug_wb_pc,
    output logic [31:0] debug_wb_instr,
    output logic        debug_wb_ena,
    output logic [4:0]  debug_wb_addr,
    output logic [31:0] debug_wb_data
);

    // ========== CPU 核心 ==========
    core u_core (
        .clk            (clk),
        .rst_n          (rst_n),
        .pc             (pc),
        .instr          (instr),
        .regs           (regs),
        .debug_wb_have  (debug_wb_have),
        .debug_wb_pc    (debug_wb_pc),
        .debug_wb_instr (debug_wb_instr),
        .debug_wb_ena   (debug_wb_ena),
        .debug_wb_addr  (debug_wb_addr),
        .debug_wb_data  (debug_wb_data)
    );

    // ========== 后续阶段在这里添加 ==========
    // 阶段 B：IFU memory slave
    // 阶段 C：LSU memory slave

endmodule