// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_CORE_H_
#define VERILATED_VTOP_CORE_H_  // guard

#include "verilated.h"
class Vtop_csr_file;
class Vtop_decode;
class Vtop_execute;
class Vtop_fetch;
class Vtop_forward_unit;
class Vtop_hazard_unit;
class Vtop_memory;
class Vtop_pc_counter;
class Vtop_pipe_reg__D107;
class Vtop_pipe_reg__D40;
class Vtop_pipe_reg__D8c;
class Vtop_pipe_reg__D8f;
class Vtop_reg_file;
class Vtop_writeback;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_core final : public VerilatedModule {
  public:
    // CELLS
    Vtop_pc_counter* __PVT__u_pc_counter;
    Vtop_fetch* __PVT__u_fetch;
    Vtop_pipe_reg__D40* __PVT__u_if2id;
    Vtop_decode* __PVT__u_decode;
    Vtop_reg_file* __PVT__u_reg_file;
    Vtop_csr_file* __PVT__u_csr_file;
    Vtop_hazard_unit* __PVT__u_hazard;
    Vtop_forward_unit* __PVT__u_forward;
    Vtop_pipe_reg__D107* __PVT__u_id2ex;
    Vtop_execute* __PVT__u_execute;
    Vtop_pipe_reg__D8f* __PVT__u_ex2mem;
    Vtop_memory* __PVT__u_memory;
    Vtop_pipe_reg__D8c* __PVT__u_mem2wb;
    Vtop_writeback* __PVT__u_writeback;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(__PVT__clk,0,0);
        VL_IN8(__PVT__rst_n,0,0);
        VL_OUT8(__PVT__lsu_wen,0,0);
        VL_OUT8(__PVT__lsu_wmask,3,0);
        VL_OUT8(__PVT__debug_wb_have,0,0);
        VL_OUT8(__PVT__debug_wb_en,0,0);
        VL_OUT8(__PVT__debug_wb_addr,4,0);
        CData/*0:0*/ __PVT__if2id_up_ready;
        CData/*0:0*/ __PVT__if2id_dn_valid;
        CData/*0:0*/ __PVT__id2ex_up_ready;
        CData/*0:0*/ __PVT__id2ex_dn_valid;
        CData/*0:0*/ __PVT__ex2mem_up_ready;
        CData/*0:0*/ __PVT__ex2mem_dn_valid;
        CData/*0:0*/ __PVT__mem2wb_up_ready;
        CData/*0:0*/ __PVT__mem2wb_dn_valid;
        CData/*4:0*/ __PVT__decode_rs1_addr;
        CData/*4:0*/ __PVT__decode_rs2_addr;
        CData/*4:0*/ __PVT__decode_rd_addr;
        CData/*1:0*/ __PVT__decode_op1_sel;
        CData/*1:0*/ __PVT__decode_op2_sel;
        CData/*6:0*/ __PVT__decode_opcode;
        CData/*2:0*/ __PVT__decode_funct3;
        CData/*6:0*/ __PVT__decode_funct7;
        CData/*0:0*/ __PVT__decode_inst_csrrw;
        CData/*0:0*/ __PVT__decode_inst_csrrs;
        CData/*0:0*/ __PVT__decode_inst_ecall;
        CData/*0:0*/ __PVT__decode_inst_mret;
        CData/*0:0*/ __PVT__decode_inst_ebreak;
        CData/*0:0*/ __PVT__ex_jump_flag;
        CData/*0:0*/ __PVT__wb_wr_en;
        CData/*4:0*/ __PVT__wb_wr_addr;
        CData/*0:0*/ __PVT__load_stall;
        CData/*1:0*/ __PVT__fwd_rs1_sel;
        CData/*1:0*/ __PVT__fwd_rs2_sel;
        CData/*0:0*/ __PVT__ifu_valid;
        CData/*0:0*/ __PVT__lsu_busy;
        CData/*0:0*/ __PVT__csr_wen;
        CData/*0:0*/ __PVT__trap_valid;
        CData/*0:0*/ __Vcellinp__u_pc_counter__pc_hold;
        CData/*0:0*/ __Vcellinp__u_if2id__stall;
        CData/*0:0*/ __Vcellinp__u_csr_file__rst;
        CData/*4:0*/ __Vcellinp__u_hazard__ex_rd_addr;
        CData/*6:0*/ __Vcellinp__u_hazard__ex_opcode;
        CData/*4:0*/ __Vcellinp__u_forward__wb_rd_addr;
        CData/*6:0*/ __Vcellinp__u_forward__wb_opcode;
        CData/*4:0*/ __Vcellinp__u_forward__mem_rd_addr;
        CData/*6:0*/ __Vcellinp__u_forward__mem_opcode;
        CData/*4:0*/ __Vcellinp__u_forward__ex_stage_rd_addr;
        CData/*6:0*/ __Vcellinp__u_forward__ex_stage_opcode;
        CData/*0:0*/ __Vcellinp__u_id2ex__flush;
        CData/*0:0*/ __Vcellinp__u_execute__inst_mret;
        CData/*0:0*/ __Vcellinp__u_execute__inst_ecall;
        CData/*0:0*/ __Vcellinp__u_execute__inst_csrrs;
        CData/*0:0*/ __Vcellinp__u_execute__inst_csrrw;
        CData/*0:0*/ __Vcellinp__u_execute__inst_ebreak_in;
        CData/*6:0*/ __Vcellinp__u_execute__funct7_in;
        CData/*2:0*/ __Vcellinp__u_execute__funct3_in;
        CData/*6:0*/ __Vcellinp__u_execute__opcode_in;
        CData/*2:0*/ __Vcellinp__u_memory__funct3_in;
        CData/*6:0*/ __Vcellinp__u_memory__opcode_in;
        CData/*0:0*/ __Vcellinp__u_mem2wb__up_valid;
        CData/*4:0*/ __Vcellinp__u_writeback__rd_addr_in;
        CData/*6:0*/ __Vcellinp__u_writeback__opcode_in;
        SData/*11:0*/ __PVT__decode_csr_addr;
    };
    struct {
        SData/*11:0*/ __PVT__csr_raddr;
        SData/*11:0*/ __PVT__csr_waddr;
        SData/*11:0*/ __Vcellinp__u_execute__csr_addr_in;
        VL_OUT(__PVT__pc,31,0);
        VL_OUT(__PVT__instr,31,0);
        VL_OUT(__PVT__ifu_raddr,31,0);
        VL_IN(__PVT__ifu_rdata,31,0);
        VL_OUT(__PVT__lsu_addr,31,0);
        VL_OUT(__PVT__lsu_wdata,31,0);
        VL_IN(__PVT__lsu_rdata,31,0);
        VL_OUT(__PVT__debug_wb_pc,31,0);
        VL_OUT(__PVT__debug_wb_instr,31,0);
        VL_OUT(__PVT__debug_wb_data,31,0);
        IData/*31:0*/ __PVT__decode_imm;
        IData/*31:0*/ __PVT__reg_rs1_data;
        IData/*31:0*/ __PVT__reg_rs2_data;
        IData/*31:0*/ __PVT__fwd_rs1_data;
        IData/*31:0*/ __PVT__fwd_rs2_data;
        IData/*31:0*/ __PVT__id_op1;
        IData/*31:0*/ __PVT__id_op2;
        IData/*31:0*/ __PVT__ex_alu_result;
        IData/*31:0*/ __PVT__ex_jump_target;
        IData/*31:0*/ __PVT__mem_rdata;
        IData/*31:0*/ __PVT__wb_wr_data;
        IData/*31:0*/ __PVT__csr_rdata;
        IData/*31:0*/ __PVT__csr_wdata;
        IData/*31:0*/ __PVT__trap_pc;
        IData/*31:0*/ __PVT__trap_cause;
        IData/*31:0*/ __PVT__trap_mtvec;
        IData/*31:0*/ __PVT__trap_mepc;
        IData/*31:0*/ __Vcellinp__u_decode__instr_in;
        IData/*31:0*/ __Vcellinp__u_decode__instr_addr_in;
        IData/*31:0*/ __Vcellinp__u_forward__ex_mem_alu_result;
        VlWide<9>/*262:0*/ __Vcellout__u_id2ex__dn_data;
        VlWide<9>/*262:0*/ __Vcellinp__u_id2ex__up_data;
        IData/*31:0*/ __Vcellinp__u_execute__imm_in;
        IData/*31:0*/ __Vcellinp__u_execute__rs1_data_in;
        IData/*31:0*/ __Vcellinp__u_execute__op2_in;
        IData/*31:0*/ __Vcellinp__u_execute__op1_in;
        IData/*31:0*/ __Vcellinp__u_execute__pc_in;
        VlWide<5>/*142:0*/ __Vcellout__u_ex2mem__dn_data;
        VlWide<5>/*142:0*/ __Vcellinp__u_ex2mem__up_data;
        IData/*31:0*/ __Vcellinp__u_memory__rs2_data_in;
        IData/*31:0*/ __Vcellinp__u_memory__alu_result_in;
        VlWide<5>/*139:0*/ __Vcellout__u_mem2wb__dn_data;
        VlWide<5>/*139:0*/ __Vcellinp__u_mem2wb__up_data;
        IData/*31:0*/ __Vcellinp__u_writeback__mem_rdata_in;
        IData/*31:0*/ __Vcellinp__u_writeback__alu_result_in;
        QData/*63:0*/ __PVT__if_id_up;
        QData/*63:0*/ __PVT__if_id_dn;
        VlWide<9>/*262:0*/ __PVT__id_ex_up;
        VlWide<9>/*262:0*/ __PVT__id_ex_dn;
        VlWide<5>/*142:0*/ __PVT__ex_mem_up;
        VlWide<5>/*142:0*/ __PVT__ex_mem_dn;
        VlWide<5>/*139:0*/ __PVT__mem_wb_up;
        VlWide<5>/*139:0*/ __PVT__mem_wb_dn;
        QData/*63:0*/ __Vcellout__u_if2id__dn_data;
        QData/*63:0*/ __Vcellinp__u_if2id__up_data;
        VL_OUT(__PVT__regs[16],31,0);
    };

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_core(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_core();
    VL_UNCOPYABLE(Vtop_core);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
