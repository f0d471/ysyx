// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_FETCH_H_
#define VERILATED_VTOP_FETCH_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_fetch final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst_n,0,0);
    VL_OUT8(__PVT__ifu_reqValid,0,0);
    VL_IN8(__PVT__ifu_respValid,0,0);
    VL_IN8(__PVT__flush,0,0);
    VL_OUT8(__PVT__ifu_valid,0,0);
    CData/*0:0*/ __PVT__state;
    CData/*0:0*/ __PVT__state_next;
    CData/*0:0*/ __Vdly__state;
    VL_IN(__PVT__pc_pointer,31,0);
    VL_OUT(__PVT__ifu_raddr,31,0);
    VL_IN(__PVT__ifu_rdata,31,0);
    VL_OUT(__PVT__instr_out,31,0);

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_fetch(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_fetch();
    VL_UNCOPYABLE(Vtop_fetch);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
