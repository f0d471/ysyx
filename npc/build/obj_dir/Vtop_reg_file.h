// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_REG_FILE_H_
#define VERILATED_VTOP_REG_FILE_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_reg_file final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst_n,0,0);
    VL_IN8(__PVT__rs1_addr,4,0);
    VL_IN8(__PVT__rs2_addr,4,0);
    VL_IN8(__PVT__wr_en,0,0);
    VL_IN8(__PVT__wr_addr,4,0);
    CData/*3:0*/ __VdlyDim0__rf__v0;
    CData/*0:0*/ __VdlySet__rf__v0;
    CData/*0:0*/ __VdlySet__rf__v1;
    CData/*0:0*/ __VdlySet__rf__v2;
    CData/*0:0*/ __VdlySet__rf__v3;
    CData/*0:0*/ __VdlySet__rf__v4;
    CData/*0:0*/ __VdlySet__rf__v5;
    CData/*0:0*/ __VdlySet__rf__v6;
    CData/*0:0*/ __VdlySet__rf__v7;
    CData/*0:0*/ __VdlySet__rf__v8;
    CData/*0:0*/ __VdlySet__rf__v9;
    CData/*0:0*/ __VdlySet__rf__v10;
    CData/*0:0*/ __VdlySet__rf__v11;
    CData/*0:0*/ __VdlySet__rf__v12;
    CData/*0:0*/ __VdlySet__rf__v13;
    CData/*0:0*/ __VdlySet__rf__v14;
    CData/*0:0*/ __VdlySet__rf__v15;
    CData/*0:0*/ __VdlySet__rf__v16;
    VL_OUT(__PVT__rs1_data,31,0);
    VL_OUT(__PVT__rs2_data,31,0);
    VL_IN(__PVT__wr_data,31,0);
    VL_OUT(__PVT__debug_x10,31,0);
    IData/*31:0*/ __PVT__unnamedblk1__DOT__i;
    IData/*31:0*/ __VdlyVal__rf__v0;
    VL_OUT(__PVT__regs[16],31,0);
    VlUnpacked<IData/*31:0*/, 16> __PVT__rf;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_reg_file(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_reg_file();
    VL_UNCOPYABLE(Vtop_reg_file);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
