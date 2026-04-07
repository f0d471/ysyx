`include "define.sv"

module fetch #(
    parameter AW = 32,
    parameter DW = 32
)(
    input  logic          clk,
    input  logic          rst_n,
 
    //  PC
    input  logic [AW-1:0] pc_pointer,
 
    //  SimpleBus 接口
    output logic [AW-1:0] ifu_raddr,      // → 存储器地址
    input  logic [DW-1:0] ifu_rdata,      // ← 存储器返回的指令
 
    //  流水线控制 
    input  logic          flush,          // 跳转冲刷（ex_jump_flag）
    output logic [DW-1:0] instr_out,      // → IF/ID 流水线寄存器
    output logic          ifu_valid       // → IF/ID 的 up_valid
);
 
    // =============================================================
    //  状态机：idle / wait 两状态交替
    // =============================================================
    localparam IDLE = 1'b0;
    localparam WAIT = 1'b1;
 
    logic state, state_next;
 
    // 状态转移
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            state <= IDLE;
        else
            state <= state_next;
    end
 
    // 次态逻辑
    //   - flush 时强制回 idle（丢弃正在等待的无效取指）
    //   - 正常时 idle → wait → idle → wait 交替
    always_comb begin
        case (state)
            IDLE:  state_next = flush ? IDLE : WAIT;
            WAIT:  state_next = IDLE;   // wait 固定回 idle
            default: state_next = IDLE;
        endcase
    end
 
    // =============================================================
    //  输出逻辑
    // =============================================================
 
    // 地址总是输出 PC（idle 时存储器锁存此地址，wait 时的地址无关紧要）
    assign ifu_raddr = pc_pointer;
 
    // 指令有效：仅在 wait 状态且无 flush 时
    //   - idle 时存储器还没返回数据，无有效指令
    //   - flush 时即使在 wait，指令也是错误路径的，必须丢弃
    assign ifu_valid = (state == WAIT) && !flush;
 
    // 指令输出：有效时取存储器数据，否则输出 NOP
    assign instr_out = ifu_valid ? ifu_rdata : `INST_NOP;
 
endmodule