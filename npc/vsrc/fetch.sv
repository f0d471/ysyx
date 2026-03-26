`include "define.sv"

// ===================================================================
//  fetch.sv — 支持 reqValid / respValid 的 IFU
//
//  协议：
//    CPU → MEM:  ifu_reqValid, ifu_raddr
//    MEM → CPU:  ifu_respValid, ifu_rdata
//
//  状态机：
//    idle      : 发出 reqValid=1, raddr=PC → 进入 wait_resp
//    wait_resp : 等待 respValid
//                respValid=1 → 拿到指令, ifu_valid=1, 回到 idle
//                respValid=0 → 继续等
//                flush       → 放弃请求, 回到 idle
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
    output logic [DW-1:0] instr_out,
    output logic          ifu_valid
);

    // =============================================================
    //  状态机
    // =============================================================
    
    localparam S_IDLE      = 1'b0;
    localparam S_WAIT_RESP = 1'b1;

    logic state, state_next;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            state <= S_IDLE;
        else
            state <= state_next;
    end

    always_comb begin
        case (state)
            S_IDLE:      state_next = flush ? S_IDLE : S_WAIT_RESP;
            S_WAIT_RESP: state_next = (flush || ifu_respValid) ? S_IDLE : S_WAIT_RESP;
            default:     state_next = S_IDLE;
        endcase
    end

    // =============================================================
    //  输出
    // =============================================================

    // 请求信号：idle 时发出取指请求
    assign ifu_reqValid = (state == S_IDLE) && !flush;
    assign ifu_raddr    = pc_pointer;

    // 指令有效：wait_resp 且收到 respValid 且无 flush
    assign ifu_valid = (state == S_WAIT_RESP) && ifu_respValid && !flush;

    // 指令数据
    assign instr_out = ifu_valid ? ifu_rdata : `INST_NOP;

endmodule