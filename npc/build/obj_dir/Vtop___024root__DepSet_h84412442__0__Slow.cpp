// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

void Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ data);
void Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ &paddr_read__Vfuncrtn);

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__wb_wr_en = ((0x40U & (IData)(vlSelfRef.top__DOT__wb_opcode))
                                     ? ((1U & ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                               >> 5U)) 
                                        && ((1U & (~ 
                                                   ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                    >> 4U))) 
                                            && ((1U 
                                                 & ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                    >> 2U)) 
                                                && ((1U 
                                                     & ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                        >> 1U)) 
                                                    && (1U 
                                                        & (IData)(vlSelfRef.top__DOT__wb_opcode))))))
                                     : ((0x20U & (IData)(vlSelfRef.top__DOT__wb_opcode))
                                         ? ((1U & ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                   >> 4U)) 
                                            && ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                     >> 3U))) 
                                                && ((1U 
                                                     & ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                        >> 1U)) 
                                                    && (1U 
                                                        & (IData)(vlSelfRef.top__DOT__wb_opcode)))))
                                         : ((0x10U 
                                             & (IData)(vlSelfRef.top__DOT__wb_opcode))
                                             ? ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                     >> 3U))) 
                                                && ((1U 
                                                     & ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                        >> 1U)) 
                                                    && (1U 
                                                        & (IData)(vlSelfRef.top__DOT__wb_opcode))))
                                             : ((1U 
                                                 & (~ 
                                                    ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                     >> 3U))) 
                                                && ((1U 
                                                     & (~ 
                                                        ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                         >> 2U))) 
                                                    && ((1U 
                                                         & ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                            >> 1U)) 
                                                        && (1U 
                                                            & (IData)(vlSelfRef.top__DOT__wb_opcode))))))));
    if ((0x23U == (IData)(vlSelfRef.top__DOT__mem_opcode))) {
        if ((0U == (IData)(vlSelfRef.top__DOT__mem_funct3))) {
            Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(vlSelfRef.top__DOT__mem_alu_result, 1U, vlSelfRef.top__DOT__mem_rs2_data);
        } else if ((1U == (IData)(vlSelfRef.top__DOT__mem_funct3))) {
            Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(vlSelfRef.top__DOT__mem_alu_result, 2U, vlSelfRef.top__DOT__mem_rs2_data);
        } else if ((2U == (IData)(vlSelfRef.top__DOT__mem_funct3))) {
            Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(vlSelfRef.top__DOT__mem_alu_result, 4U, vlSelfRef.top__DOT__mem_rs2_data);
        } else {
            Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(vlSelfRef.top__DOT__mem_alu_result, 4U, vlSelfRef.top__DOT__mem_rs2_data);
        }
    }
    vlSelfRef.top__DOT__wb_wr_data = 0U;
    if ((0x40U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
        if ((0x20U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                          >> 4U)))) {
                if ((4U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
                    if ((2U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
                        if ((1U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
                            vlSelfRef.top__DOT__wb_wr_data 
                                = vlSelfRef.top__DOT__wb_alu_result;
                        }
                    }
                }
            }
        }
    } else if ((0x20U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
        if ((0x10U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                          >> 3U)))) {
                if ((2U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
                    if ((1U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
                        vlSelfRef.top__DOT__wb_wr_data 
                            = vlSelfRef.top__DOT__wb_alu_result;
                    }
                }
            }
        }
    } else if ((0x10U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                      >> 3U)))) {
            if ((2U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
                    vlSelfRef.top__DOT__wb_wr_data 
                        = vlSelfRef.top__DOT__wb_alu_result;
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                         >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
                    vlSelfRef.top__DOT__wb_wr_data 
                        = vlSelfRef.top__DOT__wb_mem_rdata;
                }
            }
        }
    }
    if (vlSelfRef.rst_n) {
        Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.top__DOT__pc_pointer, vlSelfRef.__Vfunc_paddr_read__0__Vfuncout);
        vlSelfRef.top__DOT__instruction = vlSelfRef.__Vfunc_paddr_read__0__Vfuncout;
    } else {
        vlSelfRef.top__DOT__instruction = 0x13U;
    }
    vlSelfRef.top__DOT__u_execute__DOT__alu_res = (
                                                   (0x40U 
                                                    & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                    ? 
                                                   ((0x20U 
                                                     & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                     ? 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                      ? 0U
                                                      : 
                                                     ((4U 
                                                       & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                         ? 
                                                        (vlSelfRef.top__DOT__ex_op1 
                                                         + vlSelfRef.top__DOT__ex_op2)
                                                         : 0U)
                                                        : 0U)
                                                       : 0U))
                                                     : 0U)
                                                    : 
                                                   ((0x20U 
                                                     & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                     ? 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                          ? vlSelfRef.top__DOT__ex_op2
                                                          : 0U)
                                                         : 0U)
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                           ? 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                            ? 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                             ? 
                                                            (vlSelfRef.top__DOT__ex_op1 
                                                             & vlSelfRef.top__DOT__ex_op2)
                                                             : 
                                                            (vlSelfRef.top__DOT__ex_op1 
                                                             | vlSelfRef.top__DOT__ex_op2))
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                             ? 
                                                            ((0x20U 
                                                              & (IData)(vlSelfRef.top__DOT__ex_funct7))
                                                              ? 
                                                             VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__ex_op1, 
                                                                            (0x1fU 
                                                                             & vlSelfRef.top__DOT__ex_op2))
                                                              : 
                                                             (vlSelfRef.top__DOT__ex_op1 
                                                              >> 
                                                              (0x1fU 
                                                               & vlSelfRef.top__DOT__ex_op2)))
                                                             : 
                                                            (vlSelfRef.top__DOT__ex_op1 
                                                             ^ vlSelfRef.top__DOT__ex_op2)))
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                            ? 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                             ? 
                                                            ((vlSelfRef.top__DOT__ex_op1 
                                                              < vlSelfRef.top__DOT__ex_op2)
                                                              ? 1U
                                                              : 0U)
                                                             : 
                                                            (VL_LTS_III(32, vlSelfRef.top__DOT__ex_op1, vlSelfRef.top__DOT__ex_op2)
                                                              ? 1U
                                                              : 0U))
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                             ? 
                                                            (vlSelfRef.top__DOT__ex_op1 
                                                             << 
                                                             (0x1fU 
                                                              & vlSelfRef.top__DOT__ex_op2))
                                                             : 
                                                            ((0x20U 
                                                              & (IData)(vlSelfRef.top__DOT__ex_funct7))
                                                              ? 
                                                             (vlSelfRef.top__DOT__ex_op1 
                                                              - vlSelfRef.top__DOT__ex_op2)
                                                              : 
                                                             (vlSelfRef.top__DOT__ex_op1 
                                                              + vlSelfRef.top__DOT__ex_op2)))))
                                                          : 0U)
                                                         : 0U)))
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                          ? 
                                                         (vlSelfRef.top__DOT__ex_op1 
                                                          + vlSelfRef.top__DOT__ex_op2)
                                                          : 0U)
                                                         : 0U))))
                                                     : 
                                                    ((0x10U 
                                                      & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                          ? 
                                                         (vlSelfRef.top__DOT__ex_op1 
                                                          + vlSelfRef.top__DOT__ex_op2)
                                                          : 0U)
                                                         : 0U)
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                           ? 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                            ? 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                             ? 
                                                            (vlSelfRef.top__DOT__ex_op1 
                                                             & vlSelfRef.top__DOT__ex_op2)
                                                             : 
                                                            (vlSelfRef.top__DOT__ex_op1 
                                                             | vlSelfRef.top__DOT__ex_op2))
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                             ? 
                                                            ((0x20U 
                                                              & (IData)(vlSelfRef.top__DOT__ex_funct7))
                                                              ? 
                                                             VL_SHIFTRS_III(32,32,5, vlSelfRef.top__DOT__ex_op1, 
                                                                            (0x1fU 
                                                                             & vlSelfRef.top__DOT__ex_op2))
                                                              : 
                                                             (vlSelfRef.top__DOT__ex_op1 
                                                              >> 
                                                              (0x1fU 
                                                               & vlSelfRef.top__DOT__ex_op2)))
                                                             : 
                                                            (vlSelfRef.top__DOT__ex_op1 
                                                             ^ vlSelfRef.top__DOT__ex_op2)))
                                                           : 
                                                          ((2U 
                                                            & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                            ? 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                             ? 
                                                            ((vlSelfRef.top__DOT__ex_op1 
                                                              < vlSelfRef.top__DOT__ex_op2)
                                                              ? 1U
                                                              : 0U)
                                                             : 
                                                            (VL_LTS_III(32, vlSelfRef.top__DOT__ex_op1, vlSelfRef.top__DOT__ex_op2)
                                                              ? 1U
                                                              : 0U))
                                                            : 
                                                           ((1U 
                                                             & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                                             ? 
                                                            (vlSelfRef.top__DOT__ex_op1 
                                                             << 
                                                             (0x1fU 
                                                              & vlSelfRef.top__DOT__ex_op2))
                                                             : 
                                                            (vlSelfRef.top__DOT__ex_op1 
                                                             + vlSelfRef.top__DOT__ex_op2))))
                                                          : 0U)
                                                         : 0U)))
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                         ? 
                                                        ((1U 
                                                          & (IData)(vlSelfRef.top__DOT__ex_opcode))
                                                          ? 
                                                         (vlSelfRef.top__DOT__ex_op1 
                                                          + vlSelfRef.top__DOT__ex_op2)
                                                          : 0U)
                                                         : 0U))))));
    vlSelfRef.top__DOT__u_memory__DOT__rdata_raw = 0U;
    vlSelfRef.top__DOT__mem_mem_rdata = 0U;
    vlSelfRef.top__DOT__u_decode__DOT__imm = ((0x40U 
                                               & vlSelfRef.top__DOT__id_instr)
                                               ? ((0x20U 
                                                   & vlSelfRef.top__DOT__id_instr)
                                                   ? 
                                                  ((0x10U 
                                                    & vlSelfRef.top__DOT__id_instr)
                                                    ? 0U
                                                    : 
                                                   ((8U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 
                                                    ((4U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((2U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.top__DOT__id_instr)
                                                        ? 
                                                       (((- (IData)(
                                                                    (vlSelfRef.top__DOT__id_instr 
                                                                     >> 0x1fU))) 
                                                         << 0x14U) 
                                                        | (((0xff000U 
                                                             & vlSelfRef.top__DOT__id_instr) 
                                                            | (0x800U 
                                                               & (vlSelfRef.top__DOT__id_instr 
                                                                  >> 9U))) 
                                                           | (0x7feU 
                                                              & (vlSelfRef.top__DOT__id_instr 
                                                                 >> 0x14U))))
                                                        : 0U)
                                                       : 0U)
                                                      : 0U)
                                                     : 
                                                    ((4U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((2U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.top__DOT__id_instr)
                                                        ? 
                                                       (((- (IData)(
                                                                    (vlSelfRef.top__DOT__id_instr 
                                                                     >> 0x1fU))) 
                                                         << 0xcU) 
                                                        | (vlSelfRef.top__DOT__id_instr 
                                                           >> 0x14U))
                                                        : 0U)
                                                       : 0U)
                                                      : 
                                                     ((2U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.top__DOT__id_instr)
                                                        ? 
                                                       (((- (IData)(
                                                                    (vlSelfRef.top__DOT__id_instr 
                                                                     >> 0x1fU))) 
                                                         << 0xcU) 
                                                        | ((0x800U 
                                                            & (vlSelfRef.top__DOT__id_instr 
                                                               << 4U)) 
                                                           | ((0x7e0U 
                                                               & (vlSelfRef.top__DOT__id_instr 
                                                                  >> 0x14U)) 
                                                              | (0x1eU 
                                                                 & (vlSelfRef.top__DOT__id_instr 
                                                                    >> 7U)))))
                                                        : 0U)
                                                       : 0U))))
                                                   : 0U)
                                               : ((0x20U 
                                                   & vlSelfRef.top__DOT__id_instr)
                                                   ? 
                                                  ((0x10U 
                                                    & vlSelfRef.top__DOT__id_instr)
                                                    ? 
                                                   ((8U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((2U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.top__DOT__id_instr)
                                                        ? 
                                                       (0xfffff000U 
                                                        & vlSelfRef.top__DOT__id_instr)
                                                        : 0U)
                                                       : 0U)
                                                      : 0U))
                                                    : 
                                                   ((8U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.top__DOT__id_instr)
                                                        ? 
                                                       (((- (IData)(
                                                                    (vlSelfRef.top__DOT__id_instr 
                                                                     >> 0x1fU))) 
                                                         << 0xcU) 
                                                        | ((0xfe0U 
                                                            & (vlSelfRef.top__DOT__id_instr 
                                                               >> 0x14U)) 
                                                           | (0x1fU 
                                                              & (vlSelfRef.top__DOT__id_instr 
                                                                 >> 7U))))
                                                        : 0U)
                                                       : 0U))))
                                                   : 
                                                  ((0x10U 
                                                    & vlSelfRef.top__DOT__id_instr)
                                                    ? 
                                                   ((8U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((2U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.top__DOT__id_instr)
                                                        ? 
                                                       (0xfffff000U 
                                                        & vlSelfRef.top__DOT__id_instr)
                                                        : 0U)
                                                       : 0U)
                                                      : 
                                                     ((2U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.top__DOT__id_instr)
                                                        ? 
                                                       (((- (IData)(
                                                                    (vlSelfRef.top__DOT__id_instr 
                                                                     >> 0x1fU))) 
                                                         << 0xcU) 
                                                        | (vlSelfRef.top__DOT__id_instr 
                                                           >> 0x14U))
                                                        : 0U)
                                                       : 0U)))
                                                    : 
                                                   ((8U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((4U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.top__DOT__id_instr)
                                                        ? 
                                                       (((- (IData)(
                                                                    (vlSelfRef.top__DOT__id_instr 
                                                                     >> 0x1fU))) 
                                                         << 0xcU) 
                                                        | (vlSelfRef.top__DOT__id_instr 
                                                           >> 0x14U))
                                                        : 0U)
                                                       : 0U))))));
    if ((3U == (IData)(vlSelfRef.top__DOT__mem_opcode))) {
        Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.top__DOT__mem_alu_result, vlSelfRef.__Vfunc_paddr_read__1__Vfuncout);
        vlSelfRef.top__DOT__u_memory__DOT__rdata_raw 
            = vlSelfRef.__Vfunc_paddr_read__1__Vfuncout;
        vlSelfRef.top__DOT__mem_mem_rdata = ((4U & (IData)(vlSelfRef.top__DOT__mem_funct3))
                                              ? ((2U 
                                                  & (IData)(vlSelfRef.top__DOT__mem_funct3))
                                                  ? 0U
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__mem_funct3))
                                                   ? 
                                                  (0xffffU 
                                                   & vlSelfRef.top__DOT__u_memory__DOT__rdata_raw)
                                                   : 
                                                  (0xffU 
                                                   & vlSelfRef.top__DOT__u_memory__DOT__rdata_raw)))
                                              : ((2U 
                                                  & (IData)(vlSelfRef.top__DOT__mem_funct3))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__mem_funct3))
                                                   ? 0U
                                                   : vlSelfRef.top__DOT__u_memory__DOT__rdata_raw)
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__mem_funct3))
                                                   ? 
                                                  (((- (IData)(
                                                               (1U 
                                                                & (vlSelfRef.top__DOT__u_memory__DOT__rdata_raw 
                                                                   >> 0xfU)))) 
                                                    << 0x10U) 
                                                   | (0xffffU 
                                                      & vlSelfRef.top__DOT__u_memory__DOT__rdata_raw))
                                                   : 
                                                  (((- (IData)(
                                                               (1U 
                                                                & (vlSelfRef.top__DOT__u_memory__DOT__rdata_raw 
                                                                   >> 7U)))) 
                                                    << 8U) 
                                                   | (0xffU 
                                                      & vlSelfRef.top__DOT__u_memory__DOT__rdata_raw)))));
    }
    vlSelfRef.top__DOT__u_execute__DOT__branch_taken 
        = ((0x63U == (IData)(vlSelfRef.top__DOT__ex_opcode)) 
           && ((4U & (IData)(vlSelfRef.top__DOT__ex_funct3))
                ? ((2U & (IData)(vlSelfRef.top__DOT__ex_funct3))
                    ? ((1U & (IData)(vlSelfRef.top__DOT__ex_funct3))
                        ? (vlSelfRef.top__DOT__ex_op1 
                           >= vlSelfRef.top__DOT__ex_op2)
                        : (vlSelfRef.top__DOT__ex_op1 
                           < vlSelfRef.top__DOT__ex_op2))
                    : ((1U & (IData)(vlSelfRef.top__DOT__ex_funct3))
                        ? VL_GTES_III(32, vlSelfRef.top__DOT__ex_op1, vlSelfRef.top__DOT__ex_op2)
                        : VL_LTS_III(32, vlSelfRef.top__DOT__ex_op1, vlSelfRef.top__DOT__ex_op2)))
                : ((1U & (~ ((IData)(vlSelfRef.top__DOT__ex_funct3) 
                             >> 1U))) && ((1U & (IData)(vlSelfRef.top__DOT__ex_funct3))
                                           ? (vlSelfRef.top__DOT__ex_op1 
                                              != vlSelfRef.top__DOT__ex_op2)
                                           : (vlSelfRef.top__DOT__ex_op1 
                                              == vlSelfRef.top__DOT__ex_op2)))));
    vlSelfRef.top__DOT__id_rs1_addr = (0x1fU & ((0x40U 
                                                 & vlSelfRef.top__DOT__id_instr)
                                                 ? 
                                                ((0x20U 
                                                  & vlSelfRef.top__DOT__id_instr)
                                                  ? 
                                                 ((0x10U 
                                                   & vlSelfRef.top__DOT__id_instr)
                                                   ? 0U
                                                   : 
                                                  ((8U 
                                                    & vlSelfRef.top__DOT__id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 
                                                    ((2U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      (vlSelfRef.top__DOT__id_instr 
                                                       >> 0xfU)
                                                       : 0U)
                                                      : 0U)
                                                     : 
                                                    ((2U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      (vlSelfRef.top__DOT__id_instr 
                                                       >> 0xfU)
                                                       : 0U)
                                                      : 0U))))
                                                  : 0U)
                                                 : 
                                                ((0x20U 
                                                  & vlSelfRef.top__DOT__id_instr)
                                                  ? 
                                                 ((0x10U 
                                                   & vlSelfRef.top__DOT__id_instr)
                                                   ? 
                                                  ((8U 
                                                    & vlSelfRef.top__DOT__id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      (vlSelfRef.top__DOT__id_instr 
                                                       >> 0xfU)
                                                       : 0U)
                                                      : 0U)))
                                                   : 
                                                  ((8U 
                                                    & vlSelfRef.top__DOT__id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      (vlSelfRef.top__DOT__id_instr 
                                                       >> 0xfU)
                                                       : 0U)
                                                      : 0U))))
                                                  : 
                                                 ((0x10U 
                                                   & vlSelfRef.top__DOT__id_instr)
                                                   ? 
                                                  ((8U 
                                                    & vlSelfRef.top__DOT__id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      (vlSelfRef.top__DOT__id_instr 
                                                       >> 0xfU)
                                                       : 0U)
                                                      : 0U)))
                                                   : 
                                                  ((8U 
                                                    & vlSelfRef.top__DOT__id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      (vlSelfRef.top__DOT__id_instr 
                                                       >> 0xfU)
                                                       : 0U)
                                                      : 0U)))))));
    vlSelfRef.top__DOT__id_rs1_data = (((0U == (IData)(vlSelfRef.top__DOT__id_rs1_addr)) 
                                        | (0x10U <= (IData)(vlSelfRef.top__DOT__id_rs1_addr)))
                                        ? 0U : vlSelfRef.top__DOT__u_register__DOT__rf
                                       [(0xfU & (IData)(vlSelfRef.top__DOT__id_rs1_addr))]);
    vlSelfRef.top__DOT__id_rs2_addr = (0x1fU & ((0x40U 
                                                 & vlSelfRef.top__DOT__id_instr)
                                                 ? 
                                                ((0x20U 
                                                  & vlSelfRef.top__DOT__id_instr)
                                                  ? 
                                                 ((0x10U 
                                                   & vlSelfRef.top__DOT__id_instr)
                                                   ? 0U
                                                   : 
                                                  ((8U 
                                                    & vlSelfRef.top__DOT__id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      (vlSelfRef.top__DOT__id_instr 
                                                       >> 0x14U)
                                                       : 0U)
                                                      : 0U))))
                                                  : 0U)
                                                 : 
                                                ((0x20U 
                                                  & vlSelfRef.top__DOT__id_instr)
                                                  ? 
                                                 ((0x10U 
                                                   & vlSelfRef.top__DOT__id_instr)
                                                   ? 
                                                  ((8U 
                                                    & vlSelfRef.top__DOT__id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      (vlSelfRef.top__DOT__id_instr 
                                                       >> 0x14U)
                                                       : 0U)
                                                      : 0U)))
                                                   : 
                                                  ((8U 
                                                    & vlSelfRef.top__DOT__id_instr)
                                                    ? 0U
                                                    : 
                                                   ((4U 
                                                     & vlSelfRef.top__DOT__id_instr)
                                                     ? 0U
                                                     : 
                                                    ((2U 
                                                      & vlSelfRef.top__DOT__id_instr)
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      (vlSelfRef.top__DOT__id_instr 
                                                       >> 0x14U)
                                                       : 0U)
                                                      : 0U))))
                                                  : 0U)));
    vlSelfRef.top__DOT__id_rs2_data = (((0U == (IData)(vlSelfRef.top__DOT__id_rs2_addr)) 
                                        | (0x10U <= (IData)(vlSelfRef.top__DOT__id_rs2_addr)))
                                        ? 0U : vlSelfRef.top__DOT__u_register__DOT__rf
                                       [(0xfU & (IData)(vlSelfRef.top__DOT__id_rs2_addr))]);
    if ((0x40U & vlSelfRef.top__DOT__id_instr)) {
        if ((0x20U & vlSelfRef.top__DOT__id_instr)) {
            if ((0x10U & vlSelfRef.top__DOT__id_instr)) {
                vlSelfRef.top__DOT__id_op1 = 0U;
                vlSelfRef.top__DOT__id_op2 = 0U;
            } else if ((8U & vlSelfRef.top__DOT__id_instr)) {
                if ((4U & vlSelfRef.top__DOT__id_instr)) {
                    if ((2U & vlSelfRef.top__DOT__id_instr)) {
                        if ((1U & vlSelfRef.top__DOT__id_instr)) {
                            vlSelfRef.top__DOT__id_op1 
                                = vlSelfRef.top__DOT__id_pc;
                            vlSelfRef.top__DOT__id_op2 = 4U;
                        } else {
                            vlSelfRef.top__DOT__id_op1 = 0U;
                            vlSelfRef.top__DOT__id_op2 = 0U;
                        }
                    } else {
                        vlSelfRef.top__DOT__id_op1 = 0U;
                        vlSelfRef.top__DOT__id_op2 = 0U;
                    }
                } else {
                    vlSelfRef.top__DOT__id_op1 = 0U;
                    vlSelfRef.top__DOT__id_op2 = 0U;
                }
            } else if ((4U & vlSelfRef.top__DOT__id_instr)) {
                if ((2U & vlSelfRef.top__DOT__id_instr)) {
                    if ((1U & vlSelfRef.top__DOT__id_instr)) {
                        vlSelfRef.top__DOT__id_op1 
                            = vlSelfRef.top__DOT__id_pc;
                        vlSelfRef.top__DOT__id_op2 = 4U;
                    } else {
                        vlSelfRef.top__DOT__id_op1 = 0U;
                        vlSelfRef.top__DOT__id_op2 = 0U;
                    }
                } else {
                    vlSelfRef.top__DOT__id_op1 = 0U;
                    vlSelfRef.top__DOT__id_op2 = 0U;
                }
            } else if ((2U & vlSelfRef.top__DOT__id_instr)) {
                if ((1U & vlSelfRef.top__DOT__id_instr)) {
                    vlSelfRef.top__DOT__id_op1 = vlSelfRef.top__DOT__id_rs1_data;
                    vlSelfRef.top__DOT__id_op2 = vlSelfRef.top__DOT__id_rs2_data;
                } else {
                    vlSelfRef.top__DOT__id_op1 = 0U;
                    vlSelfRef.top__DOT__id_op2 = 0U;
                }
            } else {
                vlSelfRef.top__DOT__id_op1 = 0U;
                vlSelfRef.top__DOT__id_op2 = 0U;
            }
        } else {
            vlSelfRef.top__DOT__id_op1 = 0U;
            vlSelfRef.top__DOT__id_op2 = 0U;
        }
    } else if ((0x20U & vlSelfRef.top__DOT__id_instr)) {
        if ((0x10U & vlSelfRef.top__DOT__id_instr)) {
            if ((8U & vlSelfRef.top__DOT__id_instr)) {
                vlSelfRef.top__DOT__id_op1 = 0U;
                vlSelfRef.top__DOT__id_op2 = 0U;
            } else if ((4U & vlSelfRef.top__DOT__id_instr)) {
                vlSelfRef.top__DOT__id_op1 = 0U;
                vlSelfRef.top__DOT__id_op2 = ((2U & vlSelfRef.top__DOT__id_instr)
                                               ? ((1U 
                                                   & vlSelfRef.top__DOT__id_instr)
                                                   ? vlSelfRef.top__DOT__u_decode__DOT__imm
                                                   : 0U)
                                               : 0U);
            } else if ((2U & vlSelfRef.top__DOT__id_instr)) {
                if ((1U & vlSelfRef.top__DOT__id_instr)) {
                    vlSelfRef.top__DOT__id_op1 = vlSelfRef.top__DOT__id_rs1_data;
                    vlSelfRef.top__DOT__id_op2 = vlSelfRef.top__DOT__id_rs2_data;
                } else {
                    vlSelfRef.top__DOT__id_op1 = 0U;
                    vlSelfRef.top__DOT__id_op2 = 0U;
                }
            } else {
                vlSelfRef.top__DOT__id_op1 = 0U;
                vlSelfRef.top__DOT__id_op2 = 0U;
            }
        } else if ((8U & vlSelfRef.top__DOT__id_instr)) {
            vlSelfRef.top__DOT__id_op1 = 0U;
            vlSelfRef.top__DOT__id_op2 = 0U;
        } else if ((4U & vlSelfRef.top__DOT__id_instr)) {
            vlSelfRef.top__DOT__id_op1 = 0U;
            vlSelfRef.top__DOT__id_op2 = 0U;
        } else if ((2U & vlSelfRef.top__DOT__id_instr)) {
            if ((1U & vlSelfRef.top__DOT__id_instr)) {
                vlSelfRef.top__DOT__id_op1 = vlSelfRef.top__DOT__id_rs1_data;
                vlSelfRef.top__DOT__id_op2 = vlSelfRef.top__DOT__u_decode__DOT__imm;
            } else {
                vlSelfRef.top__DOT__id_op1 = 0U;
                vlSelfRef.top__DOT__id_op2 = 0U;
            }
        } else {
            vlSelfRef.top__DOT__id_op1 = 0U;
            vlSelfRef.top__DOT__id_op2 = 0U;
        }
    } else if ((0x10U & vlSelfRef.top__DOT__id_instr)) {
        if ((8U & vlSelfRef.top__DOT__id_instr)) {
            vlSelfRef.top__DOT__id_op1 = 0U;
            vlSelfRef.top__DOT__id_op2 = 0U;
        } else if ((4U & vlSelfRef.top__DOT__id_instr)) {
            if ((2U & vlSelfRef.top__DOT__id_instr)) {
                if ((1U & vlSelfRef.top__DOT__id_instr)) {
                    vlSelfRef.top__DOT__id_op1 = vlSelfRef.top__DOT__id_pc;
                    vlSelfRef.top__DOT__id_op2 = vlSelfRef.top__DOT__u_decode__DOT__imm;
                } else {
                    vlSelfRef.top__DOT__id_op1 = 0U;
                    vlSelfRef.top__DOT__id_op2 = 0U;
                }
            } else {
                vlSelfRef.top__DOT__id_op1 = 0U;
                vlSelfRef.top__DOT__id_op2 = 0U;
            }
        } else if ((2U & vlSelfRef.top__DOT__id_instr)) {
            if ((1U & vlSelfRef.top__DOT__id_instr)) {
                vlSelfRef.top__DOT__id_op1 = vlSelfRef.top__DOT__id_rs1_data;
                vlSelfRef.top__DOT__id_op2 = vlSelfRef.top__DOT__u_decode__DOT__imm;
            } else {
                vlSelfRef.top__DOT__id_op1 = 0U;
                vlSelfRef.top__DOT__id_op2 = 0U;
            }
        } else {
            vlSelfRef.top__DOT__id_op1 = 0U;
            vlSelfRef.top__DOT__id_op2 = 0U;
        }
    } else if ((8U & vlSelfRef.top__DOT__id_instr)) {
        vlSelfRef.top__DOT__id_op1 = 0U;
        vlSelfRef.top__DOT__id_op2 = 0U;
    } else if ((4U & vlSelfRef.top__DOT__id_instr)) {
        vlSelfRef.top__DOT__id_op1 = 0U;
        vlSelfRef.top__DOT__id_op2 = 0U;
    } else if ((2U & vlSelfRef.top__DOT__id_instr)) {
        if ((1U & vlSelfRef.top__DOT__id_instr)) {
            vlSelfRef.top__DOT__id_op1 = vlSelfRef.top__DOT__id_rs1_data;
            vlSelfRef.top__DOT__id_op2 = vlSelfRef.top__DOT__u_decode__DOT__imm;
        } else {
            vlSelfRef.top__DOT__id_op1 = 0U;
            vlSelfRef.top__DOT__id_op2 = 0U;
        }
    } else {
        vlSelfRef.top__DOT__id_op1 = 0U;
        vlSelfRef.top__DOT__id_op2 = 0U;
    }
    vlSelfRef.top__DOT__ex_jump_flag = 0U;
    vlSelfRef.top__DOT__ex_jump_target = 0U;
    if ((0x6fU == (IData)(vlSelfRef.top__DOT__ex_opcode))) {
        vlSelfRef.top__DOT__ex_jump_flag = 1U;
        vlSelfRef.top__DOT__ex_jump_target = (vlSelfRef.top__DOT__ex_pc 
                                              + vlSelfRef.top__DOT__ex_imm);
    } else if ((0x67U == (IData)(vlSelfRef.top__DOT__ex_opcode))) {
        vlSelfRef.top__DOT__ex_jump_flag = 1U;
        vlSelfRef.top__DOT__ex_jump_target = (0xfffffffeU 
                                              & (vlSelfRef.top__DOT__ex_rs1_data 
                                                 + vlSelfRef.top__DOT__ex_imm));
    } else if (vlSelfRef.top__DOT__u_execute__DOT__branch_taken) {
        vlSelfRef.top__DOT__ex_jump_flag = 1U;
        vlSelfRef.top__DOT__ex_jump_target = (vlSelfRef.top__DOT__ex_pc 
                                              + vlSelfRef.top__DOT__ex_imm);
    }
}
