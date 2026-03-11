// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_FORWARD_UNIT_H_
#define VERILATED_VTOP_FORWARD_UNIT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_forward_unit final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__ex_rs1_addr,4,0);
    VL_IN8(__PVT__ex_rs2_addr,4,0);
    VL_IN8(__PVT__ex_stage_rd_addr,4,0);
    VL_IN8(__PVT__ex_stage_opcode,6,0);
    VL_IN8(__PVT__mem_rd_addr,4,0);
    VL_IN8(__PVT__mem_opcode,6,0);
    VL_IN8(__PVT__wb_rd_addr,4,0);
    VL_IN8(__PVT__wb_opcode,6,0);
    VL_OUT8(__PVT__fwd_rs1_sel,1,0);
    VL_OUT8(__PVT__fwd_rs2_sel,1,0);
    CData/*0:0*/ __Vfunc_writes_rd__0__Vfuncout;
    CData/*6:0*/ __Vfunc_writes_rd__0__op;
    CData/*0:0*/ __Vfunc_writes_rd__1__Vfuncout;
    CData/*6:0*/ __Vfunc_writes_rd__1__op;
    CData/*0:0*/ __Vfunc_writes_rd__2__Vfuncout;
    CData/*6:0*/ __Vfunc_writes_rd__2__op;
    CData/*0:0*/ __Vfunc_writes_rd__3__Vfuncout;
    CData/*6:0*/ __Vfunc_writes_rd__3__op;
    CData/*0:0*/ __Vfunc_writes_rd__4__Vfuncout;
    CData/*6:0*/ __Vfunc_writes_rd__4__op;
    CData/*0:0*/ __Vfunc_writes_rd__5__Vfuncout;
    CData/*6:0*/ __Vfunc_writes_rd__5__op;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_forward_unit(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_forward_unit();
    VL_UNCOPYABLE(Vtop_forward_unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
