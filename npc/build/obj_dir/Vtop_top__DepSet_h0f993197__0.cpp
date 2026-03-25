// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_top.h"

VL_INLINE_OPT void Vtop_top___ico_sequent__TOP__top__0(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___ico_sequent__TOP__top__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__top__u_core.__PVT__clk = vlSelfRef.clk;
    vlSymsp->TOP__top__u_core.__PVT__rst_n = vlSelfRef.rst_n;
}

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__0(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc = vlSymsp->TOP__top__u_core.__PVT__pc;
}

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__1(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.regs[0xfU] = vlSymsp->TOP__top__u_core.__PVT__regs
        [0xfU];
    vlSelfRef.regs[0xeU] = vlSymsp->TOP__top__u_core.__PVT__regs
        [0xeU];
    vlSelfRef.regs[0xdU] = vlSymsp->TOP__top__u_core.__PVT__regs
        [0xdU];
    vlSelfRef.regs[0xcU] = vlSymsp->TOP__top__u_core.__PVT__regs
        [0xcU];
    vlSelfRef.regs[0xbU] = vlSymsp->TOP__top__u_core.__PVT__regs
        [0xbU];
    vlSelfRef.regs[0xaU] = vlSymsp->TOP__top__u_core.__PVT__regs
        [0xaU];
    vlSelfRef.regs[9U] = vlSymsp->TOP__top__u_core.__PVT__regs
        [9U];
    vlSelfRef.regs[8U] = vlSymsp->TOP__top__u_core.__PVT__regs
        [8U];
    vlSelfRef.regs[7U] = vlSymsp->TOP__top__u_core.__PVT__regs
        [7U];
    vlSelfRef.regs[6U] = vlSymsp->TOP__top__u_core.__PVT__regs
        [6U];
    vlSelfRef.regs[5U] = vlSymsp->TOP__top__u_core.__PVT__regs
        [5U];
    vlSelfRef.regs[4U] = vlSymsp->TOP__top__u_core.__PVT__regs
        [4U];
    vlSelfRef.regs[3U] = vlSymsp->TOP__top__u_core.__PVT__regs
        [3U];
    vlSelfRef.regs[2U] = vlSymsp->TOP__top__u_core.__PVT__regs
        [2U];
    vlSelfRef.regs[1U] = vlSymsp->TOP__top__u_core.__PVT__regs
        [1U];
    vlSelfRef.regs[0U] = vlSymsp->TOP__top__u_core.__PVT__regs
        [0U];
}

void Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ &paddr_read__Vfuncrtn);
void Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ data);

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__2(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__ifu_rdata = vlSelfRef.__PVT__ifu_rdata;
    vlSelfRef.__Vdly__lsu_rdata = vlSelfRef.__PVT__lsu_rdata;
    if (vlSelfRef.rst_n) {
        Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.__PVT__ifu_raddr, vlSelfRef.__Vfunc_paddr_read__0__Vfuncout);
        vlSelfRef.__Vdly__ifu_rdata = vlSelfRef.__Vfunc_paddr_read__0__Vfuncout;
    } else {
        vlSelfRef.__Vdly__ifu_rdata = 0x13U;
    }
    if (vlSelfRef.rst_n) {
        Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.__PVT__lsu_addr, vlSelfRef.__Vfunc_paddr_read__1__Vfuncout);
        vlSelfRef.__Vdly__lsu_rdata = vlSelfRef.__Vfunc_paddr_read__1__Vfuncout;
        if (vlSelfRef.__PVT__lsu_wen) {
            Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(vlSelfRef.__PVT__lsu_addr, 
                                                                    ([&]() {
                        vlSelfRef.__Vfunc_wmask2len__3__mask 
                            = vlSelfRef.__PVT__lsu_wmask;
                        {
                            if (((((1U == (IData)(vlSelfRef.__Vfunc_wmask2len__3__mask)) 
                                   || (2U == (IData)(vlSelfRef.__Vfunc_wmask2len__3__mask))) 
                                  || (4U == (IData)(vlSelfRef.__Vfunc_wmask2len__3__mask))) 
                                 || (8U == (IData)(vlSelfRef.__Vfunc_wmask2len__3__mask)))) {
                                vlSelfRef.__Vfunc_wmask2len__3__Vfuncout = 1U;
                                goto __Vlabel1;
                            } else if (((3U == (IData)(vlSelfRef.__Vfunc_wmask2len__3__mask)) 
                                        || (0xcU == (IData)(vlSelfRef.__Vfunc_wmask2len__3__mask)))) {
                                vlSelfRef.__Vfunc_wmask2len__3__Vfuncout = 2U;
                                goto __Vlabel1;
                            } else {
                                vlSelfRef.__Vfunc_wmask2len__3__Vfuncout = 4U;
                                goto __Vlabel1;
                            }
                            __Vlabel1: ;
                        }
                    }(), vlSelfRef.__Vfunc_wmask2len__3__Vfuncout), vlSelfRef.__PVT__lsu_wdata);
        }
    } else {
        vlSelfRef.__Vdly__lsu_rdata = 0U;
    }
    vlSelfRef.__PVT__ifu_rdata = vlSelfRef.__Vdly__ifu_rdata;
    vlSelfRef.__PVT__lsu_rdata = vlSelfRef.__Vdly__lsu_rdata;
    vlSymsp->TOP__top__u_core.__PVT__ifu_rdata = vlSelfRef.__PVT__ifu_rdata;
    vlSymsp->TOP__top__u_core.__PVT__lsu_rdata = vlSelfRef.__PVT__lsu_rdata;
}

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__3(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__3\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_wb_have = vlSymsp->TOP__top__u_core.__PVT__debug_wb_have;
    vlSelfRef.debug_wb_pc = vlSymsp->TOP__top__u_core.__PVT__debug_wb_pc;
    vlSelfRef.debug_wb_instr = vlSymsp->TOP__top__u_core.__PVT__debug_wb_instr;
}

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__4(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__4\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_wb_addr = vlSymsp->TOP__top__u_core.__PVT__debug_wb_addr;
    vlSelfRef.debug_wb_en = vlSymsp->TOP__top__u_core.__PVT__debug_wb_en;
    vlSelfRef.debug_wb_data = vlSymsp->TOP__top__u_core.__PVT__debug_wb_data;
}

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__5(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__5\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__lsu_wdata = vlSymsp->TOP__top__u_core.__PVT__lsu_wdata;
    vlSelfRef.__PVT__lsu_addr = vlSymsp->TOP__top__u_core.__PVT__lsu_addr;
    vlSelfRef.__PVT__lsu_wen = vlSymsp->TOP__top__u_core.__PVT__lsu_wen;
    vlSelfRef.__PVT__lsu_wmask = vlSymsp->TOP__top__u_core.__PVT__lsu_wmask;
}

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__6(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__6\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__ifu_raddr = vlSymsp->TOP__top__u_core.__PVT__ifu_raddr;
}

VL_INLINE_OPT void Vtop_top___nba_comb__TOP__top__0(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_comb__TOP__top__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.instr = vlSymsp->TOP__top__u_core.__PVT__instr;
}
