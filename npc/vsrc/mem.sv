`include "define.sv"
`include "axi4.sv"

module memory #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n,

    input  logic          valid_in,
    input  logic [DW-1:0] alu_result_in,
    input  logic [DW-1:0] rs2_data_in,
    input  logic          is_load_in,
    input  logic          is_store_in,
    input  logic [2:0]    funct3_in,

    // AXI4 AR 通道 (读地址 — load 用)
    output logic          lsu_arvalid,
    input  logic          lsu_arready,
    output logic [AW-1:0] lsu_araddr,
    output logic [2:0]    lsu_arsize,
    output logic [7:0]    lsu_arlen,
    output logic [1:0]    lsu_arburst,
    output logic [3:0]    lsu_arid,

    // AXI4 R 通道 (读数据 — load 用)
    input  logic          lsu_rvalid,
    output logic          lsu_rready,
    input  logic [DW-1:0] lsu_rdata,
    input  logic [1:0]    lsu_rresp,
    input  logic          lsu_rlast,

    // AXI4 AW 通道 (写地址 — store 用)
    output logic          lsu_awvalid,
    input  logic          lsu_awready,
    output logic [AW-1:0] lsu_awaddr,
    output logic [2:0]    lsu_awsize,
    output logic [7:0]    lsu_awlen,
    output logic [1:0]    lsu_awburst,
    output logic [3:0]    lsu_awid,

    // AXI4 W 通道 (写数据 — store 用)
    output logic          lsu_wvalid,
    input  logic          lsu_wready,
    output logic [DW-1:0] lsu_wdata,
    output logic [3:0]    lsu_wstrb,
    output logic          lsu_wlast,

    // AXI4 B 通道 (写回复 — store 用)
    input  logic          lsu_bvalid,
    output logic          lsu_bready,
    input  logic [1:0]    lsu_bresp,
    input  logic [3:0]    lsu_bid,

    output logic          lsu_busy,
    output logic          lsu_error,

    output logic [DW-1:0] mem_rdata_out
);

    wire is_load  = valid_in && is_load_in;
    wire is_store = valid_in && is_store_in;
    wire is_mem   = is_load || is_store;

    // --- Load 状态机 (AR + R) ---
    typedef enum logic [1:0] {
        LD_IDLE = 2'd0,
        LD_WAIT = 2'd1,
        LD_DONE = 2'd2
    } ld_state_t;

    ld_state_t ld_state, ld_state_next;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            ld_state <= LD_IDLE;
        else
            ld_state <= ld_state_next;
    end

    always_comb begin
        ld_state_next = ld_state;
        case (ld_state)
            LD_IDLE: begin
                if (is_load && lsu_arvalid && lsu_arready)
                    ld_state_next = LD_WAIT;
            end
            LD_WAIT: begin
                if (lsu_rvalid && lsu_rready)
                    ld_state_next = LD_DONE;
            end
            LD_DONE: begin
                ld_state_next = LD_IDLE;
            end
            default: ld_state_next = LD_IDLE;
        endcase
    end

    // --- Store 状态机 (AW + W + B) ---
    typedef enum logic [1:0] {
        ST_IDLE = 2'd0,
        ST_WAIT = 2'd1,
        ST_DONE = 2'd2
    } st_state_t;

    st_state_t st_state, st_state_next;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            st_state <= ST_IDLE;
        else
            st_state <= st_state_next;
    end

    always_comb begin
        st_state_next = st_state;
        case (st_state)
            ST_IDLE: begin
                if (is_store && lsu_awvalid && lsu_awready && lsu_wvalid && lsu_wready)
                    st_state_next = ST_WAIT;
            end
            ST_WAIT: begin
                if (lsu_bvalid && lsu_bready)
                    st_state_next = ST_DONE;
            end
            ST_DONE: begin
                st_state_next = ST_IDLE;
            end
            default: st_state_next = ST_IDLE;
        endcase
    end

    // --- Load 数据锁存 ---
    logic [DW-1:0] rdata_latch;
    logic [1:0]    resp_latch;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rdata_latch <= 32'h0;
            resp_latch  <= 2'b00;
        end else if (ld_state == LD_WAIT && lsu_rvalid && lsu_rready) begin
            rdata_latch <= lsu_rdata;
            resp_latch  <= lsu_rresp;
        end
    end

    // --- 写掩码生成 ---
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
                default:   wmask_gen = 4'b1111;
            endcase
        end
    end

    // --- AXI4 AR 通道输出 (load) ---
    assign lsu_arvalid = is_load && (ld_state == LD_IDLE);
    assign lsu_araddr  = alu_result_in;
    assign lsu_arsize  = `AXI4_SIZE_4B;
    assign lsu_arlen   = 8'h0;
    assign lsu_arburst = `AXI4_BURST_INCR;
    assign lsu_arid    = 4'h0;

    // --- AXI4 R 通道输出 (load) ---
    assign lsu_rready = (ld_state == LD_WAIT);

    // --- AXI4 AW 通道输出 (store) ---
    assign lsu_awvalid = is_store && (st_state == ST_IDLE);
    assign lsu_awaddr  = alu_result_in;
    assign lsu_awsize  = `AXI4_SIZE_4B;
    assign lsu_awlen   = 8'h0;
    assign lsu_awburst = `AXI4_BURST_INCR;
    assign lsu_awid    = 4'h0;

    // --- AXI4 W 通道输出 (store) ---
    assign lsu_wvalid = is_store && (st_state == ST_IDLE);
    assign lsu_wdata  = rs2_data_in << (8 * alu_result_in[1:0]);
    assign lsu_wstrb  = wmask_gen;
    assign lsu_wlast  = 1'b1;

    // --- AXI4 B 通道输出 (store) ---
    assign lsu_bready = (st_state == ST_WAIT);

    // --- 流水线控制 ---
    assign lsu_busy = (is_load && ld_state != LD_DONE) ||
                      (is_store && st_state != ST_DONE);

    assign lsu_error = (is_load && ld_state == LD_DONE && resp_latch != `AXI4_RESP_OKAY) ||
                       (is_store && st_state == ST_DONE && lsu_bresp != `AXI4_RESP_OKAY);

    // --- 读数据符号扩展 ---
    always_comb begin
        mem_rdata_out = 32'h0;
        if (is_load && ld_state == LD_DONE) begin
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
