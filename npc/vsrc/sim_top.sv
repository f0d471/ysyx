`include "define.sv"
`include "axi4.sv"

import "DPI-C" function int  paddr_read (input int addr);
import "DPI-C" function void paddr_write(input int addr, input int wmask, input int data);

module top (
    input  logic        clk,
    input  logic        rst_n,

    output logic [31:0] debug_regs [15:0],

    output logic        debug_have,
    output logic [31:0] debug_pc,
    output logic [31:0] debug_instr,
    output logic        debug_en,
    output logic [4:0]  debug_addr,
    output logic [31:0] debug_data
);

    // ================================================================
    //  AXI4 Master 信号 (arbiter 输出 → Slave 存储器模型)
    // ================================================================
    logic        m_arvalid, m_arready;
    logic [31:0] m_araddr;
    logic [3:0]  m_arid;
    logic [7:0]  m_arlen;
    logic [2:0]  m_arsize;
    logic [1:0]  m_arburst;

    logic        m_rvalid, m_rready;
    logic [31:0] m_rdata;
    logic [1:0]  m_rresp;
    logic [3:0]  m_rid;
    logic        m_rlast;

    logic        m_awvalid, m_awready;
    logic [31:0] m_awaddr;
    logic [3:0]  m_awid;
    logic [7:0]  m_awlen;
    logic [2:0]  m_awsize;
    logic [1:0]  m_awburst;

    logic        m_wvalid, m_wready;
    logic [31:0] m_wdata;
    logic [3:0]  m_wstrb;
    logic        m_wlast;

    logic        m_bvalid, m_bready;
    logic [1:0]  m_bresp;
    logic [3:0]  m_bid;

    // ================================================================
    //  Core AXI4 信号
    // ================================================================
    // IFU AR/R
    logic        ifu_arvalid, ifu_arready;
    logic [31:0] ifu_araddr;
    logic [2:0]  ifu_arsize;
    logic [7:0]  ifu_arlen;
    logic [1:0]  ifu_arburst;
    logic [3:0]  ifu_arid;

    logic        ifu_rvalid, ifu_rready;
    logic [31:0] ifu_rdata;
    logic [1:0]  ifu_rresp;
    logic        ifu_rlast;

    // LSU AR/R
    logic        lsu_arvalid, lsu_arready;
    logic [31:0] lsu_araddr;
    logic [2:0]  lsu_arsize;
    logic [7:0]  lsu_arlen;
    logic [1:0]  lsu_arburst;
    logic [3:0]  lsu_arid;

    logic        lsu_rvalid, lsu_rready;
    logic [31:0] lsu_rdata;
    logic [1:0]  lsu_rresp;
    logic        lsu_rlast;

    // LSU AW/W/B
    logic        lsu_awvalid, lsu_awready;
    logic [31:0] lsu_awaddr;
    logic [2:0]  lsu_awsize;
    logic [7:0]  lsu_awlen;
    logic [1:0]  lsu_awburst;
    logic [3:0]  lsu_awid;

    logic        lsu_wvalid, lsu_wready;
    logic [31:0] lsu_wdata;
    logic [3:0]  lsu_wstrb;
    logic        lsu_wlast;

    logic        lsu_bvalid, lsu_bready;
    logic [1:0]  lsu_bresp;
    logic [3:0]  lsu_bid;

    // ================================================================
    //  Core
    // ================================================================
    core u_core (
        .clk            (clk),
        .rst_n          (rst_n),

        .debug_regs     (debug_regs),

        // IFU AXI4 AR
        .ifu_arvalid    (ifu_arvalid),
        .ifu_arready    (ifu_arready),
        .ifu_araddr     (ifu_araddr),
        .ifu_arsize     (ifu_arsize),
        .ifu_arlen      (ifu_arlen),
        .ifu_arburst    (ifu_arburst),
        .ifu_arid       (ifu_arid),
        // IFU AXI4 R
        .ifu_rvalid     (ifu_rvalid),
        .ifu_rready     (ifu_rready),
        .ifu_rdata      (ifu_rdata),
        .ifu_rresp      (ifu_rresp),
        .ifu_rlast      (ifu_rlast),

        // LSU AXI4 AR
        .lsu_arvalid    (lsu_arvalid),
        .lsu_arready    (lsu_arready),
        .lsu_araddr     (lsu_araddr),
        .lsu_arsize     (lsu_arsize),
        .lsu_arlen      (lsu_arlen),
        .lsu_arburst    (lsu_arburst),
        .lsu_arid       (lsu_arid),
        // LSU AXI4 R
        .lsu_rvalid     (lsu_rvalid),
        .lsu_rready     (lsu_rready),
        .lsu_rdata      (lsu_rdata),
        .lsu_rresp      (lsu_rresp),
        .lsu_rlast      (lsu_rlast),
        // LSU AXI4 AW
        .lsu_awvalid    (lsu_awvalid),
        .lsu_awready    (lsu_awready),
        .lsu_awaddr     (lsu_awaddr),
        .lsu_awsize     (lsu_awsize),
        .lsu_awlen      (lsu_awlen),
        .lsu_awburst    (lsu_awburst),
        .lsu_awid       (lsu_awid),
        // LSU AXI4 W
        .lsu_wvalid     (lsu_wvalid),
        .lsu_wready     (lsu_wready),
        .lsu_wdata      (lsu_wdata),
        .lsu_wstrb      (lsu_wstrb),
        .lsu_wlast      (lsu_wlast),
        // LSU AXI4 B
        .lsu_bvalid     (lsu_bvalid),
        .lsu_bready     (lsu_bready),
        .lsu_bresp      (lsu_bresp),
        .lsu_bid        (lsu_bid),

        .debug_have     (debug_have),
        .debug_pc       (debug_pc),
        .debug_instr    (debug_instr),
        .debug_en       (debug_en),
        .debug_addr     (debug_addr),
        .debug_data     (debug_data)
    );

    // ================================================================
    //  Arbiter (合并 IFU + LSU → 单 AXI4 Master)
    // ================================================================
    axi_arbiter u_arbiter (
        .clk       (clk),
        .rst_n     (rst_n),

        // IFU
        .ifu_arvalid  (ifu_arvalid),
        .ifu_arready  (ifu_arready),
        .ifu_araddr   (ifu_araddr),
        .ifu_arsize   (ifu_arsize),
        .ifu_arlen    (ifu_arlen),
        .ifu_arburst  (ifu_arburst),
        .ifu_arid     (ifu_arid),
        .ifu_rvalid   (ifu_rvalid),
        .ifu_rready   (ifu_rready),
        .ifu_rdata    (ifu_rdata),
        .ifu_rresp    (ifu_rresp),
        .ifu_rlast    (ifu_rlast),

        // LSU AR/R
        .lsu_arvalid  (lsu_arvalid),
        .lsu_arready  (lsu_arready),
        .lsu_araddr   (lsu_araddr),
        .lsu_arsize   (lsu_arsize),
        .lsu_arlen    (lsu_arlen),
        .lsu_arburst  (lsu_arburst),
        .lsu_arid     (lsu_arid),
        .lsu_rvalid   (lsu_rvalid),
        .lsu_rready   (lsu_rready),
        .lsu_rdata    (lsu_rdata),
        .lsu_rresp    (lsu_rresp),
        .lsu_rlast    (lsu_rlast),
        // LSU AW/W/B
        .lsu_awvalid  (lsu_awvalid),
        .lsu_awready  (lsu_awready),
        .lsu_awaddr   (lsu_awaddr),
        .lsu_awsize   (lsu_awsize),
        .lsu_awlen    (lsu_awlen),
        .lsu_awburst  (lsu_awburst),
        .lsu_awid     (lsu_awid),
        .lsu_wvalid   (lsu_wvalid),
        .lsu_wready   (lsu_wready),
        .lsu_wdata    (lsu_wdata),
        .lsu_wstrb    (lsu_wstrb),
        .lsu_wlast    (lsu_wlast),
        .lsu_bvalid   (lsu_bvalid),
        .lsu_bready   (lsu_bready),
        .lsu_bresp    (lsu_bresp),
        .lsu_bid      (lsu_bid),

        // AXI4 Master → Slave
        .m_arvalid   (m_arvalid),
        .m_arready   (m_arready),
        .m_araddr    (m_araddr),
        .m_arid      (m_arid),
        .m_arlen     (m_arlen),
        .m_arsize    (m_arsize),
        .m_arburst   (m_arburst),
        .m_rvalid    (m_rvalid),
        .m_rready    (m_rready),
        .m_rdata     (m_rdata),
        .m_rresp     (m_rresp),
        .m_rid       (m_rid),
        .m_rlast     (m_rlast),
        .m_awvalid   (m_awvalid),
        .m_awready   (m_awready),
        .m_awaddr    (m_awaddr),
        .m_awid      (m_awid),
        .m_awlen     (m_awlen),
        .m_awsize    (m_awsize),
        .m_awburst   (m_awburst),
        .m_wvalid    (m_wvalid),
        .m_wready    (m_wready),
        .m_wdata     (m_wdata),
        .m_wstrb     (m_wstrb),
        .m_wlast     (m_wlast),
        .m_bvalid    (m_bvalid),
        .m_bready    (m_bready),
        .m_bresp     (m_bresp),
        .m_bid       (m_bid)
    );

    // ================================================================
    //  AXI4 Slave 存储器模型
    // ================================================================
    localparam MAX_DELAY = 4;

    logic [7:0] lfsr;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            lfsr <= 8'hA5;
        else
            lfsr <= {lfsr[6:0], lfsr[7] ^ lfsr[5] ^ lfsr[4] ^ lfsr[3]};
    end

    // --- 读通道状态机 ---
    typedef enum logic [1:0] {
        RD_IDLE = 2'd0,
        RD_DELAY = 2'd1,
        RD_RESP = 2'd2
    } rd_state_t;

    rd_state_t rd_state, rd_state_next;
    logic [31:0] rdata_buf;
    logic [1:0]  rresp_buf;
    logic [3:0]  rd_delay_cnt;
    logic [3:0]  rd_delay_target;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            rd_state <= RD_IDLE;
        else
            rd_state <= rd_state_next;
    end

    always_comb begin
        rd_state_next = rd_state;
        case (rd_state)
            RD_IDLE: begin
                if (m_arvalid && m_arready)
                    rd_state_next = RD_DELAY;
            end
            RD_DELAY: begin
                if (rd_delay_cnt >= rd_delay_target)
                    rd_state_next = RD_RESP;
            end
            RD_RESP: begin
                if (m_rvalid && m_rready)
                    rd_state_next = RD_IDLE;
            end
            default: rd_state_next = RD_IDLE;
        endcase
    end

    assign m_arready = (rd_state == RD_IDLE);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_delay_cnt    <= '0;
            rd_delay_target <= '0;
            rdata_buf       <= 32'h0;
            rresp_buf       <= `AXI4_RESP_OKAY;
        end else if (rd_state == RD_IDLE && m_arvalid && m_arready) begin
            rd_delay_target <= 4'(lfsr[1:0] % MAX_DELAY) + 4'd1;
            rd_delay_cnt    <= 4'd1;
            rdata_buf <= paddr_read(m_araddr);
            rresp_buf <= `AXI4_RESP_OKAY;
        end else if (rd_state == RD_DELAY) begin
            rd_delay_cnt <= rd_delay_cnt + 4'd1;
        end
    end

    assign m_rvalid = (rd_state == RD_RESP);
    assign m_rdata  = rdata_buf;
    assign m_rresp  = rresp_buf;
    assign m_rid    = 4'h0;
    assign m_rlast  = 1'b1;

    // --- 写通道状态机 ---
    typedef enum logic [1:0] {
        WR_IDLE = 2'd0,
        WR_DELAY = 2'd1,
        WR_RESP = 2'd2
    } wr_state_t;

    wr_state_t wr_state, wr_state_next;
    logic [3:0] wr_delay_cnt;
    logic [3:0] wr_delay_target;
    logic [1:0] bresp_buf;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            wr_state <= WR_IDLE;
        else
            wr_state <= wr_state_next;
    end

    wire wr_aw_w_handshake = m_awvalid && m_awready && m_wvalid && m_wready;

    always_comb begin
        wr_state_next = wr_state;
        case (wr_state)
            WR_IDLE: begin
                if (wr_aw_w_handshake)
                    wr_state_next = WR_DELAY;
            end
            WR_DELAY: begin
                if (wr_delay_cnt >= wr_delay_target)
                    wr_state_next = WR_RESP;
            end
            WR_RESP: begin
                if (m_bvalid && m_bready)
                    wr_state_next = WR_IDLE;
            end
            default: wr_state_next = WR_IDLE;
        endcase
    end

    assign m_awready = (wr_state == WR_IDLE);
    assign m_wready  = (wr_state == WR_IDLE);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_delay_cnt    <= '0;
            wr_delay_target <= '0;
            bresp_buf       <= `AXI4_RESP_OKAY;
        end else if (wr_state == WR_IDLE && wr_aw_w_handshake) begin
            wr_delay_target <= 4'(lfsr[1:0] % MAX_DELAY) + 4'd1;
            wr_delay_cnt    <= 4'd1;
            paddr_write(m_awaddr, {28'b0, m_wstrb}, m_wdata);
            bresp_buf <= `AXI4_RESP_OKAY;
        end else if (wr_state == WR_DELAY) begin
            wr_delay_cnt <= wr_delay_cnt + 4'd1;
        end
    end

    assign m_bvalid = (wr_state == WR_RESP);
    assign m_bresp  = bresp_buf;
    assign m_bid    = 4'h0;

endmodule
