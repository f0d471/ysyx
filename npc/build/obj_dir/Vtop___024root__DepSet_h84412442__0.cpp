// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.set(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop_top___ico_sequent__TOP__top__0(Vtop_top* vlSelf);
void Vtop_fetch___ico_sequent__TOP__top__u_fetch__0(Vtop_fetch* vlSelf);
void Vtop_top___ico_sequent__TOP__top__1(Vtop_top* vlSelf);
void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop_if2id___ico_sequent__TOP__top__u_if2id__0(Vtop_if2id* vlSelf);
void Vtop_top___ico_sequent__TOP__top__2(Vtop_top* vlSelf);
void Vtop_decode___ico_sequent__TOP__top__u_decode__0(Vtop_decode* vlSelf);
void Vtop_top___ico_sequent__TOP__top__3(Vtop_top* vlSelf);
void Vtop_reg_file___ico_sequent__TOP__top__u_reg_file__0(Vtop_reg_file* vlSelf);
void Vtop_top___ico_sequent__TOP__top__4(Vtop_top* vlSelf);
void Vtop_id2ex___ico_sequent__TOP__top__u_id2ex__0(Vtop_id2ex* vlSelf);
void Vtop_top___ico_sequent__TOP__top__5(Vtop_top* vlSelf);
void Vtop_execute___ico_sequent__TOP__top__u_execute__0(Vtop_execute* vlSelf);
void Vtop_top___ico_sequent__TOP__top__6(Vtop_top* vlSelf);
void Vtop_csr_file___ico_sequent__TOP__top__u_csr_file__0(Vtop_csr_file* vlSelf);
void Vtop_top___ico_sequent__TOP__top__7(Vtop_top* vlSelf);
void Vtop_execute___ico_sequent__TOP__top__u_execute__1(Vtop_execute* vlSelf);
void Vtop_top___ico_sequent__TOP__top__8(Vtop_top* vlSelf);
void Vtop_ex2mem___ico_sequent__TOP__top__u_ex2mem__0(Vtop_ex2mem* vlSelf);
void Vtop_top___ico_sequent__TOP__top__9(Vtop_top* vlSelf);
void Vtop_memory___ico_sequent__TOP__top__u_memory__0(Vtop_memory* vlSelf);
void Vtop_top___ico_sequent__TOP__top__10(Vtop_top* vlSelf);
void Vtop_mem2wb___ico_sequent__TOP__top__u_mem2wb__0(Vtop_mem2wb* vlSelf);
void Vtop_top___ico_sequent__TOP__top__11(Vtop_top* vlSelf);
void Vtop_writeback___ico_sequent__TOP__top__u_writeback__0(Vtop_writeback* vlSelf);
void Vtop_top___ico_sequent__TOP__top__12(Vtop_top* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
        Vtop_top___ico_sequent__TOP__top__0((&vlSymsp->TOP__top));
        Vtop_fetch___ico_sequent__TOP__top__u_fetch__0((&vlSymsp->TOP__top__u_fetch));
        Vtop_top___ico_sequent__TOP__top__1((&vlSymsp->TOP__top));
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
        Vtop_if2id___ico_sequent__TOP__top__u_if2id__0((&vlSymsp->TOP__top__u_if2id));
        Vtop_top___ico_sequent__TOP__top__2((&vlSymsp->TOP__top));
        Vtop_decode___ico_sequent__TOP__top__u_decode__0((&vlSymsp->TOP__top__u_decode));
        Vtop_top___ico_sequent__TOP__top__3((&vlSymsp->TOP__top));
        Vtop_reg_file___ico_sequent__TOP__top__u_reg_file__0((&vlSymsp->TOP__top__u_reg_file));
        Vtop_top___ico_sequent__TOP__top__4((&vlSymsp->TOP__top));
        Vtop_id2ex___ico_sequent__TOP__top__u_id2ex__0((&vlSymsp->TOP__top__u_id2ex));
        Vtop_top___ico_sequent__TOP__top__5((&vlSymsp->TOP__top));
        Vtop_execute___ico_sequent__TOP__top__u_execute__0((&vlSymsp->TOP__top__u_execute));
        Vtop_top___ico_sequent__TOP__top__6((&vlSymsp->TOP__top));
        Vtop_csr_file___ico_sequent__TOP__top__u_csr_file__0((&vlSymsp->TOP__top__u_csr_file));
        Vtop_top___ico_sequent__TOP__top__7((&vlSymsp->TOP__top));
        Vtop_execute___ico_sequent__TOP__top__u_execute__1((&vlSymsp->TOP__top__u_execute));
        Vtop_top___ico_sequent__TOP__top__8((&vlSymsp->TOP__top));
        Vtop_ex2mem___ico_sequent__TOP__top__u_ex2mem__0((&vlSymsp->TOP__top__u_ex2mem));
        Vtop_top___ico_sequent__TOP__top__9((&vlSymsp->TOP__top));
        Vtop_memory___ico_sequent__TOP__top__u_memory__0((&vlSymsp->TOP__top__u_memory));
        Vtop_top___ico_sequent__TOP__top__10((&vlSymsp->TOP__top));
        Vtop_mem2wb___ico_sequent__TOP__top__u_mem2wb__0((&vlSymsp->TOP__top__u_mem2wb));
        Vtop_top___ico_sequent__TOP__top__11((&vlSymsp->TOP__top));
        Vtop_writeback___ico_sequent__TOP__top__u_writeback__0((&vlSymsp->TOP__top__u_writeback));
        Vtop_top___ico_sequent__TOP__top__12((&vlSymsp->TOP__top));
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__top.clk = vlSelfRef.clk;
    vlSymsp->TOP__top.rst_n = vlSelfRef.rst_n;
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.instr = vlSymsp->TOP__top.instr;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSymsp->TOP__top__u_memory.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_memory____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((IData)(vlSymsp->TOP__top__u_csr_file.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_csr_file____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(2U, ((IData)(vlSymsp->TOP__top__u_reg_file.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_reg_file____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(3U, ((~ (IData)(vlSymsp->TOP__top__u_reg_file.__PVT__rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_reg_file____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(4U, ((IData)(vlSymsp->TOP__top__u_pc_counter.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_pc_counter____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(5U, ((~ (IData)(vlSymsp->TOP__top__u_pc_counter.__PVT__rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_pc_counter____PVT__rst_n__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_memory____PVT__clk__0 
        = vlSymsp->TOP__top__u_memory.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_csr_file____PVT__clk__0 
        = vlSymsp->TOP__top__u_csr_file.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_reg_file____PVT__clk__0 
        = vlSymsp->TOP__top__u_reg_file.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_reg_file____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_reg_file.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_pc_counter____PVT__clk__0 
        = vlSymsp->TOP__top__u_pc_counter.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_pc_counter____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_pc_counter.__PVT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vtop_memory___nba_sequent__TOP__top__u_memory__0(Vtop_memory* vlSelf);
void Vtop_csr_file___nba_sequent__TOP__top__u_csr_file__0(Vtop_csr_file* vlSelf);
void Vtop_top___nba_sequent__TOP__top__0(Vtop_top* vlSelf);
void Vtop_reg_file___nba_sequent__TOP__top__u_reg_file__0(Vtop_reg_file* vlSelf);
void Vtop_top___nba_sequent__TOP__top__1(Vtop_top* vlSelf);
void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop_pc_counter___nba_sequent__TOP__top__u_pc_counter__0(Vtop_pc_counter* vlSelf);
void Vtop_top___nba_sequent__TOP__top__2(Vtop_top* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop_fetch___nba_sequent__TOP__top__u_fetch__0(Vtop_fetch* vlSelf);
void Vtop_top___nba_sequent__TOP__top__3(Vtop_top* vlSelf);
void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop_if2id___nba_sequent__TOP__top__u_if2id__0(Vtop_if2id* vlSelf);
void Vtop_top___nba_sequent__TOP__top__4(Vtop_top* vlSelf);
void Vtop_decode___nba_sequent__TOP__top__u_decode__0(Vtop_decode* vlSelf);
void Vtop_top___nba_sequent__TOP__top__5(Vtop_top* vlSelf);
void Vtop_reg_file___nba_comb__TOP__top__u_reg_file__0(Vtop_reg_file* vlSelf);
void Vtop_top___nba_comb__TOP__top__0(Vtop_top* vlSelf);
void Vtop_id2ex___nba_comb__TOP__top__u_id2ex__0(Vtop_id2ex* vlSelf);
void Vtop_top___nba_comb__TOP__top__1(Vtop_top* vlSelf);
void Vtop_execute___nba_comb__TOP__top__u_execute__0(Vtop_execute* vlSelf);
void Vtop_top___nba_comb__TOP__top__2(Vtop_top* vlSelf);
void Vtop_execute___nba_comb__TOP__top__u_execute__1(Vtop_execute* vlSelf);
void Vtop_csr_file___nba_comb__TOP__top__u_csr_file__0(Vtop_csr_file* vlSelf);
void Vtop_top___nba_comb__TOP__top__3(Vtop_top* vlSelf);
void Vtop_execute___nba_comb__TOP__top__u_execute__2(Vtop_execute* vlSelf);
void Vtop_top___nba_comb__TOP__top__4(Vtop_top* vlSelf);
void Vtop_ex2mem___nba_comb__TOP__top__u_ex2mem__0(Vtop_ex2mem* vlSelf);
void Vtop_top___nba_comb__TOP__top__5(Vtop_top* vlSelf);
void Vtop_memory___nba_comb__TOP__top__u_memory__0(Vtop_memory* vlSelf);
void Vtop_top___nba_comb__TOP__top__6(Vtop_top* vlSelf);
void Vtop_mem2wb___nba_comb__TOP__top__u_mem2wb__0(Vtop_mem2wb* vlSelf);
void Vtop_top___nba_comb__TOP__top__7(Vtop_top* vlSelf);
void Vtop_writeback___nba_comb__TOP__top__u_writeback__0(Vtop_writeback* vlSelf);
void Vtop_top___nba_comb__TOP__top__8(Vtop_top* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_memory___nba_sequent__TOP__top__u_memory__0((&vlSymsp->TOP__top__u_memory));
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_csr_file___nba_sequent__TOP__top__u_csr_file__0((&vlSymsp->TOP__top__u_csr_file));
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        Vtop_top___nba_sequent__TOP__top__0((&vlSymsp->TOP__top));
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_reg_file___nba_sequent__TOP__top__u_reg_file__0((&vlSymsp->TOP__top__u_reg_file));
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        Vtop_top___nba_sequent__TOP__top__1((&vlSymsp->TOP__top));
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pc_counter___nba_sequent__TOP__top__u_pc_counter__0((&vlSymsp->TOP__top__u_pc_counter));
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        Vtop_top___nba_sequent__TOP__top__2((&vlSymsp->TOP__top));
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        Vtop_fetch___nba_sequent__TOP__top__u_fetch__0((&vlSymsp->TOP__top__u_fetch));
        Vtop_top___nba_sequent__TOP__top__3((&vlSymsp->TOP__top));
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
        Vtop_if2id___nba_sequent__TOP__top__u_if2id__0((&vlSymsp->TOP__top__u_if2id));
        Vtop_top___nba_sequent__TOP__top__4((&vlSymsp->TOP__top));
        Vtop_decode___nba_sequent__TOP__top__u_decode__0((&vlSymsp->TOP__top__u_decode));
        Vtop_top___nba_sequent__TOP__top__5((&vlSymsp->TOP__top));
    }
    if ((0x3cULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_reg_file___nba_comb__TOP__top__u_reg_file__0((&vlSymsp->TOP__top__u_reg_file));
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
        Vtop_top___nba_comb__TOP__top__0((&vlSymsp->TOP__top));
        Vtop_id2ex___nba_comb__TOP__top__u_id2ex__0((&vlSymsp->TOP__top__u_id2ex));
        Vtop_top___nba_comb__TOP__top__1((&vlSymsp->TOP__top));
        Vtop_execute___nba_comb__TOP__top__u_execute__0((&vlSymsp->TOP__top__u_execute));
        Vtop_top___nba_comb__TOP__top__2((&vlSymsp->TOP__top));
    }
    if ((0x3eULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_execute___nba_comb__TOP__top__u_execute__1((&vlSymsp->TOP__top__u_execute));
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
        Vtop_csr_file___nba_comb__TOP__top__u_csr_file__0((&vlSymsp->TOP__top__u_csr_file));
        Vtop_top___nba_comb__TOP__top__3((&vlSymsp->TOP__top));
        Vtop_execute___nba_comb__TOP__top__u_execute__2((&vlSymsp->TOP__top__u_execute));
        Vtop_top___nba_comb__TOP__top__4((&vlSymsp->TOP__top));
        Vtop_ex2mem___nba_comb__TOP__top__u_ex2mem__0((&vlSymsp->TOP__top__u_ex2mem));
        Vtop_top___nba_comb__TOP__top__5((&vlSymsp->TOP__top));
        Vtop_memory___nba_comb__TOP__top__u_memory__0((&vlSymsp->TOP__top__u_memory));
        Vtop_top___nba_comb__TOP__top__6((&vlSymsp->TOP__top));
        Vtop_mem2wb___nba_comb__TOP__top__u_mem2wb__0((&vlSymsp->TOP__top__u_mem2wb));
        Vtop_top___nba_comb__TOP__top__7((&vlSymsp->TOP__top));
        Vtop_writeback___nba_comb__TOP__top__u_writeback__0((&vlSymsp->TOP__top__u_writeback));
        Vtop_top___nba_comb__TOP__top__8((&vlSymsp->TOP__top));
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
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
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc = vlSymsp->TOP__top.pc;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.instr = vlSymsp->TOP__top.instr;
}
