`include "define.sv"

module register #(
    parameter DW = 32
)(
    input  wire        clk,
    input  wire        rst_n,      

    // 读端口 
    input  wire [4:0]  rs1_addr,   
    input  wire [4:0]  rs2_addr,  
    output wire [31:0] rs1_data,   
    output wire [31:0] rs2_data,  

    // 写端口 
    input  wire        wr_en,     
    input  wire [4:0]  wr_addr,    
    input  wire [31:0] wr_data   
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

endmodule
