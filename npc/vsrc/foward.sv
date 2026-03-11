`include "define.sv"

module forward_unit (
    input  logic [4:0] ex_rs1_addr,
    input  logic [4:0] ex_rs2_addr,

    // 当前在 EX 阶段的指令（id_ex_dn）
    input  logic [4:0] ex_stage_rd_addr,
    input  logic [6:0] ex_stage_opcode,

    // 在 MEM 阶段的指令（ex_mem_dn）
    input  logic [4:0] mem_rd_addr,
    input  logic [6:0] mem_opcode,

    // 在 WB 阶段的指令（mem_wb_dn）
    input  logic [4:0] wb_rd_addr,
    input  logic [6:0] wb_opcode,

    // 00=寄存器堆  01=EX前递  10=MEM前递  11=WB前递
    output logic [1:0] fwd_rs1_sel,
    output logic [1:0] fwd_rs2_sel
);

    function automatic logic writes_rd(input logic [6:0] op);
        return (op == 7'b0110011 || // R
                op == 7'b0010011 || // I
                op == 7'b0000011 || // Load
                op == 7'b1101111 || // JAL
                op == 7'b1100111 || // JALR
                op == 7'b0110111 || // LUI
                op == 7'b0010111 || // AUIPC
                op == 7'b1110011);  // SYSTEM(CSR)
    endfunction

    always_comb begin
        // 优先级：EX > MEM > WB > 寄存器堆
        if (writes_rd(ex_stage_opcode) && ex_stage_rd_addr != 5'b0
                                       && ex_stage_rd_addr == ex_rs1_addr)
            fwd_rs1_sel = 2'b01;
        else if (writes_rd(mem_opcode) && mem_rd_addr != 5'b0
                                       && mem_rd_addr == ex_rs1_addr)
            fwd_rs1_sel = 2'b10;
        else if (writes_rd(wb_opcode)  && wb_rd_addr != 5'b0
                                       && wb_rd_addr == ex_rs1_addr)
            fwd_rs1_sel = 2'b11;
        else
            fwd_rs1_sel = 2'b00;
    end

    always_comb begin
        if (writes_rd(ex_stage_opcode) && ex_stage_rd_addr != 5'b0
                                       && ex_stage_rd_addr == ex_rs2_addr)
            fwd_rs2_sel = 2'b01;
        else if (writes_rd(mem_opcode) && mem_rd_addr != 5'b0
                                       && mem_rd_addr == ex_rs2_addr)
            fwd_rs2_sel = 2'b10;
        else if (writes_rd(wb_opcode)  && wb_rd_addr != 5'b0
                                       && wb_rd_addr == ex_rs2_addr)
            fwd_rs2_sel = 2'b11;
        else
            fwd_rs2_sel = 2'b00;
    end

endmodule