`include "define.sv"

// ===================================================================
//  sim_top.sv — 阶段 B+C：IFU + LSU SimpleBus 仿真存储器
//
//  架构：
//    ┌─────────────── sim_top ──────────────────────┐
//    │                                               │
//    │  ┌── core ────────────────────────────┐       │
//    │  │  fetch  → ifu_raddr ───────────────┼──→ sram_ifu (1 cyc)
//    │  │         ← ifu_rdata ←──────────────┼──     │
//    │  │                                    │       │
//    │  │  memory → lsu_addr/wen/wdata/wmask ┼──→ sram_lsu (1 cyc)
//    │  │         ← lsu_rdata ←──────────────┼──     │
//    │  └────────────────────────────────────┘       │
//    └───────────────────────────────────────────────┘
// ===================================================================

import "DPI-C" function int  paddr_read (input int addr);
import "DPI-C" function void paddr_write(input int addr, input int len, input int data);

module top (
    input  logic        clk,
    input  logic        rst_n,

    // 暴露给 C++ testbench
    output logic [31:0] pc,
    output logic [31:0] instr,
    output logic [31:0] regs [15:0],

    // debug / commit
    output logic        debug_wb_have,
    output logic [31:0] debug_wb_pc,
    output logic [31:0] debug_wb_instr,
    output logic        debug_wb_en,
    output logic [4:0]  debug_wb_addr,
    output logic [31:0] debug_wb_data
);

    // ========== IFU SimpleBus 信号 ==========
    logic [31:0] ifu_raddr;
    logic [31:0] ifu_rdata;

    // ========== LSU SimpleBus 信号 ==========
    logic [31:0] lsu_addr;
    logic        lsu_ren;
    logic        lsu_wen;
    logic [31:0] lsu_wdata;
    logic [3:0]  lsu_wmask;
    logic [31:0] lsu_rdata;

    // ========== CPU 核心 ==========
    core u_core (
        .clk            (clk),
        .rst_n          (rst_n),
        .pc             (pc),
        .instr          (instr),
        .regs           (regs),

        // IFU SimpleBus
        .ifu_raddr      (ifu_raddr),
        .ifu_rdata      (ifu_rdata),

        // ★ [新增] LSU SimpleBus
        .lsu_addr       (lsu_addr),
        .lsu_ren        (lsu_ren),
        .lsu_wen        (lsu_wen),
        .lsu_wdata      (lsu_wdata),
        .lsu_wmask      (lsu_wmask),
        .lsu_rdata      (lsu_rdata),

        .debug_wb_have  (debug_wb_have),
        .debug_wb_pc    (debug_wb_pc),
        .debug_wb_instr (debug_wb_instr),
        .debug_wb_en   (debug_wb_en),
        .debug_wb_addr  (debug_wb_addr),
        .debug_wb_data  (debug_wb_data)
    );

    // ========== IFU 仿真存储器（1 周期读延迟）==========
    always_ff @(posedge clk) begin
        if (!rst_n)
            ifu_rdata <= 32'h00000013;  // NOP
        else
            ifu_rdata <= paddr_read(ifu_raddr);
    end

    // ========== ★ [新增] LSU 仿真存储器（1 周期延迟）==========
    //
    // 读操作：1 周期后返回数据（Load 的 IDLE→WAIT）
    // 写操作：在 posedge 立即执行（Store 无 stall）
    //
    // wmask → len 转换（适配现有 paddr_write DPI-C 接口）
    // 当前 paddr_write(addr, len, data) 的 C++ 实现
    // 已经能根据 addr 的字节偏移正确处理 SB/SH/SW，
    // 因此只需从 wmask 反推 len 即可。
    //
    function automatic int wmask2len(input logic [3:0] mask);
        case (mask)
            4'b0001, 4'b0010, 4'b0100, 4'b1000: return 1;  // SB
            4'b0011, 4'b1100:                    return 2;  // SH
            default:                             return 4;  // SW
        endcase
    endfunction

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            lsu_rdata <= 32'h0;
        end else begin
            // 读：仅当 lsu_ren=1 时执行，避免非访存指令触发越界读
            if (lsu_ren)
                lsu_rdata <= paddr_read(lsu_addr);
            else
                lsu_rdata <= 32'h0;

            // 写：仅当 wen=1 时执行
            if (lsu_wen) begin
                paddr_write(lsu_addr, wmask2len(lsu_wmask), lsu_wdata);
            end
        end
    end

endmodule