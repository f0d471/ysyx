// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_ID2EX_H_
#define VERILATED_VTOP_ID2EX_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_id2ex final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__rd_addr_in,4,0);
    VL_IN8(__PVT__op1_sel_in,1,0);
    VL_IN8(__PVT__op2_sel_in,1,0);
    VL_IN8(__PVT__opcode_in,6,0);
    VL_IN8(__PVT__funct3_in,2,0);
    VL_IN8(__PVT__funct7_in,6,0);
    VL_OUT8(__PVT__rd_addr_out,4,0);
    VL_OUT8(__PVT__opcode_out,6,0);
    VL_OUT8(__PVT__funct3_out,2,0);
    VL_OUT8(__PVT__funct7_out,6,0);
    VL_IN8(__PVT__inst_ebreak_in,0,0);
    VL_OUT8(__PVT__inst_ebreak_out,0,0);
    VL_IN(__PVT__instr_addr_in,31,0);
    VL_IN(__PVT__instr_in,31,0);
    VL_IN(__PVT__imm_in,31,0);
    VL_IN(__PVT__rs1_data_in,31,0);
    VL_IN(__PVT__rs2_data_in,31,0);
    VL_OUT(__PVT__instr_addr_out,31,0);
    VL_OUT(__PVT__instr_out,31,0);
    VL_OUT(__PVT__op1_out,31,0);
    VL_OUT(__PVT__op2_out,31,0);
    VL_OUT(__PVT__imm_out,31,0);
    VL_OUT(__PVT__rs1_data_out,31,0);
    VL_OUT(__PVT__rs2_data_out,31,0);

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_id2ex(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_id2ex();
    VL_UNCOPYABLE(Vtop_id2ex);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
