`include "define.sv"

// ===================================================================
//  sim_top.sv — 支持 reqValid / respValid + 可配置延迟
//
//  core 接口：
//    IFU: ifu_raddr, ifu_reqValid  →  ifu_rdata, ifu_respValid
//    LSU: lsu_addr, lsu_ren, lsu_wen, lsu_wdata, lsu_wmask, lsu_reqValid
//         →  lsu_rdata, lsu_respValid
//
//  延迟模式（修改 sim_sram 实例参数切换）：
//    DELAY_MODE = 0 : 固定延迟（FIXED_DELAY 周期）
//    DELAY_MODE = 1 : LFSR 随机延迟（1 ~ 2^LFSR_WIDTH - 1 周期）
//    DELAY_MODE = 2 : 固定 1 周期（退化为原始行为，调试用）
// ===================================================================

module top (
    input  logic        clk,
    input  logic        rst_n,

    output logic [31:0] pc,
    output logic [31:0] instr,
    output logic [31:0] regs [15:0],

    output logic        debug_wb_have,
    output logic [31:0] debug_wb_pc,
    output logic [31:0] debug_wb_instr,
    output logic        debug_wb_en,
    output logic [4:0]  debug_wb_addr,
    output logic [31:0] debug_wb_data
);

    // ========== IFU SimpleBus ==========
    logic [31:0] ifu_raddr;
    logic        ifu_reqValid;
    logic [31:0] ifu_rdata;
    logic        ifu_respValid;

    // ========== LSU SimpleBus ==========
    logic [31:0] lsu_addr;
    logic        lsu_ren;         // core 输出的读使能
    logic        lsu_reqValid;    // core 输出的请求有效
    logic        lsu_wen;
    logic [31:0] lsu_wdata;
    logic [3:0]  lsu_wmask;
    logic [31:0] lsu_rdata;
    logic        lsu_respValid;

    // ========== CPU 核心 ==========
    core u_core (
        .clk            (clk),
        .rst_n          (rst_n),
        .pc             (pc),
        .instr          (instr),
        .regs           (regs),

        // IFU
        .ifu_raddr      (ifu_raddr),
        .ifu_reqValid   (ifu_reqValid),
        .ifu_rdata      (ifu_rdata),
        .ifu_respValid  (ifu_respValid),

        // LSU
        .lsu_addr       (lsu_addr),
        .lsu_ren        (lsu_ren),
        .lsu_reqValid   (lsu_reqValid),
        .lsu_wen        (lsu_wen),
        .lsu_wdata      (lsu_wdata),
        .lsu_wmask      (lsu_wmask),
        .lsu_rdata      (lsu_rdata),
        .lsu_respValid  (lsu_respValid),

        .debug_wb_have  (debug_wb_have),
        .debug_wb_pc    (debug_wb_pc),
        .debug_wb_instr (debug_wb_instr),
        .debug_wb_en    (debug_wb_en),
        .debug_wb_addr  (debug_wb_addr),
        .debug_wb_data  (debug_wb_data)
    );

    // ==========================================================
    //  IFU 仿真 SRAM
    //
    //  ★ 切换延迟：改 DELAY_MODE
    //     2 → 固定 1 周期（先用这个跑通）
    //     0 → 固定 FIXED_DELAY 周期
    //     1 → LFSR 随机
    // ==========================================================
    sim_sram #(
        .DELAY_MODE  (1),
        .FIXED_DELAY (5),
        .LFSR_WIDTH  (4),
        .LFSR_SEED   (4'hA),
        .HAS_WRITE   (0)
    ) u_sram_ifu (
        .clk       (clk),
        .rst_n     (rst_n),
        .reqValid  (ifu_reqValid),
        .addr      (ifu_raddr),
        .wen       (1'b0),
        .wdata     (32'h0),
        .wmask     (4'h0),
        .respValid (ifu_respValid),
        .rdata     (ifu_rdata)
    );

    // ==========================================================
    //  LSU 仿真 SRAM
    //
    //  reqValid 触发状态机，wen 区分读写
    //  lsu_ren 不需要连入 sram（reqValid 已涵盖）
    // ==========================================================
    sim_sram #(
        .DELAY_MODE  (2),
        .FIXED_DELAY (5),
        .LFSR_WIDTH  (4),
        .LFSR_SEED   (4'h7),     // 和 IFU 用不同种子
        .HAS_WRITE   (1)
    ) u_sram_lsu (
        .clk       (clk),
        .rst_n     (rst_n),
        .reqValid  (lsu_reqValid),
        .addr      (lsu_addr),
        .wen       (lsu_wen),
        .wdata     (lsu_wdata),
        .wmask     (lsu_wmask),
        .respValid (lsu_respValid),
        .rdata     (lsu_rdata)
    );

endmodule