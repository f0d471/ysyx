// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop_top.h"
#include "Vtop___024unit.h"
#include "Vtop_pipe_reg_if2id.h"
#include "Vtop_memory.h"
#include "Vtop_writeback.h"
#include "Vtop_csr_file.h"
#include "Vtop_reg_file.h"
#include "Vtop_pipe_reg_mem2wb.h"
#include "Vtop_forward_unit.h"
#include "Vtop_fetch.h"
#include "Vtop_decode.h"
#include "Vtop_hazard_unit.h"
#include "Vtop_execute.h"
#include "Vtop_pipe_reg_id2ex.h"
#include "Vtop_pipe_reg_ex2mem.h"
#include "Vtop_pc_counter.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{
}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP____024unit{this, Verilated::catName(namep, "$unit")}
    , TOP__top{this, Verilated::catName(namep, "top")}
    , TOP__top__u_csr_file{this, Verilated::catName(namep, "top.u_csr_file")}
    , TOP__top__u_decode{this, Verilated::catName(namep, "top.u_decode")}
    , TOP__top__u_ex2mem{this, Verilated::catName(namep, "top.u_ex2mem")}
    , TOP__top__u_execute{this, Verilated::catName(namep, "top.u_execute")}
    , TOP__top__u_fetch{this, Verilated::catName(namep, "top.u_fetch")}
    , TOP__top__u_forward{this, Verilated::catName(namep, "top.u_forward")}
    , TOP__top__u_hazard{this, Verilated::catName(namep, "top.u_hazard")}
    , TOP__top__u_id2ex{this, Verilated::catName(namep, "top.u_id2ex")}
    , TOP__top__u_if2id{this, Verilated::catName(namep, "top.u_if2id")}
    , TOP__top__u_mem2wb{this, Verilated::catName(namep, "top.u_mem2wb")}
    , TOP__top__u_memory{this, Verilated::catName(namep, "top.u_memory")}
    , TOP__top__u_pc_counter{this, Verilated::catName(namep, "top.u_pc_counter")}
    , TOP__top__u_reg_file{this, Verilated::catName(namep, "top.u_reg_file")}
    , TOP__top__u_writeback{this, Verilated::catName(namep, "top.u_writeback")}
{
        // Check resources
        Verilated::stackCheck(488);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT____024unit = &TOP____024unit;
    TOP.__PVT__top = &TOP__top;
    TOP__top.__PVT__u_csr_file = &TOP__top__u_csr_file;
    TOP__top.__PVT__u_decode = &TOP__top__u_decode;
    TOP__top.__PVT__u_ex2mem = &TOP__top__u_ex2mem;
    TOP__top.__PVT__u_execute = &TOP__top__u_execute;
    TOP__top.__PVT__u_fetch = &TOP__top__u_fetch;
    TOP__top.__PVT__u_forward = &TOP__top__u_forward;
    TOP__top.__PVT__u_hazard = &TOP__top__u_hazard;
    TOP__top.__PVT__u_id2ex = &TOP__top__u_id2ex;
    TOP__top.__PVT__u_if2id = &TOP__top__u_if2id;
    TOP__top.__PVT__u_mem2wb = &TOP__top__u_mem2wb;
    TOP__top.__PVT__u_memory = &TOP__top__u_memory;
    TOP__top.__PVT__u_pc_counter = &TOP__top__u_pc_counter;
    TOP__top.__PVT__u_reg_file = &TOP__top__u_reg_file;
    TOP__top.__PVT__u_writeback = &TOP__top__u_writeback;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP____024unit.__Vconfigure(true);
    TOP__top.__Vconfigure(true);
    TOP__top__u_csr_file.__Vconfigure(true);
    TOP__top__u_decode.__Vconfigure(true);
    TOP__top__u_ex2mem.__Vconfigure(true);
    TOP__top__u_execute.__Vconfigure(true);
    TOP__top__u_fetch.__Vconfigure(true);
    TOP__top__u_forward.__Vconfigure(true);
    TOP__top__u_hazard.__Vconfigure(true);
    TOP__top__u_id2ex.__Vconfigure(true);
    TOP__top__u_if2id.__Vconfigure(true);
    TOP__top__u_mem2wb.__Vconfigure(true);
    TOP__top__u_memory.__Vconfigure(true);
    TOP__top__u_pc_counter.__Vconfigure(true);
    TOP__top__u_reg_file.__Vconfigure(true);
    TOP__top__u_writeback.__Vconfigure(true);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
    }
}
