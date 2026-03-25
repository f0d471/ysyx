// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_decode.h"

VL_INLINE_OPT void Vtop_decode___nba_sequent__TOP__top__u_core__u_decode__0(Vtop_decode* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_decode___nba_sequent__TOP__top__u_core__u_decode__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rd = (0x1fU & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 7U, 5U));
    vlSelfRef.__PVT__funct7 = (0x7fU & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 0x19U, 7U));
    vlSelfRef.__PVT__csr_addr_out = (0xfffU & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 0x14U, 0xcU));
    vlSelfRef.__PVT__rs1 = (0x1fU & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 0xfU, 5U));
    vlSelfRef.__PVT__rs2 = (0x1fU & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 0x14U, 5U));
    vlSelfRef.__PVT__is_ebreak = (0x100073U == vlSelfRef.__PVT__instr_in);
    vlSelfRef.__PVT__funct3 = (7U & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 0xcU, 3U));
    vlSelfRef.__PVT__opcode = (0x7fU & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 0U, 7U));
    vlSelfRef.__PVT__rd_addr_out = vlSelfRef.__PVT__rd;
    vlSelfRef.__PVT__funct7_out = vlSelfRef.__PVT__funct7;
    vlSelfRef.__PVT__inst_ebreak = vlSelfRef.__PVT__is_ebreak;
    vlSelfRef.__PVT__funct3_out = vlSelfRef.__PVT__funct3;
    vlSelfRef.__PVT__opcode_out = vlSelfRef.__PVT__opcode;
    vlSelfRef.__PVT__imm = ((((0x13U == (IData)(vlSelfRef.__PVT__opcode)) 
                              || (3U == (IData)(vlSelfRef.__PVT__opcode))) 
                             || (0x67U == (IData)(vlSelfRef.__PVT__opcode)))
                             ? VL_CONCAT_III(32,20,12, 
                                             (0xfffffU 
                                              & VL_REPLICATE_IOI(1,
                                                                 (1U 
                                                                  & VL_BITSEL_IIII(32, vlSelfRef.__PVT__instr_in, 0x1fU)), 0x14U)), 
                                             (0xfffU 
                                              & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 0x14U, 0xcU)))
                             : ((0x23U == (IData)(vlSelfRef.__PVT__opcode))
                                 ? VL_CONCAT_III(32,20,12, 
                                                 (0xfffffU 
                                                  & VL_REPLICATE_IOI(1,
                                                                     (1U 
                                                                      & VL_BITSEL_IIII(32, vlSelfRef.__PVT__instr_in, 0x1fU)), 0x14U)), 
                                                 VL_CONCAT_III(12,7,5, 
                                                               (0x7fU 
                                                                & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 0x19U, 7U)), 
                                                               (0x1fU 
                                                                & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 7U, 5U))))
                                 : ((0x63U == (IData)(vlSelfRef.__PVT__opcode))
                                     ? VL_CONCAT_III(32,20,12, 
                                                     (0xfffffU 
                                                      & VL_REPLICATE_IOI(1,
                                                                         (1U 
                                                                          & VL_BITSEL_IIII(32, vlSelfRef.__PVT__instr_in, 0x1fU)), 0x14U)), 
                                                     VL_CONCAT_III(12,1,11, 
                                                                   (1U 
                                                                    & VL_BITSEL_IIII(32, vlSelfRef.__PVT__instr_in, 7U)), 
                                                                   VL_CONCAT_III(11,6,5, 
                                                                                (0x3fU 
                                                                                & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 0x19U, 6U)), 
                                                                                VL_CONCAT_III(5,4,1, 
                                                                                (0xfU 
                                                                                & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 8U, 4U)), 0U))))
                                     : ((0x6fU == (IData)(vlSelfRef.__PVT__opcode))
                                         ? VL_CONCAT_III(32,12,20, 
                                                         (0xfffU 
                                                          & VL_REPLICATE_IOI(1,
                                                                             (1U 
                                                                              & VL_BITSEL_IIII(32, vlSelfRef.__PVT__instr_in, 0x1fU)), 0xcU)), 
                                                         VL_CONCAT_III(20,9,11, 
                                                                       VL_CONCAT_III(9,8,1, 
                                                                                (0xffU 
                                                                                & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 0xcU, 8U)), 
                                                                                (1U 
                                                                                & VL_BITSEL_IIII(32, vlSelfRef.__PVT__instr_in, 0x14U))), 
                                                                       VL_CONCAT_III(11,10,1, 
                                                                                (0x3ffU 
                                                                                & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 0x15U, 0xaU)), 0U)))
                                         : (((0x37U 
                                              == (IData)(vlSelfRef.__PVT__opcode)) 
                                             || (0x17U 
                                                 == (IData)(vlSelfRef.__PVT__opcode)))
                                             ? VL_CONCAT_III(32,20,12, 
                                                             (0xfffffU 
                                                              & VL_SEL_IIII(32, vlSelfRef.__PVT__instr_in, 0xcU, 0x14U)), 0U)
                                             : 0U)))));
    vlSelfRef.__PVT__is_system = (0x73U == (IData)(vlSelfRef.__PVT__opcode));
    vlSelfRef.__PVT__imm_out = vlSelfRef.__PVT__imm;
    vlSelfRef.__PVT__inst_ecall = (((IData)(vlSelfRef.__PVT__is_system) 
                                    & (0U == (IData)(vlSelfRef.__PVT__funct3))) 
                                   & (0U == (IData)(vlSelfRef.__PVT__csr_addr_out)));
    vlSelfRef.__PVT__inst_mret = (((IData)(vlSelfRef.__PVT__is_system) 
                                   & (0U == (IData)(vlSelfRef.__PVT__funct3))) 
                                  & (0x302U == (IData)(vlSelfRef.__PVT__csr_addr_out)));
    vlSelfRef.__PVT__inst_csrrw = ((IData)(vlSelfRef.__PVT__is_system) 
                                   & (1U == (IData)(vlSelfRef.__PVT__funct3)));
    vlSelfRef.__PVT__inst_csrrs = ((IData)(vlSelfRef.__PVT__is_system) 
                                   & (2U == (IData)(vlSelfRef.__PVT__funct3)));
    vlSelfRef.__PVT__rd_rs1_addr = 0U;
    vlSelfRef.__PVT__rd_rs2_addr = 0U;
    vlSelfRef.__PVT__op1_sel_out = 2U;
    vlSelfRef.__PVT__op2_sel_out = 0U;
    if (((((((((0x13U == (IData)(vlSelfRef.__PVT__opcode)) 
               | (0x33U == (IData)(vlSelfRef.__PVT__opcode))) 
              | (0x63U == (IData)(vlSelfRef.__PVT__opcode))) 
             | (0x23U == (IData)(vlSelfRef.__PVT__opcode))) 
            | (3U == (IData)(vlSelfRef.__PVT__opcode))) 
           | (0x6fU == (IData)(vlSelfRef.__PVT__opcode))) 
          | (0x67U == (IData)(vlSelfRef.__PVT__opcode))) 
         | (0x37U == (IData)(vlSelfRef.__PVT__opcode)))) {
        if ((0x13U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__rd_rs1_addr = vlSelfRef.__PVT__rs1;
            vlSelfRef.__PVT__rd_rs2_addr = 0U;
            vlSelfRef.__PVT__op1_sel_out = 0U;
            vlSelfRef.__PVT__op2_sel_out = 1U;
        } else if ((0x33U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__rd_rs1_addr = vlSelfRef.__PVT__rs1;
            vlSelfRef.__PVT__rd_rs2_addr = vlSelfRef.__PVT__rs2;
            vlSelfRef.__PVT__op1_sel_out = 0U;
            vlSelfRef.__PVT__op2_sel_out = 0U;
        } else if ((0x63U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__rd_rs1_addr = vlSelfRef.__PVT__rs1;
            vlSelfRef.__PVT__rd_rs2_addr = vlSelfRef.__PVT__rs2;
            vlSelfRef.__PVT__op1_sel_out = 0U;
            vlSelfRef.__PVT__op2_sel_out = 0U;
        } else if ((0x23U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__rd_rs1_addr = vlSelfRef.__PVT__rs1;
            vlSelfRef.__PVT__rd_rs2_addr = vlSelfRef.__PVT__rs2;
            vlSelfRef.__PVT__op1_sel_out = 0U;
            vlSelfRef.__PVT__op2_sel_out = 1U;
        } else if ((3U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__rd_rs1_addr = vlSelfRef.__PVT__rs1;
            vlSelfRef.__PVT__rd_rs2_addr = 0U;
            vlSelfRef.__PVT__op1_sel_out = 0U;
            vlSelfRef.__PVT__op2_sel_out = 1U;
        } else if ((0x6fU == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__rd_rs1_addr = 0U;
            vlSelfRef.__PVT__rd_rs2_addr = 0U;
            vlSelfRef.__PVT__op1_sel_out = 1U;
            vlSelfRef.__PVT__op2_sel_out = 2U;
        } else if ((0x67U == (IData)(vlSelfRef.__PVT__opcode))) {
            vlSelfRef.__PVT__rd_rs1_addr = vlSelfRef.__PVT__rs1;
            vlSelfRef.__PVT__rd_rs2_addr = 0U;
            vlSelfRef.__PVT__op1_sel_out = 1U;
            vlSelfRef.__PVT__op2_sel_out = 2U;
        } else {
            vlSelfRef.__PVT__rd_rs1_addr = 0U;
            vlSelfRef.__PVT__rd_rs2_addr = 0U;
            vlSelfRef.__PVT__op1_sel_out = 2U;
            vlSelfRef.__PVT__op2_sel_out = 1U;
        }
    } else if ((0x17U == (IData)(vlSelfRef.__PVT__opcode))) {
        vlSelfRef.__PVT__rd_rs1_addr = 0U;
        vlSelfRef.__PVT__rd_rs2_addr = 0U;
        vlSelfRef.__PVT__op1_sel_out = 1U;
        vlSelfRef.__PVT__op2_sel_out = 1U;
    } else if ((0x73U == (IData)(vlSelfRef.__PVT__opcode))) {
        if (vlSelfRef.__PVT__is_ebreak) {
            vlSelfRef.__PVT__rd_rs1_addr = 0xaU;
            vlSelfRef.__PVT__rd_rs2_addr = 0U;
            vlSelfRef.__PVT__op1_sel_out = 0U;
            vlSelfRef.__PVT__op2_sel_out = 0U;
        } else if (((IData)(vlSelfRef.__PVT__inst_csrrw) 
                    | (IData)(vlSelfRef.__PVT__inst_csrrs))) {
            vlSelfRef.__PVT__rd_rs1_addr = vlSelfRef.__PVT__rs1;
            vlSelfRef.__PVT__rd_rs2_addr = 0U;
            vlSelfRef.__PVT__op1_sel_out = 0U;
            vlSelfRef.__PVT__op2_sel_out = 0U;
        } else {
            vlSelfRef.__PVT__rd_rs1_addr = 0U;
            vlSelfRef.__PVT__rd_rs2_addr = 0U;
            vlSelfRef.__PVT__op1_sel_out = 2U;
            vlSelfRef.__PVT__op2_sel_out = 0U;
        }
    } else {
        vlSelfRef.__PVT__rd_rs1_addr = 0U;
        vlSelfRef.__PVT__rd_rs2_addr = 0U;
        vlSelfRef.__PVT__op1_sel_out = 2U;
        vlSelfRef.__PVT__op2_sel_out = 0U;
    }
}
