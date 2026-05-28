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

void Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ &paddr_read__Vfuncrtn);
void Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ data);

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__0(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__ifu_lfsr = vlSelfRef.__PVT__ifu_lfsr;
    vlSelfRef.__Vdly__lsu_lfsr = vlSelfRef.__PVT__lsu_lfsr;
    vlSelfRef.__Vdly__ifu_rdata_buf = vlSelfRef.__PVT__ifu_rdata_buf;
    vlSelfRef.__Vdly__ifu_delay_target = vlSelfRef.__PVT__ifu_delay_target;
    vlSelfRef.__Vdly__ifu_delay_cnt = vlSelfRef.__PVT__ifu_delay_cnt;
    vlSelfRef.__Vdly__ifu_mem_busy = vlSelfRef.__PVT__ifu_mem_busy;
    vlSelfRef.__Vdly__ifu_respValid = vlSelfRef.__PVT__ifu_respValid;
    vlSelfRef.__Vdly__lsu_delay_cnt = vlSelfRef.__PVT__lsu_delay_cnt;
    vlSelfRef.__Vdly__lsu_rdata_buf = vlSelfRef.__PVT__lsu_rdata_buf;
    vlSelfRef.__Vdly__lsu_delay_target = vlSelfRef.__PVT__lsu_delay_target;
    vlSelfRef.__Vdly__lsu_respValid = vlSelfRef.__PVT__lsu_respValid;
    vlSelfRef.__Vdly__lsu_mem_busy = vlSelfRef.__PVT__lsu_mem_busy;
    vlSelfRef.__Vdly__ifu_rdata = vlSelfRef.__PVT__ifu_rdata;
    vlSelfRef.__Vdly__lsu_rdata = vlSelfRef.__PVT__lsu_rdata;
    vlSelfRef.__Vdly__ifu_lfsr = ((IData)(vlSelfRef.rst_n)
                                   ? VL_CONCAT_III(8,7,1, 
                                                   (0x7fU 
                                                    & VL_SEL_IIII(8, (IData)(vlSelfRef.__PVT__ifu_lfsr), 0U, 7U)), 
                                                   (1U 
                                                    & (((VL_BITSEL_IIII(8, (IData)(vlSelfRef.__PVT__ifu_lfsr), 7U) 
                                                         ^ 
                                                         VL_BITSEL_IIII(8, (IData)(vlSelfRef.__PVT__ifu_lfsr), 5U)) 
                                                        ^ 
                                                        VL_BITSEL_IIII(8, (IData)(vlSelfRef.__PVT__ifu_lfsr), 4U)) 
                                                       ^ 
                                                       VL_BITSEL_IIII(8, (IData)(vlSelfRef.__PVT__ifu_lfsr), 3U))))
                                   : 0xa5U);
    vlSelfRef.__Vdly__lsu_lfsr = ((IData)(vlSelfRef.rst_n)
                                   ? VL_CONCAT_III(8,7,1, 
                                                   (0x7fU 
                                                    & VL_SEL_IIII(8, (IData)(vlSelfRef.__PVT__lsu_lfsr), 0U, 7U)), 
                                                   (1U 
                                                    & (((VL_BITSEL_IIII(8, (IData)(vlSelfRef.__PVT__lsu_lfsr), 7U) 
                                                         ^ 
                                                         VL_BITSEL_IIII(8, (IData)(vlSelfRef.__PVT__lsu_lfsr), 5U)) 
                                                        ^ 
                                                        VL_BITSEL_IIII(8, (IData)(vlSelfRef.__PVT__lsu_lfsr), 4U)) 
                                                       ^ 
                                                       VL_BITSEL_IIII(8, (IData)(vlSelfRef.__PVT__lsu_lfsr), 3U))))
                                   : 0x5aU);
    if (vlSelfRef.rst_n) {
        if (((IData)(vlSelfRef.__PVT__ifu_reqValid) 
             & (IData)(vlSelfRef.__PVT__ifu_reqReady))) {
            Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.__PVT__ifu_raddr, vlSelfRef.__Vfunc_paddr_read__0__Vfuncout);
            vlSelfRef.__Vdly__ifu_rdata_buf = vlSelfRef.__Vfunc_paddr_read__0__Vfuncout;
            vlSelfRef.__Vdly__ifu_delay_target = (0xfU 
                                                  & ((IData)(1U) 
                                                     + 
                                                     VL_SEL_IIII(32, 
                                                                 VL_MODDIV_III(32, 
                                                                               VL_EXTEND_II(32,2, 
                                                                                (3U 
                                                                                & VL_SEL_IIII(8, (IData)(vlSelfRef.__PVT__ifu_lfsr), 0U, 2U))), (IData)(3U)), 0U, 4U)));
            vlSelfRef.__Vdly__ifu_delay_cnt = 1U;
            vlSelfRef.__Vdly__ifu_mem_busy = 1U;
            vlSelfRef.__Vdly__ifu_respValid = 0U;
        } else if (((IData)(vlSelfRef.__PVT__ifu_respValid) 
                    & (IData)(vlSelfRef.__PVT__ifu_respReady))) {
            vlSelfRef.__Vdly__ifu_mem_busy = 0U;
            vlSelfRef.__Vdly__ifu_respValid = 0U;
        } else if (((IData)(vlSelfRef.__PVT__ifu_mem_busy) 
                    & (~ (IData)(vlSelfRef.__PVT__ifu_respValid)))) {
            if (((IData)(vlSelfRef.__PVT__ifu_delay_cnt) 
                 >= (IData)(vlSelfRef.__PVT__ifu_delay_target))) {
                vlSelfRef.__Vdly__ifu_respValid = 1U;
                vlSelfRef.__Vdly__ifu_rdata = vlSelfRef.__PVT__ifu_rdata_buf;
            } else {
                vlSelfRef.__Vdly__ifu_delay_cnt = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelfRef.__PVT__ifu_delay_cnt)));
            }
        }
    } else {
        vlSelfRef.__Vdly__ifu_mem_busy = 0U;
        vlSelfRef.__Vdly__ifu_delay_cnt = 0U;
        vlSelfRef.__Vdly__ifu_delay_target = 0U;
        vlSelfRef.__Vdly__ifu_rdata_buf = 0x13U;
        vlSelfRef.__Vdly__ifu_respValid = 0U;
        vlSelfRef.__Vdly__ifu_rdata = 0x13U;
    }
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.__PVT__lsu_mem_busy) {
            if (((IData)(vlSelfRef.__PVT__lsu_respValid) 
                 & (IData)(vlSelfRef.__PVT__lsu_respReady))) {
                vlSelfRef.__Vdly__lsu_mem_busy = 0U;
                vlSelfRef.__Vdly__lsu_respValid = 0U;
            } else if ((1U & (~ (IData)(vlSelfRef.__PVT__lsu_respValid)))) {
                if (((IData)(vlSelfRef.__PVT__lsu_delay_cnt) 
                     >= (IData)(vlSelfRef.__PVT__lsu_delay_target))) {
                    vlSelfRef.__Vdly__lsu_respValid = 1U;
                    vlSelfRef.__Vdly__lsu_rdata = vlSelfRef.__PVT__lsu_rdata_buf;
                } else {
                    vlSelfRef.__Vdly__lsu_delay_cnt 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.__PVT__lsu_delay_cnt)));
                }
            }
        } else {
            vlSelfRef.__Vdly__lsu_respValid = 0U;
            if (((IData)(vlSelfRef.__PVT__lsu_reqValid) 
                 & (IData)(vlSelfRef.__PVT__lsu_reqReady))) {
                if (vlSelfRef.__PVT__lsu_wen) {
                    Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(vlSelfRef.__PVT__lsu_addr, 
                                                                            ([&]() {
                                vlSelfRef.__Vfunc_wmask2len__2__mask 
                                    = vlSelfRef.__PVT__lsu_wmask;
                                {
                                    if (((((1U == (IData)(vlSelfRef.__Vfunc_wmask2len__2__mask)) 
                                           || (2U == (IData)(vlSelfRef.__Vfunc_wmask2len__2__mask))) 
                                          || (4U == (IData)(vlSelfRef.__Vfunc_wmask2len__2__mask))) 
                                         || (8U == (IData)(vlSelfRef.__Vfunc_wmask2len__2__mask)))) {
                                        vlSelfRef.__Vfunc_wmask2len__2__Vfuncout = 1U;
                                        goto __Vlabel1;
                                    } else if (((3U 
                                                 == (IData)(vlSelfRef.__Vfunc_wmask2len__2__mask)) 
                                                || (0xcU 
                                                    == (IData)(vlSelfRef.__Vfunc_wmask2len__2__mask)))) {
                                        vlSelfRef.__Vfunc_wmask2len__2__Vfuncout = 2U;
                                        goto __Vlabel1;
                                    } else {
                                        vlSelfRef.__Vfunc_wmask2len__2__Vfuncout = 4U;
                                        goto __Vlabel1;
                                    }
                                    __Vlabel1: ;
                                }
                            }(), vlSelfRef.__Vfunc_wmask2len__2__Vfuncout), vlSelfRef.__PVT__lsu_wdata);
                    vlSelfRef.__Vdly__lsu_rdata_buf = 0U;
                } else {
                    Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.__PVT__lsu_addr, vlSelfRef.__Vfunc_paddr_read__3__Vfuncout);
                    vlSelfRef.__Vdly__lsu_rdata_buf 
                        = vlSelfRef.__Vfunc_paddr_read__3__Vfuncout;
                }
                vlSelfRef.__Vdly__lsu_delay_target 
                    = (0xfU & ((IData)(1U) + VL_SEL_IIII(32, 
                                                         VL_MODDIV_III(32, 
                                                                       VL_EXTEND_II(32,2, 
                                                                                (3U 
                                                                                & VL_SEL_IIII(8, (IData)(vlSelfRef.__PVT__lsu_lfsr), 0U, 2U))), (IData)(3U)), 0U, 4U)));
                vlSelfRef.__Vdly__lsu_delay_cnt = 1U;
                vlSelfRef.__Vdly__lsu_mem_busy = 1U;
            }
        }
    } else {
        vlSelfRef.__Vdly__lsu_mem_busy = 0U;
        vlSelfRef.__Vdly__lsu_delay_cnt = 0U;
        vlSelfRef.__Vdly__lsu_delay_target = 0U;
        vlSelfRef.__Vdly__lsu_rdata_buf = 0U;
        vlSelfRef.__Vdly__lsu_respValid = 0U;
        vlSelfRef.__Vdly__lsu_rdata = 0U;
    }
    vlSelfRef.__PVT__ifu_rdata_buf = vlSelfRef.__Vdly__ifu_rdata_buf;
    vlSelfRef.__PVT__ifu_lfsr = vlSelfRef.__Vdly__ifu_lfsr;
    vlSelfRef.__PVT__ifu_delay_target = vlSelfRef.__Vdly__ifu_delay_target;
    vlSelfRef.__PVT__ifu_delay_cnt = vlSelfRef.__Vdly__ifu_delay_cnt;
    vlSelfRef.__PVT__ifu_mem_busy = vlSelfRef.__Vdly__ifu_mem_busy;
    vlSelfRef.__PVT__ifu_rdata = vlSelfRef.__Vdly__ifu_rdata;
    vlSelfRef.__PVT__ifu_respValid = vlSelfRef.__Vdly__ifu_respValid;
    vlSelfRef.__PVT__lsu_delay_cnt = vlSelfRef.__Vdly__lsu_delay_cnt;
    vlSelfRef.__PVT__lsu_rdata_buf = vlSelfRef.__Vdly__lsu_rdata_buf;
    vlSelfRef.__PVT__lsu_lfsr = vlSelfRef.__Vdly__lsu_lfsr;
    vlSelfRef.__PVT__lsu_delay_target = vlSelfRef.__Vdly__lsu_delay_target;
    vlSelfRef.__PVT__lsu_rdata = vlSelfRef.__Vdly__lsu_rdata;
    vlSelfRef.__PVT__lsu_respValid = vlSelfRef.__Vdly__lsu_respValid;
    vlSelfRef.__PVT__lsu_mem_busy = vlSelfRef.__Vdly__lsu_mem_busy;
    vlSymsp->TOP__top__u_core.__PVT__ifu_rdata = vlSelfRef.__PVT__ifu_rdata;
    vlSymsp->TOP__top__u_core.__PVT__ifu_respValid 
        = vlSelfRef.__PVT__ifu_respValid;
    vlSymsp->TOP__top__u_core.__PVT__lsu_rdata = vlSelfRef.__PVT__lsu_rdata;
    vlSymsp->TOP__top__u_core.__PVT__lsu_respValid 
        = vlSelfRef.__PVT__lsu_respValid;
    vlSelfRef.__PVT__lsu_reqReady = (1U & (~ (IData)(vlSelfRef.__PVT__lsu_mem_busy)));
    vlSymsp->TOP__top__u_core.__PVT__lsu_reqReady = vlSelfRef.__PVT__lsu_reqReady;
}

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__1(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc = vlSymsp->TOP__top__u_core.__PVT__pc;
}

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__2(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__ifu_raddr = vlSymsp->TOP__top__u_core.__PVT__ifu_raddr;
}

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__3(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__3\n"); );
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

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__4(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__4\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_wb_have = vlSymsp->TOP__top__u_core.__PVT__debug_wb_have;
    vlSelfRef.debug_wb_pc = vlSymsp->TOP__top__u_core.__PVT__debug_wb_pc;
    vlSelfRef.debug_wb_instr = vlSymsp->TOP__top__u_core.__PVT__debug_wb_instr;
}

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__5(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__5\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_wb_addr = vlSymsp->TOP__top__u_core.__PVT__debug_wb_addr;
    vlSelfRef.debug_wb_en = vlSymsp->TOP__top__u_core.__PVT__debug_wb_en;
    vlSelfRef.debug_wb_data = vlSymsp->TOP__top__u_core.__PVT__debug_wb_data;
}

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__6(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__6\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__lsu_respReady = vlSymsp->TOP__top__u_core.__PVT__lsu_respReady;
}

VL_INLINE_OPT void Vtop_top___nba_sequent__TOP__top__7(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_sequent__TOP__top__7\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__lsu_wdata = vlSymsp->TOP__top__u_core.__PVT__lsu_wdata;
    vlSelfRef.__PVT__lsu_addr = vlSymsp->TOP__top__u_core.__PVT__lsu_addr;
    vlSelfRef.__PVT__lsu_wen = vlSymsp->TOP__top__u_core.__PVT__lsu_wen;
    vlSelfRef.__PVT__lsu_ren = vlSymsp->TOP__top__u_core.__PVT__lsu_ren;
    vlSelfRef.__PVT__lsu_wmask = vlSymsp->TOP__top__u_core.__PVT__lsu_wmask;
}

VL_INLINE_OPT void Vtop_top___nba_comb__TOP__top__0(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_comb__TOP__top__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__lsu_reqValid = vlSymsp->TOP__top__u_core.__PVT__lsu_reqValid;
}

VL_INLINE_OPT void Vtop_top___nba_comb__TOP__top__1(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_comb__TOP__top__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__ifu_respReady = vlSymsp->TOP__top__u_core.__PVT__ifu_respReady;
    vlSelfRef.instr = vlSymsp->TOP__top__u_core.__PVT__instr;
}

VL_INLINE_OPT void Vtop_top___nba_comb__TOP__top__2(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___nba_comb__TOP__top__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__ifu_reqValid = vlSymsp->TOP__top__u_core.__PVT__ifu_reqValid;
}
