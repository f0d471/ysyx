`include "define.sv"

module memory #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n,

    // 来自 EX/MEM 流水线寄存器
    input  logic          valid_in,
    input  logic [DW-1:0] alu_result_in,
    input  logic [DW-1:0] rs2_data_in,
    input  logic          is_load_in,
    input  logic          is_store_in,
    input  logic [2:0]    funct3_in,

    // SimpleBus 数据通道（保持不变）
    output logic [AW-1:0] lsu_addr,
    output logic          lsu_ren,
    output logic          lsu_wen,
    output logic [DW-1:0] lsu_wdata,
    output logic [3:0]    lsu_wmask,
    output logic          lsu_reqValid,
    input  logic          lsu_reqReady,
    input  logic          lsu_respValid,
    output logic          lsu_respReady,
    input  logic [DW-1:0] lsu_rdata,

    // 流水线控制
    output logic          lsu_busy,
    output logic [DW-1:0] mem_rdata_out
);

    // =============================================================
    //  指令类型
    // =============================================================
    wire is_load  = valid_in && is_load_in;
    wire is_store = valid_in && is_store_in;
    wire is_mem   = is_load || is_store;

    // =============================================================
    //  状态机
    //    S_IDLE:      无访存 / 等待发请求
    //    S_WAIT_RESP: 请求已发出，等 respValid
    //    S_DONE:      访存完成，1 周期后回 IDLE
    // =============================================================
    typedef enum logic [1:0] {
        S_IDLE      = 2'b00,
        S_WAIT_RESP = 2'b01,
        S_DONE      = 2'b10
    } state_t;

    state_t state, state_next;
    logic [DW-1:0] rdata_latch;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            state <= S_IDLE;
        else
            state <= state_next;
    end

    always_comb begin
        state_next = state;
        case (state)
            S_IDLE: begin
                if (is_mem && lsu_reqValid && lsu_reqReady)
                    state_next = S_WAIT_RESP;
            end
            S_WAIT_RESP: begin
                if (lsu_respValid && lsu_respReady)
                    state_next = S_DONE;
            end
            S_DONE: begin
                state_next = S_IDLE;
            end
            default: state_next = S_IDLE;
        endcase
    end

    // 锁存读数据
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            rdata_latch <= 32'h0;
        else if (state == S_WAIT_RESP && lsu_respValid && lsu_respReady)
            rdata_latch <= lsu_rdata;
    end

    // =============================================================
    //  写掩码生成
    // =============================================================
    logic [3:0] wmask_gen;
    always_comb begin
        wmask_gen = 4'b0000;
        if (is_store) begin
            case (funct3_in)
                `INST_SB: begin
                    case (alu_result_in[1:0])
                        2'b00: wmask_gen = 4'b0001;
                        2'b01: wmask_gen = 4'b0010;
                        2'b10: wmask_gen = 4'b0100;
                        2'b11: wmask_gen = 4'b1000;
                    endcase
                end
                `INST_SH:  wmask_gen = alu_result_in[1] ? 4'b1100 : 4'b0011;
                default:   wmask_gen = 4'b1111;  // SW
            endcase
        end
    end

    // =============================================================
    //  总线输出
    // =============================================================
    assign lsu_addr      = alu_result_in;
    assign lsu_ren       = is_load;
    assign lsu_wen       = is_store;
    // 写数据按 addr[1:0] 移位到正确的字节 lane（真实硬件约定）
    assign lsu_wdata     = rs2_data_in << (8 * alu_result_in[1:0]);
    assign lsu_wmask     = wmask_gen;
    assign lsu_reqValid  = is_mem && (state == S_IDLE);
    assign lsu_respReady = (state == S_WAIT_RESP);

    // =============================================================
    //  Busy：有访存操作且尚未到 DONE
    // =============================================================
    assign lsu_busy = is_mem && (state != S_DONE);

    // =============================================================
    //  读数据符号扩展（DONE 状态输出）
    // =============================================================
    always_comb begin
        mem_rdata_out = 32'h0;
        if (is_load && state == S_DONE) begin
            case (funct3_in)
                `INST_LB:  case (alu_result_in[1:0])
                    2'b00: mem_rdata_out = {{24{rdata_latch[7]}},  rdata_latch[7:0]};
                    2'b01: mem_rdata_out = {{24{rdata_latch[15]}}, rdata_latch[15:8]};
                    2'b10: mem_rdata_out = {{24{rdata_latch[23]}}, rdata_latch[23:16]};
                    2'b11: mem_rdata_out = {{24{rdata_latch[31]}}, rdata_latch[31:24]};
                endcase
                `INST_LBU: case (alu_result_in[1:0])
                    2'b00: mem_rdata_out = {24'b0, rdata_latch[7:0]};
                    2'b01: mem_rdata_out = {24'b0, rdata_latch[15:8]};
                    2'b10: mem_rdata_out = {24'b0, rdata_latch[23:16]};
                    2'b11: mem_rdata_out = {24'b0, rdata_latch[31:24]};
                endcase
                `INST_LH:  mem_rdata_out = alu_result_in[1]
                    ? {{16{rdata_latch[31]}}, rdata_latch[31:16]}
                    : {{16{rdata_latch[15]}}, rdata_latch[15:0]};
                `INST_LHU: mem_rdata_out = alu_result_in[1]
                    ? {16'b0, rdata_latch[31:16]}
                    : {16'b0, rdata_latch[15:0]};
                `INST_LW:  mem_rdata_out = rdata_latch;
                default:   mem_rdata_out = 32'h0;
            endcase
        end
    end

endmodule