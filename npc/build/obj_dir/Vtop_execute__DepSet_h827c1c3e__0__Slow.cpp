// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_execute.h"

VL_ATTR_COLD void Vtop_execute___eval_initial__TOP__top__u_execute(Vtop_execute* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_execute___eval_initial__TOP__top__u_execute\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__trap_cause = 0xbU;
}

VL_ATTR_COLD void Vtop_execute___stl_sequent__TOP__top__u_execute__1(Vtop_execute* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_execute___stl_sequent__TOP__top__u_execute__1\n"); );
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

VL_ATTR_COLD void Vtop_execute___ctor_var_reset(Vtop_execute* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_execute___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__pc_in = 0;
    vlSelf->__PVT__op1_in = 0;
    vlSelf->__PVT__op2_in = 0;
    vlSelf->__PVT__rs1_data_in = 0;
    vlSelf->__PVT__imm_in = 0;
    vlSelf->__PVT__opcode_in = 0;
    vlSelf->__PVT__funct3_in = 0;
    vlSelf->__PVT__funct7_in = 0;
    vlSelf->__PVT__alu_result_out = 0;
    vlSelf->__PVT__jump_flag_out = 0;
    vlSelf->__PVT__jump_target_out = 0;
    vlSelf->__PVT__inst_ebreak_in = 0;
    vlSelf->__PVT__csr_addr_in = 0;
    vlSelf->__PVT__inst_csrrw = 0;
    vlSelf->__PVT__inst_csrrs = 0;
    vlSelf->__PVT__inst_ecall = 0;
    vlSelf->__PVT__inst_mret = 0;
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
    vlSelf->__PVT__alu_res = 0;
    vlSelf->__PVT__branch_taken = 0;
}
