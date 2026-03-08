module csr_file #(
    parameter [31:0] STU_ID = 32'd250309
)(
    input  logic        clk,
    input  logic        rst,

    // 读端口
    input  logic [11:0] csr_raddr,
    output logic [31:0] csr_rdata,

    // 写端口
    input  logic        csr_wen,
    input  logic [11:0] csr_waddr,
    input  logic [31:0] csr_wdata,

    // 异常响应机制专用接口 (保持不变)
    input  logic        trap_valid,
    input  logic [31:0] trap_pc,
    input  logic [31:0] trap_cause,
    output logic [31:0] trap_mtvec,
    output logic [31:0] trap_mepc
);

    // --- 物理寄存器定义 ---
    logic [31:0] mstatus; // 0x300
    logic [31:0] mtvec;   // 0x305
    logic [31:0] mepc;    // 0x341
    logic [31:0] mcause;  // 0x342
    
    // [新增] 64位的周期计数器
    logic [63:0] mcycle_cnt;

    // --- 读逻辑 (多路选择器，按需返回数据) ---
    always_comb begin
        case (csr_raddr)
            // 异常相关
            12'h300: csr_rdata = mstatus;
            12'h305: csr_rdata = mtvec;
            12'h341: csr_rdata = mepc;
            12'h342: csr_rdata = mcause;

            // [新增] 性能计数器 (拆分为低32位和高32位)
            12'hB00: csr_rdata = mcycle_cnt[31:0];  // mcycle
            12'hB80: csr_rdata = mcycle_cnt[63:32]; // mcycleh

            // [新增] 只读的机器信息寄存器 (直接返回硬编码常数)
            12'hF11: csr_rdata = 32'h79737978; // mvendorid ("ysyx"的ASCII码)
            12'hF12: csr_rdata = STU_ID;       // marchid (学号)

            default: csr_rdata = 32'b0;
        endcase
    end

    // --- 写逻辑与计数器递增 ---
    always_ff @(posedge clk) begin
        if (rst) begin
            mstatus    <= 32'h1800;
            mtvec      <= 32'b0;
            mepc       <= 32'b0;
            mcause     <= 32'b0;
            mcycle_cnt <= 64'b0; // 计数器复位
        end 
        else begin
            // [新增] mcycle 计数器每个时钟周期无条件加 1
            mcycle_cnt <= mcycle_cnt + 64'd1;

            if (trap_valid) begin
                mepc   <= trap_pc;
                mcause <= trap_cause;
            end 
            else if (csr_wen) begin
                case (csr_waddr)
                    12'h300: mstatus <= csr_wdata;
                    12'h305: mtvec   <= csr_wdata;
                    12'h341: mepc    <= csr_wdata;
                    12'h342: mcause  <= csr_wdata;
                    // 注意：mvendorid 和 marchid 是硬件写死的只读信息，因此没有写逻辑
                    // AM 里的时钟测试通常只需读取 mcycle，所以这里也没加 mcycle 的写逻辑
                    default: ; 
                endcase
            end
        end
    end

    assign trap_mtvec = mtvec;
    assign trap_mepc  = mepc;

endmodule