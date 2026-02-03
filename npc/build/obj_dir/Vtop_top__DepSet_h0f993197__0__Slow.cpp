// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_top.h"

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__0(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.debug_x10 = vlSymsp->TOP__top__u_reg_file.__PVT__debug_x10;
    vlSelfRef.regs[0xfU] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [0xfU];
    vlSelfRef.regs[0xeU] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [0xeU];
    vlSelfRef.regs[0xdU] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [0xdU];
    vlSelfRef.regs[0xcU] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [0xcU];
    vlSelfRef.regs[0xbU] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [0xbU];
    vlSelfRef.regs[0xaU] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [0xaU];
    vlSelfRef.regs[9U] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [9U];
    vlSelfRef.regs[8U] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [8U];
    vlSelfRef.regs[7U] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [7U];
    vlSelfRef.regs[6U] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [6U];
    vlSelfRef.regs[5U] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [5U];
    vlSelfRef.regs[4U] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [4U];
    vlSelfRef.regs[3U] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [3U];
    vlSelfRef.regs[2U] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [2U];
    vlSelfRef.regs[1U] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [1U];
    vlSelfRef.regs[0U] = vlSymsp->TOP__top__u_reg_file.__PVT__regs
        [0U];
    vlSymsp->TOP__top__u_pc_counter.__PVT__clk = vlSelfRef.clk;
    vlSymsp->TOP__top__u_fetch.__PVT__clk = vlSelfRef.clk;
    vlSymsp->TOP__top__u_reg_file.__PVT__clk = vlSelfRef.clk;
    vlSymsp->TOP__top__u_memory.__PVT__clk = vlSelfRef.clk;
    vlSymsp->TOP__top__u_pc_counter.__PVT__rst_n = vlSelfRef.rst_n;
    vlSymsp->TOP__top__u_reg_file.__PVT__rst_n = vlSelfRef.rst_n;
    vlSymsp->TOP__top__u_memory.__PVT__rst_n = vlSelfRef.rst_n;
    vlSymsp->TOP__top__u_fetch.__PVT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.pc = vlSymsp->TOP__top__u_pc_counter.__PVT__pc;
    vlSymsp->TOP__top__u_if2id.__PVT__instr_addr_in 
        = vlSelfRef.pc;
    vlSymsp->TOP__top__u_fetch.__PVT__pc_pointer = vlSelfRef.pc;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__1(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.instr = vlSymsp->TOP__top__u_fetch.__PVT__instr_out;
    vlSymsp->TOP__top__u_if2id.__PVT__instr_in = vlSelfRef.instr;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__2(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__instr_addr_out = vlSymsp->TOP__top__u_if2id.__PVT__instr_addr_out;
    vlSelfRef.__PVT__instr_out = vlSymsp->TOP__top__u_if2id.__PVT__instr_out;
    vlSymsp->TOP__top__u_decode.__PVT__instr_addr_in 
        = vlSelfRef.__PVT__instr_addr_out;
    vlSymsp->TOP__top__u_id2ex.__PVT__instr_addr_in 
        = vlSelfRef.__PVT__instr_addr_out;
    vlSymsp->TOP__top__u_id2ex.__PVT__instr_in = vlSelfRef.__PVT__instr_out;
    vlSymsp->TOP__top__u_decode.__PVT__instr_in = vlSelfRef.__PVT__instr_out;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__3(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__3\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__decode_rd_addr = vlSymsp->TOP__top__u_decode.__PVT__rd_addr_out;
    vlSelfRef.__PVT__decode_funct3 = vlSymsp->TOP__top__u_decode.__PVT__funct3_out;
    vlSelfRef.__PVT__decode_funct7 = vlSymsp->TOP__top__u_decode.__PVT__funct7_out;
    vlSelfRef.__PVT__inst_ebreak = vlSymsp->TOP__top__u_decode.__PVT__inst_ebreak;
    vlSelfRef.__PVT__decode_opcode = vlSymsp->TOP__top__u_decode.__PVT__opcode_out;
    vlSelfRef.__PVT__decode_op1_sel = vlSymsp->TOP__top__u_decode.__PVT__op1_sel_out;
    vlSelfRef.__PVT__decode_op2_sel = vlSymsp->TOP__top__u_decode.__PVT__op2_sel_out;
    vlSelfRef.__PVT__decode_rs1_addr = vlSymsp->TOP__top__u_decode.__PVT__rd_rs1_addr;
    vlSelfRef.__PVT__decode_rs2_addr = vlSymsp->TOP__top__u_decode.__PVT__rd_rs2_addr;
    vlSelfRef.__PVT__decode_imm = vlSymsp->TOP__top__u_decode.__PVT__imm_out;
    vlSymsp->TOP__top__u_id2ex.__PVT__rd_addr_in = vlSelfRef.__PVT__decode_rd_addr;
    vlSymsp->TOP__top__u_id2ex.__PVT__funct3_in = vlSelfRef.__PVT__decode_funct3;
    vlSymsp->TOP__top__u_id2ex.__PVT__funct7_in = vlSelfRef.__PVT__decode_funct7;
    vlSymsp->TOP__top__u_id2ex.__PVT__inst_ebreak_in 
        = vlSelfRef.__PVT__inst_ebreak;
    vlSymsp->TOP__top__u_id2ex.__PVT__opcode_in = vlSelfRef.__PVT__decode_opcode;
    vlSymsp->TOP__top__u_id2ex.__PVT__op1_sel_in = vlSelfRef.__PVT__decode_op1_sel;
    vlSymsp->TOP__top__u_id2ex.__PVT__op2_sel_in = vlSelfRef.__PVT__decode_op2_sel;
    vlSymsp->TOP__top__u_reg_file.__PVT__rs1_addr = vlSelfRef.__PVT__decode_rs1_addr;
    vlSymsp->TOP__top__u_reg_file.__PVT__rs2_addr = vlSelfRef.__PVT__decode_rs2_addr;
    vlSymsp->TOP__top__u_id2ex.__PVT__imm_in = vlSelfRef.__PVT__decode_imm;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__4(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__4\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__reg_rs1_data = vlSymsp->TOP__top__u_reg_file.__PVT__rs1_data;
    vlSelfRef.__PVT__reg_rs2_data = vlSymsp->TOP__top__u_reg_file.__PVT__rs2_data;
    vlSymsp->TOP__top__u_id2ex.__PVT__rs1_data_in = vlSelfRef.__PVT__reg_rs1_data;
    vlSymsp->TOP__top__u_id2ex.__PVT__rs2_data_in = vlSelfRef.__PVT__reg_rs2_data;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__5(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__5\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__id_instr_out = vlSymsp->TOP__top__u_id2ex.__PVT__instr_out;
    vlSelfRef.__PVT__inst_ebreak_out = vlSymsp->TOP__top__u_id2ex.__PVT__inst_ebreak_out;
    vlSelfRef.__PVT__id_imm_out = vlSymsp->TOP__top__u_id2ex.__PVT__imm_out;
    vlSelfRef.__PVT__id_rs1_data = vlSymsp->TOP__top__u_id2ex.__PVT__rs1_data_out;
    vlSelfRef.__PVT__id_instr_addr_out = vlSymsp->TOP__top__u_id2ex.__PVT__instr_addr_out;
    vlSelfRef.__PVT__id_rd_addr_out = vlSymsp->TOP__top__u_id2ex.__PVT__rd_addr_out;
    vlSelfRef.__PVT__id_rs2_data = vlSymsp->TOP__top__u_id2ex.__PVT__rs2_data_out;
    vlSelfRef.__PVT__id_funct7_out = vlSymsp->TOP__top__u_id2ex.__PVT__funct7_out;
    vlSelfRef.__PVT__id_op2_out = vlSymsp->TOP__top__u_id2ex.__PVT__op2_out;
    vlSelfRef.__PVT__id_op1_out = vlSymsp->TOP__top__u_id2ex.__PVT__op1_out;
    vlSelfRef.__PVT__id_funct3_out = vlSymsp->TOP__top__u_id2ex.__PVT__funct3_out;
    vlSelfRef.__PVT__id_opcode_out = vlSymsp->TOP__top__u_id2ex.__PVT__opcode_out;
    vlSymsp->TOP__top__u_execute.__PVT__inst_ebreak_in 
        = vlSelfRef.__PVT__inst_ebreak_out;
    vlSymsp->TOP__top__u_execute.__PVT__imm_in = vlSelfRef.__PVT__id_imm_out;
    vlSymsp->TOP__top__u_execute.__PVT__rs1_data_in 
        = vlSelfRef.__PVT__id_rs1_data;
    vlSymsp->TOP__top__u_ex2mem.__PVT__pc_in = vlSelfRef.__PVT__id_instr_addr_out;
    vlSymsp->TOP__top__u_execute.__PVT__pc_in = vlSelfRef.__PVT__id_instr_addr_out;
    vlSymsp->TOP__top__u_ex2mem.__PVT__rd_addr_in = vlSelfRef.__PVT__id_rd_addr_out;
    vlSymsp->TOP__top__u_ex2mem.__PVT__rs2_data_in 
        = vlSelfRef.__PVT__id_rs2_data;
    vlSymsp->TOP__top__u_execute.__PVT__funct7_in = vlSelfRef.__PVT__id_funct7_out;
    vlSymsp->TOP__top__u_execute.__PVT__op2_in = vlSelfRef.__PVT__id_op2_out;
    vlSymsp->TOP__top__u_execute.__PVT__op1_in = vlSelfRef.__PVT__id_op1_out;
    vlSymsp->TOP__top__u_ex2mem.__PVT__funct3_in = vlSelfRef.__PVT__id_funct3_out;
    vlSymsp->TOP__top__u_execute.__PVT__funct3_in = vlSelfRef.__PVT__id_funct3_out;
    vlSymsp->TOP__top__u_ex2mem.__PVT__opcode_in = vlSelfRef.__PVT__id_opcode_out;
    vlSymsp->TOP__top__u_execute.__PVT__opcode_in = vlSelfRef.__PVT__id_opcode_out;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__6(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__6\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__ex_jump_flag = vlSymsp->TOP__top__u_execute.__PVT__jump_flag_out;
    vlSelfRef.__PVT__ex_jump_target = vlSymsp->TOP__top__u_execute.__PVT__jump_target_out;
    vlSelfRef.__PVT__ex_alu_result = vlSymsp->TOP__top__u_execute.__PVT__alu_result_out;
    vlSymsp->TOP__top__u_pc_counter.__PVT__jump_en 
        = vlSelfRef.__PVT__ex_jump_flag;
    vlSymsp->TOP__top__u_pc_counter.__PVT__jump_addr 
        = vlSelfRef.__PVT__ex_jump_target;
    vlSymsp->TOP__top__u_ex2mem.__PVT__alu_result_in 
        = vlSelfRef.__PVT__ex_alu_result;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__7(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__7\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__ex_rs2_data = vlSymsp->TOP__top__u_ex2mem.__PVT__rs2_data_out;
    vlSelfRef.__PVT__ex_rd_addr = vlSymsp->TOP__top__u_ex2mem.__PVT__rd_addr_out;
    vlSelfRef.__PVT__ex_funct3 = vlSymsp->TOP__top__u_ex2mem.__PVT__funct3_out;
    vlSelfRef.__PVT__ex_alu_result_out = vlSymsp->TOP__top__u_ex2mem.__PVT__alu_result_out;
    vlSelfRef.__PVT__ex_opcode = vlSymsp->TOP__top__u_ex2mem.__PVT__opcode_out;
    vlSymsp->TOP__top__u_memory.__PVT__rs2_data_in 
        = vlSelfRef.__PVT__ex_rs2_data;
    vlSymsp->TOP__top__u_mem2wb.__PVT__rd_addr_in = vlSelfRef.__PVT__ex_rd_addr;
    vlSymsp->TOP__top__u_memory.__PVT__funct3_in = vlSelfRef.__PVT__ex_funct3;
    vlSymsp->TOP__top__u_mem2wb.__PVT__alu_result_in 
        = vlSelfRef.__PVT__ex_alu_result_out;
    vlSymsp->TOP__top__u_memory.__PVT__alu_result_in 
        = vlSelfRef.__PVT__ex_alu_result_out;
    vlSymsp->TOP__top__u_mem2wb.__PVT__opcode_in = vlSelfRef.__PVT__ex_opcode;
    vlSymsp->TOP__top__u_memory.__PVT__opcode_in = vlSelfRef.__PVT__ex_opcode;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__8(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__8\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__mem_rdata = vlSymsp->TOP__top__u_memory.__PVT__mem_rdata_out;
    vlSymsp->TOP__top__u_mem2wb.__PVT__mem_rdata_in 
        = vlSelfRef.__PVT__mem_rdata;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__9(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__9\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__mem_rd_addr = vlSymsp->TOP__top__u_mem2wb.__PVT__rd_addr_out;
    vlSelfRef.__PVT__mem_alu_result = vlSymsp->TOP__top__u_mem2wb.__PVT__alu_result_out;
    vlSelfRef.__PVT__mem_rdata_out = vlSymsp->TOP__top__u_mem2wb.__PVT__mem_rdata_out;
    vlSelfRef.__PVT__mem_opcode = vlSymsp->TOP__top__u_mem2wb.__PVT__opcode_out;
    vlSymsp->TOP__top__u_writeback.__PVT__rd_addr_in 
        = vlSelfRef.__PVT__mem_rd_addr;
    vlSymsp->TOP__top__u_writeback.__PVT__alu_result_in 
        = vlSelfRef.__PVT__mem_alu_result;
    vlSymsp->TOP__top__u_writeback.__PVT__mem_rdata_in 
        = vlSelfRef.__PVT__mem_rdata_out;
    vlSymsp->TOP__top__u_writeback.__PVT__opcode_in 
        = vlSelfRef.__PVT__mem_opcode;
}

VL_ATTR_COLD void Vtop_top___stl_sequent__TOP__top__10(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___stl_sequent__TOP__top__10\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__wb_wr_addr = vlSymsp->TOP__top__u_writeback.__PVT__wb_addr;
    vlSelfRef.__PVT__wb_wr_en = vlSymsp->TOP__top__u_writeback.__PVT__wb_en;
    vlSelfRef.__PVT__wb_wr_data = vlSymsp->TOP__top__u_writeback.__PVT__wb_data;
    vlSymsp->TOP__top__u_reg_file.__PVT__wr_addr = vlSelfRef.__PVT__wb_wr_addr;
    vlSymsp->TOP__top__u_reg_file.__PVT__wr_en = vlSelfRef.__PVT__wb_wr_en;
    vlSymsp->TOP__top__u_reg_file.__PVT__wr_data = vlSelfRef.__PVT__wb_wr_data;
}
