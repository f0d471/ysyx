// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_fetch.h"

void Vtop_fetch___ctor_var_reset(Vtop_fetch* vlSelf);

Vtop_fetch::Vtop_fetch(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_fetch___ctor_var_reset(this);
}

void Vtop_fetch::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_fetch::~Vtop_fetch() {
}
