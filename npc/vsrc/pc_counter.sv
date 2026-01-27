module pc_counter #(
    parameter   AW       = 32,
    parameter   RESET_PC = 32'h80000000 
)( 
    input  logic          clk,
    input  logic          rst_n,      
    input  logic          jump_en,
    input  logic [AW-1:0] jump_addr,
    output logic [AW-1:0] pc_pointer          
);  

always_ff @(posedge clk or negedge rst_n) begin
    if(!rst_n)
        pc_pointer <= RESET_PC;   // 复位时，PC 指向 0x80000000
    else if(jump_en)
        pc_pointer <= jump_addr;  // 跳转
    else
        pc_pointer <= pc_pointer + 'h4; // 顺序执行，+4字节
end

endmodule