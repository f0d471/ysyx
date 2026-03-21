// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_pipe_reg__D40.h"

VL_INLINE_OPT void Vtop_pipe_reg__D40___nba_sequent__TOP__top__u_core__u_if2id__0(Vtop_pipe_reg__D40* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_pipe_reg__D40___nba_sequent__TOP__top__u_core__u_if2id__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__valid_q = vlSelfRef.__PVT__valid_q;
    vlSelfRef.__Vdly__data_q = vlSelfRef.__PVT__data_q;
    if ((1U & ((~ (IData)(vlSelfRef.__PVT__rst_n)) 
               | (IData)(vlSelfRef.__PVT__flush)))) {
        vlSelfRef.__Vdly__valid_q = 0U;
        vlSelfRef.__Vdly__data_q = 0ULL;
    } else if ((1U & (~ (IData)(vlSelfRef.__PVT__stall)))) {
        if (vlSelfRef.__PVT__up_ready) {
            vlSelfRef.__Vdly__valid_q = vlSelfRef.__PVT__up_valid;
            vlSelfRef.__Vdly__data_q = vlSelfRef.__PVT__up_data;
        }
    }
    vlSelfRef.__PVT__valid_q = vlSelfRef.__Vdly__valid_q;
    vlSelfRef.__PVT__data_q = vlSelfRef.__Vdly__data_q;
    vlSelfRef.__PVT__dn_valid = vlSelfRef.__PVT__valid_q;
    vlSelfRef.__PVT__dn_data = vlSelfRef.__PVT__data_q;
}

VL_INLINE_OPT void Vtop_pipe_reg__D40___nba_comb__TOP__top__u_core__u_if2id__0(Vtop_pipe_reg__D40* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_pipe_reg__D40___nba_comb__TOP__top__u_core__u_if2id__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__up_ready = (1U & ((~ (IData)(vlSelfRef.__PVT__stall)) 
                                       & ((IData)(vlSelfRef.__PVT__dn_ready) 
                                          | (~ (IData)(vlSelfRef.__PVT__valid_q)))));
}
