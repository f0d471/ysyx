include $(AM_HOME)/scripts/isa/riscv.mk
include $(AM_HOME)/scripts/platform/nemu.mk
CFLAGS  += -DISA_H=\"riscv/riscv.h\"

AM_SRCS += riscv/nemu/start.S \
           riscv/cte.c \
           riscv/trap.S \
           riscv/nemu/vme.c
