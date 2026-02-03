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
    tracep->declBit(c+213,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+214,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+215,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+216,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+217,0,"debug_x10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+218+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_pc_counter__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_fetch__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_if2id__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_decode__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_reg_file__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_id2ex__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_execute__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_ex2mem__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_memory__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_mem2wb__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_writeback__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+234,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+157,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"debug_x10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+163+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+12,0,"instr_addr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"instr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+14,0,"decode_rs1_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+15,0,"decode_rs2_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+16,0,"decode_rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+17,0,"decode_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"decode_op1_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+19,0,"decode_op2_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+20,0,"decode_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+21,0,"decode_funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+22,0,"decode_funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+60,0,"reg_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"reg_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"id_instr_addr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"id_instr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+64,0,"id_op1_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+65,0,"id_op2_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,0,"id_rd_addr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+67,0,"id_imm_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"id_opcode_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+69,0,"id_funct3_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+70,0,"id_funct7_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+71,0,"id_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+72,0,"id_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+73,0,"ex_alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+74,0,"ex_jump_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"ex_jump_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"ex_alu_result_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"ex_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+78,0,"ex_rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+79,0,"ex_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+80,0,"ex_funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+81,0,"mem_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"mem_alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"mem_rdata_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"mem_rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+85,0,"mem_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+86,0,"wb_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+87,0,"wb_wr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+88,0,"wb_wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+23,0,"inst_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"inst_ebreak_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_pc_counter", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_pc_counter__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_fetch", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_fetch__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_if2id", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_if2id__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_decode", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_decode__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_reg_file", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_reg_file__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_id2ex", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_id2ex__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_execute", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_execute__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_ex2mem", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_ex2mem__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_memory", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_memory__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_mem2wb", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_mem2wb__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_writeback", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_writeback__0(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_if2id__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_if2id__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+234,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+158,0,"instr_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"instr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"instr_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"instr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_memory__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_memory__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+234,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+3,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+91,0,"rs2_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+92,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+93,0,"funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+94,0,"mem_rdata_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"rdata_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_writeback__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_writeback__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+234,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+97,0,"mem_rdata_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+98,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+99,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+100,0,"wb_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+101,0,"wb_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+102,0,"wb_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_reg_file__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_reg_file__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+234,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+5,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"rs1_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+28,0,"rs2_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+103,0,"rs1_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+105,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"wr_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+107,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+179,0,"debug_x10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+180+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+196+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+212,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_mem2wb__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_mem2wb__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+234,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+108,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+109,0,"mem_rdata_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+110,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+111,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+112,0,"alu_result_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"mem_rdata_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+115,0,"opcode_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_fetch__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_fetch__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+234,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+7,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+159,0,"pc_pointer",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"instr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_decode__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_decode__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+234,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"instr_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"instr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"rd_rs1_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+33,0,"rd_rs2_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+34,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+35,0,"imm_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"op1_sel_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+37,0,"op2_sel_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+38,0,"opcode_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+39,0,"funct3_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+40,0,"funct7_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+41,0,"inst_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+43,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+44,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+45,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+46,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+47,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+48,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+49,0,"is_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+235,0,"OP1_RS1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+236,0,"OP1_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+237,0,"OP1_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+235,0,"OP2_RS2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+236,0,"OP2_IMM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+237,0,"OP2_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_execute__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_execute__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+234,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"pc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"op1_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"op2_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"rs1_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+120,0,"imm_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+121,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+122,0,"funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+123,0,"funct7_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+124,0,"alu_result_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+125,0,"jump_flag_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+126,0,"jump_target_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+127,0,"inst_ebreak_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+128,0,"alu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+129,0,"branch_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_id2ex__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_id2ex__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+234,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+50,0,"instr_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"instr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+53,0,"imm_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"op1_sel_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+55,0,"op2_sel_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+56,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+57,0,"funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+58,0,"funct7_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+130,0,"rs1_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"rs2_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+132,0,"instr_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+133,0,"instr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"op1_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"op2_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+137,0,"imm_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"opcode_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+139,0,"funct3_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+140,0,"funct7_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+141,0,"rs1_data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+142,0,"rs2_data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+59,0,"inst_ebreak_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+143,0,"inst_ebreak_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+235,0,"OP1_RS1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+236,0,"OP1_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+237,0,"OP1_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+235,0,"OP2_RS2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+236,0,"OP2_IMM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+237,0,"OP2_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_ex2mem__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_ex2mem__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+234,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+234,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+144,0,"pc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+146,0,"rs2_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+147,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+148,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+149,0,"funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+150,0,"alu_result_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+151,0,"rs2_data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+153,0,"opcode_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+154,0,"funct3_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_pc_counter__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_pc_counter__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+234,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+238,0,"RESET_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+9,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"jump_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+156,0,"jump_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"pc_pointer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
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
    bufp->fullIData(oldp+234,(0x20U),32);
    bufp->fullCData(oldp+235,(0U),2);
    bufp->fullCData(oldp+236,(1U),2);
    bufp->fullCData(oldp+237,(2U),2);
    bufp->fullIData(oldp+238,(0x80000000U),32);
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
    bufp->fullBit(oldp+1,(vlSymsp->TOP__top.clk));
    bufp->fullBit(oldp+2,(vlSymsp->TOP__top.rst_n));
    bufp->fullBit(oldp+3,(vlSymsp->TOP__top__u_memory.__PVT__clk));
    bufp->fullBit(oldp+4,(vlSymsp->TOP__top__u_memory.__PVT__rst_n));
    bufp->fullBit(oldp+5,(vlSymsp->TOP__top__u_reg_file.__PVT__clk));
    bufp->fullBit(oldp+6,(vlSymsp->TOP__top__u_reg_file.__PVT__rst_n));
    bufp->fullBit(oldp+7,(vlSymsp->TOP__top__u_fetch.__PVT__clk));
    bufp->fullBit(oldp+8,(vlSymsp->TOP__top__u_fetch.__PVT__rst_n));
    bufp->fullBit(oldp+9,(vlSymsp->TOP__top__u_pc_counter.__PVT__clk));
    bufp->fullBit(oldp+10,(vlSymsp->TOP__top__u_pc_counter.__PVT__rst_n));
    bufp->fullIData(oldp+11,(vlSymsp->TOP__top.instr),32);
    bufp->fullIData(oldp+12,(vlSymsp->TOP__top.__PVT__instr_addr_out),32);
    bufp->fullIData(oldp+13,(vlSymsp->TOP__top.__PVT__instr_out),32);
    bufp->fullCData(oldp+14,(vlSymsp->TOP__top.__PVT__decode_rs1_addr),5);
    bufp->fullCData(oldp+15,(vlSymsp->TOP__top.__PVT__decode_rs2_addr),5);
    bufp->fullCData(oldp+16,(vlSymsp->TOP__top.__PVT__decode_rd_addr),5);
    bufp->fullIData(oldp+17,(vlSymsp->TOP__top.__PVT__decode_imm),32);
    bufp->fullCData(oldp+18,(vlSymsp->TOP__top.__PVT__decode_op1_sel),2);
    bufp->fullCData(oldp+19,(vlSymsp->TOP__top.__PVT__decode_op2_sel),2);
    bufp->fullCData(oldp+20,(vlSymsp->TOP__top.__PVT__decode_opcode),7);
    bufp->fullCData(oldp+21,(vlSymsp->TOP__top.__PVT__decode_funct3),3);
    bufp->fullCData(oldp+22,(vlSymsp->TOP__top.__PVT__decode_funct7),7);
    bufp->fullBit(oldp+23,(vlSymsp->TOP__top.__PVT__inst_ebreak));
    bufp->fullIData(oldp+24,(vlSymsp->TOP__top__u_if2id.__PVT__instr_in),32);
    bufp->fullIData(oldp+25,(vlSymsp->TOP__top__u_if2id.__PVT__instr_addr_out),32);
    bufp->fullIData(oldp+26,(vlSymsp->TOP__top__u_if2id.__PVT__instr_out),32);
    bufp->fullCData(oldp+27,(vlSymsp->TOP__top__u_reg_file.__PVT__rs1_addr),5);
    bufp->fullCData(oldp+28,(vlSymsp->TOP__top__u_reg_file.__PVT__rs2_addr),5);
    bufp->fullIData(oldp+29,(vlSymsp->TOP__top__u_fetch.__PVT__instr_out),32);
    bufp->fullIData(oldp+30,(vlSymsp->TOP__top__u_decode.__PVT__instr_addr_in),32);
    bufp->fullIData(oldp+31,(vlSymsp->TOP__top__u_decode.__PVT__instr_in),32);
    bufp->fullCData(oldp+32,(vlSymsp->TOP__top__u_decode.__PVT__rd_rs1_addr),5);
    bufp->fullCData(oldp+33,(vlSymsp->TOP__top__u_decode.__PVT__rd_rs2_addr),5);
    bufp->fullCData(oldp+34,(vlSymsp->TOP__top__u_decode.__PVT__rd_addr_out),5);
    bufp->fullIData(oldp+35,(vlSymsp->TOP__top__u_decode.__PVT__imm_out),32);
    bufp->fullCData(oldp+36,(vlSymsp->TOP__top__u_decode.__PVT__op1_sel_out),2);
    bufp->fullCData(oldp+37,(vlSymsp->TOP__top__u_decode.__PVT__op2_sel_out),2);
    bufp->fullCData(oldp+38,(vlSymsp->TOP__top__u_decode.__PVT__opcode_out),7);
    bufp->fullCData(oldp+39,(vlSymsp->TOP__top__u_decode.__PVT__funct3_out),3);
    bufp->fullCData(oldp+40,(vlSymsp->TOP__top__u_decode.__PVT__funct7_out),7);
    bufp->fullBit(oldp+41,(vlSymsp->TOP__top__u_decode.__PVT__inst_ebreak));
    bufp->fullCData(oldp+42,(vlSymsp->TOP__top__u_decode.__PVT__opcode),7);
    bufp->fullCData(oldp+43,(vlSymsp->TOP__top__u_decode.__PVT__rd),5);
    bufp->fullCData(oldp+44,(vlSymsp->TOP__top__u_decode.__PVT__funct3),3);
    bufp->fullCData(oldp+45,(vlSymsp->TOP__top__u_decode.__PVT__rs1),5);
    bufp->fullCData(oldp+46,(vlSymsp->TOP__top__u_decode.__PVT__rs2),5);
    bufp->fullCData(oldp+47,(vlSymsp->TOP__top__u_decode.__PVT__funct7),7);
    bufp->fullIData(oldp+48,(vlSymsp->TOP__top__u_decode.__PVT__imm),32);
    bufp->fullBit(oldp+49,(vlSymsp->TOP__top__u_decode.__PVT__is_ebreak));
    bufp->fullIData(oldp+50,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_addr_in),32);
    bufp->fullIData(oldp+51,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_in),32);
    bufp->fullCData(oldp+52,(vlSymsp->TOP__top__u_id2ex.__PVT__rd_addr_in),5);
    bufp->fullIData(oldp+53,(vlSymsp->TOP__top__u_id2ex.__PVT__imm_in),32);
    bufp->fullCData(oldp+54,(vlSymsp->TOP__top__u_id2ex.__PVT__op1_sel_in),2);
    bufp->fullCData(oldp+55,(vlSymsp->TOP__top__u_id2ex.__PVT__op2_sel_in),2);
    bufp->fullCData(oldp+56,(vlSymsp->TOP__top__u_id2ex.__PVT__opcode_in),7);
    bufp->fullCData(oldp+57,(vlSymsp->TOP__top__u_id2ex.__PVT__funct3_in),3);
    bufp->fullCData(oldp+58,(vlSymsp->TOP__top__u_id2ex.__PVT__funct7_in),7);
    bufp->fullBit(oldp+59,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_ebreak_in));
    bufp->fullIData(oldp+60,(vlSymsp->TOP__top.__PVT__reg_rs1_data),32);
    bufp->fullIData(oldp+61,(vlSymsp->TOP__top.__PVT__reg_rs2_data),32);
    bufp->fullIData(oldp+62,(vlSymsp->TOP__top.__PVT__id_instr_addr_out),32);
    bufp->fullIData(oldp+63,(vlSymsp->TOP__top.__PVT__id_instr_out),32);
    bufp->fullIData(oldp+64,(vlSymsp->TOP__top.__PVT__id_op1_out),32);
    bufp->fullIData(oldp+65,(vlSymsp->TOP__top.__PVT__id_op2_out),32);
    bufp->fullCData(oldp+66,(vlSymsp->TOP__top.__PVT__id_rd_addr_out),5);
    bufp->fullIData(oldp+67,(vlSymsp->TOP__top.__PVT__id_imm_out),32);
    bufp->fullCData(oldp+68,(vlSymsp->TOP__top.__PVT__id_opcode_out),7);
    bufp->fullCData(oldp+69,(vlSymsp->TOP__top.__PVT__id_funct3_out),3);
    bufp->fullCData(oldp+70,(vlSymsp->TOP__top.__PVT__id_funct7_out),7);
    bufp->fullIData(oldp+71,(vlSymsp->TOP__top.__PVT__id_rs1_data),32);
    bufp->fullIData(oldp+72,(vlSymsp->TOP__top.__PVT__id_rs2_data),32);
    bufp->fullIData(oldp+73,(vlSymsp->TOP__top.__PVT__ex_alu_result),32);
    bufp->fullBit(oldp+74,(vlSymsp->TOP__top.__PVT__ex_jump_flag));
    bufp->fullIData(oldp+75,(vlSymsp->TOP__top.__PVT__ex_jump_target),32);
    bufp->fullIData(oldp+76,(vlSymsp->TOP__top.__PVT__ex_alu_result_out),32);
    bufp->fullIData(oldp+77,(vlSymsp->TOP__top.__PVT__ex_rs2_data),32);
    bufp->fullCData(oldp+78,(vlSymsp->TOP__top.__PVT__ex_rd_addr),5);
    bufp->fullCData(oldp+79,(vlSymsp->TOP__top.__PVT__ex_opcode),7);
    bufp->fullCData(oldp+80,(vlSymsp->TOP__top.__PVT__ex_funct3),3);
    bufp->fullIData(oldp+81,(vlSymsp->TOP__top.__PVT__mem_rdata),32);
    bufp->fullIData(oldp+82,(vlSymsp->TOP__top.__PVT__mem_alu_result),32);
    bufp->fullIData(oldp+83,(vlSymsp->TOP__top.__PVT__mem_rdata_out),32);
    bufp->fullCData(oldp+84,(vlSymsp->TOP__top.__PVT__mem_rd_addr),5);
    bufp->fullCData(oldp+85,(vlSymsp->TOP__top.__PVT__mem_opcode),7);
    bufp->fullBit(oldp+86,(vlSymsp->TOP__top.__PVT__wb_wr_en));
    bufp->fullCData(oldp+87,(vlSymsp->TOP__top.__PVT__wb_wr_addr),5);
    bufp->fullIData(oldp+88,(vlSymsp->TOP__top.__PVT__wb_wr_data),32);
    bufp->fullBit(oldp+89,(vlSymsp->TOP__top.__PVT__inst_ebreak_out));
    bufp->fullIData(oldp+90,(vlSymsp->TOP__top__u_memory.__PVT__alu_result_in),32);
    bufp->fullIData(oldp+91,(vlSymsp->TOP__top__u_memory.__PVT__rs2_data_in),32);
    bufp->fullCData(oldp+92,(vlSymsp->TOP__top__u_memory.__PVT__opcode_in),7);
    bufp->fullCData(oldp+93,(vlSymsp->TOP__top__u_memory.__PVT__funct3_in),3);
    bufp->fullIData(oldp+94,(vlSymsp->TOP__top__u_memory.__PVT__mem_rdata_out),32);
    bufp->fullIData(oldp+95,(vlSymsp->TOP__top__u_memory.__PVT__rdata_raw),32);
    bufp->fullIData(oldp+96,(vlSymsp->TOP__top__u_writeback.__PVT__alu_result_in),32);
    bufp->fullIData(oldp+97,(vlSymsp->TOP__top__u_writeback.__PVT__mem_rdata_in),32);
    bufp->fullCData(oldp+98,(vlSymsp->TOP__top__u_writeback.__PVT__opcode_in),7);
    bufp->fullCData(oldp+99,(vlSymsp->TOP__top__u_writeback.__PVT__rd_addr_in),5);
    bufp->fullBit(oldp+100,(vlSymsp->TOP__top__u_writeback.__PVT__wb_en));
    bufp->fullCData(oldp+101,(vlSymsp->TOP__top__u_writeback.__PVT__wb_addr),5);
    bufp->fullIData(oldp+102,(vlSymsp->TOP__top__u_writeback.__PVT__wb_data),32);
    bufp->fullIData(oldp+103,(vlSymsp->TOP__top__u_reg_file.__PVT__rs1_data),32);
    bufp->fullIData(oldp+104,(vlSymsp->TOP__top__u_reg_file.__PVT__rs2_data),32);
    bufp->fullBit(oldp+105,(vlSymsp->TOP__top__u_reg_file.__PVT__wr_en));
    bufp->fullCData(oldp+106,(vlSymsp->TOP__top__u_reg_file.__PVT__wr_addr),5);
    bufp->fullIData(oldp+107,(vlSymsp->TOP__top__u_reg_file.__PVT__wr_data),32);
    bufp->fullIData(oldp+108,(vlSymsp->TOP__top__u_mem2wb.__PVT__alu_result_in),32);
    bufp->fullIData(oldp+109,(vlSymsp->TOP__top__u_mem2wb.__PVT__mem_rdata_in),32);
    bufp->fullCData(oldp+110,(vlSymsp->TOP__top__u_mem2wb.__PVT__rd_addr_in),5);
    bufp->fullCData(oldp+111,(vlSymsp->TOP__top__u_mem2wb.__PVT__opcode_in),7);
    bufp->fullIData(oldp+112,(vlSymsp->TOP__top__u_mem2wb.__PVT__alu_result_out),32);
    bufp->fullIData(oldp+113,(vlSymsp->TOP__top__u_mem2wb.__PVT__mem_rdata_out),32);
    bufp->fullCData(oldp+114,(vlSymsp->TOP__top__u_mem2wb.__PVT__rd_addr_out),5);
    bufp->fullCData(oldp+115,(vlSymsp->TOP__top__u_mem2wb.__PVT__opcode_out),7);
    bufp->fullIData(oldp+116,(vlSymsp->TOP__top__u_execute.__PVT__pc_in),32);
    bufp->fullIData(oldp+117,(vlSymsp->TOP__top__u_execute.__PVT__op1_in),32);
    bufp->fullIData(oldp+118,(vlSymsp->TOP__top__u_execute.__PVT__op2_in),32);
    bufp->fullIData(oldp+119,(vlSymsp->TOP__top__u_execute.__PVT__rs1_data_in),32);
    bufp->fullIData(oldp+120,(vlSymsp->TOP__top__u_execute.__PVT__imm_in),32);
    bufp->fullCData(oldp+121,(vlSymsp->TOP__top__u_execute.__PVT__opcode_in),7);
    bufp->fullCData(oldp+122,(vlSymsp->TOP__top__u_execute.__PVT__funct3_in),3);
    bufp->fullCData(oldp+123,(vlSymsp->TOP__top__u_execute.__PVT__funct7_in),7);
    bufp->fullIData(oldp+124,(vlSymsp->TOP__top__u_execute.__PVT__alu_result_out),32);
    bufp->fullBit(oldp+125,(vlSymsp->TOP__top__u_execute.__PVT__jump_flag_out));
    bufp->fullIData(oldp+126,(vlSymsp->TOP__top__u_execute.__PVT__jump_target_out),32);
    bufp->fullBit(oldp+127,(vlSymsp->TOP__top__u_execute.__PVT__inst_ebreak_in));
    bufp->fullIData(oldp+128,(vlSymsp->TOP__top__u_execute.__PVT__alu_res),32);
    bufp->fullBit(oldp+129,(vlSymsp->TOP__top__u_execute.__PVT__branch_taken));
    bufp->fullIData(oldp+130,(vlSymsp->TOP__top__u_id2ex.__PVT__rs1_data_in),32);
    bufp->fullIData(oldp+131,(vlSymsp->TOP__top__u_id2ex.__PVT__rs2_data_in),32);
    bufp->fullIData(oldp+132,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_addr_out),32);
    bufp->fullIData(oldp+133,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_out),32);
    bufp->fullIData(oldp+134,(vlSymsp->TOP__top__u_id2ex.__PVT__op1_out),32);
    bufp->fullIData(oldp+135,(vlSymsp->TOP__top__u_id2ex.__PVT__op2_out),32);
    bufp->fullCData(oldp+136,(vlSymsp->TOP__top__u_id2ex.__PVT__rd_addr_out),5);
    bufp->fullIData(oldp+137,(vlSymsp->TOP__top__u_id2ex.__PVT__imm_out),32);
    bufp->fullCData(oldp+138,(vlSymsp->TOP__top__u_id2ex.__PVT__opcode_out),7);
    bufp->fullCData(oldp+139,(vlSymsp->TOP__top__u_id2ex.__PVT__funct3_out),3);
    bufp->fullCData(oldp+140,(vlSymsp->TOP__top__u_id2ex.__PVT__funct7_out),7);
    bufp->fullIData(oldp+141,(vlSymsp->TOP__top__u_id2ex.__PVT__rs1_data_out),32);
    bufp->fullIData(oldp+142,(vlSymsp->TOP__top__u_id2ex.__PVT__rs2_data_out),32);
    bufp->fullBit(oldp+143,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_ebreak_out));
    bufp->fullIData(oldp+144,(vlSymsp->TOP__top__u_ex2mem.__PVT__pc_in),32);
    bufp->fullIData(oldp+145,(vlSymsp->TOP__top__u_ex2mem.__PVT__alu_result_in),32);
    bufp->fullIData(oldp+146,(vlSymsp->TOP__top__u_ex2mem.__PVT__rs2_data_in),32);
    bufp->fullCData(oldp+147,(vlSymsp->TOP__top__u_ex2mem.__PVT__rd_addr_in),5);
    bufp->fullCData(oldp+148,(vlSymsp->TOP__top__u_ex2mem.__PVT__opcode_in),7);
    bufp->fullCData(oldp+149,(vlSymsp->TOP__top__u_ex2mem.__PVT__funct3_in),3);
    bufp->fullIData(oldp+150,(vlSymsp->TOP__top__u_ex2mem.__PVT__alu_result_out),32);
    bufp->fullIData(oldp+151,(vlSymsp->TOP__top__u_ex2mem.__PVT__rs2_data_out),32);
    bufp->fullCData(oldp+152,(vlSymsp->TOP__top__u_ex2mem.__PVT__rd_addr_out),5);
    bufp->fullCData(oldp+153,(vlSymsp->TOP__top__u_ex2mem.__PVT__opcode_out),7);
    bufp->fullCData(oldp+154,(vlSymsp->TOP__top__u_ex2mem.__PVT__funct3_out),3);
    bufp->fullBit(oldp+155,(vlSymsp->TOP__top__u_pc_counter.__PVT__jump_en));
    bufp->fullIData(oldp+156,(vlSymsp->TOP__top__u_pc_counter.__PVT__jump_addr),32);
    bufp->fullIData(oldp+157,(vlSymsp->TOP__top.pc),32);
    bufp->fullIData(oldp+158,(vlSymsp->TOP__top__u_if2id.__PVT__instr_addr_in),32);
    bufp->fullIData(oldp+159,(vlSymsp->TOP__top__u_fetch.__PVT__pc_pointer),32);
    bufp->fullIData(oldp+160,(vlSymsp->TOP__top__u_pc_counter.__PVT__pc),32);
    bufp->fullIData(oldp+161,(vlSymsp->TOP__top__u_pc_counter.__PVT__pc_pointer),32);
    bufp->fullIData(oldp+162,(vlSymsp->TOP__top.debug_x10),32);
    bufp->fullIData(oldp+163,(vlSymsp->TOP__top.regs[0]),32);
    bufp->fullIData(oldp+164,(vlSymsp->TOP__top.regs[1]),32);
    bufp->fullIData(oldp+165,(vlSymsp->TOP__top.regs[2]),32);
    bufp->fullIData(oldp+166,(vlSymsp->TOP__top.regs[3]),32);
    bufp->fullIData(oldp+167,(vlSymsp->TOP__top.regs[4]),32);
    bufp->fullIData(oldp+168,(vlSymsp->TOP__top.regs[5]),32);
    bufp->fullIData(oldp+169,(vlSymsp->TOP__top.regs[6]),32);
    bufp->fullIData(oldp+170,(vlSymsp->TOP__top.regs[7]),32);
    bufp->fullIData(oldp+171,(vlSymsp->TOP__top.regs[8]),32);
    bufp->fullIData(oldp+172,(vlSymsp->TOP__top.regs[9]),32);
    bufp->fullIData(oldp+173,(vlSymsp->TOP__top.regs[10]),32);
    bufp->fullIData(oldp+174,(vlSymsp->TOP__top.regs[11]),32);
    bufp->fullIData(oldp+175,(vlSymsp->TOP__top.regs[12]),32);
    bufp->fullIData(oldp+176,(vlSymsp->TOP__top.regs[13]),32);
    bufp->fullIData(oldp+177,(vlSymsp->TOP__top.regs[14]),32);
    bufp->fullIData(oldp+178,(vlSymsp->TOP__top.regs[15]),32);
    bufp->fullIData(oldp+179,(vlSymsp->TOP__top__u_reg_file.__PVT__debug_x10),32);
    bufp->fullIData(oldp+180,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[0]),32);
    bufp->fullIData(oldp+181,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[1]),32);
    bufp->fullIData(oldp+182,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[2]),32);
    bufp->fullIData(oldp+183,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[3]),32);
    bufp->fullIData(oldp+184,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[4]),32);
    bufp->fullIData(oldp+185,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[5]),32);
    bufp->fullIData(oldp+186,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[6]),32);
    bufp->fullIData(oldp+187,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[7]),32);
    bufp->fullIData(oldp+188,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[8]),32);
    bufp->fullIData(oldp+189,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[9]),32);
    bufp->fullIData(oldp+190,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[10]),32);
    bufp->fullIData(oldp+191,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[11]),32);
    bufp->fullIData(oldp+192,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[12]),32);
    bufp->fullIData(oldp+193,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[13]),32);
    bufp->fullIData(oldp+194,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[14]),32);
    bufp->fullIData(oldp+195,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[15]),32);
    bufp->fullIData(oldp+196,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[0]),32);
    bufp->fullIData(oldp+197,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[1]),32);
    bufp->fullIData(oldp+198,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[2]),32);
    bufp->fullIData(oldp+199,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[3]),32);
    bufp->fullIData(oldp+200,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[4]),32);
    bufp->fullIData(oldp+201,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[5]),32);
    bufp->fullIData(oldp+202,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[6]),32);
    bufp->fullIData(oldp+203,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[7]),32);
    bufp->fullIData(oldp+204,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[8]),32);
    bufp->fullIData(oldp+205,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[9]),32);
    bufp->fullIData(oldp+206,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[10]),32);
    bufp->fullIData(oldp+207,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[11]),32);
    bufp->fullIData(oldp+208,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[12]),32);
    bufp->fullIData(oldp+209,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[13]),32);
    bufp->fullIData(oldp+210,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[14]),32);
    bufp->fullIData(oldp+211,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[15]),32);
    bufp->fullIData(oldp+212,(vlSymsp->TOP__top__u_reg_file.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+213,(vlSelfRef.clk));
    bufp->fullBit(oldp+214,(vlSelfRef.rst_n));
    bufp->fullIData(oldp+215,(vlSelfRef.pc),32);
    bufp->fullIData(oldp+216,(vlSelfRef.instr),32);
    bufp->fullIData(oldp+217,(vlSelfRef.debug_x10),32);
    bufp->fullIData(oldp+218,(vlSelfRef.regs[0]),32);
    bufp->fullIData(oldp+219,(vlSelfRef.regs[1]),32);
    bufp->fullIData(oldp+220,(vlSelfRef.regs[2]),32);
    bufp->fullIData(oldp+221,(vlSelfRef.regs[3]),32);
    bufp->fullIData(oldp+222,(vlSelfRef.regs[4]),32);
    bufp->fullIData(oldp+223,(vlSelfRef.regs[5]),32);
    bufp->fullIData(oldp+224,(vlSelfRef.regs[6]),32);
    bufp->fullIData(oldp+225,(vlSelfRef.regs[7]),32);
    bufp->fullIData(oldp+226,(vlSelfRef.regs[8]),32);
    bufp->fullIData(oldp+227,(vlSelfRef.regs[9]),32);
    bufp->fullIData(oldp+228,(vlSelfRef.regs[10]),32);
    bufp->fullIData(oldp+229,(vlSelfRef.regs[11]),32);
    bufp->fullIData(oldp+230,(vlSelfRef.regs[12]),32);
    bufp->fullIData(oldp+231,(vlSelfRef.regs[13]),32);
    bufp->fullIData(oldp+232,(vlSelfRef.regs[14]),32);
    bufp->fullIData(oldp+233,(vlSelfRef.regs[15]),32);
}
