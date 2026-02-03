// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_fetch.h"

void Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ &paddr_read__Vfuncrtn);

VL_INLINE_OPT void Vtop_fetch___ico_sequent__TOP__top__u_fetch__0(Vtop_fetch* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_fetch___ico_sequent__TOP__top__u_fetch__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__rst_n) {
        Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.__PVT__pc_pointer, vlSelfRef.__Vfunc_paddr_read__0__Vfuncout);
        vlSelfRef.__PVT__instr_out = vlSelfRef.__Vfunc_paddr_read__0__Vfuncout;
    } else {
        vlSelfRef.__PVT__instr_out = 0x13U;
    }
}

VL_INLINE_OPT void Vtop_fetch___nba_sequent__TOP__top__u_fetch__0(Vtop_fetch* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_fetch___nba_sequent__TOP__top__u_fetch__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__rst_n) {
        Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.__PVT__pc_pointer, vlSelfRef.__Vfunc_paddr_read__0__Vfuncout);
        vlSelfRef.__PVT__instr_out = vlSelfRef.__Vfunc_paddr_read__0__Vfuncout;
    } else {
        vlSelfRef.__PVT__instr_out = 0x13U;
    }
}
