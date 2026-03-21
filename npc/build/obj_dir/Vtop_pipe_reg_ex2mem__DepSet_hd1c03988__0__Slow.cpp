// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_pipe_reg_ex2mem.h"

VL_ATTR_COLD void Vtop_pipe_reg_ex2mem___stl_sequent__TOP__top__u_core__u_ex2mem__0(Vtop_pipe_reg_ex2mem* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_pipe_reg_ex2mem___stl_sequent__TOP__top__u_core__u_ex2mem__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__dn_valid = vlSelfRef.__PVT__valid_q;
    VL_ASSIGN_W(143,vlSelfRef.__PVT__dn_data, vlSelfRef.__PVT__data_q);
}

VL_ATTR_COLD void Vtop_pipe_reg_ex2mem___stl_sequent__TOP__top__u_core__u_ex2mem__1(Vtop_pipe_reg_ex2mem* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_pipe_reg_ex2mem___stl_sequent__TOP__top__u_core__u_ex2mem__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__up_ready = (1U & ((IData)(vlSelfRef.__PVT__dn_ready) 
                                       | (~ (IData)(vlSelfRef.__PVT__valid_q))));
}

VL_ATTR_COLD void Vtop_pipe_reg_ex2mem___ctor_var_reset(Vtop_pipe_reg_ex2mem* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_pipe_reg_ex2mem___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__clk = 0;
    vlSelf->__PVT__rst_n = 0;
    vlSelf->__PVT__flush = 0;
    vlSelf->__PVT__up_valid = 0;
    vlSelf->__PVT__up_ready = 0;
    VL_ZERO_RESET_W(143, vlSelf->__PVT__up_data);
    vlSelf->__PVT__dn_valid = 0;
    vlSelf->__PVT__dn_ready = 0;
    VL_ZERO_RESET_W(143, vlSelf->__PVT__dn_data);
    VL_ZERO_RESET_W(143, vlSelf->__PVT__data_q);
    vlSelf->__PVT__valid_q = 0;
    vlSelf->__Vdly__valid_q = 0;
    VL_ZERO_RESET_W(143, vlSelf->__Vdly__data_q);
}
