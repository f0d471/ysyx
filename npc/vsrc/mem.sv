`include "define.sv"

module memory #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n,
 
    // --- 来自 EX/MEM 流水线寄存器 ---
    input  logic          valid_in,        // ★ 新增：MEM 级有有效指令
    input  logic [DW-1:0] alu_result_in,   // 访存地址（rs1 + imm）
    input  logic [DW-1:0] rs2_data_in,     // Store 数据
    input  logic [6:0]    opcode_in,
    input  logic [2:0]    funct3_in,
 
    // --- SimpleBus 接口（连接外部存储器）---
    output logic [AW-1:0] lsu_addr,        // → 存储器地址
    output logic          lsu_ren,         // → 读使能（仅 Load）
    input  logic [DW-1:0] lsu_rdata,       // ← 存储器返回的数据
    output logic          lsu_wen,         // → 写使能
    output logic [DW-1:0] lsu_wdata,       // → 写数据（原始 rs2 值）
    output logic [3:0]    lsu_wmask,       // → 写掩码
    output logic          lsu_reqValid,    // 
    input  logic          lsu_respValid,   // 
 
    // --- 流水线控制 ---
    output logic          lsu_busy,        // → 全流水线 stall
    output logic [DW-1:0] mem_rdata_out    // → MEM/WB 流水线寄存器
);
 
    // =============================================================
    //  指令类型判断
    // =============================================================
    wire is_load  = valid_in && (opcode_in == `INST_TYPE_L);
    wire is_store = valid_in && (opcode_in == `INST_TYPE_S);
    wire is_memop  = is_load || is_store;
 
    // =============================================================
    //  状态机：idle / wait（仅 Load 使用）
    // =============================================================
    localparam S_IDLE = 1'b0;
    localparam S_WAIT_RESP = 1'b1;
 
    logic state, state_next;
 
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            state <= S_IDLE;
        else
            state <= state_next;
    end
 
    always_comb begin
        case (state)
            S_IDLE:      state_next = is_memop ? S_WAIT_RESP : S_IDLE;
            S_WAIT_RESP: state_next = lsu_respValid ? S_IDLE : S_WAIT_RESP;
            default:     state_next = S_IDLE;
        endcase
    end
 
    // =============================================================
    //  控制信号
    // =============================================================
 
    // 请求有效：idle 时且有访存操作
    assign lsu_reqValid = is_memop && (state == S_IDLE);
 
    // busy：从发出请求到收到响应的整个过程
    //   idle 且有访存 → busy（正在发请求）
    //   wait_resp 且没收到 → busy（在等）
    assign lsu_busy = (is_memop && state == S_IDLE) || (state == S_WAIT_RESP && !lsu_respValid);
 
    // =============================================================
    //  SimpleBus 输出信号
    // =============================================================
 
    // 地址：Load 或 Store 时输出计算好的地址
    assign lsu_addr = alu_result_in;
 
    // 读使能：仅 Load 指令
    assign lsu_ren = is_load;

    // 写使能：仅 Store 指令
    assign lsu_wen = is_store;
 
    // 写数据：直接传 rs2（C++ 侧 paddr_write 自行处理字节对齐）
    assign lsu_wdata = rs2_data_in;
 
    // 写掩码：根据 funct3 生成
    always_comb begin
        if (is_store) begin
            case (funct3_in)
                `INST_SB: begin
                    case (alu_result_in[1:0])
                        2'b00: lsu_wmask = 4'b0001;
                        2'b01: lsu_wmask = 4'b0010;
                        2'b10: lsu_wmask = 4'b0100;
                        2'b11: lsu_wmask = 4'b1000;
                    endcase
                end
                `INST_SH: begin
                    lsu_wmask = alu_result_in[1] ? 4'b1100 : 4'b0011;
                end
                default:   lsu_wmask = 4'b1111;  // SW
            endcase
        end else begin
            lsu_wmask = 4'b0000;
        end
    end
 
    // =============================================================
    //  读数据处理（符号扩展）
    //  仅在 WAIT 状态时 lsu_rdata 有效
    // =============================================================
    always_comb begin
        mem_rdata_out = 32'h0;
 
        if (is_load && state == S_WAIT_RESP && lsu_respValid) begin
            case (funct3_in)
                `INST_LB:  mem_rdata_out = {{24{lsu_rdata[7]}},  lsu_rdata[7:0]};
                `INST_LBU: mem_rdata_out = {24'b0,               lsu_rdata[7:0]};
                `INST_LH:  mem_rdata_out = {{16{lsu_rdata[15]}}, lsu_rdata[15:0]};
                `INST_LHU: mem_rdata_out = {16'b0,               lsu_rdata[15:0]};
                `INST_LW:  mem_rdata_out = lsu_rdata;
                default:   mem_rdata_out = 32'h0;
            endcase
        end
    end
 
endmodule
 