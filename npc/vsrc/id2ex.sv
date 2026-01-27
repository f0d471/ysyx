`include "define.sv"

module id2ex #(
    parameter AW = 32,
    parameter DW = 32
)( 
    input  logic          clk,
    input  logic          rst_n,
    input  logic          id_stall,
    input  logic          id_flush,
    
    // 输入
    input  logic [AW-1:0] instr_addr_in,
    input  logic [DW-1:0] instr_in,
    input  logic [DW-1:0] op1_in,
    input  logic [DW-1:0] op2_in,
    input  logic [DW-1:0] rs1_data_in,   // [新增] 用于 JALR 跳转目标计算
    input  logic [DW-1:0] rs2_data_in,   
    input  logic [4:0]    rd_addr_in,    
    input  logic [DW-1:0] imm_in,        
    input  logic [6:0]    opcode_in,
    input  logic [2:0]    funct3_in,
    input  logic [6:0]    funct7_in,

    // 输出
    output logic [AW-1:0] instr_addr_out,
    output logic [DW-1:0] instr_out,
    output logic [DW-1:0] op1_out,
    output logic [DW-1:0] op2_out,
    output logic [DW-1:0] rs1_data_out,  // [新增]
    output logic [DW-1:0] rs2_data_out,
    output logic [4:0]    rd_addr_out,   
    output logic [DW-1:0] imm_out,
    output logic [6:0]    opcode_out,
    output logic [2:0]    funct3_out,
    output logic [6:0]    funct7_out
);  

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            instr_addr_out <= 'h0;
            instr_out      <= `INST_NOP;
            op1_out        <= 'h0;
            op2_out        <= 'h0;
            rs1_data_out   <= 'h0; // Reset
            rs2_data_out   <= 'h0;
            rd_addr_out    <= 5'h0;
            imm_out        <= 'h0;
            opcode_out     <= `INST_TYPE_I;
            funct3_out     <= 3'h0;
            funct7_out     <= 7'h0;
        end 
        else if (id_flush) begin
            instr_addr_out <= 'h0;
            instr_out      <= `INST_NOP;
            op1_out        <= 'h0;
            op2_out        <= 'h0;
            rs1_data_out   <= 'h0; // Flush
            rs2_data_out   <= 'h0;
            rd_addr_out    <= 5'h0;
            imm_out        <= 'h0;
            opcode_out     <= `INST_TYPE_I;
            funct3_out     <= 3'h0;
            funct7_out     <= 7'h0;
        end 
        else if (id_stall) begin
            // 保持不变
        end 
        else begin
            instr_addr_out <= instr_addr_in;
            instr_out      <= instr_in;
            op1_out        <= op1_in;
            op2_out        <= op2_in;
            rs1_data_out   <= rs1_data_in; // Pass
            rs2_data_out   <= rs2_data_in;
            rd_addr_out    <= rd_addr_in;
            imm_out        <= imm_in;
            opcode_out     <= opcode_in;
            funct3_out     <= funct3_in;
            funct7_out     <= funct7_in;
        end
    end
endmodule