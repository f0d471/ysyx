// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop___024unit;
class Vtop_top;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop_top* __PVT__top;
    Vtop___024unit* __PVT____024unit;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    CData/*0:0*/ __VstlExecute;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlContinue;
    CData/*0:0*/ __VicoExecute;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoContinue;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top__u_memory____PVT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top__u_csr_file____PVT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top__u_reg_file____PVT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top__u_reg_file____PVT__rst_n__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top__u_pc_counter____PVT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top__u_pc_counter____PVT__rst_n__0;
    CData/*0:0*/ __VactExecute;
    CData/*0:0*/ __VactFirstIteration;
    CData/*0:0*/ __VactContinue;
    CData/*0:0*/ __VnbaExecute;
    CData/*0:0*/ __VnbaFirstIteration;
    CData/*0:0*/ __VnbaContinue;
    VL_OUT(pc,31,0);
    VL_OUT(instr,31,0);
    VL_OUT(debug_x10,31,0);
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VnbaIterCount;
    VL_OUT(regs[16],31,0);
    VlUnpacked<CData/*0:0*/, 7> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<6> __VactTriggered;
    VlTriggerVec<6> __VpreTriggered;
    VlTriggerVec<6> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
