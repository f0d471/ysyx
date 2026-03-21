`ifndef DEFINE_SV
`define DEFINE_SV

`define AW 				  32
`define DW 				  32

// -------------------------- 指令类型（opcode）定义 --------------------------
// I type inst (立即数/加载/JALR)
`define INST_TYPE_I       7'b0010011  // 普通I型（ADDI/SLLI等）
`define INST_TYPE_L       7'b0000011  // 加载类I型（LB/LW等）
`define INST_TYPE_JALR    7'b1100111  // JALR（特殊I型）

// S type inst (存储)
`define INST_TYPE_S       7'b0100011

// R type inst (寄存器运算/乘法扩展)
`define INST_TYPE_R       7'b0110011  

// B type inst (分支)
`define INST_TYPE_B       7'b1100011

// J type inst (跳转)
`define INST_TYPE_J       7'b1101111  // JAL

// U type inst (高位立即数)
`define INST_TYPE_U_LUI   7'b0110111  // LUI
`define INST_TYPE_U_AUIPC 7'b0010111  // AUIPC

// 特殊指令
`define INST_TYPE_SYSTEM  7'b1110011  // 系统指令（MRET/ECALL等）

// -------------------------- I型指令 funct3 定义 --------------------------
// 普通I型
`define INST_ADDI         3'b000
`define INST_SLTI         3'b010
`define INST_SLTIU        3'b011
`define INST_XORI         3'b100
`define INST_ORI          3'b110
`define INST_ANDI         3'b111
`define INST_SLLI         3'b001  // 移位类I型
`define INST_SRLI         3'b101  // 逻辑右移I型
`define INST_SRAI         3'b101  // 算术右移I型（通过funct7=0100000区分）

// 加载类I型
`define INST_LB           3'b000
`define INST_LH           3'b001
`define INST_LW           3'b010
`define INST_LBU          3'b100
`define INST_LHU          3'b101

// -------------------------- S型指令 funct3 定义 --------------------------
`define INST_SB           3'b000
`define INST_SH           3'b001
`define INST_SW           3'b010

// -------------------------- R型指令 funct3 定义 --------------------------
`define INST_ADD          3'b000  // funct7=0000000
`define INST_SUB          3'b000  // funct7=0100000
`define INST_SLL          3'b001
`define INST_SLT          3'b010
`define INST_SLTU         3'b011
`define INST_XOR          3'b100
`define INST_SRL          3'b101  // funct7=0000000
`define INST_SRA          3'b101  // funct7=0100000
`define INST_OR           3'b110
`define INST_AND          3'b111

// // -------------------------- M型指令（乘法扩展）funct3 定义 --------------------------
// `define INST_MUL          3'b000
// `define INST_MULH         3'b001
// `define INST_MULHSU       3'b010
// `define INST_MULHU        3'b011
// `define INST_DIV          3'b100
// `define INST_DIVU         3'b101
// `define INST_REM          3'b110
// `define INST_REMU         3'b111

// -------------------------- B型指令 funct3 定义 --------------------------
`define INST_BEQ          3'b000
`define INST_BNE          3'b001
`define INST_BLT          3'b100
`define INST_BGE          3'b101
`define INST_BLTU         3'b110
`define INST_BGEU         3'b111

// -------------------------- 常用指令常量定义 --------------------------
`define INST_NOP          32'h00000013  // ADDI x0, x0, 0
`define INST_MRET         32'h30200073  // 系统指令（SYSTEM类型）
`define INST_RET          32'h00008067  // JALR x0, x1, 0（I型）

// -------- IF → ID 通道 --------
typedef struct packed {
    logic [31:0] pc;
    logic [31:0] instr;
} if_id_t;

// -------- ID → EX 通道 --------
typedef struct packed {
    logic [31:0] pc;
    logic [31:0] instr;
    logic [31:0] op1;
    logic [31:0] op2;
    logic [4:0]  rd_addr;
    logic [31:0] imm;
    logic [6:0]  opcode;
    logic [2:0]  funct3;
    logic [6:0]  funct7;
    logic [31:0] rs1_data;
    logic [31:0] rs2_data;
    logic [11:0] csr_addr;
    logic        inst_csrrw;
    logic        inst_csrrs;
    logic        inst_ecall;
    logic        inst_mret;
    logic        inst_ebreak;
} id_ex_t;

// -------- EX → MEM 通道 --------
typedef struct packed {
    logic [31:0] pc;         
    logic [31:0] instr;     
    logic [31:0] alu_result;
    logic [31:0] rs2_data;
    logic [4:0]  rd_addr;
    logic [6:0]  opcode;
    logic [2:0]  funct3;
} ex_mem_t;

// -------- MEM → WB 通道 --------
typedef struct packed {
    logic [31:0] pc;          // ★ 新增
    logic [31:0] instr;       // ★ 新增
    logic [31:0] alu_result;
    logic [31:0] mem_rdata;
    logic [4:0]  rd_addr;
    logic [6:0]  opcode;
} mem_wb_t;

`endif // DEFINE_SV
