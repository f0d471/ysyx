`include "define.sv"
// ===================================================================
//  mem.sv — MEM 级访存模块（SimpleBus 协议）
//
//  Bug 修复说明（相比旧版）：
//    旧版 lsu_reqValid = is_memop && (state == S_IDLE)
//    问题：当 lsu_respValid=1 时，state 在本周期末才更新为 S_IDLE，
//    而 is_memop 仍为 1（EX/MEM 寄存器因 lsu_busy 还没放行），
//    所以下一个周期 state=S_IDLE 且 is_memop=1，lsu_reqValid=1，
//    SRAM 被重复触发，导致对同一地址发出两次访存请求。
//
//    修复方法：引入 req_sent 寄存器，记录"本次访存请求已发出"。
//    一旦发出请求，req_sent 置 1；收到 respValid 后清 0。
//    lsu_reqValid 只在 !req_sent 时才允许发出。
// ===================================================================
module memory #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n,

    // --- 来自 EX/MEM 流水线寄存器 ---
    input  logic          valid_in,
    input  logic [DW-1:0] alu_result_in,
    input  logic [DW-1:0] rs2_data_in,
    input  logic [6:0]    opcode_in,
    input  logic [2:0]    funct3_in,

    // --- SimpleBus 接口 ---
    output logic [AW-1:0] lsu_addr,
    output logic          lsu_ren,
    input  logic [DW-1:0] lsu_rdata,
    output logic          lsu_wen,
    output logic [DW-1:0] lsu_wdata,
    output logic [3:0]    lsu_wmask,
    output logic          lsu_reqValid,
    input  logic          lsu_respValid,

    // --- 流水线控制 ---
    output logic          lsu_busy,
    output logic [DW-1:0] mem_rdata_out
);

    // =============================================================
    //  指令类型判断
    // =============================================================
    wire is_load  = valid_in && (opcode_in == `INST_TYPE_L);
    wire is_store = valid_in && (opcode_in == `INST_TYPE_S);
    wire is_memop = is_load || is_store;

    // =============================================================
    //  状态机
    // =============================================================
    localparam S_IDLE      = 1'b0;
    localparam S_WAIT_RESP = 1'b1;

    logic state, state_next;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) state <= S_IDLE;
        else        state <= state_next;
    end

    always_comb begin
        case (state)
            S_IDLE:      state_next = is_memop      ? S_WAIT_RESP : S_IDLE;
            S_WAIT_RESP: state_next = lsu_respValid ? S_IDLE      : S_WAIT_RESP;
            default:     state_next = S_IDLE;
        endcase
    end

    // =============================================================
    //  ★ 修复 Bug2：req_sent 防重复请求寄存器
    // =============================================================
    logic req_sent;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            req_sent <= 1'b0;
        else if (lsu_respValid)
            req_sent <= 1'b0;                          // 响应到达，清除标记
        else if (is_memop && state == S_IDLE && !req_sent)
            req_sent <= 1'b1;                          // 发出请求，置位标记
    end

    // =============================================================
    //  控制信号
    // =============================================================

    // ★ 修复：只有在 S_IDLE 且未发过请求时才拉高 reqValid
    assign lsu_reqValid = is_memop && (state == S_IDLE) && !req_sent;

    // busy：从发出请求到收到响应的整个过程
    assign lsu_busy = (is_memop && state == S_IDLE && !req_sent) ||
                      (state == S_WAIT_RESP && !lsu_respValid);

    // =============================================================
    //  SimpleBus 输出信号
    // =============================================================
    assign lsu_addr  = alu_result_in;
    assign lsu_ren   = is_load;
    assign lsu_wen   = is_store;
    assign lsu_wdata = rs2_data_in;

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
                `INST_SH: lsu_wmask = alu_result_in[1] ? 4'b1100 : 4'b0011;
                default:  lsu_wmask = 4'b1111;
            endcase
        end else begin
            lsu_wmask = 4'b0000;
        end
    end

    // =============================================================
    //  读数据处理（符号扩展）
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
