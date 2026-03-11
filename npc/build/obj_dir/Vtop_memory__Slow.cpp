// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_memory.h"

void Vtop_memory___ctor_var_reset(Vtop_memory* vlSelf);

Vtop_memory::Vtop_memory(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_memory___ctor_var_reset(this);
}

void Vtop_memory::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_memory::~Vtop_memory() {
}
