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
        bufp->chgIData(oldp+0,(vlSymsp->TOP__top__u_core.__PVT__trap_cause),32);
        bufp->chgIData(oldp+1,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_cause),32);
        bufp->chgIData(oldp+2,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_cause),32);
        bufp->chgBit(oldp+3,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__up_valid));
        bufp->chgBit(oldp+4,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__stall));
        bufp->chgBit(oldp+5,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__flush));
        bufp->chgBit(oldp+6,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__stall));
        bufp->chgBit(oldp+7,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__flush));
        bufp->chgBit(oldp+8,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__stall));
        bufp->chgBit(oldp+9,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__dn_ready));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+10,(vlSymsp->TOP__top.clk));
        bufp->chgBit(oldp+11,(vlSymsp->TOP__top.rst_n));
        bufp->chgBit(oldp+12,(vlSymsp->TOP__top__u_core.__PVT__clk));
        bufp->chgBit(oldp+13,(vlSymsp->TOP__top__u_core.__PVT__rst_n));
        bufp->chgBit(oldp+14,(vlSymsp->TOP__top__u_core__u_memory.__PVT__clk));
        bufp->chgBit(oldp+15,(vlSymsp->TOP__top__u_core__u_memory.__PVT__rst_n));
        bufp->chgBit(oldp+16,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__clk));
        bufp->chgBit(oldp+17,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__rst));
        bufp->chgBit(oldp+18,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__clk));
        bufp->chgBit(oldp+19,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rst_n));
        bufp->chgBit(oldp+20,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__clk));
        bufp->chgBit(oldp+21,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__rst_n));
        bufp->chgBit(oldp+22,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__clk));
        bufp->chgBit(oldp+23,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__rst_n));
        bufp->chgBit(oldp+24,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__clk));
        bufp->chgBit(oldp+25,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__rst_n));
        bufp->chgBit(oldp+26,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__clk));
        bufp->chgBit(oldp+27,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__rst_n));
        bufp->chgBit(oldp+28,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__clk));
        bufp->chgBit(oldp+29,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__rst_n));
        bufp->chgBit(oldp+30,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__clk));
        bufp->chgBit(oldp+31,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__rst_n));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+32,(vlSymsp->TOP__top.pc),32);
        bufp->chgIData(oldp+33,(vlSymsp->TOP__top__u_core.__PVT__pc),32);
        bufp->chgIData(oldp+34,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__pc_pointer),32);
        bufp->chgIData(oldp+35,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__pc),32);
        bufp->chgIData(oldp+36,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__pc_pointer),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[3U])) {
        bufp->chgIData(oldp+37,(vlSymsp->TOP__top__u_core.__PVT__trap_mtvec),32);
        bufp->chgIData(oldp+38,(vlSymsp->TOP__top__u_core.__PVT__trap_mepc),32);
        bufp->chgIData(oldp+39,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_mtvec),32);
        bufp->chgIData(oldp+40,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_mepc),32);
        bufp->chgIData(oldp+41,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mstatus),32);
        bufp->chgIData(oldp+42,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mtvec),32);
        bufp->chgIData(oldp+43,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mepc),32);
        bufp->chgIData(oldp+44,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mcause),32);
        bufp->chgQData(oldp+45,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__mcycle_cnt),64);
        bufp->chgIData(oldp+47,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_mtvec),32);
        bufp->chgIData(oldp+48,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_mepc),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+49,(vlSymsp->TOP__top.regs[0]),32);
        bufp->chgIData(oldp+50,(vlSymsp->TOP__top.regs[1]),32);
        bufp->chgIData(oldp+51,(vlSymsp->TOP__top.regs[2]),32);
        bufp->chgIData(oldp+52,(vlSymsp->TOP__top.regs[3]),32);
        bufp->chgIData(oldp+53,(vlSymsp->TOP__top.regs[4]),32);
        bufp->chgIData(oldp+54,(vlSymsp->TOP__top.regs[5]),32);
        bufp->chgIData(oldp+55,(vlSymsp->TOP__top.regs[6]),32);
        bufp->chgIData(oldp+56,(vlSymsp->TOP__top.regs[7]),32);
        bufp->chgIData(oldp+57,(vlSymsp->TOP__top.regs[8]),32);
        bufp->chgIData(oldp+58,(vlSymsp->TOP__top.regs[9]),32);
        bufp->chgIData(oldp+59,(vlSymsp->TOP__top.regs[10]),32);
        bufp->chgIData(oldp+60,(vlSymsp->TOP__top.regs[11]),32);
        bufp->chgIData(oldp+61,(vlSymsp->TOP__top.regs[12]),32);
        bufp->chgIData(oldp+62,(vlSymsp->TOP__top.regs[13]),32);
        bufp->chgIData(oldp+63,(vlSymsp->TOP__top.regs[14]),32);
        bufp->chgIData(oldp+64,(vlSymsp->TOP__top.regs[15]),32);
        bufp->chgIData(oldp+65,(vlSymsp->TOP__top__u_core.__PVT__regs[0]),32);
        bufp->chgIData(oldp+66,(vlSymsp->TOP__top__u_core.__PVT__regs[1]),32);
        bufp->chgIData(oldp+67,(vlSymsp->TOP__top__u_core.__PVT__regs[2]),32);
        bufp->chgIData(oldp+68,(vlSymsp->TOP__top__u_core.__PVT__regs[3]),32);
        bufp->chgIData(oldp+69,(vlSymsp->TOP__top__u_core.__PVT__regs[4]),32);
        bufp->chgIData(oldp+70,(vlSymsp->TOP__top__u_core.__PVT__regs[5]),32);
        bufp->chgIData(oldp+71,(vlSymsp->TOP__top__u_core.__PVT__regs[6]),32);
        bufp->chgIData(oldp+72,(vlSymsp->TOP__top__u_core.__PVT__regs[7]),32);
        bufp->chgIData(oldp+73,(vlSymsp->TOP__top__u_core.__PVT__regs[8]),32);
        bufp->chgIData(oldp+74,(vlSymsp->TOP__top__u_core.__PVT__regs[9]),32);
        bufp->chgIData(oldp+75,(vlSymsp->TOP__top__u_core.__PVT__regs[10]),32);
        bufp->chgIData(oldp+76,(vlSymsp->TOP__top__u_core.__PVT__regs[11]),32);
        bufp->chgIData(oldp+77,(vlSymsp->TOP__top__u_core.__PVT__regs[12]),32);
        bufp->chgIData(oldp+78,(vlSymsp->TOP__top__u_core.__PVT__regs[13]),32);
        bufp->chgIData(oldp+79,(vlSymsp->TOP__top__u_core.__PVT__regs[14]),32);
        bufp->chgIData(oldp+80,(vlSymsp->TOP__top__u_core.__PVT__regs[15]),32);
        bufp->chgIData(oldp+81,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[0]),32);
        bufp->chgIData(oldp+82,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[1]),32);
        bufp->chgIData(oldp+83,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[2]),32);
        bufp->chgIData(oldp+84,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[3]),32);
        bufp->chgIData(oldp+85,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[4]),32);
        bufp->chgIData(oldp+86,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[5]),32);
        bufp->chgIData(oldp+87,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[6]),32);
        bufp->chgIData(oldp+88,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[7]),32);
        bufp->chgIData(oldp+89,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[8]),32);
        bufp->chgIData(oldp+90,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[9]),32);
        bufp->chgIData(oldp+91,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[10]),32);
        bufp->chgIData(oldp+92,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[11]),32);
        bufp->chgIData(oldp+93,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[12]),32);
        bufp->chgIData(oldp+94,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[13]),32);
        bufp->chgIData(oldp+95,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[14]),32);
        bufp->chgIData(oldp+96,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__regs[15]),32);
        bufp->chgIData(oldp+97,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[0]),32);
        bufp->chgIData(oldp+98,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[1]),32);
        bufp->chgIData(oldp+99,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[2]),32);
        bufp->chgIData(oldp+100,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[3]),32);
        bufp->chgIData(oldp+101,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[4]),32);
        bufp->chgIData(oldp+102,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[5]),32);
        bufp->chgIData(oldp+103,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[6]),32);
        bufp->chgIData(oldp+104,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[7]),32);
        bufp->chgIData(oldp+105,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[8]),32);
        bufp->chgIData(oldp+106,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[9]),32);
        bufp->chgIData(oldp+107,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[10]),32);
        bufp->chgIData(oldp+108,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[11]),32);
        bufp->chgIData(oldp+109,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[12]),32);
        bufp->chgIData(oldp+110,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[13]),32);
        bufp->chgIData(oldp+111,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[14]),32);
        bufp->chgIData(oldp+112,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rf[15]),32);
        bufp->chgIData(oldp+113,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[5U])) {
        bufp->chgBit(oldp+114,(vlSymsp->TOP__top.debug_wb_have));
        bufp->chgIData(oldp+115,(vlSymsp->TOP__top.debug_wb_pc),32);
        bufp->chgIData(oldp+116,(vlSymsp->TOP__top.debug_wb_instr),32);
        bufp->chgBit(oldp+117,(vlSymsp->TOP__top.debug_wb_ena));
        bufp->chgCData(oldp+118,(vlSymsp->TOP__top.debug_wb_addr),5);
        bufp->chgIData(oldp+119,(vlSymsp->TOP__top.debug_wb_data),32);
        bufp->chgBit(oldp+120,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_have));
        bufp->chgIData(oldp+121,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_pc),32);
        bufp->chgIData(oldp+122,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_instr),32);
        bufp->chgBit(oldp+123,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_ena));
        bufp->chgCData(oldp+124,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_addr),5);
        bufp->chgIData(oldp+125,(vlSymsp->TOP__top__u_core.__PVT__debug_wb_data),32);
        bufp->chgBit(oldp+126,(vlSymsp->TOP__top__u_core.__PVT__mem2wb_up_ready));
        bufp->chgBit(oldp+127,(vlSymsp->TOP__top__u_core.__PVT__mem2wb_dn_valid));
        bufp->chgWData(oldp+128,(vlSymsp->TOP__top__u_core.__PVT__mem_wb_dn),140);
        bufp->chgBit(oldp+133,(vlSymsp->TOP__top__u_core.__PVT__wb_wr_en));
        bufp->chgCData(oldp+134,(vlSymsp->TOP__top__u_core.__PVT__wb_wr_addr),5);
        bufp->chgIData(oldp+135,(vlSymsp->TOP__top__u_core.__PVT__wb_wr_data),32);
        bufp->chgIData(oldp+136,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__alu_result_in),32);
        bufp->chgIData(oldp+137,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__mem_rdata_in),32);
        bufp->chgCData(oldp+138,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__opcode_in),7);
        bufp->chgCData(oldp+139,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__rd_addr_in),5);
        bufp->chgBit(oldp+140,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__wb_en));
        bufp->chgCData(oldp+141,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__wb_addr),5);
        bufp->chgIData(oldp+142,(vlSymsp->TOP__top__u_core__u_writeback.__PVT__wb_data),32);
        bufp->chgBit(oldp+143,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__wr_en));
        bufp->chgCData(oldp+144,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__wr_addr),5);
        bufp->chgIData(oldp+145,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__wr_data),32);
        bufp->chgCData(oldp+146,(vlSymsp->TOP__top__u_core__u_forward.__PVT__wb_rd_addr),5);
        bufp->chgCData(oldp+147,(vlSymsp->TOP__top__u_core__u_forward.__PVT__wb_opcode),7);
        bufp->chgBit(oldp+148,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__dn_ready));
        bufp->chgBit(oldp+149,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__up_ready));
        bufp->chgBit(oldp+150,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__dn_valid));
        bufp->chgWData(oldp+151,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__dn_data),140);
        bufp->chgWData(oldp+156,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__data_q),140);
        bufp->chgBit(oldp+161,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__valid_q));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[6U])) {
        bufp->chgBit(oldp+162,(vlSymsp->TOP__top__u_core.__PVT__ex2mem_dn_valid));
        bufp->chgWData(oldp+163,(vlSymsp->TOP__top__u_core.__PVT__ex_mem_dn),143);
        bufp->chgWData(oldp+168,(vlSymsp->TOP__top__u_core.__PVT__mem_wb_up),140);
        bufp->chgIData(oldp+173,(vlSymsp->TOP__top__u_core.__PVT__mem_rdata),32);
        bufp->chgIData(oldp+174,(vlSymsp->TOP__top__u_core__u_memory.__PVT__alu_result_in),32);
        bufp->chgIData(oldp+175,(vlSymsp->TOP__top__u_core__u_memory.__PVT__rs2_data_in),32);
        bufp->chgCData(oldp+176,(vlSymsp->TOP__top__u_core__u_memory.__PVT__opcode_in),7);
        bufp->chgCData(oldp+177,(vlSymsp->TOP__top__u_core__u_memory.__PVT__funct3_in),3);
        bufp->chgIData(oldp+178,(vlSymsp->TOP__top__u_core__u_memory.__PVT__mem_rdata_out),32);
        bufp->chgIData(oldp+179,(vlSymsp->TOP__top__u_core__u_memory.__PVT__rdata_raw),32);
        bufp->chgCData(oldp+180,(vlSymsp->TOP__top__u_core__u_forward.__PVT__mem_rd_addr),5);
        bufp->chgCData(oldp+181,(vlSymsp->TOP__top__u_core__u_forward.__PVT__mem_opcode),7);
        bufp->chgBit(oldp+182,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__dn_valid));
        bufp->chgWData(oldp+183,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__dn_data),143);
        bufp->chgWData(oldp+188,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__data_q),143);
        bufp->chgBit(oldp+193,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__valid_q));
        bufp->chgBit(oldp+194,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__up_valid));
        bufp->chgWData(oldp+195,(vlSymsp->TOP__top__u_core__u_mem2wb.__PVT__up_data),140);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[7U])) {
        bufp->chgBit(oldp+200,(vlSymsp->TOP__top__u_core.__PVT__id2ex_dn_valid));
        bufp->chgWData(oldp+201,(vlSymsp->TOP__top__u_core.__PVT__id_ex_dn),263);
        bufp->chgSData(oldp+210,(vlSymsp->TOP__top__u_core.__PVT__csr_raddr),12);
        bufp->chgBit(oldp+211,(vlSymsp->TOP__top__u_core.__PVT__csr_wen));
        bufp->chgSData(oldp+212,(vlSymsp->TOP__top__u_core.__PVT__csr_waddr),12);
        bufp->chgBit(oldp+213,(vlSymsp->TOP__top__u_core.__PVT__trap_valid));
        bufp->chgIData(oldp+214,(vlSymsp->TOP__top__u_core.__PVT__trap_pc),32);
        bufp->chgSData(oldp+215,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_raddr),12);
        bufp->chgBit(oldp+216,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_wen));
        bufp->chgSData(oldp+217,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_waddr),12);
        bufp->chgBit(oldp+218,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_valid));
        bufp->chgIData(oldp+219,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__trap_pc),32);
        bufp->chgCData(oldp+220,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_stage_rd_addr),5);
        bufp->chgCData(oldp+221,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_stage_opcode),7);
        bufp->chgCData(oldp+222,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__ex_opcode),7);
        bufp->chgCData(oldp+223,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__ex_rd_addr),5);
        bufp->chgBit(oldp+224,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__ex_is_load));
        bufp->chgIData(oldp+225,(vlSymsp->TOP__top__u_core__u_execute.__PVT__pc_in),32);
        bufp->chgIData(oldp+226,(vlSymsp->TOP__top__u_core__u_execute.__PVT__op1_in),32);
        bufp->chgIData(oldp+227,(vlSymsp->TOP__top__u_core__u_execute.__PVT__op2_in),32);
        bufp->chgIData(oldp+228,(vlSymsp->TOP__top__u_core__u_execute.__PVT__rs1_data_in),32);
        bufp->chgIData(oldp+229,(vlSymsp->TOP__top__u_core__u_execute.__PVT__imm_in),32);
        bufp->chgCData(oldp+230,(vlSymsp->TOP__top__u_core__u_execute.__PVT__opcode_in),7);
        bufp->chgCData(oldp+231,(vlSymsp->TOP__top__u_core__u_execute.__PVT__funct3_in),3);
        bufp->chgCData(oldp+232,(vlSymsp->TOP__top__u_core__u_execute.__PVT__funct7_in),7);
        bufp->chgBit(oldp+233,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_ebreak_in));
        bufp->chgSData(oldp+234,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_addr_in),12);
        bufp->chgBit(oldp+235,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_csrrw));
        bufp->chgBit(oldp+236,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_csrrs));
        bufp->chgBit(oldp+237,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_ecall));
        bufp->chgBit(oldp+238,(vlSymsp->TOP__top__u_core__u_execute.__PVT__inst_mret));
        bufp->chgSData(oldp+239,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_raddr),12);
        bufp->chgBit(oldp+240,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_wen));
        bufp->chgSData(oldp+241,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_waddr),12);
        bufp->chgBit(oldp+242,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_valid));
        bufp->chgIData(oldp+243,(vlSymsp->TOP__top__u_core__u_execute.__PVT__trap_pc),32);
        bufp->chgIData(oldp+244,(vlSymsp->TOP__top__u_core__u_execute.__PVT__alu_res),32);
        bufp->chgBit(oldp+245,(vlSymsp->TOP__top__u_core__u_execute.__PVT__branch_taken));
        bufp->chgBit(oldp+246,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__dn_valid));
        bufp->chgWData(oldp+247,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__dn_data),263);
        bufp->chgWData(oldp+256,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__data_q),263);
        bufp->chgBit(oldp+265,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__valid_q));
        bufp->chgBit(oldp+266,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__up_valid));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[7U] 
                     | vlSelfRef.__Vm_traceActivity
                     [0xaU]))) {
        bufp->chgWData(oldp+267,(vlSymsp->TOP__top__u_core.__PVT__ex_mem_up),143);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[8U])) {
        bufp->chgBit(oldp+272,(vlSymsp->TOP__top__u_core.__PVT__if2id_dn_valid));
        bufp->chgQData(oldp+273,(vlSymsp->TOP__top__u_core.__PVT__if_id_dn),64);
        bufp->chgCData(oldp+275,(vlSymsp->TOP__top__u_core.__PVT__decode_rs1_addr),5);
        bufp->chgCData(oldp+276,(vlSymsp->TOP__top__u_core.__PVT__decode_rs2_addr),5);
        bufp->chgCData(oldp+277,(vlSymsp->TOP__top__u_core.__PVT__decode_rd_addr),5);
        bufp->chgIData(oldp+278,(vlSymsp->TOP__top__u_core.__PVT__decode_imm),32);
        bufp->chgCData(oldp+279,(vlSymsp->TOP__top__u_core.__PVT__decode_op1_sel),2);
        bufp->chgCData(oldp+280,(vlSymsp->TOP__top__u_core.__PVT__decode_op2_sel),2);
        bufp->chgCData(oldp+281,(vlSymsp->TOP__top__u_core.__PVT__decode_opcode),7);
        bufp->chgCData(oldp+282,(vlSymsp->TOP__top__u_core.__PVT__decode_funct3),3);
        bufp->chgCData(oldp+283,(vlSymsp->TOP__top__u_core.__PVT__decode_funct7),7);
        bufp->chgSData(oldp+284,(vlSymsp->TOP__top__u_core.__PVT__decode_csr_addr),12);
        bufp->chgBit(oldp+285,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_csrrw));
        bufp->chgBit(oldp+286,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_csrrs));
        bufp->chgBit(oldp+287,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_ecall));
        bufp->chgBit(oldp+288,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_mret));
        bufp->chgBit(oldp+289,(vlSymsp->TOP__top__u_core.__PVT__decode_inst_ebreak));
        bufp->chgCData(oldp+290,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs1_addr),5);
        bufp->chgCData(oldp+291,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs2_addr),5);
        bufp->chgCData(oldp+292,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_rs1_addr),5);
        bufp->chgCData(oldp+293,(vlSymsp->TOP__top__u_core__u_forward.__PVT__ex_rs2_addr),5);
        bufp->chgIData(oldp+294,(vlSymsp->TOP__top__u_core__u_decode.__PVT__instr_addr_in),32);
        bufp->chgIData(oldp+295,(vlSymsp->TOP__top__u_core__u_decode.__PVT__instr_in),32);
        bufp->chgCData(oldp+296,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rd_rs1_addr),5);
        bufp->chgCData(oldp+297,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rd_rs2_addr),5);
        bufp->chgCData(oldp+298,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rd_addr_out),5);
        bufp->chgIData(oldp+299,(vlSymsp->TOP__top__u_core__u_decode.__PVT__imm_out),32);
        bufp->chgCData(oldp+300,(vlSymsp->TOP__top__u_core__u_decode.__PVT__op1_sel_out),2);
        bufp->chgCData(oldp+301,(vlSymsp->TOP__top__u_core__u_decode.__PVT__op2_sel_out),2);
        bufp->chgCData(oldp+302,(vlSymsp->TOP__top__u_core__u_decode.__PVT__opcode_out),7);
        bufp->chgCData(oldp+303,(vlSymsp->TOP__top__u_core__u_decode.__PVT__funct3_out),3);
        bufp->chgCData(oldp+304,(vlSymsp->TOP__top__u_core__u_decode.__PVT__funct7_out),7);
        bufp->chgBit(oldp+305,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_ebreak));
        bufp->chgSData(oldp+306,(vlSymsp->TOP__top__u_core__u_decode.__PVT__csr_addr_out),12);
        bufp->chgBit(oldp+307,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_csrrw));
        bufp->chgBit(oldp+308,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_csrrs));
        bufp->chgBit(oldp+309,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_ecall));
        bufp->chgBit(oldp+310,(vlSymsp->TOP__top__u_core__u_decode.__PVT__inst_mret));
        bufp->chgCData(oldp+311,(vlSymsp->TOP__top__u_core__u_decode.__PVT__opcode),7);
        bufp->chgCData(oldp+312,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rd),5);
        bufp->chgCData(oldp+313,(vlSymsp->TOP__top__u_core__u_decode.__PVT__funct3),3);
        bufp->chgCData(oldp+314,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rs1),5);
        bufp->chgCData(oldp+315,(vlSymsp->TOP__top__u_core__u_decode.__PVT__rs2),5);
        bufp->chgCData(oldp+316,(vlSymsp->TOP__top__u_core__u_decode.__PVT__funct7),7);
        bufp->chgIData(oldp+317,(vlSymsp->TOP__top__u_core__u_decode.__PVT__imm),32);
        bufp->chgBit(oldp+318,(vlSymsp->TOP__top__u_core__u_decode.__PVT__is_ebreak));
        bufp->chgBit(oldp+319,(vlSymsp->TOP__top__u_core__u_decode.__PVT__is_system));
        bufp->chgCData(oldp+320,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__id_rs1_addr),5);
        bufp->chgCData(oldp+321,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__id_rs2_addr),5);
        bufp->chgBit(oldp+322,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__dn_valid));
        bufp->chgQData(oldp+323,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__dn_data),64);
        bufp->chgQData(oldp+325,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__data_q),64);
        bufp->chgBit(oldp+327,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__valid_q));
        bufp->chgBit(oldp+328,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__up_valid));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[8U] 
                     | vlSelfRef.__Vm_traceActivity
                     [0xfU]))) {
        bufp->chgWData(oldp+329,(vlSymsp->TOP__top__u_core.__PVT__id_ex_up),263);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[9U])) {
        bufp->chgBit(oldp+338,(vlSymsp->TOP__top__u_core.__PVT__ex2mem_up_ready));
        bufp->chgBit(oldp+339,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__dn_ready));
        bufp->chgBit(oldp+340,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__up_ready));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[0xaU])) {
        bufp->chgIData(oldp+341,(vlSymsp->TOP__top__u_core.__PVT__ex_alu_result),32);
        bufp->chgBit(oldp+342,(vlSymsp->TOP__top__u_core.__PVT__ex_jump_flag));
        bufp->chgIData(oldp+343,(vlSymsp->TOP__top__u_core.__PVT__ex_jump_target),32);
        bufp->chgIData(oldp+344,(vlSymsp->TOP__top__u_core.__PVT__csr_rdata),32);
        bufp->chgIData(oldp+345,(vlSymsp->TOP__top__u_core.__PVT__csr_wdata),32);
        bufp->chgIData(oldp+346,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_rdata),32);
        bufp->chgIData(oldp+347,(vlSymsp->TOP__top__u_core__u_csr_file.__PVT__csr_wdata),32);
        bufp->chgIData(oldp+348,(vlSymsp->TOP__top__u_core__u_execute.__PVT__alu_result_out),32);
        bufp->chgBit(oldp+349,(vlSymsp->TOP__top__u_core__u_execute.__PVT__jump_flag_out));
        bufp->chgIData(oldp+350,(vlSymsp->TOP__top__u_core__u_execute.__PVT__jump_target_out),32);
        bufp->chgIData(oldp+351,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_rdata),32);
        bufp->chgIData(oldp+352,(vlSymsp->TOP__top__u_core__u_execute.__PVT__csr_wdata),32);
        bufp->chgBit(oldp+353,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__flush));
        bufp->chgWData(oldp+354,(vlSymsp->TOP__top__u_core__u_ex2mem.__PVT__up_data),143);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[0xbU])) {
        bufp->chgBit(oldp+359,(vlSymsp->TOP__top__u_core.__PVT__load_stall));
        bufp->chgBit(oldp+360,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__stall));
        bufp->chgBit(oldp+361,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__rs1_hazard));
        bufp->chgBit(oldp+362,(vlSymsp->TOP__top__u_core__u_hazard.__PVT__rs2_hazard));
        bufp->chgBit(oldp+363,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__stall));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[0xcU])) {
        bufp->chgIData(oldp+364,(vlSymsp->TOP__top__u_core.__PVT__reg_rs1_data),32);
        bufp->chgIData(oldp+365,(vlSymsp->TOP__top__u_core.__PVT__reg_rs2_data),32);
        bufp->chgIData(oldp+366,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs1_data),32);
        bufp->chgIData(oldp+367,(vlSymsp->TOP__top__u_core__u_reg_file.__PVT__rs2_data),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[0xdU])) {
        bufp->chgCData(oldp+368,(vlSymsp->TOP__top__u_core.__PVT__fwd_rs1_sel),2);
        bufp->chgCData(oldp+369,(vlSymsp->TOP__top__u_core.__PVT__fwd_rs2_sel),2);
        bufp->chgCData(oldp+370,(vlSymsp->TOP__top__u_core__u_forward.__PVT__fwd_rs1_sel),2);
        bufp->chgCData(oldp+371,(vlSymsp->TOP__top__u_core__u_forward.__PVT__fwd_rs2_sel),2);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[0xeU])) {
        bufp->chgBit(oldp+372,(vlSymsp->TOP__top__u_core.__PVT__id2ex_up_ready));
        bufp->chgBit(oldp+373,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__dn_ready));
        bufp->chgBit(oldp+374,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__up_ready));
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[0xfU])) {
        bufp->chgIData(oldp+375,(vlSymsp->TOP__top__u_core.__PVT__fwd_rs1_data),32);
        bufp->chgIData(oldp+376,(vlSymsp->TOP__top__u_core.__PVT__fwd_rs2_data),32);
        bufp->chgIData(oldp+377,(vlSymsp->TOP__top__u_core.__PVT__id_op1),32);
        bufp->chgIData(oldp+378,(vlSymsp->TOP__top__u_core.__PVT__id_op2),32);
        bufp->chgWData(oldp+379,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__up_data),263);
    }
    bufp->chgBit(oldp+388,(vlSelfRef.clk));
    bufp->chgBit(oldp+389,(vlSelfRef.rst_n));
    bufp->chgIData(oldp+390,(vlSelfRef.pc),32);
    bufp->chgIData(oldp+391,(vlSelfRef.instr),32);
    bufp->chgIData(oldp+392,(vlSelfRef.regs[0]),32);
    bufp->chgIData(oldp+393,(vlSelfRef.regs[1]),32);
    bufp->chgIData(oldp+394,(vlSelfRef.regs[2]),32);
    bufp->chgIData(oldp+395,(vlSelfRef.regs[3]),32);
    bufp->chgIData(oldp+396,(vlSelfRef.regs[4]),32);
    bufp->chgIData(oldp+397,(vlSelfRef.regs[5]),32);
    bufp->chgIData(oldp+398,(vlSelfRef.regs[6]),32);
    bufp->chgIData(oldp+399,(vlSelfRef.regs[7]),32);
    bufp->chgIData(oldp+400,(vlSelfRef.regs[8]),32);
    bufp->chgIData(oldp+401,(vlSelfRef.regs[9]),32);
    bufp->chgIData(oldp+402,(vlSelfRef.regs[10]),32);
    bufp->chgIData(oldp+403,(vlSelfRef.regs[11]),32);
    bufp->chgIData(oldp+404,(vlSelfRef.regs[12]),32);
    bufp->chgIData(oldp+405,(vlSelfRef.regs[13]),32);
    bufp->chgIData(oldp+406,(vlSelfRef.regs[14]),32);
    bufp->chgIData(oldp+407,(vlSelfRef.regs[15]),32);
    bufp->chgBit(oldp+408,(vlSelfRef.debug_wb_have));
    bufp->chgIData(oldp+409,(vlSelfRef.debug_wb_pc),32);
    bufp->chgIData(oldp+410,(vlSelfRef.debug_wb_instr),32);
    bufp->chgBit(oldp+411,(vlSelfRef.debug_wb_ena));
    bufp->chgCData(oldp+412,(vlSelfRef.debug_wb_addr),5);
    bufp->chgIData(oldp+413,(vlSelfRef.debug_wb_data),32);
    bufp->chgIData(oldp+414,(vlSymsp->TOP__top.instr),32);
    bufp->chgIData(oldp+415,(vlSymsp->TOP__top__u_core.__PVT__instr),32);
    bufp->chgBit(oldp+416,(vlSymsp->TOP__top__u_core.__PVT__if2id_up_ready));
    bufp->chgQData(oldp+417,(vlSymsp->TOP__top__u_core.__PVT__if_id_up),64);
    bufp->chgIData(oldp+419,(vlSymsp->TOP__top__u_core__u_fetch.__PVT__instr_out),32);
    bufp->chgBit(oldp+420,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__jump_en));
    bufp->chgIData(oldp+421,(vlSymsp->TOP__top__u_core__u_pc_counter.__PVT__jump_addr),32);
    bufp->chgBit(oldp+422,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__up_ready));
    bufp->chgQData(oldp+423,(vlSymsp->TOP__top__u_core__u_if2id.__PVT__up_data),64);
    bufp->chgBit(oldp+425,(vlSymsp->TOP__top__u_core__u_id2ex.__PVT__flush));
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
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[9U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xaU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xbU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xcU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xdU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xeU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xfU] = 0U;
}
