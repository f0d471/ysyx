`include "define.sv" 

module pipe_reg_if2id (
    input  logic    clk,
    input  logic    rst_n,
    input  logic    flush,
    input  logic    stall,     // ← 新增：保持当前值（hold current value）

    input  logic    up_valid,
    output logic    up_ready,
    input  if_id_t  up_data,

    output logic    dn_valid,
    input  logic    dn_ready,
    output if_id_t  dn_data
);
    if_id_t  data_q;
    logic    valid_q;

    assign up_ready = dn_ready | ~valid_q;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n || flush) begin
            valid_q <= 1'b0;
            data_q  <= '0;
        end
        else if (stall) begin
            // 保持（hold）：valid_q和data_q维持原值（无操作）
        end
        else if (up_ready) begin
            valid_q <= up_valid;
            data_q  <= up_data;
        end
    end

    assign dn_valid = valid_q;
    assign dn_data  = data_q;

endmodule