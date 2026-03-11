module hazard_unit (
    input  logic [6:0] ex_opcode,
    input  logic [4:0] ex_rd_addr,
    input  logic [4:0] id_rs1_addr,
    input  logic [4:0] id_rs2_addr,
    output logic stall
);
    wire ex_is_load = (ex_opcode == 7'b0000011);
    wire rs1_hazard = (ex_rd_addr != 5'b0) && (ex_rd_addr == id_rs1_addr);
    wire rs2_hazard = (ex_rd_addr != 5'b0) && (ex_rd_addr == id_rs2_addr);
    assign stall = ex_is_load && (rs1_hazard || rs2_hazard);
endmodule