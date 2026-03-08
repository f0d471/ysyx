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
#include "Vtop_if2id.h"
#include "Vtop_memory.h"
#include "Vtop_writeback.h"
#include "Vtop_csr_file.h"
#include "Vtop_reg_file.h"
#include "Vtop_mem2wb.h"
#include "Vtop_fetch.h"
#include "Vtop_decode.h"
#include "Vtop_execute.h"
#include "Vtop___024unit.h"
#include "Vtop_id2ex.h"
#include "Vtop_ex2mem.h"
#include "Vtop_pc_counter.h"

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
    Vtop_csr_file                  TOP__top__u_csr_file;
    Vtop_decode                    TOP__top__u_decode;
    Vtop_ex2mem                    TOP__top__u_ex2mem;
    Vtop_execute                   TOP__top__u_execute;
    Vtop_fetch                     TOP__top__u_fetch;
    Vtop_id2ex                     TOP__top__u_id2ex;
    Vtop_if2id                     TOP__top__u_if2id;
    Vtop_mem2wb                    TOP__top__u_mem2wb;
    Vtop_memory                    TOP__top__u_memory;
    Vtop_pc_counter                TOP__top__u_pc_counter;
    Vtop_reg_file                  TOP__top__u_reg_file;
    Vtop_writeback                 TOP__top__u_writeback;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
