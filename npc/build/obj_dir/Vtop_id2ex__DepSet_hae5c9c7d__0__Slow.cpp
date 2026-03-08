// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_id2ex.h"

VL_ATTR_COLD void Vtop_id2ex___stl_sequent__TOP__top__u_id2ex__0(Vtop_id2ex* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_id2ex___stl_sequent__TOP__top__u_id2ex__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__instr_addr_out = vlSelfRef.__PVT__instr_addr_in;
    vlSelfRef.__PVT__instr_out = vlSelfRef.__PVT__instr_in;
    vlSelfRef.__PVT__rd_addr_out = vlSelfRef.__PVT__rd_addr_in;
    vlSelfRef.__PVT__imm_out = vlSelfRef.__PVT__imm_in;
    vlSelfRef.__PVT__opcode_out = vlSelfRef.__PVT__opcode_in;
    vlSelfRef.__PVT__funct3_out = vlSelfRef.__PVT__funct3_in;
    vlSelfRef.__PVT__funct7_out = vlSelfRef.__PVT__funct7_in;
    vlSelfRef.__PVT__rs1_data_out = vlSelfRef.__PVT__rs1_data_in;
    vlSelfRef.__PVT__rs2_data_out = vlSelfRef.__PVT__rs2_data_in;
    vlSelfRef.__PVT__inst_ebreak_out = vlSelfRef.__PVT__inst_ebreak_in;
    vlSelfRef.__PVT__csr_addr_out = vlSelfRef.__PVT__csr_addr_in;
    vlSelfRef.__PVT__inst_csrrw_out = vlSelfRef.__PVT__inst_csrrw_in;
    vlSelfRef.__PVT__inst_csrrs_out = vlSelfRef.__PVT__inst_csrrs_in;
    vlSelfRef.__PVT__inst_ecall_out = vlSelfRef.__PVT__inst_ecall_in;
    vlSelfRef.__PVT__inst_mret_out = vlSelfRef.__PVT__inst_mret_in;
    vlSelfRef.__PVT__op1_out = ((0U == (IData)(vlSelfRef.__PVT__op1_sel_in))
                                 ? vlSelfRef.__PVT__rs1_data_in
                                 : ((1U == (IData)(vlSelfRef.__PVT__op1_sel_in))
                                     ? vlSelfRef.__PVT__instr_addr_in
                                     : 0U));
    vlSelfRef.__PVT__op2_out = ((0U == (IData)(vlSelfRef.__PVT__op2_sel_in))
                                 ? vlSelfRef.__PVT__rs2_data_in
                                 : ((1U == (IData)(vlSelfRef.__PVT__op2_sel_in))
                                     ? vlSelfRef.__PVT__imm_in
                                     : ((2U == (IData)(vlSelfRef.__PVT__op2_sel_in))
                                         ? 4U : 0U)));
}

VL_ATTR_COLD void Vtop_id2ex___ctor_var_reset(Vtop_id2ex* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_id2ex___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__instr_addr_in = 0;
    vlSelf->__PVT__instr_in = 0;
    vlSelf->__PVT__rd_addr_in = 0;
    vlSelf->__PVT__imm_in = 0;
    vlSelf->__PVT__op1_sel_in = 0;
    vlSelf->__PVT__op2_sel_in = 0;
    vlSelf->__PVT__opcode_in = 0;
    vlSelf->__PVT__funct3_in = 0;
    vlSelf->__PVT__funct7_in = 0;
    vlSelf->__PVT__rs1_data_in = 0;
    vlSelf->__PVT__rs2_data_in = 0;
    vlSelf->__PVT__instr_addr_out = 0;
    vlSelf->__PVT__instr_out = 0;
    vlSelf->__PVT__op1_out = 0;
    vlSelf->__PVT__op2_out = 0;
    vlSelf->__PVT__rd_addr_out = 0;
    vlSelf->__PVT__imm_out = 0;
    vlSelf->__PVT__opcode_out = 0;
    vlSelf->__PVT__funct3_out = 0;
    vlSelf->__PVT__funct7_out = 0;
    vlSelf->__PVT__rs1_data_out = 0;
    vlSelf->__PVT__rs2_data_out = 0;
    vlSelf->__PVT__inst_ebreak_in = 0;
    vlSelf->__PVT__inst_ebreak_out = 0;
    vlSelf->__PVT__csr_addr_in = 0;
    vlSelf->__PVT__inst_csrrw_in = 0;
    vlSelf->__PVT__inst_csrrs_in = 0;
    vlSelf->__PVT__inst_ecall_in = 0;
    vlSelf->__PVT__inst_mret_in = 0;
    vlSelf->__PVT__csr_addr_out = 0;
    vlSelf->__PVT__inst_csrrw_out = 0;
    vlSelf->__PVT__inst_csrrs_out = 0;
    vlSelf->__PVT__inst_ecall_out = 0;
    vlSelf->__PVT__inst_mret_out = 0;
}
