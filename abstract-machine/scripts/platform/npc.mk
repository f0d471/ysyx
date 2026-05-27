AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/ioe.c \
           riscv/npc/timer.c \
           riscv/npc/input.c \
           riscv/npc/gpu.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

INC_PATH += $(AM_HOME)/am/src/riscv/npc/include
CFLAGS    += -fdata-sections -ffunction-sections
LDSCRIPTS += $(AM_HOME)/scripts/linker.ld
LDFLAGS   += --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start

MAINARGS_MAX_LEN = 64
MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here
CFLAGS += -DMAINARGS_MAX_LEN=$(MAINARGS_MAX_LEN) -DMAINARGS_PLACEHOLDER=$(MAINARGS_PLACEHOLDER)

insert-arg: image
	@python $(AM_HOME)/tools/insert-arg.py $(IMAGE).bin $(MAINARGS_MAX_LEN) $(MAINARGS_PLACEHOLDER) "$(mainargs)"

image: image-dep
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: insert-arg
	@echo "[AM] Copy $(IMAGE).bin to NPC build directory as Default.bin..."
	@cp $(IMAGE).bin $(NPC_HOME)/test/Default.bin
	@cp $(IMAGE).elf $(NPC_HOME)/test/Default.elf
	@echo "[AM] Building and running NPC with Default.bin..."
	@$(MAKE) -C $(NPC_HOME) run TEST_BIN=./test/Default.bin

gdb: insert-arg
	@echo "[AM] Copy $(IMAGE).bin to NPC build directory as Default.bin..."
	@cp $(IMAGE).bin $(NPC_HOME)/test/Default.bin
	@echo "[AM] Building and running NPC under gdb with Default.bin..."
	@$(MAKE) -C $(NPC_HOME) gdb TEST_BIN=./test/Default.bin

.PHONY: insert-arg
