// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_if2id.h"

VL_ATTR_COLD void Vtop_if2id___stl_sequent__TOP__top__u_if2id__0(Vtop_if2id* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_if2id___stl_sequent__TOP__top__u_if2id__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__instr_addr_out = vlSelfRef.__PVT__instr_addr_in;
    vlSelfRef.__PVT__instr_out = vlSelfRef.__PVT__instr_in;
}

VL_ATTR_COLD void Vtop_if2id___ctor_var_reset(Vtop_if2id* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_if2id___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__instr_addr_in = 0;
    vlSelf->__PVT__instr_in = 0;
    vlSelf->__PVT__instr_addr_out = 0;
    vlSelf->__PVT__instr_out = 0;
}
