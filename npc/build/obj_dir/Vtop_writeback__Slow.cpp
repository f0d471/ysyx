// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_writeback.h"

void Vtop_writeback___ctor_var_reset(Vtop_writeback* vlSelf);

Vtop_writeback::Vtop_writeback(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_writeback___ctor_var_reset(this);
}

void Vtop_writeback::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_writeback::~Vtop_writeback() {
}
