`include "define.sv"

import "DPI-C" function void trap(input int code, input int pc);

module core #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n,
    
    // IFU SimpleBus 接口
    output logic [AW-1:0] ifu_raddr,
    output logic          ifu_reqValid,
    input  logic          ifu_reqReady,
    input  logic [DW-1:0] ifu_rdata,
    input  logic          ifu_respValid,
    output logic          ifu_respReady,

    // LSU 握手接口
    output logic [AW-1:0] lsu_addr,
    output logic          lsu_ren,
    output logic          lsu_wen,
    output logic [DW-1:0] lsu_wdata,
    output logic [3:0]    lsu_wmask,
    output logic          lsu_reqValid,
    input  logic          lsu_reqReady,
    input  logic [DW-1:0] lsu_rdata,
    input  logic          lsu_respValid,
    output logic          lsu_respReady,
 
    // Debug / Commit 信号  
    output logic [DW-1:0] debug_regs [15:0],
    output logic          debug_have,
    output logic [31:0]   debug_pc,
    output logic [31:0]   debug_instr,
    output logic          debug_en,
    output logic [4:0]    debug_addr,
    output logic [31:0]   debug_data
);

// 握手通道信号
logic    if2id_up_ready;
logic    if2id_dn_valid;
logic    id2ex_up_ready;
logic    id2ex_dn_valid;
logic    ex2mem_up_ready;
logic    ex2mem_dn_valid;
logic    mem2wb_up_ready;
logic    mem2wb_dn_valid;

// 通道数据（struct）
if_id_t  if_id_up, if_id_dn;
id_ex_t  id_ex_up, id_ex_dn;
ex_mem_t ex_mem_up, ex_mem_dn;
mem_wb_t mem_wb_up, mem_wb_dn;

// IF 阶段内部信号
logic [AW-1:0] pc;
logic [DW-1:0] instr;

// ID 阶段中间信号
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
logic        decode_wr_en, decode_is_load, decode_is_store;
logic [31:0] reg_rs1_data, reg_rs2_data;

// 前递后的 rs1/rs2
logic [31:0] fwd_rs1_data, fwd_rs2_data;
logic [31:0] id_op1, id_op2;

// EX / MEM / WB 阶段信号
logic [31:0] ex_alu_result;
logic        ex_jump_flag;
logic [31:0] ex_jump_target;
logic [31:0] mem_rdata;
logic        wb_wr_en;
logic [4:0]  wb_wr_addr;
logic [31:0] wb_wr_data;

// Hazard / Forward 控制信号
logic        load_stall;
logic [1:0]  fwd_rs1_sel;
logic [1:0]  fwd_rs2_sel;

// IFU 控制信号
logic        ifu_valid;        
logic        lsu_busy;  
       
// CSR 接口
logic [11:0] csr_raddr;
logic [31:0] csr_rdata;
logic        csr_wen;
logic [11:0] csr_waddr;
logic [31:0] csr_wdata;
logic        trap_valid;
logic [31:0] trap_pc, trap_cause, trap_mtvec, trap_mepc;

// IF
pc_counter #(
    .AW       (AW),
    .RESET_PC (32'h80000000)
) u_pc_counter (
    .clk      (clk),
    .rst_n    (rst_n),
    .jump_en  (ex_jump_flag),
    .jump_addr(ex_jump_target),
    .pc_hold  (!ifu_valid | load_stall | lsu_busy),
    .pc       (pc)
);

fetch #(
    .AW(AW),
    .DW(DW)
) u_fetch (
    .clk          (clk),
    .rst_n        (rst_n),
    .pc_pointer   (pc),
    .ifu_raddr    (ifu_raddr),
    .ifu_rdata    (ifu_rdata),
    .ifu_reqValid (ifu_reqValid),
    .ifu_reqReady (ifu_reqReady),
    .ifu_respValid(ifu_respValid),
    .ifu_respReady(ifu_respReady),
    .flush        (ex_jump_flag),
    .stall        (load_stall | lsu_busy),      
    .instr_out    (instr),
    .ifu_valid    (ifu_valid)
);

assign if_id_up.pc    = pc;
assign if_id_up.instr = instr;

pipe_reg #(.DW($bits(if_id_t))) u_if2id (
    .clk      (clk),
    .rst_n    (rst_n),
    .flush    (ex_jump_flag),
    .stall    (load_stall | lsu_busy),          
    .up_valid (ifu_valid),              
    .up_ready (if2id_up_ready),
    .up_data  (if_id_up),
    .dn_valid (if2id_dn_valid),
    .dn_ready (id2ex_up_ready),
    .dn_data  (if_id_dn)
);

// ID
decode #(
    .AW(AW),
    .DW(DW)
) u_decode (
    .inst_addr_in (if_id_dn.pc),
    .inst_in      (if_id_dn.instr),
    .rs1_addr     (decode_rs1_addr),
    .rs2_addr     (decode_rs2_addr),
    .rd_addr_out   (decode_rd_addr),
    .imm_out       (decode_imm),
    .op1_sel_out   (decode_op1_sel),
    .op2_sel_out   (decode_op2_sel),
    .opcode_out    (decode_opcode),
    .funct3_out    (decode_funct3),
    .funct7_out    (decode_funct7),
    .inst_ebreak   (decode_inst_ebreak),
    .inst_wr_en    (decode_wr_en),
    .inst_is_load  (decode_is_load),
    .inst_is_store (decode_is_store),
    .csr_addr  (decode_csr_addr),
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
    .regs     (debug_regs)
);

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

//  Hazard 
hazard_unit u_hazard (
    .ex_is_load  (id_ex_dn.is_load),
    .ex_rd_addr  (id_ex_dn.rd_addr),
    .id_rs1_addr (decode_rs1_addr),
    .id_rs2_addr (decode_rs2_addr),
    .stall       (load_stall)
);

//  Forward 
forward_unit u_forward (
    .ex_rs1_addr      (decode_rs1_addr),
    .ex_rs2_addr      (decode_rs2_addr),

    .ex_wr_en         (id_ex_dn.wr_en),
    .ex_stage_rd_addr (id_ex_dn.rd_addr),
    .ex_alu_result    (ex_alu_result),

    .mem_wr_en        (ex_mem_dn.wr_en),
    .mem_is_load      (ex_mem_dn.is_load),
    .mem_rd_addr      (ex_mem_dn.rd_addr),
    .ex_mem_alu_result(ex_mem_dn.alu_result),
    .mem_rdata        (mem_rdata),

    .wb_wr_en         (mem_wb_dn.wr_en),
    .wb_rd_addr       (mem_wb_dn.rd_addr),
    .wb_wr_data       (wb_wr_data),

    .reg_rs1_data     (reg_rs1_data),
    .reg_rs2_data     (reg_rs2_data),

    .fwd_rs1_data     (fwd_rs1_data),  
    .fwd_rs2_data     (fwd_rs2_data)
);

// EX
always_comb begin
    case (decode_op1_sel)
        `OP1_RS1:  id_op1 = fwd_rs1_data;
        `OP1_PC:   id_op1 = if_id_dn.pc;
        `OP1_ZERO: id_op1 = 32'h0;
        default:   id_op1 = 32'h0;
    endcase
    case (decode_op2_sel)
        `OP2_RS2: id_op2 = fwd_rs2_data;
        `OP2_IMM: id_op2 = decode_imm;
        `OP2_4:   id_op2 = 32'd4;
        default:  id_op2 = 32'h0;
    endcase
end

assign id_ex_up.op1         = id_op1;
assign id_ex_up.op2         = id_op2;
assign id_ex_up.pc          = if_id_dn.pc;
assign id_ex_up.instr       = if_id_dn.instr;
assign id_ex_up.rd_addr     = decode_rd_addr;
assign id_ex_up.imm         = decode_imm;
assign id_ex_up.opcode      = decode_opcode;
assign id_ex_up.funct3      = decode_funct3;
assign id_ex_up.funct7      = decode_funct7;
assign id_ex_up.rs1_data    = fwd_rs1_data;  
assign id_ex_up.rs2_data    = fwd_rs2_data;  
assign id_ex_up.csr_addr    = decode_csr_addr;
assign id_ex_up.rs1_addr    = decode_rs1_addr;
assign id_ex_up.wr_en       = decode_wr_en;
assign id_ex_up.is_load     = decode_is_load;
assign id_ex_up.is_store    = decode_is_store;
assign id_ex_up.inst_csrrw  = decode_inst_csrrw;
assign id_ex_up.inst_csrrs  = decode_inst_csrrs;
assign id_ex_up.inst_ecall  = decode_inst_ecall;
assign id_ex_up.inst_mret   = decode_inst_mret;
assign id_ex_up.inst_ebreak = decode_inst_ebreak;

pipe_reg #(.DW($bits(id_ex_t))) u_id2ex (
    .clk      (clk),
    .rst_n    (rst_n),
    .flush    (ex_jump_flag | load_stall),
    .stall    (lsu_busy),
    .up_valid (if2id_dn_valid),
    .up_ready (id2ex_up_ready),
    .up_data  (id_ex_up),
    .dn_valid (id2ex_dn_valid),
    .dn_ready (ex2mem_up_ready),
    .dn_data  (id_ex_dn)
);

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
    .inst_ebreak     (id_ex_dn.inst_ebreak),
    .csr_addr_in     (id_ex_dn.csr_addr),
    .rs1_addr_in     (id_ex_dn.rs1_addr),
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

assign ex_mem_up.pc         = id_ex_dn.pc;
assign ex_mem_up.instr      = id_ex_dn.instr;    
assign ex_mem_up.alu_result = ex_alu_result;
assign ex_mem_up.rs2_data   = id_ex_dn.rs2_data;
assign ex_mem_up.rd_addr    = id_ex_dn.rd_addr;
assign ex_mem_up.wr_en      = id_ex_dn.wr_en;
assign ex_mem_up.is_load    = id_ex_dn.is_load;
assign ex_mem_up.is_store   = id_ex_dn.is_store;
assign ex_mem_up.opcode     = id_ex_dn.opcode;
assign ex_mem_up.funct3     = id_ex_dn.funct3;

pipe_reg #(.DW($bits(ex_mem_t))) u_ex2mem (
    .clk      (clk),
    .rst_n    (rst_n),
    .flush    (1'b0),
    .stall    (lsu_busy),
    .up_valid (id2ex_dn_valid),
    .up_ready (ex2mem_up_ready),
    .up_data  (ex_mem_up),
    .dn_valid (ex2mem_dn_valid),
    .dn_ready (mem2wb_up_ready),
    .dn_data  (ex_mem_dn)
);

// MEM
memory #(
    .AW(AW),
    .DW(DW)
) u_memory (
    .clk           (clk),
    .rst_n         (rst_n),
    .valid_in      (ex2mem_dn_valid),
    .alu_result_in (ex_mem_dn.alu_result),
    .rs2_data_in   (ex_mem_dn.rs2_data),
    .is_load_in    (ex_mem_dn.is_load),
    .is_store_in   (ex_mem_dn.is_store),
    .funct3_in     (ex_mem_dn.funct3),
    .lsu_addr      (lsu_addr),
    .lsu_ren       (lsu_ren),
    .lsu_wen       (lsu_wen),
    .lsu_wdata     (lsu_wdata),
    .lsu_wmask     (lsu_wmask),
    .lsu_reqValid  (lsu_reqValid),
    .lsu_reqReady  (lsu_reqReady),
    .lsu_rdata     (lsu_rdata),
    .lsu_respValid (lsu_respValid),
    .lsu_respReady (lsu_respReady),
    .lsu_busy      (lsu_busy),
    .mem_rdata_out (mem_rdata)
);

assign mem_wb_up.pc         = ex_mem_dn.pc;       
assign mem_wb_up.instr      = ex_mem_dn.instr;    
assign mem_wb_up.alu_result = ex_mem_dn.alu_result;
assign mem_wb_up.mem_rdata  = mem_rdata;
assign mem_wb_up.rd_addr    = ex_mem_dn.rd_addr;
assign mem_wb_up.wr_en      = ex_mem_dn.wr_en;
assign mem_wb_up.is_load    = ex_mem_dn.is_load;
assign mem_wb_up.opcode     = ex_mem_dn.opcode;

pipe_reg #(.DW($bits(mem_wb_t))) u_mem2wb (
    .clk      (clk),
    .rst_n    (rst_n),
    .flush    (1'b0),
    .stall    (1'b0),
    .up_valid (ex2mem_dn_valid && !lsu_busy),
    .up_ready (mem2wb_up_ready),
    .up_data  (mem_wb_up),
    .dn_valid (mem2wb_dn_valid),
    .dn_ready (1'b1),
    .dn_data  (mem_wb_dn)
);

// WB
writeback #(
    .DW(DW)
) u_writeback (
    .alu_result_in(mem_wb_dn.alu_result),
    .mem_rdata_in (mem_wb_dn.mem_rdata),
    .wr_en_in     (mem_wb_dn.wr_en),
    .is_load_in   (mem_wb_dn.is_load),
    .rd_addr_in   (mem_wb_dn.rd_addr),
    .wb_en        (wb_wr_en),
    .wb_addr      (wb_wr_addr),
    .wb_data      (wb_wr_data)  
);

assign debug_have  = mem2wb_dn_valid;
assign debug_pc    = mem_wb_dn.pc;
assign debug_instr = mem_wb_dn.instr;
assign debug_en    = wb_wr_en;
assign debug_addr  = wb_wr_addr;
assign debug_data  = wb_wr_data;

endmodule