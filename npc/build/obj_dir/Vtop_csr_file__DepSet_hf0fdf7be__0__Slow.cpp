// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_csr_file.h"

VL_ATTR_COLD void Vtop_csr_file___stl_sequent__TOP__top__u_core__u_csr_file__0(Vtop_csr_file* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_csr_file___stl_sequent__TOP__top__u_core__u_csr_file__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__trap_mtvec = vlSelfRef.__PVT__mtvec;
    vlSelfRef.__PVT__trap_mepc = vlSelfRef.__PVT__mepc;
}

VL_ATTR_COLD void Vtop_csr_file___stl_sequent__TOP__top__u_core__u_csr_file__1(Vtop_csr_file* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_csr_file___stl_sequent__TOP__top__u_core__u_csr_file__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__csr_rdata = (((((((((0x300U == (IData)(vlSelfRef.__PVT__csr_raddr)) 
                                         | (0x305U 
                                            == (IData)(vlSelfRef.__PVT__csr_raddr))) 
                                        | (0x341U == (IData)(vlSelfRef.__PVT__csr_raddr))) 
                                       | (0x342U == (IData)(vlSelfRef.__PVT__csr_raddr))) 
                                      | (0xb00U == (IData)(vlSelfRef.__PVT__csr_raddr))) 
                                     | (0xb80U == (IData)(vlSelfRef.__PVT__csr_raddr))) 
                                    | (0xf11U == (IData)(vlSelfRef.__PVT__csr_raddr))) 
                                   | (0xf12U == (IData)(vlSelfRef.__PVT__csr_raddr)))
                                   ? ((0x300U == (IData)(vlSelfRef.__PVT__csr_raddr))
                                       ? vlSelfRef.__PVT__mstatus
                                       : ((0x305U == (IData)(vlSelfRef.__PVT__csr_raddr))
                                           ? vlSelfRef.__PVT__mtvec
                                           : ((0x341U 
                                               == (IData)(vlSelfRef.__PVT__csr_raddr))
                                               ? vlSelfRef.__PVT__mepc
                                               : ((0x342U 
                                                   == (IData)(vlSelfRef.__PVT__csr_raddr))
                                                   ? vlSelfRef.__PVT__mcause
                                                   : 
                                                  ((0xb00U 
                                                    == (IData)(vlSelfRef.__PVT__csr_raddr))
                                                    ? 
                                                   VL_SEL_IQII(64, vlSelfRef.__PVT__mcycle_cnt, 0U, 0x20U)
                                                    : 
                                                   ((0xb80U 
                                                     == (IData)(vlSelfRef.__PVT__csr_raddr))
                                                     ? 
                                                    VL_SEL_IQII(64, vlSelfRef.__PVT__mcycle_cnt, 0x20U, 0x20U)
                                                     : 
                                                    ((0xf11U 
                                                      == (IData)(vlSelfRef.__PVT__csr_raddr))
                                                      ? 0x79737978U
                                                      : 0x3d1c5U)))))))
                                   : 0U);
}

VL_ATTR_COLD void Vtop_csr_file___ctor_var_reset(Vtop_csr_file* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_csr_file___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__clk = 0;
    vlSelf->__PVT__rst = 0;
    vlSelf->__PVT__csr_raddr = 0;
    vlSelf->__PVT__csr_rdata = 0;
    vlSelf->__PVT__csr_wen = 0;
    vlSelf->__PVT__csr_waddr = 0;
    vlSelf->__PVT__csr_wdata = 0;
    vlSelf->__PVT__trap_valid = 0;
    vlSelf->__PVT__trap_pc = 0;
    vlSelf->__PVT__trap_cause = 0;
    vlSelf->__PVT__trap_mtvec = 0;
    vlSelf->__PVT__trap_mepc = 0;
    vlSelf->__PVT__mstatus = 0;
    vlSelf->__PVT__mtvec = 0;
    vlSelf->__PVT__mepc = 0;
    vlSelf->__PVT__mcause = 0;
    vlSelf->__PVT__mcycle_cnt = 0;
    vlSelf->__Vdly__mstatus = 0;
    vlSelf->__Vdly__mtvec = 0;
    vlSelf->__Vdly__mepc = 0;
    vlSelf->__Vdly__mcause = 0;
    vlSelf->__Vdly__mcycle_cnt = 0;
}
