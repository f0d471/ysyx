`include "define.sv"

// DPI-C 接口定义
// 修正：paddr_read 只接受地址，总是返回 4 字节
import "DPI-C" function int paddr_read(input int addr);
import "DPI-C" function void paddr_write(input int addr, input int len, input int data);

module memory #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n, 

    // 来自 EX/MEM
    input  logic [DW-1:0] alu_result_in, // 访存地址
    input  logic [DW-1:0] rs2_data_in,   // 写数据
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
            // 1. 调用 DPI-C 读取原始数据 
            // 修正：不传 len，硬件总是读回 32 位，由 Verilog 进行字节选择和扩展
            rdata_raw = paddr_read(alu_result_in);

            // 2. 根据指令进行符号扩展 (Sign Extension)
            // 注意：这里假设 paddr_read 返回的数据是 Little Endian，即 addr 指向的字节在 [7:0]
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
    // 2. Write Logic
    // -----------------------------------------------------
    // 写操作依然需要 len，C 侧 paddr_write 定义保留了 len 参数
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