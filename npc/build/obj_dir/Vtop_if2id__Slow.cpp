// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_if2id.h"

void Vtop_if2id___ctor_var_reset(Vtop_if2id* vlSelf);

Vtop_if2id::Vtop_if2id(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_if2id___ctor_var_reset(this);
}

void Vtop_if2id::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_if2id::~Vtop_if2id() {
}
