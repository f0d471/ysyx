`include "define.sv"

module decode #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic [AW-1:0] instr_addr_in, // PC from IF/ID
    input  logic [DW-1:0] instr_in,      // Instruction from IF/ID
    
    // To Register  (Read Addr)
    output logic [4:0]    rd_rs1_addr,
    output logic [4:0]    rd_rs2_addr,
    
    // From Register (Read Data)
    input  logic [DW-1:0] rd_rs1_data,
    input  logic [DW-1:0] rd_rs2_data,
    
    // To Execute
    output logic [4:0]    rd_addr_out,   // 目标寄存器 (rd)
    output logic [DW-1:0] op1_out,       // ALU 操作数 1
    output logic [DW-1:0] op2_out,       // ALU 操作数 2
    output logic [DW-1:0] imm_out,       // 立即数
    
    // To Execute for decode
    output logic [6:0]    opcode_out,
    output logic [2:0]    funct3_out,
    output logic [6:0]    funct7_out
);

    logic [6:0] opcode;
    logic [4:0] rd;
    logic [2:0] funct3;
    logic [4:0] rs1;
    logic [4:0] rs2;
    logic [6:0] funct7;
    logic [31:0] imm;

    // 1. 字段提取
    assign opcode = instr_in[6:0];
    assign rd     = instr_in[11:7];
    assign funct3 = instr_in[14:12];
    assign rs1    = instr_in[19:15];
    assign rs2    = instr_in[24:20];
    assign funct7 = instr_in[31:25];

    // 透传给下一级
    assign rd_addr_out = rd;
    assign opcode_out  = opcode;
    assign funct3_out  = funct3;
    assign funct7_out  = funct7;
    assign imm_out     = imm;

    // 2. 立即数生成 (Immediate Generation)
    always_comb begin
        case(opcode)
            `INST_TYPE_I, `INST_TYPE_L, `INST_TYPE_JALR:
                imm = {{20{instr_in[31]}}, instr_in[31:20]};
            `INST_TYPE_S:
                imm = {{20{instr_in[31]}}, instr_in[31:25], instr_in[11:7]};
            `INST_TYPE_B:
                imm = {{20{instr_in[31]}}, instr_in[7], instr_in[30:25], instr_in[11:8], 1'b0};
            `INST_TYPE_J: // JAL
                imm = {{12{instr_in[31]}}, instr_in[19:12], instr_in[20], instr_in[30:21], 1'b0};
            `INST_TYPE_U_LUI, `INST_TYPE_U_AUIPC:
                imm = {instr_in[31:12], 12'h0};
            default:
                imm = 32'h0;
        endcase
    end

    // 3. 操作数选择 (Operand Mux Logic)
    always_comb begin
        // 默认行为
        rd_rs1_addr = 5'h0;
        rd_rs2_addr = 5'h0;
        op1_out     = 32'h0;
        op2_out     = 32'h0;

        case(opcode)
            `INST_TYPE_I: begin // ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI 
                rd_rs1_addr = rs1;
                rd_rs2_addr = 5'h0;
                op1_out     = rd_rs1_data;
                op2_out     = imm;
            end
            
            `INST_TYPE_R: begin // ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR ,AND 
                rd_rs1_addr = rs1;
                rd_rs2_addr = rs2;
                op1_out     = rd_rs1_data;
                op2_out     = rd_rs2_data;
            end
            
            `INST_TYPE_B: begin // BEQ, BNE, BEQ, BNE, BLT, BGE, BLTU, BGEU
                rd_rs1_addr = rs1;
                rd_rs2_addr = rs2;
                op1_out     = rd_rs1_data; 
                op2_out     = rd_rs2_data;
            end
            
            `INST_TYPE_S: begin // SW, SH, SB
                rd_rs1_addr = rs1;
                rd_rs2_addr = rs2; 
                op1_out     = rd_rs1_data;
                op2_out     = imm; 
            end
            
            `INST_TYPE_L: begin // LW, LH, LB, LBU, LHU
                rd_rs1_addr = rs1;
                rd_rs2_addr = 5'h0;
                op1_out     = rd_rs1_data;
                op2_out     = imm; 
            end
            
            `INST_TYPE_J: begin // JAL
                rd_rs1_addr = 5'h0;
                rd_rs2_addr = 5'h0;
                op1_out     = instr_addr_in; 
                op2_out     = 32'd4;
            end
            
            `INST_TYPE_JALR: begin // JALR
                rd_rs1_addr = rs1;
                rd_rs2_addr = 5'h0;
                op1_out     = instr_addr_in; 
                op2_out     = 32'd4;
            end
            
            `INST_TYPE_U_LUI: begin // LUI
                rd_rs1_addr = 5'h0;
                rd_rs2_addr = 5'h0;
                op1_out     = 32'h0;
                op2_out     = imm;
            end
            
            `INST_TYPE_U_AUIPC: begin // AUIPC
                rd_rs1_addr = 5'h0;
                rd_rs2_addr = 5'h0;
                op1_out     = instr_addr_in; 
                op2_out     = imm;
            end
            
            default: begin
                rd_rs1_addr = 5'h0;
                rd_rs2_addr = 5'h0;
                op1_out     = 32'h0;
                op2_out     = 32'h0;
            end
        endcase
    end

endmodule