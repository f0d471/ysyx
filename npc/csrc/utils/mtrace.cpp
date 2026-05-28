#include <cstdio>
#include <cstdint>

#include "common.h"
#include "utils.h"

#ifdef CONFIG_MTRACE

static const char* get_mop_name(uint32_t inst, int is_write) {
    uint32_t funct3 = (inst >> 12) & 0x7;
    if (is_write) {
        switch (funct3) {
            case 0: return "sb";
            case 1: return "sh";
            case 2: return "sw";
            default: return "s?";
        }
    } else {
        switch (funct3) {
            case 0: return "lb";
            case 1: return "lh";
            case 2: return "lw";
            case 4: return "lbu";
            case 5: return "lhu";
            default: return "l?";
        }
    }
}

void log_mtrace(uint32_t addr, uint32_t data, int is_write) {
    const char *op_name = get_mop_name(top->debug_instr, is_write);
    uint32_t rd  = (top->debug_instr >> 7) & 0x1F;
    uint32_t rs2 = (top->debug_instr >> 20) & 0x1F;

    if (!is_write) {
        iringbuf_push("[mtrace] pc:0x%08x %-3s  x%-2d <- mem[0x%08x] = 0x%08x\n",
                      top->debug_pc, op_name, rd, addr, data);
    } else {
        iringbuf_push("[mtrace] pc:0x%08x %-3s  mem[0x%08x] <- x%-2d = 0x%08x\n",
                      top->debug_pc, op_name, addr, rs2, data);
    }
}

#endif // CONFIG_MTRACE
