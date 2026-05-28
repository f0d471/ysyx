`include "define.sv"

module fetch #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n,

    input  logic [AW-1:0] pc_pointer,

    // SimpleBus 
    output logic [AW-1:0] ifu_raddr,
    input  logic [DW-1:0] ifu_rdata,
    output logic          ifu_reqValid,
    input  logic          ifu_reqReady,
    input  logic          ifu_respValid,
    output logic          ifu_respReady,

    // 流水线控制
    input  logic          flush,
    input  logic          stall,    

    output logic [DW-1:0] instr_out,
    output logic          ifu_valid
);

    typedef enum logic [1:0] {
        S_REQ       = 2'b00,  // 发送取指请求，等 reqReady
        S_WAIT_RESP = 2'b01,  // 请求已被接受，等 respValid
        S_DONE      = 2'b10   // 指令就绪，等流水线消费
    } state_t;

    state_t state, state_next;
    logic [DW-1:0] instr_latch;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            state <= S_REQ;
        else
            state <= state_next;
    end

    always_comb begin
        state_next = state;
        case (state)
            S_REQ: begin
                if (flush)
                    state_next = S_REQ;
                else if (ifu_reqValid && ifu_reqReady) 
                    state_next = S_WAIT_RESP;
            end
            S_WAIT_RESP: begin
                if (flush)
                    state_next = S_REQ;
                else if (ifu_respValid && ifu_respReady)
                    state_next = S_DONE;
            end
            S_DONE: begin
                if (flush)
                    state_next = S_REQ;
                else if (!stall)
                    state_next = S_REQ;
            end
            default: state_next = S_REQ;
        endcase
    end

    // 锁存响应数据
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            instr_latch <= `INSTR_NOP;
        else if (state == S_WAIT_RESP && ifu_respValid && ifu_respReady && !flush)
            instr_latch <= ifu_rdata;
        else if (flush)
            instr_latch <= `INSTR_NOP;
    end

    assign ifu_raddr     = pc_pointer;
    assign ifu_reqValid  = (state == S_REQ) && !flush && !stall;
    assign ifu_respReady = (state == S_WAIT_RESP) && !flush;
    assign ifu_valid     = (state == S_DONE) && !flush;
    assign instr_out     = ifu_valid ? instr_latch : `INSTR_NOP;

endmodule