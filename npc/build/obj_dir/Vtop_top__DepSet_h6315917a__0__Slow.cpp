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
    vlSelf->__PVT__if2id_up_ready = 0;
    vlSelf->__PVT__if2id_dn_valid = 0;
    vlSelf->__PVT__id2ex_up_ready = 0;
    vlSelf->__PVT__id2ex_dn_valid = 0;
    vlSelf->__PVT__ex2mem_up_ready = 0;
    vlSelf->__PVT__ex2mem_dn_valid = 0;
    vlSelf->__PVT__mem2wb_up_ready = 0;
    vlSelf->__PVT__mem2wb_dn_valid = 0;
    vlSelf->__PVT__if_id_up = 0;
    vlSelf->__PVT__if_id_dn = 0;
    VL_ZERO_RESET_W(263, vlSelf->__PVT__id_ex_up);
    VL_ZERO_RESET_W(263, vlSelf->__PVT__id_ex_dn);
    VL_ZERO_RESET_W(79, vlSelf->__PVT__ex_mem_up);
    VL_ZERO_RESET_W(79, vlSelf->__PVT__ex_mem_dn);
    VL_ZERO_RESET_W(76, vlSelf->__PVT__mem_wb_up);
    VL_ZERO_RESET_W(76, vlSelf->__PVT__mem_wb_dn);
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
    vlSelf->__PVT__decode_inst_ebreak = 0;
    vlSelf->__PVT__reg_rs1_data = 0;
    vlSelf->__PVT__reg_rs2_data = 0;
    vlSelf->__PVT__fwd_rs1_data = 0;
    vlSelf->__PVT__fwd_rs2_data = 0;
    vlSelf->__PVT__id_op1 = 0;
    vlSelf->__PVT__id_op2 = 0;
    vlSelf->__PVT__ex_alu_result = 0;
    vlSelf->__PVT__ex_jump_flag = 0;
    vlSelf->__PVT__ex_jump_target = 0;
    vlSelf->__PVT__mem_rdata = 0;
    vlSelf->__PVT__wb_wr_en = 0;
    vlSelf->__PVT__wb_wr_addr = 0;
    vlSelf->__PVT__wb_wr_data = 0;
    vlSelf->__PVT__load_stall = 0;
    vlSelf->__PVT__fwd_rs1_sel = 0;
    vlSelf->__PVT__fwd_rs2_sel = 0;
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
    vlSelf->__Vcellinp__u_pc_counter__jump_addr = 0;
    vlSelf->__Vcellinp__u_pc_counter__jump_en = 0;
    vlSelf->__Vcellinp__u_decode__instr_in = 0;
    vlSelf->__Vcellinp__u_decode__instr_addr_in = 0;
    vlSelf->__Vcellinp__u_hazard__ex_rd_addr = 0;
    vlSelf->__Vcellinp__u_hazard__ex_opcode = 0;
    vlSelf->__Vcellinp__u_forward__wb_opcode = 0;
    vlSelf->__Vcellinp__u_forward__wb_rd_addr = 0;
    vlSelf->__Vcellinp__u_forward__mem_opcode = 0;
    vlSelf->__Vcellinp__u_forward__mem_rd_addr = 0;
    vlSelf->__Vcellinp__u_forward__ex_stage_opcode = 0;
    vlSelf->__Vcellinp__u_forward__ex_stage_rd_addr = 0;
    vlSelf->__Vcellinp__u_id2ex__flush = 0;
    vlSelf->__Vcellinp__u_execute__inst_mret = 0;
    vlSelf->__Vcellinp__u_execute__inst_ecall = 0;
    vlSelf->__Vcellinp__u_execute__inst_csrrs = 0;
    vlSelf->__Vcellinp__u_execute__inst_csrrw = 0;
    vlSelf->__Vcellinp__u_execute__csr_addr_in = 0;
    vlSelf->__Vcellinp__u_execute__inst_ebreak_in = 0;
    vlSelf->__Vcellinp__u_execute__funct7_in = 0;
    vlSelf->__Vcellinp__u_execute__funct3_in = 0;
    vlSelf->__Vcellinp__u_execute__opcode_in = 0;
    vlSelf->__Vcellinp__u_execute__imm_in = 0;
    vlSelf->__Vcellinp__u_execute__rs1_data_in = 0;
    vlSelf->__Vcellinp__u_execute__op2_in = 0;
    vlSelf->__Vcellinp__u_execute__op1_in = 0;
    vlSelf->__Vcellinp__u_execute__pc_in = 0;
    vlSelf->__Vcellinp__u_memory__funct3_in = 0;
    vlSelf->__Vcellinp__u_memory__opcode_in = 0;
    vlSelf->__Vcellinp__u_memory__rs2_data_in = 0;
    vlSelf->__Vcellinp__u_memory__alu_result_in = 0;
    vlSelf->__Vcellinp__u_writeback__rd_addr_in = 0;
    vlSelf->__Vcellinp__u_writeback__opcode_in = 0;
    vlSelf->__Vcellinp__u_writeback__mem_rdata_in = 0;
    vlSelf->__Vcellinp__u_writeback__alu_result_in = 0;
    vlSelf->__Vcellinp__u_csr_file__rst = 0;
}
