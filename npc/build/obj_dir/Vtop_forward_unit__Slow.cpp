// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_forward_unit.h"

void Vtop_forward_unit___ctor_var_reset(Vtop_forward_unit* vlSelf);

Vtop_forward_unit::Vtop_forward_unit(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_forward_unit___ctor_var_reset(this);
}

void Vtop_forward_unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_forward_unit::~Vtop_forward_unit() {
}
