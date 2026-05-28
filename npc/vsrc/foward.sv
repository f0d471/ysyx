`include "define.sv"

module forward_unit (
    input  logic [4:0] ex_rs1_addr,
    input  logic [4:0] ex_rs2_addr,

    input  logic [6:0] ex_stage_opcode,
    input  logic [4:0] ex_stage_rd_addr,
    input  logic [31:0]ex_alu_result,     

    input  logic [6:0] mem_opcode,
    input  logic [4:0] mem_rd_addr,
    input  logic [31:0]ex_mem_alu_result,    
    input  logic [31:0]mem_rdata,           

    input  logic [6:0] wb_opcode,
    input  logic [4:0] wb_rd_addr,
    input  logic [31:0]wb_wr_data,           

    input  logic [31:0]reg_rs1_data,
    input  logic [31:0]reg_rs2_data,

    output logic [31:0]fwd_rs1_data,
    output logic [31:0]fwd_rs2_data
);

    logic [1:0] fwd_rs1_sel;
    logic [1:0] fwd_rs2_sel;

    // 判断指令是否写寄存器
    function automatic logic writes_rd(input logic [6:0] op);
        return (op == 7'b0110011 || // R
                op == 7'b0010011 || // I
                op == 7'b0000011 || // Load
                op == 7'b1101111 || // JAL
                op == 7'b1100111 || // JALR
                op == 7'b0110111 || // LUI
                op == 7'b0010111 || // AUIPC
                op == 7'b1110011);  // SYSTEM
    endfunction

    // RS1 前递选择逻辑
    always_comb begin
        if (writes_rd(ex_stage_opcode) && ex_stage_rd_addr != 5'b0 && ex_stage_rd_addr == ex_rs1_addr)
            fwd_rs1_sel = 2'b01;
        else if (writes_rd(mem_opcode) && mem_rd_addr != 5'b0 && mem_rd_addr == ex_rs1_addr)
            fwd_rs1_sel = 2'b10;
        else if (writes_rd(wb_opcode) && wb_rd_addr != 5'b0 && wb_rd_addr == ex_rs1_addr)
            fwd_rs1_sel = 2'b11;
        else
            fwd_rs1_sel = 2'b00;
    end

    // RS2 前递选择逻辑
    always_comb begin
        if (writes_rd(ex_stage_opcode) && ex_stage_rd_addr != 5'b0 && ex_stage_rd_addr == ex_rs2_addr)
            fwd_rs2_sel = 2'b01;
        else if (writes_rd(mem_opcode) && mem_rd_addr != 5'b0 && mem_rd_addr == ex_rs2_addr)
            fwd_rs2_sel = 2'b10;
        else if (writes_rd(wb_opcode) && wb_rd_addr != 5'b0 && wb_rd_addr == ex_rs2_addr)
            fwd_rs2_sel = 2'b11;
        else
            fwd_rs2_sel = 2'b00;
    end

    // 数据 MUX
    always_comb begin
        case (fwd_rs1_sel)
            2'b01:   fwd_rs1_data = ex_alu_result;
            2'b10:   fwd_rs1_data = (mem_opcode == `INST_TYPE_L) ? mem_rdata : ex_mem_alu_result;
            2'b11:   fwd_rs1_data = wb_wr_data;
            default: fwd_rs1_data = reg_rs1_data;
        endcase
    end

    always_comb begin
        case (fwd_rs2_sel)
            2'b01:   fwd_rs2_data = ex_alu_result;
            2'b10:   fwd_rs2_data = (mem_opcode == `INST_TYPE_L) ? mem_rdata : ex_mem_alu_result;
            2'b11:   fwd_rs2_data = wb_wr_data;
            default: fwd_rs2_data = reg_rs2_data;
        endcase
    end

endmodule