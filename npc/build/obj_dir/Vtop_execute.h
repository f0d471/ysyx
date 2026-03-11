// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_EXECUTE_H_
#define VERILATED_VTOP_EXECUTE_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_execute final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__opcode_in,6,0);
    VL_IN8(__PVT__funct3_in,2,0);
    VL_IN8(__PVT__funct7_in,6,0);
    VL_OUT8(__PVT__jump_flag_out,0,0);
    VL_IN8(__PVT__inst_ebreak_in,0,0);
    VL_IN8(__PVT__inst_csrrw,0,0);
    VL_IN8(__PVT__inst_csrrs,0,0);
    VL_IN8(__PVT__inst_ecall,0,0);
    VL_IN8(__PVT__inst_mret,0,0);
    VL_OUT8(__PVT__csr_wen,0,0);
    VL_OUT8(__PVT__trap_valid,0,0);
    CData/*0:0*/ __PVT__branch_taken;
    VL_IN16(__PVT__csr_addr_in,11,0);
    VL_OUT16(__PVT__csr_raddr,11,0);
    VL_OUT16(__PVT__csr_waddr,11,0);
    VL_IN(__PVT__pc_in,31,0);
    VL_IN(__PVT__op1_in,31,0);
    VL_IN(__PVT__op2_in,31,0);
    VL_IN(__PVT__rs1_data_in,31,0);
    VL_IN(__PVT__imm_in,31,0);
    VL_OUT(__PVT__alu_result_out,31,0);
    VL_OUT(__PVT__jump_target_out,31,0);
    VL_IN(__PVT__csr_rdata,31,0);
    VL_OUT(__PVT__csr_wdata,31,0);
    VL_OUT(__PVT__trap_pc,31,0);
    VL_OUT(__PVT__trap_cause,31,0);
    VL_IN(__PVT__trap_mtvec,31,0);
    VL_IN(__PVT__trap_mepc,31,0);
    IData/*31:0*/ __PVT__alu_res;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_execute(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_execute();
    VL_UNCOPYABLE(Vtop_execute);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
