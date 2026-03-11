module pipe_reg_id2ex (
    input  logic    clk,
    input  logic    rst_n,
    input  logic    flush,      // 来自 EX：跳转时清空

    // 上游（ID）
    input  logic    up_valid,
    output logic    up_ready,
    input  id_ex_t  up_data,

    // 下游（EX）
    output logic    dn_valid,
    input  logic    dn_ready,
    output id_ex_t  dn_data
);
    id_ex_t  data_q;
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