// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSymsp->TOP__top.__PVT__trap_cause),32);
        bufp->chgIData(oldp+1,(vlSymsp->TOP__top__u_csr_file.__PVT__trap_cause),32);
        bufp->chgIData(oldp+2,(vlSymsp->TOP__top__u_execute.__PVT__trap_cause),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+3,(vlSymsp->TOP__top.clk));
        bufp->chgBit(oldp+4,(vlSymsp->TOP__top.rst_n));
        bufp->chgBit(oldp+5,(vlSymsp->TOP__top__u_memory.__PVT__clk));
        bufp->chgBit(oldp+6,(vlSymsp->TOP__top__u_memory.__PVT__rst_n));
        bufp->chgBit(oldp+7,(vlSymsp->TOP__top__u_csr_file.__PVT__clk));
        bufp->chgBit(oldp+8,(vlSymsp->TOP__top__u_csr_file.__PVT__rst));
        bufp->chgBit(oldp+9,(vlSymsp->TOP__top__u_reg_file.__PVT__clk));
        bufp->chgBit(oldp+10,(vlSymsp->TOP__top__u_reg_file.__PVT__rst_n));
        bufp->chgBit(oldp+11,(vlSymsp->TOP__top__u_fetch.__PVT__clk));
        bufp->chgBit(oldp+12,(vlSymsp->TOP__top__u_fetch.__PVT__rst_n));
        bufp->chgBit(oldp+13,(vlSymsp->TOP__top__u_pc_counter.__PVT__clk));
        bufp->chgBit(oldp+14,(vlSymsp->TOP__top__u_pc_counter.__PVT__rst_n));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [4U]))) {
        bufp->chgIData(oldp+15,(vlSymsp->TOP__top.instr),32);
        bufp->chgIData(oldp+16,(vlSymsp->TOP__top.__PVT__instr_addr_out),32);
        bufp->chgIData(oldp+17,(vlSymsp->TOP__top.__PVT__instr_out),32);
        bufp->chgCData(oldp+18,(vlSymsp->TOP__top.__PVT__decode_rs1_addr),5);
        bufp->chgCData(oldp+19,(vlSymsp->TOP__top.__PVT__decode_rs2_addr),5);
        bufp->chgCData(oldp+20,(vlSymsp->TOP__top.__PVT__decode_rd_addr),5);
        bufp->chgIData(oldp+21,(vlSymsp->TOP__top.__PVT__decode_imm),32);
        bufp->chgCData(oldp+22,(vlSymsp->TOP__top.__PVT__decode_op1_sel),2);
        bufp->chgCData(oldp+23,(vlSymsp->TOP__top.__PVT__decode_op2_sel),2);
        bufp->chgCData(oldp+24,(vlSymsp->TOP__top.__PVT__decode_opcode),7);
        bufp->chgCData(oldp+25,(vlSymsp->TOP__top.__PVT__decode_funct3),3);
        bufp->chgCData(oldp+26,(vlSymsp->TOP__top.__PVT__decode_funct7),7);
        bufp->chgSData(oldp+27,(vlSymsp->TOP__top.__PVT__decode_csr_addr),12);
        bufp->chgBit(oldp+28,(vlSymsp->TOP__top.__PVT__decode_inst_csrrw));
        bufp->chgBit(oldp+29,(vlSymsp->TOP__top.__PVT__decode_inst_csrrs));
        bufp->chgBit(oldp+30,(vlSymsp->TOP__top.__PVT__decode_inst_ecall));
        bufp->chgBit(oldp+31,(vlSymsp->TOP__top.__PVT__decode_inst_mret));
        bufp->chgBit(oldp+32,(vlSymsp->TOP__top.__PVT__inst_ebreak));
        bufp->chgIData(oldp+33,(vlSymsp->TOP__top__u_if2id.__PVT__instr_in),32);
        bufp->chgIData(oldp+34,(vlSymsp->TOP__top__u_if2id.__PVT__instr_addr_out),32);
        bufp->chgIData(oldp+35,(vlSymsp->TOP__top__u_if2id.__PVT__instr_out),32);
        bufp->chgCData(oldp+36,(vlSymsp->TOP__top__u_reg_file.__PVT__rs1_addr),5);
        bufp->chgCData(oldp+37,(vlSymsp->TOP__top__u_reg_file.__PVT__rs2_addr),5);
        bufp->chgIData(oldp+38,(vlSymsp->TOP__top__u_fetch.__PVT__instr_out),32);
        bufp->chgIData(oldp+39,(vlSymsp->TOP__top__u_decode.__PVT__instr_addr_in),32);
        bufp->chgIData(oldp+40,(vlSymsp->TOP__top__u_decode.__PVT__instr_in),32);
        bufp->chgCData(oldp+41,(vlSymsp->TOP__top__u_decode.__PVT__rd_rs1_addr),5);
        bufp->chgCData(oldp+42,(vlSymsp->TOP__top__u_decode.__PVT__rd_rs2_addr),5);
        bufp->chgCData(oldp+43,(vlSymsp->TOP__top__u_decode.__PVT__rd_addr_out),5);
        bufp->chgIData(oldp+44,(vlSymsp->TOP__top__u_decode.__PVT__imm_out),32);
        bufp->chgCData(oldp+45,(vlSymsp->TOP__top__u_decode.__PVT__op1_sel_out),2);
        bufp->chgCData(oldp+46,(vlSymsp->TOP__top__u_decode.__PVT__op2_sel_out),2);
        bufp->chgCData(oldp+47,(vlSymsp->TOP__top__u_decode.__PVT__opcode_out),7);
        bufp->chgCData(oldp+48,(vlSymsp->TOP__top__u_decode.__PVT__funct3_out),3);
        bufp->chgCData(oldp+49,(vlSymsp->TOP__top__u_decode.__PVT__funct7_out),7);
        bufp->chgBit(oldp+50,(vlSymsp->TOP__top__u_decode.__PVT__inst_ebreak));
        bufp->chgSData(oldp+51,(vlSymsp->TOP__top__u_decode.__PVT__csr_addr_out),12);
        bufp->chgBit(oldp+52,(vlSymsp->TOP__top__u_decode.__PVT__inst_csrrw));
        bufp->chgBit(oldp+53,(vlSymsp->TOP__top__u_decode.__PVT__inst_csrrs));
        bufp->chgBit(oldp+54,(vlSymsp->TOP__top__u_decode.__PVT__inst_ecall));
        bufp->chgBit(oldp+55,(vlSymsp->TOP__top__u_decode.__PVT__inst_mret));
        bufp->chgCData(oldp+56,(vlSymsp->TOP__top__u_decode.__PVT__opcode),7);
        bufp->chgCData(oldp+57,(vlSymsp->TOP__top__u_decode.__PVT__rd),5);
        bufp->chgCData(oldp+58,(vlSymsp->TOP__top__u_decode.__PVT__funct3),3);
        bufp->chgCData(oldp+59,(vlSymsp->TOP__top__u_decode.__PVT__rs1),5);
        bufp->chgCData(oldp+60,(vlSymsp->TOP__top__u_decode.__PVT__rs2),5);
        bufp->chgCData(oldp+61,(vlSymsp->TOP__top__u_decode.__PVT__funct7),7);
        bufp->chgIData(oldp+62,(vlSymsp->TOP__top__u_decode.__PVT__imm),32);
        bufp->chgBit(oldp+63,(vlSymsp->TOP__top__u_decode.__PVT__is_ebreak));
        bufp->chgBit(oldp+64,(vlSymsp->TOP__top__u_decode.__PVT__is_system));
        bufp->chgIData(oldp+65,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_addr_in),32);
        bufp->chgIData(oldp+66,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_in),32);
        bufp->chgCData(oldp+67,(vlSymsp->TOP__top__u_id2ex.__PVT__rd_addr_in),5);
        bufp->chgIData(oldp+68,(vlSymsp->TOP__top__u_id2ex.__PVT__imm_in),32);
        bufp->chgCData(oldp+69,(vlSymsp->TOP__top__u_id2ex.__PVT__op1_sel_in),2);
        bufp->chgCData(oldp+70,(vlSymsp->TOP__top__u_id2ex.__PVT__op2_sel_in),2);
        bufp->chgCData(oldp+71,(vlSymsp->TOP__top__u_id2ex.__PVT__opcode_in),7);
        bufp->chgCData(oldp+72,(vlSymsp->TOP__top__u_id2ex.__PVT__funct3_in),3);
        bufp->chgCData(oldp+73,(vlSymsp->TOP__top__u_id2ex.__PVT__funct7_in),7);
        bufp->chgBit(oldp+74,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_ebreak_in));
        bufp->chgSData(oldp+75,(vlSymsp->TOP__top__u_id2ex.__PVT__csr_addr_in),12);
        bufp->chgBit(oldp+76,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_csrrw_in));
        bufp->chgBit(oldp+77,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_csrrs_in));
        bufp->chgBit(oldp+78,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_ecall_in));
        bufp->chgBit(oldp+79,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_mret_in));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [5U]))) {
        bufp->chgIData(oldp+80,(vlSymsp->TOP__top.__PVT__reg_rs1_data),32);
        bufp->chgIData(oldp+81,(vlSymsp->TOP__top.__PVT__reg_rs2_data),32);
        bufp->chgIData(oldp+82,(vlSymsp->TOP__top.__PVT__id_instr_addr_out),32);
        bufp->chgIData(oldp+83,(vlSymsp->TOP__top.__PVT__id_instr_out),32);
        bufp->chgIData(oldp+84,(vlSymsp->TOP__top.__PVT__id_op1_out),32);
        bufp->chgIData(oldp+85,(vlSymsp->TOP__top.__PVT__id_op2_out),32);
        bufp->chgCData(oldp+86,(vlSymsp->TOP__top.__PVT__id_rd_addr_out),5);
        bufp->chgIData(oldp+87,(vlSymsp->TOP__top.__PVT__id_imm_out),32);
        bufp->chgCData(oldp+88,(vlSymsp->TOP__top.__PVT__id_opcode_out),7);
        bufp->chgCData(oldp+89,(vlSymsp->TOP__top.__PVT__id_funct3_out),3);
        bufp->chgCData(oldp+90,(vlSymsp->TOP__top.__PVT__id_funct7_out),7);
        bufp->chgIData(oldp+91,(vlSymsp->TOP__top.__PVT__id_rs1_data),32);
        bufp->chgIData(oldp+92,(vlSymsp->TOP__top.__PVT__id_rs2_data),32);
        bufp->chgSData(oldp+93,(vlSymsp->TOP__top.__PVT__id_csr_addr),12);
        bufp->chgBit(oldp+94,(vlSymsp->TOP__top.__PVT__id_inst_csrrw));
        bufp->chgBit(oldp+95,(vlSymsp->TOP__top.__PVT__id_inst_csrrs));
        bufp->chgBit(oldp+96,(vlSymsp->TOP__top.__PVT__id_inst_ecall));
        bufp->chgBit(oldp+97,(vlSymsp->TOP__top.__PVT__id_inst_mret));
        bufp->chgBit(oldp+98,(vlSymsp->TOP__top.__PVT__inst_ebreak_out));
        bufp->chgSData(oldp+99,(vlSymsp->TOP__top.__PVT__csr_raddr),12);
        bufp->chgBit(oldp+100,(vlSymsp->TOP__top.__PVT__csr_wen));
        bufp->chgSData(oldp+101,(vlSymsp->TOP__top.__PVT__csr_waddr),12);
        bufp->chgBit(oldp+102,(vlSymsp->TOP__top.__PVT__trap_valid));
        bufp->chgIData(oldp+103,(vlSymsp->TOP__top.__PVT__trap_pc),32);
        bufp->chgSData(oldp+104,(vlSymsp->TOP__top__u_csr_file.__PVT__csr_raddr),12);
        bufp->chgBit(oldp+105,(vlSymsp->TOP__top__u_csr_file.__PVT__csr_wen));
        bufp->chgSData(oldp+106,(vlSymsp->TOP__top__u_csr_file.__PVT__csr_waddr),12);
        bufp->chgBit(oldp+107,(vlSymsp->TOP__top__u_csr_file.__PVT__trap_valid));
        bufp->chgIData(oldp+108,(vlSymsp->TOP__top__u_csr_file.__PVT__trap_pc),32);
        bufp->chgIData(oldp+109,(vlSymsp->TOP__top__u_reg_file.__PVT__rs1_data),32);
        bufp->chgIData(oldp+110,(vlSymsp->TOP__top__u_reg_file.__PVT__rs2_data),32);
        bufp->chgIData(oldp+111,(vlSymsp->TOP__top__u_execute.__PVT__pc_in),32);
        bufp->chgIData(oldp+112,(vlSymsp->TOP__top__u_execute.__PVT__op1_in),32);
        bufp->chgIData(oldp+113,(vlSymsp->TOP__top__u_execute.__PVT__op2_in),32);
        bufp->chgIData(oldp+114,(vlSymsp->TOP__top__u_execute.__PVT__rs1_data_in),32);
        bufp->chgIData(oldp+115,(vlSymsp->TOP__top__u_execute.__PVT__imm_in),32);
        bufp->chgCData(oldp+116,(vlSymsp->TOP__top__u_execute.__PVT__opcode_in),7);
        bufp->chgCData(oldp+117,(vlSymsp->TOP__top__u_execute.__PVT__funct3_in),3);
        bufp->chgCData(oldp+118,(vlSymsp->TOP__top__u_execute.__PVT__funct7_in),7);
        bufp->chgBit(oldp+119,(vlSymsp->TOP__top__u_execute.__PVT__inst_ebreak_in));
        bufp->chgSData(oldp+120,(vlSymsp->TOP__top__u_execute.__PVT__csr_addr_in),12);
        bufp->chgBit(oldp+121,(vlSymsp->TOP__top__u_execute.__PVT__inst_csrrw));
        bufp->chgBit(oldp+122,(vlSymsp->TOP__top__u_execute.__PVT__inst_csrrs));
        bufp->chgBit(oldp+123,(vlSymsp->TOP__top__u_execute.__PVT__inst_ecall));
        bufp->chgBit(oldp+124,(vlSymsp->TOP__top__u_execute.__PVT__inst_mret));
        bufp->chgSData(oldp+125,(vlSymsp->TOP__top__u_execute.__PVT__csr_raddr),12);
        bufp->chgBit(oldp+126,(vlSymsp->TOP__top__u_execute.__PVT__csr_wen));
        bufp->chgSData(oldp+127,(vlSymsp->TOP__top__u_execute.__PVT__csr_waddr),12);
        bufp->chgBit(oldp+128,(vlSymsp->TOP__top__u_execute.__PVT__trap_valid));
        bufp->chgIData(oldp+129,(vlSymsp->TOP__top__u_execute.__PVT__trap_pc),32);
        bufp->chgIData(oldp+130,(vlSymsp->TOP__top__u_execute.__PVT__alu_res),32);
        bufp->chgBit(oldp+131,(vlSymsp->TOP__top__u_execute.__PVT__branch_taken));
        bufp->chgIData(oldp+132,(vlSymsp->TOP__top__u_id2ex.__PVT__rs1_data_in),32);
        bufp->chgIData(oldp+133,(vlSymsp->TOP__top__u_id2ex.__PVT__rs2_data_in),32);
        bufp->chgIData(oldp+134,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_addr_out),32);
        bufp->chgIData(oldp+135,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_out),32);
        bufp->chgIData(oldp+136,(vlSymsp->TOP__top__u_id2ex.__PVT__op1_out),32);
        bufp->chgIData(oldp+137,(vlSymsp->TOP__top__u_id2ex.__PVT__op2_out),32);
        bufp->chgCData(oldp+138,(vlSymsp->TOP__top__u_id2ex.__PVT__rd_addr_out),5);
        bufp->chgIData(oldp+139,(vlSymsp->TOP__top__u_id2ex.__PVT__imm_out),32);
        bufp->chgCData(oldp+140,(vlSymsp->TOP__top__u_id2ex.__PVT__opcode_out),7);
        bufp->chgCData(oldp+141,(vlSymsp->TOP__top__u_id2ex.__PVT__funct3_out),3);
        bufp->chgCData(oldp+142,(vlSymsp->TOP__top__u_id2ex.__PVT__funct7_out),7);
        bufp->chgIData(oldp+143,(vlSymsp->TOP__top__u_id2ex.__PVT__rs1_data_out),32);
        bufp->chgIData(oldp+144,(vlSymsp->TOP__top__u_id2ex.__PVT__rs2_data_out),32);
        bufp->chgBit(oldp+145,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_ebreak_out));
        bufp->chgSData(oldp+146,(vlSymsp->TOP__top__u_id2ex.__PVT__csr_addr_out),12);
        bufp->chgBit(oldp+147,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_csrrw_out));
        bufp->chgBit(oldp+148,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_csrrs_out));
        bufp->chgBit(oldp+149,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_ecall_out));
        bufp->chgBit(oldp+150,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_mret_out));
        bufp->chgIData(oldp+151,(vlSymsp->TOP__top__u_ex2mem.__PVT__pc_in),32);
        bufp->chgIData(oldp+152,(vlSymsp->TOP__top__u_ex2mem.__PVT__rs2_data_in),32);
        bufp->chgCData(oldp+153,(vlSymsp->TOP__top__u_ex2mem.__PVT__rd_addr_in),5);
        bufp->chgCData(oldp+154,(vlSymsp->TOP__top__u_ex2mem.__PVT__opcode_in),7);
        bufp->chgCData(oldp+155,(vlSymsp->TOP__top__u_ex2mem.__PVT__funct3_in),3);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [6U]))) {
        bufp->chgIData(oldp+156,(vlSymsp->TOP__top.__PVT__ex_alu_result),32);
        bufp->chgBit(oldp+157,(vlSymsp->TOP__top.__PVT__ex_jump_flag));
        bufp->chgIData(oldp+158,(vlSymsp->TOP__top.__PVT__ex_jump_target),32);
        bufp->chgIData(oldp+159,(vlSymsp->TOP__top.__PVT__ex_alu_result_out),32);
        bufp->chgIData(oldp+160,(vlSymsp->TOP__top.__PVT__ex_rs2_data),32);
        bufp->chgCData(oldp+161,(vlSymsp->TOP__top.__PVT__ex_rd_addr),5);
        bufp->chgCData(oldp+162,(vlSymsp->TOP__top.__PVT__ex_opcode),7);
        bufp->chgCData(oldp+163,(vlSymsp->TOP__top.__PVT__ex_funct3),3);
        bufp->chgIData(oldp+164,(vlSymsp->TOP__top.__PVT__mem_rdata),32);
        bufp->chgIData(oldp+165,(vlSymsp->TOP__top.__PVT__mem_alu_result),32);
        bufp->chgIData(oldp+166,(vlSymsp->TOP__top.__PVT__mem_rdata_out),32);
        bufp->chgCData(oldp+167,(vlSymsp->TOP__top.__PVT__mem_rd_addr),5);
        bufp->chgCData(oldp+168,(vlSymsp->TOP__top.__PVT__mem_opcode),7);
        bufp->chgBit(oldp+169,(vlSymsp->TOP__top.__PVT__wb_wr_en));
        bufp->chgCData(oldp+170,(vlSymsp->TOP__top.__PVT__wb_wr_addr),5);
        bufp->chgIData(oldp+171,(vlSymsp->TOP__top.__PVT__wb_wr_data),32);
        bufp->chgIData(oldp+172,(vlSymsp->TOP__top.__PVT__csr_rdata),32);
        bufp->chgIData(oldp+173,(vlSymsp->TOP__top.__PVT__csr_wdata),32);
        bufp->chgIData(oldp+174,(vlSymsp->TOP__top__u_memory.__PVT__alu_result_in),32);
        bufp->chgIData(oldp+175,(vlSymsp->TOP__top__u_memory.__PVT__rs2_data_in),32);
        bufp->chgCData(oldp+176,(vlSymsp->TOP__top__u_memory.__PVT__opcode_in),7);
        bufp->chgCData(oldp+177,(vlSymsp->TOP__top__u_memory.__PVT__funct3_in),3);
        bufp->chgIData(oldp+178,(vlSymsp->TOP__top__u_memory.__PVT__mem_rdata_out),32);
        bufp->chgIData(oldp+179,(vlSymsp->TOP__top__u_memory.__PVT__rdata_raw),32);
        bufp->chgIData(oldp+180,(vlSymsp->TOP__top__u_writeback.__PVT__alu_result_in),32);
        bufp->chgIData(oldp+181,(vlSymsp->TOP__top__u_writeback.__PVT__mem_rdata_in),32);
        bufp->chgCData(oldp+182,(vlSymsp->TOP__top__u_writeback.__PVT__opcode_in),7);
        bufp->chgCData(oldp+183,(vlSymsp->TOP__top__u_writeback.__PVT__rd_addr_in),5);
        bufp->chgBit(oldp+184,(vlSymsp->TOP__top__u_writeback.__PVT__wb_en));
        bufp->chgCData(oldp+185,(vlSymsp->TOP__top__u_writeback.__PVT__wb_addr),5);
        bufp->chgIData(oldp+186,(vlSymsp->TOP__top__u_writeback.__PVT__wb_data),32);
        bufp->chgIData(oldp+187,(vlSymsp->TOP__top__u_csr_file.__PVT__csr_rdata),32);
        bufp->chgIData(oldp+188,(vlSymsp->TOP__top__u_csr_file.__PVT__csr_wdata),32);
        bufp->chgBit(oldp+189,(vlSymsp->TOP__top__u_reg_file.__PVT__wr_en));
        bufp->chgCData(oldp+190,(vlSymsp->TOP__top__u_reg_file.__PVT__wr_addr),5);
        bufp->chgIData(oldp+191,(vlSymsp->TOP__top__u_reg_file.__PVT__wr_data),32);
        bufp->chgIData(oldp+192,(vlSymsp->TOP__top__u_mem2wb.__PVT__alu_result_in),32);
        bufp->chgIData(oldp+193,(vlSymsp->TOP__top__u_mem2wb.__PVT__mem_rdata_in),32);
        bufp->chgCData(oldp+194,(vlSymsp->TOP__top__u_mem2wb.__PVT__rd_addr_in),5);
        bufp->chgCData(oldp+195,(vlSymsp->TOP__top__u_mem2wb.__PVT__opcode_in),7);
        bufp->chgIData(oldp+196,(vlSymsp->TOP__top__u_mem2wb.__PVT__alu_result_out),32);
        bufp->chgIData(oldp+197,(vlSymsp->TOP__top__u_mem2wb.__PVT__mem_rdata_out),32);
        bufp->chgCData(oldp+198,(vlSymsp->TOP__top__u_mem2wb.__PVT__rd_addr_out),5);
        bufp->chgCData(oldp+199,(vlSymsp->TOP__top__u_mem2wb.__PVT__opcode_out),7);
        bufp->chgIData(oldp+200,(vlSymsp->TOP__top__u_execute.__PVT__alu_result_out),32);
        bufp->chgBit(oldp+201,(vlSymsp->TOP__top__u_execute.__PVT__jump_flag_out));
        bufp->chgIData(oldp+202,(vlSymsp->TOP__top__u_execute.__PVT__jump_target_out),32);
        bufp->chgIData(oldp+203,(vlSymsp->TOP__top__u_execute.__PVT__csr_rdata),32);
        bufp->chgIData(oldp+204,(vlSymsp->TOP__top__u_execute.__PVT__csr_wdata),32);
        bufp->chgIData(oldp+205,(vlSymsp->TOP__top__u_ex2mem.__PVT__alu_result_in),32);
        bufp->chgIData(oldp+206,(vlSymsp->TOP__top__u_ex2mem.__PVT__alu_result_out),32);
        bufp->chgIData(oldp+207,(vlSymsp->TOP__top__u_ex2mem.__PVT__rs2_data_out),32);
        bufp->chgCData(oldp+208,(vlSymsp->TOP__top__u_ex2mem.__PVT__rd_addr_out),5);
        bufp->chgCData(oldp+209,(vlSymsp->TOP__top__u_ex2mem.__PVT__opcode_out),7);
        bufp->chgCData(oldp+210,(vlSymsp->TOP__top__u_ex2mem.__PVT__funct3_out),3);
        bufp->chgBit(oldp+211,(vlSymsp->TOP__top__u_pc_counter.__PVT__jump_en));
        bufp->chgIData(oldp+212,(vlSymsp->TOP__top__u_pc_counter.__PVT__jump_addr),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+213,(vlSymsp->TOP__top.__PVT__trap_mtvec),32);
        bufp->chgIData(oldp+214,(vlSymsp->TOP__top.__PVT__trap_mepc),32);
        bufp->chgIData(oldp+215,(vlSymsp->TOP__top__u_csr_file.__PVT__trap_mtvec),32);
        bufp->chgIData(oldp+216,(vlSymsp->TOP__top__u_csr_file.__PVT__trap_mepc),32);
        bufp->chgIData(oldp+217,(vlSymsp->TOP__top__u_csr_file.__PVT__mstatus),32);
        bufp->chgIData(oldp+218,(vlSymsp->TOP__top__u_csr_file.__PVT__mtvec),32);
        bufp->chgIData(oldp+219,(vlSymsp->TOP__top__u_csr_file.__PVT__mepc),32);
        bufp->chgIData(oldp+220,(vlSymsp->TOP__top__u_csr_file.__PVT__mcause),32);
        bufp->chgQData(oldp+221,(vlSymsp->TOP__top__u_csr_file.__PVT__mcycle_cnt),64);
        bufp->chgIData(oldp+223,(vlSymsp->TOP__top__u_execute.__PVT__trap_mtvec),32);
        bufp->chgIData(oldp+224,(vlSymsp->TOP__top__u_execute.__PVT__trap_mepc),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+225,(vlSymsp->TOP__top.debug_x10),32);
        bufp->chgIData(oldp+226,(vlSymsp->TOP__top.regs[0]),32);
        bufp->chgIData(oldp+227,(vlSymsp->TOP__top.regs[1]),32);
        bufp->chgIData(oldp+228,(vlSymsp->TOP__top.regs[2]),32);
        bufp->chgIData(oldp+229,(vlSymsp->TOP__top.regs[3]),32);
        bufp->chgIData(oldp+230,(vlSymsp->TOP__top.regs[4]),32);
        bufp->chgIData(oldp+231,(vlSymsp->TOP__top.regs[5]),32);
        bufp->chgIData(oldp+232,(vlSymsp->TOP__top.regs[6]),32);
        bufp->chgIData(oldp+233,(vlSymsp->TOP__top.regs[7]),32);
        bufp->chgIData(oldp+234,(vlSymsp->TOP__top.regs[8]),32);
        bufp->chgIData(oldp+235,(vlSymsp->TOP__top.regs[9]),32);
        bufp->chgIData(oldp+236,(vlSymsp->TOP__top.regs[10]),32);
        bufp->chgIData(oldp+237,(vlSymsp->TOP__top.regs[11]),32);
        bufp->chgIData(oldp+238,(vlSymsp->TOP__top.regs[12]),32);
        bufp->chgIData(oldp+239,(vlSymsp->TOP__top.regs[13]),32);
        bufp->chgIData(oldp+240,(vlSymsp->TOP__top.regs[14]),32);
        bufp->chgIData(oldp+241,(vlSymsp->TOP__top.regs[15]),32);
        bufp->chgIData(oldp+242,(vlSymsp->TOP__top__u_reg_file.__PVT__debug_x10),32);
        bufp->chgIData(oldp+243,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[0]),32);
        bufp->chgIData(oldp+244,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[1]),32);
        bufp->chgIData(oldp+245,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[2]),32);
        bufp->chgIData(oldp+246,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[3]),32);
        bufp->chgIData(oldp+247,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[4]),32);
        bufp->chgIData(oldp+248,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[5]),32);
        bufp->chgIData(oldp+249,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[6]),32);
        bufp->chgIData(oldp+250,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[7]),32);
        bufp->chgIData(oldp+251,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[8]),32);
        bufp->chgIData(oldp+252,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[9]),32);
        bufp->chgIData(oldp+253,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[10]),32);
        bufp->chgIData(oldp+254,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[11]),32);
        bufp->chgIData(oldp+255,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[12]),32);
        bufp->chgIData(oldp+256,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[13]),32);
        bufp->chgIData(oldp+257,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[14]),32);
        bufp->chgIData(oldp+258,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[15]),32);
        bufp->chgIData(oldp+259,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[0]),32);
        bufp->chgIData(oldp+260,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[1]),32);
        bufp->chgIData(oldp+261,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[2]),32);
        bufp->chgIData(oldp+262,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[3]),32);
        bufp->chgIData(oldp+263,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[4]),32);
        bufp->chgIData(oldp+264,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[5]),32);
        bufp->chgIData(oldp+265,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[6]),32);
        bufp->chgIData(oldp+266,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[7]),32);
        bufp->chgIData(oldp+267,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[8]),32);
        bufp->chgIData(oldp+268,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[9]),32);
        bufp->chgIData(oldp+269,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[10]),32);
        bufp->chgIData(oldp+270,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[11]),32);
        bufp->chgIData(oldp+271,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[12]),32);
        bufp->chgIData(oldp+272,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[13]),32);
        bufp->chgIData(oldp+273,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[14]),32);
        bufp->chgIData(oldp+274,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[15]),32);
        bufp->chgIData(oldp+275,(vlSymsp->TOP__top__u_reg_file.__PVT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+276,(vlSymsp->TOP__top.pc),32);
        bufp->chgIData(oldp+277,(vlSymsp->TOP__top__u_if2id.__PVT__instr_addr_in),32);
        bufp->chgIData(oldp+278,(vlSymsp->TOP__top__u_fetch.__PVT__pc_pointer),32);
        bufp->chgIData(oldp+279,(vlSymsp->TOP__top__u_pc_counter.__PVT__pc),32);
        bufp->chgIData(oldp+280,(vlSymsp->TOP__top__u_pc_counter.__PVT__pc_pointer),32);
    }
    bufp->chgBit(oldp+281,(vlSelfRef.clk));
    bufp->chgBit(oldp+282,(vlSelfRef.rst_n));
    bufp->chgIData(oldp+283,(vlSelfRef.pc),32);
    bufp->chgIData(oldp+284,(vlSelfRef.instr),32);
    bufp->chgIData(oldp+285,(vlSelfRef.debug_x10),32);
    bufp->chgIData(oldp+286,(vlSelfRef.regs[0]),32);
    bufp->chgIData(oldp+287,(vlSelfRef.regs[1]),32);
    bufp->chgIData(oldp+288,(vlSelfRef.regs[2]),32);
    bufp->chgIData(oldp+289,(vlSelfRef.regs[3]),32);
    bufp->chgIData(oldp+290,(vlSelfRef.regs[4]),32);
    bufp->chgIData(oldp+291,(vlSelfRef.regs[5]),32);
    bufp->chgIData(oldp+292,(vlSelfRef.regs[6]),32);
    bufp->chgIData(oldp+293,(vlSelfRef.regs[7]),32);
    bufp->chgIData(oldp+294,(vlSelfRef.regs[8]),32);
    bufp->chgIData(oldp+295,(vlSelfRef.regs[9]),32);
    bufp->chgIData(oldp+296,(vlSelfRef.regs[10]),32);
    bufp->chgIData(oldp+297,(vlSelfRef.regs[11]),32);
    bufp->chgIData(oldp+298,(vlSelfRef.regs[12]),32);
    bufp->chgIData(oldp+299,(vlSelfRef.regs[13]),32);
    bufp->chgIData(oldp+300,(vlSelfRef.regs[14]),32);
    bufp->chgIData(oldp+301,(vlSelfRef.regs[15]),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
}
