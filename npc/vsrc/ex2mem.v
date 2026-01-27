`include "define.v"

module ex2mem #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n,
    // input  logic          mem_stall, // 预留给内存暂停

    // 来自 EX 阶段
    input  logic [AW-1:0] pc_in,
    input  logic [DW-1:0] alu_result_in,
    input  logic [DW-1:0] rs2_data_in, // Store Data
    input  logic [4:0]    rd_addr_in,
    input  logic [6:0]    opcode_in,
    input  logic [2:0]    funct3_in,

    // 发往 MEM 阶段
    output logic [AW-1:0] pc_out,
    output logic [DW-1:0] alu_result_out,
    output logic [DW-1:0] rs2_data_out,
    output logic [4:0]    rd_addr_out,
    output logic [6:0]    opcode_out,
    output logic [2:0]    funct3_out
);

    always_ff @(posedge clk or negedge rst_n) begin
        if(!rst_n) begin
            pc_out         <= 'h0;
            alu_result_out <= 'h0;
            rs2_data_out   <= 'h0;
            rd_addr_out    <= 5'h0;
            opcode_out     <= `INST_TYPE_I; // NOP
            funct3_out     <= 3'h0;
        end else begin
            pc_out         <= pc_in;
            alu_result_out <= alu_result_in;
            rs2_data_out   <= rs2_data_in;
            rd_addr_out    <= rd_addr_in;
            opcode_out     <= opcode_in;
            funct3_out     <= funct3_in;
        end
    end
endmodule