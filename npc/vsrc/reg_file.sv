`include "define.sv"

module reg_file #(
    parameter DW = 32
)(
    input  logic        clk,
    input  logic        rst_n,      
    // 读端口 
    input  logic [4:0]  rs1_addr,   
    input  logic [4:0]  rs2_addr,  
    output logic [31:0] rs1_data,   
    output logic [31:0] rs2_data,  
    // 写端口 
    input  logic        wr_en,     
    input  logic [4:0]  wr_addr,    
    input  logic [31:0] wr_data,
    //for test
    output logic [DW-1:0] debug_x10,
    output logic [DW-1:0] regs [15:0]   
);

    reg [DW-1:0] rf [15:0];

    // 写
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int i = 0; i < 16; i = i + 1) begin
                rf[i] <= 32'b0;
            end
        end
        else if (wr_en && (wr_addr != 5'b0) && (wr_addr < 5'd16)) begin
            rf[wr_addr[3:0]] <= wr_data; 
        end
    end

    // 读
    assign rs1_data = ((rs1_addr == 5'd0) || (rs1_addr >= 5'd16)) ? 32'b0 : rf[rs1_addr[3:0]];
    assign rs2_data = ((rs2_addr == 5'd0) || (rs2_addr >= 5'd16)) ? 32'b0 : rf[rs2_addr[3:0]];
    assign debug_x10 = rf[10];

      genvar i;
    generate
      for (i = 0; i < 16; i = i + 1) begin
        assign regs[i] = rf[i];
      end
    endgenerate

endmodule
