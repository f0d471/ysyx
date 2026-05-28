module forward_unit (
    input  logic [4:0]  ex_rs1_addr,
    input  logic [4:0]  ex_rs2_addr,

    input  logic        ex_wr_en,
    input  logic [4:0]  ex_stage_rd_addr,
    input  logic [31:0] ex_alu_result,

    input  logic        mem_wr_en,
    input  logic        mem_is_load,
    input  logic [4:0]  mem_rd_addr,
    input  logic [31:0] ex_mem_alu_result,
    input  logic [31:0] mem_rdata,

    input  logic        wb_wr_en,
    input  logic [4:0]  wb_rd_addr,
    input  logic [31:0] wb_wr_data,

    input  logic [31:0] reg_rs1_data,
    input  logic [31:0] reg_rs2_data,

    output logic [31:0] fwd_rs1_data,
    output logic [31:0] fwd_rs2_data
);

    localparam logic [1:0] FWD_NONE = 2'b00;
    localparam logic [1:0] FWD_EX   = 2'b01;
    localparam logic [1:0] FWD_MEM  = 2'b10;
    localparam logic [1:0] FWD_WB   = 2'b11;

    logic [1:0] fwd_rs1_sel;
    logic [1:0] fwd_rs2_sel;

    always_comb begin
        if (ex_wr_en && ex_stage_rd_addr != 5'b0 && ex_stage_rd_addr == ex_rs1_addr)
            fwd_rs1_sel = FWD_EX;
        else if (mem_wr_en && mem_rd_addr != 5'b0 && mem_rd_addr == ex_rs1_addr)
            fwd_rs1_sel = FWD_MEM;
        else if (wb_wr_en && wb_rd_addr != 5'b0 && wb_rd_addr == ex_rs1_addr)
            fwd_rs1_sel = FWD_WB;
        else
            fwd_rs1_sel = FWD_NONE;
    end

    always_comb begin
        if (ex_wr_en && ex_stage_rd_addr != 5'b0 && ex_stage_rd_addr == ex_rs2_addr)
            fwd_rs2_sel = FWD_EX;
        else if (mem_wr_en && mem_rd_addr != 5'b0 && mem_rd_addr == ex_rs2_addr)
            fwd_rs2_sel = FWD_MEM;
        else if (wb_wr_en && wb_rd_addr != 5'b0 && wb_rd_addr == ex_rs2_addr)
            fwd_rs2_sel = FWD_WB;
        else
            fwd_rs2_sel = FWD_NONE;
    end

    always_comb begin
        case (fwd_rs1_sel)
            FWD_EX:  fwd_rs1_data = ex_alu_result;
            FWD_MEM: fwd_rs1_data = mem_is_load ? mem_rdata : ex_mem_alu_result;
            FWD_WB:  fwd_rs1_data = wb_wr_data;
            default: fwd_rs1_data = reg_rs1_data;
        endcase
    end

    always_comb begin
        case (fwd_rs2_sel)
            FWD_EX:  fwd_rs2_data = ex_alu_result;
            FWD_MEM: fwd_rs2_data = mem_is_load ? mem_rdata : ex_mem_alu_result;
            FWD_WB:  fwd_rs2_data = wb_wr_data;
            default: fwd_rs2_data = reg_rs2_data;
        endcase
    end

endmodule
