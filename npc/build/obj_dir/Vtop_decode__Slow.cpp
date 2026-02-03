// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_decode.h"

void Vtop_decode___ctor_var_reset(Vtop_decode* vlSelf);

Vtop_decode::Vtop_decode(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_decode___ctor_var_reset(this);
}

void Vtop_decode::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_decode::~Vtop_decode() {
}
