`include "define.sv"

module id2ex #(
    parameter AW = 32,
    parameter DW = 32
)( 
    // input  logic          id_stall,
    // input  logic          id_flush,
    
    // from decode
    input  logic [AW-1:0] instr_addr_in,
    input  logic [DW-1:0] instr_in,
    input  logic [4:0]    rd_addr_in,
    input  logic [DW-1:0] imm_in,
    input  logic [1:0]    op1_sel_in,
    input  logic [1:0]    op2_sel_in,
    input  logic [6:0]    opcode_in,
    input  logic [2:0]    funct3_in,
    input  logic [6:0]    funct7_in,
    
    // from register
    input  logic [DW-1:0] rs1_data_in,
    input  logic [DW-1:0] rs2_data_in,

    // to ex
    output logic [AW-1:0] instr_addr_out,
    output logic [DW-1:0] instr_out,
    output logic [DW-1:0] op1_out,
    output logic [DW-1:0] op2_out,
    output logic [4:0]    rd_addr_out,
    output logic [DW-1:0] imm_out,
    output logic [6:0]    opcode_out,
    output logic [2:0]    funct3_out,
    output logic [6:0]    funct7_out,
    output logic [DW-1:0] rs1_data_out,
    output logic [DW-1:0] rs2_data_out,

    //ebreak
    input  logic          inst_ebreak_in,
    output logic          inst_ebreak_out,

    // --- [新增] CSR & 异常相关控制信号 ---
    input  logic [11:0]   csr_addr_in,
    input  logic          inst_csrrw_in,
    input  logic          inst_csrrs_in,
    input  logic          inst_ecall_in,
    input  logic          inst_mret_in,

    output logic [11:0]   csr_addr_out,
    output logic          inst_csrrw_out,
    output logic          inst_csrrs_out,
    output logic          inst_ecall_out,
    output logic          inst_mret_out
);  

    // op1 select
    localparam logic [1:0] OP1_RS1  = 2'b00;
    localparam logic [1:0] OP1_PC   = 2'b01;
    localparam logic [1:0] OP1_ZERO = 2'b10;

    // op2 select
    localparam logic [1:0] OP2_RS2 = 2'b00;
    localparam logic [1:0] OP2_IMM = 2'b01;
    localparam logic [1:0] OP2_4   = 2'b10;

    always_comb begin
        instr_addr_out  = instr_addr_in;
        instr_out       = instr_in;
        rd_addr_out     = rd_addr_in;
        imm_out         = imm_in;
        opcode_out      = opcode_in;
        funct3_out      = funct3_in;
        funct7_out      = funct7_in;
        rs1_data_out    = rs1_data_in;
        rs2_data_out    = rs2_data_in;
        inst_ebreak_out = inst_ebreak_in;

        // --- [新增] 透传 CSR 相关信号 ---
        csr_addr_out    = csr_addr_in;
        inst_csrrw_out  = inst_csrrw_in;
        inst_csrrs_out  = inst_csrrs_in;
        inst_ecall_out  = inst_ecall_in;
        inst_mret_out   = inst_mret_in;

        case(op1_sel_in)
            OP1_RS1:  op1_out = rs1_data_in;  // 选择rs1原始数据
            OP1_PC:   op1_out = instr_addr_in; // 选择PC值
            OP1_ZERO: op1_out = 32'h0;        // 选择0
            default:  op1_out = 32'h0;
        endcase

        case(op2_sel_in)
            OP2_RS2:  op2_out = rs2_data_in;  // 直接使用register输入的原始数据
            OP2_IMM:  op2_out = imm_in;       // 直接使用decode输入的立即数
            OP2_4:    op2_out = 32'd4;        // 固定值，用于返回地址计算
            default:  op2_out = 32'h0;
        endcase
    end

endmodule