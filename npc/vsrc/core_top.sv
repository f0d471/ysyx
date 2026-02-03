`include "define.sv"

import "DPI-C" function void trap(input int code, input int pc);
import "DPI-C" function int paddr_read(input int addr);
import "DPI-C" function void paddr_write(input int addr, input int len, input int data);

module top #(
    parameter AW = 32, // 地址位宽
    parameter DW = 32  // 数据位宽
)( 
    input  logic          clk,
    input  logic          rst_n,

    output logic [AW-1:0] pc,
    output logic [DW-1:0] instr,
    output logic [DW-1:0] debug_x10,
    output logic [DW-1:0] regs [15:0] 
); 

// ================================== 全局连线定义 =======================================

// ---------------- IF Stage ----------------
// logic [DW-1:0]  pc;
// logic [DW-1:0]  instr;

// ---------------- IF / ID ----------------
logic [AW-1:0]  instr_addr_out;
logic [DW-1:0]  instr_out;

// ---------------- ID Stage ----------------
logic [4:0]     decode_rs1_addr;
logic [4:0]     decode_rs2_addr;
logic [4:0]     decode_rd_addr;

logic [DW-1:0]  decode_imm;
logic [1:0]     decode_op1_sel;
logic [1:0]     decode_op2_sel;

logic [6:0]     decode_opcode;
logic [2:0]     decode_funct3;
logic [6:0]     decode_funct7;

// ---------------- Register File ----------------
logic [DW-1:0]  reg_rs1_data;
logic [DW-1:0]  reg_rs2_data;

// ---------------- ID / EX ----------------
logic [AW-1:0]  id_instr_addr_out;
logic [DW-1:0]  id_instr_out;

logic [DW-1:0]  id_op1_out;
logic [DW-1:0]  id_op2_out;

logic [4:0]     id_rd_addr_out;
logic [DW-1:0]  id_imm_out;

logic [6:0]     id_opcode_out;
logic [2:0]     id_funct3_out;
logic [6:0]     id_funct7_out;

logic [DW-1:0]  id_rs1_data;
logic [DW-1:0]  id_rs2_data;

// ---------------- EX Stage ----------------
logic [DW-1:0]  ex_alu_result;
logic           ex_jump_flag;
logic [AW-1:0]  ex_jump_target;

// ---------------- EX / MEM ----------------
logic [DW-1:0]  ex_alu_result_out;
logic [DW-1:0]  ex_rs2_data;
logic [4:0]     ex_rd_addr;
logic [6:0]     ex_opcode;
logic [2:0]     ex_funct3;

// ---------------- MEM Stage ----------------
logic [DW-1:0]  mem_rdata;

// ---------------- MEM / WB ----------------
logic [DW-1:0]  mem_alu_result;
logic [DW-1:0]  mem_rdata_out;
logic [4:0]     mem_rd_addr;
logic [6:0]     mem_opcode;

// ---------------- WB Stage ----------------
logic           wb_wr_en;
logic [4:0]     wb_wr_addr;
logic [DW-1:0]  wb_wr_data;

// --------------- ebreak -------------------
logic inst_ebreak;
logic inst_ebreak_out;

// ================================== 模块例化 =======================================

    // ---------------- Stage 1: Fetch (IF) ----------------
    pc_counter #( 
        .AW             (AW),
        .RESET_PC       (32'h80000000) 
    ) u_pc_counter ( 
        .clk            (clk),
        .rst_n          (rst_n),

        // from EX
        // .pc_stall    (1'b0),  
        .jump_en        (ex_jump_flag),   
        .jump_addr      (ex_jump_target),
        // to fetch
        .pc             (pc) 
    );  

    fetch #(
        .AW             (AW),  
        .DW             (DW)
    ) u_fetch (                        
        .clk            (clk),
        .rst_n          (rst_n),

        //from pc_counter
        .pc_pointer     (pc),
        // to if 
        .instr_out      (instr)  
    ); 

    if2id #(
        .AW (AW),  
        .DW (DW)   
    ) u_if2id ( 
        // from ex
        // .if_stall    (1'b0),         
        // .if_flush    (ex_jump_flag),
        // from if
        .instr_addr_in  (pc), 
        .instr_in       (instr),
        // to id
        .instr_addr_out (instr_addr_out),
        .instr_out      (instr_out)     
    );  

    // ---------------- Stage 2: Decode (ID) ----------------
    decode #(
        .AW(AW),
        .DW(DW)
    ) u_decode (
        // from if
        .instr_addr_in  (instr_addr_out),
        .instr_in       (instr_out),
        // to reg
        .rd_rs1_addr    (decode_rs1_addr),
        .rd_rs2_addr    (decode_rs2_addr),
        // to id2ex
        .rd_addr_out    (decode_rd_addr),
        .imm_out        (decode_imm),
        .op1_sel_out    (decode_op1_sel),
        .op2_sel_out    (decode_op2_sel),
        // to ex
        .opcode_out     (decode_opcode),
        .funct3_out     (decode_funct3),
        .funct7_out     (decode_funct7),
        //erbreak
        .inst_ebreak    (inst_ebreak)
    );

    reg_file #(
        .DW(DW)
    ) u_reg_file (
        .clk            (clk),
        .rst_n          (rst_n),
        // read from decode
        .rs1_addr       (decode_rs1_addr),
        .rs2_addr       (decode_rs2_addr),
        // read to ex
        .rs1_data       (reg_rs1_data),
        .rs2_data       (reg_rs2_data),
        // write from wb
        .wr_en          (wb_wr_en),
        .wr_addr        (wb_wr_addr),
        .wr_data        (wb_wr_data),
        // for test
        .debug_x10      (debug_x10),
        .regs           (regs)
    );

    id2ex #(
        .AW(AW),
        .DW(DW)
    ) u_id2ex (

        // from if
        .instr_addr_in  (instr_addr_out),  
        .instr_in       (instr_out),
        // from decode
        .rd_addr_in     (decode_rd_addr),
        .imm_in         (decode_imm),
        .op1_sel_in     (decode_op1_sel),
        .op2_sel_in     (decode_op2_sel),
        .opcode_in      (decode_opcode),
        .funct3_in      (decode_funct3),
        .funct7_in      (decode_funct7),
        // from register
        .rs1_data_in    (reg_rs1_data),
        .rs2_data_in    (reg_rs2_data),
        // to ex
        .instr_addr_out (id_instr_addr_out),
        .instr_out      (id_instr_out),
        .op1_out        (id_op1_out),
        .op2_out        (id_op2_out),
        .rd_addr_out    (id_rd_addr_out),
        .imm_out        (id_imm_out),
        .opcode_out     (id_opcode_out),
        .funct3_out     (id_funct3_out),
        .funct7_out     (id_funct7_out),
        .rs1_data_out   (id_rs1_data),
        .rs2_data_out   (id_rs2_data),
        //erbeak
        .inst_ebreak_in (inst_ebreak),
        .inst_ebreak_out(inst_ebreak_out)
    );

    // ---------------- Stage 3: Execute (EX) ----------------
    execute #(
        .AW (AW),
        .DW (DW)
    ) u_execute (
        .pc_in           (id_instr_addr_out),
        .op1_in          (id_op1_out),
        .op2_in          (id_op2_out),
        .rs1_data_in     (id_rs1_data), 
        .imm_in          (id_imm_out),
        .opcode_in       (id_opcode_out),
        .funct3_in       (id_funct3_out),
        .funct7_in       (id_funct7_out),
        // to mem
        .alu_result_out  (ex_alu_result),
        // to pc
        .jump_flag_out   (ex_jump_flag),   
        .jump_target_out (ex_jump_target),
        //ebreak
        .inst_ebreak_in  (inst_ebreak_out)
    );

    ex2mem #(
        .AW (AW),
        .DW (DW)
    ) u_ex2mem (
        //from id
        .rs2_data_in    (id_rs2_data),
        .pc_in          (id_instr_addr_out),
        .rd_addr_in     (id_rd_addr_out),
        .opcode_in      (id_opcode_out),
        .funct3_in      (id_funct3_out),
        // from ex
        .alu_result_in  (ex_alu_result),
        // to mem
        .alu_result_out (ex_alu_result_out),
        .rs2_data_out   (ex_rs2_data),
        .rd_addr_out    (ex_rd_addr),
        .opcode_out     (ex_opcode),
        .funct3_out     (ex_funct3)
    );

    // ---------------- Stage 4: Load-Store (LS) ----------------
    memory #(
        .AW (AW),
        .DW (DW)
    ) u_memory (
        .clk            (clk),
        .rst_n          (rst_n),
        // from ex
        .alu_result_in  (ex_alu_result_out), 
        .rs2_data_in    (ex_rs2_data),   
        .opcode_in      (ex_opcode),
        .funct3_in      (ex_funct3),
        // to wb
        .mem_rdata_out  (mem_rdata)  
    );

    mem2wb #(
        .AW (AW),
        .DW (DW)
    ) u_mem2wb (
        // from ex
        .alu_result_in  (ex_alu_result_out),
        .rd_addr_in     (ex_rd_addr),
        .opcode_in      (ex_opcode),
        // from mem
        .mem_rdata_in   (mem_rdata),
        // to wb
        .alu_result_out (mem_alu_result),
        .mem_rdata_out  (mem_rdata_out),
        .opcode_out     (mem_opcode),
        .rd_addr_out    (mem_rd_addr)
    );

    // ---------------- Stage 5: Writeback (WB) ----------------
    writeback #(
        .DW (DW)
    ) u_writeback (
        // from wb
        .alu_result_in (mem_alu_result),
        .mem_rdata_in  (mem_rdata_out),
        .opcode_in     (mem_opcode),
        .rd_addr_in    (mem_rd_addr),
        // to reg
        .wb_en         (wb_wr_en),
        .wb_addr       (wb_wr_addr),
        .wb_data       (wb_wr_data)
    );

endmodule