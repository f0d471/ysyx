// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_TOP_H_
#define VERILATED_VTOP_TOP_H_  // guard

#include "verilated.h"
class Vtop_decode;
class Vtop_ex2mem;
class Vtop_execute;
class Vtop_fetch;
class Vtop_id2ex;
class Vtop_if2id;
class Vtop_mem2wb;
class Vtop_memory;
class Vtop_pc_counter;
class Vtop_reg_file;
class Vtop_writeback;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_top final : public VerilatedModule {
  public:
    // CELLS
    Vtop_pc_counter* __PVT__u_pc_counter;
    Vtop_fetch* __PVT__u_fetch;
    Vtop_if2id* __PVT__u_if2id;
    Vtop_decode* __PVT__u_decode;
    Vtop_reg_file* __PVT__u_reg_file;
    Vtop_id2ex* __PVT__u_id2ex;
    Vtop_execute* __PVT__u_execute;
    Vtop_ex2mem* __PVT__u_ex2mem;
    Vtop_memory* __PVT__u_memory;
    Vtop_mem2wb* __PVT__u_mem2wb;
    Vtop_writeback* __PVT__u_writeback;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    CData/*4:0*/ __PVT__decode_rs1_addr;
    CData/*4:0*/ __PVT__decode_rs2_addr;
    CData/*4:0*/ __PVT__decode_rd_addr;
    CData/*1:0*/ __PVT__decode_op1_sel;
    CData/*1:0*/ __PVT__decode_op2_sel;
    CData/*6:0*/ __PVT__decode_opcode;
    CData/*2:0*/ __PVT__decode_funct3;
    CData/*6:0*/ __PVT__decode_funct7;
    CData/*4:0*/ __PVT__id_rd_addr_out;
    CData/*6:0*/ __PVT__id_opcode_out;
    CData/*2:0*/ __PVT__id_funct3_out;
    CData/*6:0*/ __PVT__id_funct7_out;
    CData/*0:0*/ __PVT__ex_jump_flag;
    CData/*4:0*/ __PVT__ex_rd_addr;
    CData/*6:0*/ __PVT__ex_opcode;
    CData/*2:0*/ __PVT__ex_funct3;
    CData/*4:0*/ __PVT__mem_rd_addr;
    CData/*6:0*/ __PVT__mem_opcode;
    CData/*0:0*/ __PVT__wb_wr_en;
    CData/*4:0*/ __PVT__wb_wr_addr;
    CData/*0:0*/ __PVT__inst_ebreak;
    CData/*0:0*/ __PVT__inst_ebreak_out;
    VL_OUT(pc,31,0);
    VL_OUT(instr,31,0);
    VL_OUT(debug_x10,31,0);
    IData/*31:0*/ __PVT__instr_addr_out;
    IData/*31:0*/ __PVT__instr_out;
    IData/*31:0*/ __PVT__decode_imm;
    IData/*31:0*/ __PVT__reg_rs1_data;
    IData/*31:0*/ __PVT__reg_rs2_data;
    IData/*31:0*/ __PVT__id_instr_addr_out;
    IData/*31:0*/ __PVT__id_instr_out;
    IData/*31:0*/ __PVT__id_op1_out;
    IData/*31:0*/ __PVT__id_op2_out;
    IData/*31:0*/ __PVT__id_imm_out;
    IData/*31:0*/ __PVT__id_rs1_data;
    IData/*31:0*/ __PVT__id_rs2_data;
    IData/*31:0*/ __PVT__ex_alu_result;
    IData/*31:0*/ __PVT__ex_jump_target;
    IData/*31:0*/ __PVT__ex_alu_result_out;
    IData/*31:0*/ __PVT__ex_rs2_data;
    IData/*31:0*/ __PVT__mem_rdata;
    IData/*31:0*/ __PVT__mem_alu_result;
    IData/*31:0*/ __PVT__mem_rdata_out;
    IData/*31:0*/ __PVT__wb_wr_data;
    VL_OUT(regs[16],31,0);

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_top(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_top();
    VL_UNCOPYABLE(Vtop_top);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
