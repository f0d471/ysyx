// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_csr_file.h"

VL_INLINE_OPT void Vtop_csr_file___nba_sequent__TOP__top__u_csr_file__0(Vtop_csr_file* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_csr_file___nba_sequent__TOP__top__u_csr_file__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__mcycle_cnt = vlSelfRef.__PVT__mcycle_cnt;
    vlSelfRef.__Vdly__mstatus = vlSelfRef.__PVT__mstatus;
    vlSelfRef.__Vdly__mcause = vlSelfRef.__PVT__mcause;
    vlSelfRef.__Vdly__mtvec = vlSelfRef.__PVT__mtvec;
    vlSelfRef.__Vdly__mepc = vlSelfRef.__PVT__mepc;
    if (vlSelfRef.__PVT__rst) {
        vlSelfRef.__Vdly__mstatus = 0x1800U;
        vlSelfRef.__Vdly__mtvec = 0U;
        vlSelfRef.__Vdly__mepc = 0U;
        vlSelfRef.__Vdly__mcause = 0U;
        vlSelfRef.__Vdly__mcycle_cnt = 0ULL;
    } else {
        vlSelfRef.__Vdly__mcycle_cnt = (1ULL + vlSelfRef.__PVT__mcycle_cnt);
        if (vlSelfRef.__PVT__trap_valid) {
            vlSelfRef.__Vdly__mepc = vlSelfRef.__PVT__trap_pc;
            vlSelfRef.__Vdly__mcause = vlSelfRef.__PVT__trap_cause;
        } else if (vlSelfRef.__PVT__csr_wen) {
            if ((0x300U == (IData)(vlSelfRef.__PVT__csr_waddr))) {
                vlSelfRef.__Vdly__mstatus = vlSelfRef.__PVT__csr_wdata;
            } else if ((0x305U == (IData)(vlSelfRef.__PVT__csr_waddr))) {
                vlSelfRef.__Vdly__mtvec = vlSelfRef.__PVT__csr_wdata;
            } else if ((0x341U == (IData)(vlSelfRef.__PVT__csr_waddr))) {
                vlSelfRef.__Vdly__mepc = vlSelfRef.__PVT__csr_wdata;
            } else if ((0x342U == (IData)(vlSelfRef.__PVT__csr_waddr))) {
                vlSelfRef.__Vdly__mcause = vlSelfRef.__PVT__csr_wdata;
            }
        }
    }
    vlSelfRef.__PVT__mstatus = vlSelfRef.__Vdly__mstatus;
    vlSelfRef.__PVT__mcause = vlSelfRef.__Vdly__mcause;
    vlSelfRef.__PVT__mcycle_cnt = vlSelfRef.__Vdly__mcycle_cnt;
    vlSelfRef.__PVT__mtvec = vlSelfRef.__Vdly__mtvec;
    vlSelfRef.__PVT__mepc = vlSelfRef.__Vdly__mepc;
    vlSelfRef.__PVT__trap_mtvec = vlSelfRef.__PVT__mtvec;
    vlSelfRef.__PVT__trap_mepc = vlSelfRef.__PVT__mepc;
}

VL_INLINE_OPT void Vtop_csr_file___nba_comb__TOP__top__u_csr_file__0(Vtop_csr_file* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_csr_file___nba_comb__TOP__top__u_csr_file__0\n"); );
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
