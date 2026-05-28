#include <cstdio>
#include <cstring>
#include <cassert>
#include <capstone/capstone.h>

#include "common.h"
#include "utils.h"

#ifdef CONFIG_ITRACE

// ==================== disasm ====================
static csh capstone_handle;

extern "C" void init_disasm() {
    if (cs_open(CS_ARCH_RISCV, CS_MODE_RISCV32, &capstone_handle) != CS_ERR_OK) {
        fprintf(stderr, "Failed to initialize Capstone disassembler!\n");
        assert(0);
    }
}

extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
    cs_insn *insn;
    size_t count = cs_disasm(capstone_handle, code, nbyte, pc, 0, &insn);

    if (count > 0) {
        snprintf(str, size, "%s %s", insn[0].mnemonic, insn[0].op_str);
        cs_free(insn, count);
    } else {
        snprintf(str, size, "???");
    }
}

// ==================== itrace ====================
void log_itrace() {
    char asm_buf[128];
    uint32_t inst = top->debug_instr;
    disassemble(asm_buf, sizeof(asm_buf), top->debug_pc, (uint8_t *)&inst, 4);
    iringbuf_push("[itrace] 0x%08x: 0x%08x  %s\n", top->debug_pc, inst, asm_buf);
}

#endif // CONFIG_ITRACE
