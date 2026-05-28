`include "define.sv"

module execute #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic [AW-1:0] pc_in,
    input  logic [DW-1:0] op1_in,
    input  logic [DW-1:0] op2_in,
    input  logic [DW-1:0] rs1_data_in, 
    input  logic [DW-1:0] imm_in,
    input  logic [6:0]    opcode_in,
    input  logic [2:0]    funct3_in,
    input  logic [6:0]    funct7_in,
    
    output logic [DW-1:0] alu_result_out, 
    output logic          jump_flag_out,  
    output logic [AW-1:0] jump_target_out, 

    input  logic          inst_ebreak_in,
    input  logic [11:0]   csr_addr_in,
    input  logic          inst_csrrw,
    input  logic          inst_csrrs,
    input  logic          inst_ecall,
    input  logic          inst_mret,

    output logic [11:0]   csr_raddr,     
    input  logic [31:0]   csr_rdata,    
    output logic          csr_wen,      
    output logic [11:0]   csr_waddr,    
    output logic [31:0]   csr_wdata,     

    output logic          trap_valid,    
    output logic [31:0]   trap_pc,       
    output logic [31:0]   trap_cause,  
    input  logic [31:0]   trap_mtvec,   
    input  logic [31:0]   trap_mepc     
);

    logic [DW-1:0] alu_res;
    logic          branch_taken;

    //  ALU 
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
                    `INST_SRLI: begin 
                        if(funct7_in[5]) alu_res = $signed(op1_in) >>> op2_in[4:0]; // SRAI (算术右移)
                        else             alu_res = op1_in >> op2_in[4:0];           // SRLI (逻辑右移)
                    end
                    default: alu_res = 32'h0;
                endcase
            end
            
            `INST_TYPE_R: begin
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

            `INST_TYPE_L, `INST_TYPE_S: begin
                alu_res = op1_in + op2_in; // 计算内存地址
            end

            `INST_TYPE_J, `INST_TYPE_JALR: begin
                alu_res = op1_in + op2_in; // PC + 4
            end

            `INST_TYPE_U_LUI:   alu_res = op2_in; // imm
            `INST_TYPE_U_AUIPC: alu_res = op1_in + op2_in; // PC + imm
            default: alu_res = 32'h0;
        endcase
    end

    //  分支判断 
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

    //  跳转目标计算 
    always_comb begin
        jump_flag_out   = 1'b0;
        jump_target_out = 32'h0;

        if (inst_ecall) begin 
            jump_flag_out   = 1'b1;
            jump_target_out = trap_mtvec; 
        end
        else if (inst_mret) begin 
            jump_flag_out   = 1'b1;
            jump_target_out = trap_mepc;  
        end
        else if (opcode_in == `INST_TYPE_J) begin // JAL
            jump_flag_out   = 1'b1;
            jump_target_out = pc_in + imm_in;
        end 
        else if (opcode_in == `INST_TYPE_JALR) begin // JALR
            jump_flag_out   = 1'b1;
            jump_target_out = (rs1_data_in + imm_in) & ~32'd1;
        end 
        else if (branch_taken) begin 
            jump_flag_out   = 1'b1;
            jump_target_out = pc_in + imm_in;
        end
    end

    //  CSR 操作与异常响应 
    assign csr_raddr = csr_addr_in;

    assign csr_wen   = inst_csrrw | (inst_csrrs & (op1_in != 32'b0)); 
    assign csr_waddr = csr_addr_in;
    assign csr_wdata = inst_csrrw ? op1_in : (csr_rdata | op1_in);

    assign trap_valid = inst_ecall;
    assign trap_pc    = pc_in;
    assign trap_cause = 32'd11; 

    //  结果选择 
    always_comb begin
        if (inst_csrrw || inst_csrrs) begin
            alu_result_out = csr_rdata;
        end else begin
            alu_result_out = alu_res;
        end
    end

    //  ebreak 
    always_comb begin
        if (inst_ebreak_in) begin
            trap(op1_in, pc_in);
        end
    end

endmodule