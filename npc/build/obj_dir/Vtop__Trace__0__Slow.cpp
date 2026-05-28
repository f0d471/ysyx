// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+471,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+472,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+473,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+474,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+475+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+491,0,"debug_wb_have",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+492,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+493,0,"debug_wb_instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+494,0,"debug_wb_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+495,0,"debug_wb_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+496,0,"debug_wb_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+11,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+436,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+74+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+139,0,"debug_wb_have",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+140,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"debug_wb_instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+142,0,"debug_wb_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+143,0,"debug_wb_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+144,0,"debug_wb_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+55,0,"ifu_raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"ifu_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+466,0,"ifu_reqValid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"ifu_reqReady",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"ifu_respValid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+437,0,"ifu_respReady",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+193,0,"lsu_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+194,0,"lsu_ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+195,0,"lsu_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+196,0,"lsu_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+197,0,"lsu_wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+35,0,"lsu_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+385,0,"lsu_reqValid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"lsu_reqReady",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"lsu_respValid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"lsu_respReady",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_core", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+510,0,"IFU_MAX_DELAY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"ifu_delay_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+39,0,"ifu_delay_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+40,0,"ifu_mem_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+41,0,"ifu_rdata_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"ifu_lfsr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+510,0,"LSU_MAX_DELAY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"lsu_delay_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+44,0,"lsu_delay_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+45,0,"lsu_mem_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"lsu_rdata_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"lsu_lfsr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_pc_counter__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_fetch__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_if2id__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_decode__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_reg_file__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_csr_file__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_hazard__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_forward__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_id2ex__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_execute__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_ex2mem__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_memory__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_mem2wb__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_writeback__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+511,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+511,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+13,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+56,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+438,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+90+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+57,0,"ifu_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+467,0,"ifu_reqValid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"ifu_reqReady",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"ifu_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+49,0,"ifu_respValid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+439,0,"ifu_respReady",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+198,0,"lsu_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+199,0,"lsu_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+200,0,"lsu_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+201,0,"lsu_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+202,0,"lsu_wmask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+386,0,"lsu_reqValid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"lsu_reqReady",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"lsu_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+52,0,"lsu_respValid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"lsu_respReady",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+145,0,"debug_wb_have",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+146,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"debug_wb_instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+148,0,"debug_wb_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+149,0,"debug_wb_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+150,0,"debug_wb_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+497,0,"if2id_up_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"if2id_dn_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+463,0,"id2ex_up_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+243,0,"id2ex_dn_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+433,0,"ex2mem_up_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+203,0,"ex2mem_dn_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"mem2wb_up_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+152,0,"mem2wb_dn_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+498,0,"if_id_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+316,0,"if_id_dn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declArray(c+372,0,"id_ex_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 262,0);
    tracep->declArray(c+244,0,"id_ex_dn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 262,0);
    tracep->declArray(c+310,0,"ex_mem_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 142,0);
    tracep->declArray(c+204,0,"ex_mem_dn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 142,0);
    tracep->declArray(c+238,0,"mem_wb_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 139,0);
    tracep->declArray(c+153,0,"mem_wb_dn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 139,0);
    tracep->declBus(c+318,0,"decode_rs1_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+319,0,"decode_rs2_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+320,0,"decode_rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+321,0,"decode_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+322,0,"decode_op1_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+323,0,"decode_op2_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+324,0,"decode_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+325,0,"decode_funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+326,0,"decode_funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+327,0,"decode_csr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+328,0,"decode_inst_csrrw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+329,0,"decode_inst_csrrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+330,0,"decode_inst_ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+331,0,"decode_inst_mret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+332,0,"decode_inst_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+427,0,"reg_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+428,0,"reg_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+448,0,"fwd_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+449,0,"fwd_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+450,0,"id_op1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+451,0,"id_op2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+401,0,"ex_alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+402,0,"ex_jump_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+403,0,"ex_jump_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+387,0,"mem_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+158,0,"wb_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+159,0,"wb_wr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+160,0,"wb_wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+423,0,"load_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+512,0,"fwd_rs1_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+513,0,"fwd_rs2_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+440,0,"ifu_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+388,0,"lsu_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+253,0,"csr_raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+404,0,"csr_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+254,0,"csr_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+255,0,"csr_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+405,0,"csr_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+256,0,"trap_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+257,0,"trap_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"trap_cause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"trap_mtvec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"trap_mepc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+445,0,"backend_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+468,0,"pc_hold_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_pc_counter", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_pc_counter__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_fetch", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_fetch__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_if2id", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_if2id__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_decode", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_decode__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_reg_file", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_reg_file__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_csr_file", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_csr_file__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_hazard", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_hazard__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_forward", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_forward__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_id2ex", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_id2ex__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_execute", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_execute__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_ex2mem", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_ex2mem__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_memory", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_memory__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_mem2wb", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_mem2wb__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_writeback", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__u_writeback__0(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_memory__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_memory__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+511,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+511,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+15,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+209,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+210,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+211,0,"rs2_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+212,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+213,0,"funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+214,0,"lsu_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+215,0,"lsu_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+216,0,"lsu_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+217,0,"lsu_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+218,0,"lsu_wmask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+389,0,"lsu_reqValid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"lsu_reqReady",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+381,0,"lsu_respValid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+190,0,"lsu_respReady",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+382,0,"lsu_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+390,0,"lsu_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+391,0,"mem_rdata_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+219,0,"is_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+220,0,"is_store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+221,0,"is_mem",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+191,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+500,0,"state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+192,0,"rdata_latch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+222,0,"wmask_gen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_writeback__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_writeback__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+511,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"mem_rdata_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+164,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+165,0,"wb_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+166,0,"wb_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+167,0,"wb_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_csr_file__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_csr_file__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+514,0,"STU_ID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+17,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+258,0,"csr_raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+406,0,"csr_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+259,0,"csr_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+260,0,"csr_waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+407,0,"csr_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+261,0,"trap_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+262,0,"trap_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"trap_cause",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"trap_mtvec",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+65,0,"trap_mepc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,0,"mstatus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,0,"mtvec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"mepc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"mcause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+70,0,"mcycle_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_reg_file__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_reg_file__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+511,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+19,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+333,0,"rs1_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+334,0,"rs2_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+429,0,"rs1_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+430,0,"rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+168,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+169,0,"wr_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+170,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+106+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+122+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+138,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_forward__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_forward__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+335,0,"ex_rs1_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+336,0,"ex_rs2_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+263,0,"ex_stage_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+264,0,"ex_stage_rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+408,0,"ex_alu_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+223,0,"mem_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+224,0,"mem_rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+225,0,"ex_mem_alu_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+392,0,"mem_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"wb_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+172,0,"wb_rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+173,0,"wb_wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+431,0,"reg_rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+432,0,"reg_rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+452,0,"fwd_rs1_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+453,0,"fwd_rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+501,0,"fwd_rs1_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+502,0,"fwd_rs2_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_fetch__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_fetch__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+511,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+511,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+21,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"pc_pointer",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"ifu_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+383,0,"ifu_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+469,0,"ifu_reqValid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"ifu_reqReady",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+384,0,"ifu_respValid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+441,0,"ifu_respReady",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+409,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+446,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+442,0,"instr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+443,0,"ifu_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+503,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+504,0,"state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+505,0,"instr_latch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_decode__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_decode__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+511,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+511,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+337,0,"instr_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+338,0,"instr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+339,0,"rd_rs1_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+340,0,"rd_rs2_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+341,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+342,0,"imm_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+343,0,"op1_sel_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+344,0,"op2_sel_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+345,0,"opcode_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+346,0,"funct3_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+347,0,"funct7_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+348,0,"inst_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+349,0,"csr_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+350,0,"inst_csrrw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+351,0,"inst_csrrs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+352,0,"inst_ecall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+353,0,"inst_mret",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+354,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+355,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+356,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+357,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+358,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+359,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+360,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+361,0,"is_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+362,0,"is_system",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+515,0,"OP1_RS1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+516,0,"OP1_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+517,0,"OP1_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+515,0,"OP2_RS2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+516,0,"OP2_IMM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+517,0,"OP2_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_hazard__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_hazard__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+265,0,"ex_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+266,0,"ex_rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+363,0,"id_rs1_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+364,0,"id_rs2_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+424,0,"stall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+267,0,"ex_is_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+425,0,"rs1_hazard",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+426,0,"rs2_hazard",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_execute__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_execute__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+511,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+511,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+268,0,"pc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+269,0,"op1_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+270,0,"op2_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+271,0,"rs1_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+272,0,"imm_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+273,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+274,0,"funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+275,0,"funct7_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+410,0,"alu_result_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+411,0,"jump_flag_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+412,0,"jump_target_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+276,0,"inst_ebreak_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+277,0,"csr_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+278,0,"inst_csrrw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+279,0,"inst_csrrs",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+280,0,"inst_ecall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+281,0,"inst_mret",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+282,0,"csr_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+413,0,"csr_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+283,0,"csr_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+284,0,"csr_waddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+414,0,"csr_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+285,0,"trap_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+286,0,"trap_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"trap_cause",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"trap_mtvec",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"trap_mepc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+287,0,"alu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+288,0,"branch_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_pc_counter__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_pc_counter__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+511,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+518,0,"RESET_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+23,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+415,0,"jump_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+416,0,"jump_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+470,0,"pc_hold",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+60,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"pc_pointer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_if2id__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_if2id__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+519,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+25,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+417,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+447,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+444,0,"up_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+506,0,"up_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+507,0,"up_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+365,0,"dn_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+464,0,"dn_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+366,0,"dn_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+368,0,"data_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+370,0,"valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_id2ex__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_id2ex__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+520,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+27,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+509,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+393,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+371,0,"up_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+465,0,"up_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+454,0,"up_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 262,0);
    tracep->declBit(c+289,0,"dn_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+434,0,"dn_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+290,0,"dn_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 262,0);
    tracep->declArray(c+299,0,"data_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 262,0);
    tracep->declBit(c+308,0,"valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_ex2mem__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_ex2mem__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+521,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+29,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+394,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+309,0,"up_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+435,0,"up_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+418,0,"up_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 142,0);
    tracep->declBit(c+226,0,"dn_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+174,0,"dn_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+227,0,"dn_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 142,0);
    tracep->declArray(c+232,0,"data_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 142,0);
    tracep->declBit(c+237,0,"valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_mem2wb__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_mem2wb__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+522,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+31,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+395,0,"up_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+175,0,"up_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+396,0,"up_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 139,0);
    tracep->declBit(c+176,0,"dn_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"dn_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+177,0,"dn_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 139,0);
    tracep->declArray(c+182,0,"data_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 139,0);
    tracep->declBit(c+187,0,"valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+510,(3U),32);
    bufp->fullIData(oldp+511,(0x20U),32);
    bufp->fullCData(oldp+512,(vlSymsp->TOP__top__u_core.__PVT__fwd_rs1_sel),2);
    bufp->fullCData(oldp+513,(vlSymsp->TOP__top__u_core.__PVT__fwd_rs2_sel),2);
    bufp->fullIData(oldp+514,(0x3d1c5U),32);
    bufp->fullCData(oldp+515,(0U),2);
    bufp->fullCData(oldp+516,(1U),2);
    bufp->fullCData(oldp+517,(2U),2);
    bufp->fullIData(oldp+518,(0x80000000U),32);
    bufp->fullIData(oldp+519,(0x40U),32);
    bufp->fullIData(oldp+520,(0x107U),32);
    bufp->fullIData(oldp+521,(0x8fU),32);
    bufp->fullIData(oldp+522,(0x8cU),32);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSymsp->TOP__top.__PVT__ifu_reqReady));
    bufp->fullBit(oldp+2,(vlSymsp->TOP__top__u_core.__PVT__ifu_reqReady));
    bufp->fullIData(oldp+3,(vlSymsp->TOP__top__u_core.__PVT__trap_cause),32);
    bufp->fullIData(oldp+4,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_cause),32);
    bufp->fullBit(oldp+5,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__ifu_reqReady));
    bufp->fullIData(oldp+6,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_cause),32);
    bufp->fullBit(oldp+7,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__flush));
    bufp->fullBit(oldp+8,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__flush));
    bufp->fullBit(oldp+9,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__stall));
    bufp->fullBit(oldp+10,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__dn_ready));
    bufp->fullBit(oldp+11,(vlSymsp->TOP__top.clk));
    bufp->fullBit(oldp+12,(vlSymsp->TOP__top.rst_n));
    bufp->fullBit(oldp+13,(vlSymsp->TOP__top__u_core.__PVT__clk));
    bufp->fullBit(oldp+14,(vlSymsp->TOP__top__u_core.__PVT__rst_n));
    bufp->fullBit(oldp+15,(vlSymsp->TOP__top__u_core__u_memory.__PVT__clk));
    bufp->fullBit(oldp+16,(vlSymsp->TOP__top__u_core__u_memory.__PVT__rst_n));
    bufp->fullBit(oldp+17,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__clk));
    bufp->fullBit(oldp+18,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__rst));
    bufp->fullBit(oldp+19,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__clk));
    bufp->fullBit(oldp+20,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rst_n));
    bufp->fullBit(oldp+21,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__clk));
    bufp->fullBit(oldp+22,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__rst_n));
    bufp->fullBit(oldp+23,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__clk));
    bufp->fullBit(oldp+24,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__rst_n));
    bufp->fullBit(oldp+25,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__clk));
    bufp->fullBit(oldp+26,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__rst_n));
    bufp->fullBit(oldp+27,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__clk));
    bufp->fullBit(oldp+28,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__rst_n));
    bufp->fullBit(oldp+29,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__clk));
    bufp->fullBit(oldp+30,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__rst_n));
    bufp->fullBit(oldp+31,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__clk));
    bufp->fullBit(oldp+32,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__rst_n));
    bufp->fullIData(oldp+33,(vlSymsp->TOP__top.__PVT__ifu_rdata),32);
    bufp->fullBit(oldp+34,(vlSymsp->TOP__top.__PVT__ifu_respValid));
    bufp->fullIData(oldp+35,(vlSymsp->TOP__top.__PVT__lsu_rdata),32);
    bufp->fullBit(oldp+36,(vlSymsp->TOP__top.__PVT__lsu_reqReady));
    bufp->fullBit(oldp+37,(vlSymsp->TOP__top.__PVT__lsu_respValid));
    bufp->fullCData(oldp+38,(vlSymsp->TOP__top.__PVT__ifu_delay_cnt),4);
    bufp->fullCData(oldp+39,(vlSymsp->TOP__top.__PVT__ifu_delay_target),4);
    bufp->fullBit(oldp+40,(vlSymsp->TOP__top.__PVT__ifu_mem_busy));
    bufp->fullIData(oldp+41,(vlSymsp->TOP__top.__PVT__ifu_rdata_buf),32);
    bufp->fullCData(oldp+42,(vlSymsp->TOP__top.__PVT__ifu_lfsr),8);
    bufp->fullCData(oldp+43,(vlSymsp->TOP__top.__PVT__lsu_delay_cnt),4);
    bufp->fullCData(oldp+44,(vlSymsp->TOP__top.__PVT__lsu_delay_target),4);
    bufp->fullBit(oldp+45,(vlSymsp->TOP__top.__PVT__lsu_mem_busy));
    bufp->fullIData(oldp+46,(vlSymsp->TOP__top.__PVT__lsu_rdata_buf),32);
    bufp->fullCData(oldp+47,(vlSymsp->TOP__top.__PVT__lsu_lfsr),8);
    bufp->fullIData(oldp+48,(vlSymsp->TOP__top__u_core.__PVT__ifu_rdata),32);
    bufp->fullBit(oldp+49,(vlSymsp->TOP__top__u_core.__PVT__ifu_respValid));
    bufp->fullBit(oldp+50,(vlSymsp->TOP__top__u_core.__PVT__lsu_reqReady));
    bufp->fullIData(oldp+51,(vlSymsp->TOP__top__u_core.__PVT__lsu_rdata),32);
    bufp->fullBit(oldp+52,(vlSymsp->TOP__top__u_core.__PVT__lsu_respValid));
    bufp->fullBit(oldp+53,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_reqReady));
    bufp->fullIData(oldp+54,(vlSymsp->TOP__top.pc),32);
    bufp->fullIData(oldp+55,(vlSymsp->TOP__top.__PVT__ifu_raddr),32);
    bufp->fullIData(oldp+56,(vlSymsp->TOP__top__u_core.__PVT__pc),32);
    bufp->fullIData(oldp+57,(vlSymsp->TOP__top__u_core.__PVT__ifu_raddr),32);
    bufp->fullIData(oldp+58,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__pc_pointer),32);
    bufp->fullIData(oldp+59,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__ifu_raddr),32);
    bufp->fullIData(oldp+60,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__pc),32);
    bufp->fullIData(oldp+61,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__pc_pointer),32);
    bufp->fullIData(oldp+62,(vlSymsp->TOP__top__u_core.__PVT__trap_mtvec),32);
    bufp->fullIData(oldp+63,(vlSymsp->TOP__top__u_core.__PVT__trap_mepc),32);
    bufp->fullIData(oldp+64,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_mtvec),32);
    bufp->fullIData(oldp+65,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_mepc),32);
    bufp->fullIData(oldp+66,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mstatus),32);
    bufp->fullIData(oldp+67,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mtvec),32);
    bufp->fullIData(oldp+68,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mepc),32);
    bufp->fullIData(oldp+69,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mcause),32);
    bufp->fullQData(oldp+70,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mcycle_cnt),64);
    bufp->fullIData(oldp+72,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_mtvec),32);
    bufp->fullIData(oldp+73,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_mepc),32);
    bufp->fullIData(oldp+74,(vlSymsp->TOP__top.regs[0]),32);
    bufp->fullIData(oldp+75,(vlSymsp->TOP__top.regs[1]),32);
    bufp->fullIData(oldp+76,(vlSymsp->TOP__top.regs[2]),32);
    bufp->fullIData(oldp+77,(vlSymsp->TOP__top.regs[3]),32);
    bufp->fullIData(oldp+78,(vlSymsp->TOP__top.regs[4]),32);
    bufp->fullIData(oldp+79,(vlSymsp->TOP__top.regs[5]),32);
    bufp->fullIData(oldp+80,(vlSymsp->TOP__top.regs[6]),32);
    bufp->fullIData(oldp+81,(vlSymsp->TOP__top.regs[7]),32);
    bufp->fullIData(oldp+82,(vlSymsp->TOP__top.regs[8]),32);
    bufp->fullIData(oldp+83,(vlSymsp->TOP__top.regs[9]),32);
    bufp->fullIData(oldp+84,(vlSymsp->TOP__top.regs[10]),32);
    bufp->fullIData(oldp+85,(vlSymsp->TOP__top.regs[11]),32);
    bufp->fullIData(oldp+86,(vlSymsp->TOP__top.regs[12]),32);
    bufp->fullIData(oldp+87,(vlSymsp->TOP__top.regs[13]),32);
    bufp->fullIData(oldp+88,(vlSymsp->TOP__top.regs[14]),32);
    bufp->fullIData(oldp+89,(vlSymsp->TOP__top.regs[15]),32);
    bufp->fullIData(oldp+90,(vlSymsp->TOP__top__u_core.__PVT__regs[0]),32);
    bufp->fullIData(oldp+91,(vlSymsp->TOP__top__u_core.__PVT__regs[1]),32);
    bufp->fullIData(oldp+92,(vlSymsp->TOP__top__u_core.__PVT__regs[2]),32);
    bufp->fullIData(oldp+93,(vlSymsp->TOP__top__u_core.__PVT__regs[3]),32);
    bufp->fullIData(oldp+94,(vlSymsp->TOP__top__u_core.__PVT__regs[4]),32);
    bufp->fullIData(oldp+95,(vlSymsp->TOP__top__u_core.__PVT__regs[5]),32);
    bufp->fullIData(oldp+96,(vlSymsp->TOP__top__u_core.__PVT__regs[6]),32);
    bufp->fullIData(oldp+97,(vlSymsp->TOP__top__u_core.__PVT__regs[7]),32);
    bufp->fullIData(oldp+98,(vlSymsp->TOP__top__u_core.__PVT__regs[8]),32);
    bufp->fullIData(oldp+99,(vlSymsp->TOP__top__u_core.__PVT__regs[9]),32);
    bufp->fullIData(oldp+100,(vlSymsp->TOP__top__u_core.__PVT__regs[10]),32);
    bufp->fullIData(oldp+101,(vlSymsp->TOP__top__u_core.__PVT__regs[11]),32);
    bufp->fullIData(oldp+102,(vlSymsp->TOP__top__u_core.__PVT__regs[12]),32);
    bufp->fullIData(oldp+103,(vlSymsp->TOP__top__u_core.__PVT__regs[13]),32);
    bufp->fullIData(oldp+104,(vlSymsp->TOP__top__u_core.__PVT__regs[14]),32);
    bufp->fullIData(oldp+105,(vlSymsp->TOP__top__u_core.__PVT__regs[15]),32);
    bufp->fullIData(oldp+106,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[0]),32);
    bufp->fullIData(oldp+107,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[1]),32);
    bufp->fullIData(oldp+108,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[2]),32);
    bufp->fullIData(oldp+109,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[3]),32);
    bufp->fullIData(oldp+110,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[4]),32);
    bufp->fullIData(oldp+111,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[5]),32);
    bufp->fullIData(oldp+112,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[6]),32);
    bufp->fullIData(oldp+113,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[7]),32);
    bufp->fullIData(oldp+114,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[8]),32);
    bufp->fullIData(oldp+115,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[9]),32);
    bufp->fullIData(oldp+116,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[10]),32);
    bufp->fullIData(oldp+117,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[11]),32);
    bufp->fullIData(oldp+118,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[12]),32);
    bufp->fullIData(oldp+119,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[13]),32);
    bufp->fullIData(oldp+120,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[14]),32);
    bufp->fullIData(oldp+121,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[15]),32);
    bufp->fullIData(oldp+122,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[0]),32);
    bufp->fullIData(oldp+123,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[1]),32);
    bufp->fullIData(oldp+124,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[2]),32);
    bufp->fullIData(oldp+125,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[3]),32);
    bufp->fullIData(oldp+126,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[4]),32);
    bufp->fullIData(oldp+127,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[5]),32);
    bufp->fullIData(oldp+128,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[6]),32);
    bufp->fullIData(oldp+129,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[7]),32);
    bufp->fullIData(oldp+130,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[8]),32);
    bufp->fullIData(oldp+131,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[9]),32);
    bufp->fullIData(oldp+132,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[10]),32);
    bufp->fullIData(oldp+133,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[11]),32);
    bufp->fullIData(oldp+134,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[12]),32);
    bufp->fullIData(oldp+135,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[13]),32);
    bufp->fullIData(oldp+136,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[14]),32);
    bufp->fullIData(oldp+137,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[15]),32);
    bufp->fullIData(oldp+138,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+139,(vlSymsp->TOP__top.debug_wb_have));
    bufp->fullIData(oldp+140,(vlSymsp->TOP__top.debug_wb_pc),32);
    bufp->fullIData(oldp+141,(vlSymsp->TOP__top.debug_wb_instr),32);
    bufp->fullBit(oldp+142,(vlSymsp->TOP__top.debug_wb_en));
    bufp->fullCData(oldp+143,(vlSymsp->TOP__top.debug_wb_addr),5);
    bufp->fullIData(oldp+144,(vlSymsp->TOP__top.debug_wb_data),32);
    bufp->fullBit(oldp+145,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_have));
    bufp->fullIData(oldp+146,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_pc),32);
    bufp->fullIData(oldp+147,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_instr),32);
    bufp->fullBit(oldp+148,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_en));
    bufp->fullCData(oldp+149,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_addr),5);
    bufp->fullIData(oldp+150,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_data),32);
    bufp->fullBit(oldp+151,(vlSymsp->TOP__top__u_core.__PVT__mem2wb_up_ready));
    bufp->fullBit(oldp+152,(vlSymsp->TOP__top__u_core.__PVT__mem2wb_dn_valid));
    bufp->fullWData(oldp+153,(vlSymsp->TOP__top__u_core.__PVT__mem_wb_dn),140);
    bufp->fullBit(oldp+158,(vlSymsp->TOP__top__u_core.__PVT__wb_wr_en));
    bufp->fullCData(oldp+159,(vlSymsp->TOP__top__u_core.__PVT__wb_wr_addr),5);
    bufp->fullIData(oldp+160,(vlSymsp->TOP__top__u_core.__PVT__wb_wr_data),32);
    bufp->fullIData(oldp+161,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__alu_result_in),32);
    bufp->fullIData(oldp+162,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__mem_rdata_in),32);
    bufp->fullCData(oldp+163,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__opcode_in),7);
    bufp->fullCData(oldp+164,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__rd_addr_in),5);
    bufp->fullBit(oldp+165,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__wb_en));
    bufp->fullCData(oldp+166,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__wb_addr),5);
    bufp->fullIData(oldp+167,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__wb_data),32);
    bufp->fullBit(oldp+168,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__wr_en));
    bufp->fullCData(oldp+169,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__wr_addr),5);
    bufp->fullIData(oldp+170,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__wr_data),32);
    bufp->fullCData(oldp+171,(vlSymsp->TOP__top__u_core__u_forward.__PVT__wb_opcode),7);
    bufp->fullCData(oldp+172,(vlSymsp->TOP__top__u_core__u_forward.__PVT__wb_rd_addr),5);
    bufp->fullIData(oldp+173,(vlSymsp->TOP__top__u_core__u_forward.__PVT__wb_wr_data),32);
    bufp->fullBit(oldp+174,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__dn_ready));
    bufp->fullBit(oldp+175,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__up_ready));
    bufp->fullBit(oldp+176,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__dn_valid));
    bufp->fullWData(oldp+177,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__dn_data),140);
    bufp->fullWData(oldp+182,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__data_q),140);
    bufp->fullBit(oldp+187,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__valid_q));
    bufp->fullBit(oldp+188,(vlSymsp->TOP__top.__PVT__lsu_respReady));
    bufp->fullBit(oldp+189,(vlSymsp->TOP__top__u_core.__PVT__lsu_respReady));
    bufp->fullBit(oldp+190,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_respReady));
    bufp->fullCData(oldp+191,(vlSymsp->TOP__top__u_core__u_memory.__PVT__state),2);
    bufp->fullIData(oldp+192,(vlSymsp->TOP__top__u_core__u_memory.__PVT__rdata_latch),32);
    bufp->fullIData(oldp+193,(vlSymsp->TOP__top.__PVT__lsu_addr),32);
    bufp->fullBit(oldp+194,(vlSymsp->TOP__top.__PVT__lsu_ren));
    bufp->fullBit(oldp+195,(vlSymsp->TOP__top.__PVT__lsu_wen));
    bufp->fullIData(oldp+196,(vlSymsp->TOP__top.__PVT__lsu_wdata),32);
    bufp->fullCData(oldp+197,(vlSymsp->TOP__top.__PVT__lsu_wmask),4);
    bufp->fullIData(oldp+198,(vlSymsp->TOP__top__u_core.__PVT__lsu_addr),32);
    bufp->fullBit(oldp+199,(vlSymsp->TOP__top__u_core.__PVT__lsu_ren));
    bufp->fullBit(oldp+200,(vlSymsp->TOP__top__u_core.__PVT__lsu_wen));
    bufp->fullIData(oldp+201,(vlSymsp->TOP__top__u_core.__PVT__lsu_wdata),32);
    bufp->fullCData(oldp+202,(vlSymsp->TOP__top__u_core.__PVT__lsu_wmask),4);
    bufp->fullBit(oldp+203,(vlSymsp->TOP__top__u_core.__PVT__ex2mem_dn_valid));
    bufp->fullWData(oldp+204,(vlSymsp->TOP__top__u_core.__PVT__ex_mem_dn),143);
    bufp->fullBit(oldp+209,(vlSymsp->TOP__top__u_core__u_memory.__PVT__valid_in));
    bufp->fullIData(oldp+210,(vlSymsp->TOP__top__u_core__u_memory.__PVT__alu_result_in),32);
    bufp->fullIData(oldp+211,(vlSymsp->TOP__top__u_core__u_memory.__PVT__rs2_data_in),32);
    bufp->fullCData(oldp+212,(vlSymsp->TOP__top__u_core__u_memory.__PVT__opcode_in),7);
    bufp->fullCData(oldp+213,(vlSymsp->TOP__top__u_core__u_memory.__PVT__funct3_in),3);
    bufp->fullIData(oldp+214,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_addr),32);
    bufp->fullBit(oldp+215,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_ren));
    bufp->fullBit(oldp+216,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_wen));
    bufp->fullIData(oldp+217,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_wdata),32);
    bufp->fullCData(oldp+218,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_wmask),4);
    bufp->fullBit(oldp+219,(vlSymsp->TOP__top__u_core__u_memory.__PVT__is_load));
    bufp->fullBit(oldp+220,(vlSymsp->TOP__top__u_core__u_memory.__PVT__is_store));
    bufp->fullBit(oldp+221,(vlSymsp->TOP__top__u_core__u_memory.__PVT__is_mem));
    bufp->fullCData(oldp+222,(vlSymsp->TOP__top__u_core__u_memory.__PVT__wmask_gen),4);
    bufp->fullCData(oldp+223,(vlSymsp->TOP__top__u_core__u_forward.__PVT__mem_opcode),7);
    bufp->fullCData(oldp+224,(vlSymsp->TOP__top__u_core__u_forward.__PVT__mem_rd_addr),5);
    bufp->fullIData(oldp+225,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_mem_alu_result),32);
    bufp->fullBit(oldp+226,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__dn_valid));
    bufp->fullWData(oldp+227,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__dn_data),143);
    bufp->fullWData(oldp+232,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__data_q),143);
    bufp->fullBit(oldp+237,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__valid_q));
    bufp->fullWData(oldp+238,(vlSymsp->TOP__top__u_core.__PVT__mem_wb_up),140);
    bufp->fullBit(oldp+243,(vlSymsp->TOP__top__u_core.__PVT__id2ex_dn_valid));
    bufp->fullWData(oldp+244,(vlSymsp->TOP__top__u_core.__PVT__id_ex_dn),263);
    bufp->fullSData(oldp+253,(vlSymsp->TOP__top__u_core.__PVT__csr_raddr),12);
    bufp->fullBit(oldp+254,(vlSymsp->TOP__top__u_core.__PVT__csr_wen));
    bufp->fullSData(oldp+255,(vlSymsp->TOP__top__u_core.__PVT__csr_waddr),12);
    bufp->fullBit(oldp+256,(vlSymsp->TOP__top__u_core.__PVT__trap_valid));
    bufp->fullIData(oldp+257,(vlSymsp->TOP__top__u_core.__PVT__trap_pc),32);
    bufp->fullSData(oldp+258,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_raddr),12);
    bufp->fullBit(oldp+259,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_wen));
    bufp->fullSData(oldp+260,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_waddr),12);
    bufp->fullBit(oldp+261,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_valid));
    bufp->fullIData(oldp+262,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_pc),32);
    bufp->fullCData(oldp+263,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_stage_opcode),7);
    bufp->fullCData(oldp+264,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_stage_rd_addr),5);
    bufp->fullCData(oldp+265,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__ex_opcode),7);
    bufp->fullCData(oldp+266,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__ex_rd_addr),5);
    bufp->fullBit(oldp+267,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__ex_is_load));
    bufp->fullIData(oldp+268,(vlSymsp->TOP__top__u_core__u_execute.__PVT__pc_in),32);
    bufp->fullIData(oldp+269,(vlSymsp->TOP__top__u_core__u_execute.__PVT__op1_in),32);
    bufp->fullIData(oldp+270,(vlSymsp->TOP__top__u_core__u_execute.__PVT__op2_in),32);
    bufp->fullIData(oldp+271,(vlSymsp->TOP__top__u_core__u_execute.__PVT__rs1_data_in),32);
    bufp->fullIData(oldp+272,(vlSymsp->TOP__top__u_core__u_execute.__PVT__imm_in),32);
    bufp->fullCData(oldp+273,(vlSymsp->TOP__top__u_core__u_execute.__PVT__opcode_in),7);
    bufp->fullCData(oldp+274,(vlSymsp->TOP__top__u_core__u_execute.__PVT__funct3_in),3);
    bufp->fullCData(oldp+275,(vlSymsp->TOP__top__u_core__u_execute.__PVT__funct7_in),7);
    bufp->fullBit(oldp+276,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_ebreak_in));
    bufp->fullSData(oldp+277,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_addr_in),12);
    bufp->fullBit(oldp+278,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_csrrw));
    bufp->fullBit(oldp+279,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_csrrs));
    bufp->fullBit(oldp+280,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_ecall));
    bufp->fullBit(oldp+281,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_mret));
    bufp->fullSData(oldp+282,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_raddr),12);
    bufp->fullBit(oldp+283,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_wen));
    bufp->fullSData(oldp+284,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_waddr),12);
    bufp->fullBit(oldp+285,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_valid));
    bufp->fullIData(oldp+286,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_pc),32);
    bufp->fullIData(oldp+287,(vlSymsp->TOP__top__u_core__u_execute.__PVT__alu_res),32);
    bufp->fullBit(oldp+288,(vlSymsp->TOP__top__u_core__u_execute.__PVT__branch_taken));
    bufp->fullBit(oldp+289,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__dn_valid));
    bufp->fullWData(oldp+290,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__dn_data),263);
    bufp->fullWData(oldp+299,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__data_q),263);
    bufp->fullBit(oldp+308,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__valid_q));
    bufp->fullBit(oldp+309,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__up_valid));
    bufp->fullWData(oldp+310,(vlSymsp->TOP__top__u_core.__PVT__ex_mem_up),143);
    bufp->fullBit(oldp+315,(vlSymsp->TOP__top__u_core.__PVT__if2id_dn_valid));
    bufp->fullQData(oldp+316,(vlSymsp->TOP__top__u_core.__PVT__if_id_dn),64);
    bufp->fullCData(oldp+318,(vlSymsp->TOP__top__u_core.__PVT__decode_rs1_addr),5);
    bufp->fullCData(oldp+319,(vlSymsp->TOP__top__u_core.__PVT__decode_rs2_addr),5);
    bufp->fullCData(oldp+320,(vlSymsp->TOP__top__u_core.__PVT__decode_rd_addr),5);
    bufp->fullIData(oldp+321,(vlSymsp->TOP__top__u_core.__PVT__decode_imm),32);
    bufp->fullCData(oldp+322,(vlSymsp->TOP__top__u_core.__PVT__decode_op1_sel),2);
    bufp->fullCData(oldp+323,(vlSymsp->TOP__top__u_core.__PVT__decode_op2_sel),2);
    bufp->fullCData(oldp+324,(vlSymsp->TOP__top__u_core.__PVT__decode_opcode),7);
    bufp->fullCData(oldp+325,(vlSymsp->TOP__top__u_core.__PVT__decode_funct3),3);
    bufp->fullCData(oldp+326,(vlSymsp->TOP__top__u_core.__PVT__decode_funct7),7);
    bufp->fullSData(oldp+327,(vlSymsp->TOP__top__u_core.__PVT__decode_csr_addr),12);
    bufp->fullBit(oldp+328,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_csrrw));
    bufp->fullBit(oldp+329,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_csrrs));
    bufp->fullBit(oldp+330,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_ecall));
    bufp->fullBit(oldp+331,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_mret));
    bufp->fullBit(oldp+332,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_ebreak));
    bufp->fullCData(oldp+333,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs1_addr),5);
    bufp->fullCData(oldp+334,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs2_addr),5);
    bufp->fullCData(oldp+335,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_rs1_addr),5);
    bufp->fullCData(oldp+336,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_rs2_addr),5);
    bufp->fullIData(oldp+337,(vlSymsp->TOP__top__u_core__u_decode.__PVT__instr_addr_in),32);
    bufp->fullIData(oldp+338,(vlSymsp->TOP__top__u_core__u_decode.__PVT__instr_in),32);
    bufp->fullCData(oldp+339,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rd_rs1_addr),5);
    bufp->fullCData(oldp+340,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rd_rs2_addr),5);
    bufp->fullCData(oldp+341,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rd_addr_out),5);
    bufp->fullIData(oldp+342,(vlSymsp->TOP__top__u_core__u_decode.__PVT__imm_out),32);
    bufp->fullCData(oldp+343,(vlSymsp->TOP__top__u_core__u_decode.__PVT__op1_sel_out),2);
    bufp->fullCData(oldp+344,(vlSymsp->TOP__top__u_core__u_decode.__PVT__op2_sel_out),2);
    bufp->fullCData(oldp+345,(vlSymsp->TOP__top__u_core__u_decode.__PVT__opcode_out),7);
    bufp->fullCData(oldp+346,(vlSymsp->TOP__top__u_core__u_decode.__PVT__funct3_out),3);
    bufp->fullCData(oldp+347,(vlSymsp->TOP__top__u_core__u_decode.__PVT__funct7_out),7);
    bufp->fullBit(oldp+348,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_ebreak));
    bufp->fullSData(oldp+349,(vlSymsp->TOP__top__u_core__u_decode.__PVT__csr_addr_out),12);
    bufp->fullBit(oldp+350,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_csrrw));
    bufp->fullBit(oldp+351,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_csrrs));
    bufp->fullBit(oldp+352,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_ecall));
    bufp->fullBit(oldp+353,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_mret));
    bufp->fullCData(oldp+354,(vlSymsp->TOP__top__u_core__u_decode.__PVT__opcode),7);
    bufp->fullCData(oldp+355,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rd),5);
    bufp->fullCData(oldp+356,(vlSymsp->TOP__top__u_core__u_decode.__PVT__funct3),3);
    bufp->fullCData(oldp+357,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rs1),5);
    bufp->fullCData(oldp+358,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rs2),5);
    bufp->fullCData(oldp+359,(vlSymsp->TOP__top__u_core__u_decode.__PVT__funct7),7);
    bufp->fullIData(oldp+360,(vlSymsp->TOP__top__u_core__u_decode.__PVT__imm),32);
    bufp->fullBit(oldp+361,(vlSymsp->TOP__top__u_core__u_decode.__PVT__is_ebreak));
    bufp->fullBit(oldp+362,(vlSymsp->TOP__top__u_core__u_decode.__PVT__is_system));
    bufp->fullCData(oldp+363,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__id_rs1_addr),5);
    bufp->fullCData(oldp+364,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__id_rs2_addr),5);
    bufp->fullBit(oldp+365,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__dn_valid));
    bufp->fullQData(oldp+366,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__dn_data),64);
    bufp->fullQData(oldp+368,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__data_q),64);
    bufp->fullBit(oldp+370,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__valid_q));
    bufp->fullBit(oldp+371,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__up_valid));
    bufp->fullWData(oldp+372,(vlSymsp->TOP__top__u_core.__PVT__id_ex_up),263);
    bufp->fullBit(oldp+381,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_respValid));
    bufp->fullIData(oldp+382,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_rdata),32);
    bufp->fullIData(oldp+383,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__ifu_rdata),32);
    bufp->fullBit(oldp+384,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__ifu_respValid));
    bufp->fullBit(oldp+385,(vlSymsp->TOP__top.__PVT__lsu_reqValid));
    bufp->fullBit(oldp+386,(vlSymsp->TOP__top__u_core.__PVT__lsu_reqValid));
    bufp->fullIData(oldp+387,(vlSymsp->TOP__top__u_core.__PVT__mem_rdata),32);
    bufp->fullBit(oldp+388,(vlSymsp->TOP__top__u_core.__PVT__lsu_busy));
    bufp->fullBit(oldp+389,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_reqValid));
    bufp->fullBit(oldp+390,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_busy));
    bufp->fullIData(oldp+391,(vlSymsp->TOP__top__u_core__u_memory.__PVT__mem_rdata_out),32);
    bufp->fullIData(oldp+392,(vlSymsp->TOP__top__u_core__u_forward.__PVT__mem_rdata),32);
    bufp->fullBit(oldp+393,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__stall));
    bufp->fullBit(oldp+394,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__stall));
    bufp->fullBit(oldp+395,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__up_valid));
    bufp->fullWData(oldp+396,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__up_data),140);
    bufp->fullIData(oldp+401,(vlSymsp->TOP__top__u_core.__PVT__ex_alu_result),32);
    bufp->fullBit(oldp+402,(vlSymsp->TOP__top__u_core.__PVT__ex_jump_flag));
    bufp->fullIData(oldp+403,(vlSymsp->TOP__top__u_core.__PVT__ex_jump_target),32);
    bufp->fullIData(oldp+404,(vlSymsp->TOP__top__u_core.__PVT__csr_rdata),32);
    bufp->fullIData(oldp+405,(vlSymsp->TOP__top__u_core.__PVT__csr_wdata),32);
    bufp->fullIData(oldp+406,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_rdata),32);
    bufp->fullIData(oldp+407,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_wdata),32);
    bufp->fullIData(oldp+408,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_alu_result),32);
    bufp->fullBit(oldp+409,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__flush));
    bufp->fullIData(oldp+410,(vlSymsp->TOP__top__u_core__u_execute.__PVT__alu_result_out),32);
    bufp->fullBit(oldp+411,(vlSymsp->TOP__top__u_core__u_execute.__PVT__jump_flag_out));
    bufp->fullIData(oldp+412,(vlSymsp->TOP__top__u_core__u_execute.__PVT__jump_target_out),32);
    bufp->fullIData(oldp+413,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_rdata),32);
    bufp->fullIData(oldp+414,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_wdata),32);
    bufp->fullBit(oldp+415,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__jump_en));
    bufp->fullIData(oldp+416,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__jump_addr),32);
    bufp->fullBit(oldp+417,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__flush));
    bufp->fullWData(oldp+418,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__up_data),143);
    bufp->fullBit(oldp+423,(vlSymsp->TOP__top__u_core.__PVT__load_stall));
    bufp->fullBit(oldp+424,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__stall));
    bufp->fullBit(oldp+425,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__rs1_hazard));
    bufp->fullBit(oldp+426,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__rs2_hazard));
    bufp->fullIData(oldp+427,(vlSymsp->TOP__top__u_core.__PVT__reg_rs1_data),32);
    bufp->fullIData(oldp+428,(vlSymsp->TOP__top__u_core.__PVT__reg_rs2_data),32);
    bufp->fullIData(oldp+429,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs1_data),32);
    bufp->fullIData(oldp+430,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs2_data),32);
    bufp->fullIData(oldp+431,(vlSymsp->TOP__top__u_core__u_forward.__PVT__reg_rs1_data),32);
    bufp->fullIData(oldp+432,(vlSymsp->TOP__top__u_core__u_forward.__PVT__reg_rs2_data),32);
    bufp->fullBit(oldp+433,(vlSymsp->TOP__top__u_core.__PVT__ex2mem_up_ready));
    bufp->fullBit(oldp+434,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__dn_ready));
    bufp->fullBit(oldp+435,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__up_ready));
    bufp->fullIData(oldp+436,(vlSymsp->TOP__top.instr),32);
    bufp->fullBit(oldp+437,(vlSymsp->TOP__top.__PVT__ifu_respReady));
    bufp->fullIData(oldp+438,(vlSymsp->TOP__top__u_core.__PVT__instr),32);
    bufp->fullBit(oldp+439,(vlSymsp->TOP__top__u_core.__PVT__ifu_respReady));
    bufp->fullBit(oldp+440,(vlSymsp->TOP__top__u_core.__PVT__ifu_valid));
    bufp->fullBit(oldp+441,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__ifu_respReady));
    bufp->fullIData(oldp+442,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__instr_out),32);
    bufp->fullBit(oldp+443,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__ifu_valid));
    bufp->fullBit(oldp+444,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__up_valid));
    bufp->fullBit(oldp+445,(vlSymsp->TOP__top__u_core.__PVT__backend_stall));
    bufp->fullBit(oldp+446,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__stall));
    bufp->fullBit(oldp+447,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__stall));
    bufp->fullIData(oldp+448,(vlSymsp->TOP__top__u_core.__PVT__fwd_rs1_data),32);
    bufp->fullIData(oldp+449,(vlSymsp->TOP__top__u_core.__PVT__fwd_rs2_data),32);
    bufp->fullIData(oldp+450,(vlSymsp->TOP__top__u_core.__PVT__id_op1),32);
    bufp->fullIData(oldp+451,(vlSymsp->TOP__top__u_core.__PVT__id_op2),32);
    bufp->fullIData(oldp+452,(vlSymsp->TOP__top__u_core__u_forward.__PVT__fwd_rs1_data),32);
    bufp->fullIData(oldp+453,(vlSymsp->TOP__top__u_core__u_forward.__PVT__fwd_rs2_data),32);
    bufp->fullWData(oldp+454,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__up_data),263);
    bufp->fullBit(oldp+463,(vlSymsp->TOP__top__u_core.__PVT__id2ex_up_ready));
    bufp->fullBit(oldp+464,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__dn_ready));
    bufp->fullBit(oldp+465,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__up_ready));
    bufp->fullBit(oldp+466,(vlSymsp->TOP__top.__PVT__ifu_reqValid));
    bufp->fullBit(oldp+467,(vlSymsp->TOP__top__u_core.__PVT__ifu_reqValid));
    bufp->fullBit(oldp+468,(vlSymsp->TOP__top__u_core.__PVT__pc_hold_sig));
    bufp->fullBit(oldp+469,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__ifu_reqValid));
    bufp->fullBit(oldp+470,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__pc_hold));
    bufp->fullBit(oldp+471,(vlSelfRef.clk));
    bufp->fullBit(oldp+472,(vlSelfRef.rst_n));
    bufp->fullIData(oldp+473,(vlSelfRef.pc),32);
    bufp->fullIData(oldp+474,(vlSelfRef.instr),32);
    bufp->fullIData(oldp+475,(vlSelfRef.regs[0]),32);
    bufp->fullIData(oldp+476,(vlSelfRef.regs[1]),32);
    bufp->fullIData(oldp+477,(vlSelfRef.regs[2]),32);
    bufp->fullIData(oldp+478,(vlSelfRef.regs[3]),32);
    bufp->fullIData(oldp+479,(vlSelfRef.regs[4]),32);
    bufp->fullIData(oldp+480,(vlSelfRef.regs[5]),32);
    bufp->fullIData(oldp+481,(vlSelfRef.regs[6]),32);
    bufp->fullIData(oldp+482,(vlSelfRef.regs[7]),32);
    bufp->fullIData(oldp+483,(vlSelfRef.regs[8]),32);
    bufp->fullIData(oldp+484,(vlSelfRef.regs[9]),32);
    bufp->fullIData(oldp+485,(vlSelfRef.regs[10]),32);
    bufp->fullIData(oldp+486,(vlSelfRef.regs[11]),32);
    bufp->fullIData(oldp+487,(vlSelfRef.regs[12]),32);
    bufp->fullIData(oldp+488,(vlSelfRef.regs[13]),32);
    bufp->fullIData(oldp+489,(vlSelfRef.regs[14]),32);
    bufp->fullIData(oldp+490,(vlSelfRef.regs[15]),32);
    bufp->fullBit(oldp+491,(vlSelfRef.debug_wb_have));
    bufp->fullIData(oldp+492,(vlSelfRef.debug_wb_pc),32);
    bufp->fullIData(oldp+493,(vlSelfRef.debug_wb_instr),32);
    bufp->fullBit(oldp+494,(vlSelfRef.debug_wb_en));
    bufp->fullCData(oldp+495,(vlSelfRef.debug_wb_addr),5);
    bufp->fullIData(oldp+496,(vlSelfRef.debug_wb_data),32);
    bufp->fullBit(oldp+497,(vlSymsp->TOP__top__u_core.__PVT__if2id_up_ready));
    bufp->fullQData(oldp+498,(vlSymsp->TOP__top__u_core.__PVT__if_id_up),64);
    bufp->fullCData(oldp+500,(vlSymsp->TOP__top__u_core__u_memory.__PVT__state_next),2);
    bufp->fullCData(oldp+501,(vlSymsp->TOP__top__u_core__u_forward.__PVT__fwd_rs1_sel),2);
    bufp->fullCData(oldp+502,(vlSymsp->TOP__top__u_core__u_forward.__PVT__fwd_rs2_sel),2);
    bufp->fullCData(oldp+503,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__state),2);
    bufp->fullCData(oldp+504,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__state_next),2);
    bufp->fullIData(oldp+505,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__instr_latch),32);
    bufp->fullBit(oldp+506,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__up_ready));
    bufp->fullQData(oldp+507,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__up_data),64);
    bufp->fullBit(oldp+509,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__flush));
}
