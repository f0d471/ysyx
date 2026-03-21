// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_hazard_unit.h"

VL_ATTR_COLD void Vtop_hazard_unit___stl_sequent__TOP__top__u_core__u_hazard__0(Vtop_hazard_unit* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_hazard_unit___stl_sequent__TOP__top__u_core__u_hazard__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__ex_is_load = (3U == (IData)(vlSelfRef.__PVT__ex_opcode));
}

VL_ATTR_COLD void Vtop_hazard_unit___stl_sequent__TOP__top__u_core__u_hazard__1(Vtop_hazard_unit* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_hazard_unit___stl_sequent__TOP__top__u_core__u_hazard__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rs1_hazard = ((0U != (IData)(vlSelfRef.__PVT__ex_rd_addr)) 
                                   & ((IData)(vlSelfRef.__PVT__ex_rd_addr) 
                                      == (IData)(vlSelfRef.__PVT__id_rs1_addr)));
    vlSelfRef.__PVT__rs2_hazard = ((0U != (IData)(vlSelfRef.__PVT__ex_rd_addr)) 
                                   & ((IData)(vlSelfRef.__PVT__ex_rd_addr) 
                                      == (IData)(vlSelfRef.__PVT__id_rs2_addr)));
    vlSelfRef.__PVT__stall = ((IData)(vlSelfRef.__PVT__ex_is_load) 
                              & ((IData)(vlSelfRef.__PVT__rs1_hazard) 
                                 | (IData)(vlSelfRef.__PVT__rs2_hazard)));
}

VL_ATTR_COLD void Vtop_hazard_unit___ctor_var_reset(Vtop_hazard_unit* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_hazard_unit___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__ex_opcode = 0;
    vlSelf->__PVT__ex_rd_addr = 0;
    vlSelf->__PVT__id_rs1_addr = 0;
    vlSelf->__PVT__id_rs2_addr = 0;
    vlSelf->__PVT__stall = 0;
    vlSelf->__PVT__ex_is_load = 0;
    vlSelf->__PVT__rs1_hazard = 0;
    vlSelf->__PVT__rs2_hazard = 0;
}
