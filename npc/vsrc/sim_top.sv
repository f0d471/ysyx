`include "define.sv"

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

    //  IFU SimpleBus 信号 
    logic [31:0] ifu_raddr;
    logic [31:0] ifu_rdata;
    logic        ifu_reqValid;
    logic        ifu_reqReady;
    logic        ifu_respValid;
    logic        ifu_respReady;

    //  LSU SimpleBus 信号 
    logic [31:0] lsu_addr;
    logic        lsu_ren;
    logic        lsu_wen;
    logic [31:0] lsu_wdata;
    logic [3:0]  lsu_wmask;
    logic [31:0] lsu_rdata;
    logic        lsu_reqValid;
    logic        lsu_reqReady;
    logic        lsu_respValid;
    logic        lsu_respReady;

    core u_core (
        .clk            (clk),
        .rst_n          (rst_n),

        .debug_regs     (debug_regs),

        .ifu_raddr      (ifu_raddr),
        .ifu_rdata      (ifu_rdata),
        .ifu_reqValid   (ifu_reqValid),
        .ifu_reqReady   (ifu_reqReady),
        .ifu_respValid  (ifu_respValid),
        .ifu_respReady  (ifu_respReady),

        .lsu_addr       (lsu_addr),
        .lsu_ren        (lsu_ren),
        .lsu_wen        (lsu_wen),
        .lsu_wdata      (lsu_wdata),
        .lsu_wmask      (lsu_wmask),
        .lsu_rdata      (lsu_rdata),
        .lsu_reqValid   (lsu_reqValid),
        .lsu_reqReady   (lsu_reqReady),
        .lsu_respValid  (lsu_respValid),
        .lsu_respReady  (lsu_respReady),

        .debug_have     (debug_have),
        .debug_pc       (debug_pc),
        .debug_instr    (debug_instr),
        .debug_en       (debug_en),
        .debug_addr     (debug_addr),
        .debug_data     (debug_data)
    );

    localparam IFU_MAX_DELAY = 3;
    
    logic        ifu_mem_busy;
    logic [3:0]  ifu_delay_cnt;
    logic [3:0]  ifu_delay_target;
    logic [31:0] ifu_rdata_buf;

    logic [7:0] ifu_lfsr;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            ifu_lfsr <= 8'hA5;
        else
            ifu_lfsr <= {ifu_lfsr[6:0], ifu_lfsr[7] ^ ifu_lfsr[5] ^ ifu_lfsr[4] ^ ifu_lfsr[3]};
    end

    assign ifu_reqReady = 1'b1;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            ifu_mem_busy     <= 1'b0;
            ifu_delay_cnt    <= '0;
            ifu_delay_target <= '0;
            ifu_rdata_buf    <= 32'h00000013;
            ifu_respValid    <= 1'b0;
            ifu_rdata        <= 32'h00000013;
        end else begin
            if (ifu_reqValid && ifu_reqReady) begin
                ifu_rdata_buf    <= paddr_read(ifu_raddr & ~32'h3);
                ifu_delay_target <= 4'(ifu_lfsr[1:0] % IFU_MAX_DELAY) + 4'd1;
                ifu_delay_cnt    <= 4'd1;
                ifu_mem_busy     <= 1'b1;
                ifu_respValid    <= 1'b0;   
            end
            else if (ifu_respValid && ifu_respReady) begin
                ifu_mem_busy  <= 1'b0;
                ifu_respValid <= 1'b0;
            end
            else if (ifu_mem_busy && !ifu_respValid) begin
                if (ifu_delay_cnt >= ifu_delay_target) begin
                    ifu_respValid <= 1'b1;
                    ifu_rdata     <= ifu_rdata_buf;
                end else begin
                    ifu_delay_cnt <= ifu_delay_cnt + 4'd1;
                end
            end
        end
    end

    localparam LSU_MAX_DELAY = 3;

    logic [3:0]  lsu_delay_cnt;
    logic [3:0]  lsu_delay_target;
    logic        lsu_mem_busy;
    logic [31:0] lsu_rdata_buf;

    logic [7:0] lsu_lfsr;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            lsu_lfsr <= 8'h5A;
        else
            lsu_lfsr <= {lsu_lfsr[6:0], lsu_lfsr[7] ^ lsu_lfsr[5] ^ lsu_lfsr[4] ^ lsu_lfsr[3]};
    end

    assign lsu_reqReady = !lsu_mem_busy;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            lsu_mem_busy     <= 1'b0;
            lsu_delay_cnt    <= '0;
            lsu_delay_target <= '0;
            lsu_rdata_buf    <= 32'h0;
            lsu_respValid    <= 1'b0;
            lsu_rdata        <= 32'h0;
        end else begin
            if (!lsu_mem_busy) begin
                lsu_respValid <= 1'b0;
                if (lsu_reqValid && lsu_reqReady) begin
                    if (lsu_wen) begin
                        paddr_write(lsu_addr & ~32'h3, {28'b0, lsu_wmask}, lsu_wdata);
                        lsu_rdata_buf <= 32'h0;
                    end else begin
                        lsu_rdata_buf <= paddr_read(lsu_addr & ~32'h3);
                    end
                    lsu_delay_target <= 4'(lsu_lfsr[1:0] % LSU_MAX_DELAY) + 4'd1;
                    lsu_delay_cnt    <= 4'd1;
                    lsu_mem_busy     <= 1'b1;
                end
            end else begin
                if (lsu_respValid && lsu_respReady) begin
                    lsu_mem_busy  <= 1'b0;
                    lsu_respValid <= 1'b0;
                end else if (!lsu_respValid) begin
                    if (lsu_delay_cnt >= lsu_delay_target) begin
                        lsu_respValid <= 1'b1;
                        lsu_rdata     <= lsu_rdata_buf;
                    end else begin
                        lsu_delay_cnt <= lsu_delay_cnt + 4'd1;
                    end
                end
            end
        end
    end

endmodule