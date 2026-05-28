module writeback #(
    parameter DW = 32
)(
    input  logic [DW-1:0] alu_result_in,
    input  logic [DW-1:0] mem_rdata_in,
    input  logic          wr_en_in,
    input  logic          is_load_in,
    input  logic [4:0]    rd_addr_in,

    output logic          wb_en,
    output logic [4:0]    wb_addr,
    output logic [DW-1:0] wb_data
);

    assign wb_addr = rd_addr_in;
    assign wb_en   = wr_en_in;
    assign wb_data = is_load_in ? mem_rdata_in : alu_result_in;

endmodule
