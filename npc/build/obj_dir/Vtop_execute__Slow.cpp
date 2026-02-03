// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_execute.h"

void Vtop_execute___ctor_var_reset(Vtop_execute* vlSelf);

Vtop_execute::Vtop_execute(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_execute___ctor_var_reset(this);
}

void Vtop_execute::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_execute::~Vtop_execute() {
}
