// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_PC_COUNTER_H_
#define VERILATED_VTOP_PC_COUNTER_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_pc_counter final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst_n,0,0);
    VL_IN8(__PVT__jump_en,0,0);
    VL_IN8(__PVT__pc_hold,0,0);
    VL_IN(__PVT__jump_addr,31,0);
    VL_OUT(__PVT__pc,31,0);
    IData/*31:0*/ __PVT__pc_pointer;
    IData/*31:0*/ __Vdly__pc_pointer;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_pc_counter(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_pc_counter();
    VL_UNCOPYABLE(Vtop_pc_counter);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
