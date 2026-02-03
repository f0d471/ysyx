`include "define.sv" 

module if2id #(
    parameter AW = `AW, 
    parameter DW = `DW
)( 
    // // from ex
    // input  logic          if_stall,  // 暂停
    // input  logic          if_flush,  // 清空
    // from if
    input  logic [AW-1:0] instr_addr_in, 
    input  logic [DW-1:0] instr_in,
    // to id    
    output logic [AW-1:0] instr_addr_out, 
    output logic [DW-1:0] instr_out       
);  

always_comb  begin
    // if (!rst_n) begin
    //     instr_addr_out = 'h0;
    //     instr_out      = `INST_NOP; 
    // end 
    // else if (if_flush) begin
    //     instr_addr_out <= 'h0;
    //     instr_out      <= `INST_NOP; // 清空时插入气泡
    // end 
    // else if (if_stall) begin
    //     instr_addr_out <= instr_addr_out;
    //     instr_out      <= instr_out;
    // end 
    // else begin
        instr_addr_out = instr_addr_in;
        instr_out      = instr_in;
    // end
end
    
endmodule