// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_execute.h"

VL_INLINE_OPT void Vtop_execute___nba_comb__TOP__top__u_core__u_execute__0(Vtop_execute* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_execute___nba_comb__TOP__top__u_core__u_execute__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__jump_flag_out = 0U;
    vlSelfRef.__PVT__jump_target_out = 0U;
    if (vlSelfRef.__PVT__inst_ecall) {
        vlSelfRef.__PVT__jump_flag_out = 1U;
        vlSelfRef.__PVT__jump_target_out = vlSelfRef.__PVT__trap_mtvec;
    } else if (vlSelfRef.__PVT__inst_mret) {
        vlSelfRef.__PVT__jump_flag_out = 1U;
        vlSelfRef.__PVT__jump_target_out = vlSelfRef.__PVT__trap_mepc;
    } else if ((0x6fU == (IData)(vlSelfRef.__PVT__opcode_in))) {
        vlSelfRef.__PVT__jump_flag_out = 1U;
        vlSelfRef.__PVT__jump_target_out = (vlSelfRef.__PVT__pc_in 
                                            + vlSelfRef.__PVT__imm_in);
    } else if ((0x67U == (IData)(vlSelfRef.__PVT__opcode_in))) {
        vlSelfRef.__PVT__jump_flag_out = 1U;
        vlSelfRef.__PVT__jump_target_out = (0xfffffffeU 
                                            & (vlSelfRef.__PVT__rs1_data_in 
                                               + vlSelfRef.__PVT__imm_in));
    } else if (vlSelfRef.__PVT__branch_taken) {
        vlSelfRef.__PVT__jump_flag_out = 1U;
        vlSelfRef.__PVT__jump_target_out = (vlSelfRef.__PVT__pc_in 
                                            + vlSelfRef.__PVT__imm_in);
    }
}

VL_INLINE_OPT void Vtop_execute___nba_comb__TOP__top__u_core__u_execute__1(Vtop_execute* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_execute___nba_comb__TOP__top__u_core__u_execute__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__csr_wdata = ((IData)(vlSelfRef.__PVT__inst_csrrw)
                                   ? vlSelfRef.__PVT__op1_in
                                   : (vlSelfRef.__PVT__csr_rdata 
                                      | vlSelfRef.__PVT__op1_in));
    vlSelfRef.__PVT__alu_result_out = (((IData)(vlSelfRef.__PVT__inst_csrrw) 
                                        | (IData)(vlSelfRef.__PVT__inst_csrrs))
                                        ? vlSelfRef.__PVT__csr_rdata
                                        : vlSelfRef.__PVT__alu_res);
}
