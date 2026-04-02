`include "define.sv"
// ===================================================================
//  fetch.sv — 支持 reqValid / respValid 的 IFU
//
//  协议：
//    CPU → MEM:  ifu_reqValid, ifu_raddr
//    MEM → CPU:  ifu_respValid, ifu_rdata
//
//  状态机（三状态）：
//    S_IDLE      : 发出 reqValid=1, raddr=PC → 进入 S_WAIT_RESP
//    S_WAIT_RESP : 等待 respValid
//                  respValid=1 && up_ready=1 → 指令直通 IF/ID, 回到 S_IDLE
//                  respValid=1 && up_ready=0 → 锁存指令, 进入 S_HOLD
//                  flush                     → 放弃请求, 回到 S_IDLE
//    S_HOLD      : 已拿到指令, 等待下游 up_ready
//                  up_ready=1                → 放行, 回到 S_IDLE
//                  flush                     → 丢弃锁存指令, 回到 S_IDLE
//
//  Bug 修复说明（相比旧版）：
//    旧版在 S_WAIT_RESP 收到 respValid 后无条件回到 S_IDLE，
//    若此时下游因 lsu_busy/load_stall 导致 up_ready=0，
//    指令会被丢弃，造成流水线错位。
//    新版引入 S_HOLD 状态，将已取到的指令锁存，
//    直到下游 up_ready=1 才真正放行并回到 S_IDLE。
// ===================================================================
module fetch #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n,
    input  logic [AW-1:0] pc_pointer,
    // --- SimpleBus 接口 ---
    output logic [AW-1:0] ifu_raddr,
    input  logic [DW-1:0] ifu_rdata,
    output logic          ifu_reqValid,
    input  logic          ifu_respValid,
    // --- 流水线控制 ---
    input  logic          flush,
    input  logic          up_ready,      // ★ 新增：来自 u_if2id 的 up_ready
    output logic [DW-1:0] instr_out,
    output logic          ifu_valid
);
    // =============================================================
    //  状态机
    // =============================================================
    localparam S_IDLE      = 2'd0;
    localparam S_WAIT_RESP = 2'd1;
    localparam S_HOLD      = 2'd2;   // ★ 新增：已取到指令，等待下游 ready

    logic [1:0] state, state_next;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            state <= S_IDLE;
        else
            state <= state_next;
    end

    always_comb begin
        case (state)
            S_IDLE: begin
                state_next = flush ? S_IDLE : S_WAIT_RESP;
            end
            S_WAIT_RESP: begin
                if (flush)
                    state_next = S_IDLE;
                else if (ifu_respValid && up_ready)
                    state_next = S_IDLE;      // 直通：指令直接进入 IF/ID
                else if (ifu_respValid && !up_ready)
                    state_next = S_HOLD;      // 锁存：下游还没准备好
                else
                    state_next = S_WAIT_RESP;
            end
            S_HOLD: begin
                if (flush)
                    state_next = S_IDLE;      // 冲刷：丢弃锁存的指令
                else if (up_ready)
                    state_next = S_IDLE;      // 下游准备好了，放行
                else
                    state_next = S_HOLD;
            end
            default: state_next = S_IDLE;
        endcase
    end

    // =============================================================
    //  锁存指令（S_HOLD 期间保存 ifu_rdata）
    // =============================================================
    logic [DW-1:0] held_instr;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            held_instr <= `INST_NOP;
        else if (state == S_WAIT_RESP && ifu_respValid && !up_ready && !flush)
            held_instr <= ifu_rdata;   // 进入 S_HOLD 时锁存
    end

    // =============================================================
    //  输出
    // =============================================================

    // 请求信号：仅在 S_IDLE 且无 flush 时发出
    assign ifu_reqValid = (state == S_IDLE) && !flush;
    assign ifu_raddr    = pc_pointer;

    // 指令有效：
    //   S_WAIT_RESP 收到 respValid（无论 up_ready，都先给出 valid）
    //   S_HOLD 期间持续给出 valid，直到 up_ready 或 flush
    assign ifu_valid =
        (!flush && state == S_WAIT_RESP && ifu_respValid) ||
        (!flush && state == S_HOLD);

    // 指令数据：
    //   S_WAIT_RESP → 直接用 SRAM 返回的 ifu_rdata（组合逻辑，无需寄存）
    //   S_HOLD      → 用锁存的 held_instr
    always_comb begin
        if (!flush && state == S_HOLD)
            instr_out = held_instr;
        else if (!flush && state == S_WAIT_RESP && ifu_respValid)
            instr_out = ifu_rdata;
        else
            instr_out = `INST_NOP;
    end

endmodule
