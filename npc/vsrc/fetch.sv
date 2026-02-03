`include "define.sv"

module fetch #(
    parameter   AW = 32, // 地址位宽
    parameter   DW = 32  // 数据位宽 
)( 
    input  logic          clk,        
    input  logic          rst_n,    
      
    input  logic [AW-1:0] pc_pointer, // 当前PC值

    output logic [DW-1:0] instr_out // 取到的指令
);  

always_comb begin
    if (!rst_n) begin
        instr_out  = 32'h00000013;
    end else begin
        instr_out  = paddr_read(pc_pointer);
    end
end

endmodule