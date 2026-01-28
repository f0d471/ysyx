// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop___024unit;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    CData/*0:0*/ top__DOT__ex_jump_flag;
    CData/*4:0*/ top__DOT__id_rs1_addr;
    CData/*4:0*/ top__DOT__id_rs2_addr;
    CData/*4:0*/ top__DOT__ex_rd_addr;
    CData/*6:0*/ top__DOT__ex_opcode;
    CData/*2:0*/ top__DOT__ex_funct3;
    CData/*6:0*/ top__DOT__ex_funct7;
    CData/*4:0*/ top__DOT__mem_rd_addr;
    CData/*6:0*/ top__DOT__mem_opcode;
    CData/*2:0*/ top__DOT__mem_funct3;
    CData/*4:0*/ top__DOT__wb_rd_addr;
    CData/*6:0*/ top__DOT__wb_opcode;
    CData/*0:0*/ top__DOT__wb_wr_en;
    CData/*0:0*/ top__DOT__u_execute__DOT__branch_taken;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ top__DOT__ex_jump_target;
    IData/*31:0*/ top__DOT__pc_pointer;
    IData/*31:0*/ top__DOT__instruction;
    IData/*31:0*/ top__DOT__id_pc;
    IData/*31:0*/ top__DOT__id_instr;
    IData/*31:0*/ top__DOT__id_rs1_data;
    IData/*31:0*/ top__DOT__id_rs2_data;
    IData/*31:0*/ top__DOT__id_op1;
    IData/*31:0*/ top__DOT__id_op2;
    IData/*31:0*/ top__DOT__ex_pc;
    IData/*31:0*/ top__DOT__ex_instr;
    IData/*31:0*/ top__DOT__ex_op1;
    IData/*31:0*/ top__DOT__ex_op2;
    IData/*31:0*/ top__DOT__ex_rs1_data;
    IData/*31:0*/ top__DOT__ex_rs2_data;
    IData/*31:0*/ top__DOT__ex_imm;
    IData/*31:0*/ top__DOT__mem_pc;
    IData/*31:0*/ top__DOT__mem_alu_result;
    IData/*31:0*/ top__DOT__mem_rs2_data;
    IData/*31:0*/ top__DOT__mem_mem_rdata;
    IData/*31:0*/ top__DOT__wb_pc;
    IData/*31:0*/ top__DOT__wb_alu_result;
    IData/*31:0*/ top__DOT__wb_mem_rdata;
    IData/*31:0*/ top__DOT__wb_wr_data;
    IData/*31:0*/ top__DOT__u_register__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ top__DOT__u_decode__DOT__imm;
    IData/*31:0*/ top__DOT__u_execute__DOT__alu_res;
    IData/*31:0*/ top__DOT__u_memory__DOT__rdata_raw;
    IData/*31:0*/ __Vfunc_paddr_read__0__Vfuncout;
    IData/*31:0*/ __Vfunc_paddr_read__1__Vfuncout;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 16> top__DOT__u_register__DOT__rf;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
