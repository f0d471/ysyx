# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vtop.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 0
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 1
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 1
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vtop \
	Vtop___024root__DepSet_h84412442__0 \
	Vtop___024root__DepSet_heccd7ead__0 \
	Vtop_top__DepSet_h0f993197__0 \
	Vtop___024unit__DepSet_hab9af801__0 \
	Vtop_pipe_reg_if2id__DepSet_h0a246a71__0 \
	Vtop_memory__DepSet_hf5a2896a__0 \
	Vtop_writeback__DepSet_h9c0cf8ce__0 \
	Vtop_csr_file__DepSet_hf0fdf7be__0 \
	Vtop_reg_file__DepSet_he71db602__0 \
	Vtop_pipe_reg_mem2wb__DepSet_hb290ece2__0 \
	Vtop_forward_unit__DepSet_h89dad57c__0 \
	Vtop_fetch__DepSet_hece00146__0 \
	Vtop_decode__DepSet_h626b6706__0 \
	Vtop_hazard_unit__DepSet_h686296db__0 \
	Vtop_execute__DepSet_h2e3646d3__0 \
	Vtop_execute__DepSet_h827c1c3e__0 \
	Vtop_pipe_reg_id2ex__DepSet_h8efae207__0 \
	Vtop_pipe_reg_ex2mem__DepSet_hd1c03988__0 \
	Vtop_pc_counter__DepSet_h952d53ec__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vtop__ConstPool_0 \
	Vtop___024root__Slow \
	Vtop___024root__DepSet_h84412442__0__Slow \
	Vtop___024root__DepSet_heccd7ead__0__Slow \
	Vtop_top__Slow \
	Vtop_top__DepSet_h0f993197__0__Slow \
	Vtop_top__DepSet_h6315917a__0__Slow \
	Vtop___024unit__Slow \
	Vtop___024unit__DepSet_hff17caec__0__Slow \
	Vtop_pipe_reg_if2id__Slow \
	Vtop_pipe_reg_if2id__DepSet_h0a246a71__0__Slow \
	Vtop_memory__Slow \
	Vtop_memory__DepSet_hf5a2896a__0__Slow \
	Vtop_memory__DepSet_h3cefd995__0__Slow \
	Vtop_writeback__Slow \
	Vtop_writeback__DepSet_h9c0cf8ce__0__Slow \
	Vtop_csr_file__Slow \
	Vtop_csr_file__DepSet_hf0fdf7be__0__Slow \
	Vtop_reg_file__Slow \
	Vtop_reg_file__DepSet_he71db602__0__Slow \
	Vtop_pipe_reg_mem2wb__Slow \
	Vtop_pipe_reg_mem2wb__DepSet_hb290ece2__0__Slow \
	Vtop_forward_unit__Slow \
	Vtop_forward_unit__DepSet_h89dad57c__0__Slow \
	Vtop_fetch__Slow \
	Vtop_fetch__DepSet_hece00146__0__Slow \
	Vtop_fetch__DepSet_h442e61a9__0__Slow \
	Vtop_decode__Slow \
	Vtop_decode__DepSet_h626b6706__0__Slow \
	Vtop_hazard_unit__Slow \
	Vtop_hazard_unit__DepSet_h686296db__0__Slow \
	Vtop_execute__Slow \
	Vtop_execute__DepSet_h2e3646d3__0__Slow \
	Vtop_execute__DepSet_h827c1c3e__0__Slow \
	Vtop_pipe_reg_id2ex__Slow \
	Vtop_pipe_reg_id2ex__DepSet_h8efae207__0__Slow \
	Vtop_pipe_reg_ex2mem__Slow \
	Vtop_pipe_reg_ex2mem__DepSet_hd1c03988__0__Slow \
	Vtop_pc_counter__Slow \
	Vtop_pc_counter__DepSet_h952d53ec__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	Vtop__Dpi \
	Vtop__Trace__0 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vtop__Syms \
	Vtop__Trace__0__Slow \
	Vtop__TraceDecls__0__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_dpi \
	verilated_vcd_c \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
