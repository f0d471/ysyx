// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_top.h"

VL_ATTR_COLD void Vtop_top___ctor_var_reset(Vtop_top* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vtop_top___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = 0;
    vlSelf->rst_n = 0;
    vlSelf->pc = 0;
    vlSelf->instr = 0;
    vlSelf->debug_x10 = 0;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->regs[__Vi0] = 0;
    }
    vlSelf->__PVT__instr_addr_out = 0;
    vlSelf->__PVT__instr_out = 0;
    vlSelf->__PVT__decode_rs1_addr = 0;
    vlSelf->__PVT__decode_rs2_addr = 0;
    vlSelf->__PVT__decode_rd_addr = 0;
    vlSelf->__PVT__decode_imm = 0;
    vlSelf->__PVT__decode_op1_sel = 0;
    vlSelf->__PVT__decode_op2_sel = 0;
    vlSelf->__PVT__decode_opcode = 0;
    vlSelf->__PVT__decode_funct3 = 0;
    vlSelf->__PVT__decode_funct7 = 0;
    vlSelf->__PVT__decode_csr_addr = 0;
    vlSelf->__PVT__decode_inst_csrrw = 0;
    vlSelf->__PVT__decode_inst_csrrs = 0;
    vlSelf->__PVT__decode_inst_ecall = 0;
    vlSelf->__PVT__decode_inst_mret = 0;
    vlSelf->__PVT__reg_rs1_data = 0;
    vlSelf->__PVT__reg_rs2_data = 0;
    vlSelf->__PVT__id_instr_addr_out = 0;
    vlSelf->__PVT__id_instr_out = 0;
    vlSelf->__PVT__id_op1_out = 0;
    vlSelf->__PVT__id_op2_out = 0;
    vlSelf->__PVT__id_rd_addr_out = 0;
    vlSelf->__PVT__id_imm_out = 0;
    vlSelf->__PVT__id_opcode_out = 0;
    vlSelf->__PVT__id_funct3_out = 0;
    vlSelf->__PVT__id_funct7_out = 0;
    vlSelf->__PVT__id_rs1_data = 0;
    vlSelf->__PVT__id_rs2_data = 0;
    vlSelf->__PVT__id_csr_addr = 0;
    vlSelf->__PVT__id_inst_csrrw = 0;
    vlSelf->__PVT__id_inst_csrrs = 0;
    vlSelf->__PVT__id_inst_ecall = 0;
    vlSelf->__PVT__id_inst_mret = 0;
    vlSelf->__PVT__ex_alu_result = 0;
    vlSelf->__PVT__ex_jump_flag = 0;
    vlSelf->__PVT__ex_jump_target = 0;
    vlSelf->__PVT__ex_alu_result_out = 0;
    vlSelf->__PVT__ex_rs2_data = 0;
    vlSelf->__PVT__ex_rd_addr = 0;
    vlSelf->__PVT__ex_opcode = 0;
    vlSelf->__PVT__ex_funct3 = 0;
    vlSelf->__PVT__mem_rdata = 0;
    vlSelf->__PVT__mem_alu_result = 0;
    vlSelf->__PVT__mem_rdata_out = 0;
    vlSelf->__PVT__mem_rd_addr = 0;
    vlSelf->__PVT__mem_opcode = 0;
    vlSelf->__PVT__wb_wr_en = 0;
    vlSelf->__PVT__wb_wr_addr = 0;
    vlSelf->__PVT__wb_wr_data = 0;
    vlSelf->__PVT__inst_ebreak = 0;
    vlSelf->__PVT__inst_ebreak_out = 0;
    vlSelf->__PVT__csr_raddr = 0;
    vlSelf->__PVT__csr_rdata = 0;
    vlSelf->__PVT__csr_wen = 0;
    vlSelf->__PVT__csr_waddr = 0;
    vlSelf->__PVT__csr_wdata = 0;
    vlSelf->__PVT__trap_valid = 0;
    vlSelf->__PVT__trap_pc = 0;
    vlSelf->__PVT__trap_cause = 0;
    vlSelf->__PVT__trap_mtvec = 0;
    vlSelf->__PVT__trap_mepc = 0;
    vlSelf->__Vcellinp__u_csr_file__rst = 0;
}
