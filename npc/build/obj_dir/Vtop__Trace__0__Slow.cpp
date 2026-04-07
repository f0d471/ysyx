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
    tracep->declBit(c+429,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+430,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+431,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+432,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+433+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+449,0,"debug_wb_have",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+450,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+451,0,"debug_wb_instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+452,0,"debug_wb_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+453,0,"debug_wb_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+454,0,"debug_wb_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
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
    tracep->declBit(c+8,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+426,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+49+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+120,0,"debug_wb_have",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+121,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"debug_wb_instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+123,0,"debug_wb_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+124,0,"debug_wb_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+125,0,"debug_wb_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+455,0,"ifu_raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"ifu_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"lsu_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+170,0,"lsu_ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+171,0,"lsu_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+172,0,"lsu_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+173,0,"lsu_wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+115,0,"lsu_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_core", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_core__0(vlSelf, tracep);
    tracep->popPrefix();
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
    tracep->declBus(c+469,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+469,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+10,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+427,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+65+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+32,0,"ifu_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"ifu_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+174,0,"lsu_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+175,0,"lsu_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+176,0,"lsu_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+177,0,"lsu_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+178,0,"lsu_wmask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+117,0,"lsu_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+126,0,"debug_wb_have",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+127,0,"debug_wb_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"debug_wb_instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+129,0,"debug_wb_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+130,0,"debug_wb_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+131,0,"debug_wb_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+456,0,"if2id_up_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+289,0,"if2id_dn_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+423,0,"id2ex_up_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+217,0,"id2ex_dn_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+401,0,"ex2mem_up_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+179,0,"ex2mem_dn_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+132,0,"mem2wb_up_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"mem2wb_dn_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+457,0,"if_id_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+290,0,"if_id_dn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declArray(c+346,0,"id_ex_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 262,0);
    tracep->declArray(c+218,0,"id_ex_dn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 262,0);
    tracep->declArray(c+284,0,"ex_mem_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 142,0);
    tracep->declArray(c+180,0,"ex_mem_dn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 142,0);
    tracep->declArray(c+212,0,"mem_wb_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 139,0);
    tracep->declArray(c+134,0,"mem_wb_dn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 139,0);
    tracep->declBus(c+292,0,"decode_rs1_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+293,0,"decode_rs2_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+294,0,"decode_rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+295,0,"decode_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+296,0,"decode_op1_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+297,0,"decode_op2_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+298,0,"decode_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+299,0,"decode_funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+300,0,"decode_funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+301,0,"decode_csr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+302,0,"decode_inst_csrrw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+303,0,"decode_inst_csrrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+304,0,"decode_inst_ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+305,0,"decode_inst_mret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+306,0,"decode_inst_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+395,0,"reg_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+396,0,"reg_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+408,0,"fwd_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+409,0,"fwd_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+410,0,"id_op1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+411,0,"id_op2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+369,0,"ex_alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+370,0,"ex_jump_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+371,0,"ex_jump_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+361,0,"mem_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+139,0,"wb_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+140,0,"wb_wr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+141,0,"wb_wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+391,0,"load_stall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+470,0,"fwd_rs1_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+471,0,"fwd_rs2_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+404,0,"ifu_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+355,0,"lsu_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+227,0,"csr_raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+372,0,"csr_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+228,0,"csr_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+229,0,"csr_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+373,0,"csr_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+230,0,"trap_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+231,0,"trap_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"trap_cause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"trap_mtvec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"trap_mepc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
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
    tracep->declBus(c+469,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+469,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+12,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+185,0,"valid_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+186,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+187,0,"rs2_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+188,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+189,0,"funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+190,0,"lsu_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+191,0,"lsu_ren",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"lsu_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+193,0,"lsu_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+194,0,"lsu_wmask",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+118,0,"lsu_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+356,0,"lsu_busy",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+362,0,"mem_rdata_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+195,0,"is_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+196,0,"is_store",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+472,0,"S_IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+473,0,"S_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+459,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+357,0,"state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_writeback__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_writeback__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+469,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+142,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+143,0,"mem_rdata_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+144,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+145,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+146,0,"wb_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+147,0,"wb_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+148,0,"wb_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_csr_file__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_csr_file__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+474,0,"STU_ID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+232,0,"csr_raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+374,0,"csr_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+233,0,"csr_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+234,0,"csr_waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+375,0,"csr_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+235,0,"trap_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+236,0,"trap_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"trap_cause",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"trap_mtvec",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"trap_mepc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"mstatus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"mtvec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+43,0,"mepc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"mcause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+45,0,"mcycle_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_reg_file__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_reg_file__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+469,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+16,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+307,0,"rs1_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+308,0,"rs2_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+397,0,"rs1_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+398,0,"rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+149,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+150,0,"wr_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+151,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+81+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+97+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+113,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
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
    tracep->declBus(c+309,0,"ex_rs1_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+310,0,"ex_rs2_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+237,0,"ex_stage_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+238,0,"ex_stage_rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+376,0,"ex_alu_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+197,0,"mem_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+198,0,"mem_rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+199,0,"ex_mem_alu_result",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+363,0,"mem_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"wb_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+153,0,"wb_rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+154,0,"wb_wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+399,0,"reg_rs1_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+400,0,"reg_rs2_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+412,0,"fwd_rs1_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+413,0,"fwd_rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+460,0,"fwd_rs1_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+461,0,"fwd_rs2_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_fetch__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_fetch__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+469,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+469,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+18,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"pc_pointer",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"ifu_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"ifu_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+377,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+428,0,"instr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+405,0,"ifu_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+472,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+473,0,"WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+462,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+406,0,"state_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_decode__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_decode__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+469,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+469,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+311,0,"instr_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+312,0,"instr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+313,0,"rd_rs1_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+314,0,"rd_rs2_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+315,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+316,0,"imm_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+317,0,"op1_sel_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+318,0,"op2_sel_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+319,0,"opcode_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+320,0,"funct3_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+321,0,"funct7_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+322,0,"inst_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+323,0,"csr_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+324,0,"inst_csrrw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+325,0,"inst_csrrs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+326,0,"inst_ecall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+327,0,"inst_mret",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+328,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+329,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+330,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+331,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+332,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+333,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+334,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+335,0,"is_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+336,0,"is_system",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+475,0,"OP1_RS1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+476,0,"OP1_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+477,0,"OP1_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+475,0,"OP2_RS2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+476,0,"OP2_IMM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+477,0,"OP2_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_hazard__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_hazard__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+239,0,"ex_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+240,0,"ex_rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+337,0,"id_rs1_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+338,0,"id_rs2_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+392,0,"stall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+241,0,"ex_is_load",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+393,0,"rs1_hazard",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+394,0,"rs2_hazard",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_execute__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_execute__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+469,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+469,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+242,0,"pc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+243,0,"op1_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+244,0,"op2_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+245,0,"rs1_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+246,0,"imm_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+247,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+248,0,"funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+249,0,"funct7_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+378,0,"alu_result_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+379,0,"jump_flag_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+380,0,"jump_target_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+250,0,"inst_ebreak_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+251,0,"csr_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+252,0,"inst_csrrw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+253,0,"inst_csrrs",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+254,0,"inst_ecall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+255,0,"inst_mret",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+256,0,"csr_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+381,0,"csr_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+257,0,"csr_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+258,0,"csr_waddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+382,0,"csr_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+259,0,"trap_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+260,0,"trap_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"trap_cause",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"trap_mtvec",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"trap_mepc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+261,0,"alu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+262,0,"branch_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_pc_counter__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_pc_counter__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+469,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+478,0,"RESET_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+20,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+383,0,"jump_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+384,0,"jump_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+463,0,"pc_hold",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+35,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"pc_pointer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_if2id__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_if2id__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+479,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+22,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+385,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+464,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"up_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+465,0,"up_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+466,0,"up_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+339,0,"dn_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+424,0,"dn_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+340,0,"dn_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+342,0,"data_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBit(c+344,0,"valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_id2ex__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_id2ex__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+480,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+24,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+468,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+358,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+345,0,"up_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+425,0,"up_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+414,0,"up_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 262,0);
    tracep->declBit(c+263,0,"dn_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+402,0,"dn_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+264,0,"dn_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 262,0);
    tracep->declArray(c+273,0,"data_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 262,0);
    tracep->declBit(c+282,0,"valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_ex2mem__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_ex2mem__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+481,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+26,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+359,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+283,0,"up_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+403,0,"up_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+386,0,"up_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 142,0);
    tracep->declBit(c+200,0,"dn_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"dn_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+201,0,"dn_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 142,0);
    tracep->declArray(c+206,0,"data_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 142,0);
    tracep->declBit(c+211,0,"valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_core__u_mem2wb__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_core__u_mem2wb__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+482,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+28,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+6,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+360,0,"up_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"up_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+364,0,"up_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 139,0);
    tracep->declBit(c+157,0,"dn_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"dn_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+158,0,"dn_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 139,0);
    tracep->declArray(c+163,0,"data_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 139,0);
    tracep->declBit(c+168,0,"valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
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
    bufp->fullIData(oldp+469,(0x20U),32);
    bufp->fullCData(oldp+470,(vlSymsp->TOP__top__u_core.__PVT__fwd_rs1_sel),2);
    bufp->fullCData(oldp+471,(vlSymsp->TOP__top__u_core.__PVT__fwd_rs2_sel),2);
    bufp->fullBit(oldp+472,(0U));
    bufp->fullBit(oldp+473,(1U));
    bufp->fullIData(oldp+474,(0x3d1c5U),32);
    bufp->fullCData(oldp+475,(0U),2);
    bufp->fullCData(oldp+476,(1U),2);
    bufp->fullCData(oldp+477,(2U),2);
    bufp->fullIData(oldp+478,(0x80000000U),32);
    bufp->fullIData(oldp+479,(0x40U),32);
    bufp->fullIData(oldp+480,(0x107U),32);
    bufp->fullIData(oldp+481,(0x8fU),32);
    bufp->fullIData(oldp+482,(0x8cU),32);
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
    bufp->fullIData(oldp+1,(vlSymsp->TOP__top__u_core.__PVT__trap_cause),32);
    bufp->fullIData(oldp+2,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_cause),32);
    bufp->fullIData(oldp+3,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_cause),32);
    bufp->fullBit(oldp+4,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__flush));
    bufp->fullBit(oldp+5,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__flush));
    bufp->fullBit(oldp+6,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__stall));
    bufp->fullBit(oldp+7,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__dn_ready));
    bufp->fullBit(oldp+8,(vlSymsp->TOP__top.clk));
    bufp->fullBit(oldp+9,(vlSymsp->TOP__top.rst_n));
    bufp->fullBit(oldp+10,(vlSymsp->TOP__top__u_core.__PVT__clk));
    bufp->fullBit(oldp+11,(vlSymsp->TOP__top__u_core.__PVT__rst_n));
    bufp->fullBit(oldp+12,(vlSymsp->TOP__top__u_core__u_memory.__PVT__clk));
    bufp->fullBit(oldp+13,(vlSymsp->TOP__top__u_core__u_memory.__PVT__rst_n));
    bufp->fullBit(oldp+14,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__clk));
    bufp->fullBit(oldp+15,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__rst));
    bufp->fullBit(oldp+16,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__clk));
    bufp->fullBit(oldp+17,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rst_n));
    bufp->fullBit(oldp+18,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__clk));
    bufp->fullBit(oldp+19,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__rst_n));
    bufp->fullBit(oldp+20,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__clk));
    bufp->fullBit(oldp+21,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__rst_n));
    bufp->fullBit(oldp+22,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__clk));
    bufp->fullBit(oldp+23,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__rst_n));
    bufp->fullBit(oldp+24,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__clk));
    bufp->fullBit(oldp+25,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__rst_n));
    bufp->fullBit(oldp+26,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__clk));
    bufp->fullBit(oldp+27,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__rst_n));
    bufp->fullBit(oldp+28,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__clk));
    bufp->fullBit(oldp+29,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__rst_n));
    bufp->fullIData(oldp+30,(vlSymsp->TOP__top.pc),32);
    bufp->fullIData(oldp+31,(vlSymsp->TOP__top__u_core.__PVT__pc),32);
    bufp->fullIData(oldp+32,(vlSymsp->TOP__top__u_core.__PVT__ifu_raddr),32);
    bufp->fullIData(oldp+33,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__pc_pointer),32);
    bufp->fullIData(oldp+34,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__ifu_raddr),32);
    bufp->fullIData(oldp+35,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__pc),32);
    bufp->fullIData(oldp+36,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__pc_pointer),32);
    bufp->fullIData(oldp+37,(vlSymsp->TOP__top__u_core.__PVT__trap_mtvec),32);
    bufp->fullIData(oldp+38,(vlSymsp->TOP__top__u_core.__PVT__trap_mepc),32);
    bufp->fullIData(oldp+39,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_mtvec),32);
    bufp->fullIData(oldp+40,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_mepc),32);
    bufp->fullIData(oldp+41,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mstatus),32);
    bufp->fullIData(oldp+42,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mtvec),32);
    bufp->fullIData(oldp+43,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mepc),32);
    bufp->fullIData(oldp+44,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mcause),32);
    bufp->fullQData(oldp+45,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mcycle_cnt),64);
    bufp->fullIData(oldp+47,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_mtvec),32);
    bufp->fullIData(oldp+48,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_mepc),32);
    bufp->fullIData(oldp+49,(vlSymsp->TOP__top.regs[0]),32);
    bufp->fullIData(oldp+50,(vlSymsp->TOP__top.regs[1]),32);
    bufp->fullIData(oldp+51,(vlSymsp->TOP__top.regs[2]),32);
    bufp->fullIData(oldp+52,(vlSymsp->TOP__top.regs[3]),32);
    bufp->fullIData(oldp+53,(vlSymsp->TOP__top.regs[4]),32);
    bufp->fullIData(oldp+54,(vlSymsp->TOP__top.regs[5]),32);
    bufp->fullIData(oldp+55,(vlSymsp->TOP__top.regs[6]),32);
    bufp->fullIData(oldp+56,(vlSymsp->TOP__top.regs[7]),32);
    bufp->fullIData(oldp+57,(vlSymsp->TOP__top.regs[8]),32);
    bufp->fullIData(oldp+58,(vlSymsp->TOP__top.regs[9]),32);
    bufp->fullIData(oldp+59,(vlSymsp->TOP__top.regs[10]),32);
    bufp->fullIData(oldp+60,(vlSymsp->TOP__top.regs[11]),32);
    bufp->fullIData(oldp+61,(vlSymsp->TOP__top.regs[12]),32);
    bufp->fullIData(oldp+62,(vlSymsp->TOP__top.regs[13]),32);
    bufp->fullIData(oldp+63,(vlSymsp->TOP__top.regs[14]),32);
    bufp->fullIData(oldp+64,(vlSymsp->TOP__top.regs[15]),32);
    bufp->fullIData(oldp+65,(vlSymsp->TOP__top__u_core.__PVT__regs[0]),32);
    bufp->fullIData(oldp+66,(vlSymsp->TOP__top__u_core.__PVT__regs[1]),32);
    bufp->fullIData(oldp+67,(vlSymsp->TOP__top__u_core.__PVT__regs[2]),32);
    bufp->fullIData(oldp+68,(vlSymsp->TOP__top__u_core.__PVT__regs[3]),32);
    bufp->fullIData(oldp+69,(vlSymsp->TOP__top__u_core.__PVT__regs[4]),32);
    bufp->fullIData(oldp+70,(vlSymsp->TOP__top__u_core.__PVT__regs[5]),32);
    bufp->fullIData(oldp+71,(vlSymsp->TOP__top__u_core.__PVT__regs[6]),32);
    bufp->fullIData(oldp+72,(vlSymsp->TOP__top__u_core.__PVT__regs[7]),32);
    bufp->fullIData(oldp+73,(vlSymsp->TOP__top__u_core.__PVT__regs[8]),32);
    bufp->fullIData(oldp+74,(vlSymsp->TOP__top__u_core.__PVT__regs[9]),32);
    bufp->fullIData(oldp+75,(vlSymsp->TOP__top__u_core.__PVT__regs[10]),32);
    bufp->fullIData(oldp+76,(vlSymsp->TOP__top__u_core.__PVT__regs[11]),32);
    bufp->fullIData(oldp+77,(vlSymsp->TOP__top__u_core.__PVT__regs[12]),32);
    bufp->fullIData(oldp+78,(vlSymsp->TOP__top__u_core.__PVT__regs[13]),32);
    bufp->fullIData(oldp+79,(vlSymsp->TOP__top__u_core.__PVT__regs[14]),32);
    bufp->fullIData(oldp+80,(vlSymsp->TOP__top__u_core.__PVT__regs[15]),32);
    bufp->fullIData(oldp+81,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[0]),32);
    bufp->fullIData(oldp+82,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[1]),32);
    bufp->fullIData(oldp+83,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[2]),32);
    bufp->fullIData(oldp+84,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[3]),32);
    bufp->fullIData(oldp+85,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[4]),32);
    bufp->fullIData(oldp+86,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[5]),32);
    bufp->fullIData(oldp+87,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[6]),32);
    bufp->fullIData(oldp+88,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[7]),32);
    bufp->fullIData(oldp+89,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[8]),32);
    bufp->fullIData(oldp+90,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[9]),32);
    bufp->fullIData(oldp+91,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[10]),32);
    bufp->fullIData(oldp+92,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[11]),32);
    bufp->fullIData(oldp+93,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[12]),32);
    bufp->fullIData(oldp+94,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[13]),32);
    bufp->fullIData(oldp+95,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[14]),32);
    bufp->fullIData(oldp+96,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[15]),32);
    bufp->fullIData(oldp+97,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[0]),32);
    bufp->fullIData(oldp+98,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[1]),32);
    bufp->fullIData(oldp+99,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[2]),32);
    bufp->fullIData(oldp+100,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[3]),32);
    bufp->fullIData(oldp+101,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[4]),32);
    bufp->fullIData(oldp+102,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[5]),32);
    bufp->fullIData(oldp+103,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[6]),32);
    bufp->fullIData(oldp+104,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[7]),32);
    bufp->fullIData(oldp+105,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[8]),32);
    bufp->fullIData(oldp+106,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[9]),32);
    bufp->fullIData(oldp+107,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[10]),32);
    bufp->fullIData(oldp+108,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[11]),32);
    bufp->fullIData(oldp+109,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[12]),32);
    bufp->fullIData(oldp+110,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[13]),32);
    bufp->fullIData(oldp+111,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[14]),32);
    bufp->fullIData(oldp+112,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[15]),32);
    bufp->fullIData(oldp+113,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+114,(vlSymsp->TOP__top.__PVT__ifu_rdata),32);
    bufp->fullIData(oldp+115,(vlSymsp->TOP__top.__PVT__lsu_rdata),32);
    bufp->fullIData(oldp+116,(vlSymsp->TOP__top__u_core.__PVT__ifu_rdata),32);
    bufp->fullIData(oldp+117,(vlSymsp->TOP__top__u_core.__PVT__lsu_rdata),32);
    bufp->fullIData(oldp+118,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_rdata),32);
    bufp->fullIData(oldp+119,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__ifu_rdata),32);
    bufp->fullBit(oldp+120,(vlSymsp->TOP__top.debug_wb_have));
    bufp->fullIData(oldp+121,(vlSymsp->TOP__top.debug_wb_pc),32);
    bufp->fullIData(oldp+122,(vlSymsp->TOP__top.debug_wb_instr),32);
    bufp->fullBit(oldp+123,(vlSymsp->TOP__top.debug_wb_en));
    bufp->fullCData(oldp+124,(vlSymsp->TOP__top.debug_wb_addr),5);
    bufp->fullIData(oldp+125,(vlSymsp->TOP__top.debug_wb_data),32);
    bufp->fullBit(oldp+126,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_have));
    bufp->fullIData(oldp+127,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_pc),32);
    bufp->fullIData(oldp+128,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_instr),32);
    bufp->fullBit(oldp+129,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_en));
    bufp->fullCData(oldp+130,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_addr),5);
    bufp->fullIData(oldp+131,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_data),32);
    bufp->fullBit(oldp+132,(vlSymsp->TOP__top__u_core.__PVT__mem2wb_up_ready));
    bufp->fullBit(oldp+133,(vlSymsp->TOP__top__u_core.__PVT__mem2wb_dn_valid));
    bufp->fullWData(oldp+134,(vlSymsp->TOP__top__u_core.__PVT__mem_wb_dn),140);
    bufp->fullBit(oldp+139,(vlSymsp->TOP__top__u_core.__PVT__wb_wr_en));
    bufp->fullCData(oldp+140,(vlSymsp->TOP__top__u_core.__PVT__wb_wr_addr),5);
    bufp->fullIData(oldp+141,(vlSymsp->TOP__top__u_core.__PVT__wb_wr_data),32);
    bufp->fullIData(oldp+142,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__alu_result_in),32);
    bufp->fullIData(oldp+143,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__mem_rdata_in),32);
    bufp->fullCData(oldp+144,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__opcode_in),7);
    bufp->fullCData(oldp+145,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__rd_addr_in),5);
    bufp->fullBit(oldp+146,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__wb_en));
    bufp->fullCData(oldp+147,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__wb_addr),5);
    bufp->fullIData(oldp+148,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__wb_data),32);
    bufp->fullBit(oldp+149,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__wr_en));
    bufp->fullCData(oldp+150,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__wr_addr),5);
    bufp->fullIData(oldp+151,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__wr_data),32);
    bufp->fullCData(oldp+152,(vlSymsp->TOP__top__u_core__u_forward.__PVT__wb_opcode),7);
    bufp->fullCData(oldp+153,(vlSymsp->TOP__top__u_core__u_forward.__PVT__wb_rd_addr),5);
    bufp->fullIData(oldp+154,(vlSymsp->TOP__top__u_core__u_forward.__PVT__wb_wr_data),32);
    bufp->fullBit(oldp+155,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__dn_ready));
    bufp->fullBit(oldp+156,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__up_ready));
    bufp->fullBit(oldp+157,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__dn_valid));
    bufp->fullWData(oldp+158,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__dn_data),140);
    bufp->fullWData(oldp+163,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__data_q),140);
    bufp->fullBit(oldp+168,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__valid_q));
    bufp->fullIData(oldp+169,(vlSymsp->TOP__top.__PVT__lsu_addr),32);
    bufp->fullBit(oldp+170,(vlSymsp->TOP__top.__PVT__lsu_ren));
    bufp->fullBit(oldp+171,(vlSymsp->TOP__top.__PVT__lsu_wen));
    bufp->fullIData(oldp+172,(vlSymsp->TOP__top.__PVT__lsu_wdata),32);
    bufp->fullCData(oldp+173,(vlSymsp->TOP__top.__PVT__lsu_wmask),4);
    bufp->fullIData(oldp+174,(vlSymsp->TOP__top__u_core.__PVT__lsu_addr),32);
    bufp->fullBit(oldp+175,(vlSymsp->TOP__top__u_core.__PVT__lsu_ren));
    bufp->fullBit(oldp+176,(vlSymsp->TOP__top__u_core.__PVT__lsu_wen));
    bufp->fullIData(oldp+177,(vlSymsp->TOP__top__u_core.__PVT__lsu_wdata),32);
    bufp->fullCData(oldp+178,(vlSymsp->TOP__top__u_core.__PVT__lsu_wmask),4);
    bufp->fullBit(oldp+179,(vlSymsp->TOP__top__u_core.__PVT__ex2mem_dn_valid));
    bufp->fullWData(oldp+180,(vlSymsp->TOP__top__u_core.__PVT__ex_mem_dn),143);
    bufp->fullBit(oldp+185,(vlSymsp->TOP__top__u_core__u_memory.__PVT__valid_in));
    bufp->fullIData(oldp+186,(vlSymsp->TOP__top__u_core__u_memory.__PVT__alu_result_in),32);
    bufp->fullIData(oldp+187,(vlSymsp->TOP__top__u_core__u_memory.__PVT__rs2_data_in),32);
    bufp->fullCData(oldp+188,(vlSymsp->TOP__top__u_core__u_memory.__PVT__opcode_in),7);
    bufp->fullCData(oldp+189,(vlSymsp->TOP__top__u_core__u_memory.__PVT__funct3_in),3);
    bufp->fullIData(oldp+190,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_addr),32);
    bufp->fullBit(oldp+191,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_ren));
    bufp->fullBit(oldp+192,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_wen));
    bufp->fullIData(oldp+193,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_wdata),32);
    bufp->fullCData(oldp+194,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_wmask),4);
    bufp->fullBit(oldp+195,(vlSymsp->TOP__top__u_core__u_memory.__PVT__is_load));
    bufp->fullBit(oldp+196,(vlSymsp->TOP__top__u_core__u_memory.__PVT__is_store));
    bufp->fullCData(oldp+197,(vlSymsp->TOP__top__u_core__u_forward.__PVT__mem_opcode),7);
    bufp->fullCData(oldp+198,(vlSymsp->TOP__top__u_core__u_forward.__PVT__mem_rd_addr),5);
    bufp->fullIData(oldp+199,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_mem_alu_result),32);
    bufp->fullBit(oldp+200,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__dn_valid));
    bufp->fullWData(oldp+201,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__dn_data),143);
    bufp->fullWData(oldp+206,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__data_q),143);
    bufp->fullBit(oldp+211,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__valid_q));
    bufp->fullWData(oldp+212,(vlSymsp->TOP__top__u_core.__PVT__mem_wb_up),140);
    bufp->fullBit(oldp+217,(vlSymsp->TOP__top__u_core.__PVT__id2ex_dn_valid));
    bufp->fullWData(oldp+218,(vlSymsp->TOP__top__u_core.__PVT__id_ex_dn),263);
    bufp->fullSData(oldp+227,(vlSymsp->TOP__top__u_core.__PVT__csr_raddr),12);
    bufp->fullBit(oldp+228,(vlSymsp->TOP__top__u_core.__PVT__csr_wen));
    bufp->fullSData(oldp+229,(vlSymsp->TOP__top__u_core.__PVT__csr_waddr),12);
    bufp->fullBit(oldp+230,(vlSymsp->TOP__top__u_core.__PVT__trap_valid));
    bufp->fullIData(oldp+231,(vlSymsp->TOP__top__u_core.__PVT__trap_pc),32);
    bufp->fullSData(oldp+232,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_raddr),12);
    bufp->fullBit(oldp+233,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_wen));
    bufp->fullSData(oldp+234,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_waddr),12);
    bufp->fullBit(oldp+235,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_valid));
    bufp->fullIData(oldp+236,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_pc),32);
    bufp->fullCData(oldp+237,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_stage_opcode),7);
    bufp->fullCData(oldp+238,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_stage_rd_addr),5);
    bufp->fullCData(oldp+239,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__ex_opcode),7);
    bufp->fullCData(oldp+240,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__ex_rd_addr),5);
    bufp->fullBit(oldp+241,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__ex_is_load));
    bufp->fullIData(oldp+242,(vlSymsp->TOP__top__u_core__u_execute.__PVT__pc_in),32);
    bufp->fullIData(oldp+243,(vlSymsp->TOP__top__u_core__u_execute.__PVT__op1_in),32);
    bufp->fullIData(oldp+244,(vlSymsp->TOP__top__u_core__u_execute.__PVT__op2_in),32);
    bufp->fullIData(oldp+245,(vlSymsp->TOP__top__u_core__u_execute.__PVT__rs1_data_in),32);
    bufp->fullIData(oldp+246,(vlSymsp->TOP__top__u_core__u_execute.__PVT__imm_in),32);
    bufp->fullCData(oldp+247,(vlSymsp->TOP__top__u_core__u_execute.__PVT__opcode_in),7);
    bufp->fullCData(oldp+248,(vlSymsp->TOP__top__u_core__u_execute.__PVT__funct3_in),3);
    bufp->fullCData(oldp+249,(vlSymsp->TOP__top__u_core__u_execute.__PVT__funct7_in),7);
    bufp->fullBit(oldp+250,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_ebreak_in));
    bufp->fullSData(oldp+251,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_addr_in),12);
    bufp->fullBit(oldp+252,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_csrrw));
    bufp->fullBit(oldp+253,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_csrrs));
    bufp->fullBit(oldp+254,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_ecall));
    bufp->fullBit(oldp+255,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_mret));
    bufp->fullSData(oldp+256,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_raddr),12);
    bufp->fullBit(oldp+257,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_wen));
    bufp->fullSData(oldp+258,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_waddr),12);
    bufp->fullBit(oldp+259,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_valid));
    bufp->fullIData(oldp+260,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_pc),32);
    bufp->fullIData(oldp+261,(vlSymsp->TOP__top__u_core__u_execute.__PVT__alu_res),32);
    bufp->fullBit(oldp+262,(vlSymsp->TOP__top__u_core__u_execute.__PVT__branch_taken));
    bufp->fullBit(oldp+263,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__dn_valid));
    bufp->fullWData(oldp+264,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__dn_data),263);
    bufp->fullWData(oldp+273,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__data_q),263);
    bufp->fullBit(oldp+282,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__valid_q));
    bufp->fullBit(oldp+283,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__up_valid));
    bufp->fullWData(oldp+284,(vlSymsp->TOP__top__u_core.__PVT__ex_mem_up),143);
    bufp->fullBit(oldp+289,(vlSymsp->TOP__top__u_core.__PVT__if2id_dn_valid));
    bufp->fullQData(oldp+290,(vlSymsp->TOP__top__u_core.__PVT__if_id_dn),64);
    bufp->fullCData(oldp+292,(vlSymsp->TOP__top__u_core.__PVT__decode_rs1_addr),5);
    bufp->fullCData(oldp+293,(vlSymsp->TOP__top__u_core.__PVT__decode_rs2_addr),5);
    bufp->fullCData(oldp+294,(vlSymsp->TOP__top__u_core.__PVT__decode_rd_addr),5);
    bufp->fullIData(oldp+295,(vlSymsp->TOP__top__u_core.__PVT__decode_imm),32);
    bufp->fullCData(oldp+296,(vlSymsp->TOP__top__u_core.__PVT__decode_op1_sel),2);
    bufp->fullCData(oldp+297,(vlSymsp->TOP__top__u_core.__PVT__decode_op2_sel),2);
    bufp->fullCData(oldp+298,(vlSymsp->TOP__top__u_core.__PVT__decode_opcode),7);
    bufp->fullCData(oldp+299,(vlSymsp->TOP__top__u_core.__PVT__decode_funct3),3);
    bufp->fullCData(oldp+300,(vlSymsp->TOP__top__u_core.__PVT__decode_funct7),7);
    bufp->fullSData(oldp+301,(vlSymsp->TOP__top__u_core.__PVT__decode_csr_addr),12);
    bufp->fullBit(oldp+302,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_csrrw));
    bufp->fullBit(oldp+303,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_csrrs));
    bufp->fullBit(oldp+304,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_ecall));
    bufp->fullBit(oldp+305,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_mret));
    bufp->fullBit(oldp+306,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_ebreak));
    bufp->fullCData(oldp+307,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs1_addr),5);
    bufp->fullCData(oldp+308,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs2_addr),5);
    bufp->fullCData(oldp+309,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_rs1_addr),5);
    bufp->fullCData(oldp+310,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_rs2_addr),5);
    bufp->fullIData(oldp+311,(vlSymsp->TOP__top__u_core__u_decode.__PVT__instr_addr_in),32);
    bufp->fullIData(oldp+312,(vlSymsp->TOP__top__u_core__u_decode.__PVT__instr_in),32);
    bufp->fullCData(oldp+313,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rd_rs1_addr),5);
    bufp->fullCData(oldp+314,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rd_rs2_addr),5);
    bufp->fullCData(oldp+315,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rd_addr_out),5);
    bufp->fullIData(oldp+316,(vlSymsp->TOP__top__u_core__u_decode.__PVT__imm_out),32);
    bufp->fullCData(oldp+317,(vlSymsp->TOP__top__u_core__u_decode.__PVT__op1_sel_out),2);
    bufp->fullCData(oldp+318,(vlSymsp->TOP__top__u_core__u_decode.__PVT__op2_sel_out),2);
    bufp->fullCData(oldp+319,(vlSymsp->TOP__top__u_core__u_decode.__PVT__opcode_out),7);
    bufp->fullCData(oldp+320,(vlSymsp->TOP__top__u_core__u_decode.__PVT__funct3_out),3);
    bufp->fullCData(oldp+321,(vlSymsp->TOP__top__u_core__u_decode.__PVT__funct7_out),7);
    bufp->fullBit(oldp+322,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_ebreak));
    bufp->fullSData(oldp+323,(vlSymsp->TOP__top__u_core__u_decode.__PVT__csr_addr_out),12);
    bufp->fullBit(oldp+324,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_csrrw));
    bufp->fullBit(oldp+325,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_csrrs));
    bufp->fullBit(oldp+326,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_ecall));
    bufp->fullBit(oldp+327,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_mret));
    bufp->fullCData(oldp+328,(vlSymsp->TOP__top__u_core__u_decode.__PVT__opcode),7);
    bufp->fullCData(oldp+329,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rd),5);
    bufp->fullCData(oldp+330,(vlSymsp->TOP__top__u_core__u_decode.__PVT__funct3),3);
    bufp->fullCData(oldp+331,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rs1),5);
    bufp->fullCData(oldp+332,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rs2),5);
    bufp->fullCData(oldp+333,(vlSymsp->TOP__top__u_core__u_decode.__PVT__funct7),7);
    bufp->fullIData(oldp+334,(vlSymsp->TOP__top__u_core__u_decode.__PVT__imm),32);
    bufp->fullBit(oldp+335,(vlSymsp->TOP__top__u_core__u_decode.__PVT__is_ebreak));
    bufp->fullBit(oldp+336,(vlSymsp->TOP__top__u_core__u_decode.__PVT__is_system));
    bufp->fullCData(oldp+337,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__id_rs1_addr),5);
    bufp->fullCData(oldp+338,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__id_rs2_addr),5);
    bufp->fullBit(oldp+339,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__dn_valid));
    bufp->fullQData(oldp+340,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__dn_data),64);
    bufp->fullQData(oldp+342,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__data_q),64);
    bufp->fullBit(oldp+344,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__valid_q));
    bufp->fullBit(oldp+345,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__up_valid));
    bufp->fullWData(oldp+346,(vlSymsp->TOP__top__u_core.__PVT__id_ex_up),263);
    bufp->fullBit(oldp+355,(vlSymsp->TOP__top__u_core.__PVT__lsu_busy));
    bufp->fullBit(oldp+356,(vlSymsp->TOP__top__u_core__u_memory.__PVT__lsu_busy));
    bufp->fullBit(oldp+357,(vlSymsp->TOP__top__u_core__u_memory.__PVT__state_next));
    bufp->fullBit(oldp+358,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__stall));
    bufp->fullBit(oldp+359,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__stall));
    bufp->fullBit(oldp+360,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__up_valid));
    bufp->fullIData(oldp+361,(vlSymsp->TOP__top__u_core.__PVT__mem_rdata),32);
    bufp->fullIData(oldp+362,(vlSymsp->TOP__top__u_core__u_memory.__PVT__mem_rdata_out),32);
    bufp->fullIData(oldp+363,(vlSymsp->TOP__top__u_core__u_forward.__PVT__mem_rdata),32);
    bufp->fullWData(oldp+364,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__up_data),140);
    bufp->fullIData(oldp+369,(vlSymsp->TOP__top__u_core.__PVT__ex_alu_result),32);
    bufp->fullBit(oldp+370,(vlSymsp->TOP__top__u_core.__PVT__ex_jump_flag));
    bufp->fullIData(oldp+371,(vlSymsp->TOP__top__u_core.__PVT__ex_jump_target),32);
    bufp->fullIData(oldp+372,(vlSymsp->TOP__top__u_core.__PVT__csr_rdata),32);
    bufp->fullIData(oldp+373,(vlSymsp->TOP__top__u_core.__PVT__csr_wdata),32);
    bufp->fullIData(oldp+374,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_rdata),32);
    bufp->fullIData(oldp+375,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_wdata),32);
    bufp->fullIData(oldp+376,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_alu_result),32);
    bufp->fullBit(oldp+377,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__flush));
    bufp->fullIData(oldp+378,(vlSymsp->TOP__top__u_core__u_execute.__PVT__alu_result_out),32);
    bufp->fullBit(oldp+379,(vlSymsp->TOP__top__u_core__u_execute.__PVT__jump_flag_out));
    bufp->fullIData(oldp+380,(vlSymsp->TOP__top__u_core__u_execute.__PVT__jump_target_out),32);
    bufp->fullIData(oldp+381,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_rdata),32);
    bufp->fullIData(oldp+382,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_wdata),32);
    bufp->fullBit(oldp+383,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__jump_en));
    bufp->fullIData(oldp+384,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__jump_addr),32);
    bufp->fullBit(oldp+385,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__flush));
    bufp->fullWData(oldp+386,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__up_data),143);
    bufp->fullBit(oldp+391,(vlSymsp->TOP__top__u_core.__PVT__load_stall));
    bufp->fullBit(oldp+392,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__stall));
    bufp->fullBit(oldp+393,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__rs1_hazard));
    bufp->fullBit(oldp+394,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__rs2_hazard));
    bufp->fullIData(oldp+395,(vlSymsp->TOP__top__u_core.__PVT__reg_rs1_data),32);
    bufp->fullIData(oldp+396,(vlSymsp->TOP__top__u_core.__PVT__reg_rs2_data),32);
    bufp->fullIData(oldp+397,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs1_data),32);
    bufp->fullIData(oldp+398,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs2_data),32);
    bufp->fullIData(oldp+399,(vlSymsp->TOP__top__u_core__u_forward.__PVT__reg_rs1_data),32);
    bufp->fullIData(oldp+400,(vlSymsp->TOP__top__u_core__u_forward.__PVT__reg_rs2_data),32);
    bufp->fullBit(oldp+401,(vlSymsp->TOP__top__u_core.__PVT__ex2mem_up_ready));
    bufp->fullBit(oldp+402,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__dn_ready));
    bufp->fullBit(oldp+403,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__up_ready));
    bufp->fullBit(oldp+404,(vlSymsp->TOP__top__u_core.__PVT__ifu_valid));
    bufp->fullBit(oldp+405,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__ifu_valid));
    bufp->fullBit(oldp+406,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__state_next));
    bufp->fullBit(oldp+407,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__up_valid));
    bufp->fullIData(oldp+408,(vlSymsp->TOP__top__u_core.__PVT__fwd_rs1_data),32);
    bufp->fullIData(oldp+409,(vlSymsp->TOP__top__u_core.__PVT__fwd_rs2_data),32);
    bufp->fullIData(oldp+410,(vlSymsp->TOP__top__u_core.__PVT__id_op1),32);
    bufp->fullIData(oldp+411,(vlSymsp->TOP__top__u_core.__PVT__id_op2),32);
    bufp->fullIData(oldp+412,(vlSymsp->TOP__top__u_core__u_forward.__PVT__fwd_rs1_data),32);
    bufp->fullIData(oldp+413,(vlSymsp->TOP__top__u_core__u_forward.__PVT__fwd_rs2_data),32);
    bufp->fullWData(oldp+414,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__up_data),263);
    bufp->fullBit(oldp+423,(vlSymsp->TOP__top__u_core.__PVT__id2ex_up_ready));
    bufp->fullBit(oldp+424,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__dn_ready));
    bufp->fullBit(oldp+425,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__up_ready));
    bufp->fullIData(oldp+426,(vlSymsp->TOP__top.instr),32);
    bufp->fullIData(oldp+427,(vlSymsp->TOP__top__u_core.__PVT__instr),32);
    bufp->fullIData(oldp+428,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__instr_out),32);
    bufp->fullBit(oldp+429,(vlSelfRef.clk));
    bufp->fullBit(oldp+430,(vlSelfRef.rst_n));
    bufp->fullIData(oldp+431,(vlSelfRef.pc),32);
    bufp->fullIData(oldp+432,(vlSelfRef.instr),32);
    bufp->fullIData(oldp+433,(vlSelfRef.regs[0]),32);
    bufp->fullIData(oldp+434,(vlSelfRef.regs[1]),32);
    bufp->fullIData(oldp+435,(vlSelfRef.regs[2]),32);
    bufp->fullIData(oldp+436,(vlSelfRef.regs[3]),32);
    bufp->fullIData(oldp+437,(vlSelfRef.regs[4]),32);
    bufp->fullIData(oldp+438,(vlSelfRef.regs[5]),32);
    bufp->fullIData(oldp+439,(vlSelfRef.regs[6]),32);
    bufp->fullIData(oldp+440,(vlSelfRef.regs[7]),32);
    bufp->fullIData(oldp+441,(vlSelfRef.regs[8]),32);
    bufp->fullIData(oldp+442,(vlSelfRef.regs[9]),32);
    bufp->fullIData(oldp+443,(vlSelfRef.regs[10]),32);
    bufp->fullIData(oldp+444,(vlSelfRef.regs[11]),32);
    bufp->fullIData(oldp+445,(vlSelfRef.regs[12]),32);
    bufp->fullIData(oldp+446,(vlSelfRef.regs[13]),32);
    bufp->fullIData(oldp+447,(vlSelfRef.regs[14]),32);
    bufp->fullIData(oldp+448,(vlSelfRef.regs[15]),32);
    bufp->fullBit(oldp+449,(vlSelfRef.debug_wb_have));
    bufp->fullIData(oldp+450,(vlSelfRef.debug_wb_pc),32);
    bufp->fullIData(oldp+451,(vlSelfRef.debug_wb_instr),32);
    bufp->fullBit(oldp+452,(vlSelfRef.debug_wb_en));
    bufp->fullCData(oldp+453,(vlSelfRef.debug_wb_addr),5);
    bufp->fullIData(oldp+454,(vlSelfRef.debug_wb_data),32);
    bufp->fullIData(oldp+455,(vlSymsp->TOP__top.__PVT__ifu_raddr),32);
    bufp->fullBit(oldp+456,(vlSymsp->TOP__top__u_core.__PVT__if2id_up_ready));
    bufp->fullQData(oldp+457,(vlSymsp->TOP__top__u_core.__PVT__if_id_up),64);
    bufp->fullBit(oldp+459,(vlSymsp->TOP__top__u_core__u_memory.__PVT__state));
    bufp->fullCData(oldp+460,(vlSymsp->TOP__top__u_core__u_forward.__PVT__fwd_rs1_sel),2);
    bufp->fullCData(oldp+461,(vlSymsp->TOP__top__u_core__u_forward.__PVT__fwd_rs2_sel),2);
    bufp->fullBit(oldp+462,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__state));
    bufp->fullBit(oldp+463,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__pc_hold));
    bufp->fullBit(oldp+464,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__stall));
    bufp->fullBit(oldp+465,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__up_ready));
    bufp->fullQData(oldp+466,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__up_data),64);
    bufp->fullBit(oldp+468,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__flush));
}
