`include "define.sv"
`include "axi4.sv"

// =============================================================
// ysyxSoC 顶层包装模块
// 命名规范：ysyx_XXXXXXXX
// 端口规范：cpu-interface.md
//
// 包含：
//   1. core (五级流水线 + SimpleBus)
//   2. axi_arbiter (SimpleBus → AXI4)
// =============================================================

module ysyx_250309 (
    input  logic        clock,
    input  logic        reset,
    input  logic        io_interrupt,

    // AXI4 Master
    // AW
    output logic        io_master_awvalid,
    input  logic        io_master_awready,
    output logic [31:0] io_master_awaddr,
    output logic [3:0]  io_master_awid,
    output logic [7:0]  io_master_awlen,
    output logic [2:0]  io_master_awsize,
    output logic [1:0]  io_master_awburst,
    // W
    output logic        io_master_wvalid,
    input  logic        io_master_wready,
    output logic [31:0] io_master_wdata,
    output logic [3:0]  io_master_wstrb,
    output logic        io_master_wlast,
    // B
    input  logic        io_master_bvalid,
    output logic        io_master_bready,
    input  logic [1:0]  io_master_bresp,
    input  logic [3:0]  io_master_bid,
    // AR
    output logic        io_master_arvalid,
    input  logic        io_master_arready,
    output logic [31:0] io_master_araddr,
    output logic [3:0]  io_master_arid,
    output logic [7:0]  io_master_arlen,
    output logic [2:0]  io_master_arsize,
    output logic [1:0]  io_master_arburst,
    // R
    input  logic        io_master_rvalid,
    output logic        io_master_rready,
    input  logic [31:0] io_master_rdata,
    input  logic [1:0]  io_master_rresp,
    input  logic [3:0]  io_master_rid,
    input  logic        io_master_rlast,

    // AXI4 Slave (不使用，接默认值)
    output logic        io_slave_awready,
    input  logic        io_slave_awvalid,
    input  logic [31:0] io_slave_awaddr,
    input  logic [3:0]  io_slave_awid,
    input  logic [7:0]  io_slave_awlen,
    input  logic [2:0]  io_slave_awsize,
    input  logic [1:0]  io_slave_awburst,
    output logic        io_slave_wready,
    input  logic        io_slave_wvalid,
    input  logic [31:0] io_slave_wdata,
    input  logic [3:0]  io_slave_wstrb,
    input  logic        io_slave_wlast,
    output logic        io_slave_bvalid,
    input  logic        io_slave_bready,
    output logic [1:0]  io_slave_bresp,
    output logic [3:0]  io_slave_bid,
    output logic        io_slave_arready,
    input  logic        io_slave_arvalid,
    input  logic [31:0] io_slave_araddr,
    input  logic [3:0]  io_slave_arid,
    input  logic [7:0]  io_slave_arlen,
    input  logic [2:0]  io_slave_arsize,
    input  logic [1:0]  io_slave_arburst,
    output logic        io_slave_rvalid,
    input  logic        io_slave_rready,
    output logic [31:0] io_slave_rdata,
    output logic [1:0]  io_slave_rresp,
    output logic [3:0]  io_slave_rid,
    output logic        io_slave_rlast
);

    // --- Slave 端口不使用，接默认值 ---
    assign io_slave_awready = 1'b0;
    assign io_slave_wready  = 1'b0;
    assign io_slave_bvalid  = 1'b0;
    assign io_slave_bresp   = `AXI4_RESP_OKAY;
    assign io_slave_bid     = 4'h0;
    assign io_slave_arready = 1'b0;
    assign io_slave_rvalid  = 1'b0;
    assign io_slave_rdata   = 32'h0;
    assign io_slave_rresp   = `AXI4_RESP_OKAY;
    assign io_slave_rid     = 4'h0;
    assign io_slave_rlast   = 1'b0;

    // --- 内部信号：core ↔ arbiter ---
    wire rst_n = ~reset;

    // IFU AXI4
    wire        ifu_arvalid, ifu_arready;
    wire [31:0] ifu_araddr;
    wire [2:0]  ifu_arsize;
    wire [7:0]  ifu_arlen;
    wire [1:0]  ifu_arburst;
    wire [3:0]  ifu_arid;

    wire        ifu_rvalid, ifu_rready;
    wire [31:0] ifu_rdata;
    wire [1:0]  ifu_rresp;
    wire        ifu_rlast;

    // LSU AXI4
    wire        lsu_arvalid, lsu_arready;
    wire [31:0] lsu_araddr;
    wire [2:0]  lsu_arsize;
    wire [7:0]  lsu_arlen;
    wire [1:0]  lsu_arburst;
    wire [3:0]  lsu_arid;

    wire        lsu_rvalid, lsu_rready;
    wire [31:0] lsu_rdata;
    wire [1:0]  lsu_rresp;
    wire        lsu_rlast;

    wire        lsu_awvalid, lsu_awready;
    wire [31:0] lsu_awaddr;
    wire [2:0]  lsu_awsize;
    wire [7:0]  lsu_awlen;
    wire [1:0]  lsu_awburst;
    wire [3:0]  lsu_awid;

    wire        lsu_wvalid, lsu_wready;
    wire [31:0] lsu_wdata;
    wire [3:0]  lsu_wstrb;
    wire        lsu_wlast;

    wire        lsu_bvalid, lsu_bready;
    wire [1:0]  lsu_bresp;
    wire [3:0]  lsu_bid;

    // debug (未连接)
    wire [31:0] debug_regs [15:0];
    wire        debug_have;
    wire [31:0] debug_pc;
    wire [31:0] debug_instr;
    wire        debug_en;
    wire [4:0]  debug_addr;
    wire [31:0] debug_data;

    // --- 实例化 core ---
    core u_core (
        .clk            (clock),
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

    // --- 实例化仲裁器 ---
    axi_arbiter u_arbiter (
        .clk       (clock),
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

        // AXI4 Master
        .m_arvalid   (io_master_arvalid),
        .m_arready   (io_master_arready),
        .m_araddr    (io_master_araddr),
        .m_arid      (io_master_arid),
        .m_arlen     (io_master_arlen),
        .m_arsize    (io_master_arsize),
        .m_arburst   (io_master_arburst),
        .m_rvalid    (io_master_rvalid),
        .m_rready    (io_master_rready),
        .m_rdata     (io_master_rdata),
        .m_rresp     (io_master_rresp),
        .m_rid       (io_master_rid),
        .m_rlast     (io_master_rlast),
        .m_awvalid   (io_master_awvalid),
        .m_awready   (io_master_awready),
        .m_awaddr    (io_master_awaddr),
        .m_awid      (io_master_awid),
        .m_awlen     (io_master_awlen),
        .m_awsize    (io_master_awsize),
        .m_awburst   (io_master_awburst),
        .m_wvalid    (io_master_wvalid),
        .m_wready    (io_master_wready),
        .m_wdata     (io_master_wdata),
        .m_wstrb     (io_master_wstrb),
        .m_wlast     (io_master_wlast),
        .m_bvalid    (io_master_bvalid),
        .m_bready    (io_master_bready),
        .m_bresp     (io_master_bresp),
        .m_bid       (io_master_bid)
    );

endmodule
