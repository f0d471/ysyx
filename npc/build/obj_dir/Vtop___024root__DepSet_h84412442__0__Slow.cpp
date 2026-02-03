// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop_pc_counter___eval_static__TOP__top__u_pc_counter(Vtop_pc_counter* vlSelf);
VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_pc_counter___eval_static__TOP__top__u_pc_counter((&vlSymsp->TOP__top__u_pc_counter));
    Vtop___024root____Vm_traceActivitySetAll(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_memory____PVT__clk__0 
        = vlSymsp->TOP__top__u_memory.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_reg_file____PVT__clk__0 
        = vlSymsp->TOP__top__u_reg_file.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_reg_file____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_reg_file.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_pc_counter____PVT__clk__0 
        = vlSymsp->TOP__top__u_pc_counter.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_pc_counter____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_pc_counter.__PVT__rst_n;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vtop_reg_file___stl_sequent__TOP__top__u_reg_file__0(Vtop_reg_file* vlSelf);
VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop_pc_counter___stl_sequent__TOP__top__u_pc_counter__0(Vtop_pc_counter* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__0(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__1(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop_fetch___stl_sequent__TOP__top__u_fetch__0(Vtop_fetch* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__1(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__2(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop_if2id___stl_sequent__TOP__top__u_if2id__0(Vtop_if2id* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__2(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop_decode___stl_sequent__TOP__top__u_decode__0(Vtop_decode* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__3(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop_reg_file___stl_sequent__TOP__top__u_reg_file__1(Vtop_reg_file* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__4(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop_id2ex___stl_sequent__TOP__top__u_id2ex__0(Vtop_id2ex* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__5(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop_execute___stl_sequent__TOP__top__u_execute__0(Vtop_execute* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__6(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop_ex2mem___stl_sequent__TOP__top__u_ex2mem__0(Vtop_ex2mem* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__7(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop_memory___stl_sequent__TOP__top__u_memory__0(Vtop_memory* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__8(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop_mem2wb___stl_sequent__TOP__top__u_mem2wb__0(Vtop_mem2wb* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__9(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop_writeback___stl_sequent__TOP__top__u_writeback__0(Vtop_writeback* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__10(Vtop_top* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop_reg_file___stl_sequent__TOP__top__u_reg_file__0((&vlSymsp->TOP__top__u_reg_file));
        Vtop___024root____Vm_traceActivitySetAll(vlSelf);
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop_pc_counter___stl_sequent__TOP__top__u_pc_counter__0((&vlSymsp->TOP__top__u_pc_counter));
        Vtop_top___stl_sequent__TOP__top__0((&vlSymsp->TOP__top));
        Vtop___024root___stl_sequent__TOP__1(vlSelf);
        Vtop_fetch___stl_sequent__TOP__top__u_fetch__0((&vlSymsp->TOP__top__u_fetch));
        Vtop_top___stl_sequent__TOP__top__1((&vlSymsp->TOP__top));
        Vtop___024root___stl_sequent__TOP__2(vlSelf);
        Vtop_if2id___stl_sequent__TOP__top__u_if2id__0((&vlSymsp->TOP__top__u_if2id));
        Vtop_top___stl_sequent__TOP__top__2((&vlSymsp->TOP__top));
        Vtop_decode___stl_sequent__TOP__top__u_decode__0((&vlSymsp->TOP__top__u_decode));
        Vtop_top___stl_sequent__TOP__top__3((&vlSymsp->TOP__top));
        Vtop_reg_file___stl_sequent__TOP__top__u_reg_file__1((&vlSymsp->TOP__top__u_reg_file));
        Vtop_top___stl_sequent__TOP__top__4((&vlSymsp->TOP__top));
        Vtop_id2ex___stl_sequent__TOP__top__u_id2ex__0((&vlSymsp->TOP__top__u_id2ex));
        Vtop_top___stl_sequent__TOP__top__5((&vlSymsp->TOP__top));
        Vtop_execute___stl_sequent__TOP__top__u_execute__0((&vlSymsp->TOP__top__u_execute));
        Vtop_top___stl_sequent__TOP__top__6((&vlSymsp->TOP__top));
        Vtop_ex2mem___stl_sequent__TOP__top__u_ex2mem__0((&vlSymsp->TOP__top__u_ex2mem));
        Vtop_top___stl_sequent__TOP__top__7((&vlSymsp->TOP__top));
        Vtop_memory___stl_sequent__TOP__top__u_memory__0((&vlSymsp->TOP__top__u_memory));
        Vtop_top___stl_sequent__TOP__top__8((&vlSymsp->TOP__top));
        Vtop_mem2wb___stl_sequent__TOP__top__u_mem2wb__0((&vlSymsp->TOP__top__u_mem2wb));
        Vtop_top___stl_sequent__TOP__top__9((&vlSymsp->TOP__top));
        Vtop_writeback___stl_sequent__TOP__top__u_writeback__0((&vlSymsp->TOP__top__u_writeback));
        Vtop_top___stl_sequent__TOP__top__10((&vlSymsp->TOP__top));
    }
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__top.clk = vlSelfRef.clk;
    vlSymsp->TOP__top.rst_n = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__1(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_x10 = vlSymsp->TOP__top.debug_x10;
    vlSelfRef.regs[0xfU] = vlSymsp->TOP__top.regs[0xfU];
    vlSelfRef.regs[0xeU] = vlSymsp->TOP__top.regs[0xeU];
    vlSelfRef.regs[0xdU] = vlSymsp->TOP__top.regs[0xdU];
    vlSelfRef.regs[0xcU] = vlSymsp->TOP__top.regs[0xcU];
    vlSelfRef.regs[0xbU] = vlSymsp->TOP__top.regs[0xbU];
    vlSelfRef.regs[0xaU] = vlSymsp->TOP__top.regs[0xaU];
    vlSelfRef.regs[9U] = vlSymsp->TOP__top.regs[9U];
    vlSelfRef.regs[8U] = vlSymsp->TOP__top.regs[8U];
    vlSelfRef.regs[7U] = vlSymsp->TOP__top.regs[7U];
    vlSelfRef.regs[6U] = vlSymsp->TOP__top.regs[6U];
    vlSelfRef.regs[5U] = vlSymsp->TOP__top.regs[5U];
    vlSelfRef.regs[4U] = vlSymsp->TOP__top.regs[4U];
    vlSelfRef.regs[3U] = vlSymsp->TOP__top.regs[3U];
    vlSelfRef.regs[2U] = vlSymsp->TOP__top.regs[2U];
    vlSelfRef.regs[1U] = vlSymsp->TOP__top.regs[1U];
    vlSelfRef.regs[0U] = vlSymsp->TOP__top.regs[0U];
    vlSelfRef.pc = vlSymsp->TOP__top.pc;
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__2(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.instr = vlSymsp->TOP__top.instr;
}
