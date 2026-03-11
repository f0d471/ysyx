// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_TOP_H_
#define VERILATED_VTOP_TOP_H_  // guard

#include "verilated.h"
class Vtop_csr_file;
class Vtop_decode;
class Vtop_execute;
class Vtop_fetch;
class Vtop_forward_unit;
class Vtop_hazard_unit;
class Vtop_memory;
class Vtop_pc_counter;
class Vtop_pipe_reg_ex2mem;
class Vtop_pipe_reg_id2ex;
class Vtop_pipe_reg_if2id;
class Vtop_pipe_reg_mem2wb;
class Vtop_reg_file;
class Vtop_writeback;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_top final : public VerilatedModule {
  public:
    // CELLS
    Vtop_pc_counter* __PVT__u_pc_counter;
    Vtop_fetch* __PVT__u_fetch;
    Vtop_pipe_reg_if2id* __PVT__u_if2id;
    Vtop_decode* __PVT__u_decode;
    Vtop_reg_file* __PVT__u_reg_file;
    Vtop_hazard_unit* __PVT__u_hazard;
    Vtop_forward_unit* __PVT__u_forward;
    Vtop_pipe_reg_id2ex* __PVT__u_id2ex;
    Vtop_execute* __PVT__u_execute;
    Vtop_pipe_reg_ex2mem* __PVT__u_ex2mem;
    Vtop_memory* __PVT__u_memory;
    Vtop_pipe_reg_mem2wb* __PVT__u_mem2wb;
    Vtop_writeback* __PVT__u_writeback;
    Vtop_csr_file* __PVT__u_csr_file;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
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
        CData/*0:0*/ __PVT__csr_wen;
        CData/*0:0*/ __PVT__trap_valid;
        CData/*0:0*/ __Vcellinp__u_pc_counter__jump_en;
        CData/*4:0*/ __Vcellinp__u_hazard__ex_rd_addr;
        CData/*6:0*/ __Vcellinp__u_hazard__ex_opcode;
        CData/*6:0*/ __Vcellinp__u_forward__wb_opcode;
        CData/*4:0*/ __Vcellinp__u_forward__wb_rd_addr;
        CData/*6:0*/ __Vcellinp__u_forward__mem_opcode;
        CData/*4:0*/ __Vcellinp__u_forward__mem_rd_addr;
        CData/*6:0*/ __Vcellinp__u_forward__ex_stage_opcode;
        CData/*4:0*/ __Vcellinp__u_forward__ex_stage_rd_addr;
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
        CData/*4:0*/ __Vcellinp__u_writeback__rd_addr_in;
        CData/*6:0*/ __Vcellinp__u_writeback__opcode_in;
        CData/*0:0*/ __Vcellinp__u_csr_file__rst;
        SData/*11:0*/ __PVT__decode_csr_addr;
        SData/*11:0*/ __PVT__csr_raddr;
        SData/*11:0*/ __PVT__csr_waddr;
        SData/*11:0*/ __Vcellinp__u_execute__csr_addr_in;
        VL_OUT(pc,31,0);
        VL_OUT(instr,31,0);
        VL_OUT(debug_x10,31,0);
        IData/*31:0*/ __PVT__decode_imm;
        IData/*31:0*/ __PVT__reg_rs1_data;
        IData/*31:0*/ __PVT__reg_rs2_data;
    };
    struct {
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
        IData/*31:0*/ __Vcellinp__u_pc_counter__jump_addr;
        IData/*31:0*/ __Vcellinp__u_decode__instr_in;
        IData/*31:0*/ __Vcellinp__u_decode__instr_addr_in;
        IData/*31:0*/ __Vcellinp__u_execute__imm_in;
        IData/*31:0*/ __Vcellinp__u_execute__rs1_data_in;
        IData/*31:0*/ __Vcellinp__u_execute__op2_in;
        IData/*31:0*/ __Vcellinp__u_execute__op1_in;
        IData/*31:0*/ __Vcellinp__u_execute__pc_in;
        IData/*31:0*/ __Vcellinp__u_memory__rs2_data_in;
        IData/*31:0*/ __Vcellinp__u_memory__alu_result_in;
        IData/*31:0*/ __Vcellinp__u_writeback__mem_rdata_in;
        IData/*31:0*/ __Vcellinp__u_writeback__alu_result_in;
        QData/*63:0*/ __PVT__if_id_up;
        QData/*63:0*/ __PVT__if_id_dn;
        VlWide<9>/*262:0*/ __PVT__id_ex_up;
        VlWide<9>/*262:0*/ __PVT__id_ex_dn;
        VlWide<3>/*78:0*/ __PVT__ex_mem_up;
        VlWide<3>/*78:0*/ __PVT__ex_mem_dn;
        VlWide<3>/*75:0*/ __PVT__mem_wb_up;
        VlWide<3>/*75:0*/ __PVT__mem_wb_dn;
        VL_OUT(regs[16],31,0);
    };

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_top(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_top();
    VL_UNCOPYABLE(Vtop_top);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
