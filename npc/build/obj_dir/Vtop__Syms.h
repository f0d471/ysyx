// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"
#include "Vtop_top.h"
#include "Vtop___024unit.h"
#include "Vtop_core.h"
#include "Vtop_sim_sram__D1.h"
#include "Vtop_sim_sram__LBz1_H1.h"
#include "Vtop_memory.h"
#include "Vtop_writeback.h"
#include "Vtop_csr_file.h"
#include "Vtop_reg_file.h"
#include "Vtop_forward_unit.h"
#include "Vtop_fetch.h"
#include "Vtop_decode.h"
#include "Vtop_hazard_unit.h"
#include "Vtop_execute.h"
#include "Vtop_pc_counter.h"
#include "Vtop_pipe_reg__D40.h"
#include "Vtop_pipe_reg__D107.h"
#include "Vtop_pipe_reg__D8f.h"
#include "Vtop_pipe_reg__D8c.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;
    Vtop___024unit                 TOP____024unit;
    Vtop_top                       TOP__top;
    Vtop_core                      TOP__top__u_core;
    Vtop_csr_file                  TOP__top__u_core__u_csr_file;
    Vtop_decode                    TOP__top__u_core__u_decode;
    Vtop_pipe_reg__D8f             TOP__top__u_core__u_ex2mem;
    Vtop_execute                   TOP__top__u_core__u_execute;
    Vtop_fetch                     TOP__top__u_core__u_fetch;
    Vtop_forward_unit              TOP__top__u_core__u_forward;
    Vtop_hazard_unit               TOP__top__u_core__u_hazard;
    Vtop_pipe_reg__D107            TOP__top__u_core__u_id2ex;
    Vtop_pipe_reg__D40             TOP__top__u_core__u_if2id;
    Vtop_pipe_reg__D8c             TOP__top__u_core__u_mem2wb;
    Vtop_memory                    TOP__top__u_core__u_memory;
    Vtop_pc_counter                TOP__top__u_core__u_pc_counter;
    Vtop_reg_file                  TOP__top__u_core__u_reg_file;
    Vtop_writeback                 TOP__top__u_core__u_writeback;
    Vtop_sim_sram__D1              TOP__top__u_sram_ifu;
    Vtop_sim_sram__LBz1_H1         TOP__top__u_sram_lsu;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
