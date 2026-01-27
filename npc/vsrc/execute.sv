`include "define.v"

module execute #(
    parameter AW = 32,
    parameter DW = 32
)(
    // Inputs from ID/EX
    input  logic [AW-1:0] pc_in,
    input  logic [DW-1:0] op1_in,
    input  logic [DW-1:0] op2_in,
    input  logic [DW-1:0] rs1_data_in, // 用于 JALR
    input  logic [DW-1:0] imm_in,
    input  logic [6:0]    opcode_in,
    input  logic [2:0]    funct3_in,
    input  logic [6:0]    funct7_in,
    
    // Outputs to EX/MEM
    output logic [DW-1:0] alu_result_out, // ALU 计算结果 (或内存地址)
    output logic          jump_flag_out,  // 是否发生跳转
    output logic [AW-1:0] jump_target_out // 跳转目标地址
);

    logic [DW-1:0] alu_res;
    logic          branch_taken;

    // -------------------------------------------------------------------------
    // 1. ALU Logic
    // -------------------------------------------------------------------------
    always_comb begin
        case(opcode_in)
            `INST_TYPE_I: begin
                case(funct3_in)
                    `INST_ADDI:  alu_res = op1_in + op2_in;
                    `INST_SLTI:  alu_res = ($signed(op1_in) < $signed(op2_in)) ? 32'd1 : 32'd0;
                    `INST_SLTIU: alu_res = (op1_in < op2_in) ? 32'd1 : 32'd0;
                    `INST_XORI:  alu_res = op1_in ^ op2_in;
                    `INST_ORI:   alu_res = op1_in | op2_in;
                    `INST_ANDI:  alu_res = op1_in & op2_in;
                    `INST_SLLI:  alu_res = op1_in << op2_in[4:0];
                    `INST_SRLI, `INST_SRAI: begin
                        if(funct7_in[5]) alu_res = $signed(op1_in) >>> op2_in[4:0]; // SRAI
                        else             alu_res = op1_in >> op2_in[4:0];           // SRLI
                    end
                    default: alu_res = 32'h0;
                endcase
            end
            `INST_TYPE_R_M: begin
                if(funct7_in == `FUNCT7_M_EXT) begin 
                    // M-Extension (Mul/Div) - 暂简化，你可以加上你的乘除法器
                    alu_res = 32'h0; 
                end else begin
                    case(funct3_in)
                        `INST_ADD: begin
                            if(funct7_in[5]) alu_res = op1_in - op2_in; // SUB
                            else             alu_res = op1_in + op2_in; // ADD
                        end
                        `INST_SLL:  alu_res = op1_in << op2_in[4:0];
                        `INST_SLT:  alu_res = ($signed(op1_in) < $signed(op2_in)) ? 32'd1 : 32'd0;
                        `INST_SLTU: alu_res = (op1_in < op2_in) ? 32'd1 : 32'd0;
                        `INST_XOR:  alu_res = op1_in ^ op2_in;
                        `INST_SRL: begin
                            if(funct7_in[5]) alu_res = $signed(op1_in) >>> op2_in[4:0]; // SRA
                            else             alu_res = op1_in >> op2_in[4:0];           // SRL
                        end
                        `INST_OR:   alu_res = op1_in | op2_in;
                        `INST_AND:  alu_res = op1_in & op2_in;
                        default:    alu_res = 32'h0;
                    endcase
                end
            end
            `INST_TYPE_L, `INST_TYPE_S: begin
                alu_res = op1_in + op2_in; // 计算内存地址: rs1 + imm
            end
            `INST_TYPE_J, `INST_TYPE_JALR: begin
                alu_res = op1_in + op2_in; // 计算 Link Address: PC + 4 (Decoder已设好op1=PC, op2=4)
            end
            `INST_TYPE_U_LUI:   alu_res = op2_in; // imm
            `INST_TYPE_U_AUIPC: alu_res = op1_in + op2_in; // PC + imm
            default: alu_res = 32'h0;
        endcase
    end

    // -------------------------------------------------------------------------
    // 2. Branch Judgment (分支判断)
    // -------------------------------------------------------------------------
    always_comb begin
        if(opcode_in == `INST_TYPE_B) begin
            case(funct3_in)
                `INST_BEQ:  branch_taken = (op1_in == op2_in);
                `INST_BNE:  branch_taken = (op1_in != op2_in);
                `INST_BLT:  branch_taken = ($signed(op1_in) < $signed(op2_in));
                `INST_BGE:  branch_taken = ($signed(op1_in) >= $signed(op2_in));
                `INST_BLTU: branch_taken = (op1_in < op2_in);
                `INST_BGEU: branch_taken = (op1_in >= op2_in);
                default:    branch_taken = 1'b0;
            endcase
        end else begin
            branch_taken = 1'b0;
        end
    end

    // -------------------------------------------------------------------------
    // 3. Jump/Branch Target Calculation (跳转目标计算)
    // -------------------------------------------------------------------------
    always_comb begin
        jump_flag_out   = 1'b0;
        jump_target_out = 32'h0;

        if (opcode_in == `INST_TYPE_J) begin // JAL
            jump_flag_out   = 1'b1;
            jump_target_out = pc_in + imm_in;
        end 
        else if (opcode_in == `INST_TYPE_JALR) begin // JALR
            jump_flag_out   = 1'b1;
            // 规范: JALR 目标地址最低位必须设为 0
            jump_target_out = (rs1_data_in + imm_in) & ~32'd1;
        end 
        else if (branch_taken) begin // Branch Taken
            jump_flag_out   = 1'b1;
            jump_target_out = pc_in + imm_in;
        end
    end

    assign alu_result_out = alu_res;

endmodule