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
    // DPI import at /home/normal/ysyx-workbench/npc/vsrc/sim_top.sv:11:30
    extern int paddr_read(int addr);
    // DPI import at /home/normal/ysyx-workbench/npc/vsrc/sim_top.sv:12:30
    extern void paddr_write(int addr, int len, int data);
    // DPI import at /home/normal/ysyx-workbench/npc/vsrc/core_top.sv:3:30
    extern void trap(int code, int pc);

#ifdef __cplusplus
}
#endif

#endif  // guard
