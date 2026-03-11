// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_CSR_FILE_H_
#define VERILATED_VTOP_CSR_FILE_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_csr_file final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst,0,0);
    VL_IN8(__PVT__csr_wen,0,0);
    VL_IN8(__PVT__trap_valid,0,0);
    VL_IN16(__PVT__csr_raddr,11,0);
    VL_IN16(__PVT__csr_waddr,11,0);
    VL_OUT(__PVT__csr_rdata,31,0);
    VL_IN(__PVT__csr_wdata,31,0);
    VL_IN(__PVT__trap_pc,31,0);
    VL_IN(__PVT__trap_cause,31,0);
    VL_OUT(__PVT__trap_mtvec,31,0);
    VL_OUT(__PVT__trap_mepc,31,0);
    IData/*31:0*/ __PVT__mstatus;
    IData/*31:0*/ __PVT__mtvec;
    IData/*31:0*/ __PVT__mepc;
    IData/*31:0*/ __PVT__mcause;
    IData/*31:0*/ __Vdly__mstatus;
    IData/*31:0*/ __Vdly__mtvec;
    IData/*31:0*/ __Vdly__mepc;
    IData/*31:0*/ __Vdly__mcause;
    QData/*63:0*/ __PVT__mcycle_cnt;
    QData/*63:0*/ __Vdly__mcycle_cnt;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_csr_file(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_csr_file();
    VL_UNCOPYABLE(Vtop_csr_file);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
