// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_memory.h"

void Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ len, IData/*31:0*/ data);

VL_INLINE_OPT void Vtop_memory___nba_sequent__TOP__top__u_memory__0(Vtop_memory* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_memory___nba_sequent__TOP__top__u_memory__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x23U == (IData)(vlSelfRef.__PVT__opcode_in))) {
        if ((0U == (IData)(vlSelfRef.__PVT__funct3_in))) {
            Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(vlSelfRef.__PVT__alu_result_in, 1U, vlSelfRef.__PVT__rs2_data_in);
        } else if ((1U == (IData)(vlSelfRef.__PVT__funct3_in))) {
            Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(vlSelfRef.__PVT__alu_result_in, 2U, vlSelfRef.__PVT__rs2_data_in);
        } else if ((2U == (IData)(vlSelfRef.__PVT__funct3_in))) {
            Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(vlSelfRef.__PVT__alu_result_in, 4U, vlSelfRef.__PVT__rs2_data_in);
        } else {
            Vtop___024unit____Vdpiimwrap_paddr_write_TOP____024unit(vlSelfRef.__PVT__alu_result_in, 4U, vlSelfRef.__PVT__rs2_data_in);
        }
    }
}

void Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ &paddr_read__Vfuncrtn);

VL_INLINE_OPT void Vtop_memory___nba_sequent__TOP__top__u_memory__1(Vtop_memory* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_memory___nba_sequent__TOP__top__u_memory__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__rdata_raw = 0U;
    vlSelfRef.__PVT__mem_rdata_out = 0U;
    if ((3U == (IData)(vlSelfRef.__PVT__opcode_in))) {
        Vtop___024unit____Vdpiimwrap_paddr_read_TOP____024unit(vlSelfRef.__PVT__alu_result_in, vlSelfRef.__Vfunc_paddr_read__0__Vfuncout);
        vlSelfRef.__PVT__rdata_raw = vlSelfRef.__Vfunc_paddr_read__0__Vfuncout;
        vlSelfRef.__PVT__mem_rdata_out = ((0U == (IData)(vlSelfRef.__PVT__funct3_in))
                                           ? VL_CONCAT_III(32,24,8, 
                                                           (0xffffffU 
                                                            & VL_REPLICATE_IOI(1,
                                                                               (1U 
                                                                                & VL_BITSEL_IIII(32, vlSelfRef.__PVT__rdata_raw, 7U)), 0x18U)), 
                                                           (0xffU 
                                                            & VL_SEL_IIII(32, vlSelfRef.__PVT__rdata_raw, 0U, 8U)))
                                           : ((4U == (IData)(vlSelfRef.__PVT__funct3_in))
                                               ? VL_EXTEND_II(32,8, 
                                                              (0xffU 
                                                               & VL_SEL_IIII(32, vlSelfRef.__PVT__rdata_raw, 0U, 8U)))
                                               : ((1U 
                                                   == (IData)(vlSelfRef.__PVT__funct3_in))
                                                   ? 
                                                  VL_CONCAT_III(32,16,16, 
                                                                (0xffffU 
                                                                 & VL_REPLICATE_IOI(1,
                                                                                (1U 
                                                                                & VL_BITSEL_IIII(32, vlSelfRef.__PVT__rdata_raw, 0xfU)), 0x10U)), 
                                                                (0xffffU 
                                                                 & VL_SEL_IIII(32, vlSelfRef.__PVT__rdata_raw, 0U, 0x10U)))
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlSelfRef.__PVT__funct3_in))
                                                    ? 
                                                   VL_EXTEND_II(32,16, 
                                                                (0xffffU 
                                                                 & VL_SEL_IIII(32, vlSelfRef.__PVT__rdata_raw, 0U, 0x10U)))
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelfRef.__PVT__funct3_in))
                                                     ? vlSelfRef.__PVT__rdata_raw
                                                     : 0U)))));
    }
}
