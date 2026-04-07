// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_TOP_H_
#define VERILATED_VTOP_TOP_H_  // guard

#include "verilated.h"
class Vtop_core;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_top final : public VerilatedModule {
  public:
    // CELLS
    Vtop_core* __PVT__u_core;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_OUT8(debug_wb_have,0,0);
    VL_OUT8(debug_wb_en,0,0);
    VL_OUT8(debug_wb_addr,4,0);
    CData/*0:0*/ __PVT__lsu_ren;
    CData/*0:0*/ __PVT__lsu_wen;
    CData/*3:0*/ __PVT__lsu_wmask;
    CData/*3:0*/ __Vfunc_wmask2len__3__mask;
    VL_OUT(pc,31,0);
    VL_OUT(instr,31,0);
    VL_OUT(debug_wb_pc,31,0);
    VL_OUT(debug_wb_instr,31,0);
    VL_OUT(debug_wb_data,31,0);
    IData/*31:0*/ __PVT__ifu_raddr;
    IData/*31:0*/ __PVT__ifu_rdata;
    IData/*31:0*/ __PVT__lsu_addr;
    IData/*31:0*/ __PVT__lsu_wdata;
    IData/*31:0*/ __PVT__lsu_rdata;
    IData/*31:0*/ __Vfunc_paddr_read__0__Vfuncout;
    IData/*31:0*/ __Vfunc_paddr_read__1__Vfuncout;
    IData/*31:0*/ __Vfunc_wmask2len__3__Vfuncout;
    IData/*31:0*/ __Vdly__ifu_rdata;
    IData/*31:0*/ __Vdly__lsu_rdata;
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
