// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_top.h"

VL_ATTR_COLD void Vtop_top___eval_initial__TOP__top(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___eval_initial__TOP__top\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__top__u_sram_ifu.__PVT__wmask = 0U;
    vlSymsp->TOP__top__u_sram_ifu.__PVT__wdata = 0U;
    vlSymsp->TOP__top__u_sram_ifu.__PVT__wen = 0U;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__0(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__ifu_rdata = vlSymsp->TOP__top__u_sram_ifu.__PVT__rdata;
    vlSelfRef.__PVT__ifu_respValid = vlSymsp->TOP__top__u_sram_ifu.__PVT__respValid;
    vlSelfRef.__PVT__lsu_rdata = vlSymsp->TOP__top__u_sram_lsu.__PVT__rdata;
    vlSelfRef.__PVT__lsu_respValid = vlSymsp->TOP__top__u_sram_lsu.__PVT__respValid;
    vlSymsp->TOP__top__u_core.__PVT__ifu_rdata = vlSelfRef.__PVT__ifu_rdata;
    vlSymsp->TOP__top__u_core.__PVT__ifu_respValid 
        = vlSelfRef.__PVT__ifu_respValid;
    vlSymsp->TOP__top__u_core.__PVT__lsu_rdata = vlSelfRef.__PVT__lsu_rdata;
    vlSymsp->TOP__top__u_core.__PVT__lsu_respValid 
        = vlSelfRef.__PVT__lsu_respValid;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__1(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__top__u_sram_ifu.__PVT__clk = vlSelfRef.clk;
    vlSymsp->TOP__top__u_sram_lsu.__PVT__clk = vlSelfRef.clk;
    vlSymsp->TOP__top__u_core.__PVT__clk = vlSelfRef.clk;
    vlSymsp->TOP__top__u_sram_ifu.__PVT__rst_n = vlSelfRef.rst_n;
    vlSymsp->TOP__top__u_sram_lsu.__PVT__rst_n = vlSelfRef.rst_n;
    vlSymsp->TOP__top__u_core.__PVT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.pc = vlSymsp->TOP__top__u_core.__PVT__pc;
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
    vlSelfRef.debug_wb_have = vlSymsp->TOP__top__u_core.__PVT__debug_wb_have;
    vlSelfRef.debug_wb_pc = vlSymsp->TOP__top__u_core.__PVT__debug_wb_pc;
    vlSelfRef.debug_wb_instr = vlSymsp->TOP__top__u_core.__PVT__debug_wb_instr;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__2(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__ifu_raddr = vlSymsp->TOP__top__u_core.__PVT__ifu_raddr;
    vlSelfRef.__PVT__lsu_wdata = vlSymsp->TOP__top__u_core.__PVT__lsu_wdata;
    vlSelfRef.__PVT__lsu_addr = vlSymsp->TOP__top__u_core.__PVT__lsu_addr;
    vlSelfRef.__PVT__lsu_wen = vlSymsp->TOP__top__u_core.__PVT__lsu_wen;
    vlSelfRef.__PVT__lsu_wmask = vlSymsp->TOP__top__u_core.__PVT__lsu_wmask;
    vlSelfRef.__PVT__lsu_ren = vlSymsp->TOP__top__u_core.__PVT__lsu_ren;
    vlSelfRef.__PVT__lsu_reqValid = vlSymsp->TOP__top__u_core.__PVT__lsu_reqValid;
    vlSelfRef.debug_wb_addr = vlSymsp->TOP__top__u_core.__PVT__debug_wb_addr;
    vlSelfRef.debug_wb_en = vlSymsp->TOP__top__u_core.__PVT__debug_wb_en;
    vlSelfRef.debug_wb_data = vlSymsp->TOP__top__u_core.__PVT__debug_wb_data;
    vlSymsp->TOP__top__u_sram_ifu.__PVT__addr = vlSelfRef.__PVT__ifu_raddr;
    vlSymsp->TOP__top__u_sram_lsu.__PVT__wdata = vlSelfRef.__PVT__lsu_wdata;
    vlSymsp->TOP__top__u_sram_lsu.__PVT__addr = vlSelfRef.__PVT__lsu_addr;
    vlSymsp->TOP__top__u_sram_lsu.__PVT__wen = vlSelfRef.__PVT__lsu_wen;
    vlSymsp->TOP__top__u_sram_lsu.__PVT__wmask = vlSelfRef.__PVT__lsu_wmask;
    vlSymsp->TOP__top__u_sram_lsu.__PVT__reqValid = vlSelfRef.__PVT__lsu_reqValid;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__3(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__3\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__ifu_reqValid = vlSymsp->TOP__top__u_core.__PVT__ifu_reqValid;
    vlSelfRef.instr = vlSymsp->TOP__top__u_core.__PVT__instr;
    vlSymsp->TOP__top__u_sram_ifu.__PVT__reqValid = vlSelfRef.__PVT__ifu_reqValid;
}
