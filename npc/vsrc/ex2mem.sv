`include "define.sv"

module pipe_reg_ex2mem (
    input  logic     clk,
    input  logic     rst_n,
    input  logic     flush,     // 预留（当前流水线跳转不影响这一级）

    // 上游（EX）
    input  logic     up_valid,
    output logic     up_ready,
    input  ex_mem_t  up_data,

    // 下游（MEM）
    output logic     dn_valid,
    input  logic     dn_ready,
    output ex_mem_t  dn_data
);
    ex_mem_t data_q;
    logic    valid_q;

    assign up_ready = dn_ready | ~valid_q;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n || flush) begin
            valid_q        <= 1'b0;
            data_q         <= '0;
        end
        else if (up_ready) begin
            valid_q        <= up_valid;
            data_q         <= up_data;
        end
    end

    assign dn_valid = valid_q;
    assign dn_data  = data_q;

endmodule