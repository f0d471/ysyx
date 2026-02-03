// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ex2mem.h"

VL_INLINE_OPT void Vtop_ex2mem___ico_sequent__TOP__top__u_ex2mem__0(Vtop_ex2mem* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ex2mem___ico_sequent__TOP__top__u_ex2mem__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__alu_result_out = vlSelfRef.__PVT__alu_result_in;
    vlSelfRef.__PVT__rs2_data_out = vlSelfRef.__PVT__rs2_data_in;
    vlSelfRef.__PVT__rd_addr_out = vlSelfRef.__PVT__rd_addr_in;
    vlSelfRef.__PVT__opcode_out = vlSelfRef.__PVT__opcode_in;
    vlSelfRef.__PVT__funct3_out = vlSelfRef.__PVT__funct3_in;
}

VL_INLINE_OPT void Vtop_ex2mem___nba_comb__TOP__top__u_ex2mem__0(Vtop_ex2mem* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ex2mem___nba_comb__TOP__top__u_ex2mem__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__alu_result_out = vlSelfRef.__PVT__alu_result_in;
    vlSelfRef.__PVT__rs2_data_out = vlSelfRef.__PVT__rs2_data_in;
    vlSelfRef.__PVT__rd_addr_out = vlSelfRef.__PVT__rd_addr_in;
    vlSelfRef.__PVT__opcode_out = vlSelfRef.__PVT__opcode_in;
    vlSelfRef.__PVT__funct3_out = vlSelfRef.__PVT__funct3_in;
}
