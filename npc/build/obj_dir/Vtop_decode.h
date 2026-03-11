// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_DECODE_H_
#define VERILATED_VTOP_DECODE_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_decode final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_OUT8(__PVT__rd_rs1_addr,4,0);
    VL_OUT8(__PVT__rd_rs2_addr,4,0);
    VL_OUT8(__PVT__rd_addr_out,4,0);
    VL_OUT8(__PVT__op1_sel_out,1,0);
    VL_OUT8(__PVT__op2_sel_out,1,0);
    VL_OUT8(__PVT__opcode_out,6,0);
    VL_OUT8(__PVT__funct3_out,2,0);
    VL_OUT8(__PVT__funct7_out,6,0);
    VL_OUT8(__PVT__inst_ebreak,0,0);
    VL_OUT8(__PVT__inst_csrrw,0,0);
    VL_OUT8(__PVT__inst_csrrs,0,0);
    VL_OUT8(__PVT__inst_ecall,0,0);
    VL_OUT8(__PVT__inst_mret,0,0);
    CData/*6:0*/ __PVT__opcode;
    CData/*4:0*/ __PVT__rd;
    CData/*2:0*/ __PVT__funct3;
    CData/*4:0*/ __PVT__rs1;
    CData/*4:0*/ __PVT__rs2;
    CData/*6:0*/ __PVT__funct7;
    CData/*0:0*/ __PVT__is_ebreak;
    CData/*0:0*/ __PVT__is_system;
    VL_OUT16(__PVT__csr_addr_out,11,0);
    VL_IN(__PVT__instr_addr_in,31,0);
    VL_IN(__PVT__instr_in,31,0);
    VL_OUT(__PVT__imm_out,31,0);
    IData/*31:0*/ __PVT__imm;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_decode(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_decode();
    VL_UNCOPYABLE(Vtop_decode);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
