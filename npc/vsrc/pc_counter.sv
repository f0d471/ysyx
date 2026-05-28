`include "define.sv"

module pc_counter #(
    parameter AW       = 32,
    parameter RESET_PC = 32'h80000000
)(
    input  logic          clk,
    input  logic          rst_n,
 
    input  logic          jump_en,        // 跳转使能（ex_jump_flag）
    input  logic [AW-1:0] jump_addr,      // 跳转目标（ex_jump_target）
    input  logic          pc_hold,        // PC 保持不变
 
    output logic [AW-1:0] pc
);
 
    logic [AW-1:0] pc_pointer;
    assign pc = pc_pointer;
 
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            pc_pointer <= RESET_PC;
        else if (jump_en)               
            pc_pointer <= jump_addr;
        else if (pc_hold)               // 保持（IFU 忙/stall）
            pc_pointer <= pc_pointer;
        else                            
            pc_pointer <= pc_pointer + 32'h4;
    end
 
endmodule