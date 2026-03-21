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
void Vtop_fetch___ico_sequent__TOP__top__u_core__u_fetch__0(Vtop_fetch* vlSelf);
void Vtop_core___ico_sequent__TOP__top__u_core__1(Vtop_core* vlSelf);
void Vtop_top___ico_sequent__TOP__top__1(Vtop_top* vlSelf);
void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf);

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
        Vtop_fetch___ico_sequent__TOP__top__u_core__u_fetch__0((&vlSymsp->TOP__top__u_core__u_fetch));
        Vtop_core___ico_sequent__TOP__top__u_core__1((&vlSymsp->TOP__top__u_core));
        Vtop_top___ico_sequent__TOP__top__1((&vlSymsp->TOP__top));
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
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
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSymsp->TOP__top__u_core__u_if2id.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_if2id____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((~ (IData)(vlSymsp->TOP__top__u_core__u_if2id.__PVT__rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_if2id____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(2U, ((IData)(vlSymsp->TOP__top__u_core__u_memory.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_memory____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(3U, ((IData)(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_csr_file____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(4U, ((IData)(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_reg_file____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(5U, ((~ (IData)(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_reg_file____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(6U, ((IData)(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_mem2wb____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(7U, ((~ (IData)(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_mem2wb____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(8U, ((IData)(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_id2ex____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(9U, ((~ (IData)(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__rst_n)) 
                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_id2ex____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(0xaU, ((IData)(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__clk) 
                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_ex2mem____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(0xbU, ((~ (IData)(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__rst_n)) 
                                         & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_ex2mem____PVT__rst_n__0)));
    vlSelfRef.__VactTriggered.set(0xcU, ((IData)(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__clk) 
                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_pc_counter____PVT__clk__0))));
    vlSelfRef.__VactTriggered.set(0xdU, ((~ (IData)(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__rst_n)) 
                                         & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_pc_counter____PVT__rst_n__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_if2id____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_if2id.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_if2id____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_if2id.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_memory____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_memory.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_csr_file____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_csr_file.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_reg_file____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_reg_file____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_mem2wb____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_mem2wb____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_id2ex____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_id2ex.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_id2ex____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_id2ex.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_ex2mem____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_ex2mem____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_pc_counter____PVT__clk__0 
        = vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_core__u_pc_counter____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vtop_pc_counter___nba_sequent__TOP__top__u_core__u_pc_counter__0(Vtop_pc_counter* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__0(Vtop_core* vlSelf);
void Vtop_top___nba_sequent__TOP__top__0(Vtop_top* vlSelf);
void Vtop_fetch___nba_sequent__TOP__top__u_core__u_fetch__0(Vtop_fetch* vlSelf);
void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__1(Vtop_core* vlSelf);
void Vtop_top___nba_sequent__TOP__top__1(Vtop_top* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop_memory___nba_sequent__TOP__top__u_core__u_memory__0(Vtop_memory* vlSelf);
void Vtop_csr_file___nba_sequent__TOP__top__u_core__u_csr_file__0(Vtop_csr_file* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__2(Vtop_core* vlSelf);
void Vtop_reg_file___nba_sequent__TOP__top__u_core__u_reg_file__0(Vtop_reg_file* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__3(Vtop_core* vlSelf);
void Vtop_top___nba_sequent__TOP__top__2(Vtop_top* vlSelf);
void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop_pipe_reg_ex2mem___nba_sequent__TOP__top__u_core__u_ex2mem__0(Vtop_pipe_reg_ex2mem* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__4(Vtop_core* vlSelf);
void Vtop_memory___nba_sequent__TOP__top__u_core__u_memory__1(Vtop_memory* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__5(Vtop_core* vlSelf);
void Vtop_pipe_reg_mem2wb___nba_sequent__TOP__top__u_core__u_mem2wb__0(Vtop_pipe_reg_mem2wb* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__6(Vtop_core* vlSelf);
void Vtop_top___nba_sequent__TOP__top__3(Vtop_top* vlSelf);
void Vtop_writeback___nba_sequent__TOP__top__u_core__u_writeback__0(Vtop_writeback* vlSelf);
void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__7(Vtop_core* vlSelf);
void Vtop_top___nba_sequent__TOP__top__4(Vtop_top* vlSelf);
void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf);
void Vtop_pipe_reg_id2ex___nba_sequent__TOP__top__u_core__u_id2ex__0(Vtop_pipe_reg_id2ex* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__8(Vtop_core* vlSelf);
void Vtop_hazard_unit___nba_sequent__TOP__top__u_core__u_hazard__0(Vtop_hazard_unit* vlSelf);
void Vtop_execute___nba_sequent__TOP__top__u_core__u_execute__0(Vtop_execute* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__9(Vtop_core* vlSelf);
void Vtop_pipe_reg_if2id___nba_sequent__TOP__top__u_core__u_if2id__0(Vtop_pipe_reg_if2id* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__10(Vtop_core* vlSelf);
void Vtop_decode___nba_sequent__TOP__top__u_core__u_decode__0(Vtop_decode* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__11(Vtop_core* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__12(Vtop_core* vlSelf);
void Vtop_pipe_reg_ex2mem___nba_comb__TOP__top__u_core__u_ex2mem__0(Vtop_pipe_reg_ex2mem* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__0(Vtop_core* vlSelf);
void Vtop_execute___nba_comb__TOP__top__u_core__u_execute__0(Vtop_execute* vlSelf);
void Vtop_csr_file___nba_comb__TOP__top__u_core__u_csr_file__0(Vtop_csr_file* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__1(Vtop_core* vlSelf);
void Vtop_execute___nba_comb__TOP__top__u_core__u_execute__1(Vtop_execute* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__2(Vtop_core* vlSelf);
void Vtop_core___nba_sequent__TOP__top__u_core__13(Vtop_core* vlSelf);
void Vtop_hazard_unit___nba_comb__TOP__top__u_core__u_hazard__0(Vtop_hazard_unit* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__3(Vtop_core* vlSelf);
void Vtop_reg_file___nba_comb__TOP__top__u_core__u_reg_file__0(Vtop_reg_file* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__4(Vtop_core* vlSelf);
void Vtop_forward_unit___nba_comb__TOP__top__u_core__u_forward__0(Vtop_forward_unit* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__5(Vtop_core* vlSelf);
void Vtop_pipe_reg_id2ex___nba_comb__TOP__top__u_core__u_id2ex__0(Vtop_pipe_reg_id2ex* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__6(Vtop_core* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__7(Vtop_core* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__8(Vtop_core* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__9(Vtop_core* vlSelf);
void Vtop_pipe_reg_if2id___nba_comb__TOP__top__u_core__u_if2id__0(Vtop_pipe_reg_if2id* vlSelf);
void Vtop_core___nba_comb__TOP__top__u_core__10(Vtop_core* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x3000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pc_counter___nba_sequent__TOP__top__u_core__u_pc_counter__0((&vlSymsp->TOP__top__u_core__u_pc_counter));
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__0((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_sequent__TOP__top__0((&vlSymsp->TOP__top));
        Vtop_fetch___nba_sequent__TOP__top__u_core__u_fetch__0((&vlSymsp->TOP__top__u_core__u_fetch));
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        Vtop_core___nba_sequent__TOP__top__u_core__1((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_sequent__TOP__top__1((&vlSymsp->TOP__top));
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_memory___nba_sequent__TOP__top__u_core__u_memory__0((&vlSymsp->TOP__top__u_core__u_memory));
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_csr_file___nba_sequent__TOP__top__u_core__u_csr_file__0((&vlSymsp->TOP__top__u_core__u_csr_file));
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__2((&vlSymsp->TOP__top__u_core));
    }
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_reg_file___nba_sequent__TOP__top__u_core__u_reg_file__0((&vlSymsp->TOP__top__u_core__u_reg_file));
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__3((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_sequent__TOP__top__2((&vlSymsp->TOP__top));
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0xc00ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg_ex2mem___nba_sequent__TOP__top__u_core__u_ex2mem__0((&vlSymsp->TOP__top__u_core__u_ex2mem));
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__4((&vlSymsp->TOP__top__u_core));
        Vtop_memory___nba_sequent__TOP__top__u_core__u_memory__1((&vlSymsp->TOP__top__u_core__u_memory));
        Vtop_core___nba_sequent__TOP__top__u_core__5((&vlSymsp->TOP__top__u_core));
    }
    if ((0xc0ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg_mem2wb___nba_sequent__TOP__top__u_core__u_mem2wb__0((&vlSymsp->TOP__top__u_core__u_mem2wb));
        vlSelfRef.__Vm_traceActivity[6U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__6((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_sequent__TOP__top__3((&vlSymsp->TOP__top));
        Vtop_writeback___nba_sequent__TOP__top__u_core__u_writeback__0((&vlSymsp->TOP__top__u_core__u_writeback));
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
        Vtop_core___nba_sequent__TOP__top__u_core__7((&vlSymsp->TOP__top__u_core));
        Vtop_top___nba_sequent__TOP__top__4((&vlSymsp->TOP__top));
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((0x300ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg_id2ex___nba_sequent__TOP__top__u_core__u_id2ex__0((&vlSymsp->TOP__top__u_core__u_id2ex));
        vlSelfRef.__Vm_traceActivity[7U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__8((&vlSymsp->TOP__top__u_core));
        Vtop_hazard_unit___nba_sequent__TOP__top__u_core__u_hazard__0((&vlSymsp->TOP__top__u_core__u_hazard));
        Vtop_execute___nba_sequent__TOP__top__u_core__u_execute__0((&vlSymsp->TOP__top__u_core__u_execute));
        Vtop_core___nba_sequent__TOP__top__u_core__9((&vlSymsp->TOP__top__u_core));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg_if2id___nba_sequent__TOP__top__u_core__u_if2id__0((&vlSymsp->TOP__top__u_core__u_if2id));
        vlSelfRef.__Vm_traceActivity[8U] = 1U;
        Vtop_core___nba_sequent__TOP__top__u_core__10((&vlSymsp->TOP__top__u_core));
        Vtop_decode___nba_sequent__TOP__top__u_core__u_decode__0((&vlSymsp->TOP__top__u_core__u_decode));
        Vtop_core___nba_sequent__TOP__top__u_core__11((&vlSymsp->TOP__top__u_core));
    }
    if ((0xc00ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_core___nba_sequent__TOP__top__u_core__12((&vlSymsp->TOP__top__u_core));
        vlSelfRef.__Vm_traceActivity[9U] = 1U;
    }
    if ((0xcc0ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg_ex2mem___nba_comb__TOP__top__u_core__u_ex2mem__0((&vlSymsp->TOP__top__u_core__u_ex2mem));
        vlSelfRef.__Vm_traceActivity[0xaU] = 1U;
        Vtop_core___nba_comb__TOP__top__u_core__0((&vlSymsp->TOP__top__u_core));
    }
    if ((0x308ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_execute___nba_comb__TOP__top__u_core__u_execute__0((&vlSymsp->TOP__top__u_core__u_execute));
        vlSelfRef.__Vm_traceActivity[0xbU] = 1U;
        Vtop_csr_file___nba_comb__TOP__top__u_core__u_csr_file__0((&vlSymsp->TOP__top__u_core__u_csr_file));
        Vtop_core___nba_comb__TOP__top__u_core__1((&vlSymsp->TOP__top__u_core));
        Vtop_execute___nba_comb__TOP__top__u_core__u_execute__1((&vlSymsp->TOP__top__u_core__u_execute));
        Vtop_core___nba_comb__TOP__top__u_core__2((&vlSymsp->TOP__top__u_core));
    }
    if ((0x3000ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_core___nba_sequent__TOP__top__u_core__13((&vlSymsp->TOP__top__u_core));
    }
    if ((0x303ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_hazard_unit___nba_comb__TOP__top__u_core__u_hazard__0((&vlSymsp->TOP__top__u_core__u_hazard));
        vlSelfRef.__Vm_traceActivity[0xcU] = 1U;
        Vtop_core___nba_comb__TOP__top__u_core__3((&vlSymsp->TOP__top__u_core));
    }
    if ((0x33ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_reg_file___nba_comb__TOP__top__u_core__u_reg_file__0((&vlSymsp->TOP__top__u_core__u_reg_file));
        vlSelfRef.__Vm_traceActivity[0xdU] = 1U;
        Vtop_core___nba_comb__TOP__top__u_core__4((&vlSymsp->TOP__top__u_core));
    }
    if ((0xfc3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_forward_unit___nba_comb__TOP__top__u_core__u_forward__0((&vlSymsp->TOP__top__u_core__u_forward));
        vlSelfRef.__Vm_traceActivity[0xeU] = 1U;
        Vtop_core___nba_comb__TOP__top__u_core__5((&vlSymsp->TOP__top__u_core));
    }
    if ((0xfc0ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg_id2ex___nba_comb__TOP__top__u_core__u_id2ex__0((&vlSymsp->TOP__top__u_core__u_id2ex));
        vlSelfRef.__Vm_traceActivity[0xfU] = 1U;
        Vtop_core___nba_comb__TOP__top__u_core__6((&vlSymsp->TOP__top__u_core));
    }
    if ((0x30bULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_core___nba_comb__TOP__top__u_core__7((&vlSymsp->TOP__top__u_core));
    }
    if ((0x330bULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_core___nba_comb__TOP__top__u_core__8((&vlSymsp->TOP__top__u_core));
    }
    if ((0xffbULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_core___nba_comb__TOP__top__u_core__9((&vlSymsp->TOP__top__u_core));
        vlSelfRef.__Vm_traceActivity[0x10U] = 1U;
    }
    if ((0xfc3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_pipe_reg_if2id___nba_comb__TOP__top__u_core__u_if2id__0((&vlSymsp->TOP__top__u_core__u_if2id));
        Vtop_core___nba_comb__TOP__top__u_core__10((&vlSymsp->TOP__top__u_core));
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
    vlSelfRef.instr = vlSymsp->TOP__top.instr;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
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

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_wb_have = vlSymsp->TOP__top.debug_wb_have;
    vlSelfRef.debug_wb_pc = vlSymsp->TOP__top.debug_wb_pc;
    vlSelfRef.debug_wb_instr = vlSymsp->TOP__top.debug_wb_instr;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_wb_addr = vlSymsp->TOP__top.debug_wb_addr;
    vlSelfRef.debug_wb_ena = vlSymsp->TOP__top.debug_wb_ena;
    vlSelfRef.debug_wb_data = vlSymsp->TOP__top.debug_wb_data;
}
