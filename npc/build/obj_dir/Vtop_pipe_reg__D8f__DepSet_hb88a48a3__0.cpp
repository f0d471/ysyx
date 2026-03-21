// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_pipe_reg__D8f.h"

VL_INLINE_OPT void Vtop_pipe_reg__D8f___nba_sequent__TOP__top__u_core__u_ex2mem__0(Vtop_pipe_reg__D8f* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_pipe_reg__D8f___nba_sequent__TOP__top__u_core__u_ex2mem__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__valid_q = vlSelfRef.__PVT__valid_q;
    VL_ASSIGN_W(143,vlSelfRef.__Vdly__data_q, vlSelfRef.__PVT__data_q);
    if ((1U & ((~ (IData)(vlSelfRef.__PVT__rst_n)) 
               | (IData)(vlSelfRef.__PVT__flush)))) {
        vlSelfRef.__Vdly__valid_q = 0U;
        VL_CONST_W_1X(143,vlSelfRef.__Vdly__data_q,0x00000000);
    } else if ((1U & (~ (IData)(vlSelfRef.__PVT__stall)))) {
        if (vlSelfRef.__PVT__up_ready) {
            vlSelfRef.__Vdly__valid_q = vlSelfRef.__PVT__up_valid;
            VL_ASSIGN_W(143,vlSelfRef.__Vdly__data_q, vlSelfRef.__PVT__up_data);
        }
    }
    vlSelfRef.__PVT__valid_q = vlSelfRef.__Vdly__valid_q;
    VL_ASSIGN_W(143,vlSelfRef.__PVT__data_q, vlSelfRef.__Vdly__data_q);
    vlSelfRef.__PVT__dn_valid = vlSelfRef.__PVT__valid_q;
    VL_ASSIGN_W(143,vlSelfRef.__PVT__dn_data, vlSelfRef.__PVT__data_q);
}

VL_INLINE_OPT void Vtop_pipe_reg__D8f___nba_comb__TOP__top__u_core__u_ex2mem__0(Vtop_pipe_reg__D8f* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_pipe_reg__D8f___nba_comb__TOP__top__u_core__u_ex2mem__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__up_ready = (1U & ((~ (IData)(vlSelfRef.__PVT__stall)) 
                                       & ((IData)(vlSelfRef.__PVT__dn_ready) 
                                          | (~ (IData)(vlSelfRef.__PVT__valid_q)))));
}
