`include "define.sv"

import "DPI-C" function int  paddr_read (input int addr);
import "DPI-C" function void paddr_write(input int addr, input int len, input int data);


// =================================================================
//  通用仿真 SRAM（IFU 和 LSU 复用）
// =================================================================
module sim_sram #(
    parameter DELAY_MODE  = 2,     // 0=固定N  1=LFSR随机  2=固定1
    parameter FIXED_DELAY = 5,     // DELAY_MODE=0 时的延迟周期数
    parameter LFSR_WIDTH  = 4,     // DELAY_MODE=1 时，延迟范围 1 ~ 2^W-1
    parameter LFSR_SEED   = 4'hA,  // LFSR 种子（不能全 0）
    parameter HAS_WRITE   = 0      // 0=只读(IFU)  1=读写(LSU)
)(
    input  logic        clk,
    input  logic        rst_n,

    // SimpleBus
    input  logic        reqValid,
    input  logic [31:0] addr,
    input  logic        wen,       // HAS_WRITE=1 时有意义
    input  logic [31:0] wdata,
    input  logic [3:0]  wmask,
    output logic        respValid,
    output logic [31:0] rdata
);

    // ---- wmask → len ----
    function automatic int wmask2len(input logic [3:0] m);
        case (m)
            4'b0001, 4'b0010, 4'b0100, 4'b1000: return 1;
            4'b0011, 4'b1100:                    return 2;
            default:                             return 4;
        endcase
    endfunction

    // ---- LFSR（伪随机数发生器）----
    logic [LFSR_WIDTH-1:0] lfsr;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            lfsr <= LFSR_SEED;
        else
            lfsr <= {lfsr[0] ^ lfsr[LFSR_WIDTH-1], lfsr[LFSR_WIDTH-1:1]};
    end

    // ---- 延迟目标 ----
    logic [15:0] delay_target;
    generate
        if (DELAY_MODE == 0)
            assign delay_target = FIXED_DELAY[15:0];
        else if (DELAY_MODE == 1)
            assign delay_target = (lfsr == 0) ? 16'd1 : {{(16-LFSR_WIDTH){1'b0}}, lfsr};
        else
            assign delay_target = 16'd1;
    endgenerate

    // ---- 状态机 ----
    localparam S_IDLE    = 1'b0;
    localparam S_WAITING = 1'b1;

    logic        state;
    logic [15:0] counter;
    logic [31:0] lat_addr;
    logic        lat_wen;
    logic [31:0] lat_wdata;
    logic [3:0]  lat_wmask;
    logic [15:0] lat_delay;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state     <= S_IDLE;
            counter   <= 0;
            respValid <= 0;
            rdata     <= 0;
        end
        else begin
            case (state)
                S_IDLE: begin
                    respValid <= 1'b0;
                    if (reqValid) begin
                        lat_addr  <= addr;
                        lat_wen   <= wen;
                        lat_wdata <= wdata;
                        lat_wmask <= wmask;
                        lat_delay <= delay_target;
                        counter   <= 16'd1;
                        state     <= S_WAITING;
                    end
                end

                S_WAITING: begin
                    if (counter >= lat_delay) begin
                        if (HAS_WRITE && lat_wen) begin
                            paddr_write(lat_addr, wmask2len(lat_wmask), lat_wdata);
                            rdata <= 32'h0;
                        end else begin
                            rdata <= paddr_read(lat_addr);
                        end
                        respValid <= 1'b1;
                        state     <= S_IDLE;
                    end
                    else begin
                        counter   <= counter + 16'd1;
                        respValid <= 1'b0;
                    end
                end
            endcase
        end
    end

endmodule
