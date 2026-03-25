// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_pc_counter.h"

VL_ATTR_COLD void Vtop_pc_counter___stl_sequent__TOP__top__u_core__u_pc_counter__0(Vtop_pc_counter* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_pc_counter___stl_sequent__TOP__top__u_core__u_pc_counter__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__pc = vlSelfRef.__PVT__pc_pointer;
}

VL_ATTR_COLD void Vtop_pc_counter___ctor_var_reset(Vtop_pc_counter* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_pc_counter___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__clk = 0;
    vlSelf->__PVT__rst_n = 0;
    vlSelf->__PVT__jump_en = 0;
    vlSelf->__PVT__jump_addr = 0;
    vlSelf->__PVT__pc_hold = 0;
    vlSelf->__PVT__pc = 0;
    vlSelf->__PVT__pc_pointer = 0;
    vlSelf->__Vdly__pc_pointer = 0;
}
