// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_pc_counter.h"

VL_INLINE_OPT void Vtop_pc_counter___nba_sequent__TOP__top__u_core__u_pc_counter__0(Vtop_pc_counter* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_pc_counter___nba_sequent__TOP__top__u_core__u_pc_counter__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__pc_pointer = vlSelfRef.__PVT__pc_pointer;
    vlSelfRef.__Vdly__pc_pointer = ((IData)(vlSelfRef.__PVT__rst_n)
                                     ? ((IData)(vlSelfRef.__PVT__jump_en)
                                         ? vlSelfRef.__PVT__jump_addr
                                         : ((IData)(vlSelfRef.__PVT__pc_hold)
                                             ? vlSelfRef.__PVT__pc_pointer
                                             : ((IData)(4U) 
                                                + vlSelfRef.__PVT__pc_pointer)))
                                     : 0x80000000U);
    vlSelfRef.__PVT__pc_pointer = vlSelfRef.__Vdly__pc_pointer;
    vlSelfRef.__PVT__pc = vlSelfRef.__PVT__pc_pointer;
}
