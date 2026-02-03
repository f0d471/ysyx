// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_if2id.h"

VL_INLINE_OPT void Vtop_if2id___ico_sequent__TOP__top__u_if2id__0(Vtop_if2id* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_if2id___ico_sequent__TOP__top__u_if2id__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__instr_addr_out = vlSelfRef.__PVT__instr_addr_in;
    vlSelfRef.__PVT__instr_out = vlSelfRef.__PVT__instr_in;
}

VL_INLINE_OPT void Vtop_if2id___nba_sequent__TOP__top__u_if2id__0(Vtop_if2id* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_if2id___nba_sequent__TOP__top__u_if2id__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__instr_addr_out = vlSelfRef.__PVT__instr_addr_in;
    vlSelfRef.__PVT__instr_out = vlSelfRef.__PVT__instr_in;
}
