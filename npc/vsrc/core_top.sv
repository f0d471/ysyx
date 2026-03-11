`include "define.sv"

import "DPI-C" function void trap(input int code, input int pc);
import "DPI-C" function int paddr_read(input int addr);
import "DPI-C" function void paddr_write(input int addr, input int len, input int data);

module top #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n,
    output logic [AW-1:0] pc,
    output logic [DW-1:0] instr,
    output logic [DW-1:0] debug_x10,
    output logic [DW-1:0] regs [15:0]
);

//  握手通道信号
logic    if2id_up_ready;
logic    if2id_dn_valid;
logic    id2ex_up_ready;
logic    id2ex_dn_valid;
logic    ex2mem_up_ready;
logic    ex2mem_dn_valid;
logic    mem2wb_up_ready;
logic    mem2wb_dn_valid;

// ===================================================================
//  通道数据（struct）
// ===================================================================
if_id_t  if_id_up, if_id_dn;
id_ex_t  id_ex_up, id_ex_dn;
ex_mem_t ex_mem_up, ex_mem_dn;
mem_wb_t mem_wb_up, mem_wb_dn;

// ===================================================================
//  ID 阶段中间信号
// ===================================================================
logic [4:0]  decode_rs1_addr, decode_rs2_addr;
logic [4:0]  decode_rd_addr;
logic [31:0] decode_imm;
logic [1:0]  decode_op1_sel, decode_op2_sel;
logic [6:0]  decode_opcode;
logic [2:0]  decode_funct3;
logic [6:0]  decode_funct7;
logic [11:0] decode_csr_addr;
logic        decode_inst_csrrw, decode_inst_csrrs;
logic        decode_inst_ecall, decode_inst_mret;
logic        decode_inst_ebreak;
logic [31:0] reg_rs1_data, reg_rs2_data;

// 前递后的 rs1/rs2（在 ID 阶段选出，直接打入流水线寄存器）
logic [31:0] fwd_rs1_data, fwd_rs2_data;
logic [31:0] id_op1, id_op2;

// ===================================================================
//  EX / MEM / WB 阶段信号
// ===================================================================
logic [31:0] ex_alu_result;
logic        ex_jump_flag;
logic [31:0] ex_jump_target;
logic [31:0] mem_rdata;
logic        wb_wr_en;
logic [4:0]  wb_wr_addr;
logic [31:0] wb_wr_data;

// ===================================================================
//  Hazard / Forward 控制信号
// ===================================================================
logic        load_stall;
logic [1:0]  fwd_rs1_sel;
logic [1:0]  fwd_rs2_sel;

// ===================================================================
//  CSR 接口
// ===================================================================
logic [11:0] csr_raddr;
logic [31:0] csr_rdata;
logic        csr_wen;
logic [11:0] csr_waddr;
logic [31:0] csr_wdata;
logic        trap_valid;
logic [31:0] trap_pc, trap_cause, trap_mtvec, trap_mepc;


// ===================================================================
//  Stage 1 : Fetch (IF)
// ===================================================================

pc_counter #(
    .AW       (AW),
    .RESET_PC (32'h80000000)
) u_pc_counter (
    .clk      (clk),
    .rst_n    (rst_n),
    // stall 时 jump_en=1，jump_addr=pc（原地踏步）
    // 跳转优先级高于 stall，用三目运算符保证正确顺序
    .jump_en  (load_stall | ex_jump_flag),
    .jump_addr(load_stall ? pc : ex_jump_target),
    .pc       (pc)
);

fetch #(
    .AW(AW),
    .DW(DW)
) u_fetch (
    .clk       (clk),
    .rst_n     (rst_n),
    .pc_pointer(pc),
    .instr_out (instr)
);

assign if_id_up.pc    = pc;
assign if_id_up.instr = instr;


// ===================================================================
//  IF/ID 流水线寄存器
// ===================================================================

pipe_reg_if2id u_if2id (
    .clk      (clk),
    .rst_n    (rst_n),
    .flush    (ex_jump_flag),
    .stall    (load_stall),    // ← 替换~load_stall，通过stall端口实现保持（hold）
    .up_valid (1'b1),          // ← 恒为1（stall由stall端口处理）
    .up_ready (if2id_up_ready),
    .up_data  (if_id_up),
    .dn_valid (if2id_dn_valid),
    .dn_ready (id2ex_up_ready),
    .dn_data  (if_id_dn)
);


// ===================================================================
//  Stage 2 : Decode (ID)
// ===================================================================

decode #(
    .AW(AW),
    .DW(DW)
) u_decode (
    .instr_addr_in (if_id_dn.pc),
    .instr_in      (if_id_dn.instr),
    .rd_rs1_addr   (decode_rs1_addr),
    .rd_rs2_addr   (decode_rs2_addr),
    .rd_addr_out   (decode_rd_addr),
    .imm_out       (decode_imm),
    .op1_sel_out   (decode_op1_sel),
    .op2_sel_out   (decode_op2_sel),
    .opcode_out    (decode_opcode),
    .funct3_out    (decode_funct3),
    .funct7_out    (decode_funct7),
    .inst_ebreak   (decode_inst_ebreak),
    .csr_addr_out  (decode_csr_addr),
    .inst_csrrw    (decode_inst_csrrw),
    .inst_csrrs    (decode_inst_csrrs),
    .inst_ecall    (decode_inst_ecall),
    .inst_mret     (decode_inst_mret)
);

reg_file #(
    .DW(DW)
) u_reg_file (
    .clk      (clk),
    .rst_n    (rst_n),
    .rs1_addr (decode_rs1_addr),
    .rs2_addr (decode_rs2_addr),
    .rs1_data (reg_rs1_data),
    .rs2_data (reg_rs2_data),
    .wr_en    (wb_wr_en),
    .wr_addr  (wb_wr_addr),
    .wr_data  (wb_wr_data),
    .debug_x10(debug_x10),
    .regs     (regs)
);

// ------------------------------------------------------------------
//  Hazard Detection Unit（load-use 冒险检测）
//  当前在 EX 的指令是 load，且目标寄存器是 ID 阶段的源寄存器
// ------------------------------------------------------------------
hazard_unit u_hazard (
    .ex_opcode   (id_ex_dn.opcode),
    .ex_rd_addr  (id_ex_dn.rd_addr),
    .id_rs1_addr (decode_rs1_addr),
    .id_rs2_addr (decode_rs2_addr),
    .stall       (load_stall)
);

// ------------------------------------------------------------------
//  Forward Unit（数据前递，在 ID 阶段选好，避免 EX 用到旧值）
//  数据源优先级：EX/MEM > MEM/WB > 寄存器堆
// ------------------------------------------------------------------
forward_unit u_forward (
    .ex_rs1_addr      (decode_rs1_addr),
    .ex_rs2_addr      (decode_rs2_addr),

    // 新增：当前在 EX 阶段的指令
    .ex_stage_rd_addr (id_ex_dn.rd_addr),
    .ex_stage_opcode  (id_ex_dn.opcode),

    .mem_rd_addr      (ex_mem_dn.rd_addr),
    .mem_opcode       (ex_mem_dn.opcode),
    .wb_rd_addr       (mem_wb_dn.rd_addr),
    .wb_opcode        (mem_wb_dn.opcode),
    .fwd_rs1_sel      (fwd_rs1_sel),
    .fwd_rs2_sel      (fwd_rs2_sel)
);

// 前递 mux：选出 rs1/rs2 的最新值
// wb_wr_data 是 writeback 模块输出的最终写回值（load 时是 mem_rdata，其余是 alu_result）
always_comb begin
    case (fwd_rs1_sel)
        2'b01:   fwd_rs1_data = ex_alu_result;
        2'b10:   fwd_rs1_data = (ex_mem_dn.opcode == `INST_TYPE_L)
                                 ? mem_rdata                // load：实际数据
                                 : ex_mem_dn.alu_result;   // 普通指令：ALU结果
        2'b11:   fwd_rs1_data = wb_wr_data;
        default: fwd_rs1_data = reg_rs1_data;
    endcase
    case (fwd_rs2_sel)
        2'b01:   fwd_rs2_data = ex_alu_result;
        2'b10:   fwd_rs2_data = (ex_mem_dn.opcode == `INST_TYPE_L)
                                 ? mem_rdata
                                 : ex_mem_dn.alu_result;
        2'b11:   fwd_rs2_data = wb_wr_data;
        default: fwd_rs2_data = reg_rs2_data;
    endcase
end

// op1/op2 mux：RS1/RS2 通路使用前递后的值
always_comb begin
    case (decode_op1_sel)
        2'b00:   id_op1 = fwd_rs1_data;   // OP1_RS1 → 前递值
        2'b01:   id_op1 = if_id_dn.pc;    // OP1_PC
        2'b10:   id_op1 = 32'h0;          // OP1_ZERO
        default: id_op1 = 32'h0;
    endcase
    case (decode_op2_sel)
        2'b00:   id_op2 = fwd_rs2_data;   // OP2_RS2 → 前递值
        2'b01:   id_op2 = decode_imm;     // OP2_IMM
        2'b10:   id_op2 = 32'd4;          // OP2_4
        default: id_op2 = 32'h0;
    endcase
end

// 打包 ID → EX 数据（op1/op2 已经是前递后的正确值）
assign id_ex_up.pc          = if_id_dn.pc;
assign id_ex_up.instr       = if_id_dn.instr;
assign id_ex_up.op1         = id_op1;
assign id_ex_up.op2         = id_op2;
assign id_ex_up.rd_addr     = decode_rd_addr;
assign id_ex_up.imm         = decode_imm;
assign id_ex_up.opcode      = decode_opcode;
assign id_ex_up.funct3      = decode_funct3;
assign id_ex_up.funct7      = decode_funct7;
assign id_ex_up.rs1_data    = fwd_rs1_data;  // 前递后的值（branch 比较用）
assign id_ex_up.rs2_data    = fwd_rs2_data;  // 前递后的值（store 数据用）
assign id_ex_up.csr_addr    = decode_csr_addr;
assign id_ex_up.inst_csrrw  = decode_inst_csrrw;
assign id_ex_up.inst_csrrs  = decode_inst_csrrs;
assign id_ex_up.inst_ecall  = decode_inst_ecall;
assign id_ex_up.inst_mret   = decode_inst_mret;
assign id_ex_up.inst_ebreak = decode_inst_ebreak;


// ===================================================================
//  ID/EX 流水线寄存器
//  load_stall 时 flush，插入气泡（NOP），不让错误数据进 EX
// ===================================================================

pipe_reg_id2ex u_id2ex (
    .clk      (clk),
    .rst_n    (rst_n),
    .flush    (ex_jump_flag | load_stall),

    .up_valid (if2id_dn_valid),
    .up_ready (id2ex_up_ready),
    .up_data  (id_ex_up),

    .dn_valid (id2ex_dn_valid),
    .dn_ready (ex2mem_up_ready),
    .dn_data  (id_ex_dn)
);


// ===================================================================
//  Stage 3 : Execute (EX)
//  op1/op2/rs1_data/rs2_data 已经是前递后的正确值，直接用
// ===================================================================

execute #(
    .AW(AW),
    .DW(DW)
) u_execute (
    .pc_in           (id_ex_dn.pc),
    .op1_in          (id_ex_dn.op1),
    .op2_in          (id_ex_dn.op2),
    .rs1_data_in     (id_ex_dn.rs1_data),
    .imm_in          (id_ex_dn.imm),
    .opcode_in       (id_ex_dn.opcode),
    .funct3_in       (id_ex_dn.funct3),
    .funct7_in       (id_ex_dn.funct7),
    .alu_result_out  (ex_alu_result),
    .jump_flag_out   (ex_jump_flag),
    .jump_target_out (ex_jump_target),
    .inst_ebreak_in  (id_ex_dn.inst_ebreak),
    .csr_addr_in     (id_ex_dn.csr_addr),
    .inst_csrrw      (id_ex_dn.inst_csrrw),
    .inst_csrrs      (id_ex_dn.inst_csrrs),
    .inst_ecall      (id_ex_dn.inst_ecall),
    .inst_mret       (id_ex_dn.inst_mret),
    .csr_raddr       (csr_raddr),
    .csr_rdata       (csr_rdata),
    .csr_wen         (csr_wen),
    .csr_waddr       (csr_waddr),
    .csr_wdata       (csr_wdata),
    .trap_valid      (trap_valid),
    .trap_pc         (trap_pc),
    .trap_cause      (trap_cause),
    .trap_mtvec      (trap_mtvec),
    .trap_mepc       (trap_mepc)
);

assign ex_mem_up.alu_result = ex_alu_result;
assign ex_mem_up.rs2_data   = id_ex_dn.rs2_data; // store 数据（已前递）
assign ex_mem_up.rd_addr    = id_ex_dn.rd_addr;
assign ex_mem_up.opcode     = id_ex_dn.opcode;
assign ex_mem_up.funct3     = id_ex_dn.funct3;


// ===================================================================
//  EX/MEM 流水线寄存器
// ===================================================================

pipe_reg_ex2mem u_ex2mem (
    .clk      (clk),
    .rst_n    (rst_n),
    .flush    (1'b0),

    .up_valid (id2ex_dn_valid),
    .up_ready (ex2mem_up_ready),
    .up_data  (ex_mem_up),

    .dn_valid (ex2mem_dn_valid),
    .dn_ready (mem2wb_up_ready),
    .dn_data  (ex_mem_dn)
);


// ===================================================================
//  Stage 4 : Memory (MEM)
// ===================================================================

memory #(
    .AW(AW),
    .DW(DW)
) u_memory (
    .clk          (clk),
    .rst_n        (rst_n),
    .alu_result_in(ex_mem_dn.alu_result),
    .rs2_data_in  (ex_mem_dn.rs2_data),
    .opcode_in    (ex_mem_dn.opcode),
    .funct3_in    (ex_mem_dn.funct3),
    .mem_rdata_out(mem_rdata)
);

assign mem_wb_up.alu_result = ex_mem_dn.alu_result;
assign mem_wb_up.mem_rdata  = mem_rdata;
assign mem_wb_up.rd_addr    = ex_mem_dn.rd_addr;
assign mem_wb_up.opcode     = ex_mem_dn.opcode;


// ===================================================================
//  MEM/WB 流水线寄存器
// ===================================================================

pipe_reg_mem2wb u_mem2wb (
    .clk      (clk),
    .rst_n    (rst_n),
    .flush    (1'b0),

    .up_valid (ex2mem_dn_valid),
    .up_ready (mem2wb_up_ready),
    .up_data  (mem_wb_up),

    .dn_valid (mem2wb_dn_valid),
    .dn_ready (1'b1),          // WB 纯组合，永远 ready
    .dn_data  (mem_wb_dn)
);


// ===================================================================
//  Stage 5 : Writeback (WB)
// ===================================================================

writeback #(
    .DW(DW)
) u_writeback (
    .alu_result_in(mem_wb_dn.alu_result),
    .mem_rdata_in (mem_wb_dn.mem_rdata),
    .opcode_in    (mem_wb_dn.opcode),
    .rd_addr_in   (mem_wb_dn.rd_addr),
    .wb_en        (wb_wr_en),
    .wb_addr      (wb_wr_addr),
    .wb_data      (wb_wr_data)  // ← forward_unit 的 MEM/WB 前递数据源
);


// ===================================================================
//  CSR File
// ===================================================================

csr_file #(
    .STU_ID(32'd250309)
) u_csr_file (
    .clk        (clk),
    .rst        (~rst_n),
    .csr_raddr  (csr_raddr),
    .csr_rdata  (csr_rdata),
    .csr_wen    (csr_wen),
    .csr_waddr  (csr_waddr),
    .csr_wdata  (csr_wdata),
    .trap_valid (trap_valid),
    .trap_pc    (trap_pc),
    .trap_cause (trap_cause),
    .trap_mtvec (trap_mtvec),
    .trap_mepc  (trap_mepc)
);

endmodule