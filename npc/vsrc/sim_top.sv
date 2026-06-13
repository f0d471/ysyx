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
    //  AXI4 Master 信号 (core → arbiter → 这里)
    // ================================================================
    // AR
    logic        m_arvalid, m_arready;
    logic [31:0] m_araddr;
    logic [3:0]  m_arid;
    logic [7:0]  m_arlen;
    logic [2:0]  m_arsize;
    logic [1:0]  m_arburst;
    // R
    logic        m_rvalid, m_rready;
    logic [31:0] m_rdata;
    logic [1:0]  m_rresp;
    logic [3:0]  m_rid;
    logic        m_rlast;
    // AW
    logic        m_awvalid, m_awready;
    logic [31:0] m_awaddr;
    logic [3:0]  m_awid;
    logic [7:0]  m_awlen;
    logic [2:0]  m_awsize;
    logic [1:0]  m_awburst;
    // W
    logic        m_wvalid, m_wready;
    logic [31:0] m_wdata;
    logic [3:0]  m_wstrb;
    logic        m_wlast;
    // B
    logic        m_bvalid, m_bready;
    logic [1:0]  m_bresp;
    logic [3:0]  m_bid;

    // ================================================================
    //  Core
    // ================================================================
    // IFU SimpleBus
    logic [31:0] ifu_araddr;
    logic        ifu_arvalid, ifu_arready;
    logic [31:0] ifu_rdata;
    logic        ifu_rvalid, ifu_rready;
    logic [1:0]  ifu_rresp;

    // LSU SimpleBus
    logic [31:0] lsu_araddr;
    logic        lsu_arvalid, lsu_arready;
    logic [31:0] lsu_rdata;
    logic        lsu_rvalid, lsu_rready;
    logic [1:0]  lsu_rresp;

    logic [31:0] lsu_awaddr;
    logic        lsu_awvalid, lsu_awready;
    logic [31:0] lsu_wdata;
    logic [3:0]  lsu_wstrb;
    logic        lsu_wvalid, lsu_wready;
    logic        lsu_bvalid, lsu_bready;
    logic [1:0]  lsu_bresp;

    core u_core (
        .clk            (clk),
        .rst_n          (rst_n),

        .debug_regs     (debug_regs),

        .ifu_raddr      (ifu_araddr),
        .ifu_reqValid   (ifu_arvalid),
        .ifu_reqReady   (ifu_arready),
        .ifu_rdata      (ifu_rdata),
        .ifu_respValid  (ifu_rvalid),
        .ifu_respReady  (ifu_rready),
        .ifu_rresp      (ifu_rresp),

        .lsu_addr       (lsu_araddr),
        .lsu_ren        (),
        .lsu_wen        (lsu_awvalid),
        .lsu_wdata      (lsu_wdata),
        .lsu_wmask      (lsu_wstrb),
        .lsu_reqValid   (lsu_arvalid),
        .lsu_reqReady   (lsu_arready),
        .lsu_rdata      (lsu_rdata),
        .lsu_respValid  (lsu_rvalid),
        .lsu_respReady  (lsu_rready),
        .lsu_rresp      (lsu_rresp),
        .lsu_bresp      (lsu_bresp),

        .debug_have     (debug_have),
        .debug_pc       (debug_pc),
        .debug_instr    (debug_instr),
        .debug_en       (debug_en),
        .debug_addr     (debug_addr),
        .debug_data     (debug_data)
    );

    // ================================================================
    //  Arbiter (SimpleBus → AXI4)
    // ================================================================
    axi_arbiter u_arbiter (
        .clk       (clk),
        .rst_n     (rst_n),

        // IFU
        .ifu_araddr  (ifu_araddr),
        .ifu_arvalid (ifu_arvalid),
        .ifu_arready (ifu_arready),
        .ifu_rdata   (ifu_rdata),
        .ifu_rvalid  (ifu_rvalid),
        .ifu_rready  (ifu_rready),
        .ifu_rresp   (ifu_rresp),

        // LSU
        .lsu_araddr  (lsu_araddr),
        .lsu_arvalid (lsu_arvalid & ~lsu_awvalid),
        .lsu_arready (lsu_arready),
        .lsu_rdata   (lsu_rdata),
        .lsu_rvalid  (lsu_rvalid),
        .lsu_rready  (lsu_rready),
        .lsu_rresp   (lsu_rresp),

        .lsu_awaddr  (lsu_awaddr),
        .lsu_awvalid (lsu_awvalid),
        .lsu_awready (lsu_awready),
        .lsu_wdata   (lsu_wdata),
        .lsu_wstrb   (lsu_wstrb),
        .lsu_wvalid  (lsu_wvalid),
        .lsu_wready  (lsu_wready),
        .lsu_bvalid  (lsu_bvalid),
        .lsu_bready  (lsu_bready),
        .lsu_bresp   (lsu_bresp),

        // AXI4 Master
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
    //  - 使用 DPI-C (paddr_read / paddr_write) 访问实际存储
    //  - LFSR 随机延迟 (1~4 周期)
    //  - 地址越界返回 DECERR
    // ================================================================

    localparam MAX_DELAY = 4;

    // LFSR
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

    // 读请求握手：始终就绪
    assign m_arready = (rd_state == RD_IDLE);

    // 读延迟计数 + 数据获取
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_delay_cnt    <= '0;
            rd_delay_target <= '0;
            rdata_buf       <= 32'h0;
            rresp_buf       <= `AXI4_RESP_OKAY;
        end else if (rd_state == RD_IDLE && m_arvalid && m_arready) begin
            // 握手成功，开始延迟
            rd_delay_target <= 4'(lfsr[1:0] % MAX_DELAY) + 4'd1;
            rd_delay_cnt    <= 4'd1;
            // 同时读取数据
            rdata_buf <= paddr_read(m_araddr);
            rresp_buf <= `AXI4_RESP_OKAY;
        end else if (rd_state == RD_DELAY) begin
            rd_delay_cnt <= rd_delay_cnt + 4'd1;
        end
    end

    // R 通道输出
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

    // 写通道：AW 和 W 同时握手
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

    // AW/W 握手：同时就绪
    assign m_awready = (wr_state == WR_IDLE);
    assign m_wready  = (wr_state == WR_IDLE);

    // 写延迟计数 + 数据写入
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_delay_cnt    <= '0;
            wr_delay_target <= '0;
            bresp_buf       <= `AXI4_RESP_OKAY;
        end else if (wr_state == WR_IDLE && wr_aw_w_handshake) begin
            wr_delay_target <= 4'(lfsr[1:0] % MAX_DELAY) + 4'd1;
            wr_delay_cnt    <= 4'd1;
            // 写入存储
            paddr_write(m_awaddr, {28'b0, m_wstrb}, m_wdata);
            bresp_buf <= `AXI4_RESP_OKAY;
        end else if (wr_state == WR_DELAY) begin
            wr_delay_cnt <= wr_delay_cnt + 4'd1;
        end
    end

    // B 通道输出
    assign m_bvalid = (wr_state == WR_RESP);
    assign m_bresp  = bresp_buf;
    assign m_bid    = 4'h0;

endmodule
