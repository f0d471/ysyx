// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_forward_unit.h"

VL_ATTR_COLD void Vtop_forward_unit___stl_sequent__TOP__top__u_forward__0(Vtop_forward_unit* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_forward_unit___stl_sequent__TOP__top__u_forward__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__fwd_rs1_sel = (((([&]() {
                        vlSelfRef.__Vfunc_writes_rd__0__op 
                            = vlSelfRef.__PVT__ex_stage_opcode;
                        vlSelfRef.__Vfunc_writes_rd__0__Vfuncout 
                            = ((((((((0x33U == (IData)(vlSelfRef.__Vfunc_writes_rd__0__op)) 
                                     | (0x13U == (IData)(vlSelfRef.__Vfunc_writes_rd__0__op))) 
                                    | (3U == (IData)(vlSelfRef.__Vfunc_writes_rd__0__op))) 
                                   | (0x6fU == (IData)(vlSelfRef.__Vfunc_writes_rd__0__op))) 
                                  | (0x67U == (IData)(vlSelfRef.__Vfunc_writes_rd__0__op))) 
                                 | (0x37U == (IData)(vlSelfRef.__Vfunc_writes_rd__0__op))) 
                                | (0x17U == (IData)(vlSelfRef.__Vfunc_writes_rd__0__op))) 
                               | (0x73U == (IData)(vlSelfRef.__Vfunc_writes_rd__0__op)));
                    }(), (IData)(vlSelfRef.__Vfunc_writes_rd__0__Vfuncout)) 
                                      & (0U != (IData)(vlSelfRef.__PVT__ex_stage_rd_addr))) 
                                     & ((IData)(vlSelfRef.__PVT__ex_stage_rd_addr) 
                                        == (IData)(vlSelfRef.__PVT__ex_rs1_addr)))
                                     ? 1U : (((([&]() {
                            vlSelfRef.__Vfunc_writes_rd__1__op 
                                = vlSelfRef.__PVT__mem_opcode;
                            vlSelfRef.__Vfunc_writes_rd__1__Vfuncout 
                                = ((((((((0x33U == (IData)(vlSelfRef.__Vfunc_writes_rd__1__op)) 
                                         | (0x13U == (IData)(vlSelfRef.__Vfunc_writes_rd__1__op))) 
                                        | (3U == (IData)(vlSelfRef.__Vfunc_writes_rd__1__op))) 
                                       | (0x6fU == (IData)(vlSelfRef.__Vfunc_writes_rd__1__op))) 
                                      | (0x67U == (IData)(vlSelfRef.__Vfunc_writes_rd__1__op))) 
                                     | (0x37U == (IData)(vlSelfRef.__Vfunc_writes_rd__1__op))) 
                                    | (0x17U == (IData)(vlSelfRef.__Vfunc_writes_rd__1__op))) 
                                   | (0x73U == (IData)(vlSelfRef.__Vfunc_writes_rd__1__op)));
                        }(), (IData)(vlSelfRef.__Vfunc_writes_rd__1__Vfuncout)) 
                                               & (0U 
                                                  != (IData)(vlSelfRef.__PVT__mem_rd_addr))) 
                                              & ((IData)(vlSelfRef.__PVT__mem_rd_addr) 
                                                 == (IData)(vlSelfRef.__PVT__ex_rs1_addr)))
                                              ? 2U : 
                                             (((([&]() {
                                vlSelfRef.__Vfunc_writes_rd__2__op 
                                    = vlSelfRef.__PVT__wb_opcode;
                                vlSelfRef.__Vfunc_writes_rd__2__Vfuncout 
                                    = ((((((((0x33U 
                                              == (IData)(vlSelfRef.__Vfunc_writes_rd__2__op)) 
                                             | (0x13U 
                                                == (IData)(vlSelfRef.__Vfunc_writes_rd__2__op))) 
                                            | (3U == (IData)(vlSelfRef.__Vfunc_writes_rd__2__op))) 
                                           | (0x6fU 
                                              == (IData)(vlSelfRef.__Vfunc_writes_rd__2__op))) 
                                          | (0x67U 
                                             == (IData)(vlSelfRef.__Vfunc_writes_rd__2__op))) 
                                         | (0x37U == (IData)(vlSelfRef.__Vfunc_writes_rd__2__op))) 
                                        | (0x17U == (IData)(vlSelfRef.__Vfunc_writes_rd__2__op))) 
                                       | (0x73U == (IData)(vlSelfRef.__Vfunc_writes_rd__2__op)));
                            }(), (IData)(vlSelfRef.__Vfunc_writes_rd__2__Vfuncout)) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.__PVT__wb_rd_addr))) 
                                               & ((IData)(vlSelfRef.__PVT__wb_rd_addr) 
                                                  == (IData)(vlSelfRef.__PVT__ex_rs1_addr)))
                                               ? 3U
                                               : 0U)));
    vlSelfRef.__PVT__fwd_rs2_sel = (((([&]() {
                        vlSelfRef.__Vfunc_writes_rd__3__op 
                            = vlSelfRef.__PVT__ex_stage_opcode;
                        vlSelfRef.__Vfunc_writes_rd__3__Vfuncout 
                            = ((((((((0x33U == (IData)(vlSelfRef.__Vfunc_writes_rd__3__op)) 
                                     | (0x13U == (IData)(vlSelfRef.__Vfunc_writes_rd__3__op))) 
                                    | (3U == (IData)(vlSelfRef.__Vfunc_writes_rd__3__op))) 
                                   | (0x6fU == (IData)(vlSelfRef.__Vfunc_writes_rd__3__op))) 
                                  | (0x67U == (IData)(vlSelfRef.__Vfunc_writes_rd__3__op))) 
                                 | (0x37U == (IData)(vlSelfRef.__Vfunc_writes_rd__3__op))) 
                                | (0x17U == (IData)(vlSelfRef.__Vfunc_writes_rd__3__op))) 
                               | (0x73U == (IData)(vlSelfRef.__Vfunc_writes_rd__3__op)));
                    }(), (IData)(vlSelfRef.__Vfunc_writes_rd__3__Vfuncout)) 
                                      & (0U != (IData)(vlSelfRef.__PVT__ex_stage_rd_addr))) 
                                     & ((IData)(vlSelfRef.__PVT__ex_stage_rd_addr) 
                                        == (IData)(vlSelfRef.__PVT__ex_rs2_addr)))
                                     ? 1U : (((([&]() {
                            vlSelfRef.__Vfunc_writes_rd__4__op 
                                = vlSelfRef.__PVT__mem_opcode;
                            vlSelfRef.__Vfunc_writes_rd__4__Vfuncout 
                                = ((((((((0x33U == (IData)(vlSelfRef.__Vfunc_writes_rd__4__op)) 
                                         | (0x13U == (IData)(vlSelfRef.__Vfunc_writes_rd__4__op))) 
                                        | (3U == (IData)(vlSelfRef.__Vfunc_writes_rd__4__op))) 
                                       | (0x6fU == (IData)(vlSelfRef.__Vfunc_writes_rd__4__op))) 
                                      | (0x67U == (IData)(vlSelfRef.__Vfunc_writes_rd__4__op))) 
                                     | (0x37U == (IData)(vlSelfRef.__Vfunc_writes_rd__4__op))) 
                                    | (0x17U == (IData)(vlSelfRef.__Vfunc_writes_rd__4__op))) 
                                   | (0x73U == (IData)(vlSelfRef.__Vfunc_writes_rd__4__op)));
                        }(), (IData)(vlSelfRef.__Vfunc_writes_rd__4__Vfuncout)) 
                                               & (0U 
                                                  != (IData)(vlSelfRef.__PVT__mem_rd_addr))) 
                                              & ((IData)(vlSelfRef.__PVT__mem_rd_addr) 
                                                 == (IData)(vlSelfRef.__PVT__ex_rs2_addr)))
                                              ? 2U : 
                                             (((([&]() {
                                vlSelfRef.__Vfunc_writes_rd__5__op 
                                    = vlSelfRef.__PVT__wb_opcode;
                                vlSelfRef.__Vfunc_writes_rd__5__Vfuncout 
                                    = ((((((((0x33U 
                                              == (IData)(vlSelfRef.__Vfunc_writes_rd__5__op)) 
                                             | (0x13U 
                                                == (IData)(vlSelfRef.__Vfunc_writes_rd__5__op))) 
                                            | (3U == (IData)(vlSelfRef.__Vfunc_writes_rd__5__op))) 
                                           | (0x6fU 
                                              == (IData)(vlSelfRef.__Vfunc_writes_rd__5__op))) 
                                          | (0x67U 
                                             == (IData)(vlSelfRef.__Vfunc_writes_rd__5__op))) 
                                         | (0x37U == (IData)(vlSelfRef.__Vfunc_writes_rd__5__op))) 
                                        | (0x17U == (IData)(vlSelfRef.__Vfunc_writes_rd__5__op))) 
                                       | (0x73U == (IData)(vlSelfRef.__Vfunc_writes_rd__5__op)));
                            }(), (IData)(vlSelfRef.__Vfunc_writes_rd__5__Vfuncout)) 
                                                & (0U 
                                                   != (IData)(vlSelfRef.__PVT__wb_rd_addr))) 
                                               & ((IData)(vlSelfRef.__PVT__wb_rd_addr) 
                                                  == (IData)(vlSelfRef.__PVT__ex_rs2_addr)))
                                               ? 3U
                                               : 0U)));
}

VL_ATTR_COLD void Vtop_forward_unit___ctor_var_reset(Vtop_forward_unit* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_forward_unit___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__ex_rs1_addr = 0;
    vlSelf->__PVT__ex_rs2_addr = 0;
    vlSelf->__PVT__ex_stage_rd_addr = 0;
    vlSelf->__PVT__ex_stage_opcode = 0;
    vlSelf->__PVT__mem_rd_addr = 0;
    vlSelf->__PVT__mem_opcode = 0;
    vlSelf->__PVT__wb_rd_addr = 0;
    vlSelf->__PVT__wb_opcode = 0;
    vlSelf->__PVT__fwd_rs1_sel = 0;
    vlSelf->__PVT__fwd_rs2_sel = 0;
    vlSelf->__Vfunc_writes_rd__0__Vfuncout = 0;
    vlSelf->__Vfunc_writes_rd__0__op = 0;
    vlSelf->__Vfunc_writes_rd__1__Vfuncout = 0;
    vlSelf->__Vfunc_writes_rd__1__op = 0;
    vlSelf->__Vfunc_writes_rd__2__Vfuncout = 0;
    vlSelf->__Vfunc_writes_rd__2__op = 0;
    vlSelf->__Vfunc_writes_rd__3__Vfuncout = 0;
    vlSelf->__Vfunc_writes_rd__3__op = 0;
    vlSelf->__Vfunc_writes_rd__4__Vfuncout = 0;
    vlSelf->__Vfunc_writes_rd__4__op = 0;
    vlSelf->__Vfunc_writes_rd__5__Vfuncout = 0;
    vlSelf->__Vfunc_writes_rd__5__op = 0;
}
