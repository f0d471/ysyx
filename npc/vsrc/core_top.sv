`include "define.sv"

import "DPI-C" function int paddr_read(input int addr);
import "DPI-C" function void paddr_write(input int addr, input int len, input int data);

module top #(
    parameter AW = 32, // 地址位宽
    parameter DW = 32  // 数据位宽
)( 
    input  logic          clk,
    input  logic          rst_n
); 

// ================================== 全局连线定义 =======================================

    //  跳转控制 (来自 EX 阶段) 
    logic          ex_jump_flag;      // 当 EX 阶段判断需要跳转时，拉高此信号，同时刷新流水线
    logic [AW-1:0] ex_jump_target;    // 

    //  IF 
    logic [AW-1:0] pc_pointer;        // 当前 PC
    logic [DW-1:0] instruction;       // 取到的指令

    // --- IF/ID 流水线寄存器输出 ---
    logic [AW-1:0] id_pc;             // 传给 ID 的 PC
    logic [DW-1:0] id_instr;          // 传给 ID 的指令

    // --- ID (译码) 阶段 ---
    logic [4:0]    id_rs1_addr;       // 读寄存器地址 1
    logic [4:0]    id_rs2_addr;       // 读寄存器地址 2
    logic [DW-1:0] id_rs1_data;       // 读寄存器数据 1
    logic [DW-1:0] id_rs2_data;       // 读寄存器数据 2

    logic [4:0]    id_rd_addr;        // 目标寄存器地址
    logic [DW-1:0] id_op1;            // ALU 操作数 1
    logic [DW-1:0] id_op2;            // ALU 操作数 2
    logic [DW-1:0] id_imm;            // 立即数
    logic [6:0]    id_opcode;         // 指令 Opcode
    logic [2:0]    id_funct3;         // Funct3
    logic [6:0]    id_funct7;         // Funct7

    // --- ID/EX 流水线寄存器输出 (EX 阶段输入) ---
    logic [AW-1:0] ex_pc;
    logic [DW-1:0] ex_instr;          
    logic [DW-1:0] ex_op1;
    logic [DW-1:0] ex_op2;
    logic [DW-1:0] ex_rs1_data;       
    logic [DW-1:0] ex_rs2_data;      
    logic [4:0]    ex_rd_addr;
    logic [DW-1:0] ex_imm;
    logic [6:0]    ex_opcode;
    logic [2:0]    ex_funct3;
    logic [6:0]    ex_funct7;

    // --- EX (执行) 阶段输出 ---
    logic [DW-1:0] ex_alu_result;     // ALU 计算结果

    // --- EX/MEM 流水线寄存器输出 (MEM 阶段输入) ---
    logic [AW-1:0] mem_pc;
    logic [DW-1:0] mem_alu_result;    // 也是访存地址
    logic [DW-1:0] mem_rs2_data;      // 写内存的数据
    logic [4:0]    mem_rd_addr;
    logic [6:0]    mem_opcode;
    logic [2:0]    mem_funct3;

    // --- MEM (访存) 阶段输出 ---
    logic [DW-1:0] mem_mem_rdata;     // 从内存读出的数据

    // --- MEM/WB 流水线寄存器输出 (WB 阶段输入) ---
    logic [AW-1:0] wb_pc;
    logic [DW-1:0] wb_alu_result;
    logic [DW-1:0] wb_mem_rdata;
    logic [4:0]    wb_rd_addr;
    logic [6:0]    wb_opcode;

    // --- WB (写回) 阶段输出 (连接回 Register File) ---
    logic          wb_wr_en;          // 写使能
    logic [4:0]    wb_wr_addr;        // 写地址
    logic [DW-1:0] wb_wr_data;        // 写数据

// =========================================================================
// 2. 模块例化 (Module Instantiation)
// =========================================================================

    // ---------------- Stage 1: Fetch (IF) ----------------
    // PC 
    pc_counter #( 
        .AW       (AW),
        .RESET_PC (32'h80000000) 
    ) u_pc_counter ( 
        .clk        (clk),
        .rst_n      (rst_n),
        // 流水线暂停和跳转控制
        .pc_stall   (1'b0),         
        .jump_en    (ex_jump_flag),   
        .jump_addr  (ex_jump_target),
        // 输出的PC
        .pc_pointer (pc_pointer) 
    );  

    // 取指
    fetch #(
        .AW (AW),  
        .DW (DW)
    ) u_fetch (                        
        .clk       (clk),
        .rst_n     (rst_n),
        // PC
        .pc_addr   (pc_pointer),
        // 取出的指令
        .instr_out (instruction)  
    ); 

    // 
    if2id #(
        .AW (AW),  
        .DW (DW)   
    ) u_if2id ( 
        .clk            (clk),
        .rst_n          (rst_n),
        // 流水线暂停和冲刷
        .if_stall       (1'b0),         
        .if_flush       (ex_jump_flag),
        //data in
        .instr_addr_in  (pc_pointer), 
        .instr_in       (instruction),
        //data out
        .instr_addr_out (id_pc),
        .instr_out      (id_instr)     
    );  

    // ---------------- Stage 2: Decode (ID) ----------------
    // 寄存器堆
    register #(
        .DW (DW)
    ) u_register (
        .clk      (clk),
        .rst_n    (rst_n),
        // 读端口 (来自 Decoder)
        .rs1_addr (id_rs1_addr),
        .rs2_addr (id_rs2_addr),
        .rs1_data (id_rs1_data), 
        .rs2_data (id_rs2_data), 
        // 写端口 (来自 WB 阶段)
        .wr_en    (wb_wr_en),
        .wr_addr  (wb_wr_addr),
        .wr_data  (wb_wr_data)
    );

    // 4. 译码器
    decode #(
        .AW (AW),
        .DW (DW)
    ) u_decode (
        .instr_addr_in (id_pc),
        .instr_in      (id_instr),
        // RegFile 接口
        .rd_rs1_addr   (id_rs1_addr), 
        .rd_rs2_addr   (id_rs2_addr),

        .rd_rs1_data   (id_rs1_data), 
        .rd_rs2_data   (id_rs2_data), 
        // 解码结果 -> ID/EX
        .rd_addr_out   (id_rd_addr),
        .op1_out       (id_op1),
        .op2_out       (id_op2),
        .imm_out       (id_imm),
        // to execute
        .opcode_out    (id_opcode),
        .funct3_out    (id_funct3),
        .funct7_out    (id_funct7)
    );

    // Pipeline Reg
    id2ex #(
        .AW (AW),
        .DW (DW)
    ) u_id2ex ( 
        .clk            (clk),
        .rst_n          (rst_n),

        .id_stall       (1'b0),
        .id_flush       (ex_jump_flag), 
        // Inputs
        .instr_addr_in  (id_pc),
        .instr_in       (id_instr),
        .op1_in         (id_op1),
        .op2_in         (id_op2),
        .rs1_data_in    (id_rs1_data),  
        .rs2_data_in    (id_rs2_data),  
        .rd_addr_in     (id_rd_addr),
        .imm_in         (id_imm),
        .opcode_in      (id_opcode),
        .funct3_in      (id_funct3),
        .funct7_in      (id_funct7),
        // Outputs
        .instr_addr_out (ex_pc),
        .instr_out      (ex_instr),
        .op1_out        (ex_op1),
        .op2_out        (ex_op2),
        .rs1_data_out   (ex_rs1_data),  
        .rs2_data_out   (ex_rs2_data),
        .rd_addr_out    (ex_rd_addr),
        .imm_out        (ex_imm),
        .opcode_out     (ex_opcode),
        .funct3_out     (ex_funct3),
        .funct7_out     (ex_funct7)
    );

    // ---------------- Stage 3: Execute (EX) ----------------
    // 执行
    execute #(
        .AW (AW),
        .DW (DW)
    ) u_execute (
        .pc_in           (ex_pc),
        .op1_in          (ex_op1),
        .op2_in          (ex_op2),
        .rs1_data_in     (ex_rs1_data), 
        .imm_in          (ex_imm),
        .opcode_in       (ex_opcode),
        .funct3_in       (ex_funct3),
        .funct7_in       (ex_funct7),
        // Outputs
        .alu_result_out  (ex_alu_result),
        .jump_flag_out   (ex_jump_flag),   
        .jump_target_out (ex_jump_target)  
    );

    // Pipeline Reg
    ex2mem #(
        .AW (AW),
        .DW (DW)
    ) u_ex2mem (
        .clk            (clk),
        .rst_n          (rst_n),
        // Inputs
        .pc_in          (ex_pc),
        .alu_result_in  (ex_alu_result),
        .rs2_data_in    (ex_rs2_data),
        .rd_addr_in     (ex_rd_addr),
        .opcode_in      (ex_opcode),
        .funct3_in      (ex_funct3),
        // Outputs
        .pc_out         (mem_pc),
        .alu_result_out (mem_alu_result),
        .rs2_data_out   (mem_rs2_data),
        .rd_addr_out    (mem_rd_addr),
        .opcode_out     (mem_opcode),
        .funct3_out     (mem_funct3)
    );

    // 访存单元 
    memory #(
        .AW (AW),
        .DW (DW)
    ) u_memory (
        .clk            (clk),
        .rst_n          (rst_n),
        .alu_result_in  (mem_alu_result), 
        .rs2_data_in    (mem_rs2_data),   
        .opcode_in      (mem_opcode),
        .funct3_in      (mem_funct3),
        // Output
        .mem_rdata_out  (mem_mem_rdata)  
    );

    // ---------------- Pipeline Reg: MEM/WB ----------------
    mem2wb #(
        .AW (AW),
        .DW (DW)
    ) u_mem2wb (
        .clk            (clk),
        .rst_n          (rst_n),
        // Inputs
        .pc_in          (mem_pc),
        .alu_result_in  (mem_alu_result),
        .mem_rdata_in   (mem_mem_rdata),
        .rd_addr_in     (mem_rd_addr),
        .opcode_in      (mem_opcode),
        // Outputs
        .pc_out         (wb_pc),
        .alu_result_out (wb_alu_result),
        .mem_rdata_out  (wb_mem_rdata),
        .rd_addr_out    (wb_rd_addr),
        .opcode_out     (wb_opcode)
    );

    // ---------------- Stage 5: Writeback (WB) ----------------
    // 7. 写回选择逻辑
    writeback #(
        .DW (DW)
    ) u_writeback (
        .alu_result_in (wb_alu_result),
        .mem_rdata_in  (wb_mem_rdata),
        .opcode_in     (wb_opcode),
        .rd_addr_in    (wb_rd_addr),
        // Outputs -> 回连到 Register File
        .wb_en         (wb_wr_en),
        .wb_addr       (wb_wr_addr),
        .wb_data       (wb_wr_data)
    );

endmodule