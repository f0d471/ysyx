// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop_top___eval_initial__TOP__top(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop___024root____Vm_traceActivitySetAll(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop_core___eval_initial__TOP__top__u_core(Vtop_core* vlSelf);
VL_ATTR_COLD void Vtop_sim_sram__LBz1_H1___eval_initial__TOP__top__u_sram_lsu(Vtop_sim_sram__LBz1_H1* vlSelf);
VL_ATTR_COLD void Vtop_execute___eval_initial__TOP__top__u_core__u_execute(Vtop_execute* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_top___eval_initial__TOP__top((&vlSymsp->TOP__top));
    Vtop___024root____Vm_traceActivitySetAll(vlSelf);
    Vtop_core___eval_initial__TOP__top__u_core((&vlSymsp->TOP__top__u_core));
    Vtop_sim_sram__LBz1_H1___eval_initial__TOP__top__u_sram_lsu((&vlSymsp->TOP__top__u_sram_lsu));
    Vtop_execute___eval_initial__TOP__top__u_core__u_execute((&vlSymsp->TOP__top__u_core__u_execute));
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_sram_ifu____PVT__clk__0 
        = vlSymsp->TOP__top__u_sram_ifu.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_sram_ifu____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_sram_ifu.__PVT__rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_sram_lsu____PVT__clk__0 
        = vlSymsp->TOP__top__u_sram_lsu.__PVT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top__u_sram_lsu____PVT__rst_n__0 
        = vlSymsp->TOP__top__u_sram_lsu.__PVT__rst_n;
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

VL_ATTR_COLD void Vtop_sim_sram__D1___stl_sequent__TOP__top__u_sram_ifu__0(Vtop_sim_sram__D1* vlSelf);
VL_ATTR_COLD void Vtop_core___stl_sequent__TOP__top__u_core__0(Vtop_core* vlSelf);
VL_ATTR_COLD void Vtop_pipe_reg__D40___stl_sequent__TOP__top__u_core__u_if2id__0(Vtop_pipe_reg__D40* vlSelf);
VL_ATTR_COLD void Vtop_pipe_reg__D107___stl_sequent__TOP__top__u_core__u_id2ex__0(Vtop_pipe_reg__D107* vlSelf);
VL_ATTR_COLD void Vtop_pipe_reg__D8c___stl_sequent__TOP__top__u_core__u_mem2wb__0(Vtop_pipe_reg__D8c* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__0(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop_pc_counter___stl_sequent__TOP__top__u_core__u_pc_counter__0(Vtop_pc_counter* vlSelf);
VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop_csr_file___stl_sequent__TOP__top__u_core__u_csr_file__0(Vtop_csr_file* vlSelf);
VL_ATTR_COLD void Vtop_pipe_reg__D8f___stl_sequent__TOP__top__u_core__u_ex2mem__0(Vtop_pipe_reg__D8f* vlSelf);
VL_ATTR_COLD void Vtop_reg_file___stl_sequent__TOP__top__u_core__u_reg_file__0(Vtop_reg_file* vlSelf);
VL_ATTR_COLD void Vtop_core___stl_sequent__TOP__top__u_core__1(Vtop_core* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__1(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop_fetch___stl_sequent__TOP__top__u_core__u_fetch__0(Vtop_fetch* vlSelf);
VL_ATTR_COLD void Vtop_decode___stl_sequent__TOP__top__u_core__u_decode__0(Vtop_decode* vlSelf);
VL_ATTR_COLD void Vtop_hazard_unit___stl_sequent__TOP__top__u_core__u_hazard__0(Vtop_hazard_unit* vlSelf);
VL_ATTR_COLD void Vtop_execute___stl_sequent__TOP__top__u_core__u_execute__0(Vtop_execute* vlSelf);
VL_ATTR_COLD void Vtop_writeback___stl_sequent__TOP__top__u_core__u_writeback__0(Vtop_writeback* vlSelf);
VL_ATTR_COLD void Vtop_memory___stl_sequent__TOP__top__u_core__u_memory__0(Vtop_memory* vlSelf);
VL_ATTR_COLD void Vtop_core___stl_sequent__TOP__top__u_core__2(Vtop_core* vlSelf);
VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__1(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__2(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop_hazard_unit___stl_sequent__TOP__top__u_core__u_hazard__1(Vtop_hazard_unit* vlSelf);
VL_ATTR_COLD void Vtop_reg_file___stl_sequent__TOP__top__u_core__u_reg_file__1(Vtop_reg_file* vlSelf);
VL_ATTR_COLD void Vtop_forward_unit___stl_sequent__TOP__top__u_core__u_forward__0(Vtop_forward_unit* vlSelf);
VL_ATTR_COLD void Vtop_csr_file___stl_sequent__TOP__top__u_core__u_csr_file__1(Vtop_csr_file* vlSelf);
VL_ATTR_COLD void Vtop_fetch___stl_sequent__TOP__top__u_core__u_fetch__1(Vtop_fetch* vlSelf);
VL_ATTR_COLD void Vtop_pipe_reg__D8f___stl_sequent__TOP__top__u_core__u_ex2mem__1(Vtop_pipe_reg__D8f* vlSelf);
VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__2(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop_core___stl_sequent__TOP__top__u_core__3(Vtop_core* vlSelf);
VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__3(Vtop_top* vlSelf);
VL_ATTR_COLD void Vtop_execute___stl_sequent__TOP__top__u_core__u_execute__1(Vtop_execute* vlSelf);
VL_ATTR_COLD void Vtop_pipe_reg__D107___stl_sequent__TOP__top__u_core__u_id2ex__1(Vtop_pipe_reg__D107* vlSelf);
VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__3(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop_core___stl_sequent__TOP__top__u_core__4(Vtop_core* vlSelf);
VL_ATTR_COLD void Vtop_forward_unit___stl_sequent__TOP__top__u_core__u_forward__1(Vtop_forward_unit* vlSelf);
VL_ATTR_COLD void Vtop_pipe_reg__D40___stl_sequent__TOP__top__u_core__u_if2id__1(Vtop_pipe_reg__D40* vlSelf);
VL_ATTR_COLD void Vtop_core___stl_sequent__TOP__top__u_core__5(Vtop_core* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop_sim_sram__D1___stl_sequent__TOP__top__u_sram_ifu__0((&vlSymsp->TOP__top__u_sram_ifu));
        Vtop___024root____Vm_traceActivitySetAll(vlSelf);
        Vtop_core___stl_sequent__TOP__top__u_core__0((&vlSymsp->TOP__top__u_core));
        Vtop_pipe_reg__D40___stl_sequent__TOP__top__u_core__u_if2id__0((&vlSymsp->TOP__top__u_core__u_if2id));
        Vtop_pipe_reg__D107___stl_sequent__TOP__top__u_core__u_id2ex__0((&vlSymsp->TOP__top__u_core__u_id2ex));
        Vtop_pipe_reg__D8c___stl_sequent__TOP__top__u_core__u_mem2wb__0((&vlSymsp->TOP__top__u_core__u_mem2wb));
        Vtop_top___stl_sequent__TOP__top__0((&vlSymsp->TOP__top));
        Vtop_pc_counter___stl_sequent__TOP__top__u_core__u_pc_counter__0((&vlSymsp->TOP__top__u_core__u_pc_counter));
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop_csr_file___stl_sequent__TOP__top__u_core__u_csr_file__0((&vlSymsp->TOP__top__u_core__u_csr_file));
        Vtop_pipe_reg__D8f___stl_sequent__TOP__top__u_core__u_ex2mem__0((&vlSymsp->TOP__top__u_core__u_ex2mem));
        Vtop_reg_file___stl_sequent__TOP__top__u_core__u_reg_file__0((&vlSymsp->TOP__top__u_core__u_reg_file));
        Vtop_core___stl_sequent__TOP__top__u_core__1((&vlSymsp->TOP__top__u_core));
        Vtop_top___stl_sequent__TOP__top__1((&vlSymsp->TOP__top));
        Vtop_fetch___stl_sequent__TOP__top__u_core__u_fetch__0((&vlSymsp->TOP__top__u_core__u_fetch));
        Vtop_decode___stl_sequent__TOP__top__u_core__u_decode__0((&vlSymsp->TOP__top__u_core__u_decode));
        Vtop_hazard_unit___stl_sequent__TOP__top__u_core__u_hazard__0((&vlSymsp->TOP__top__u_core__u_hazard));
        Vtop_execute___stl_sequent__TOP__top__u_core__u_execute__0((&vlSymsp->TOP__top__u_core__u_execute));
        Vtop_writeback___stl_sequent__TOP__top__u_core__u_writeback__0((&vlSymsp->TOP__top__u_core__u_writeback));
        Vtop_memory___stl_sequent__TOP__top__u_core__u_memory__0((&vlSymsp->TOP__top__u_core__u_memory));
        Vtop_core___stl_sequent__TOP__top__u_core__2((&vlSymsp->TOP__top__u_core));
        Vtop___024root___stl_sequent__TOP__1(vlSelf);
        Vtop_top___stl_sequent__TOP__top__2((&vlSymsp->TOP__top));
        Vtop_hazard_unit___stl_sequent__TOP__top__u_core__u_hazard__1((&vlSymsp->TOP__top__u_core__u_hazard));
        Vtop_reg_file___stl_sequent__TOP__top__u_core__u_reg_file__1((&vlSymsp->TOP__top__u_core__u_reg_file));
        Vtop_forward_unit___stl_sequent__TOP__top__u_core__u_forward__0((&vlSymsp->TOP__top__u_core__u_forward));
        Vtop_csr_file___stl_sequent__TOP__top__u_core__u_csr_file__1((&vlSymsp->TOP__top__u_core__u_csr_file));
        Vtop_fetch___stl_sequent__TOP__top__u_core__u_fetch__1((&vlSymsp->TOP__top__u_core__u_fetch));
        Vtop_pipe_reg__D8f___stl_sequent__TOP__top__u_core__u_ex2mem__1((&vlSymsp->TOP__top__u_core__u_ex2mem));
        Vtop___024root___stl_sequent__TOP__2(vlSelf);
        Vtop_core___stl_sequent__TOP__top__u_core__3((&vlSymsp->TOP__top__u_core));
        Vtop_top___stl_sequent__TOP__top__3((&vlSymsp->TOP__top));
        Vtop_execute___stl_sequent__TOP__top__u_core__u_execute__1((&vlSymsp->TOP__top__u_core__u_execute));
        Vtop_pipe_reg__D107___stl_sequent__TOP__top__u_core__u_id2ex__1((&vlSymsp->TOP__top__u_core__u_id2ex));
        Vtop___024root___stl_sequent__TOP__3(vlSelf);
        Vtop_core___stl_sequent__TOP__top__u_core__4((&vlSymsp->TOP__top__u_core));
        Vtop_forward_unit___stl_sequent__TOP__top__u_core__u_forward__1((&vlSymsp->TOP__top__u_core__u_forward));
        Vtop_pipe_reg__D40___stl_sequent__TOP__top__u_core__u_if2id__1((&vlSymsp->TOP__top__u_core__u_if2id));
        Vtop_core___stl_sequent__TOP__top__u_core__5((&vlSymsp->TOP__top__u_core));
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
    vlSelfRef.pc = vlSymsp->TOP__top.pc;
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
    vlSelfRef.debug_wb_have = vlSymsp->TOP__top.debug_wb_have;
    vlSelfRef.debug_wb_pc = vlSymsp->TOP__top.debug_wb_pc;
    vlSelfRef.debug_wb_instr = vlSymsp->TOP__top.debug_wb_instr;
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__2(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_wb_addr = vlSymsp->TOP__top.debug_wb_addr;
    vlSelfRef.debug_wb_en = vlSymsp->TOP__top.debug_wb_en;
    vlSelfRef.debug_wb_data = vlSymsp->TOP__top.debug_wb_data;
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__3(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__3\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.instr = vlSymsp->TOP__top.instr;
}
