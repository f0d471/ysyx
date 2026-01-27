module fetch #(
    parameter   AW = 32, // 地址位宽
    parameter   DW = 32  // 数据位宽 (指令长度为32位)
)( 
    input  logic          clk,        // 时钟
    input  logic          rst_n,      // 低电平复位
    input  logic [AW-1:0] pc_addr,    // 也就是原来的 instr_addr，即当前 PC 值
    output logic [DW-1:0] instr_out   // 取到的 32 位指令
);  

// =========================================================================
// 取指逻辑 (纯组合逻辑)
// =========================================================================
always_comb begin
    if (!rst_n) begin
        // 行为：复位期间，不进行取指，输出空指令 (NOP: addi x0, x0, 0 -> 32'h00000013) 
        // 含义：防止复位期间 PC 为不稳定值（如 X 态）传给 DPI-C 导致 C++ 端内存越界报错
        instr_out = 32'h00000013; 
    end else begin
        // 行为：调用 C++ 端的 paddr_read 函数读取指令
        // 含义：直接从 C++ 维护的 pmem 数组中拿到对应地址的 4 字节数据
        instr_out = paddr_read(pc_addr);
    end
end

endmodule