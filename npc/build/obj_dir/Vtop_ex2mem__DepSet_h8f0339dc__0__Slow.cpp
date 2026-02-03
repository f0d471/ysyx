// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_ex2mem.h"

VL_ATTR_COLD void Vtop_ex2mem___stl_sequent__TOP__top__u_ex2mem__0(Vtop_ex2mem* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ex2mem___stl_sequent__TOP__top__u_ex2mem__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__alu_result_out = vlSelfRef.__PVT__alu_result_in;
    vlSelfRef.__PVT__rs2_data_out = vlSelfRef.__PVT__rs2_data_in;
    vlSelfRef.__PVT__rd_addr_out = vlSelfRef.__PVT__rd_addr_in;
    vlSelfRef.__PVT__opcode_out = vlSelfRef.__PVT__opcode_in;
    vlSelfRef.__PVT__funct3_out = vlSelfRef.__PVT__funct3_in;
}

VL_ATTR_COLD void Vtop_ex2mem___ctor_var_reset(Vtop_ex2mem* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_ex2mem___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__pc_in = 0;
    vlSelf->__PVT__alu_result_in = 0;
    vlSelf->__PVT__rs2_data_in = 0;
    vlSelf->__PVT__rd_addr_in = 0;
    vlSelf->__PVT__opcode_in = 0;
    vlSelf->__PVT__funct3_in = 0;
    vlSelf->__PVT__alu_result_out = 0;
    vlSelf->__PVT__rs2_data_out = 0;
    vlSelf->__PVT__rd_addr_out = 0;
    vlSelf->__PVT__opcode_out = 0;
    vlSelf->__PVT__funct3_out = 0;
}
