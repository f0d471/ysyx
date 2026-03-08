`include "define.sv"

module execute #(
    parameter AW = 32,
    parameter DW = 32
)(
    // Inputs from ID/EX
    input  logic [AW-1:0] pc_in,
    input  logic [DW-1:0] op1_in,
    input  logic [DW-1:0] op2_in,
    input  logic [DW-1:0] rs1_data_in, 
    input  logic [DW-1:0] imm_in,
    input  logic [6:0]    opcode_in,
    input  logic [2:0]    funct3_in,
    input  logic [6:0]    funct7_in,
    
    // Outputs to EX/MEM
    output logic [DW-1:0] alu_result_out, // ALU计算结果或内存地址
    output logic          jump_flag_out,  // 是否发生跳转
    output logic [AW-1:0] jump_target_out, // 跳转目标地址

    //ebreak
    input  logic          inst_ebreak_in,

    // --- [新增] Inputs from ID/EX (CSR & Exception 控制信号) ---
    input  logic [11:0]   csr_addr_in,
    input  logic          inst_csrrw,
    input  logic          inst_csrrs,
    input  logic          inst_ecall,
    input  logic          inst_mret,

    // --- [新增] Interfaces with CSR File ---
    output logic [11:0]   csr_raddr,     // 读CSR地址
    input  logic [31:0]   csr_rdata,     // 读出的CSR数据
    
    output logic          csr_wen,       // 写CSR使能
    output logic [11:0]   csr_waddr,     // 写CSR地址
    output logic [31:0]   csr_wdata,     // 写CSR数据

    output logic          trap_valid,    // 触发异常
    output logic [31:0]   trap_pc,       // 保存的PC
    output logic [31:0]   trap_cause,    // 异常原因
    
    input  logic [31:0]   trap_mtvec,    // 异常入口地址
    input  logic [31:0]   trap_mepc      // 异常返回地址
);

    logic [DW-1:0] alu_res;
    logic          branch_taken;

    // ----------------------------------- ALU --------------------------------------
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
                alu_res = op1_in + op2_in; // 计算内存地址: rs1 + imm
            end

            `INST_TYPE_J, `INST_TYPE_JALR: begin
                alu_res = op1_in + op2_in; // 计算 Link Address: PC + 4
            end

            `INST_TYPE_U_LUI:   alu_res = op2_in; // imm
            `INST_TYPE_U_AUIPC: alu_res = op1_in + op2_in; // PC + imm
            default: alu_res = 32'h0;
        endcase
    end

    // ---------------------------------- 分支判断 --------------------------------------
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

    // -------------------------------- 跳转目标计算 -------------------------------------
    // [修改] 将异常自陷 (ecall) 和返回 (mret) 也纳入硬件强制跳转逻辑
    always_comb begin
        jump_flag_out   = 1'b0;
        jump_target_out = 32'h0;

        if (inst_ecall) begin // 发生环境调用异常
            jump_flag_out   = 1'b1;
            jump_target_out = trap_mtvec; // 强行跳到 mtvec 保存的异常入口地址
        end
        else if (inst_mret) begin // 从异常返回
            jump_flag_out   = 1'b1;
            jump_target_out = trap_mepc;  // 强行恢复到 mepc 保存的返回地址
        end
        else if (opcode_in == `INST_TYPE_J) begin // JAL
            jump_flag_out   = 1'b1;
            jump_target_out = pc_in + imm_in;
        end 
        else if (opcode_in == `INST_TYPE_JALR) begin // JALR
            jump_flag_out   = 1'b1;
            jump_target_out = (rs1_data_in + imm_in) & ~32'd1;
        end 
        else if (branch_taken) begin // Branch Taken
            jump_flag_out   = 1'b1;
            jump_target_out = pc_in + imm_in;
        end
    end

    // ------------------------------- CSR 操作与异常响应 --------------------------------
    // CSR 读请求
    assign csr_raddr = csr_addr_in;

    // CSR 写请求
    // 规定: csrrw 始终写; csrrs 当且仅当 rs1 != 0 时才写。
    // 这里如果源寄存器地址为0，decode 阶段应该已经把 op1_in 设为了 0，
    // 我们暂时用 op1_in != 0 来近似代替 (rs1!=0) 的判断，或者依靠之前约定的行为。
    assign csr_wen   = inst_csrrw | (inst_csrrs & (op1_in != 32'b0)); 
    assign csr_waddr = csr_addr_in;
    // CSR 写入的数据: csrrw 用新值覆盖; csrrs 用按位或更新
    assign csr_wdata = inst_csrrw ? op1_in : (csr_rdata | op1_in);

    // 异常触发请求给 csr_file 自动保存状态
    assign trap_valid = inst_ecall;
    assign trap_pc    = pc_in;
    // RISC-V 规定：来自 M 模式的 Environment Call 对应的 cause 值为 11
    assign trap_cause = 32'd11; 

    // ------------------------------- 结果选择 (写回目标寄存器) -------------------------
    always_comb begin
        if (inst_csrrw || inst_csrrs) begin
            // 如果是 CSR 读写指令，需要把从 CSR 中读出的旧值写回 rd 通用寄存器
            alu_result_out = csr_rdata;
        end else begin
            // 其它普通运算或访存指令，按正常 ALU 结果传递
            alu_result_out = alu_res;
        end
    end

    // ------------------------------- ebreak ------------------------------------
    always_comb begin
        if (inst_ebreak_in) begin
            // 触发 C++ 环境的 Trap
            trap(op1_in, pc_in);
        end
    end

endmodule