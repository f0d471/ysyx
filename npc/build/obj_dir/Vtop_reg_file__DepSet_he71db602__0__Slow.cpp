// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_reg_file.h"

VL_ATTR_COLD void Vtop_reg_file___stl_sequent__TOP__top__u_reg_file__0(Vtop_reg_file* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_reg_file___stl_sequent__TOP__top__u_reg_file__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__debug_x10 = vlSelfRef.__PVT__rf
        [0xaU];
    vlSelfRef.__PVT__regs[0U] = vlSelfRef.__PVT__rf
        [0U];
    vlSelfRef.__PVT__regs[1U] = vlSelfRef.__PVT__rf
        [1U];
    vlSelfRef.__PVT__regs[2U] = vlSelfRef.__PVT__rf
        [2U];
    vlSelfRef.__PVT__regs[3U] = vlSelfRef.__PVT__rf
        [3U];
    vlSelfRef.__PVT__regs[4U] = vlSelfRef.__PVT__rf
        [4U];
    vlSelfRef.__PVT__regs[5U] = vlSelfRef.__PVT__rf
        [5U];
    vlSelfRef.__PVT__regs[6U] = vlSelfRef.__PVT__rf
        [6U];
    vlSelfRef.__PVT__regs[7U] = vlSelfRef.__PVT__rf
        [7U];
    vlSelfRef.__PVT__regs[8U] = vlSelfRef.__PVT__rf
        [8U];
    vlSelfRef.__PVT__regs[9U] = vlSelfRef.__PVT__rf
        [9U];
    vlSelfRef.__PVT__regs[0xaU] = vlSelfRef.__PVT__rf
        [0xaU];
    vlSelfRef.__PVT__regs[0xbU] = vlSelfRef.__PVT__rf
        [0xbU];
    vlSelfRef.__PVT__regs[0xcU] = vlSelfRef.__PVT__rf
        [0xcU];
    vlSelfRef.__PVT__regs[0xdU] = vlSelfRef.__PVT__rf
        [0xdU];
    vlSelfRef.__PVT__regs[0xeU] = vlSelfRef.__PVT__rf
        [0xeU];
    vlSelfRef.__PVT__regs[0xfU] = vlSelfRef.__PVT__rf
        [0xfU];
}

VL_ATTR_COLD void Vtop_reg_file___stl_sequent__TOP__top__u_reg_file__1(Vtop_reg_file* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_reg_file___stl_sequent__TOP__top__u_reg_file__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rs1_data = (((0U == (IData)(vlSelfRef.__PVT__rs1_addr)) 
                                  | (0x10U <= (IData)(vlSelfRef.__PVT__rs1_addr)))
                                  ? 0U : vlSelfRef.__PVT__rf
                                 [(0xfU & VL_SEL_IIII(5, (IData)(vlSelfRef.__PVT__rs1_addr), 0U, 4U))]);
    vlSelfRef.__PVT__rs2_data = (((0U == (IData)(vlSelfRef.__PVT__rs2_addr)) 
                                  | (0x10U <= (IData)(vlSelfRef.__PVT__rs2_addr)))
                                  ? 0U : vlSelfRef.__PVT__rf
                                 [(0xfU & VL_SEL_IIII(5, (IData)(vlSelfRef.__PVT__rs2_addr), 0U, 4U))]);
}

VL_ATTR_COLD void Vtop_reg_file___ctor_var_reset(Vtop_reg_file* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_reg_file___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__clk = 0;
    vlSelf->__PVT__rst_n = 0;
    vlSelf->__PVT__rs1_addr = 0;
    vlSelf->__PVT__rs2_addr = 0;
    vlSelf->__PVT__rs1_data = 0;
    vlSelf->__PVT__rs2_data = 0;
    vlSelf->__PVT__wr_en = 0;
    vlSelf->__PVT__wr_addr = 0;
    vlSelf->__PVT__wr_data = 0;
    vlSelf->__PVT__debug_x10 = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__regs[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->__PVT__rf[__Vi0] = 0;
    }
    vlSelf->__PVT__unnamedblk1__DOT__i = 0;
    vlSelf->__VdlyVal__rf__v0 = 0;
    vlSelf->__VdlyDim0__rf__v0 = 0;
    vlSelf->__VdlySet__rf__v0 = 0;
    vlSelf->__VdlySet__rf__v1 = 0;
    vlSelf->__VdlySet__rf__v2 = 0;
    vlSelf->__VdlySet__rf__v3 = 0;
    vlSelf->__VdlySet__rf__v4 = 0;
    vlSelf->__VdlySet__rf__v5 = 0;
    vlSelf->__VdlySet__rf__v6 = 0;
    vlSelf->__VdlySet__rf__v7 = 0;
    vlSelf->__VdlySet__rf__v8 = 0;
    vlSelf->__VdlySet__rf__v9 = 0;
    vlSelf->__VdlySet__rf__v10 = 0;
    vlSelf->__VdlySet__rf__v11 = 0;
    vlSelf->__VdlySet__rf__v12 = 0;
    vlSelf->__VdlySet__rf__v13 = 0;
    vlSelf->__VdlySet__rf__v14 = 0;
    vlSelf->__VdlySet__rf__v15 = 0;
    vlSelf->__VdlySet__rf__v16 = 0;
}
