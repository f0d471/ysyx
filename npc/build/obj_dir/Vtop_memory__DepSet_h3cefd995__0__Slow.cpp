// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_memory.h"

VL_ATTR_COLD void Vtop_memory___stl_sequent__TOP__top__u_core__u_memory__0(Vtop_memory* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_memory___stl_sequent__TOP__top__u_core__u_memory__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__lsu_wdata = vlSelfRef.__PVT__rs2_data_in;
    vlSelfRef.__PVT__lsu_addr = vlSelfRef.__PVT__alu_result_in;
    vlSelfRef.__PVT__is_store = ((IData)(vlSelfRef.__PVT__valid_in) 
                                 & (0x23U == (IData)(vlSelfRef.__PVT__opcode_in)));
    vlSelfRef.__PVT__is_load = ((IData)(vlSelfRef.__PVT__valid_in) 
                                & (3U == (IData)(vlSelfRef.__PVT__opcode_in)));
    vlSelfRef.__PVT__lsu_wen = vlSelfRef.__PVT__is_store;
    if (vlSelfRef.__PVT__is_store) {
        if ((0U == (IData)(vlSelfRef.__PVT__funct3_in))) {
            if ((0U == (3U & VL_SEL_IIII(32, vlSelfRef.__PVT__alu_result_in, 0U, 2U)))) {
                vlSelfRef.__PVT__lsu_wmask = 1U;
            } else if ((1U == (3U & VL_SEL_IIII(32, vlSelfRef.__PVT__alu_result_in, 0U, 2U)))) {
                vlSelfRef.__PVT__lsu_wmask = 2U;
            } else if ((2U == (3U & VL_SEL_IIII(32, vlSelfRef.__PVT__alu_result_in, 0U, 2U)))) {
                vlSelfRef.__PVT__lsu_wmask = 4U;
            } else if ((3U == (3U & VL_SEL_IIII(32, vlSelfRef.__PVT__alu_result_in, 0U, 2U)))) {
                vlSelfRef.__PVT__lsu_wmask = 8U;
            }
        } else {
            vlSelfRef.__PVT__lsu_wmask = ((1U == (IData)(vlSelfRef.__PVT__funct3_in))
                                           ? ((1U & 
                                               VL_BITSEL_IIII(32, vlSelfRef.__PVT__alu_result_in, 1U))
                                               ? 0xcU
                                               : 3U)
                                           : 0xfU);
        }
    } else {
        vlSelfRef.__PVT__lsu_wmask = 0U;
    }
    vlSelfRef.__PVT__state_next = ((1U & (~ (IData)(vlSelfRef.__PVT__state))) 
                                   && (IData)(vlSelfRef.__PVT__is_load));
    vlSelfRef.__PVT__lsu_ren = vlSelfRef.__PVT__is_load;
    vlSelfRef.__PVT__lsu_busy = ((IData)(vlSelfRef.__PVT__is_load) 
                                 & (~ (IData)(vlSelfRef.__PVT__state)));
    vlSelfRef.__PVT__mem_rdata_out = 0U;
    if (((IData)(vlSelfRef.__PVT__is_load) & (IData)(vlSelfRef.__PVT__state))) {
        vlSelfRef.__PVT__mem_rdata_out = ((0U == (IData)(vlSelfRef.__PVT__funct3_in))
                                           ? VL_CONCAT_III(32,24,8, 
                                                           (0xffffffU 
                                                            & VL_REPLICATE_IOI(1,
                                                                               (1U 
                                                                                & VL_BITSEL_IIII(32, vlSelfRef.__PVT__lsu_rdata, 7U)), 0x18U)), 
                                                           (0xffU 
                                                            & VL_SEL_IIII(32, vlSelfRef.__PVT__lsu_rdata, 0U, 8U)))
                                           : ((4U == (IData)(vlSelfRef.__PVT__funct3_in))
                                               ? VL_EXTEND_II(32,8, 
                                                              (0xffU 
                                                               & VL_SEL_IIII(32, vlSelfRef.__PVT__lsu_rdata, 0U, 8U)))
                                               : ((1U 
                                                   == (IData)(vlSelfRef.__PVT__funct3_in))
                                                   ? 
                                                  VL_CONCAT_III(32,16,16, 
                                                                (0xffffU 
                                                                 & VL_REPLICATE_IOI(1,
                                                                                (1U 
                                                                                & VL_BITSEL_IIII(32, vlSelfRef.__PVT__lsu_rdata, 0xfU)), 0x10U)), 
                                                                (0xffffU 
                                                                 & VL_SEL_IIII(32, vlSelfRef.__PVT__lsu_rdata, 0U, 0x10U)))
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlSelfRef.__PVT__funct3_in))
                                                    ? 
                                                   VL_EXTEND_II(32,16, 
                                                                (0xffffU 
                                                                 & VL_SEL_IIII(32, vlSelfRef.__PVT__lsu_rdata, 0U, 0x10U)))
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelfRef.__PVT__funct3_in))
                                                     ? vlSelfRef.__PVT__lsu_rdata
                                                     : 0U)))));
    }
}

VL_ATTR_COLD void Vtop_memory___ctor_var_reset(Vtop_memory* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_memory___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__clk = 0;
    vlSelf->__PVT__rst_n = 0;
    vlSelf->__PVT__valid_in = 0;
    vlSelf->__PVT__alu_result_in = 0;
    vlSelf->__PVT__rs2_data_in = 0;
    vlSelf->__PVT__opcode_in = 0;
    vlSelf->__PVT__funct3_in = 0;
    vlSelf->__PVT__lsu_addr = 0;
    vlSelf->__PVT__lsu_ren = 0;
    vlSelf->__PVT__lsu_wen = 0;
    vlSelf->__PVT__lsu_wdata = 0;
    vlSelf->__PVT__lsu_wmask = 0;
    vlSelf->__PVT__lsu_rdata = 0;
    vlSelf->__PVT__lsu_busy = 0;
    vlSelf->__PVT__mem_rdata_out = 0;
    vlSelf->__PVT__is_load = 0;
    vlSelf->__PVT__is_store = 0;
    vlSelf->__PVT__state = 0;
    vlSelf->__PVT__state_next = 0;
    vlSelf->__Vdly__state = 0;
}
