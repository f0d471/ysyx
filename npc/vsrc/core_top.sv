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

// --- [新增] Decode 出的 CSR/Exception 信号 ---
logic [11:0]    decode_csr_addr;
logic           decode_inst_csrrw;
logic           decode_inst_csrrs;
logic           decode_inst_ecall;
logic           decode_inst_mret;

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

// --- [新增] ID/EX 透传的 CSR/Exception 信号 ---
logic [11:0]    id_csr_addr;
logic           id_inst_csrrw;
logic           id_inst_csrrs;
logic           id_inst_ecall;
logic           id_inst_mret;

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

// ---------------- CSR ---------------------
logic [11:0]    csr_raddr;
logic [31:0]    csr_rdata;
logic           csr_wen;
logic [11:0]    csr_waddr;
logic [31:0]    csr_wdata;

logic           trap_valid;
logic [31:0]    trap_pc;
logic [31:0]    trap_cause;
logic [31:0]    trap_mtvec;
logic [31:0]    trap_mepc;

// ================================== 模块例化 =======================================

    // ---------------- Stage 1: Fetch (IF) ----------------
    pc_counter #( 
        .AW             (AW),
        .RESET_PC       (32'h80000000) 
    ) u_pc_counter ( 
        .clk            (clk),
        .rst_n          (rst_n),
        .jump_en        (ex_jump_flag),   
        .jump_addr      (ex_jump_target),
        .pc             (pc) 
    );  

    fetch #(
        .AW             (AW),  
        .DW             (DW)
    ) u_fetch (                        
        .clk            (clk),
        .rst_n          (rst_n),
        .pc_pointer     (pc),
        .instr_out      (instr)  
    ); 

    if2id #(
        .AW (AW),  
        .DW (DW)   
    ) u_if2id ( 
        .instr_addr_in  (pc), 
        .instr_in       (instr),
        .instr_addr_out (instr_addr_out),
        .instr_out      (instr_out)     
    );  

    // ---------------- Stage 2: Decode (ID) ----------------
    decode #(
        .AW(AW),
        .DW(DW)
    ) u_decode (
        .instr_addr_in  (instr_addr_out),
        .instr_in       (instr_out),
        
        .rd_rs1_addr    (decode_rs1_addr),
        .rd_rs2_addr    (decode_rs2_addr),
        
        .rd_addr_out    (decode_rd_addr),
        .imm_out        (decode_imm),
        .op1_sel_out    (decode_op1_sel),
        .op2_sel_out    (decode_op2_sel),
        
        .opcode_out     (decode_opcode),
        .funct3_out     (decode_funct3),
        .funct7_out     (decode_funct7),
        
        .inst_ebreak    (inst_ebreak),

        // --- [新增] CSR 输出连接 ---
        .csr_addr_out   (decode_csr_addr),
        .inst_csrrw     (decode_inst_csrrw),
        .inst_csrrs     (decode_inst_csrrs),
        .inst_ecall     (decode_inst_ecall),
        .inst_mret      (decode_inst_mret)
    );

    reg_file #(
        .DW(DW)
    ) u_reg_file (
        .clk            (clk),
        .rst_n          (rst_n),
        .rs1_addr       (decode_rs1_addr),
        .rs2_addr       (decode_rs2_addr),
        .rs1_data       (reg_rs1_data),
        .rs2_data       (reg_rs2_data),
        .wr_en          (wb_wr_en),
        .wr_addr        (wb_wr_addr),
        .wr_data        (wb_wr_data),
        .debug_x10      (debug_x10),
        .regs           (regs)
    );

    id2ex #(
        .AW(AW),
        .DW(DW)
    ) u_id2ex (
        .instr_addr_in  (instr_addr_out),  
        .instr_in       (instr_out),
        
        .rd_addr_in     (decode_rd_addr),
        .imm_in         (decode_imm),
        .op1_sel_in     (decode_op1_sel),
        .op2_sel_in     (decode_op2_sel),
        .opcode_in      (decode_opcode),
        .funct3_in      (decode_funct3),
        .funct7_in      (decode_funct7),
        
        .rs1_data_in    (reg_rs1_data),
        .rs2_data_in    (reg_rs2_data),
        
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
        
        .inst_ebreak_in (inst_ebreak),
        .inst_ebreak_out(inst_ebreak_out),

        // --- [新增] CSR 透传连接 ---
        .csr_addr_in    (decode_csr_addr),
        .inst_csrrw_in  (decode_inst_csrrw),
        .inst_csrrs_in  (decode_inst_csrrs),
        .inst_ecall_in  (decode_inst_ecall),
        .inst_mret_in   (decode_inst_mret),

        .csr_addr_out   (id_csr_addr),
        .inst_csrrw_out (id_inst_csrrw),
        .inst_csrrs_out (id_inst_csrrs),
        .inst_ecall_out (id_inst_ecall),
        .inst_mret_out  (id_inst_mret)
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
        
        .alu_result_out  (ex_alu_result),
        .jump_flag_out   (ex_jump_flag),   
        .jump_target_out (ex_jump_target),
        
        .inst_ebreak_in  (inst_ebreak_out),

        // --- [新增] CSR 及 异常控制输入 ---
        .csr_addr_in     (id_csr_addr),
        .inst_csrrw      (id_inst_csrrw),
        .inst_csrrs      (id_inst_csrrs),
        .inst_ecall      (id_inst_ecall),
        .inst_mret       (id_inst_mret),

        // --- [新增] 与 CSR File 交互的接口 ---
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

    ex2mem #(
        .AW (AW),
        .DW (DW)
    ) u_ex2mem (
        .rs2_data_in    (id_rs2_data),
        .pc_in          (id_instr_addr_out),
        .rd_addr_in     (id_rd_addr_out),
        .opcode_in      (id_opcode_out),
        .funct3_in      (id_funct3_out),
        .alu_result_in  (ex_alu_result),
        
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
        .alu_result_in  (ex_alu_result_out), 
        .rs2_data_in    (ex_rs2_data),   
        .opcode_in      (ex_opcode),
        .funct3_in      (ex_funct3),
        
        .mem_rdata_out  (mem_rdata)  
    );

    mem2wb #(
        .AW (AW),
        .DW (DW)
    ) u_mem2wb (
        .alu_result_in  (ex_alu_result_out),
        .rd_addr_in     (ex_rd_addr),
        .opcode_in      (ex_opcode),
        .mem_rdata_in   (mem_rdata),
        
        .alu_result_out (mem_alu_result),
        .mem_rdata_out  (mem_rdata_out),
        .opcode_out     (mem_opcode),
        .rd_addr_out    (mem_rd_addr)
    );

    // ---------------- Stage 5: Writeback (WB) ----------------
    writeback #(
        .DW (DW)
    ) u_writeback (
        .alu_result_in (mem_alu_result),
        .mem_rdata_in  (mem_rdata_out),
        .opcode_in     (mem_opcode),
        .rd_addr_in    (mem_rd_addr),
        
        .wb_en         (wb_wr_en),
        .wb_addr       (wb_wr_addr),
        .wb_data       (wb_wr_data)
    );

    // ---------------- CSR File ----------------
    csr_file #(
        .STU_ID     (32'd250309) 
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