// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_csr_file.h"

void Vtop_csr_file___ctor_var_reset(Vtop_csr_file* vlSelf);

Vtop_csr_file::Vtop_csr_file(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_csr_file___ctor_var_reset(this);
}

void Vtop_csr_file::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_csr_file::~Vtop_csr_file() {
}
