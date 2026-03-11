// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_memory.h"

VL_ATTR_COLD void Vtop_memory___ctor_var_reset(Vtop_memory* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_memory___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__clk = 0;
    vlSelf->__PVT__rst_n = 0;
    vlSelf->__PVT__alu_result_in = 0;
    vlSelf->__PVT__rs2_data_in = 0;
    vlSelf->__PVT__opcode_in = 0;
    vlSelf->__PVT__funct3_in = 0;
    vlSelf->__PVT__mem_rdata_out = 0;
    vlSelf->__PVT__rdata_raw = 0;
    vlSelf->__Vfunc_paddr_read__0__Vfuncout = 0;
}
