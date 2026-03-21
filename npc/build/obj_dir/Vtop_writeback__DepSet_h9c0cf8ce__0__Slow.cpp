// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_writeback.h"

VL_ATTR_COLD void Vtop_writeback___stl_sequent__TOP__top__u_core__u_writeback__0(Vtop_writeback* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_writeback___stl_sequent__TOP__top__u_core__u_writeback__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__wb_addr = vlSelfRef.__PVT__rd_addr_in;
    vlSelfRef.__PVT__wb_en = 0U;
    vlSelfRef.__PVT__wb_data = 0U;
    if ((3U == (IData)(vlSelfRef.__PVT__opcode_in))) {
        vlSelfRef.__PVT__wb_en = 1U;
        vlSelfRef.__PVT__wb_data = vlSelfRef.__PVT__mem_rdata_in;
    } else if ((((((((0x13U == (IData)(vlSelfRef.__PVT__opcode_in)) 
                     || (0x33U == (IData)(vlSelfRef.__PVT__opcode_in))) 
                    || (0x37U == (IData)(vlSelfRef.__PVT__opcode_in))) 
                   || (0x17U == (IData)(vlSelfRef.__PVT__opcode_in))) 
                  || (0x6fU == (IData)(vlSelfRef.__PVT__opcode_in))) 
                 || (0x67U == (IData)(vlSelfRef.__PVT__opcode_in))) 
                || (0x73U == (IData)(vlSelfRef.__PVT__opcode_in)))) {
        vlSelfRef.__PVT__wb_en = 1U;
        vlSelfRef.__PVT__wb_data = vlSelfRef.__PVT__alu_result_in;
    } else {
        vlSelfRef.__PVT__wb_en = 0U;
        vlSelfRef.__PVT__wb_data = 0U;
    }
}

VL_ATTR_COLD void Vtop_writeback___ctor_var_reset(Vtop_writeback* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_writeback___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__alu_result_in = 0;
    vlSelf->__PVT__mem_rdata_in = 0;
    vlSelf->__PVT__opcode_in = 0;
    vlSelf->__PVT__rd_addr_in = 0;
    vlSelf->__PVT__wb_en = 0;
    vlSelf->__PVT__wb_addr = 0;
    vlSelf->__PVT__wb_data = 0;
}
