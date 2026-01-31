`include "define.sv"

module pc_counter #(
    parameter   AW       = 32,
    parameter   RESET_PC = 32'h80000000 
)( 
    input  logic          clk,
    input  logic          rst_n,
    
    input  logic          pc_stall,  
    input  logic          jump_en,
    input  logic [AW-1:0] jump_addr,
    output logic [AW-1:0] pc_pointer      
);  

always_ff @(posedge clk or negedge rst_n) begin
    if(!rst_n)
        pc_pointer <= RESET_PC;
    else if(pc_stall)             // <--- 优先级处理：暂停时保持原值
        pc_pointer <= pc_pointer; // 保持当前 PC 不变
    else if(jump_en)
        pc_pointer <= jump_addr;
    else
        pc_pointer <= pc_pointer + 'h4;
                $display("PC updated! New PC address = 0x%08h", pc_pointer);

end

endmodule