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
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSymsp->TOP__top.clk));
        bufp->chgBit(oldp+1,(vlSymsp->TOP__top.rst_n));
        bufp->chgBit(oldp+2,(vlSymsp->TOP__top__u_memory.__PVT__clk));
        bufp->chgBit(oldp+3,(vlSymsp->TOP__top__u_memory.__PVT__rst_n));
        bufp->chgBit(oldp+4,(vlSymsp->TOP__top__u_reg_file.__PVT__clk));
        bufp->chgBit(oldp+5,(vlSymsp->TOP__top__u_reg_file.__PVT__rst_n));
        bufp->chgBit(oldp+6,(vlSymsp->TOP__top__u_fetch.__PVT__clk));
        bufp->chgBit(oldp+7,(vlSymsp->TOP__top__u_fetch.__PVT__rst_n));
        bufp->chgBit(oldp+8,(vlSymsp->TOP__top__u_pc_counter.__PVT__clk));
        bufp->chgBit(oldp+9,(vlSymsp->TOP__top__u_pc_counter.__PVT__rst_n));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [2U]))) {
        bufp->chgIData(oldp+10,(vlSymsp->TOP__top.instr),32);
        bufp->chgIData(oldp+11,(vlSymsp->TOP__top.__PVT__instr_addr_out),32);
        bufp->chgIData(oldp+12,(vlSymsp->TOP__top.__PVT__instr_out),32);
        bufp->chgCData(oldp+13,(vlSymsp->TOP__top.__PVT__decode_rs1_addr),5);
        bufp->chgCData(oldp+14,(vlSymsp->TOP__top.__PVT__decode_rs2_addr),5);
        bufp->chgCData(oldp+15,(vlSymsp->TOP__top.__PVT__decode_rd_addr),5);
        bufp->chgIData(oldp+16,(vlSymsp->TOP__top.__PVT__decode_imm),32);
        bufp->chgCData(oldp+17,(vlSymsp->TOP__top.__PVT__decode_op1_sel),2);
        bufp->chgCData(oldp+18,(vlSymsp->TOP__top.__PVT__decode_op2_sel),2);
        bufp->chgCData(oldp+19,(vlSymsp->TOP__top.__PVT__decode_opcode),7);
        bufp->chgCData(oldp+20,(vlSymsp->TOP__top.__PVT__decode_funct3),3);
        bufp->chgCData(oldp+21,(vlSymsp->TOP__top.__PVT__decode_funct7),7);
        bufp->chgBit(oldp+22,(vlSymsp->TOP__top.__PVT__inst_ebreak));
        bufp->chgIData(oldp+23,(vlSymsp->TOP__top__u_if2id.__PVT__instr_in),32);
        bufp->chgIData(oldp+24,(vlSymsp->TOP__top__u_if2id.__PVT__instr_addr_out),32);
        bufp->chgIData(oldp+25,(vlSymsp->TOP__top__u_if2id.__PVT__instr_out),32);
        bufp->chgCData(oldp+26,(vlSymsp->TOP__top__u_reg_file.__PVT__rs1_addr),5);
        bufp->chgCData(oldp+27,(vlSymsp->TOP__top__u_reg_file.__PVT__rs2_addr),5);
        bufp->chgIData(oldp+28,(vlSymsp->TOP__top__u_fetch.__PVT__instr_out),32);
        bufp->chgIData(oldp+29,(vlSymsp->TOP__top__u_decode.__PVT__instr_addr_in),32);
        bufp->chgIData(oldp+30,(vlSymsp->TOP__top__u_decode.__PVT__instr_in),32);
        bufp->chgCData(oldp+31,(vlSymsp->TOP__top__u_decode.__PVT__rd_rs1_addr),5);
        bufp->chgCData(oldp+32,(vlSymsp->TOP__top__u_decode.__PVT__rd_rs2_addr),5);
        bufp->chgCData(oldp+33,(vlSymsp->TOP__top__u_decode.__PVT__rd_addr_out),5);
        bufp->chgIData(oldp+34,(vlSymsp->TOP__top__u_decode.__PVT__imm_out),32);
        bufp->chgCData(oldp+35,(vlSymsp->TOP__top__u_decode.__PVT__op1_sel_out),2);
        bufp->chgCData(oldp+36,(vlSymsp->TOP__top__u_decode.__PVT__op2_sel_out),2);
        bufp->chgCData(oldp+37,(vlSymsp->TOP__top__u_decode.__PVT__opcode_out),7);
        bufp->chgCData(oldp+38,(vlSymsp->TOP__top__u_decode.__PVT__funct3_out),3);
        bufp->chgCData(oldp+39,(vlSymsp->TOP__top__u_decode.__PVT__funct7_out),7);
        bufp->chgBit(oldp+40,(vlSymsp->TOP__top__u_decode.__PVT__inst_ebreak));
        bufp->chgCData(oldp+41,(vlSymsp->TOP__top__u_decode.__PVT__opcode),7);
        bufp->chgCData(oldp+42,(vlSymsp->TOP__top__u_decode.__PVT__rd),5);
        bufp->chgCData(oldp+43,(vlSymsp->TOP__top__u_decode.__PVT__funct3),3);
        bufp->chgCData(oldp+44,(vlSymsp->TOP__top__u_decode.__PVT__rs1),5);
        bufp->chgCData(oldp+45,(vlSymsp->TOP__top__u_decode.__PVT__rs2),5);
        bufp->chgCData(oldp+46,(vlSymsp->TOP__top__u_decode.__PVT__funct7),7);
        bufp->chgIData(oldp+47,(vlSymsp->TOP__top__u_decode.__PVT__imm),32);
        bufp->chgBit(oldp+48,(vlSymsp->TOP__top__u_decode.__PVT__is_ebreak));
        bufp->chgIData(oldp+49,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_addr_in),32);
        bufp->chgIData(oldp+50,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_in),32);
        bufp->chgCData(oldp+51,(vlSymsp->TOP__top__u_id2ex.__PVT__rd_addr_in),5);
        bufp->chgIData(oldp+52,(vlSymsp->TOP__top__u_id2ex.__PVT__imm_in),32);
        bufp->chgCData(oldp+53,(vlSymsp->TOP__top__u_id2ex.__PVT__op1_sel_in),2);
        bufp->chgCData(oldp+54,(vlSymsp->TOP__top__u_id2ex.__PVT__op2_sel_in),2);
        bufp->chgCData(oldp+55,(vlSymsp->TOP__top__u_id2ex.__PVT__opcode_in),7);
        bufp->chgCData(oldp+56,(vlSymsp->TOP__top__u_id2ex.__PVT__funct3_in),3);
        bufp->chgCData(oldp+57,(vlSymsp->TOP__top__u_id2ex.__PVT__funct7_in),7);
        bufp->chgBit(oldp+58,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_ebreak_in));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [4U]))) {
        bufp->chgIData(oldp+59,(vlSymsp->TOP__top.__PVT__reg_rs1_data),32);
        bufp->chgIData(oldp+60,(vlSymsp->TOP__top.__PVT__reg_rs2_data),32);
        bufp->chgIData(oldp+61,(vlSymsp->TOP__top.__PVT__id_instr_addr_out),32);
        bufp->chgIData(oldp+62,(vlSymsp->TOP__top.__PVT__id_instr_out),32);
        bufp->chgIData(oldp+63,(vlSymsp->TOP__top.__PVT__id_op1_out),32);
        bufp->chgIData(oldp+64,(vlSymsp->TOP__top.__PVT__id_op2_out),32);
        bufp->chgCData(oldp+65,(vlSymsp->TOP__top.__PVT__id_rd_addr_out),5);
        bufp->chgIData(oldp+66,(vlSymsp->TOP__top.__PVT__id_imm_out),32);
        bufp->chgCData(oldp+67,(vlSymsp->TOP__top.__PVT__id_opcode_out),7);
        bufp->chgCData(oldp+68,(vlSymsp->TOP__top.__PVT__id_funct3_out),3);
        bufp->chgCData(oldp+69,(vlSymsp->TOP__top.__PVT__id_funct7_out),7);
        bufp->chgIData(oldp+70,(vlSymsp->TOP__top.__PVT__id_rs1_data),32);
        bufp->chgIData(oldp+71,(vlSymsp->TOP__top.__PVT__id_rs2_data),32);
        bufp->chgIData(oldp+72,(vlSymsp->TOP__top.__PVT__ex_alu_result),32);
        bufp->chgBit(oldp+73,(vlSymsp->TOP__top.__PVT__ex_jump_flag));
        bufp->chgIData(oldp+74,(vlSymsp->TOP__top.__PVT__ex_jump_target),32);
        bufp->chgIData(oldp+75,(vlSymsp->TOP__top.__PVT__ex_alu_result_out),32);
        bufp->chgIData(oldp+76,(vlSymsp->TOP__top.__PVT__ex_rs2_data),32);
        bufp->chgCData(oldp+77,(vlSymsp->TOP__top.__PVT__ex_rd_addr),5);
        bufp->chgCData(oldp+78,(vlSymsp->TOP__top.__PVT__ex_opcode),7);
        bufp->chgCData(oldp+79,(vlSymsp->TOP__top.__PVT__ex_funct3),3);
        bufp->chgIData(oldp+80,(vlSymsp->TOP__top.__PVT__mem_rdata),32);
        bufp->chgIData(oldp+81,(vlSymsp->TOP__top.__PVT__mem_alu_result),32);
        bufp->chgIData(oldp+82,(vlSymsp->TOP__top.__PVT__mem_rdata_out),32);
        bufp->chgCData(oldp+83,(vlSymsp->TOP__top.__PVT__mem_rd_addr),5);
        bufp->chgCData(oldp+84,(vlSymsp->TOP__top.__PVT__mem_opcode),7);
        bufp->chgBit(oldp+85,(vlSymsp->TOP__top.__PVT__wb_wr_en));
        bufp->chgCData(oldp+86,(vlSymsp->TOP__top.__PVT__wb_wr_addr),5);
        bufp->chgIData(oldp+87,(vlSymsp->TOP__top.__PVT__wb_wr_data),32);
        bufp->chgBit(oldp+88,(vlSymsp->TOP__top.__PVT__inst_ebreak_out));
        bufp->chgIData(oldp+89,(vlSymsp->TOP__top__u_memory.__PVT__alu_result_in),32);
        bufp->chgIData(oldp+90,(vlSymsp->TOP__top__u_memory.__PVT__rs2_data_in),32);
        bufp->chgCData(oldp+91,(vlSymsp->TOP__top__u_memory.__PVT__opcode_in),7);
        bufp->chgCData(oldp+92,(vlSymsp->TOP__top__u_memory.__PVT__funct3_in),3);
        bufp->chgIData(oldp+93,(vlSymsp->TOP__top__u_memory.__PVT__mem_rdata_out),32);
        bufp->chgIData(oldp+94,(vlSymsp->TOP__top__u_memory.__PVT__rdata_raw),32);
        bufp->chgIData(oldp+95,(vlSymsp->TOP__top__u_writeback.__PVT__alu_result_in),32);
        bufp->chgIData(oldp+96,(vlSymsp->TOP__top__u_writeback.__PVT__mem_rdata_in),32);
        bufp->chgCData(oldp+97,(vlSymsp->TOP__top__u_writeback.__PVT__opcode_in),7);
        bufp->chgCData(oldp+98,(vlSymsp->TOP__top__u_writeback.__PVT__rd_addr_in),5);
        bufp->chgBit(oldp+99,(vlSymsp->TOP__top__u_writeback.__PVT__wb_en));
        bufp->chgCData(oldp+100,(vlSymsp->TOP__top__u_writeback.__PVT__wb_addr),5);
        bufp->chgIData(oldp+101,(vlSymsp->TOP__top__u_writeback.__PVT__wb_data),32);
        bufp->chgIData(oldp+102,(vlSymsp->TOP__top__u_reg_file.__PVT__rs1_data),32);
        bufp->chgIData(oldp+103,(vlSymsp->TOP__top__u_reg_file.__PVT__rs2_data),32);
        bufp->chgBit(oldp+104,(vlSymsp->TOP__top__u_reg_file.__PVT__wr_en));
        bufp->chgCData(oldp+105,(vlSymsp->TOP__top__u_reg_file.__PVT__wr_addr),5);
        bufp->chgIData(oldp+106,(vlSymsp->TOP__top__u_reg_file.__PVT__wr_data),32);
        bufp->chgIData(oldp+107,(vlSymsp->TOP__top__u_mem2wb.__PVT__alu_result_in),32);
        bufp->chgIData(oldp+108,(vlSymsp->TOP__top__u_mem2wb.__PVT__mem_rdata_in),32);
        bufp->chgCData(oldp+109,(vlSymsp->TOP__top__u_mem2wb.__PVT__rd_addr_in),5);
        bufp->chgCData(oldp+110,(vlSymsp->TOP__top__u_mem2wb.__PVT__opcode_in),7);
        bufp->chgIData(oldp+111,(vlSymsp->TOP__top__u_mem2wb.__PVT__alu_result_out),32);
        bufp->chgIData(oldp+112,(vlSymsp->TOP__top__u_mem2wb.__PVT__mem_rdata_out),32);
        bufp->chgCData(oldp+113,(vlSymsp->TOP__top__u_mem2wb.__PVT__rd_addr_out),5);
        bufp->chgCData(oldp+114,(vlSymsp->TOP__top__u_mem2wb.__PVT__opcode_out),7);
        bufp->chgIData(oldp+115,(vlSymsp->TOP__top__u_execute.__PVT__pc_in),32);
        bufp->chgIData(oldp+116,(vlSymsp->TOP__top__u_execute.__PVT__op1_in),32);
        bufp->chgIData(oldp+117,(vlSymsp->TOP__top__u_execute.__PVT__op2_in),32);
        bufp->chgIData(oldp+118,(vlSymsp->TOP__top__u_execute.__PVT__rs1_data_in),32);
        bufp->chgIData(oldp+119,(vlSymsp->TOP__top__u_execute.__PVT__imm_in),32);
        bufp->chgCData(oldp+120,(vlSymsp->TOP__top__u_execute.__PVT__opcode_in),7);
        bufp->chgCData(oldp+121,(vlSymsp->TOP__top__u_execute.__PVT__funct3_in),3);
        bufp->chgCData(oldp+122,(vlSymsp->TOP__top__u_execute.__PVT__funct7_in),7);
        bufp->chgIData(oldp+123,(vlSymsp->TOP__top__u_execute.__PVT__alu_result_out),32);
        bufp->chgBit(oldp+124,(vlSymsp->TOP__top__u_execute.__PVT__jump_flag_out));
        bufp->chgIData(oldp+125,(vlSymsp->TOP__top__u_execute.__PVT__jump_target_out),32);
        bufp->chgBit(oldp+126,(vlSymsp->TOP__top__u_execute.__PVT__inst_ebreak_in));
        bufp->chgIData(oldp+127,(vlSymsp->TOP__top__u_execute.__PVT__alu_res),32);
        bufp->chgBit(oldp+128,(vlSymsp->TOP__top__u_execute.__PVT__branch_taken));
        bufp->chgIData(oldp+129,(vlSymsp->TOP__top__u_id2ex.__PVT__rs1_data_in),32);
        bufp->chgIData(oldp+130,(vlSymsp->TOP__top__u_id2ex.__PVT__rs2_data_in),32);
        bufp->chgIData(oldp+131,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_addr_out),32);
        bufp->chgIData(oldp+132,(vlSymsp->TOP__top__u_id2ex.__PVT__instr_out),32);
        bufp->chgIData(oldp+133,(vlSymsp->TOP__top__u_id2ex.__PVT__op1_out),32);
        bufp->chgIData(oldp+134,(vlSymsp->TOP__top__u_id2ex.__PVT__op2_out),32);
        bufp->chgCData(oldp+135,(vlSymsp->TOP__top__u_id2ex.__PVT__rd_addr_out),5);
        bufp->chgIData(oldp+136,(vlSymsp->TOP__top__u_id2ex.__PVT__imm_out),32);
        bufp->chgCData(oldp+137,(vlSymsp->TOP__top__u_id2ex.__PVT__opcode_out),7);
        bufp->chgCData(oldp+138,(vlSymsp->TOP__top__u_id2ex.__PVT__funct3_out),3);
        bufp->chgCData(oldp+139,(vlSymsp->TOP__top__u_id2ex.__PVT__funct7_out),7);
        bufp->chgIData(oldp+140,(vlSymsp->TOP__top__u_id2ex.__PVT__rs1_data_out),32);
        bufp->chgIData(oldp+141,(vlSymsp->TOP__top__u_id2ex.__PVT__rs2_data_out),32);
        bufp->chgBit(oldp+142,(vlSymsp->TOP__top__u_id2ex.__PVT__inst_ebreak_out));
        bufp->chgIData(oldp+143,(vlSymsp->TOP__top__u_ex2mem.__PVT__pc_in),32);
        bufp->chgIData(oldp+144,(vlSymsp->TOP__top__u_ex2mem.__PVT__alu_result_in),32);
        bufp->chgIData(oldp+145,(vlSymsp->TOP__top__u_ex2mem.__PVT__rs2_data_in),32);
        bufp->chgCData(oldp+146,(vlSymsp->TOP__top__u_ex2mem.__PVT__rd_addr_in),5);
        bufp->chgCData(oldp+147,(vlSymsp->TOP__top__u_ex2mem.__PVT__opcode_in),7);
        bufp->chgCData(oldp+148,(vlSymsp->TOP__top__u_ex2mem.__PVT__funct3_in),3);
        bufp->chgIData(oldp+149,(vlSymsp->TOP__top__u_ex2mem.__PVT__alu_result_out),32);
        bufp->chgIData(oldp+150,(vlSymsp->TOP__top__u_ex2mem.__PVT__rs2_data_out),32);
        bufp->chgCData(oldp+151,(vlSymsp->TOP__top__u_ex2mem.__PVT__rd_addr_out),5);
        bufp->chgCData(oldp+152,(vlSymsp->TOP__top__u_ex2mem.__PVT__opcode_out),7);
        bufp->chgCData(oldp+153,(vlSymsp->TOP__top__u_ex2mem.__PVT__funct3_out),3);
        bufp->chgBit(oldp+154,(vlSymsp->TOP__top__u_pc_counter.__PVT__jump_en));
        bufp->chgIData(oldp+155,(vlSymsp->TOP__top__u_pc_counter.__PVT__jump_addr),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+156,(vlSymsp->TOP__top.pc),32);
        bufp->chgIData(oldp+157,(vlSymsp->TOP__top__u_if2id.__PVT__instr_addr_in),32);
        bufp->chgIData(oldp+158,(vlSymsp->TOP__top__u_fetch.__PVT__pc_pointer),32);
        bufp->chgIData(oldp+159,(vlSymsp->TOP__top__u_pc_counter.__PVT__pc),32);
        bufp->chgIData(oldp+160,(vlSymsp->TOP__top__u_pc_counter.__PVT__pc_pointer),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+161,(vlSymsp->TOP__top.debug_x10),32);
        bufp->chgIData(oldp+162,(vlSymsp->TOP__top.regs[0]),32);
        bufp->chgIData(oldp+163,(vlSymsp->TOP__top.regs[1]),32);
        bufp->chgIData(oldp+164,(vlSymsp->TOP__top.regs[2]),32);
        bufp->chgIData(oldp+165,(vlSymsp->TOP__top.regs[3]),32);
        bufp->chgIData(oldp+166,(vlSymsp->TOP__top.regs[4]),32);
        bufp->chgIData(oldp+167,(vlSymsp->TOP__top.regs[5]),32);
        bufp->chgIData(oldp+168,(vlSymsp->TOP__top.regs[6]),32);
        bufp->chgIData(oldp+169,(vlSymsp->TOP__top.regs[7]),32);
        bufp->chgIData(oldp+170,(vlSymsp->TOP__top.regs[8]),32);
        bufp->chgIData(oldp+171,(vlSymsp->TOP__top.regs[9]),32);
        bufp->chgIData(oldp+172,(vlSymsp->TOP__top.regs[10]),32);
        bufp->chgIData(oldp+173,(vlSymsp->TOP__top.regs[11]),32);
        bufp->chgIData(oldp+174,(vlSymsp->TOP__top.regs[12]),32);
        bufp->chgIData(oldp+175,(vlSymsp->TOP__top.regs[13]),32);
        bufp->chgIData(oldp+176,(vlSymsp->TOP__top.regs[14]),32);
        bufp->chgIData(oldp+177,(vlSymsp->TOP__top.regs[15]),32);
        bufp->chgIData(oldp+178,(vlSymsp->TOP__top__u_reg_file.__PVT__debug_x10),32);
        bufp->chgIData(oldp+179,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[0]),32);
        bufp->chgIData(oldp+180,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[1]),32);
        bufp->chgIData(oldp+181,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[2]),32);
        bufp->chgIData(oldp+182,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[3]),32);
        bufp->chgIData(oldp+183,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[4]),32);
        bufp->chgIData(oldp+184,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[5]),32);
        bufp->chgIData(oldp+185,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[6]),32);
        bufp->chgIData(oldp+186,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[7]),32);
        bufp->chgIData(oldp+187,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[8]),32);
        bufp->chgIData(oldp+188,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[9]),32);
        bufp->chgIData(oldp+189,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[10]),32);
        bufp->chgIData(oldp+190,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[11]),32);
        bufp->chgIData(oldp+191,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[12]),32);
        bufp->chgIData(oldp+192,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[13]),32);
        bufp->chgIData(oldp+193,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[14]),32);
        bufp->chgIData(oldp+194,(vlSymsp->TOP__top__u_reg_file.__PVT__regs[15]),32);
        bufp->chgIData(oldp+195,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[0]),32);
        bufp->chgIData(oldp+196,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[1]),32);
        bufp->chgIData(oldp+197,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[2]),32);
        bufp->chgIData(oldp+198,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[3]),32);
        bufp->chgIData(oldp+199,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[4]),32);
        bufp->chgIData(oldp+200,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[5]),32);
        bufp->chgIData(oldp+201,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[6]),32);
        bufp->chgIData(oldp+202,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[7]),32);
        bufp->chgIData(oldp+203,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[8]),32);
        bufp->chgIData(oldp+204,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[9]),32);
        bufp->chgIData(oldp+205,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[10]),32);
        bufp->chgIData(oldp+206,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[11]),32);
        bufp->chgIData(oldp+207,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[12]),32);
        bufp->chgIData(oldp+208,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[13]),32);
        bufp->chgIData(oldp+209,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[14]),32);
        bufp->chgIData(oldp+210,(vlSymsp->TOP__top__u_reg_file.__PVT__rf[15]),32);
        bufp->chgIData(oldp+211,(vlSymsp->TOP__top__u_reg_file.__PVT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+212,(vlSelfRef.clk));
    bufp->chgBit(oldp+213,(vlSelfRef.rst_n));
    bufp->chgIData(oldp+214,(vlSelfRef.pc),32);
    bufp->chgIData(oldp+215,(vlSelfRef.instr),32);
    bufp->chgIData(oldp+216,(vlSelfRef.debug_x10),32);
    bufp->chgIData(oldp+217,(vlSelfRef.regs[0]),32);
    bufp->chgIData(oldp+218,(vlSelfRef.regs[1]),32);
    bufp->chgIData(oldp+219,(vlSelfRef.regs[2]),32);
    bufp->chgIData(oldp+220,(vlSelfRef.regs[3]),32);
    bufp->chgIData(oldp+221,(vlSelfRef.regs[4]),32);
    bufp->chgIData(oldp+222,(vlSelfRef.regs[5]),32);
    bufp->chgIData(oldp+223,(vlSelfRef.regs[6]),32);
    bufp->chgIData(oldp+224,(vlSelfRef.regs[7]),32);
    bufp->chgIData(oldp+225,(vlSelfRef.regs[8]),32);
    bufp->chgIData(oldp+226,(vlSelfRef.regs[9]),32);
    bufp->chgIData(oldp+227,(vlSelfRef.regs[10]),32);
    bufp->chgIData(oldp+228,(vlSelfRef.regs[11]),32);
    bufp->chgIData(oldp+229,(vlSelfRef.regs[12]),32);
    bufp->chgIData(oldp+230,(vlSelfRef.regs[13]),32);
    bufp->chgIData(oldp+231,(vlSelfRef.regs[14]),32);
    bufp->chgIData(oldp+232,(vlSelfRef.regs[15]),32);
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
}
