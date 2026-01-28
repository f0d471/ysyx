// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTOP__DPI_H_
#define VERILATED_VTOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/normal/ysyx-workbench/npc/vsrc/core_top.sv:3:29
    extern int paddr_read(int addr);
    // DPI import at /home/normal/ysyx-workbench/npc/vsrc/core_top.sv:4:30
    extern void paddr_write(int addr, int len, int data);

#ifdef __cplusplus
}
#endif

#endif  // guard
