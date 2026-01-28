// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

void Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ &paddr_read__Vfuncrtn);

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rst_n) {
        Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.top__DOT__pc_pointer, vlSelfRef.__Vfunc_paddr_read__0__Vfuncout);
        vlSelfRef.top__DOT__instruction = vlSelfRef.__Vfunc_paddr_read__0__Vfuncout;
    } else {
        vlSelfRef.top__DOT__instruction = 0x13U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((~ (IData)(vlSelfRef.rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ data);

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__top__DOT__pc_pointer;
    __Vdly__top__DOT__pc_pointer = 0;
    IData/*31:0*/ __VdlyVal__top__DOT__u_register__DOT__rf__v0;
    __VdlyVal__top__DOT__u_register__DOT__rf__v0 = 0;
    CData/*3:0*/ __VdlyDim0__top__DOT__u_register__DOT__rf__v0;
    __VdlyDim0__top__DOT__u_register__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_register__DOT__rf__v0;
    __VdlySet__top__DOT__u_register__DOT__rf__v0 = 0;
    CData/*0:0*/ __VdlySet__top__DOT__u_register__DOT__rf__v1;
    __VdlySet__top__DOT__u_register__DOT__rf__v1 = 0;
    // Body
    __Vdly__top__DOT__pc_pointer = vlSelfRef.top__DOT__pc_pointer;
    __VdlySet__top__DOT__u_register__DOT__rf__v0 = 0U;
    __VdlySet__top__DOT__u_register__DOT__rf__v1 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.rst_n)))) {
        vlSelfRef.top__DOT__u_register__DOT__unnamedblk1__DOT__i = 0x10U;
    }
    if (vlSelfRef.rst_n) {
        __Vdly__top__DOT__pc_pointer = ((IData)(vlSelfRef.top__DOT__ex_jump_flag)
                                         ? vlSelfRef.top__DOT__ex_jump_target
                                         : ((IData)(4U) 
                                            + vlSelfRef.top__DOT__pc_pointer));
        if ((((IData)(vlSelfRef.top__DOT__wb_wr_en) 
              & (0U != (IData)(vlSelfRef.top__DOT__wb_rd_addr))) 
             & (0x10U > (IData)(vlSelfRef.top__DOT__wb_rd_addr)))) {
            __VdlyVal__top__DOT__u_register__DOT__rf__v0 
                = vlSelfRef.top__DOT__wb_wr_data;
            __VdlyDim0__top__DOT__u_register__DOT__rf__v0 
                = (0xfU & (IData)(vlSelfRef.top__DOT__wb_rd_addr));
            __VdlySet__top__DOT__u_register__DOT__rf__v0 = 1U;
        }
    } else {
        __Vdly__top__DOT__pc_pointer = 0x80000000U;
        __VdlySet__top__DOT__u_register__DOT__rf__v1 = 1U;
    }
    if (__VdlySet__top__DOT__u_register__DOT__rf__v0) {
        vlSelfRef.top__DOT__u_register__DOT__rf[__VdlyDim0__top__DOT__u_register__DOT__rf__v0] 
            = __VdlyVal__top__DOT__u_register__DOT__rf__v0;
    }
    if (__VdlySet__top__DOT__u_register__DOT__rf__v1) {
        vlSelfRef.top__DOT__u_register__DOT__rf[0U] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[1U] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[2U] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[3U] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[4U] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[5U] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[6U] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[7U] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[8U] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[9U] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[0xaU] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[0xbU] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[0xcU] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[0xdU] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[0xeU] = 0U;
        vlSelfRef.top__DOT__u_register__DOT__rf[0xfU] = 0U;
    }
    vlSelfRef.top__DOT__wb_wr_data = 0U;
    if (vlSelfRef.rst_n) {
        vlSelfRef.top__DOT__wb_mem_rdata = vlSelfRef.top__DOT__mem_mem_rdata;
        if (vlSelfRef.top__DOT__ex_jump_flag) {
            vlSelfRef.top__DOT__ex_imm = 0U;
            vlSelfRef.top__DOT__ex_rs1_data = 0U;
            vlSelfRef.top__DOT__ex_op2 = 0U;
            vlSelfRef.top__DOT__ex_op1 = 0U;
            vlSelfRef.top__DOT__ex_instr = 0x13U;
            vlSelfRef.top__DOT__ex_funct7 = 0U;
        } else {
            vlSelfRef.top__DOT__ex_imm = vlSelfRef.top__DOT__u_decode__DOT__imm;
            vlSelfRef.top__DOT__ex_rs1_data = vlSelfRef.top__DOT__id_rs1_data;
            vlSelfRef.top__DOT__ex_op2 = vlSelfRef.top__DOT__id_op2;
            vlSelfRef.top__DOT__ex_op1 = vlSelfRef.top__DOT__id_op1;
            vlSelfRef.top__DOT__ex_instr = vlSelfRef.top__DOT__id_instr;
            vlSelfRef.top__DOT__ex_funct7 = (vlSelfRef.top__DOT__id_instr 
                                             >> 0x19U);
        }
        vlSelfRef.top__DOT__mem_rs2_data = vlSelfRef.top__DOT__ex_rs2_data;
        vlSelfRef.top__DOT__wb_alu_result = vlSelfRef.top__DOT__mem_alu_result;
        vlSelfRef.top__DOT__wb_pc = vlSelfRef.top__DOT__mem_pc;
        vlSelfRef.top__DOT__mem_funct3 = vlSelfRef.top__DOT__ex_funct3;
        vlSelfRef.top__DOT__wb_opcode = vlSelfRef.top__DOT__mem_opcode;
    } else {
        vlSelfRef.top__DOT__wb_mem_rdata = 0U;
        vlSelfRef.top__DOT__ex_imm = 0U;
        vlSelfRef.top__DOT__ex_rs1_data = 0U;
        vlSelfRef.top__DOT__ex_op2 = 0U;
        vlSelfRef.top__DOT__ex_op1 = 0U;
        vlSelfRef.top__DOT__mem_rs2_data = 0U;
        vlSelfRef.top__DOT__wb_alu_result = 0U;
        vlSelfRef.top__DOT__ex_instr = 0x13U;
        vlSelfRef.top__DOT__ex_funct7 = 0U;
        vlSelfRef.top__DOT__wb_pc = 0U;
        vlSelfRef.top__DOT__mem_funct3 = 0U;
        vlSelfRef.top__DOT__wb_opcode = 0x13U;
    }
    if ((0x40U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
        vlSelfRef.top__DOT__wb_wr_en = ((1U & ((IData)(vlSelfRef.top__DOT__wb_opcode) 
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
                                                        & (IData)(vlSelfRef.top__DOT__wb_opcode))))));
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
        vlSelfRef.top__DOT__wb_wr_en = ((1U & ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                               >> 4U)) 
                                        && ((1U & (~ 
                                                   ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                    >> 3U))) 
                                            && ((1U 
                                                 & ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                    >> 1U)) 
                                                && (1U 
                                                    & (IData)(vlSelfRef.top__DOT__wb_opcode)))));
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
        vlSelfRef.top__DOT__wb_wr_en = ((1U & (~ ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                  >> 3U))) 
                                        && ((1U & ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                   >> 1U)) 
                                            && (1U 
                                                & (IData)(vlSelfRef.top__DOT__wb_opcode))));
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                      >> 3U)))) {
            if ((2U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
                if ((1U & (IData)(vlSelfRef.top__DOT__wb_opcode))) {
                    vlSelfRef.top__DOT__wb_wr_data 
                        = vlSelfRef.top__DOT__wb_alu_result;
                }
            }
        }
    } else {
        vlSelfRef.top__DOT__wb_wr_en = ((1U & (~ ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                  >> 3U))) 
                                        && ((1U & (~ 
                                                   ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                    >> 2U))) 
                                            && ((1U 
                                                 & ((IData)(vlSelfRef.top__DOT__wb_opcode) 
                                                    >> 1U)) 
                                                && (1U 
                                                    & (IData)(vlSelfRef.top__DOT__wb_opcode)))));
        if ((1U & (~ ((IData)(vlSelfRef.top__DOT__wb_opcode) 
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
    }
    if (vlSelfRef.rst_n) {
        vlSelfRef.top__DOT__wb_rd_addr = vlSelfRef.top__DOT__mem_rd_addr;
        vlSelfRef.top__DOT__mem_alu_result = vlSelfRef.top__DOT__u_execute__DOT__alu_res;
        vlSelfRef.top__DOT__mem_pc = vlSelfRef.top__DOT__ex_pc;
        if (vlSelfRef.top__DOT__ex_jump_flag) {
            vlSelfRef.top__DOT__ex_rs2_data = 0U;
            vlSelfRef.top__DOT__ex_funct3 = 0U;
            vlSelfRef.top__DOT__ex_pc = 0U;
        } else {
            vlSelfRef.top__DOT__ex_rs2_data = vlSelfRef.top__DOT__id_rs2_data;
            vlSelfRef.top__DOT__ex_funct3 = (7U & (vlSelfRef.top__DOT__id_instr 
                                                   >> 0xcU));
            vlSelfRef.top__DOT__ex_pc = vlSelfRef.top__DOT__id_pc;
        }
        vlSelfRef.top__DOT__mem_opcode = vlSelfRef.top__DOT__ex_opcode;
        vlSelfRef.top__DOT__mem_rd_addr = vlSelfRef.top__DOT__ex_rd_addr;
    } else {
        vlSelfRef.top__DOT__wb_rd_addr = 0U;
        vlSelfRef.top__DOT__ex_rs2_data = 0U;
        vlSelfRef.top__DOT__mem_alu_result = 0U;
        vlSelfRef.top__DOT__mem_pc = 0U;
        vlSelfRef.top__DOT__ex_funct3 = 0U;
        vlSelfRef.top__DOT__mem_opcode = 0x13U;
        vlSelfRef.top__DOT__mem_rd_addr = 0U;
        vlSelfRef.top__DOT__ex_pc = 0U;
    }
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
    vlSelfRef.top__DOT__u_memory__DOT__rdata_raw = 0U;
    vlSelfRef.top__DOT__mem_mem_rdata = 0U;
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
    vlSelfRef.top__DOT__ex_opcode = ((IData)(vlSelfRef.rst_n)
                                      ? ((IData)(vlSelfRef.top__DOT__ex_jump_flag)
                                          ? 0x13U : 
                                         (0x7fU & vlSelfRef.top__DOT__id_instr))
                                      : 0x13U);
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
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.top__DOT__ex_jump_flag) {
            vlSelfRef.top__DOT__ex_rd_addr = 0U;
            vlSelfRef.top__DOT__id_pc = 0U;
            vlSelfRef.top__DOT__id_instr = 0x13U;
        } else {
            vlSelfRef.top__DOT__ex_rd_addr = (0x1fU 
                                              & (vlSelfRef.top__DOT__id_instr 
                                                 >> 7U));
            vlSelfRef.top__DOT__id_pc = vlSelfRef.top__DOT__pc_pointer;
            vlSelfRef.top__DOT__id_instr = vlSelfRef.top__DOT__instruction;
        }
        vlSelfRef.top__DOT__pc_pointer = __Vdly__top__DOT__pc_pointer;
        vlSelfRef.top__DOT__ex_jump_target = 0U;
    } else {
        vlSelfRef.top__DOT__ex_rd_addr = 0U;
        vlSelfRef.top__DOT__id_pc = 0U;
        vlSelfRef.top__DOT__pc_pointer = __Vdly__top__DOT__pc_pointer;
        vlSelfRef.top__DOT__ex_jump_target = 0U;
        vlSelfRef.top__DOT__id_instr = 0x13U;
    }
    if ((0x6fU == (IData)(vlSelfRef.top__DOT__ex_opcode))) {
        vlSelfRef.top__DOT__ex_jump_target = (vlSelfRef.top__DOT__ex_pc 
                                              + vlSelfRef.top__DOT__ex_imm);
    } else if ((0x67U == (IData)(vlSelfRef.top__DOT__ex_opcode))) {
        vlSelfRef.top__DOT__ex_jump_target = (0xfffffffeU 
                                              & (vlSelfRef.top__DOT__ex_rs1_data 
                                                 + vlSelfRef.top__DOT__ex_imm));
    } else if (vlSelfRef.top__DOT__u_execute__DOT__branch_taken) {
        vlSelfRef.top__DOT__ex_jump_target = (vlSelfRef.top__DOT__ex_pc 
                                              + vlSelfRef.top__DOT__ex_imm);
    }
    if (vlSelfRef.rst_n) {
        Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.top__DOT__pc_pointer, vlSelfRef.__Vfunc_paddr_read__0__Vfuncout);
        vlSelfRef.top__DOT__instruction = vlSelfRef.__Vfunc_paddr_read__0__Vfuncout;
    } else {
        vlSelfRef.top__DOT__instruction = 0x13U;
    }
    vlSelfRef.top__DOT__ex_jump_flag = 0U;
    if ((0x6fU == (IData)(vlSelfRef.top__DOT__ex_opcode))) {
        vlSelfRef.top__DOT__ex_jump_flag = 1U;
    } else if ((0x67U == (IData)(vlSelfRef.top__DOT__ex_opcode))) {
        vlSelfRef.top__DOT__ex_jump_flag = 1U;
    } else if (vlSelfRef.top__DOT__u_execute__DOT__branch_taken) {
        vlSelfRef.top__DOT__ex_jump_flag = 1U;
    }
    if ((0x40U & vlSelfRef.top__DOT__id_instr)) {
        if ((0x20U & vlSelfRef.top__DOT__id_instr)) {
            if ((0x10U & vlSelfRef.top__DOT__id_instr)) {
                vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
                vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                                   & 0U);
            } else if ((8U & vlSelfRef.top__DOT__id_instr)) {
                vlSelfRef.top__DOT__u_decode__DOT__imm 
                    = ((4U & vlSelfRef.top__DOT__id_instr)
                        ? ((2U & vlSelfRef.top__DOT__id_instr)
                            ? ((1U & vlSelfRef.top__DOT__id_instr)
                                ? (((- (IData)((vlSelfRef.top__DOT__id_instr 
                                                >> 0x1fU))) 
                                    << 0x14U) | (((0xff000U 
                                                   & vlSelfRef.top__DOT__id_instr) 
                                                  | (0x800U 
                                                     & (vlSelfRef.top__DOT__id_instr 
                                                        >> 9U))) 
                                                 | (0x7feU 
                                                    & (vlSelfRef.top__DOT__id_instr 
                                                       >> 0x14U))))
                                : 0U) : 0U) : 0U);
                vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                                   & 0U);
            } else if ((4U & vlSelfRef.top__DOT__id_instr)) {
                if ((2U & vlSelfRef.top__DOT__id_instr)) {
                    if ((1U & vlSelfRef.top__DOT__id_instr)) {
                        vlSelfRef.top__DOT__u_decode__DOT__imm 
                            = (((- (IData)((vlSelfRef.top__DOT__id_instr 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelfRef.top__DOT__id_instr 
                                            >> 0x14U));
                        vlSelfRef.top__DOT__id_rs1_addr 
                            = (0x1fU & (vlSelfRef.top__DOT__id_instr 
                                        >> 0xfU));
                    } else {
                        vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
                        vlSelfRef.top__DOT__id_rs1_addr 
                            = (0x1fU & 0U);
                    }
                } else {
                    vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
                    vlSelfRef.top__DOT__id_rs1_addr 
                        = (0x1fU & 0U);
                }
            } else if ((2U & vlSelfRef.top__DOT__id_instr)) {
                if ((1U & vlSelfRef.top__DOT__id_instr)) {
                    vlSelfRef.top__DOT__u_decode__DOT__imm 
                        = (((- (IData)((vlSelfRef.top__DOT__id_instr 
                                        >> 0x1fU))) 
                            << 0xcU) | ((0x800U & (vlSelfRef.top__DOT__id_instr 
                                                   << 4U)) 
                                        | ((0x7e0U 
                                            & (vlSelfRef.top__DOT__id_instr 
                                               >> 0x14U)) 
                                           | (0x1eU 
                                              & (vlSelfRef.top__DOT__id_instr 
                                                 >> 7U)))));
                    vlSelfRef.top__DOT__id_rs1_addr 
                        = (0x1fU & (vlSelfRef.top__DOT__id_instr 
                                    >> 0xfU));
                } else {
                    vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
                    vlSelfRef.top__DOT__id_rs1_addr 
                        = (0x1fU & 0U);
                }
            } else {
                vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
                vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                                   & 0U);
            }
        } else {
            vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
            vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                               & 0U);
        }
    } else if ((0x20U & vlSelfRef.top__DOT__id_instr)) {
        if ((0x10U & vlSelfRef.top__DOT__id_instr)) {
            if ((8U & vlSelfRef.top__DOT__id_instr)) {
                vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
                vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                                   & 0U);
            } else if ((4U & vlSelfRef.top__DOT__id_instr)) {
                vlSelfRef.top__DOT__u_decode__DOT__imm 
                    = ((2U & vlSelfRef.top__DOT__id_instr)
                        ? ((1U & vlSelfRef.top__DOT__id_instr)
                            ? (0xfffff000U & vlSelfRef.top__DOT__id_instr)
                            : 0U) : 0U);
                vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                                   & 0U);
            } else {
                vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
                vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                                   & ((2U 
                                                       & vlSelfRef.top__DOT__id_instr)
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.top__DOT__id_instr)
                                                        ? 
                                                       (vlSelfRef.top__DOT__id_instr 
                                                        >> 0xfU)
                                                        : 0U)
                                                       : 0U));
            }
        } else if ((8U & vlSelfRef.top__DOT__id_instr)) {
            vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
            vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                               & 0U);
        } else if ((4U & vlSelfRef.top__DOT__id_instr)) {
            vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
            vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                               & 0U);
        } else if ((2U & vlSelfRef.top__DOT__id_instr)) {
            if ((1U & vlSelfRef.top__DOT__id_instr)) {
                vlSelfRef.top__DOT__u_decode__DOT__imm 
                    = (((- (IData)((vlSelfRef.top__DOT__id_instr 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelfRef.top__DOT__id_instr 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelfRef.top__DOT__id_instr 
                                                      >> 7U))));
                vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                                   & (vlSelfRef.top__DOT__id_instr 
                                                      >> 0xfU));
            } else {
                vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
                vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                                   & 0U);
            }
        } else {
            vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
            vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                               & 0U);
        }
    } else if ((0x10U & vlSelfRef.top__DOT__id_instr)) {
        if ((8U & vlSelfRef.top__DOT__id_instr)) {
            vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
            vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                               & 0U);
        } else if ((4U & vlSelfRef.top__DOT__id_instr)) {
            vlSelfRef.top__DOT__u_decode__DOT__imm 
                = ((2U & vlSelfRef.top__DOT__id_instr)
                    ? ((1U & vlSelfRef.top__DOT__id_instr)
                        ? (0xfffff000U & vlSelfRef.top__DOT__id_instr)
                        : 0U) : 0U);
            vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                               & 0U);
        } else if ((2U & vlSelfRef.top__DOT__id_instr)) {
            if ((1U & vlSelfRef.top__DOT__id_instr)) {
                vlSelfRef.top__DOT__u_decode__DOT__imm 
                    = (((- (IData)((vlSelfRef.top__DOT__id_instr 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelfRef.top__DOT__id_instr 
                          >> 0x14U));
                vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                                   & (vlSelfRef.top__DOT__id_instr 
                                                      >> 0xfU));
            } else {
                vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
                vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                                   & 0U);
            }
        } else {
            vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
            vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                               & 0U);
        }
    } else if ((8U & vlSelfRef.top__DOT__id_instr)) {
        vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
        vlSelfRef.top__DOT__id_rs1_addr = (0x1fU & 0U);
    } else if ((4U & vlSelfRef.top__DOT__id_instr)) {
        vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
        vlSelfRef.top__DOT__id_rs1_addr = (0x1fU & 0U);
    } else if ((2U & vlSelfRef.top__DOT__id_instr)) {
        if ((1U & vlSelfRef.top__DOT__id_instr)) {
            vlSelfRef.top__DOT__u_decode__DOT__imm 
                = (((- (IData)((vlSelfRef.top__DOT__id_instr 
                                >> 0x1fU))) << 0xcU) 
                   | (vlSelfRef.top__DOT__id_instr 
                      >> 0x14U));
            vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                               & (vlSelfRef.top__DOT__id_instr 
                                                  >> 0xfU));
        } else {
            vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
            vlSelfRef.top__DOT__id_rs1_addr = (0x1fU 
                                               & 0U);
        }
    } else {
        vlSelfRef.top__DOT__u_decode__DOT__imm = 0U;
        vlSelfRef.top__DOT__id_rs1_addr = (0x1fU & 0U);
    }
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
}
