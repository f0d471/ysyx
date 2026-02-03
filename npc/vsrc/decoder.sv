`include "define.sv"

module decode #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic [AW-1:0] instr_addr_in, // PC from IF/ID
    input  logic [DW-1:0] instr_in,      // Instruction from IF/ID
    
    // To Register (Read Addr) 
    output logic [4:0]    rd_rs1_addr,
    output logic [4:0]    rd_rs2_addr,
    
    // To Execute 
    output logic [4:0]    rd_addr_out,   // 目标寄存器 (rd)
    output logic [DW-1:0] imm_out,       // 立即数
    output logic [1:0]      op1_sel_out,   // op1选择控制：0=0，1=rs1，2=PC，3=PC+4（扩展用）
    output logic [1:0]      op2_sel_out,   // op2选择控制：0=0，1=rs2，2=imm，3=4（返回地址用）
    
    // To Execute for decode
    output logic [6:0]    opcode_out,
    output logic [2:0]    funct3_out,
    output logic [6:0]    funct7_out,

    // ebreak
    output logic inst_ebreak
);

    logic [6:0] opcode;
    logic [4:0] rd;
    logic [2:0] funct3;
    logic [4:0] rs1;
    logic [4:0] rs2;
    logic [6:0] funct7;
    logic [31:0] imm;

    // 字段提取
    assign opcode = instr_in[6:0];
    assign rd     = instr_in[11:7];
    assign funct3 = instr_in[14:12];
    assign rs1    = instr_in[19:15];
    assign rs2    = instr_in[24:20];
    assign funct7 = instr_in[31:25];

    assign opcode_out  = opcode;
    assign rd_addr_out = rd;
    assign funct3_out  = funct3;
    assign funct7_out  = funct7;
    assign imm_out     = imm;

    //ebreak
    wire is_ebreak = (instr_in == 32'h00100073); // ebreak 的机器码
    assign inst_ebreak = is_ebreak;

    // 立即数生成 
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

    // op1 select
    localparam logic [1:0] OP1_RS1  = 2'b00;
    localparam logic [1:0] OP1_PC   = 2'b01;
    localparam logic [1:0] OP1_ZERO = 2'b10;

    // op2 select
    localparam logic [1:0] OP2_RS2 = 2'b00;
    localparam logic [1:0] OP2_IMM = 2'b01;
    localparam logic [1:0] OP2_4   = 2'b10;

    // 指令行为
    always_comb begin
        // 默认行为
        rd_rs1_addr = 5'h0;
        rd_rs2_addr = 5'h0;

        op1_sel_out = OP1_ZERO;
        op2_sel_out = OP2_RS2;

        case(opcode)
            `INST_TYPE_I: begin // ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI 
                rd_rs1_addr = rs1;
                rd_rs2_addr = 5'h0;

                op1_sel_out = OP1_RS1;
                op2_sel_out = OP2_IMM;
            end
            
            `INST_TYPE_R: begin // ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR ,AND 
                rd_rs1_addr = rs1;
                rd_rs2_addr = rs2;

                op1_sel_out = OP1_RS1;
                op2_sel_out = OP2_RS2;
            end
            
            `INST_TYPE_B: begin // BEQ, BNE, BEQ, BNE, BLT, BGE, BLTU, BGEU
                rd_rs1_addr = rs1;
                rd_rs2_addr = rs2;

                op1_sel_out = OP1_RS1;
                op2_sel_out = OP2_RS2;
            end
            
            `INST_TYPE_S: begin // SW, SH, SB
                rd_rs1_addr = rs1;
                rd_rs2_addr = rs2;

                op1_sel_out = OP1_RS1;
                op2_sel_out = OP2_IMM;
            end
            
            `INST_TYPE_L: begin // LW, LH, LB, LBU, LHU
                rd_rs1_addr = rs1;
                rd_rs2_addr = 5'h0;

                op1_sel_out = OP1_RS1;
                op2_sel_out = OP2_IMM;
            end
            
            `INST_TYPE_J: begin // JAL
                rd_rs1_addr = 5'h0;
                rd_rs2_addr = 5'h0;

                op1_sel_out = OP1_PC;
                op2_sel_out = OP2_4;
            end
            
            `INST_TYPE_JALR: begin // JALR
                rd_rs1_addr = rs1;
                rd_rs2_addr = 5'h0;

                op1_sel_out = OP1_PC;
                op2_sel_out = OP2_4;
            end
            
            `INST_TYPE_U_LUI: begin // LUI
                rd_rs1_addr = 5'h0;
                rd_rs2_addr = 5'h0;

                op1_sel_out = OP1_ZERO;
                op2_sel_out = OP2_IMM;
            end
            
            `INST_TYPE_U_AUIPC: begin // AUIPC
                rd_rs1_addr = 5'h0;
                rd_rs2_addr = 5'h0;

                op1_sel_out = OP1_PC;
                op2_sel_out = OP2_IMM;
            end
            
            7'b1110011: begin 
                if (is_ebreak) begin
                    // 关键点：ebreak 本身不带 rs1 索引，但我们需要读取 a0 (x10) 寄存器的值传给 trap 函数
                    rd_rs1_addr = 5'd10; // 强制读取 x10 (a0)
                    rd_rs2_addr = 5'h0;

                    op1_sel_out = OP1_RS1; // 让 op1_in 拿到 a0 的值
                    op2_sel_out = OP2_RS2;
                end else begin
                    // 处理其他 CSR 指令 (暂时留空或默认)
                    rd_rs1_addr = 5'h0;
                    rd_rs2_addr = 5'h0;
                    op1_sel_out = OP1_ZERO;
                    op2_sel_out = OP2_RS2;
                end
            end
            
            default: begin
                rd_rs1_addr = 5'h0;
                rd_rs2_addr = 5'h0;

                op1_sel_out = OP1_ZERO;
                op2_sel_out = OP2_RS2;
            end
        endcase
    end

endmodule