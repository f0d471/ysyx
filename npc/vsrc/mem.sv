`include "define.sv"

module memory #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n, 

    // 来自 EX/MEM
    input  logic [DW-1:0] alu_result_in, // 访存地址
    input  logic [DW-1:0] rs2_data_in, 
    input  logic [6:0]    opcode_in,
    input  logic [2:0]    funct3_in,

    // 输出到 WB
    output logic [DW-1:0] mem_rdata_out 
);

    logic [DW-1:0] rdata_raw;

    always_comb begin
        rdata_raw = 32'h0;
        mem_rdata_out = 32'h0;

        if (opcode_in == `INST_TYPE_L) begin
            rdata_raw = paddr_read(alu_result_in);

            case(funct3_in)
                `INST_LB:  mem_rdata_out = {{24{rdata_raw[7]}}, rdata_raw[7:0]};
                `INST_LBU: mem_rdata_out = {24'b0, rdata_raw[7:0]};
                `INST_LH:  mem_rdata_out = {{16{rdata_raw[15]}}, rdata_raw[15:0]};
                `INST_LHU: mem_rdata_out = {16'b0, rdata_raw[15:0]};
                `INST_LW:  mem_rdata_out = rdata_raw;
                default:   mem_rdata_out = 32'h0;
            endcase
        end
    end

    always_ff @(posedge clk) begin
        if (opcode_in == `INST_TYPE_S) begin
            case(funct3_in)
                `INST_SB: paddr_write(alu_result_in, 1, rs2_data_in);
                `INST_SH: paddr_write(alu_result_in, 2, rs2_data_in);
                `INST_SW: paddr_write(alu_result_in, 4, rs2_data_in);
                default:  paddr_write(alu_result_in, 4, rs2_data_in);
            endcase
        end
    end

endmodule