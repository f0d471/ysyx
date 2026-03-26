// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_MEMORY_H_
#define VERILATED_VTOP_MEMORY_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_memory final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst_n,0,0);
    VL_IN8(__PVT__valid_in,0,0);
    VL_IN8(__PVT__opcode_in,6,0);
    VL_IN8(__PVT__funct3_in,2,0);
    VL_OUT8(__PVT__lsu_ren,0,0);
    VL_OUT8(__PVT__lsu_wen,0,0);
    VL_OUT8(__PVT__lsu_wmask,3,0);
    VL_OUT8(__PVT__lsu_reqValid,0,0);
    VL_IN8(__PVT__lsu_respValid,0,0);
    VL_OUT8(__PVT__lsu_busy,0,0);
    CData/*0:0*/ __PVT__is_load;
    CData/*0:0*/ __PVT__is_store;
    CData/*0:0*/ __PVT__is_memop;
    CData/*0:0*/ __PVT__state;
    CData/*0:0*/ __PVT__state_next;
    CData/*0:0*/ __Vdly__state;
    VL_IN(__PVT__alu_result_in,31,0);
    VL_IN(__PVT__rs2_data_in,31,0);
    VL_OUT(__PVT__lsu_addr,31,0);
    VL_IN(__PVT__lsu_rdata,31,0);
    VL_OUT(__PVT__lsu_wdata,31,0);
    VL_OUT(__PVT__mem_rdata_out,31,0);

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_memory(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_memory();
    VL_UNCOPYABLE(Vtop_memory);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
