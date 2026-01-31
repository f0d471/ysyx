`include "define.sv"

module fetch #(
    parameter   AW = 32, // 地址位宽
    parameter   DW = 32  // 数据位宽 (指令长度为32位)
)( 
    input  logic          clk,        // 时钟
    input  logic          rst_n,      // 低电平复位
    input  logic [AW-1:0] pc_addr,    // 也就是原来的 instr_addr，即当前 PC 值
    output logic [DW-1:0] instr_out   // 取到的 32 位指令
);  

always_ff @(posedge clk) begin
    if (!rst_n) begin
        instr_out <= 32'h00000013;
    end else begin
        instr_out <= paddr_read(pc_addr);
    end
end


endmodule