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
    vlSelfRef.__PVT__ifu_respReady = ((1U == (IData)(vlSelfRef.__PVT__state)) 
                                      & (~ (IData)(vlSelfRef.__PVT__flush)));
    vlSelfRef.__PVT__ifu_valid = ((2U == (IData)(vlSelfRef.__PVT__state)) 
                                  & (~ (IData)(vlSelfRef.__PVT__flush)));
    vlSelfRef.__PVT__instr_out = ((IData)(vlSelfRef.__PVT__ifu_valid)
                                   ? vlSelfRef.__PVT__instr_latch
                                   : 0x13U);
}

VL_ATTR_COLD void Vtop_fetch___stl_sequent__TOP__top__u_core__u_fetch__2(Vtop_fetch* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_fetch___stl_sequent__TOP__top__u_core__u_fetch__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__ifu_reqValid = (((0U == (IData)(vlSelfRef.__PVT__state)) 
                                      & (~ (IData)(vlSelfRef.__PVT__flush))) 
                                     & (~ (IData)(vlSelfRef.__PVT__stall)));
    vlSelfRef.__PVT__state_next = vlSelfRef.__PVT__state;
    if ((0U == (IData)(vlSelfRef.__PVT__state))) {
        if (vlSelfRef.__PVT__flush) {
            vlSelfRef.__PVT__state_next = 0U;
        } else if (((IData)(vlSelfRef.__PVT__ifu_reqValid) 
                    & (IData)(vlSelfRef.__PVT__ifu_reqReady))) {
            vlSelfRef.__PVT__state_next = 1U;
        }
    } else if ((1U == (IData)(vlSelfRef.__PVT__state))) {
        if (vlSelfRef.__PVT__flush) {
            vlSelfRef.__PVT__state_next = 0U;
        } else if (((IData)(vlSelfRef.__PVT__ifu_respValid) 
                    & (IData)(vlSelfRef.__PVT__ifu_respReady))) {
            vlSelfRef.__PVT__state_next = 2U;
        }
    } else if ((2U == (IData)(vlSelfRef.__PVT__state))) {
        if (vlSelfRef.__PVT__flush) {
            vlSelfRef.__PVT__state_next = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.__PVT__stall)))) {
            vlSelfRef.__PVT__state_next = 0U;
        }
    } else {
        vlSelfRef.__PVT__state_next = 0U;
    }
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
    vlSelf->__PVT__ifu_reqValid = 0;
    vlSelf->__PVT__ifu_reqReady = 0;
    vlSelf->__PVT__ifu_respValid = 0;
    vlSelf->__PVT__ifu_respReady = 0;
    vlSelf->__PVT__flush = 0;
    vlSelf->__PVT__stall = 0;
    vlSelf->__PVT__instr_out = 0;
    vlSelf->__PVT__ifu_valid = 0;
    vlSelf->__PVT__state = 0;
    vlSelf->__PVT__state_next = 0;
    vlSelf->__PVT__instr_latch = 0;
    vlSelf->__Vdly__state = 0;
    vlSelf->__Vdly__instr_latch = 0;
}
