// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_execute.h"

void Vtop___024unit____Vdpiimwrap_trap_TOP____024unit(IData/*31:0*/ code, IData/*31:0*/ pc);

VL_INLINE_OPT void Vtop_execute___ico_sequent__TOP__top__u_execute__0(Vtop_execute* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_execute___ico_sequent__TOP__top__u_execute__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__inst_ebreak_in) {
        Vtop___024unit____Vdpiimwrap_trap_TOP____024unit(vlSelfRef.__PVT__op1_in, vlSelfRef.__PVT__pc_in);
    }
    vlSelfRef.__PVT__branch_taken = ((0x63U == (IData)(vlSelfRef.__PVT__opcode_in)) 
                                     && ((0U == (IData)(vlSelfRef.__PVT__funct3_in))
                                          ? (vlSelfRef.__PVT__op1_in 
                                             == vlSelfRef.__PVT__op2_in)
                                          : ((1U == (IData)(vlSelfRef.__PVT__funct3_in))
                                              ? (vlSelfRef.__PVT__op1_in 
                                                 != vlSelfRef.__PVT__op2_in)
                                              : ((4U 
                                                  == (IData)(vlSelfRef.__PVT__funct3_in))
                                                  ? 
                                                 VL_LTS_III(32, vlSelfRef.__PVT__op1_in, vlSelfRef.__PVT__op2_in)
                                                  : 
                                                 ((5U 
                                                   == (IData)(vlSelfRef.__PVT__funct3_in))
                                                   ? 
                                                  VL_GTES_III(32, vlSelfRef.__PVT__op1_in, vlSelfRef.__PVT__op2_in)
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlSelfRef.__PVT__funct3_in))
                                                    ? 
                                                   (vlSelfRef.__PVT__op1_in 
                                                    < vlSelfRef.__PVT__op2_in)
                                                    : 
                                                   ((7U 
                                                     == (IData)(vlSelfRef.__PVT__funct3_in)) 
                                                    && (vlSelfRef.__PVT__op1_in 
                                                        >= vlSelfRef.__PVT__op2_in))))))));
    vlSelfRef.__PVT__alu_res = ((0x13U == (IData)(vlSelfRef.__PVT__opcode_in))
                                 ? (((((((((0U == (IData)(vlSelfRef.__PVT__funct3_in)) 
                                           | (2U == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                          | (3U == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                         | (4U == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                        | (6U == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                       | (7U == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                      | (1U == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                     | (5U == (IData)(vlSelfRef.__PVT__funct3_in)))
                                     ? ((0U == (IData)(vlSelfRef.__PVT__funct3_in))
                                         ? (vlSelfRef.__PVT__op1_in 
                                            + vlSelfRef.__PVT__op2_in)
                                         : ((2U == (IData)(vlSelfRef.__PVT__funct3_in))
                                             ? (VL_LTS_III(32, vlSelfRef.__PVT__op1_in, vlSelfRef.__PVT__op2_in)
                                                 ? 1U
                                                 : 0U)
                                             : ((3U 
                                                 == (IData)(vlSelfRef.__PVT__funct3_in))
                                                 ? 
                                                ((vlSelfRef.__PVT__op1_in 
                                                  < vlSelfRef.__PVT__op2_in)
                                                  ? 1U
                                                  : 0U)
                                                 : 
                                                ((4U 
                                                  == (IData)(vlSelfRef.__PVT__funct3_in))
                                                  ? 
                                                 (vlSelfRef.__PVT__op1_in 
                                                  ^ vlSelfRef.__PVT__op2_in)
                                                  : 
                                                 ((6U 
                                                   == (IData)(vlSelfRef.__PVT__funct3_in))
                                                   ? 
                                                  (vlSelfRef.__PVT__op1_in 
                                                   | vlSelfRef.__PVT__op2_in)
                                                   : 
                                                  ((7U 
                                                    == (IData)(vlSelfRef.__PVT__funct3_in))
                                                    ? 
                                                   (vlSelfRef.__PVT__op1_in 
                                                    & vlSelfRef.__PVT__op2_in)
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelfRef.__PVT__funct3_in))
                                                     ? 
                                                    (vlSelfRef.__PVT__op1_in 
                                                     << 
                                                     (0x1fU 
                                                      & VL_SEL_IIII(32, vlSelfRef.__PVT__op2_in, 0U, 5U)))
                                                     : 
                                                    ((1U 
                                                      & VL_BITSEL_IIII(7, (IData)(vlSelfRef.__PVT__funct7_in), 5U))
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, vlSelfRef.__PVT__op1_in, 
                                                                    (0x1fU 
                                                                     & VL_SEL_IIII(32, vlSelfRef.__PVT__op2_in, 0U, 5U)))
                                                      : 
                                                     (vlSelfRef.__PVT__op1_in 
                                                      >> 
                                                      (0x1fU 
                                                       & VL_SEL_IIII(32, vlSelfRef.__PVT__op2_in, 0U, 5U)))))))))))
                                     : 0U) : ((0x33U 
                                               == (IData)(vlSelfRef.__PVT__opcode_in))
                                               ? ((
                                                   (((((((0U 
                                                          == (IData)(vlSelfRef.__PVT__funct3_in)) 
                                                         | (1U 
                                                            == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                                        | (2U 
                                                           == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                                       | (3U 
                                                          == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                                      | (4U 
                                                         == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                                     | (5U 
                                                        == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                                    | (6U 
                                                       == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                                   | (7U 
                                                      == (IData)(vlSelfRef.__PVT__funct3_in)))
                                                   ? 
                                                  ((0U 
                                                    == (IData)(vlSelfRef.__PVT__funct3_in))
                                                    ? 
                                                   ((1U 
                                                     & VL_BITSEL_IIII(7, (IData)(vlSelfRef.__PVT__funct7_in), 5U))
                                                     ? 
                                                    (vlSelfRef.__PVT__op1_in 
                                                     - vlSelfRef.__PVT__op2_in)
                                                     : 
                                                    (vlSelfRef.__PVT__op1_in 
                                                     + vlSelfRef.__PVT__op2_in))
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelfRef.__PVT__funct3_in))
                                                     ? 
                                                    (vlSelfRef.__PVT__op1_in 
                                                     << 
                                                     (0x1fU 
                                                      & VL_SEL_IIII(32, vlSelfRef.__PVT__op2_in, 0U, 5U)))
                                                     : 
                                                    ((2U 
                                                      == (IData)(vlSelfRef.__PVT__funct3_in))
                                                      ? 
                                                     (VL_LTS_III(32, vlSelfRef.__PVT__op1_in, vlSelfRef.__PVT__op2_in)
                                                       ? 1U
                                                       : 0U)
                                                      : 
                                                     ((3U 
                                                       == (IData)(vlSelfRef.__PVT__funct3_in))
                                                       ? 
                                                      ((vlSelfRef.__PVT__op1_in 
                                                        < vlSelfRef.__PVT__op2_in)
                                                        ? 1U
                                                        : 0U)
                                                       : 
                                                      ((4U 
                                                        == (IData)(vlSelfRef.__PVT__funct3_in))
                                                        ? 
                                                       (vlSelfRef.__PVT__op1_in 
                                                        ^ vlSelfRef.__PVT__op2_in)
                                                        : 
                                                       ((5U 
                                                         == (IData)(vlSelfRef.__PVT__funct3_in))
                                                         ? 
                                                        ((1U 
                                                          & VL_BITSEL_IIII(7, (IData)(vlSelfRef.__PVT__funct7_in), 5U))
                                                          ? 
                                                         VL_SHIFTRS_III(32,32,5, vlSelfRef.__PVT__op1_in, 
                                                                        (0x1fU 
                                                                         & VL_SEL_IIII(32, vlSelfRef.__PVT__op2_in, 0U, 5U)))
                                                          : 
                                                         (vlSelfRef.__PVT__op1_in 
                                                          >> 
                                                          (0x1fU 
                                                           & VL_SEL_IIII(32, vlSelfRef.__PVT__op2_in, 0U, 5U))))
                                                         : 
                                                        ((6U 
                                                          == (IData)(vlSelfRef.__PVT__funct3_in))
                                                          ? 
                                                         (vlSelfRef.__PVT__op1_in 
                                                          | vlSelfRef.__PVT__op2_in)
                                                          : 
                                                         (vlSelfRef.__PVT__op1_in 
                                                          & vlSelfRef.__PVT__op2_in))))))))
                                                   : 0U)
                                               : ((
                                                   (3U 
                                                    == (IData)(vlSelfRef.__PVT__opcode_in)) 
                                                   || (0x23U 
                                                       == (IData)(vlSelfRef.__PVT__opcode_in)))
                                                   ? 
                                                  (vlSelfRef.__PVT__op1_in 
                                                   + vlSelfRef.__PVT__op2_in)
                                                   : 
                                                  (((0x6fU 
                                                     == (IData)(vlSelfRef.__PVT__opcode_in)) 
                                                    || (0x67U 
                                                        == (IData)(vlSelfRef.__PVT__opcode_in)))
                                                    ? 
                                                   (vlSelfRef.__PVT__op1_in 
                                                    + vlSelfRef.__PVT__op2_in)
                                                    : 
                                                   ((0x37U 
                                                     == (IData)(vlSelfRef.__PVT__opcode_in))
                                                     ? vlSelfRef.__PVT__op2_in
                                                     : 
                                                    ((0x17U 
                                                      == (IData)(vlSelfRef.__PVT__opcode_in))
                                                      ? 
                                                     (vlSelfRef.__PVT__op1_in 
                                                      + vlSelfRef.__PVT__op2_in)
                                                      : 0U))))));
    vlSelfRef.__PVT__jump_flag_out = 0U;
    vlSelfRef.__PVT__jump_target_out = 0U;
    if ((0x6fU == (IData)(vlSelfRef.__PVT__opcode_in))) {
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
    vlSelfRef.__PVT__alu_result_out = vlSelfRef.__PVT__alu_res;
}

VL_INLINE_OPT void Vtop_execute___nba_comb__TOP__top__u_execute__0(Vtop_execute* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_execute___nba_comb__TOP__top__u_execute__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__inst_ebreak_in) {
        Vtop___024unit____Vdpiimwrap_trap_TOP____024unit(vlSelfRef.__PVT__op1_in, vlSelfRef.__PVT__pc_in);
    }
    vlSelfRef.__PVT__branch_taken = ((0x63U == (IData)(vlSelfRef.__PVT__opcode_in)) 
                                     && ((0U == (IData)(vlSelfRef.__PVT__funct3_in))
                                          ? (vlSelfRef.__PVT__op1_in 
                                             == vlSelfRef.__PVT__op2_in)
                                          : ((1U == (IData)(vlSelfRef.__PVT__funct3_in))
                                              ? (vlSelfRef.__PVT__op1_in 
                                                 != vlSelfRef.__PVT__op2_in)
                                              : ((4U 
                                                  == (IData)(vlSelfRef.__PVT__funct3_in))
                                                  ? 
                                                 VL_LTS_III(32, vlSelfRef.__PVT__op1_in, vlSelfRef.__PVT__op2_in)
                                                  : 
                                                 ((5U 
                                                   == (IData)(vlSelfRef.__PVT__funct3_in))
                                                   ? 
                                                  VL_GTES_III(32, vlSelfRef.__PVT__op1_in, vlSelfRef.__PVT__op2_in)
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlSelfRef.__PVT__funct3_in))
                                                    ? 
                                                   (vlSelfRef.__PVT__op1_in 
                                                    < vlSelfRef.__PVT__op2_in)
                                                    : 
                                                   ((7U 
                                                     == (IData)(vlSelfRef.__PVT__funct3_in)) 
                                                    && (vlSelfRef.__PVT__op1_in 
                                                        >= vlSelfRef.__PVT__op2_in))))))));
    vlSelfRef.__PVT__alu_res = ((0x13U == (IData)(vlSelfRef.__PVT__opcode_in))
                                 ? (((((((((0U == (IData)(vlSelfRef.__PVT__funct3_in)) 
                                           | (2U == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                          | (3U == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                         | (4U == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                        | (6U == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                       | (7U == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                      | (1U == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                     | (5U == (IData)(vlSelfRef.__PVT__funct3_in)))
                                     ? ((0U == (IData)(vlSelfRef.__PVT__funct3_in))
                                         ? (vlSelfRef.__PVT__op1_in 
                                            + vlSelfRef.__PVT__op2_in)
                                         : ((2U == (IData)(vlSelfRef.__PVT__funct3_in))
                                             ? (VL_LTS_III(32, vlSelfRef.__PVT__op1_in, vlSelfRef.__PVT__op2_in)
                                                 ? 1U
                                                 : 0U)
                                             : ((3U 
                                                 == (IData)(vlSelfRef.__PVT__funct3_in))
                                                 ? 
                                                ((vlSelfRef.__PVT__op1_in 
                                                  < vlSelfRef.__PVT__op2_in)
                                                  ? 1U
                                                  : 0U)
                                                 : 
                                                ((4U 
                                                  == (IData)(vlSelfRef.__PVT__funct3_in))
                                                  ? 
                                                 (vlSelfRef.__PVT__op1_in 
                                                  ^ vlSelfRef.__PVT__op2_in)
                                                  : 
                                                 ((6U 
                                                   == (IData)(vlSelfRef.__PVT__funct3_in))
                                                   ? 
                                                  (vlSelfRef.__PVT__op1_in 
                                                   | vlSelfRef.__PVT__op2_in)
                                                   : 
                                                  ((7U 
                                                    == (IData)(vlSelfRef.__PVT__funct3_in))
                                                    ? 
                                                   (vlSelfRef.__PVT__op1_in 
                                                    & vlSelfRef.__PVT__op2_in)
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelfRef.__PVT__funct3_in))
                                                     ? 
                                                    (vlSelfRef.__PVT__op1_in 
                                                     << 
                                                     (0x1fU 
                                                      & VL_SEL_IIII(32, vlSelfRef.__PVT__op2_in, 0U, 5U)))
                                                     : 
                                                    ((1U 
                                                      & VL_BITSEL_IIII(7, (IData)(vlSelfRef.__PVT__funct7_in), 5U))
                                                      ? 
                                                     VL_SHIFTRS_III(32,32,5, vlSelfRef.__PVT__op1_in, 
                                                                    (0x1fU 
                                                                     & VL_SEL_IIII(32, vlSelfRef.__PVT__op2_in, 0U, 5U)))
                                                      : 
                                                     (vlSelfRef.__PVT__op1_in 
                                                      >> 
                                                      (0x1fU 
                                                       & VL_SEL_IIII(32, vlSelfRef.__PVT__op2_in, 0U, 5U)))))))))))
                                     : 0U) : ((0x33U 
                                               == (IData)(vlSelfRef.__PVT__opcode_in))
                                               ? ((
                                                   (((((((0U 
                                                          == (IData)(vlSelfRef.__PVT__funct3_in)) 
                                                         | (1U 
                                                            == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                                        | (2U 
                                                           == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                                       | (3U 
                                                          == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                                      | (4U 
                                                         == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                                     | (5U 
                                                        == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                                    | (6U 
                                                       == (IData)(vlSelfRef.__PVT__funct3_in))) 
                                                   | (7U 
                                                      == (IData)(vlSelfRef.__PVT__funct3_in)))
                                                   ? 
                                                  ((0U 
                                                    == (IData)(vlSelfRef.__PVT__funct3_in))
                                                    ? 
                                                   ((1U 
                                                     & VL_BITSEL_IIII(7, (IData)(vlSelfRef.__PVT__funct7_in), 5U))
                                                     ? 
                                                    (vlSelfRef.__PVT__op1_in 
                                                     - vlSelfRef.__PVT__op2_in)
                                                     : 
                                                    (vlSelfRef.__PVT__op1_in 
                                                     + vlSelfRef.__PVT__op2_in))
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelfRef.__PVT__funct3_in))
                                                     ? 
                                                    (vlSelfRef.__PVT__op1_in 
                                                     << 
                                                     (0x1fU 
                                                      & VL_SEL_IIII(32, vlSelfRef.__PVT__op2_in, 0U, 5U)))
                                                     : 
                                                    ((2U 
                                                      == (IData)(vlSelfRef.__PVT__funct3_in))
                                                      ? 
                                                     (VL_LTS_III(32, vlSelfRef.__PVT__op1_in, vlSelfRef.__PVT__op2_in)
                                                       ? 1U
                                                       : 0U)
                                                      : 
                                                     ((3U 
                                                       == (IData)(vlSelfRef.__PVT__funct3_in))
                                                       ? 
                                                      ((vlSelfRef.__PVT__op1_in 
                                                        < vlSelfRef.__PVT__op2_in)
                                                        ? 1U
                                                        : 0U)
                                                       : 
                                                      ((4U 
                                                        == (IData)(vlSelfRef.__PVT__funct3_in))
                                                        ? 
                                                       (vlSelfRef.__PVT__op1_in 
                                                        ^ vlSelfRef.__PVT__op2_in)
                                                        : 
                                                       ((5U 
                                                         == (IData)(vlSelfRef.__PVT__funct3_in))
                                                         ? 
                                                        ((1U 
                                                          & VL_BITSEL_IIII(7, (IData)(vlSelfRef.__PVT__funct7_in), 5U))
                                                          ? 
                                                         VL_SHIFTRS_III(32,32,5, vlSelfRef.__PVT__op1_in, 
                                                                        (0x1fU 
                                                                         & VL_SEL_IIII(32, vlSelfRef.__PVT__op2_in, 0U, 5U)))
                                                          : 
                                                         (vlSelfRef.__PVT__op1_in 
                                                          >> 
                                                          (0x1fU 
                                                           & VL_SEL_IIII(32, vlSelfRef.__PVT__op2_in, 0U, 5U))))
                                                         : 
                                                        ((6U 
                                                          == (IData)(vlSelfRef.__PVT__funct3_in))
                                                          ? 
                                                         (vlSelfRef.__PVT__op1_in 
                                                          | vlSelfRef.__PVT__op2_in)
                                                          : 
                                                         (vlSelfRef.__PVT__op1_in 
                                                          & vlSelfRef.__PVT__op2_in))))))))
                                                   : 0U)
                                               : ((
                                                   (3U 
                                                    == (IData)(vlSelfRef.__PVT__opcode_in)) 
                                                   || (0x23U 
                                                       == (IData)(vlSelfRef.__PVT__opcode_in)))
                                                   ? 
                                                  (vlSelfRef.__PVT__op1_in 
                                                   + vlSelfRef.__PVT__op2_in)
                                                   : 
                                                  (((0x6fU 
                                                     == (IData)(vlSelfRef.__PVT__opcode_in)) 
                                                    || (0x67U 
                                                        == (IData)(vlSelfRef.__PVT__opcode_in)))
                                                    ? 
                                                   (vlSelfRef.__PVT__op1_in 
                                                    + vlSelfRef.__PVT__op2_in)
                                                    : 
                                                   ((0x37U 
                                                     == (IData)(vlSelfRef.__PVT__opcode_in))
                                                     ? vlSelfRef.__PVT__op2_in
                                                     : 
                                                    ((0x17U 
                                                      == (IData)(vlSelfRef.__PVT__opcode_in))
                                                      ? 
                                                     (vlSelfRef.__PVT__op1_in 
                                                      + vlSelfRef.__PVT__op2_in)
                                                      : 0U))))));
    vlSelfRef.__PVT__jump_flag_out = 0U;
    vlSelfRef.__PVT__jump_target_out = 0U;
    if ((0x6fU == (IData)(vlSelfRef.__PVT__opcode_in))) {
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
    vlSelfRef.__PVT__alu_result_out = vlSelfRef.__PVT__alu_res;
}
