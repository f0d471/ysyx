// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_reg_file.h"

void Vtop_reg_file___ctor_var_reset(Vtop_reg_file* vlSelf);

Vtop_reg_file::Vtop_reg_file(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_reg_file___ctor_var_reset(this);
}

void Vtop_reg_file::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_reg_file::~Vtop_reg_file() {
}
