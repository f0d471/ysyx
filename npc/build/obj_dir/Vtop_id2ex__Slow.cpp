// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_id2ex.h"

void Vtop_id2ex___ctor_var_reset(Vtop_id2ex* vlSelf);

Vtop_id2ex::Vtop_id2ex(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_id2ex___ctor_var_reset(this);
}

void Vtop_id2ex::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_id2ex::~Vtop_id2ex() {
}
