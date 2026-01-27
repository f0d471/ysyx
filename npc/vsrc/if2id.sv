`include "define.sv" 

module if2id #(
    parameter AW = `AW, 
    parameter DW = `DW
)( 
    input  logic          clk,
    input  logic          rst_n,
    
    // --- 流水线控制信号 ---
    input  logic          if_stall,  // 暂停
    input  logic          if_flush,  // 清空
    
    // --- 数据输入 (IF -> ID) ---
    input  logic [AW-1:0] instr_addr_in, 
    input  logic [DW-1:0] instr_in,
    
    // --- 数据输出 (IF -> ID) ---
    output logic [AW-1:0] instr_addr_out, 
    output logic [DW-1:0] instr_out       
);  

always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        instr_addr_out <= 'h0;
        instr_out      <= `INST_NOP; // 使用你定义的宏 32'h00000013
    end 
    else if (if_flush) begin
        instr_addr_out <= 'h0;
        instr_out      <= `INST_NOP; // 清空时插入气泡
    end 
    else if (if_stall) begin
        instr_addr_out <= instr_addr_out;
        instr_out      <= instr_out;
    end 
    else begin
        instr_addr_out <= instr_addr_in;
        instr_out      <= instr_in;
    end
end
    
endmodule