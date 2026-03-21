// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_core.h"

void Vtop_core___ctor_var_reset(Vtop_core* vlSelf);

Vtop_core::Vtop_core(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_core___ctor_var_reset(this);
}

void Vtop_core::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_core::~Vtop_core() {
}
