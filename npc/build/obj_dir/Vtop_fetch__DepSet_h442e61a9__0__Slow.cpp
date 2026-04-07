// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_fetch.h"

VL_ATTR_COLD void Vtop_fetch___stl_sequent__TOP__top__u_core__u_fetch__0(Vtop_fetch* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_fetch___stl_sequent__TOP__top__u_core__u_fetch__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__ifu_raddr = vlSelfRef.__PVT__pc_pointer;
}

VL_ATTR_COLD void Vtop_fetch___stl_sequent__TOP__top__u_core__u_fetch__1(Vtop_fetch* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_fetch___stl_sequent__TOP__top__u_core__u_fetch__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__state_next = ((1U & (~ (IData)(vlSelfRef.__PVT__state))) 
                                   && (1U & (~ (IData)(vlSelfRef.__PVT__flush))));
    vlSelfRef.__PVT__ifu_valid = ((IData)(vlSelfRef.__PVT__state) 
                                  & (~ (IData)(vlSelfRef.__PVT__flush)));
    vlSelfRef.__PVT__instr_out = ((IData)(vlSelfRef.__PVT__ifu_valid)
                                   ? vlSelfRef.__PVT__ifu_rdata
                                   : 0x13U);
}

VL_ATTR_COLD void Vtop_fetch___ctor_var_reset(Vtop_fetch* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_fetch___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__clk = 0;
    vlSelf->__PVT__rst_n = 0;
    vlSelf->__PVT__pc_pointer = 0;
    vlSelf->__PVT__ifu_raddr = 0;
    vlSelf->__PVT__ifu_rdata = 0;
    vlSelf->__PVT__flush = 0;
    vlSelf->__PVT__instr_out = 0;
    vlSelf->__PVT__ifu_valid = 0;
    vlSelf->__PVT__state = 0;
    vlSelf->__PVT__state_next = 0;
    vlSelf->__Vdly__state = 0;
}
