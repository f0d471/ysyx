`include "axi4.sv"

// =============================================================
// AXI4 轻量级合并器
// 将 IFU (只读) 和 LSU (读写) 两个原生 AXI4 端口
// 合并为一个 AXI4 Master 端口
//
// 读通道 (AR/R)：IFU 优先，LSU 被阻塞时 IFU 可独立工作
// 写通道 (AW/W/B)：仅 LSU 使用，直通
// =============================================================

module axi_arbiter (
    input  logic clk,
    input  logic rst_n,

    // --- IFU AXI4 端口 (只读) ---
    // AR
    input  logic        ifu_arvalid,
    output logic        ifu_arready,
    input  logic [31:0] ifu_araddr,
    input  logic [2:0]  ifu_arsize,
    input  logic [7:0]  ifu_arlen,
    input  logic [1:0]  ifu_arburst,
    input  logic [3:0]  ifu_arid,
    // R
    output logic        ifu_rvalid,
    input  logic        ifu_rready,
    output logic [31:0] ifu_rdata,
    output logic [1:0]  ifu_rresp,
    output logic        ifu_rlast,

    // --- LSU AXI4 端口 (读写) ---
    // AR
    input  logic        lsu_arvalid,
    output logic        lsu_arready,
    input  logic [31:0] lsu_araddr,
    input  logic [2:0]  lsu_arsize,
    input  logic [7:0]  lsu_arlen,
    input  logic [1:0]  lsu_arburst,
    input  logic [3:0]  lsu_arid,
    // R
    output logic        lsu_rvalid,
    input  logic        lsu_rready,
    output logic [31:0] lsu_rdata,
    output logic [1:0]  lsu_rresp,
    output logic        lsu_rlast,
    // AW
    input  logic        lsu_awvalid,
    output logic        lsu_awready,
    input  logic [31:0] lsu_awaddr,
    input  logic [2:0]  lsu_awsize,
    input  logic [7:0]  lsu_awlen,
    input  logic [1:0]  lsu_awburst,
    input  logic [3:0]  lsu_awid,
    // W
    input  logic        lsu_wvalid,
    output logic        lsu_wready,
    input  logic [31:0] lsu_wdata,
    input  logic [3:0]  lsu_wstrb,
    input  logic        lsu_wlast,
    // B
    output logic        lsu_bvalid,
    input  logic        lsu_bready,
    output logic [1:0]  lsu_bresp,
    output logic [3:0]  lsu_bid,

    // --- AXI4 Master 端口 (连接 SoC) ---
    // AR
    output logic        m_arvalid,
    input  logic        m_arready,
    output logic [31:0] m_araddr,
    output logic [3:0]  m_arid,
    output logic [7:0]  m_arlen,
    output logic [2:0]  m_arsize,
    output logic [1:0]  m_arburst,
    // R
    input  logic        m_rvalid,
    output logic        m_rready,
    input  logic [31:0] m_rdata,
    input  logic [1:0]  m_rresp,
    input  logic [3:0]  m_rid,
    input  logic        m_rlast,
    // AW
    output logic        m_awvalid,
    input  logic        m_awready,
    output logic [31:0] m_awaddr,
    output logic [3:0]  m_awid,
    output logic [7:0]  m_awlen,
    output logic [2:0]  m_awsize,
    output logic [1:0]  m_awburst,
    // W
    output logic        m_wvalid,
    input  logic        m_wready,
    output logic [31:0] m_wdata,
    output logic [3:0]  m_wstrb,
    output logic        m_wlast,
    // B
    input  logic        m_bvalid,
    output logic        m_bready,
    input  logic [1:0]  m_bresp,
    input  logic [3:0]  m_bid
);

    // ================================================================
    //  读通道仲裁 (AR + R)
    //  IFU 优先：流水线中 IFU 被 lsu_busy 阻塞，
    //  所以 IFU 和 LSU 不会同时发 AR 请求
    // ================================================================

    // AR 通道选择
    logic sel_lsu_ar;  // 1 = LSU 获得 AR 通道

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            sel_lsu_ar <= 1'b0;
        else if (m_arvalid && m_arready) begin
            sel_lsu_ar <= 1'b0;  // 握手后清除
        end else if (lsu_arvalid && !ifu_arvalid) begin
            sel_lsu_ar <= 1'b1;  // LSU 优先
        end
    end

    // AR 通道 MUX
    assign m_arvalid = lsu_arvalid | ifu_arvalid;
    assign m_araddr  = lsu_arvalid ? lsu_araddr  : ifu_araddr;
    assign m_arid    = lsu_arvalid ? lsu_arid    : ifu_arid;
    assign m_arlen   = lsu_arvalid ? lsu_arlen   : ifu_arlen;
    assign m_arsize  = lsu_arvalid ? lsu_arsize  : ifu_arsize;
    assign m_arburst = lsu_arvalid ? lsu_arburst : ifu_arburst;

    // AR ready 路由
    assign lsu_arready = m_arready && lsu_arvalid;
    assign ifu_arready = m_arready && !lsu_arvalid;

    // R 通道 MUX (路由回请求方)
    assign lsu_rvalid = m_rvalid && sel_lsu_ar;
    assign ifu_rvalid = m_rvalid && !sel_lsu_ar;
    assign m_rready   = sel_lsu_ar ? lsu_rready : ifu_rready;
    assign lsu_rdata  = m_rdata;
    assign ifu_rdata  = m_rdata;
    assign lsu_rresp  = m_rresp;
    assign ifu_rresp  = m_rresp;
    assign lsu_rlast  = m_rlast;
    assign ifu_rlast  = m_rlast;

    // ================================================================
    //  写通道直通 (AW + W + B)
    //  仅 LSU 使用，无需仲裁
    // ================================================================

    assign m_awvalid = lsu_awvalid;
    assign m_awaddr  = lsu_awaddr;
    assign m_awid    = lsu_awid;
    assign m_awlen   = lsu_awlen;
    assign m_awsize  = lsu_awsize;
    assign m_awburst = lsu_awburst;
    assign lsu_awready = m_awready;

    assign m_wvalid  = lsu_wvalid;
    assign m_wdata   = lsu_wdata;
    assign m_wstrb   = lsu_wstrb;
    assign m_wlast   = lsu_wlast;
    assign lsu_wready = m_wready;

    assign lsu_bvalid = m_bvalid;
    assign m_bready   = lsu_bready;
    assign lsu_bresp  = m_bresp;
    assign lsu_bid    = m_bid;

endmodule
