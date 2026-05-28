`include "define.sv"

module decode #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic [AW-1:0] inst_addr_in,
    input  logic [DW-1:0] inst_in,

    output logic [4:0]    rs1_addr,
    output logic [4:0]    rs2_addr,
    
    output logic [4:0]    rd_addr_out,   
    output logic [DW-1:0] imm_out,       
    output logic [1:0]    op1_sel_out,   
    output logic [1:0]    op2_sel_out,   
    output logic [6:0]    opcode_out,
    output logic [2:0]    funct3_out,
    output logic [6:0]    funct7_out,

    output logic inst_ebreak,

    // CSR 
    output logic [11:0]   csr_addr,
    output logic          inst_csrrw,   
    output logic          inst_csrrs,   
    output logic          inst_ecall,    
    output logic          inst_mret     
);

    logic [6:0] opcode;
    logic [4:0] rd;
    logic [2:0] funct3;
    logic [4:0] rs1;
    logic [4:0] rs2;
    logic [6:0] funct7;
    logic [31:0] imm;

    // 字段提取
    assign opcode = inst_in[6:0];
    assign rd     = inst_in[11:7];
    assign funct3 = inst_in[14:12];
    assign rs1    = inst_in[19:15];
    assign rs2    = inst_in[24:20];
    assign funct7 = inst_in[31:25];

    assign opcode_out  = opcode;
    assign rd_addr_out = rd;
    assign funct3_out  = funct3;
    assign funct7_out  = funct7;
    assign imm_out     = imm;

    // CSR 地址提取 
    assign csr_addr = inst_in[31:20];

    // ebreak
    assign inst_ebreak = (inst_in == 32'h00100073);

    // SYSTEM
    assign inst_csrrw = (opcode == `INST_TYPE_SYSTEM) && (funct3 == 3'b001);
    assign inst_csrrs = (opcode == `INST_TYPE_SYSTEM) && (funct3 == 3'b010);
    assign inst_ecall = (opcode == `INST_TYPE_SYSTEM) && (funct3 == 3'b000) && (csr_addr == 12'h000);
    assign inst_mret  = (opcode == `INST_TYPE_SYSTEM) && (funct3 == 3'b000) && (csr_addr == 12'h302);


    // 立即数生成 
    always_comb begin
        case(opcode)
            `INST_TYPE_I, `INST_TYPE_L, `INST_TYPE_JALR:
                imm = {{20{inst_in[31]}}, inst_in[31:20]};
            `INST_TYPE_S:
                imm = {{20{inst_in[31]}}, inst_in[31:25], inst_in[11:7]};
            `INST_TYPE_B:
                imm = {{20{inst_in[31]}}, inst_in[7], inst_in[30:25], inst_in[11:8], 1'b0};
            `INST_TYPE_J: // JAL
                imm = {{12{inst_in[31]}}, inst_in[19:12], inst_in[20], inst_in[30:21], 1'b0};
            `INST_TYPE_U_LUI, `INST_TYPE_U_AUIPC:
                imm = {inst_in[31:12], 12'h0};
            default:
                imm = 32'h0;
        endcase
    end


    // 指令行为
    always_comb begin
        // 默认行为
        rs1_addr = 5'h0;
        rs2_addr = 5'h0;

        op1_sel_out = `OP1_ZERO;
        op2_sel_out = `OP2_RS2;

        case(opcode)
            `INST_TYPE_I: begin // ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI 
                rs1_addr = rs1;
                rs2_addr = 5'h0;

                op1_sel_out = `OP1_RS1;
                op2_sel_out = `OP2_IMM;
            end
            
            `INST_TYPE_R: begin // ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR ,AND 
                rs1_addr = rs1;
                rs2_addr = rs2;

                op1_sel_out = `OP1_RS1;
                op2_sel_out = `OP2_RS2;
            end
            
            `INST_TYPE_B: begin // BEQ, BNE, BEQ, BNE, BLT, BGE, BLTU, BGEU
                rs1_addr = rs1;
                rs2_addr = rs2;

                op1_sel_out = `OP1_RS1;
                op2_sel_out = `OP2_RS2;
            end
            
            `INST_TYPE_S: begin // SW, SH, SB
                rs1_addr = rs1;
                rs2_addr = rs2;

                op1_sel_out = `OP1_RS1;
                op2_sel_out = `OP2_IMM;
            end
            
            `INST_TYPE_L: begin // LW, LH, LB, LBU, LHU
                rs1_addr = rs1;
                rs2_addr = 5'h0;

                op1_sel_out = `OP1_RS1;
                op2_sel_out = `OP2_IMM;
            end
            
            `INST_TYPE_J: begin // JAL
                rs1_addr = 5'h0;
                rs2_addr = 5'h0;

                op1_sel_out = `OP1_PC;
                op2_sel_out = `OP2_4;
            end
            
            `INST_TYPE_JALR: begin // JALR
                rs1_addr = rs1;
                rs2_addr = 5'h0;

                op1_sel_out = `OP1_PC;
                op2_sel_out = `OP2_4;
            end
            
            `INST_TYPE_U_LUI: begin // LUI
                rs1_addr = 5'h0;
                rs2_addr = 5'h0;

                op1_sel_out = `OP1_ZERO;
                op2_sel_out = `OP2_IMM;
            end
            
            `INST_TYPE_U_AUIPC: begin // AUIPC
                rs1_addr = 5'h0;
                rs2_addr = 5'h0;

                op1_sel_out = `OP1_PC;
                op2_sel_out = `OP2_IMM;
            end
            
            `INST_TYPE_SYSTEM: begin
                if (inst_ebreak) begin // EBREAK
                    rs1_addr = 5'ha;
                    rs2_addr = 5'h0;

                    op1_sel_out = `OP1_RS1;
                    op2_sel_out = `OP2_RS2;
                end 
                else if (inst_csrrw || inst_csrrs) begin // CSRRW,CSRRS
                    rs1_addr = rs1;
                    rs2_addr = 5'h0;

                    op1_sel_out = `OP1_RS1; 
                    op2_sel_out = `OP2_RS2; 
                end
                else begin // ECALL, MRET 
                    rs1_addr = 5'h0;
                    rs2_addr = 5'h0;

                    op1_sel_out = `OP1_ZERO;
                    op2_sel_out = `OP2_RS2;
                end
            end
            
            default: begin
                rs1_addr = 5'h0;
                rs2_addr = 5'h0;

                op1_sel_out = `OP1_ZERO;
                op2_sel_out = `OP2_RS2;
            end
        endcase
    end

endmodule