`include "define.sv"

module mem2wb #(
    parameter AW = 32,
    parameter DW = 32
)(
    // 来自 MEM 阶段
    input  logic [DW-1:0] alu_result_in, // 可能是 ALU 结果，也可能是地址
    input  logic [DW-1:0] mem_rdata_in,  // 内存读结果
    input  logic [4:0]    rd_addr_in,
    input  logic [6:0]    opcode_in,

    // 发往 WB 阶段
    output logic [DW-1:0] alu_result_out,
    output logic [DW-1:0] mem_rdata_out,
    output logic [4:0]    rd_addr_out,
    output logic [6:0]    opcode_out
);

    always_comb begin
        // if(!rst_n) begin
        //     alu_result_out = 'h0;
        //     mem_rdata_out  = 'h0;
        //     rd_addr_out    = 5'h0;
        //     opcode_out     = `INST_TYPE_I;
        // end else begin
            alu_result_out = alu_result_in;
            mem_rdata_out  = mem_rdata_in;
            rd_addr_out    = rd_addr_in;
            opcode_out     = opcode_in;
        end
    // end
endmodule