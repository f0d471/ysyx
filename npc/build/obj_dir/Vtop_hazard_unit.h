// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_HAZARD_UNIT_H_
#define VERILATED_VTOP_HAZARD_UNIT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_hazard_unit final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__ex_opcode,6,0);
    VL_IN8(__PVT__ex_rd_addr,4,0);
    VL_IN8(__PVT__id_rs1_addr,4,0);
    VL_IN8(__PVT__id_rs2_addr,4,0);
    VL_OUT8(__PVT__stall,0,0);
    CData/*0:0*/ __PVT__ex_is_load;
    CData/*0:0*/ __PVT__rs1_hazard;
    CData/*0:0*/ __PVT__rs2_hazard;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_hazard_unit(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_hazard_unit();
    VL_UNCOPYABLE(Vtop_hazard_unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
