// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_EX2MEM_H_
#define VERILATED_VTOP_EX2MEM_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ex2mem final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__rd_addr_in,4,0);
    VL_IN8(__PVT__opcode_in,6,0);
    VL_IN8(__PVT__funct3_in,2,0);
    VL_OUT8(__PVT__rd_addr_out,4,0);
    VL_OUT8(__PVT__opcode_out,6,0);
    VL_OUT8(__PVT__funct3_out,2,0);
    VL_IN(__PVT__pc_in,31,0);
    VL_IN(__PVT__alu_result_in,31,0);
    VL_IN(__PVT__rs2_data_in,31,0);
    VL_OUT(__PVT__alu_result_out,31,0);
    VL_OUT(__PVT__rs2_data_out,31,0);

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_ex2mem(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_ex2mem();
    VL_UNCOPYABLE(Vtop_ex2mem);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
