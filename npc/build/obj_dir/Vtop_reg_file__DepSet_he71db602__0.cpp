// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_reg_file.h"

VL_INLINE_OPT void Vtop_reg_file___nba_sequent__TOP__top__u_core__u_reg_file__0(Vtop_reg_file* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_reg_file___nba_sequent__TOP__top__u_core__u_reg_file__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__rf__v0 = 0U;
    vlSelfRef.__VdlySet__rf__v1 = 0U;
    vlSelfRef.__VdlySet__rf__v2 = 0U;
    vlSelfRef.__VdlySet__rf__v3 = 0U;
    vlSelfRef.__VdlySet__rf__v4 = 0U;
    vlSelfRef.__VdlySet__rf__v5 = 0U;
    vlSelfRef.__VdlySet__rf__v6 = 0U;
    vlSelfRef.__VdlySet__rf__v7 = 0U;
    vlSelfRef.__VdlySet__rf__v8 = 0U;
    vlSelfRef.__VdlySet__rf__v9 = 0U;
    vlSelfRef.__VdlySet__rf__v10 = 0U;
    vlSelfRef.__VdlySet__rf__v11 = 0U;
    vlSelfRef.__VdlySet__rf__v12 = 0U;
    vlSelfRef.__VdlySet__rf__v13 = 0U;
    vlSelfRef.__VdlySet__rf__v14 = 0U;
    vlSelfRef.__VdlySet__rf__v15 = 0U;
    vlSelfRef.__VdlySet__rf__v16 = 0U;
    if (vlSelfRef.__PVT__rst_n) {
        if ((((IData)(vlSelfRef.__PVT__wr_en) & (0U 
                                                 != (IData)(vlSelfRef.__PVT__wr_addr))) 
             & (0x10U > (IData)(vlSelfRef.__PVT__wr_addr)))) {
            vlSelfRef.__VdlyVal__rf__v0 = vlSelfRef.__PVT__wr_data;
            vlSelfRef.__VdlyDim0__rf__v0 = (0xfU & 
                                            VL_SEL_IIII(5, (IData)(vlSelfRef.__PVT__wr_addr), 0U, 4U));
            vlSelfRef.__VdlySet__rf__v0 = 1U;
        }
    } else {
        vlSelfRef.__VdlySet__rf__v1 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 1U;
        vlSelfRef.__VdlySet__rf__v2 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 2U;
        vlSelfRef.__VdlySet__rf__v3 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 3U;
        vlSelfRef.__VdlySet__rf__v4 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 4U;
        vlSelfRef.__VdlySet__rf__v5 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 5U;
        vlSelfRef.__VdlySet__rf__v6 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 6U;
        vlSelfRef.__VdlySet__rf__v7 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 7U;
        vlSelfRef.__VdlySet__rf__v8 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 8U;
        vlSelfRef.__VdlySet__rf__v9 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 9U;
        vlSelfRef.__VdlySet__rf__v10 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 0xaU;
        vlSelfRef.__VdlySet__rf__v11 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 0xbU;
        vlSelfRef.__VdlySet__rf__v12 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 0xcU;
        vlSelfRef.__VdlySet__rf__v13 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 0xdU;
        vlSelfRef.__VdlySet__rf__v14 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 0xeU;
        vlSelfRef.__VdlySet__rf__v15 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 0xfU;
        vlSelfRef.__VdlySet__rf__v16 = 1U;
        vlSelfRef.__PVT__unnamedblk1__DOT__i = 0x10U;
    }
    if (vlSelfRef.__VdlySet__rf__v0) {
        vlSelfRef.__PVT__rf[vlSelfRef.__VdlyDim0__rf__v0] 
            = vlSelfRef.__VdlyVal__rf__v0;
    }
    if (vlSelfRef.__VdlySet__rf__v1) {
        vlSelfRef.__PVT__rf[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v2) {
        vlSelfRef.__PVT__rf[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v3) {
        vlSelfRef.__PVT__rf[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v4) {
        vlSelfRef.__PVT__rf[3U] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v5) {
        vlSelfRef.__PVT__rf[4U] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v6) {
        vlSelfRef.__PVT__rf[5U] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v7) {
        vlSelfRef.__PVT__rf[6U] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v8) {
        vlSelfRef.__PVT__rf[7U] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v9) {
        vlSelfRef.__PVT__rf[8U] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v10) {
        vlSelfRef.__PVT__rf[9U] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v11) {
        vlSelfRef.__PVT__rf[0xaU] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v12) {
        vlSelfRef.__PVT__rf[0xbU] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v13) {
        vlSelfRef.__PVT__rf[0xcU] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v14) {
        vlSelfRef.__PVT__rf[0xdU] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v15) {
        vlSelfRef.__PVT__rf[0xeU] = 0U;
    }
    if (vlSelfRef.__VdlySet__rf__v16) {
        vlSelfRef.__PVT__rf[0xfU] = 0U;
    }
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

VL_INLINE_OPT void Vtop_reg_file___nba_comb__TOP__top__u_core__u_reg_file__0(Vtop_reg_file* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_reg_file___nba_comb__TOP__top__u_core__u_reg_file__0\n"); );
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
