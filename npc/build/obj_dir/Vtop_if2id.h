// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_IF2ID_H_
#define VERILATED_VTOP_IF2ID_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_if2id final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN(__PVT__instr_addr_in,31,0);
    VL_IN(__PVT__instr_in,31,0);
    VL_OUT(__PVT__instr_addr_out,31,0);
    VL_OUT(__PVT__instr_out,31,0);

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_if2id(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_if2id();
    VL_UNCOPYABLE(Vtop_if2id);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
