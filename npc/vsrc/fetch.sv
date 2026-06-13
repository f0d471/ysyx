`include "define.sv"
`include "axi4.sv"

module fetch #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n,

    input  logic [AW-1:0] pc_pointer,

    // AXI4 AR 通道 (读地址)
    output logic          ifu_arvalid,
    input  logic          ifu_arready,
    output logic [AW-1:0] ifu_araddr,
    output logic [2:0]    ifu_arsize,
    output logic [7:0]    ifu_arlen,
    output logic [1:0]    ifu_arburst,
    output logic [3:0]    ifu_arid,

    // AXI4 R 通道 (读数据)
    input  logic          ifu_rvalid,
    output logic          ifu_rready,
    input  logic [DW-1:0] ifu_rdata,
    input  logic [1:0]    ifu_rresp,
    input  logic          ifu_rlast,

    // 流水线控制
    input  logic          flush,
    input  logic          stall,    

    output logic [DW-1:0] instr_out,
    output logic          ifu_valid,
    output logic          ifu_error
);

    typedef enum logic [1:0] {
        S_REQ       = 2'b00,  // 发出 arvalid，等 arready
        S_WAIT_RESP = 2'b01,  // 已握手，等 rvalid
        S_DONE      = 2'b10   // 指令就绪，等流水线消费
    } state_t;

    state_t state, state_next;
    logic [DW-1:0] instr_latch;
    logic [1:0]    rresp_latch;

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
                else if (ifu_arvalid && ifu_arready)
                    state_next = S_WAIT_RESP;
            end
            S_WAIT_RESP: begin
                if (flush)
                    state_next = S_REQ;
                else if (ifu_rvalid && ifu_rready)
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

    // 锁存 R 通道响应
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            instr_latch <= `INSTR_NOP;
            rresp_latch <= 2'b00;
        end else if (state == S_WAIT_RESP && ifu_rvalid && ifu_rready && !flush) begin
            instr_latch <= ifu_rdata;
            rresp_latch <= ifu_rresp;
        end else if (flush) begin
            instr_latch <= `INSTR_NOP;
            rresp_latch <= 2'b00;
        end
    end

    // AR 通道输出
    assign ifu_arvalid = (state == S_REQ) && !flush && !stall;
    assign ifu_araddr  = pc_pointer;
    assign ifu_arsize  = `AXI4_SIZE_4B;
    assign ifu_arlen   = 8'h0;
    assign ifu_arburst = `AXI4_BURST_INCR;
    assign ifu_arid    = 4'h0;

    // R 通道输出
    assign ifu_rready = (state == S_WAIT_RESP) && !flush;

    // 流水线输出
    assign ifu_valid = (state == S_DONE) && !flush;
    assign instr_out = ifu_valid ? instr_latch : `INSTR_NOP;
    assign ifu_error = ifu_valid && (rresp_latch != `AXI4_RESP_OKAY);

endmodule
