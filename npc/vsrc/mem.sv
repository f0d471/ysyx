`include "define.v"

// DPI-C 接口定义
import "DPI-C" function int paddr_read(input int addr, input int len);
import "DPI-C" function void paddr_write(input int addr, input int len, input int data);

module memory #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n, // DPI-C 通常是组合逻辑，但 Write 最好在时钟沿或者组合逻辑受控

    // 来自 EX/MEM
    input  logic [DW-1:0] alu_result_in, // 既是 ALU 结果，也是 Memory Address
    input  logic [DW-1:0] rs2_data_in,   // Store Data
    input  logic [6:0]    opcode_in,
    input  logic [2:0]    funct3_in,

    // 输出到 WB
    output logic [DW-1:0] mem_rdata_out  // 从内存读出的数据
);

    logic [DW-1:0] rdata_raw;
    logic is_load, is_store;
    
    assign is_load  = (opcode_in == `INST_TYPE_L);
    assign is_store = (opcode_in == `INST_TYPE_S);

    // -----------------------------------------------------
    // 1. Read Logic (Combinational DPI-C Call)
    // -----------------------------------------------------
    always_comb begin
        rdata_raw = 32'h0;
        mem_rdata_out = 32'h0;

        if (is_load) begin
            // 1. 调用 DPI-C 读取原始数据 (len = 1, 2, 4)
            case(funct3_in)
                `INST_LB, `INST_LBU: rdata_raw = paddr_read(alu_result_in, 1);
                `INST_LH, `INST_LHU: rdata_raw = paddr_read(alu_result_in, 2);
                `INST_LW:            rdata_raw = paddr_read(alu_result_in, 4);
                default:             rdata_raw = 32'h0;
            endcase

            // 2. 根据指令进行符号扩展 (Sign Extension)
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

    // -----------------------------------------------------
    // 2. Write Logic (Combination or Clocked?)
    // -----------------------------------------------------
    // 注意：paddr_write 是副作用函数。为了安全，通常建议在组合逻辑中只在使能时调用，
    // 或者在时钟上升沿调用。这里为了配合单周期/简单流水线行为，我们在组合逻辑里做，
    // 但必须确保 is_store 信号极其稳定。在严谨的 Verilog 仿真中，DPI-C 写通常放在 always_ff。
    
    // 方案：使用 always @(*) 配合 valid 信号，模拟组合逻辑写。
    // 实际上 NEMU 的 DPI-C 接口是即时的。
    always_comb begin
        if (is_store) begin
            case(funct3_in)
                `INST_SB: paddr_write(alu_result_in, 1, rs2_data_in);
                `INST_SH: paddr_write(alu_result_in, 2, rs2_data_in);
                `INST_SW: paddr_write(alu_result_in, 4, rs2_data_in);
                default:  paddr_write(alu_result_in, 4, rs2_data_in);
            endcase
        end
    end

endmodule