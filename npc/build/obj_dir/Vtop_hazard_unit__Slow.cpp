// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_hazard_unit.h"

void Vtop_hazard_unit___ctor_var_reset(Vtop_hazard_unit* vlSelf);

Vtop_hazard_unit::Vtop_hazard_unit(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_hazard_unit___ctor_var_reset(this);
}

void Vtop_hazard_unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_hazard_unit::~Vtop_hazard_unit() {
}
