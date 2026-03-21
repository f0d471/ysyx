// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_core.h"

VL_ATTR_COLD void Vtop_core___eval_initial__TOP__top__u_core(Vtop_core* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_core___eval_initial__TOP__top__u_core\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__top__u_core__u_if2id.__PVT__up_valid = 1U;
    vlSymsp->TOP__top__u_core__u_id2ex.__PVT__stall = 0U;
    vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__stall = 0U;
    vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__flush = 0U;
    vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__dn_ready = 1U;
    vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__stall = 0U;
    vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__flush = 0U;
}

VL_ATTR_COLD void Vtop_core___stl_sequent__TOP__top__u_core__0(Vtop_core* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_core___stl_sequent__TOP__top__u_core__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__trap_cause = vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_cause;
    vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_cause 
        = vlSelfRef.__PVT__trap_cause;
}

VL_ATTR_COLD void Vtop_core___stl_sequent__TOP__top__u_core__1(Vtop_core* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_core___stl_sequent__TOP__top__u_core__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    vlSelfRef.__PVT__if2id_dn_valid = vlSymsp->TOP__top__u_core__u_if2id.__PVT__dn_valid;
    vlSelfRef.__Vcellout__u_if2id__dn_data = vlSymsp->TOP__top__u_core__u_if2id.__PVT__dn_data;
    vlSelfRef.__PVT__id2ex_dn_valid = vlSymsp->TOP__top__u_core__u_id2ex.__PVT__dn_valid;
    VL_ASSIGN_W(263,vlSelfRef.__Vcellout__u_id2ex__dn_data, vlSymsp->TOP__top__u_core__u_id2ex.__PVT__dn_data);
    vlSelfRef.__PVT__ex2mem_dn_valid = vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__dn_valid;
    VL_ASSIGN_W(143,vlSelfRef.__Vcellout__u_ex2mem__dn_data, vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__dn_data);
    vlSelfRef.__PVT__mem2wb_dn_valid = vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__dn_valid;
    vlSelfRef.__PVT__mem2wb_up_ready = vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__up_ready;
    VL_ASSIGN_W(140,vlSelfRef.__Vcellout__u_mem2wb__dn_data, vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__dn_data);
    vlSelfRef.__PVT__trap_mtvec = vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_mtvec;
    vlSelfRef.__PVT__trap_mepc = vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_mepc;
    vlSelfRef.__PVT__pc = vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__pc;
    vlSelfRef.__PVT__regs[0xfU] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [0xfU];
    vlSelfRef.__PVT__regs[0xeU] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [0xeU];
    vlSelfRef.__PVT__regs[0xdU] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [0xdU];
    vlSelfRef.__PVT__regs[0xcU] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [0xcU];
    vlSelfRef.__PVT__regs[0xbU] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [0xbU];
    vlSelfRef.__PVT__regs[0xaU] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [0xaU];
    vlSelfRef.__PVT__regs[9U] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [9U];
    vlSelfRef.__PVT__regs[8U] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [8U];
    vlSelfRef.__PVT__regs[7U] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [7U];
    vlSelfRef.__PVT__regs[6U] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [6U];
    vlSelfRef.__PVT__regs[5U] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [5U];
    vlSelfRef.__PVT__regs[4U] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [4U];
    vlSelfRef.__PVT__regs[3U] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [3U];
    vlSelfRef.__PVT__regs[2U] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [2U];
    vlSelfRef.__PVT__regs[1U] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [1U];
    vlSelfRef.__PVT__regs[0U] = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs
        [0U];
    vlSymsp->TOP__top__u_core__u_id2ex.__PVT__up_valid 
        = vlSelfRef.__PVT__if2id_dn_valid;
    vlSelfRef.__PVT__if_id_dn = vlSelfRef.__Vcellout__u_if2id__dn_data;
    vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__up_valid 
        = vlSelfRef.__PVT__id2ex_dn_valid;
    VL_ASSIGN_W(263,vlSelfRef.__PVT__id_ex_dn, vlSelfRef.__Vcellout__u_id2ex__dn_data);
    vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__up_valid 
        = vlSelfRef.__PVT__ex2mem_dn_valid;
    VL_ASSIGN_W(143,vlSelfRef.__PVT__ex_mem_dn, vlSelfRef.__Vcellout__u_ex2mem__dn_data);
    vlSelfRef.__PVT__debug_wb_have = vlSelfRef.__PVT__mem2wb_dn_valid;
    vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__dn_ready 
        = vlSelfRef.__PVT__mem2wb_up_ready;
    VL_ASSIGN_W(140,vlSelfRef.__PVT__mem_wb_dn, vlSelfRef.__Vcellout__u_mem2wb__dn_data);
    vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_mtvec 
        = vlSelfRef.__PVT__trap_mtvec;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_mepc 
        = vlSelfRef.__PVT__trap_mepc;
    vlSymsp->TOP__top__u_core__u_fetch.__PVT__pc_pointer 
        = vlSelfRef.__PVT__pc;
    vlSelfRef.__Vcellinp__u_decode__instr_addr_in = 
        VL_SEL_IQII(64, vlSelfRef.__PVT__if_id_dn, 0x20U, 0x20U);
    vlSelfRef.__Vcellinp__u_decode__instr_in = VL_SEL_IQII(64, vlSelfRef.__PVT__if_id_dn, 0U, 0x20U);
    vlSelfRef.__Vcellinp__u_execute__inst_ebreak_in 
        = (1U & VL_BITSEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0U));
    VL_ASSIGNSEL_WQ(143,44,3U, vlSelfRef.__PVT__ex_mem_up, 
                    VL_CONCAT_QII(44,32,12, VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x11U, 0x20U), 
                                  VL_CONCAT_III(12,5,7, 
                                                (0x1fU 
                                                 & VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x82U, 5U)), 
                                                (0x7fU 
                                                 & VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x5bU, 7U)))));
    VL_ASSIGNSEL_WI(143,3,0U, vlSelfRef.__PVT__ex_mem_up, 
                    (7U & VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x58U, 3U)));
    vlSelfRef.__Vcellinp__u_hazard__ex_opcode = (0x7fU 
                                                 & VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x5bU, 7U));
    vlSelfRef.__Vcellinp__u_execute__inst_mret = (1U 
                                                  & VL_BITSEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 1U));
    vlSelfRef.__Vcellinp__u_execute__imm_in = VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x62U, 0x20U);
    vlSelfRef.__Vcellinp__u_execute__rs1_data_in = 
        VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x31U, 0x20U);
    vlSelfRef.__Vcellinp__u_execute__inst_ecall = (1U 
                                                   & VL_BITSEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 2U));
    vlSelfRef.__Vcellinp__u_execute__pc_in = VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0xe7U, 0x20U);
    vlSelfRef.__Vcellinp__u_hazard__ex_rd_addr = (0x1fU 
                                                  & VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x82U, 5U));
    vlSelfRef.__Vcellinp__u_execute__funct7_in = (0x7fU 
                                                  & VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x51U, 7U));
    vlSelfRef.__Vcellinp__u_execute__inst_csrrs = (1U 
                                                   & VL_BITSEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 3U));
    vlSelfRef.__Vcellinp__u_execute__inst_csrrw = (1U 
                                                   & VL_BITSEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 4U));
    vlSelfRef.__Vcellinp__u_execute__csr_addr_in = 
        (0xfffU & VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 5U, 0xcU));
    vlSelfRef.__Vcellinp__u_execute__funct3_in = (7U 
                                                  & VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x58U, 3U));
    vlSelfRef.__Vcellinp__u_execute__op2_in = VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x87U, 0x20U);
    vlSelfRef.__Vcellinp__u_execute__op1_in = VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0xa7U, 0x20U);
    vlSelfRef.__Vcellinp__u_execute__opcode_in = (0x7fU 
                                                  & VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x5bU, 7U));
    vlSelfRef.__Vcellinp__u_forward__ex_stage_opcode 
        = (0x7fU & VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x5bU, 7U));
    vlSelfRef.__Vcellinp__u_forward__ex_stage_rd_addr 
        = (0x1fU & VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0x82U, 5U));
    vlSelfRef.__Vcellinp__u_memory__rs2_data_in = VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 0xfU, 0x20U);
    VL_CONCAT_WQI(96,64,32, __Vtemp_1, VL_CONCAT_QII(64,32,32, 
                                                     VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 0x6fU, 0x20U), 
                                                     VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 0x4fU, 0x20U)), 
                  VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 0x2fU, 0x20U));
    VL_ASSIGNSEL_WW(140,96,0x2cU, vlSelfRef.__PVT__mem_wb_up, __Vtemp_1);
    vlSelfRef.__Vcellinp__u_memory__funct3_in = (7U 
                                                 & VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 0U, 3U));
    vlSelfRef.__Vcellinp__u_memory__opcode_in = (0x7fU 
                                                 & VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 3U, 7U));
    vlSelfRef.__Vcellinp__u_memory__alu_result_in = 
        VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 0x2fU, 0x20U);
    vlSelfRef.__Vcellinp__u_forward__mem_opcode = (0x7fU 
                                                   & VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 3U, 7U));
    vlSelfRef.__Vcellinp__u_forward__mem_rd_addr = 
        (0x1fU & VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 0xaU, 5U));
    vlSelfRef.__PVT__debug_wb_pc = VL_SEL_IWII(140, vlSelfRef.__PVT__mem_wb_dn, 0x6cU, 0x20U);
    vlSelfRef.__PVT__debug_wb_instr = VL_SEL_IWII(140, vlSelfRef.__PVT__mem_wb_dn, 0x4cU, 0x20U);
    vlSelfRef.__Vcellinp__u_writeback__rd_addr_in = 
        (0x1fU & VL_SEL_IWII(140, vlSelfRef.__PVT__mem_wb_dn, 7U, 5U));
    vlSelfRef.__Vcellinp__u_writeback__opcode_in = 
        (0x7fU & VL_SEL_IWII(140, vlSelfRef.__PVT__mem_wb_dn, 0U, 7U));
    vlSelfRef.__Vcellinp__u_writeback__mem_rdata_in 
        = VL_SEL_IWII(140, vlSelfRef.__PVT__mem_wb_dn, 0xcU, 0x20U);
    vlSelfRef.__Vcellinp__u_writeback__alu_result_in 
        = VL_SEL_IWII(140, vlSelfRef.__PVT__mem_wb_dn, 0x2cU, 0x20U);
    vlSelfRef.__Vcellinp__u_forward__wb_opcode = (0x7fU 
                                                  & VL_SEL_IWII(140, vlSelfRef.__PVT__mem_wb_dn, 0U, 7U));
    vlSelfRef.__Vcellinp__u_forward__wb_rd_addr = (0x1fU 
                                                   & VL_SEL_IWII(140, vlSelfRef.__PVT__mem_wb_dn, 7U, 5U));
    vlSymsp->TOP__top__u_core__u_decode.__PVT__instr_addr_in 
        = vlSelfRef.__Vcellinp__u_decode__instr_addr_in;
    vlSymsp->TOP__top__u_core__u_decode.__PVT__instr_in 
        = vlSelfRef.__Vcellinp__u_decode__instr_in;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_ebreak_in 
        = vlSelfRef.__Vcellinp__u_execute__inst_ebreak_in;
    vlSymsp->TOP__top__u_core__u_hazard.__PVT__ex_opcode 
        = vlSelfRef.__Vcellinp__u_hazard__ex_opcode;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_mret 
        = vlSelfRef.__Vcellinp__u_execute__inst_mret;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__imm_in 
        = vlSelfRef.__Vcellinp__u_execute__imm_in;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__rs1_data_in 
        = vlSelfRef.__Vcellinp__u_execute__rs1_data_in;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_ecall 
        = vlSelfRef.__Vcellinp__u_execute__inst_ecall;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__pc_in 
        = vlSelfRef.__Vcellinp__u_execute__pc_in;
    vlSymsp->TOP__top__u_core__u_hazard.__PVT__ex_rd_addr 
        = vlSelfRef.__Vcellinp__u_hazard__ex_rd_addr;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__funct7_in 
        = vlSelfRef.__Vcellinp__u_execute__funct7_in;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_csrrs 
        = vlSelfRef.__Vcellinp__u_execute__inst_csrrs;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_csrrw 
        = vlSelfRef.__Vcellinp__u_execute__inst_csrrw;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_addr_in 
        = vlSelfRef.__Vcellinp__u_execute__csr_addr_in;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__funct3_in 
        = vlSelfRef.__Vcellinp__u_execute__funct3_in;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__op2_in 
        = vlSelfRef.__Vcellinp__u_execute__op2_in;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__op1_in 
        = vlSelfRef.__Vcellinp__u_execute__op1_in;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__opcode_in 
        = vlSelfRef.__Vcellinp__u_execute__opcode_in;
    vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_stage_opcode 
        = vlSelfRef.__Vcellinp__u_forward__ex_stage_opcode;
    vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_stage_rd_addr 
        = vlSelfRef.__Vcellinp__u_forward__ex_stage_rd_addr;
    vlSymsp->TOP__top__u_core__u_memory.__PVT__rs2_data_in 
        = vlSelfRef.__Vcellinp__u_memory__rs2_data_in;
    vlSymsp->TOP__top__u_core__u_memory.__PVT__funct3_in 
        = vlSelfRef.__Vcellinp__u_memory__funct3_in;
    vlSymsp->TOP__top__u_core__u_memory.__PVT__opcode_in 
        = vlSelfRef.__Vcellinp__u_memory__opcode_in;
    vlSymsp->TOP__top__u_core__u_memory.__PVT__alu_result_in 
        = vlSelfRef.__Vcellinp__u_memory__alu_result_in;
    vlSymsp->TOP__top__u_core__u_forward.__PVT__mem_opcode 
        = vlSelfRef.__Vcellinp__u_forward__mem_opcode;
    vlSymsp->TOP__top__u_core__u_forward.__PVT__mem_rd_addr 
        = vlSelfRef.__Vcellinp__u_forward__mem_rd_addr;
    vlSymsp->TOP__top__u_core__u_writeback.__PVT__rd_addr_in 
        = vlSelfRef.__Vcellinp__u_writeback__rd_addr_in;
    vlSymsp->TOP__top__u_core__u_writeback.__PVT__opcode_in 
        = vlSelfRef.__Vcellinp__u_writeback__opcode_in;
    vlSymsp->TOP__top__u_core__u_writeback.__PVT__mem_rdata_in 
        = vlSelfRef.__Vcellinp__u_writeback__mem_rdata_in;
    vlSymsp->TOP__top__u_core__u_writeback.__PVT__alu_result_in 
        = vlSelfRef.__Vcellinp__u_writeback__alu_result_in;
    vlSymsp->TOP__top__u_core__u_forward.__PVT__wb_opcode 
        = vlSelfRef.__Vcellinp__u_forward__wb_opcode;
    vlSymsp->TOP__top__u_core__u_forward.__PVT__wb_rd_addr 
        = vlSelfRef.__Vcellinp__u_forward__wb_rd_addr;
}

VL_ATTR_COLD void Vtop_core___stl_sequent__TOP__top__u_core__2(Vtop_core* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_core___stl_sequent__TOP__top__u_core__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__clk 
        = vlSelfRef.__PVT__clk;
    vlSymsp->TOP__top__u_core__u_fetch.__PVT__clk = vlSelfRef.__PVT__clk;
    vlSymsp->TOP__top__u_core__u_if2id.__PVT__clk = vlSelfRef.__PVT__clk;
    vlSymsp->TOP__top__u_core__u_reg_file.__PVT__clk 
        = vlSelfRef.__PVT__clk;
    vlSymsp->TOP__top__u_core__u_id2ex.__PVT__clk = vlSelfRef.__PVT__clk;
    vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__clk 
        = vlSelfRef.__PVT__clk;
    vlSymsp->TOP__top__u_core__u_memory.__PVT__clk 
        = vlSelfRef.__PVT__clk;
    vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__clk 
        = vlSelfRef.__PVT__clk;
    vlSymsp->TOP__top__u_core__u_csr_file.__PVT__clk 
        = vlSelfRef.__PVT__clk;
    vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__rst_n 
        = vlSelfRef.__PVT__rst_n;
    vlSymsp->TOP__top__u_core__u_if2id.__PVT__rst_n 
        = vlSelfRef.__PVT__rst_n;
    vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rst_n 
        = vlSelfRef.__PVT__rst_n;
    vlSymsp->TOP__top__u_core__u_id2ex.__PVT__rst_n 
        = vlSelfRef.__PVT__rst_n;
    vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__rst_n 
        = vlSelfRef.__PVT__rst_n;
    vlSymsp->TOP__top__u_core__u_memory.__PVT__rst_n 
        = vlSelfRef.__PVT__rst_n;
    vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__rst_n 
        = vlSelfRef.__PVT__rst_n;
    vlSelfRef.__Vcellinp__u_csr_file__rst = (1U & (~ (IData)(vlSelfRef.__PVT__rst_n)));
    vlSymsp->TOP__top__u_core__u_fetch.__PVT__rst_n 
        = vlSelfRef.__PVT__rst_n;
    vlSelfRef.__PVT__ex2mem_up_ready = vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__up_ready;
    vlSelfRef.__PVT__decode_csr_addr = vlSymsp->TOP__top__u_core__u_decode.__PVT__csr_addr_out;
    vlSelfRef.__PVT__decode_rd_addr = vlSymsp->TOP__top__u_core__u_decode.__PVT__rd_addr_out;
    vlSelfRef.__PVT__decode_funct7 = vlSymsp->TOP__top__u_core__u_decode.__PVT__funct7_out;
    vlSelfRef.__PVT__decode_inst_ebreak = vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_ebreak;
    vlSelfRef.__PVT__decode_funct3 = vlSymsp->TOP__top__u_core__u_decode.__PVT__funct3_out;
    vlSelfRef.__PVT__decode_opcode = vlSymsp->TOP__top__u_core__u_decode.__PVT__opcode_out;
    vlSelfRef.__PVT__decode_imm = vlSymsp->TOP__top__u_core__u_decode.__PVT__imm_out;
    vlSelfRef.__PVT__decode_inst_mret = vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_mret;
    vlSelfRef.__PVT__decode_inst_ecall = vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_ecall;
    vlSelfRef.__PVT__decode_inst_csrrw = vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_csrrw;
    vlSelfRef.__PVT__decode_inst_csrrs = vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_csrrs;
    vlSelfRef.__PVT__decode_op1_sel = vlSymsp->TOP__top__u_core__u_decode.__PVT__op1_sel_out;
    vlSelfRef.__PVT__decode_op2_sel = vlSymsp->TOP__top__u_core__u_decode.__PVT__op2_sel_out;
    vlSelfRef.__PVT__decode_rs1_addr = vlSymsp->TOP__top__u_core__u_decode.__PVT__rd_rs1_addr;
    vlSelfRef.__PVT__decode_rs2_addr = vlSymsp->TOP__top__u_core__u_decode.__PVT__rd_rs2_addr;
    vlSelfRef.__PVT__trap_valid = vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_valid;
    vlSelfRef.__PVT__trap_pc = vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_pc;
    vlSelfRef.__PVT__csr_waddr = vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_waddr;
    vlSelfRef.__PVT__csr_raddr = vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_raddr;
    vlSelfRef.__PVT__csr_wen = vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_wen;
    vlSelfRef.__PVT__ex_jump_target = vlSymsp->TOP__top__u_core__u_execute.__PVT__jump_target_out;
    vlSelfRef.__PVT__ex_jump_flag = vlSymsp->TOP__top__u_core__u_execute.__PVT__jump_flag_out;
    vlSelfRef.__PVT__mem_rdata = vlSymsp->TOP__top__u_core__u_memory.__PVT__mem_rdata_out;
    vlSelfRef.__PVT__wb_wr_addr = vlSymsp->TOP__top__u_core__u_writeback.__PVT__wb_addr;
    vlSelfRef.__PVT__wb_wr_en = vlSymsp->TOP__top__u_core__u_writeback.__PVT__wb_en;
    vlSelfRef.__PVT__wb_wr_data = vlSymsp->TOP__top__u_core__u_writeback.__PVT__wb_data;
    vlSymsp->TOP__top__u_core__u_csr_file.__PVT__rst 
        = vlSelfRef.__Vcellinp__u_csr_file__rst;
    vlSymsp->TOP__top__u_core__u_id2ex.__PVT__dn_ready 
        = vlSelfRef.__PVT__ex2mem_up_ready;
    VL_ASSIGNSEL_WI(263,2,0U, vlSelfRef.__PVT__id_ex_up, 
                    VL_CONCAT_III(2,1,1, (IData)(vlSelfRef.__PVT__decode_inst_mret), (IData)(vlSelfRef.__PVT__decode_inst_ebreak)));
    VL_ASSIGNSEL_WI(263,15,2U, vlSelfRef.__PVT__id_ex_up, 
                    VL_CONCAT_III(15,12,3, (IData)(vlSelfRef.__PVT__decode_csr_addr), 
                                  VL_CONCAT_III(3,1,2, (IData)(vlSelfRef.__PVT__decode_inst_csrrw), 
                                                VL_CONCAT_III(2,1,1, (IData)(vlSelfRef.__PVT__decode_inst_csrrs), (IData)(vlSelfRef.__PVT__decode_inst_ecall)))));
    vlSymsp->TOP__top__u_core__u_hazard.__PVT__id_rs1_addr 
        = vlSelfRef.__PVT__decode_rs1_addr;
    vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs1_addr 
        = vlSelfRef.__PVT__decode_rs1_addr;
    vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_rs1_addr 
        = vlSelfRef.__PVT__decode_rs1_addr;
    vlSymsp->TOP__top__u_core__u_hazard.__PVT__id_rs2_addr 
        = vlSelfRef.__PVT__decode_rs2_addr;
    vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs2_addr 
        = vlSelfRef.__PVT__decode_rs2_addr;
    vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_rs2_addr 
        = vlSelfRef.__PVT__decode_rs2_addr;
    vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_valid 
        = vlSelfRef.__PVT__trap_valid;
    vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_pc 
        = vlSelfRef.__PVT__trap_pc;
    vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_waddr 
        = vlSelfRef.__PVT__csr_waddr;
    vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_raddr 
        = vlSelfRef.__PVT__csr_raddr;
    vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_wen 
        = vlSelfRef.__PVT__csr_wen;
    vlSymsp->TOP__top__u_core__u_if2id.__PVT__flush 
        = vlSelfRef.__PVT__ex_jump_flag;
    VL_ASSIGNSEL_WQ(140,44,0U, vlSelfRef.__PVT__mem_wb_up, 
                    VL_CONCAT_QII(44,32,12, vlSelfRef.__PVT__mem_rdata, 
                                  VL_CONCAT_III(12,5,7, 
                                                (0x1fU 
                                                 & VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 0xaU, 5U)), 
                                                (0x7fU 
                                                 & VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 3U, 7U)))));
    vlSymsp->TOP__top__u_core__u_reg_file.__PVT__wr_addr 
        = vlSelfRef.__PVT__wb_wr_addr;
    vlSelfRef.__PVT__debug_wb_addr = vlSelfRef.__PVT__wb_wr_addr;
    vlSymsp->TOP__top__u_core__u_reg_file.__PVT__wr_en 
        = vlSelfRef.__PVT__wb_wr_en;
    vlSelfRef.__PVT__debug_wb_ena = vlSelfRef.__PVT__wb_wr_en;
    vlSymsp->TOP__top__u_core__u_reg_file.__PVT__wr_data 
        = vlSelfRef.__PVT__wb_wr_data;
    vlSelfRef.__PVT__debug_wb_data = vlSelfRef.__PVT__wb_wr_data;
    VL_ASSIGN_W(140,vlSelfRef.__Vcellinp__u_mem2wb__up_data, vlSelfRef.__PVT__mem_wb_up);
    VL_ASSIGN_W(140,vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__up_data, vlSelfRef.__Vcellinp__u_mem2wb__up_data);
}

VL_ATTR_COLD void Vtop_core___stl_sequent__TOP__top__u_core__3(Vtop_core* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_core___stl_sequent__TOP__top__u_core__3\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__instr = vlSymsp->TOP__top__u_core__u_fetch.__PVT__instr_out;
    vlSelfRef.__PVT__id2ex_up_ready = vlSymsp->TOP__top__u_core__u_id2ex.__PVT__up_ready;
    vlSelfRef.__PVT__load_stall = vlSymsp->TOP__top__u_core__u_hazard.__PVT__stall;
    vlSelfRef.__PVT__reg_rs1_data = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs1_data;
    vlSelfRef.__PVT__reg_rs2_data = vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs2_data;
    vlSelfRef.__PVT__fwd_rs1_sel = vlSymsp->TOP__top__u_core__u_forward.__PVT__fwd_rs1_sel;
    vlSelfRef.__PVT__fwd_rs2_sel = vlSymsp->TOP__top__u_core__u_forward.__PVT__fwd_rs2_sel;
    vlSelfRef.__PVT__csr_rdata = vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_rdata;
    vlSelfRef.__PVT__if_id_up = VL_CONCAT_QII(64,32,32, vlSelfRef.__PVT__pc, vlSelfRef.__PVT__instr);
    vlSymsp->TOP__top__u_core__u_if2id.__PVT__dn_ready 
        = vlSelfRef.__PVT__id2ex_up_ready;
    vlSelfRef.__Vcellinp__u_pc_counter__jump_en = ((IData)(vlSelfRef.__PVT__load_stall) 
                                                   | (IData)(vlSelfRef.__PVT__ex_jump_flag));
    vlSelfRef.__Vcellinp__u_id2ex__flush = ((IData)(vlSelfRef.__PVT__ex_jump_flag) 
                                            | (IData)(vlSelfRef.__PVT__load_stall));
    vlSelfRef.__Vcellinp__u_pc_counter__jump_addr = 
        ((IData)(vlSelfRef.__PVT__load_stall) ? vlSelfRef.__PVT__pc
          : vlSelfRef.__PVT__ex_jump_target);
    vlSymsp->TOP__top__u_core__u_if2id.__PVT__stall 
        = vlSelfRef.__PVT__load_stall;
    vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_rdata 
        = vlSelfRef.__PVT__csr_rdata;
    vlSelfRef.__Vcellinp__u_if2id__up_data = vlSelfRef.__PVT__if_id_up;
    vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__jump_en 
        = vlSelfRef.__Vcellinp__u_pc_counter__jump_en;
    vlSymsp->TOP__top__u_core__u_id2ex.__PVT__flush 
        = vlSelfRef.__Vcellinp__u_id2ex__flush;
    vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__jump_addr 
        = vlSelfRef.__Vcellinp__u_pc_counter__jump_addr;
    vlSymsp->TOP__top__u_core__u_if2id.__PVT__up_data 
        = vlSelfRef.__Vcellinp__u_if2id__up_data;
}

VL_ATTR_COLD void Vtop_core___stl_sequent__TOP__top__u_core__4(Vtop_core* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_core___stl_sequent__TOP__top__u_core__4\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    // Body
    vlSelfRef.__PVT__if2id_up_ready = vlSymsp->TOP__top__u_core__u_if2id.__PVT__up_ready;
    vlSelfRef.__PVT__csr_wdata = vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_wdata;
    vlSelfRef.__PVT__ex_alu_result = vlSymsp->TOP__top__u_core__u_execute.__PVT__alu_result_out;
    vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_wdata 
        = vlSelfRef.__PVT__csr_wdata;
    VL_CONCAT_WQI(96,64,32, __Vtemp_1, VL_CONCAT_QII(64,32,32, 
                                                     VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0xe7U, 0x20U), 
                                                     VL_SEL_IWII(263, vlSelfRef.__PVT__id_ex_dn, 0xc7U, 0x20U)), vlSelfRef.__PVT__ex_alu_result);
    VL_ASSIGNSEL_WW(143,96,0x2fU, vlSelfRef.__PVT__ex_mem_up, __Vtemp_1);
    vlSelfRef.__PVT__fwd_rs1_data = ((1U == (IData)(vlSelfRef.__PVT__fwd_rs1_sel))
                                      ? vlSelfRef.__PVT__ex_alu_result
                                      : ((2U == (IData)(vlSelfRef.__PVT__fwd_rs1_sel))
                                          ? ((3U == 
                                              (0x7fU 
                                               & VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 3U, 7U)))
                                              ? vlSelfRef.__PVT__mem_rdata
                                              : VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 0x2fU, 0x20U))
                                          : ((3U == (IData)(vlSelfRef.__PVT__fwd_rs1_sel))
                                              ? vlSelfRef.__PVT__wb_wr_data
                                              : vlSelfRef.__PVT__reg_rs1_data)));
    vlSelfRef.__PVT__fwd_rs2_data = ((1U == (IData)(vlSelfRef.__PVT__fwd_rs2_sel))
                                      ? vlSelfRef.__PVT__ex_alu_result
                                      : ((2U == (IData)(vlSelfRef.__PVT__fwd_rs2_sel))
                                          ? ((3U == 
                                              (0x7fU 
                                               & VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 3U, 7U)))
                                              ? vlSelfRef.__PVT__mem_rdata
                                              : VL_SEL_IWII(143, vlSelfRef.__PVT__ex_mem_dn, 0x2fU, 0x20U))
                                          : ((3U == (IData)(vlSelfRef.__PVT__fwd_rs2_sel))
                                              ? vlSelfRef.__PVT__wb_wr_data
                                              : vlSelfRef.__PVT__reg_rs2_data)));
    VL_ASSIGN_W(143,vlSelfRef.__Vcellinp__u_ex2mem__up_data, vlSelfRef.__PVT__ex_mem_up);
    VL_CONCAT_WIQ(74,10,64, __Vtemp_2, VL_CONCAT_III(10,3,7, (IData)(vlSelfRef.__PVT__decode_funct3), (IData)(vlSelfRef.__PVT__decode_funct7)), 
                  VL_CONCAT_QII(64,32,32, vlSelfRef.__PVT__fwd_rs1_data, vlSelfRef.__PVT__fwd_rs2_data));
    VL_ASSIGNSEL_WW(263,74,0x11U, vlSelfRef.__PVT__id_ex_up, __Vtemp_2);
    vlSelfRef.__PVT__id_op1 = ((0U == (IData)(vlSelfRef.__PVT__decode_op1_sel))
                                ? vlSelfRef.__PVT__fwd_rs1_data
                                : ((1U == (IData)(vlSelfRef.__PVT__decode_op1_sel))
                                    ? VL_SEL_IQII(64, vlSelfRef.__PVT__if_id_dn, 0x20U, 0x20U)
                                    : 0U));
    vlSelfRef.__PVT__id_op2 = ((0U == (IData)(vlSelfRef.__PVT__decode_op2_sel))
                                ? vlSelfRef.__PVT__fwd_rs2_data
                                : ((1U == (IData)(vlSelfRef.__PVT__decode_op2_sel))
                                    ? vlSelfRef.__PVT__decode_imm
                                    : ((2U == (IData)(vlSelfRef.__PVT__decode_op2_sel))
                                        ? 4U : 0U)));
    VL_ASSIGN_W(143,vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__up_data, vlSelfRef.__Vcellinp__u_ex2mem__up_data);
    VL_CONCAT_WQI(96,64,32, __Vtemp_3, VL_CONCAT_QII(64,32,32, 
                                                     VL_SEL_IQII(64, vlSelfRef.__PVT__if_id_dn, 0x20U, 0x20U), 
                                                     VL_SEL_IQII(64, vlSelfRef.__PVT__if_id_dn, 0U, 0x20U)), vlSelfRef.__PVT__id_op1);
    VL_ASSIGNSEL_WW(263,96,0xa7U, vlSelfRef.__PVT__id_ex_up, __Vtemp_3);
    VL_CONCAT_WIQ(76,32,44, __Vtemp_4, vlSelfRef.__PVT__id_op2, 
                  VL_CONCAT_QIQ(44,5,39, (IData)(vlSelfRef.__PVT__decode_rd_addr), 
                                VL_CONCAT_QII(39,32,7, vlSelfRef.__PVT__decode_imm, (IData)(vlSelfRef.__PVT__decode_opcode))));
    VL_ASSIGNSEL_WW(263,76,0x5bU, vlSelfRef.__PVT__id_ex_up, __Vtemp_4);
    VL_ASSIGN_W(263,vlSelfRef.__Vcellinp__u_id2ex__up_data, vlSelfRef.__PVT__id_ex_up);
    VL_ASSIGN_W(263,vlSymsp->TOP__top__u_core__u_id2ex.__PVT__up_data, vlSelfRef.__Vcellinp__u_id2ex__up_data);
}
