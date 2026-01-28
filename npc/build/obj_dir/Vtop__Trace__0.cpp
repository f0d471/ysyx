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
        bufp->chgBit(oldp+0,(vlSelfRef.top__DOT__ex_jump_flag));
        bufp->chgIData(oldp+1,(vlSelfRef.top__DOT__ex_jump_target),32);
        bufp->chgIData(oldp+2,(vlSelfRef.top__DOT__pc_pointer),32);
        bufp->chgIData(oldp+3,(vlSelfRef.top__DOT__id_pc),32);
        bufp->chgIData(oldp+4,(vlSelfRef.top__DOT__id_instr),32);
        bufp->chgCData(oldp+5,(vlSelfRef.top__DOT__id_rs1_addr),5);
        bufp->chgCData(oldp+6,(vlSelfRef.top__DOT__id_rs2_addr),5);
        bufp->chgIData(oldp+7,(vlSelfRef.top__DOT__id_rs1_data),32);
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__id_rs2_data),32);
        bufp->chgCData(oldp+9,((0x1fU & (vlSelfRef.top__DOT__id_instr 
                                         >> 7U))),5);
        bufp->chgIData(oldp+10,(vlSelfRef.top__DOT__id_op1),32);
        bufp->chgIData(oldp+11,(vlSelfRef.top__DOT__id_op2),32);
        bufp->chgIData(oldp+12,(vlSelfRef.top__DOT__u_decode__DOT__imm),32);
        bufp->chgCData(oldp+13,((0x7fU & vlSelfRef.top__DOT__id_instr)),7);
        bufp->chgCData(oldp+14,((7U & (vlSelfRef.top__DOT__id_instr 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+15,((vlSelfRef.top__DOT__id_instr 
                                 >> 0x19U)),7);
        bufp->chgIData(oldp+16,(vlSelfRef.top__DOT__ex_pc),32);
        bufp->chgIData(oldp+17,(vlSelfRef.top__DOT__ex_instr),32);
        bufp->chgIData(oldp+18,(vlSelfRef.top__DOT__ex_op1),32);
        bufp->chgIData(oldp+19,(vlSelfRef.top__DOT__ex_op2),32);
        bufp->chgIData(oldp+20,(vlSelfRef.top__DOT__ex_rs1_data),32);
        bufp->chgIData(oldp+21,(vlSelfRef.top__DOT__ex_rs2_data),32);
        bufp->chgCData(oldp+22,(vlSelfRef.top__DOT__ex_rd_addr),5);
        bufp->chgIData(oldp+23,(vlSelfRef.top__DOT__ex_imm),32);
        bufp->chgCData(oldp+24,(vlSelfRef.top__DOT__ex_opcode),7);
        bufp->chgCData(oldp+25,(vlSelfRef.top__DOT__ex_funct3),3);
        bufp->chgCData(oldp+26,(vlSelfRef.top__DOT__ex_funct7),7);
        bufp->chgIData(oldp+27,(vlSelfRef.top__DOT__u_execute__DOT__alu_res),32);
        bufp->chgIData(oldp+28,(vlSelfRef.top__DOT__mem_pc),32);
        bufp->chgIData(oldp+29,(vlSelfRef.top__DOT__mem_alu_result),32);
        bufp->chgIData(oldp+30,(vlSelfRef.top__DOT__mem_rs2_data),32);
        bufp->chgCData(oldp+31,(vlSelfRef.top__DOT__mem_rd_addr),5);
        bufp->chgCData(oldp+32,(vlSelfRef.top__DOT__mem_opcode),7);
        bufp->chgCData(oldp+33,(vlSelfRef.top__DOT__mem_funct3),3);
        bufp->chgIData(oldp+34,(vlSelfRef.top__DOT__mem_mem_rdata),32);
        bufp->chgIData(oldp+35,(vlSelfRef.top__DOT__wb_pc),32);
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__wb_alu_result),32);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__wb_mem_rdata),32);
        bufp->chgCData(oldp+38,(vlSelfRef.top__DOT__wb_rd_addr),5);
        bufp->chgCData(oldp+39,(vlSelfRef.top__DOT__wb_opcode),7);
        bufp->chgBit(oldp+40,(vlSelfRef.top__DOT__wb_wr_en));
        bufp->chgIData(oldp+41,(vlSelfRef.top__DOT__wb_wr_data),32);
        bufp->chgCData(oldp+42,((0x1fU & (vlSelfRef.top__DOT__id_instr 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+43,((0x1fU & (vlSelfRef.top__DOT__id_instr 
                                          >> 0x14U))),5);
        bufp->chgBit(oldp+44,(vlSelfRef.top__DOT__u_execute__DOT__branch_taken));
        bufp->chgIData(oldp+45,(vlSelfRef.top__DOT__u_memory__DOT__rdata_raw),32);
        bufp->chgBit(oldp+46,((3U == (IData)(vlSelfRef.top__DOT__mem_opcode))));
        bufp->chgBit(oldp+47,((0x23U == (IData)(vlSelfRef.top__DOT__mem_opcode))));
        bufp->chgIData(oldp+48,(vlSelfRef.top__DOT__u_register__DOT__rf[0]),32);
        bufp->chgIData(oldp+49,(vlSelfRef.top__DOT__u_register__DOT__rf[1]),32);
        bufp->chgIData(oldp+50,(vlSelfRef.top__DOT__u_register__DOT__rf[2]),32);
        bufp->chgIData(oldp+51,(vlSelfRef.top__DOT__u_register__DOT__rf[3]),32);
        bufp->chgIData(oldp+52,(vlSelfRef.top__DOT__u_register__DOT__rf[4]),32);
        bufp->chgIData(oldp+53,(vlSelfRef.top__DOT__u_register__DOT__rf[5]),32);
        bufp->chgIData(oldp+54,(vlSelfRef.top__DOT__u_register__DOT__rf[6]),32);
        bufp->chgIData(oldp+55,(vlSelfRef.top__DOT__u_register__DOT__rf[7]),32);
        bufp->chgIData(oldp+56,(vlSelfRef.top__DOT__u_register__DOT__rf[8]),32);
        bufp->chgIData(oldp+57,(vlSelfRef.top__DOT__u_register__DOT__rf[9]),32);
        bufp->chgIData(oldp+58,(vlSelfRef.top__DOT__u_register__DOT__rf[10]),32);
        bufp->chgIData(oldp+59,(vlSelfRef.top__DOT__u_register__DOT__rf[11]),32);
        bufp->chgIData(oldp+60,(vlSelfRef.top__DOT__u_register__DOT__rf[12]),32);
        bufp->chgIData(oldp+61,(vlSelfRef.top__DOT__u_register__DOT__rf[13]),32);
        bufp->chgIData(oldp+62,(vlSelfRef.top__DOT__u_register__DOT__rf[14]),32);
        bufp->chgIData(oldp+63,(vlSelfRef.top__DOT__u_register__DOT__rf[15]),32);
        bufp->chgIData(oldp+64,(vlSelfRef.top__DOT__u_register__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+65,(vlSelfRef.clk));
    bufp->chgBit(oldp+66,(vlSelfRef.rst_n));
    bufp->chgIData(oldp+67,(vlSelfRef.top__DOT__instruction),32);
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
}
