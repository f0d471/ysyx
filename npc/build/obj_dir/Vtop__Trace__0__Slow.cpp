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
    tracep->declBit(c+282,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+283,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+284,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+285,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+286,0,"debug_x10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+287+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
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
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_csr_file__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+303,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+4,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+5,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+277,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+226,0,"debug_x10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+227+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+17,0,"instr_addr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"instr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"decode_rs1_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+20,0,"decode_rs2_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+21,0,"decode_rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+22,0,"decode_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"decode_op1_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+24,0,"decode_op2_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+25,0,"decode_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+26,0,"decode_funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+27,0,"decode_funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+28,0,"decode_csr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+29,0,"decode_inst_csrrw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"decode_inst_csrrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"decode_inst_ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"decode_inst_mret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+81,0,"reg_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"reg_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"id_instr_addr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"id_instr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"id_op1_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"id_op2_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"id_rd_addr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+88,0,"id_imm_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+89,0,"id_opcode_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+90,0,"id_funct3_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+91,0,"id_funct7_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+92,0,"id_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"id_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"id_csr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+95,0,"id_inst_csrrw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"id_inst_csrrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"id_inst_ecall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"id_inst_mret",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+157,0,"ex_alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+158,0,"ex_jump_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+159,0,"ex_jump_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+160,0,"ex_alu_result_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+161,0,"ex_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+162,0,"ex_rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+163,0,"ex_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+164,0,"ex_funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+165,0,"mem_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"mem_alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"mem_rdata_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"mem_rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+169,0,"mem_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+170,0,"wb_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+171,0,"wb_wr_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+172,0,"wb_wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+33,0,"inst_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"inst_ebreak_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"csr_raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+173,0,"csr_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+101,0,"csr_wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+102,0,"csr_waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+174,0,"csr_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+103,0,"trap_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"trap_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"trap_cause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+214,0,"trap_mtvec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+215,0,"trap_mepc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
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
    tracep->pushPrefix("u_csr_file", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top__u_csr_file__0(vlSelf, tracep);
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
    tracep->declBus(c+303,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+278,0,"instr_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"instr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"instr_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"instr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_memory__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_memory__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+303,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+6,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+175,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+176,0,"rs2_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+177,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+178,0,"funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+179,0,"mem_rdata_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+180,0,"rdata_raw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_writeback__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_writeback__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+303,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+181,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+182,0,"mem_rdata_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+183,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+184,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+185,0,"wb_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+186,0,"wb_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+187,0,"wb_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_csr_file__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_csr_file__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+304,0,"STU_ID",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+105,0,"csr_raddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+188,0,"csr_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+106,0,"csr_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+107,0,"csr_waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+189,0,"csr_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+108,0,"trap_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"trap_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"trap_cause",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+216,0,"trap_mtvec",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+217,0,"trap_mepc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+218,0,"mstatus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+219,0,"mtvec",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+220,0,"mepc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+221,0,"mcause",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+222,0,"mcycle_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_reg_file__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_reg_file__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+303,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+10,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"rs1_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+38,0,"rs2_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+110,0,"rs1_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+111,0,"rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+190,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+191,0,"wr_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+192,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+243,0,"debug_x10",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+244+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("rf", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+260+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+276,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
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
    tracep->declBus(c+303,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+193,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+194,0,"mem_rdata_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+195,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+196,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+197,0,"alu_result_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+198,0,"mem_rdata_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+199,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+200,0,"opcode_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_fetch__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_fetch__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+303,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+12,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+279,0,"pc_pointer",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+39,0,"instr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_decode__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_decode__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+303,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"instr_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"instr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"rd_rs1_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+43,0,"rd_rs2_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+44,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+45,0,"imm_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"op1_sel_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+47,0,"op2_sel_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+48,0,"opcode_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+49,0,"funct3_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+50,0,"funct7_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+51,0,"inst_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+52,0,"csr_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+53,0,"inst_csrrw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"inst_csrrs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"inst_ecall",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"inst_mret",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+57,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+58,0,"rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+59,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+60,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+61,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+62,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+63,0,"imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+64,0,"is_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"is_system",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+305,0,"OP1_RS1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+306,0,"OP1_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+307,0,"OP1_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+305,0,"OP2_RS2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+306,0,"OP2_IMM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+307,0,"OP2_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_execute__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_execute__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+303,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+112,0,"pc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+113,0,"op1_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+114,0,"op2_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+115,0,"rs1_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+116,0,"imm_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+118,0,"funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+119,0,"funct7_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+201,0,"alu_result_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+202,0,"jump_flag_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+203,0,"jump_target_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+120,0,"inst_ebreak_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+121,0,"csr_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+122,0,"inst_csrrw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"inst_csrrs",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"inst_ecall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"inst_mret",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+126,0,"csr_raddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+204,0,"csr_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+127,0,"csr_wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+128,0,"csr_waddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+205,0,"csr_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+129,0,"trap_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+130,0,"trap_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"trap_cause",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+224,0,"trap_mtvec",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+225,0,"trap_mepc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"alu_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+132,0,"branch_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_id2ex__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_id2ex__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+303,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+66,0,"instr_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,0,"instr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+69,0,"imm_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"op1_sel_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+71,0,"op2_sel_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+72,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+73,0,"funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+74,0,"funct7_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+133,0,"rs1_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"rs2_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+135,0,"instr_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+136,0,"instr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+137,0,"op1_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+138,0,"op2_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+139,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+140,0,"imm_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+141,0,"opcode_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+142,0,"funct3_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+143,0,"funct7_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+144,0,"rs1_data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+145,0,"rs2_data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+75,0,"inst_ebreak_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"inst_ebreak_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"csr_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+77,0,"inst_csrrw_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"inst_csrrs_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"inst_ecall_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"inst_mret_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+147,0,"csr_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+148,0,"inst_csrrw_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"inst_csrrs_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+150,0,"inst_ecall_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"inst_mret_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+305,0,"OP1_RS1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+306,0,"OP1_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+307,0,"OP1_ZERO",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+305,0,"OP2_RS2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+306,0,"OP2_IMM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+307,0,"OP2_4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_ex2mem__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_ex2mem__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+303,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+303,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+152,0,"pc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+206,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+153,0,"rs2_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+154,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+155,0,"opcode_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+156,0,"funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+207,0,"alu_result_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+208,0,"rs2_data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+209,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+210,0,"opcode_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+211,0,"funct3_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__u_pc_counter__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__u_pc_counter__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+303,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+308,0,"RESET_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+212,0,"jump_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+213,0,"jump_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+280,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+281,0,"pc_pointer",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
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
    bufp->fullIData(oldp+303,(0x20U),32);
    bufp->fullIData(oldp+304,(0x3d1c5U),32);
    bufp->fullCData(oldp+305,(0U),2);
    bufp->fullCData(oldp+306,(1U),2);
    bufp->fullCData(oldp+307,(2U),2);
    bufp->fullIData(oldp+308,(0x80000000U),32);
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
    bufp->fullIData(oldp+1,(vlSymsp->TOP__top.__PVT__trap_cause),32);
    bufp->fullIData(oldp+2,(vlSymsp->TOP__top__u_csr_file.__PVT__trap_cause),32);
    bufp->fullIData(oldp+3,(vlSymsp->TOP__top__u_execute.__PVT__trap_cause),32);
    bufp->fullBit(oldp+4,(vlSymsp->TOP__top.clk));
    bufp->fullBit(oldp+5,(vlSymsp->TOP__top.rst_n));
    bufp->fullBit(oldp+6,(vlSymsp->TOP__top__u_memory.__PVT__clk));
    bufp->fullBit(oldp+7,(vlSymsp->TOP__top__u_memory.__PVT__rst_n));
    bufp->fullBit(oldp+8,(vlSymsp->TOP__top__u_csr_file.__PVT__clk));
    bufp->fullBit(oldp+9,(vlSymsp->TOP__top__u_csr_file.__PVT__rst));
    bufp->fullBit(oldp+10,(vlSymsp->TOP__top__u_reg_file.__PVT__clk));
    bufp->fullBit(oldp+11,(vlSymsp->TOP__top__u_reg_file.__PVT__rst_n));
    bufp->fullBit(oldp+12,(vlSymsp->TOP__top__u_fetch.__PVT__clk));
    bufp->fullBit(oldp+13,(vlSymsp->TOP__top__u_fetch.__PVT__rst_n));
    bufp->fullBit(oldp+14,(vlSymsp->TOP__top__u_pc_counter.__PVT__clk));
    bufp->fullBit(oldp+15,(vlSymsp->TOP__top__u_pc_counter.__PVT__rst_n));
    bufp->fullIData(oldp+16,(vlSymsp->TOP__top.instr),32);
    bufp->fullIData(oldp+17,(vlSymsp->TOP__top.__PVT__instr_addr_out),32);
    bufp->fullIData(oldp+18,(vlSymsp->TOP__top.__PVT__instr_out),32);
    bufp->fullCData(oldp+19,(vlSymsp->TOP__top.__PVT__decode_rs1_addr),5);
    bufp->fullCData(oldp+20,(vlSymsp->TOP__top.__PVT__decode_rs2_addr),5);
    bufp->fullCData(oldp+21,(vlSymsp->TOP__top.__PVT__decode_rd_addr),5);
    bufp->fullIData(oldp+22,(vlSymsp->TOP__top.__PVT__decode_imm),32);
    bufp->fullCData(oldp+23,(vlSymsp->TOP__top.__PVT__decode_op1_sel),2);
    bufp->fullCData(oldp+24,(vlSymsp->TOP__top.__PVT__decode_op2_sel),2);
    bufp->fullCData(oldp+25,(vlSymsp->TOP__top.__PVT__decode_opcode),7);
    bufp->fullCData(oldp+26,(vlSymsp->TOP__top.__PVT__decode_funct3),3);
    bufp->fullCData(oldp+27,(vlSymsp->TOP__top.__PVT__decode_funct7),7);
    bufp->fullSData(oldp+28,(vlSymsp->TOP__top.__PVT__decode_csr_addr),12);
    bufp->fullBit(oldp+29,(vlSymsp->TOP__top.__PVT__decode_inst_csrrw));
    bufp->fullBit(oldp+30,(vlSymsp->TOP__top.__PVT__decode_inst_csrrs));
    bufp->fullBit(oldp+31,(vlSymsp->TOP__top.__PVT__decode_inst_ecall));
    bufp->fullBit(oldp+32,(vlSymsp->TOP__top.__PVT__decode_inst_mret));
    bufp->fullBit(oldp+33,(vlSymsp->TOP__top.__PVT__inst_ebreak));
    bufp->fullIData(oldp+34,(vlSymsp->TOP__top__u_if2id.__PVT__instr_in),32);
    bufp->fullIData(oldp+35,(vlSymsp->TOP__top__u_if2id.__PVT__instr_addr_out),32);
    bufp->fullIData(oldp+36,(vlSymsp->TOP__top__u_if2id.__PVT__instr_out),32);
    bufp->fullCData(oldp+37,(vlSymsp->TOP__top__u_reg_file.__PVT__rs1_addr),5);
    bufp->fullCData(oldp+38,(vlSymsp->TOP__top__u_reg_file.__PVT__rs2_addr),5);
    bufp->fullIData(oldp+39,(vlSymsp->TOP__top__u_fetch.__PVT__instr_out),32);
    bufp->fullIData(oldp+40,(vlSymsp->TOP__top__u_decode.__PVT__instr_addr_in),32);
    bufp->fullIData(oldp+41,(vlSymsp->TOP__top__u_decode.__PVT__instr_in),32);
    bufp->fullCData(oldp+42,(vlSymsp->TOP__top__u_decode.__PVT__rd_rs1_addr),5);
    bufp->fullCData(oldp+43,(vlSymsp->TOP__top__u_decode.__PVT__rd_rs2_addr),5);
    bufp->fullCData(oldp+44,(vlSymsp->TOP__top__u_decode.__PVT__rd_addr_out),5);
    bufp->fullIData(oldp+45,(vlSymsp->TOP__top__u_decode.__PVT__imm_out),32);
    bufp->fullCData(oldp+46,(vlSymsp->TOP__top__u_decode.__PVT__op1_sel_out),2);
    bufp->fullCData(oldp+47,(vlSymsp->TOP__top__u_decode.__PVT__op2_sel_out),2);
    bufp->fullCData(oldp+48,(vlSymsp->TOP__top__u_decode.__PVT__opcode_out),7);
    bufp->fullCData(oldp+49,(vlSymsp->TOP__top__u_decode.__PVT__funct3_out),3);
    bufp->fullCData(oldp+50,(vlSymsp->TOP__top__u_decode.__PVT__funct7_out),7);
    bufp->fullBit(oldp+51,(vlSymsp->TOP__top__u_decode.__PVT__inst_ebreak));
    bufp->fullSData(oldp+52,(vlSymsp->TOP__top__u_decode.__PVT__csr_addr_out),12);
    bufp->fullBit(oldp+53,(vlSymsp->TOP__top__u_decode.__PVT__inst_csrrw));
    bufp->fullBit(oldp+54,(vlSymsp->TOP__top__u_decode.__PVT__inst_csrrs));
    bufp->fullBit(oldp+55,(vlSymsp->TOP__top__u_decode.__PVT__inst_ecall));
    bufp->fullBit(oldp+56,(vlSymsp->TOP__top__u_decode.__PVT__inst_mret));
    bufp->fullCData(oldp+57,(vlSymsp->TOP__top__u_decode.__PVT__opcode),7);
    bufp->fullCData(oldp+58,(vlSymsp->TOP__top__u_decode.__PVT__rd),5);
    bufp->fullCData(oldp+59,(vlSymsp->TOP__top__u_decode.__PVT__funct3),3);
    bufp->fullCData(oldp+60,(vlSymsp->TOP__top__u_decode.__PVT__rs1),5);
    bufp->fullCData(oldp+61,(vlSymsp->TOP__top__u_decode.__PVT__rs2),5);
    bufp->fullCData(oldp+62,(vlSymsp->TOP__top__u_decode.__PVT__funct7),7);
    bufp->fullIData(oldp+63,(vlSymsp->TOP__top__u_decode.__PVT__imm),32);
    bufp->fullBit(oldp+64,(vlSymsp->TOP__top__u_decode.__PVT__is_ebreak));
    bufp->fullBit(oldp+65,(vlSymsp->TOP__top__u_decode.__PVT__is_system));
    bufp->fullIData(oldp+66,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_addr_in),32);
    bufp->fullIData(oldp+67,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_in),32);
    bufp->fullCData(oldp+68,(vlSymsp->TOP__top__u_id2ex.__PVT__rd_addr_in),5);
    bufp->fullIData(oldp+69,(vlSymsp->TOP__top__u_id2ex.__PVT__imm_in),32);
    bufp->fullCData(oldp+70,(vlSymsp->TOP__top__u_id2ex.__PVT__op1_sel_in),2);
    bufp->fullCData(oldp+71,(vlSymsp->TOP__top__u_id2ex.__PVT__op2_sel_in),2);
    bufp->fullCData(oldp+72,(vlSymsp->TOP__top__u_id2ex.__PVT__opcode_in),7);
    bufp->fullCData(oldp+73,(vlSymsp->TOP__top__u_id2ex.__PVT__funct3_in),3);
    bufp->fullCData(oldp+74,(vlSymsp->TOP__top__u_id2ex.__PVT__funct7_in),7);
    bufp->fullBit(oldp+75,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_ebreak_in));
    bufp->fullSData(oldp+76,(vlSymsp->TOP__top__u_id2ex.__PVT__csr_addr_in),12);
    bufp->fullBit(oldp+77,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_csrrw_in));
    bufp->fullBit(oldp+78,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_csrrs_in));
    bufp->fullBit(oldp+79,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_ecall_in));
    bufp->fullBit(oldp+80,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_mret_in));
    bufp->fullIData(oldp+81,(vlSymsp->TOP__top.__PVT__reg_rs1_data),32);
    bufp->fullIData(oldp+82,(vlSymsp->TOP__top.__PVT__reg_rs2_data),32);
    bufp->fullIData(oldp+83,(vlSymsp->TOP__top.__PVT__id_instr_addr_out),32);
    bufp->fullIData(oldp+84,(vlSymsp->TOP__top.__PVT__id_instr_out),32);
    bufp->fullIData(oldp+85,(vlSymsp->TOP__top.__PVT__id_op1_out),32);
    bufp->fullIData(oldp+86,(vlSymsp->TOP__top.__PVT__id_op2_out),32);
    bufp->fullCData(oldp+87,(vlSymsp->TOP__top.__PVT__id_rd_addr_out),5);
    bufp->fullIData(oldp+88,(vlSymsp->TOP__top.__PVT__id_imm_out),32);
    bufp->fullCData(oldp+89,(vlSymsp->TOP__top.__PVT__id_opcode_out),7);
    bufp->fullCData(oldp+90,(vlSymsp->TOP__top.__PVT__id_funct3_out),3);
    bufp->fullCData(oldp+91,(vlSymsp->TOP__top.__PVT__id_funct7_out),7);
    bufp->fullIData(oldp+92,(vlSymsp->TOP__top.__PVT__id_rs1_data),32);
    bufp->fullIData(oldp+93,(vlSymsp->TOP__top.__PVT__id_rs2_data),32);
    bufp->fullSData(oldp+94,(vlSymsp->TOP__top.__PVT__id_csr_addr),12);
    bufp->fullBit(oldp+95,(vlSymsp->TOP__top.__PVT__id_inst_csrrw));
    bufp->fullBit(oldp+96,(vlSymsp->TOP__top.__PVT__id_inst_csrrs));
    bufp->fullBit(oldp+97,(vlSymsp->TOP__top.__PVT__id_inst_ecall));
    bufp->fullBit(oldp+98,(vlSymsp->TOP__top.__PVT__id_inst_mret));
    bufp->fullBit(oldp+99,(vlSymsp->TOP__top.__PVT__inst_ebreak_out));
    bufp->fullSData(oldp+100,(vlSymsp->TOP__top.__PVT__csr_raddr),12);
    bufp->fullBit(oldp+101,(vlSymsp->TOP__top.__PVT__csr_wen));
    bufp->fullSData(oldp+102,(vlSymsp->TOP__top.__PVT__csr_waddr),12);
    bufp->fullBit(oldp+103,(vlSymsp->TOP__top.__PVT__trap_valid));
    bufp->fullIData(oldp+104,(vlSymsp->TOP__top.__PVT__trap_pc),32);
    bufp->fullSData(oldp+105,(vlSymsp->TOP__top__u_csr_file.__PVT__csr_raddr),12);
    bufp->fullBit(oldp+106,(vlSymsp->TOP__top__u_csr_file.__PVT__csr_wen));
    bufp->fullSData(oldp+107,(vlSymsp->TOP__top__u_csr_file.__PVT__csr_waddr),12);
    bufp->fullBit(oldp+108,(vlSymsp->TOP__top__u_csr_file.__PVT__trap_valid));
    bufp->fullIData(oldp+109,(vlSymsp->TOP__top__u_csr_file.__PVT__trap_pc),32);
    bufp->fullIData(oldp+110,(vlSymsp->TOP__top__u_reg_file.__PVT__rs1_data),32);
    bufp->fullIData(oldp+111,(vlSymsp->TOP__top__u_reg_file.__PVT__rs2_data),32);
    bufp->fullIData(oldp+112,(vlSymsp->TOP__top__u_execute.__PVT__pc_in),32);
    bufp->fullIData(oldp+113,(vlSymsp->TOP__top__u_execute.__PVT__op1_in),32);
    bufp->fullIData(oldp+114,(vlSymsp->TOP__top__u_execute.__PVT__op2_in),32);
    bufp->fullIData(oldp+115,(vlSymsp->TOP__top__u_execute.__PVT__rs1_data_in),32);
    bufp->fullIData(oldp+116,(vlSymsp->TOP__top__u_execute.__PVT__imm_in),32);
    bufp->fullCData(oldp+117,(vlSymsp->TOP__top__u_execute.__PVT__opcode_in),7);
    bufp->fullCData(oldp+118,(vlSymsp->TOP__top__u_execute.__PVT__funct3_in),3);
    bufp->fullCData(oldp+119,(vlSymsp->TOP__top__u_execute.__PVT__funct7_in),7);
    bufp->fullBit(oldp+120,(vlSymsp->TOP__top__u_execute.__PVT__inst_ebreak_in));
    bufp->fullSData(oldp+121,(vlSymsp->TOP__top__u_execute.__PVT__csr_addr_in),12);
    bufp->fullBit(oldp+122,(vlSymsp->TOP__top__u_execute.__PVT__inst_csrrw));
    bufp->fullBit(oldp+123,(vlSymsp->TOP__top__u_execute.__PVT__inst_csrrs));
    bufp->fullBit(oldp+124,(vlSymsp->TOP__top__u_execute.__PVT__inst_ecall));
    bufp->fullBit(oldp+125,(vlSymsp->TOP__top__u_execute.__PVT__inst_mret));
    bufp->fullSData(oldp+126,(vlSymsp->TOP__top__u_execute.__PVT__csr_raddr),12);
    bufp->fullBit(oldp+127,(vlSymsp->TOP__top__u_execute.__PVT__csr_wen));
    bufp->fullSData(oldp+128,(vlSymsp->TOP__top__u_execute.__PVT__csr_waddr),12);
    bufp->fullBit(oldp+129,(vlSymsp->TOP__top__u_execute.__PVT__trap_valid));
    bufp->fullIData(oldp+130,(vlSymsp->TOP__top__u_execute.__PVT__trap_pc),32);
    bufp->fullIData(oldp+131,(vlSymsp->TOP__top__u_execute.__PVT__alu_res),32);
    bufp->fullBit(oldp+132,(vlSymsp->TOP__top__u_execute.__PVT__branch_taken));
    bufp->fullIData(oldp+133,(vlSymsp->TOP__top__u_id2ex.__PVT__rs1_data_in),32);
    bufp->fullIData(oldp+134,(vlSymsp->TOP__top__u_id2ex.__PVT__rs2_data_in),32);
    bufp->fullIData(oldp+135,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_addr_out),32);
    bufp->fullIData(oldp+136,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_out),32);
    bufp->fullIData(oldp+137,(vlSymsp->TOP__top__u_id2ex.__PVT__op1_out),32);
    bufp->fullIData(oldp+138,(vlSymsp->TOP__top__u_id2ex.__PVT__op2_out),32);
    bufp->fullCData(oldp+139,(vlSymsp->TOP__top__u_id2ex.__PVT__rd_addr_out),5);
    bufp->fullIData(oldp+140,(vlSymsp->TOP__top__u_id2ex.__PVT__imm_out),32);
    bufp->fullCData(oldp+141,(vlSymsp->TOP__top__u_id2ex.__PVT__opcode_out),7);
    bufp->fullCData(oldp+142,(vlSymsp->TOP__top__u_id2ex.__PVT__funct3_out),3);
    bufp->fullCData(oldp+143,(vlSymsp->TOP__top__u_id2ex.__PVT__funct7_out),7);
    bufp->fullIData(oldp+144,(vlSymsp->TOP__top__u_id2ex.__PVT__rs1_data_out),32);
    bufp->fullIData(oldp+145,(vlSymsp->TOP__top__u_id2ex.__PVT__rs2_data_out),32);
    bufp->fullBit(oldp+146,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_ebreak_out));
    bufp->fullSData(oldp+147,(vlSymsp->TOP__top__u_id2ex.__PVT__csr_addr_out),12);
    bufp->fullBit(oldp+148,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_csrrw_out));
    bufp->fullBit(oldp+149,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_csrrs_out));
    bufp->fullBit(oldp+150,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_ecall_out));
    bufp->fullBit(oldp+151,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_mret_out));
    bufp->fullIData(oldp+152,(vlSymsp->TOP__top__u_ex2mem.__PVT__pc_in),32);
    bufp->fullIData(oldp+153,(vlSymsp->TOP__top__u_ex2mem.__PVT__rs2_data_in),32);
    bufp->fullCData(oldp+154,(vlSymsp->TOP__top__u_ex2mem.__PVT__rd_addr_in),5);
    bufp->fullCData(oldp+155,(vlSymsp->TOP__top__u_ex2mem.__PVT__opcode_in),7);
    bufp->fullCData(oldp+156,(vlSymsp->TOP__top__u_ex2mem.__PVT__funct3_in),3);
    bufp->fullIData(oldp+157,(vlSymsp->TOP__top.__PVT__ex_alu_result),32);
    bufp->fullBit(oldp+158,(vlSymsp->TOP__top.__PVT__ex_jump_flag));
    bufp->fullIData(oldp+159,(vlSymsp->TOP__top.__PVT__ex_jump_target),32);
    bufp->fullIData(oldp+160,(vlSymsp->TOP__top.__PVT__ex_alu_result_out),32);
    bufp->fullIData(oldp+161,(vlSymsp->TOP__top.__PVT__ex_rs2_data),32);
    bufp->fullCData(oldp+162,(vlSymsp->TOP__top.__PVT__ex_rd_addr),5);
    bufp->fullCData(oldp+163,(vlSymsp->TOP__top.__PVT__ex_opcode),7);
    bufp->fullCData(oldp+164,(vlSymsp->TOP__top.__PVT__ex_funct3),3);
    bufp->fullIData(oldp+165,(vlSymsp->TOP__top.__PVT__mem_rdata),32);
    bufp->fullIData(oldp+166,(vlSymsp->TOP__top.__PVT__mem_alu_result),32);
    bufp->fullIData(oldp+167,(vlSymsp->TOP__top.__PVT__mem_rdata_out),32);
    bufp->fullCData(oldp+168,(vlSymsp->TOP__top.__PVT__mem_rd_addr),5);
    bufp->fullCData(oldp+169,(vlSymsp->TOP__top.__PVT__mem_opcode),7);
    bufp->fullBit(oldp+170,(vlSymsp->TOP__top.__PVT__wb_wr_en));
    bufp->fullCData(oldp+171,(vlSymsp->TOP__top.__PVT__wb_wr_addr),5);
    bufp->fullIData(oldp+172,(vlSymsp->TOP__top.__PVT__wb_wr_data),32);
    bufp->fullIData(oldp+173,(vlSymsp->TOP__top.__PVT__csr_rdata),32);
    bufp->fullIData(oldp+174,(vlSymsp->TOP__top.__PVT__csr_wdata),32);
    bufp->fullIData(oldp+175,(vlSymsp->TOP__top__u_memory.__PVT__alu_result_in),32);
    bufp->fullIData(oldp+176,(vlSymsp->TOP__top__u_memory.__PVT__rs2_data_in),32);
    bufp->fullCData(oldp+177,(vlSymsp->TOP__top__u_memory.__PVT__opcode_in),7);
    bufp->fullCData(oldp+178,(vlSymsp->TOP__top__u_memory.__PVT__funct3_in),3);
    bufp->fullIData(oldp+179,(vlSymsp->TOP__top__u_memory.__PVT__mem_rdata_out),32);
    bufp->fullIData(oldp+180,(vlSymsp->TOP__top__u_memory.__PVT__rdata_raw),32);
    bufp->fullIData(oldp+181,(vlSymsp->TOP__top__u_writeback.__PVT__alu_result_in),32);
    bufp->fullIData(oldp+182,(vlSymsp->TOP__top__u_writeback.__PVT__mem_rdata_in),32);
    bufp->fullCData(oldp+183,(vlSymsp->TOP__top__u_writeback.__PVT__opcode_in),7);
    bufp->fullCData(oldp+184,(vlSymsp->TOP__top__u_writeback.__PVT__rd_addr_in),5);
    bufp->fullBit(oldp+185,(vlSymsp->TOP__top__u_writeback.__PVT__wb_en));
    bufp->fullCData(oldp+186,(vlSymsp->TOP__top__u_writeback.__PVT__wb_addr),5);
    bufp->fullIData(oldp+187,(vlSymsp->TOP__top__u_writeback.__PVT__wb_data),32);
    bufp->fullIData(oldp+188,(vlSymsp->TOP__top__u_csr_file.__PVT__csr_rdata),32);
    bufp->fullIData(oldp+189,(vlSymsp->TOP__top__u_csr_file.__PVT__csr_wdata),32);
    bufp->fullBit(oldp+190,(vlSymsp->TOP__top__u_reg_file.__PVT__wr_en));
    bufp->fullCData(oldp+191,(vlSymsp->TOP__top__u_reg_file.__PVT__wr_addr),5);
    bufp->fullIData(oldp+192,(vlSymsp->TOP__top__u_reg_file.__PVT__wr_data),32);
    bufp->fullIData(oldp+193,(vlSymsp->TOP__top__u_mem2wb.__PVT__alu_result_in),32);
    bufp->fullIData(oldp+194,(vlSymsp->TOP__top__u_mem2wb.__PVT__mem_rdata_in),32);
    bufp->fullCData(oldp+195,(vlSymsp->TOP__top__u_mem2wb.__PVT__rd_addr_in),5);
    bufp->fullCData(oldp+196,(vlSymsp->TOP__top__u_mem2wb.__PVT__opcode_in),7);
    bufp->fullIData(oldp+197,(vlSymsp->TOP__top__u_mem2wb.__PVT__alu_result_out),32);
    bufp->fullIData(oldp+198,(vlSymsp->TOP__top__u_mem2wb.__PVT__mem_rdata_out),32);
    bufp->fullCData(oldp+199,(vlSymsp->TOP__top__u_mem2wb.__PVT__rd_addr_out),5);
    bufp->fullCData(oldp+200,(vlSymsp->TOP__top__u_mem2wb.__PVT__opcode_out),7);
    bufp->fullIData(oldp+201,(vlSymsp->TOP__top__u_execute.__PVT__alu_result_out),32);
    bufp->fullBit(oldp+202,(vlSymsp->TOP__top__u_execute.__PVT__jump_flag_out));
    bufp->fullIData(oldp+203,(vlSymsp->TOP__top__u_execute.__PVT__jump_target_out),32);
    bufp->fullIData(oldp+204,(vlSymsp->TOP__top__u_execute.__PVT__csr_rdata),32);
    bufp->fullIData(oldp+205,(vlSymsp->TOP__top__u_execute.__PVT__csr_wdata),32);
    bufp->fullIData(oldp+206,(vlSymsp->TOP__top__u_ex2mem.__PVT__alu_result_in),32);
    bufp->fullIData(oldp+207,(vlSymsp->TOP__top__u_ex2mem.__PVT__alu_result_out),32);
    bufp->fullIData(oldp+208,(vlSymsp->TOP__top__u_ex2mem.__PVT__rs2_data_out),32);
    bufp->fullCData(oldp+209,(vlSymsp->TOP__top__u_ex2mem.__PVT__rd_addr_out),5);
    bufp->fullCData(oldp+210,(vlSymsp->TOP__top__u_ex2mem.__PVT__opcode_out),7);
    bufp->fullCData(oldp+211,(vlSymsp->TOP__top__u_ex2mem.__PVT__funct3_out),3);
    bufp->fullBit(oldp+212,(vlSymsp->TOP__top__u_pc_counter.__PVT__jump_en));
    bufp->fullIData(oldp+213,(vlSymsp->TOP__top__u_pc_counter.__PVT__jump_addr),32);
    bufp->fullIData(oldp+214,(vlSymsp->TOP__top.__PVT__trap_mtvec),32);
    bufp->fullIData(oldp+215,(vlSymsp->TOP__top.__PVT__trap_mepc),32);
    bufp->fullIData(oldp+216,(vlSymsp->TOP__top__u_csr_file.__PVT__trap_mtvec),32);
    bufp->fullIData(oldp+217,(vlSymsp->TOP__top__u_csr_file.__PVT__trap_mepc),32);
    bufp->fullIData(oldp+218,(vlSymsp->TOP__top__u_csr_file.__PVT__mstatus),32);
    bufp->fullIData(oldp+219,(vlSymsp->TOP__top__u_csr_file.__PVT__mtvec),32);
    bufp->fullIData(oldp+220,(vlSymsp->TOP__top__u_csr_file.__PVT__mepc),32);
    bufp->fullIData(oldp+221,(vlSymsp->TOP__top__u_csr_file.__PVT__mcause),32);
    bufp->fullQData(oldp+222,(vlSymsp->TOP__top__u_csr_file.__PVT__mcycle_cnt),64);
    bufp->fullIData(oldp+224,(vlSymsp->TOP__top__u_execute.__PVT__trap_mtvec),32);
    bufp->fullIData(oldp+225,(vlSymsp->TOP__top__u_execute.__PVT__trap_mepc),32);
    bufp->fullIData(oldp+226,(vlSymsp->TOP__top.debug_x10),32);
    bufp->fullIData(oldp+227,(vlSymsp->TOP__top.regs[0]),32);
    bufp->fullIData(oldp+228,(vlSymsp->TOP__top.regs[1]),32);
    bufp->fullIData(oldp+229,(vlSymsp->TOP__top.regs[2]),32);
    bufp->fullIData(oldp+230,(vlSymsp->TOP__top.regs[3]),32);
    bufp->fullIData(oldp+231,(vlSymsp->TOP__top.regs[4]),32);
    bufp->fullIData(oldp+232,(vlSymsp->TOP__top.regs[5]),32);
    bufp->fullIData(oldp+233,(vlSymsp->TOP__top.regs[6]),32);
    bufp->fullIData(oldp+234,(vlSymsp->TOP__top.regs[7]),32);
    bufp->fullIData(oldp+235,(vlSymsp->TOP__top.regs[8]),32);
    bufp->fullIData(oldp+236,(vlSymsp->TOP__top.regs[9]),32);
    bufp->fullIData(oldp+237,(vlSymsp->TOP__top.regs[10]),32);
    bufp->fullIData(oldp+238,(vlSymsp->TOP__top.regs[11]),32);
    bufp->fullIData(oldp+239,(vlSymsp->TOP__top.regs[12]),32);
    bufp->fullIData(oldp+240,(vlSymsp->TOP__top.regs[13]),32);
    bufp->fullIData(oldp+241,(vlSymsp->TOP__top.regs[14]),32);
    bufp->fullIData(oldp+242,(vlSymsp->TOP__top.regs[15]),32);
    bufp->fullIData(oldp+243,(vlSymsp->TOP__top__u_reg_file.__PVT__debug_x10),32);
    bufp->fullIData(oldp+244,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[0]),32);
    bufp->fullIData(oldp+245,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[1]),32);
    bufp->fullIData(oldp+246,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[2]),32);
    bufp->fullIData(oldp+247,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[3]),32);
    bufp->fullIData(oldp+248,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[4]),32);
    bufp->fullIData(oldp+249,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[5]),32);
    bufp->fullIData(oldp+250,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[6]),32);
    bufp->fullIData(oldp+251,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[7]),32);
    bufp->fullIData(oldp+252,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[8]),32);
    bufp->fullIData(oldp+253,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[9]),32);
    bufp->fullIData(oldp+254,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[10]),32);
    bufp->fullIData(oldp+255,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[11]),32);
    bufp->fullIData(oldp+256,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[12]),32);
    bufp->fullIData(oldp+257,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[13]),32);
    bufp->fullIData(oldp+258,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[14]),32);
    bufp->fullIData(oldp+259,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[15]),32);
    bufp->fullIData(oldp+260,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[0]),32);
    bufp->fullIData(oldp+261,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[1]),32);
    bufp->fullIData(oldp+262,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[2]),32);
    bufp->fullIData(oldp+263,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[3]),32);
    bufp->fullIData(oldp+264,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[4]),32);
    bufp->fullIData(oldp+265,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[5]),32);
    bufp->fullIData(oldp+266,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[6]),32);
    bufp->fullIData(oldp+267,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[7]),32);
    bufp->fullIData(oldp+268,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[8]),32);
    bufp->fullIData(oldp+269,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[9]),32);
    bufp->fullIData(oldp+270,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[10]),32);
    bufp->fullIData(oldp+271,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[11]),32);
    bufp->fullIData(oldp+272,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[12]),32);
    bufp->fullIData(oldp+273,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[13]),32);
    bufp->fullIData(oldp+274,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[14]),32);
    bufp->fullIData(oldp+275,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[15]),32);
    bufp->fullIData(oldp+276,(vlSymsp->TOP__top__u_reg_file.__PVT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+277,(vlSymsp->TOP__top.pc),32);
    bufp->fullIData(oldp+278,(vlSymsp->TOP__top__u_if2id.__PVT__instr_addr_in),32);
    bufp->fullIData(oldp+279,(vlSymsp->TOP__top__u_fetch.__PVT__pc_pointer),32);
    bufp->fullIData(oldp+280,(vlSymsp->TOP__top__u_pc_counter.__PVT__pc),32);
    bufp->fullIData(oldp+281,(vlSymsp->TOP__top__u_pc_counter.__PVT__pc_pointer),32);
    bufp->fullBit(oldp+282,(vlSelfRef.clk));
    bufp->fullBit(oldp+283,(vlSelfRef.rst_n));
    bufp->fullIData(oldp+284,(vlSelfRef.pc),32);
    bufp->fullIData(oldp+285,(vlSelfRef.instr),32);
    bufp->fullIData(oldp+286,(vlSelfRef.debug_x10),32);
    bufp->fullIData(oldp+287,(vlSelfRef.regs[0]),32);
    bufp->fullIData(oldp+288,(vlSelfRef.regs[1]),32);
    bufp->fullIData(oldp+289,(vlSelfRef.regs[2]),32);
    bufp->fullIData(oldp+290,(vlSelfRef.regs[3]),32);
    bufp->fullIData(oldp+291,(vlSelfRef.regs[4]),32);
    bufp->fullIData(oldp+292,(vlSelfRef.regs[5]),32);
    bufp->fullIData(oldp+293,(vlSelfRef.regs[6]),32);
    bufp->fullIData(oldp+294,(vlSelfRef.regs[7]),32);
    bufp->fullIData(oldp+295,(vlSelfRef.regs[8]),32);
    bufp->fullIData(oldp+296,(vlSelfRef.regs[9]),32);
    bufp->fullIData(oldp+297,(vlSelfRef.regs[10]),32);
    bufp->fullIData(oldp+298,(vlSelfRef.regs[11]),32);
    bufp->fullIData(oldp+299,(vlSelfRef.regs[12]),32);
    bufp->fullIData(oldp+300,(vlSelfRef.regs[13]),32);
    bufp->fullIData(oldp+301,(vlSelfRef.regs[14]),32);
    bufp->fullIData(oldp+302,(vlSelfRef.regs[15]),32);
}
