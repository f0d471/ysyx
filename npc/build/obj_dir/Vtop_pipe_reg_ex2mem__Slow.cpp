// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_pipe_reg_ex2mem.h"

void Vtop_pipe_reg_ex2mem___ctor_var_reset(Vtop_pipe_reg_ex2mem* vlSelf);

Vtop_pipe_reg_ex2mem::Vtop_pipe_reg_ex2mem(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_pipe_reg_ex2mem___ctor_var_reset(this);
}

void Vtop_pipe_reg_ex2mem::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_pipe_reg_ex2mem::~Vtop_pipe_reg_ex2mem() {
}
