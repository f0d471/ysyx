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
    VL_OUT8(debug_wb_ena,0,0);
    VL_OUT8(debug_wb_addr,4,0);
    VL_OUT(pc,31,0);
    VL_OUT(instr,31,0);
    VL_OUT(debug_wb_pc,31,0);
    VL_OUT(debug_wb_instr,31,0);
    VL_OUT(debug_wb_data,31,0);
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
