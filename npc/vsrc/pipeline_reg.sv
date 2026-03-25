`include "define.sv"

module pipe_reg #(
    parameter DW = 32       // 数据位宽，实例化时用 $bits(xxx_t)
)(
    input  logic          clk,
    input  logic          rst_n,
    input  logic          flush,
    input  logic          stall,      

    input  logic          up_valid,
    output logic          up_ready,
    input  logic [DW-1:0] up_data,

    output logic          dn_valid,
    input  logic          dn_ready,
    output logic [DW-1:0] dn_data
);

    logic [DW-1:0] data_q;
    logic           valid_q;

    assign up_ready = ~stall & (dn_ready | ~valid_q);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n || flush) begin
            valid_q <= 1'b0;
            data_q  <= '0;
        end
        else if (stall) begin
            // hold
        end
        else if (up_ready) begin
            valid_q <= up_valid;
            data_q  <= up_data;
        end
    end

    assign dn_valid = valid_q;
    assign dn_data  = data_q;

endmodule