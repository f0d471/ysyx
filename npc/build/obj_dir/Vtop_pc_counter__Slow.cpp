// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_pc_counter.h"

void Vtop_pc_counter___ctor_var_reset(Vtop_pc_counter* vlSelf);

Vtop_pc_counter::Vtop_pc_counter(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_pc_counter___ctor_var_reset(this);
}

void Vtop_pc_counter::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_pc_counter::~Vtop_pc_counter() {
}
