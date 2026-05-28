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
void Vtop_core___ico_sequent__TOP__top__u_core__0(Vtop_core* vlSelf);

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
        Vtop_core___ico_sequent__TOP__top__u_core__0((&vlSymsp->TOP__top__u_core));
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

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSymsp->TOP__top.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((~ (IData)(vlSymsp->TOP__top.rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__rst_n__0)));
    vlSelfRef.__VactTriggered.set(2U, ((IData)(vlSymsp->TOP__top__u_core__u_memory.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_memory____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(3U, ((~ (IData)(vlSymsp->TOP__top__u_core__u_memory.__PVT__rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_memory____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(4U, ((IData)(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_csr_file____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(5U, ((IData)(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_reg_file____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(6U, ((~ (IData)(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_reg_file____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(7U, ((IData)(vlSymsp->TOP__top__u_core__u_fetch.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_fetch____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(8U, ((~ (IData)(vlSymsp->TOP__top__u_core__u_fetch.__PVT__rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_fetch____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(9U, ((IData)(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_pc_counter____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(0xaU, ((~ (IData)(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__rst_n)) 
                                         & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_pc_counter____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(0xbU, ((IData)(vlSymsp->TOP__top__u_core__u_if2id.__PVT__clk) 
                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_if2id____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(0xcU, ((~ (IData)(vlSymsp->TOP__top__u_core__u_if2id.__PVT__rst_n)) 
                                         & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_if2id____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(0xdU, ((IData)(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__clk) 
                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_id2ex____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(0xeU, ((~ (IData)(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__rst_n)) 
                                         & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_id2ex____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(0xfU, ((IData)(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__clk) 
                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_ex2mem____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(0x10U, ((~ (IData)(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__rst_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_ex2mem____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(0x11U, ((IData)(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_mem2wb____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(0x12U, ((~ (IData)(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__rst_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_mem2wb____PVT__rst_n__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__top__clk__0 = vlSymsp->TOP__top.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__rst_n__0 
        = vlSymsp->TOP__top.rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_memory____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_memory.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_memory____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_memory.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_csr_file____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_csr_file.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_reg_file____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_reg_file____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_fetch____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_fetch.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_fetch____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_fetch.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_pc_counter____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_pc_counter____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_if2id____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_if2id.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_if2id____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_if2id.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_id2ex____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_id2ex.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_id2ex____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_id2ex.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_ex2mem____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_ex2mem____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_mem2wb____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_mem2wb____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vtop_top___nba_sequent__TOP__top__0(Vtop_top* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__0(Vtop_core* vlSelf);
void Vtop_pc_counter___nba_sequent__TOP__top__u_core__u_pc_counter__0(Vtop_pc_counter* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__1(Vtop_core* vlSelf);
void Vtop_top___nba_sequent__TOP__top__1(Vtop_top* vlSelf);
void Vtop_fetch___nba_sequent__TOP__top__u_core__u_fetch__0(Vtop_fetch* vlSelf);
void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__2(Vtop_core* vlSelf);
void Vtop_top___nba_sequent__TOP__top__2(Vtop_top* vlSelf);
void Vtop_csr_file___nba_sequent__TOP__top__u_core__u_csr_file__0(Vtop_csr_file* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__3(Vtop_core* vlSelf);
void Vtop_reg_file___nba_sequent__TOP__top__u_core__u_reg_file__0(Vtop_reg_file* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__4(Vtop_core* vlSelf);
void Vtop_top___nba_sequent__TOP__top__3(Vtop_top* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop_fetch___nba_sequent__TOP__top__u_core__u_fetch__1(Vtop_fetch* vlSelf);
void Vtop_pipe_reg__D8c___nba_sequent__TOP__top__u_core__u_mem2wb__0(Vtop_pipe_reg__D8c* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__5(Vtop_core* vlSelf);
void Vtop_top___nba_sequent__TOP__top__4(Vtop_top* vlSelf);
void Vtop_writeback___nba_sequent__TOP__top__u_core__u_writeback__0(Vtop_writeback* vlSelf);
void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__6(Vtop_core* vlSelf);
void Vtop_top___nba_sequent__TOP__top__5(Vtop_top* vlSelf);
void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf);
void Vtop_memory___nba_sequent__TOP__top__u_core__u_memory__0(Vtop_memory* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__7(Vtop_core* vlSelf);
void Vtop_top___nba_sequent__TOP__top__6(Vtop_top* vlSelf);
void Vtop_pipe_reg__D8f___nba_sequent__TOP__top__u_core__u_ex2mem__0(Vtop_pipe_reg__D8f* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__8(Vtop_core* vlSelf);
void Vtop_memory___nba_sequent__TOP__top__u_core__u_memory__1(Vtop_memory* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__9(Vtop_core* vlSelf);
void Vtop_top___nba_sequent__TOP__top__7(Vtop_top* vlSelf);
void Vtop_pipe_reg__D107___nba_sequent__TOP__top__u_core__u_id2ex__0(Vtop_pipe_reg__D107* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__10(Vtop_core* vlSelf);
void Vtop_hazard_unit___nba_sequent__TOP__top__u_core__u_hazard__0(Vtop_hazard_unit* vlSelf);
void Vtop_execute___nba_sequent__TOP__top__u_core__u_execute__0(Vtop_execute* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__11(Vtop_core* vlSelf);
void Vtop_pipe_reg__D40___nba_sequent__TOP__top__u_core__u_if2id__0(Vtop_pipe_reg__D40* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__12(Vtop_core* vlSelf);
void Vtop_decode___nba_sequent__TOP__top__u_core__u_decode__0(Vtop_decode* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__13(Vtop_core* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__14(Vtop_core* vlSelf);
void Vtop_memory___nba_comb__TOP__top__u_core__u_memory__0(Vtop_memory* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__0(Vtop_core* vlSelf);
void Vtop_top___nba_comb__TOP__top__0(Vtop_top* vlSelf);
void Vtop_execute___nba_comb__TOP__top__u_core__u_execute__0(Vtop_execute* vlSelf);
void Vtop_csr_file___nba_comb__TOP__top__u_core__u_csr_file__0(Vtop_csr_file* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__1(Vtop_core* vlSelf);
void Vtop_execute___nba_comb__TOP__top__u_core__u_execute__1(Vtop_execute* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__2(Vtop_core* vlSelf);
void Vtop_hazard_unit___nba_comb__TOP__top__u_core__u_hazard__0(Vtop_hazard_unit* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__3(Vtop_core* vlSelf);
void Vtop_reg_file___nba_comb__TOP__top__u_core__u_reg_file__0(Vtop_reg_file* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__4(Vtop_core* vlSelf);
void Vtop_forward_unit___nba_comb__TOP__top__u_core__u_forward__0(Vtop_forward_unit* vlSelf);
void Vtop_memory___nba_comb__TOP__top__u_core__u_memory__1(Vtop_memory* vlSelf);
void Vtop_pipe_reg__D8f___nba_comb__TOP__top__u_core__u_ex2mem__0(Vtop_pipe_reg__D8f* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__5(Vtop_core* vlSelf);
void Vtop_fetch___nba_comb__TOP__top__u_core__u_fetch__0(Vtop_fetch* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__6(Vtop_core* vlSelf);
void Vtop_top___nba_comb__TOP__top__1(Vtop_top* vlSelf);
void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__7(Vtop_core* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__8(Vtop_core* vlSelf);
void Vtop_forward_unit___nba_comb__TOP__top__u_core__u_forward__1(Vtop_forward_unit* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__9(Vtop_core* vlSelf);
void Vtop_pipe_reg__D107___nba_comb__TOP__top__u_core__u_id2ex__0(Vtop_pipe_reg__D107* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__10(Vtop_core* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__11(Vtop_core* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__12(Vtop_core* vlSelf);
void Vtop_fetch___nba_comb__TOP__top__u_core__u_fetch__1(Vtop_fetch* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__13(Vtop_core* vlSelf);
void Vtop_top___nba_comb__TOP__top__2(Vtop_top* vlSelf);
void Vtop_pipe_reg__D40___nba_comb__TOP__top__u_core__u_if2id__0(Vtop_pipe_reg__D40* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__14(Vtop_core* vlSelf);
void Vtop_fetch___nba_comb__TOP__top__u_core__u_fetch__2(Vtop_fetch* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_top___nba_sequent__TOP__top__0((&vlSymsp->TOP__top));
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__0((&vlSymsp->TOP__top__u_core));
    }
    if ((0x600ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pc_counter___nba_sequent__TOP__top__u_core__u_pc_counter__0((&vlSymsp->TOP__top__u_core__u_pc_counter));
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__1((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_sequent__TOP__top__1((&vlSymsp->TOP__top));
        Vtop_fetch___nba_sequent__TOP__top__u_core__u_fetch__0((&vlSymsp->TOP__top__u_core__u_fetch));
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        Vtop_core___nba_sequent__TOP__top__u_core__2((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_sequent__TOP__top__2((&vlSymsp->TOP__top));
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_csr_file___nba_sequent__TOP__top__u_core__u_csr_file__0((&vlSymsp->TOP__top__u_core__u_csr_file));
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__3((&vlSymsp->TOP__top__u_core));
    }
    if ((0x60ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_reg_file___nba_sequent__TOP__top__u_core__u_reg_file__0((&vlSymsp->TOP__top__u_core__u_reg_file));
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__4((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_sequent__TOP__top__3((&vlSymsp->TOP__top));
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x180ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_fetch___nba_sequent__TOP__top__u_core__u_fetch__1((&vlSymsp->TOP__top__u_core__u_fetch));
    }
    if ((0x60000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg__D8c___nba_sequent__TOP__top__u_core__u_mem2wb__0((&vlSymsp->TOP__top__u_core__u_mem2wb));
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__5((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_sequent__TOP__top__4((&vlSymsp->TOP__top));
        Vtop_writeback___nba_sequent__TOP__top__u_core__u_writeback__0((&vlSymsp->TOP__top__u_core__u_writeback));
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
        Vtop_core___nba_sequent__TOP__top__u_core__6((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_sequent__TOP__top__5((&vlSymsp->TOP__top));
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_memory___nba_sequent__TOP__top__u_core__u_memory__0((&vlSymsp->TOP__top__u_core__u_memory));
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__7((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_sequent__TOP__top__6((&vlSymsp->TOP__top));
    }
    if ((0x18000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg__D8f___nba_sequent__TOP__top__u_core__u_ex2mem__0((&vlSymsp->TOP__top__u_core__u_ex2mem));
        vlSelfRef.__Vm_traceActivity[8U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__8((&vlSymsp->TOP__top__u_core));
        Vtop_memory___nba_sequent__TOP__top__u_core__u_memory__1((&vlSymsp->TOP__top__u_core__u_memory));
        Vtop_core___nba_sequent__TOP__top__u_core__9((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_sequent__TOP__top__7((&vlSymsp->TOP__top));
    }
    if ((0x6000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg__D107___nba_sequent__TOP__top__u_core__u_id2ex__0((&vlSymsp->TOP__top__u_core__u_id2ex));
        vlSelfRef.__Vm_traceActivity[9U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__10((&vlSymsp->TOP__top__u_core));
        Vtop_hazard_unit___nba_sequent__TOP__top__u_core__u_hazard__0((&vlSymsp->TOP__top__u_core__u_hazard));
        Vtop_execute___nba_sequent__TOP__top__u_core__u_execute__0((&vlSymsp->TOP__top__u_core__u_execute));
        Vtop_core___nba_sequent__TOP__top__u_core__11((&vlSymsp->TOP__top__u_core));
    }
    if ((0x1800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg__D40___nba_sequent__TOP__top__u_core__u_if2id__0((&vlSymsp->TOP__top__u_core__u_if2id));
        vlSelfRef.__Vm_traceActivity[0xaU] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__12((&vlSymsp->TOP__top__u_core));
        Vtop_decode___nba_sequent__TOP__top__u_core__u_decode__0((&vlSymsp->TOP__top__u_core__u_decode));
        Vtop_core___nba_sequent__TOP__top__u_core__13((&vlSymsp->TOP__top__u_core));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_core___nba_sequent__TOP__top__u_core__14((&vlSymsp->TOP__top__u_core));
        vlSelfRef.__Vm_traceActivity[0xbU] = 1U;
    }
    if ((0x1800cULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_memory___nba_comb__TOP__top__u_core__u_memory__0((&vlSymsp->TOP__top__u_core__u_memory));
        vlSelfRef.__Vm_traceActivity[0xcU] = 1U;
        Vtop_core___nba_comb__TOP__top__u_core__0((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_comb__TOP__top__0((&vlSymsp->TOP__top));
    }
    if ((0x6010ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_execute___nba_comb__TOP__top__u_core__u_execute__0((&vlSymsp->TOP__top__u_core__u_execute));
        vlSelfRef.__Vm_traceActivity[0xdU] = 1U;
        Vtop_csr_file___nba_comb__TOP__top__u_core__u_csr_file__0((&vlSymsp->TOP__top__u_core__u_csr_file));
        Vtop_core___nba_comb__TOP__top__u_core__1((&vlSymsp->TOP__top__u_core));
        Vtop_execute___nba_comb__TOP__top__u_core__u_execute__1((&vlSymsp->TOP__top__u_core__u_execute));
        Vtop_core___nba_comb__TOP__top__u_core__2((&vlSymsp->TOP__top__u_core));
    }
    if ((0x7800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_hazard_unit___nba_comb__TOP__top__u_core__u_hazard__0((&vlSymsp->TOP__top__u_core__u_hazard));
        vlSelfRef.__Vm_traceActivity[0xeU] = 1U;
        Vtop_core___nba_comb__TOP__top__u_core__3((&vlSymsp->TOP__top__u_core));
    }
    if ((0x1860ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_reg_file___nba_comb__TOP__top__u_core__u_reg_file__0((&vlSymsp->TOP__top__u_core__u_reg_file));
        vlSelfRef.__Vm_traceActivity[0xfU] = 1U;
        Vtop_core___nba_comb__TOP__top__u_core__4((&vlSymsp->TOP__top__u_core));
    }
    if ((0x7f800ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_forward_unit___nba_comb__TOP__top__u_core__u_forward__0((&vlSymsp->TOP__top__u_core__u_forward));
    }
    if ((0x1800fULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_memory___nba_comb__TOP__top__u_core__u_memory__1((&vlSymsp->TOP__top__u_core__u_memory));
    }
    if ((0x7800cULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg__D8f___nba_comb__TOP__top__u_core__u_ex2mem__0((&vlSymsp->TOP__top__u_core__u_ex2mem));
        vlSelfRef.__Vm_traceActivity[0x10U] = 1U;
        Vtop_core___nba_comb__TOP__top__u_core__5((&vlSymsp->TOP__top__u_core));
    }
    if ((0x6190ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_fetch___nba_comb__TOP__top__u_core__u_fetch__0((&vlSymsp->TOP__top__u_core__u_fetch));
        vlSelfRef.__Vm_traceActivity[0x11U] = 1U;
        Vtop_core___nba_comb__TOP__top__u_core__6((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_comb__TOP__top__1((&vlSymsp->TOP__top));
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x7810ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_core___nba_comb__TOP__top__u_core__7((&vlSymsp->TOP__top__u_core));
    }
    if ((0x1f80cULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_core___nba_comb__TOP__top__u_core__8((&vlSymsp->TOP__top__u_core));
        vlSelfRef.__Vm_traceActivity[0x12U] = 1U;
    }
    if ((0x7f87cULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_forward_unit___nba_comb__TOP__top__u_core__u_forward__1((&vlSymsp->TOP__top__u_core__u_forward));
        vlSelfRef.__Vm_traceActivity[0x13U] = 1U;
        Vtop_core___nba_comb__TOP__top__u_core__9((&vlSymsp->TOP__top__u_core));
    }
    if ((0x7e00cULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg__D107___nba_comb__TOP__top__u_core__u_id2ex__0((&vlSymsp->TOP__top__u_core__u_id2ex));
        vlSelfRef.__Vm_traceActivity[0x14U] = 1U;
        Vtop_core___nba_comb__TOP__top__u_core__10((&vlSymsp->TOP__top__u_core));
    }
    if ((0x6790ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_core___nba_comb__TOP__top__u_core__11((&vlSymsp->TOP__top__u_core));
    }
    if ((0x1f99cULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_core___nba_comb__TOP__top__u_core__12((&vlSymsp->TOP__top__u_core));
        vlSelfRef.__Vm_traceActivity[0x15U] = 1U;
        Vtop_fetch___nba_comb__TOP__top__u_core__u_fetch__1((&vlSymsp->TOP__top__u_core__u_fetch));
        Vtop_core___nba_comb__TOP__top__u_core__13((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_comb__TOP__top__2((&vlSymsp->TOP__top));
    }
    if ((0x7f80cULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg__D40___nba_comb__TOP__top__u_core__u_if2id__0((&vlSymsp->TOP__top__u_core__u_if2id));
        Vtop_core___nba_comb__TOP__top__u_core__14((&vlSymsp->TOP__top__u_core));
    }
    if ((0x1f99fULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_fetch___nba_comb__TOP__top__u_core__u_fetch__2((&vlSymsp->TOP__top__u_core__u_fetch));
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pc = vlSymsp->TOP__top.pc;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_wb_have = vlSymsp->TOP__top.debug_wb_have;
    vlSelfRef.debug_wb_pc = vlSymsp->TOP__top.debug_wb_pc;
    vlSelfRef.debug_wb_instr = vlSymsp->TOP__top.debug_wb_instr;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_wb_addr = vlSymsp->TOP__top.debug_wb_addr;
    vlSelfRef.debug_wb_en = vlSymsp->TOP__top.debug_wb_en;
    vlSelfRef.debug_wb_data = vlSymsp->TOP__top.debug_wb_data;
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.instr = vlSymsp->TOP__top.instr;
}
