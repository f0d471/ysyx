`include "define.sv"

module pc_counter #(
    parameter   AW       = 32,
    parameter   RESET_PC = 32'h80000000 
)( 
    input  logic          clk,
    input  logic          rst_n,
    
    // input  logic          pc_stall,  
    input  logic          jump_en,
    input  logic [AW-1:0] jump_addr,
    output logic [AW-1:0] pc      
);  

  logic [31:0] pc_pointer = 32'h80000000;
  assign pc = pc_pointer;

  always_ff @(posedge clk or negedge rst_n) begin
      if(!rst_n)
          pc_pointer <= RESET_PC;
      // else if(pc_stall)             // <--- 优先级处理：暂停时保持原值
      //     pc_pointer <= pc_pointer; // 保持当前 PC 不变
      else if(jump_en)
          pc_pointer <= jump_addr;
      else
          pc_pointer <= pc_pointer + 'h4;
          //$display("[%0t] PC : 0x%h", $time, pc_pointer);
  end

  


endmodule