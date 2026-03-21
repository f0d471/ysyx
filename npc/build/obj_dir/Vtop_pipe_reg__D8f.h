// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_PIPE_REG__D8F_H_
#define VERILATED_VTOP_PIPE_REG__D8F_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_pipe_reg__D8f final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst_n,0,0);
    VL_IN8(__PVT__flush,0,0);
    VL_IN8(__PVT__stall,0,0);
    VL_IN8(__PVT__up_valid,0,0);
    VL_OUT8(__PVT__up_ready,0,0);
    VL_OUT8(__PVT__dn_valid,0,0);
    VL_IN8(__PVT__dn_ready,0,0);
    CData/*0:0*/ __PVT__valid_q;
    CData/*0:0*/ __Vdly__valid_q;
    VL_INW(__PVT__up_data,142,0,5);
    VL_OUTW(__PVT__dn_data,142,0,5);
    VlWide<5>/*142:0*/ __PVT__data_q;
    VlWide<5>/*142:0*/ __Vdly__data_q;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_pipe_reg__D8f(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_pipe_reg__D8f();
    VL_UNCOPYABLE(Vtop_pipe_reg__D8f);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
