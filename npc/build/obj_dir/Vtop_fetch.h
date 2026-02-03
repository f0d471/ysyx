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
    VL_IN(__PVT__pc_pointer,31,0);
    VL_OUT(__PVT__instr_out,31,0);
    IData/*31:0*/ __Vfunc_paddr_read__0__Vfuncout;

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
