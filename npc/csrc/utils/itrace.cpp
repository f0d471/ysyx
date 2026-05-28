#include <cstdio>
#include <cstring>
#include <cassert>
#include <capstone/capstone.h>

#include "Vtop.h"
#include "itrace.h"
#include "trace.h"

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

// ==================== iringbuf ====================

#define IRINGBUF_SIZE 2056

struct IRingEntry {
    uint32_t pc;
    uint32_t inst;
    char disasm[128];
};

static IRingEntry iringbuf[IRINGBUF_SIZE];
static int iringbuf_w = 0;
static int iringbuf_cnt = 0;

static void iringbuf_push(uint32_t pc, uint32_t inst) {
    IRingEntry *e = &iringbuf[iringbuf_w];
    e->pc = pc;
    e->inst = inst;
    disassemble(e->disasm, sizeof(e->disasm), pc, (uint8_t *)&inst, 4);
    iringbuf_w = (iringbuf_w + 1) % IRINGBUF_SIZE;
    if (iringbuf_cnt < IRINGBUF_SIZE) iringbuf_cnt++;
}

void iringbuf_dump() {
    if (iringbuf_cnt == 0) return;

    int count = iringbuf_cnt;
    int start = (count < IRINGBUF_SIZE) ? 0 : iringbuf_w;

    TRACE_LOG("\n========== IRINGBUF (%d/%d instructions) ==========\n",
              count, IRINGBUF_SIZE);
    for (int i = 0; i < count; i++) {
        int idx = (start + i) % IRINGBUF_SIZE;
        TRACE_LOG("  0x%08x: 0x%08x  %s\n",
                  iringbuf[idx].pc, iringbuf[idx].inst, iringbuf[idx].disasm);
    }
    TRACE_LOG("========== IRINGBUF END ==========\n\n");
}

// ==================== itrace ====================

void log_itrace() {
    uint32_t inst = top->debug_instr;
    iringbuf_push(top->debug_pc, inst);

    char asm_buf[128];
    disassemble(asm_buf, sizeof(asm_buf), top->debug_pc, (uint8_t *)&inst, 4);
    TRACE_LOG("[itrace] 0x%08x: 0x%08x  %s\n", top->debug_pc, inst, asm_buf);
}

#endif // CONFIG_ITRACE
