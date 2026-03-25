// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
void Vtop___024root___eval_ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    vlSelfRef.__VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (vlSelfRef.__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (vlSelfRef.__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    vlSelfRef.__VactExecute = vlSelfRef.__VactTriggered.any();
    if (vlSelfRef.__VactExecute) {
        vlSelfRef.__VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (vlSelfRef.__VactExecute);
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (vlSelfRef.__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (vlSelfRef.__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vtemp_1;
    IData/*31:0*/ __Vtemp_2;
    IData/*31:0*/ __Vtemp_3;
    // Body
    vlSelfRef.__VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    vlSelfRef.__VicoContinue = 1U;
    while (vlSelfRef.__VicoContinue) {
        if (VL_UNLIKELY((0x64U < vlSelfRef.__VicoIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/normal/ysyx-workbench/npc/vsrc/sim_top.sv", 22, "", "Input combinational region did not converge.");
        }
        __Vtemp_1 = ((IData)(1U) + vlSelfRef.__VicoIterCount);
        vlSelfRef.__VicoIterCount = __Vtemp_1;
        vlSelfRef.__VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            vlSelfRef.__VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    vlSelfRef.__VnbaIterCount = 0U;
    vlSelfRef.__VnbaFirstIteration = 1U;
    vlSelfRef.__VnbaContinue = 1U;
    while (vlSelfRef.__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < vlSelfRef.__VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/normal/ysyx-workbench/npc/vsrc/sim_top.sv", 22, "", "NBA region did not converge.");
        }
        __Vtemp_2 = ((IData)(1U) + vlSelfRef.__VnbaIterCount);
        vlSelfRef.__VnbaIterCount = __Vtemp_2;
        vlSelfRef.__VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactFirstIteration = 1U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/normal/ysyx-workbench/npc/vsrc/sim_top.sv", 22, "", "Active region did not converge.");
            }
            __Vtemp_3 = ((IData)(1U) + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactIterCount = __Vtemp_3;
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
            vlSelfRef.__VactFirstIteration = 0U;
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            vlSelfRef.__VnbaContinue = 1U;
        }
        vlSelfRef.__VnbaFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelfRef.rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
}
#endif  // VL_DEBUG
