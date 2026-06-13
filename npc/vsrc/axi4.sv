`ifndef AXI4_SV
`define AXI4_SV

// =============================================================
// AXI4 协议定义
// 对齐 ysyxSoC CPU 接口规范 (cpu-interface.md)
// 当前仅支持单次传输 (len=0, 即 non-burst)
// =============================================================

// --- AXI4 参数 ---
`define AXI4_ADDR_W   32
`define AXI4_DATA_W   32
`define AXI4_ID_W     4
`define AXI4_LEN_W    8
`define AXI4_SIZE_W   3
`define AXI4_BURST_W  2
`define AXI4_RESP_W   2
`define AXI4_STRB_W   4

// Burst 类型
`define AXI4_BURST_FIXED 2'b00
`define AXI4_BURST_INCR  2'b01
`define AXI4_BURST_WRAP  2'b10

// 响应码
`define AXI4_RESP_OKAY   2'b00
`define AXI4_RESP_EXOKAY 2'b01
`define AXI4_RESP_SLVERR 2'b10
`define AXI4_RESP_DECERR 2'b11

// 传输宽度 (arsize / awsize)
`define AXI4_SIZE_1B   3'b000
`define AXI4_SIZE_2B   3'b001
`define AXI4_SIZE_4B   3'b010

// --- 通道结构体 ---

// AR 通道 (读地址) - master 输出
typedef struct packed {
    logic [`AXI4_ID_W-1:0]    id;
    logic [`AXI4_ADDR_W-1:0]  addr;
    logic [`AXI4_LEN_W-1:0]   len;     // burst 长度 - 1
    logic [`AXI4_SIZE_W-1:0]  size;    // 每拍字节数 = 2^size
    logic [`AXI4_BURST_W-1:0] burst;   // burst 类型
} axi4_ar_t;

// R 通道 (读数据) - slave 输出
typedef struct packed {
    logic [`AXI4_ID_W-1:0]    id;
    logic [`AXI4_DATA_W-1:0]  data;
    logic [`AXI4_RESP_W-1:0]  resp;
    logic                     last;
} axi4_r_t;

// AW 通道 (写地址) - master 输出
typedef struct packed {
    logic [`AXI4_ID_W-1:0]    id;
    logic [`AXI4_ADDR_W-1:0]  addr;
    logic [`AXI4_LEN_W-1:0]   len;
    logic [`AXI4_SIZE_W-1:0]  size;
    logic [`AXI4_BURST_W-1:0] burst;
} axi4_aw_t;

// W 通道 (写数据) - master 输出
typedef struct packed {
    logic [`AXI4_DATA_W-1:0]  data;
    logic [`AXI4_STRB_W-1:0]  strb;
    logic                     last;
} axi4_w_t;

// B 通道 (写回复) - slave 输出
typedef struct packed {
    logic [`AXI4_ID_W-1:0]    id;
    logic [`AXI4_RESP_W-1:0]  resp;
} axi4_b_t;

// --- AXI4 握手对 (valid + ready + payload) ---

// master 端口信号方向 (CPU 视角)
typedef struct packed {
    // AR
    logic        arvalid;
    axi4_ar_t    ar;
    // R (输入)
    logic        rready;
    // AW
    logic        awvalid;
    axi4_aw_t    aw;
    // W
    logic        wvalid;
    axi4_w_t     w;
    // B (输入)
    logic        bready;
} axi4_m_out_t;

typedef struct packed {
    // AR (输入)
    logic        arready;
    // R
    logic        rvalid;
    axi4_r_t     r;
    // AW (输入)
    logic        awready;
    // W (输入)
    logic        wready;
    // B
    logic        bvalid;
    axi4_b_t     b;
} axi4_m_in_t;

// --- 默认值常量 ---

function automatic axi4_ar_t axi4_default_ar();
    axi4_ar_t ar;
    ar.id    = '0;
    ar.addr  = '0;
    ar.len   = 8'h0;           // 单次传输
    ar.size  = `AXI4_SIZE_4B;  // 4 字节
    ar.burst = `AXI4_BURST_INCR;
    return ar;
endfunction

function automatic axi4_aw_t axi4_default_aw();
    axi4_aw_t aw;
    aw.id    = '0;
    aw.addr  = '0;
    aw.len   = 8'h0;
    aw.size  = `AXI4_SIZE_4B;
    aw.burst = `AXI4_BURST_INCR;
    return aw;
endfunction

function automatic axi4_w_t axi4_default_w();
    axi4_w_t w;
    w.data = '0;
    w.strb = 4'b1111;
    w.last = 1'b1;
    return w;
endfunction

`endif // AXI4_SV
