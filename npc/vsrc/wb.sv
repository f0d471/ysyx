`include "define.v"

module writeback #(
    parameter DW = 32
)(
    // Inputs from MEM/WB
    input  logic [DW-1:0] alu_result_in,
    input  logic [DW-1:0] mem_rdata_in,
    input  logic [6:0]    opcode_in,
    input  logic [4:0]    rd_addr_in,

    // Outputs to Register File
    output logic          wb_en,
    output logic [4:0]    wb_addr,
    output logic [DW-1:0] wb_data
);

    assign wb_addr = rd_addr_in;

    always_comb begin
        // 默认不写
        wb_en   = 1'b0;
        wb_data = 32'h0;

        case(opcode_in)
            `INST_TYPE_L: begin // Load: 写回内存数据
                wb_en   = 1'b1;
                wb_data = mem_rdata_in;
            end
            `INST_TYPE_I, `INST_TYPE_R_M, `INST_TYPE_U_LUI, `INST_TYPE_U_AUIPC, `INST_TYPE_J, `INST_TYPE_JALR: begin
                // ALU 运算 / JAL / JALR (Link PC) / LUI / AUIPC: 写回 ALU 结果
                wb_en   = 1'b1;
                wb_data = alu_result_in;
            end
            // Store / Branch 不写回
            default: begin
                wb_en = 1'b0;
            end
        endcase
    end

endmodule