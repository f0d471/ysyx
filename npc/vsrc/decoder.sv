`include "define.v"

module decode #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic [AW-1:0] instr_addr_in, // PC from IF/ID
    input  logic [DW-1:0] instr_in,      // Instruction from IF/ID
    
    // To Register File (Read Port)
    output logic [4:0]    rd_rs1_addr,
    output logic [4:0]    rd_rs2_addr,
    
    // From Register File (Read Data)
    input  logic [DW-1:0] rd_rs1_data,
    input  logic [DW-1:0] rd_rs2_data,
    
    // To Execute Stage
    output logic [4:0]    rd_addr_out,   // 目标寄存器地址 (RD)
    output logic [DW-1:0] op1_out,       // ALU 操作数 1
    output logic [DW-1:0] op2_out,       // ALU 操作数 2
    output logic [DW-1:0] imm_out,      
    
    // 将指令字段透传给 EX 阶段 (用于 ALU Control 译码)
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
            `INST_TYPE_I: begin // ADDI, SLTI, etc.
                rd_rs1_addr = rs1;
                rd_rs2_addr = 5'h0; // 不需要 rs2
                op1_out     = rd_rs1_data;
                op2_out     = imm;
            end
            
            `INST_TYPE_R_M: begin // ADD, SUB, MUL, etc.
                rd_rs1_addr = rs1;
                rd_rs2_addr = rs2;
                op1_out     = rd_rs1_data;
                op2_out     = rd_rs2_data;
            end
            
            `INST_TYPE_B: begin // BEQ, BNE...
                rd_rs1_addr = rs1;
                rd_rs2_addr = rs2;
                op1_out     = rd_rs1_data; // ALU 做比较 (rs1 - rs2)
                op2_out     = rd_rs2_data;
                // 注意：跳转目标 PC + Imm 会在 EX 阶段通过加法器或 ALU 旁路计算
            end
            
            `INST_TYPE_S: begin // SW, SH, SB
                rd_rs1_addr = rs1; // 基地址
                rd_rs2_addr = rs2; // 要存的数据
                op1_out     = rd_rs1_data;
                op2_out     = imm; // ALU 计算地址: rs1 + imm
            end
            
            `INST_TYPE_L: begin // LW, LH, LB
                rd_rs1_addr = rs1;
                rd_rs2_addr = 5'h0;
                op1_out     = rd_rs1_data;
                op2_out     = imm; // ALU 计算地址: rs1 + imm
            end
            
            `INST_TYPE_J: begin // JAL
                rd_rs1_addr = 5'h0;
                rd_rs2_addr = 5'h0;
                // JAL 行为: rd = PC + 4 (链接); PC = PC + imm (跳转)
                // 这里让 ALU 计算 PC + 4 写入 rd
                op1_out     = instr_addr_in; // PC
                op2_out     = 32'd4;
            end
            
            `INST_TYPE_JALR: begin // JALR
                rd_rs1_addr = rs1;
                rd_rs2_addr = 5'h0;
                // JALR 行为: rd = PC + 4; PC = (rs1 + imm) & ~1
                // 同样让 ALU 计算 PC + 4 写入 rd
                op1_out     = instr_addr_in; // PC
                op2_out     = 32'd4;
                // 跳转目标 rs1 + imm 将在 EX 阶段额外处理
            end
            
            `INST_TYPE_U_LUI: begin // LUI: rd = imm
                rd_rs1_addr = 5'h0;
                rd_rs2_addr = 5'h0;
                op1_out     = 32'h0;
                op2_out     = imm;
            end
            
            `INST_TYPE_U_AUIPC: begin // AUIPC: rd = PC + imm
                rd_rs1_addr = 5'h0;
                rd_rs2_addr = 5'h0;
                op1_out     = instr_addr_in; // PC
                op2_out     = imm;
            end
            
            default: begin
                // 处理 NOP 或非法指令
                rd_rs1_addr = 5'h0;
                rd_rs2_addr = 5'h0;
                op1_out     = 32'h0;
                op2_out     = 32'h0;
            end
        endcase
    end

endmodule