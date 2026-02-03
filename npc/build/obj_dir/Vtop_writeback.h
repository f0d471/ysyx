// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_WRITEBACK_H_
#define VERILATED_VTOP_WRITEBACK_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_writeback final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__opcode_in,6,0);
    VL_IN8(__PVT__rd_addr_in,4,0);
    VL_OUT8(__PVT__wb_en,0,0);
    VL_OUT8(__PVT__wb_addr,4,0);
    VL_IN(__PVT__alu_result_in,31,0);
    VL_IN(__PVT__mem_rdata_in,31,0);
    VL_OUT(__PVT__wb_data,31,0);

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_writeback(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_writeback();
    VL_UNCOPYABLE(Vtop_writeback);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
