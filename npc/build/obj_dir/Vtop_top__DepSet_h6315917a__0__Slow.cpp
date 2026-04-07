// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_top.h"

VL_ATTR_COLD void Vtop_top___ctor_var_reset(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = 0;
    vlSelf->rst_n = 0;
    vlSelf->pc = 0;
    vlSelf->instr = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->regs[__Vi0] = 0;
    }
    vlSelf->debug_wb_have = 0;
    vlSelf->debug_wb_pc = 0;
    vlSelf->debug_wb_instr = 0;
    vlSelf->debug_wb_en = 0;
    vlSelf->debug_wb_addr = 0;
    vlSelf->debug_wb_data = 0;
    vlSelf->__PVT__ifu_raddr = 0;
    vlSelf->__PVT__ifu_rdata = 0;
    vlSelf->__PVT__lsu_addr = 0;
    vlSelf->__PVT__lsu_ren = 0;
    vlSelf->__PVT__lsu_wen = 0;
    vlSelf->__PVT__lsu_wdata = 0;
    vlSelf->__PVT__lsu_wmask = 0;
    vlSelf->__PVT__lsu_rdata = 0;
    vlSelf->__Vfunc_paddr_read__0__Vfuncout = 0;
    vlSelf->__Vfunc_paddr_read__1__Vfuncout = 0;
    vlSelf->__Vfunc_wmask2len__3__Vfuncout = 0;
    vlSelf->__Vfunc_wmask2len__3__mask = 0;
    vlSelf->__Vdly__ifu_rdata = 0;
    vlSelf->__Vdly__lsu_rdata = 0;
}
