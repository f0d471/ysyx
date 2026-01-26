#include "common.h"
#include <cstdio>
#include <cstdarg>

// ===================== log =============================
static FILE *trace_fp = NULL;

// 初始化
void init_trace(const char *filename) {
#if defined(CONFIG_ITRACE) || defined(CONFIG_MTRACE)
    if (trace_fp != NULL) return;  
    trace_fp = fopen(filename, "w");
    if (!trace_fp) {
        perror("fopen trace file");
        exit(1);
    }
#endif
}

// 写日志
void trace_log(const char *fmt, ...) {
    if (!trace_fp) return;  

    va_list args;
    va_start(args, fmt);
    vfprintf(trace_fp, fmt, args);
    va_end(args);

    fflush(trace_fp); 
}

// 关闭 trace 文件
void trace_close() {
    if (trace_fp) {
        fclose(trace_fp);
        trace_fp = NULL;
    }
}

// ============================ itrace =============================
void log_itrace() {
#ifdef CONFIG_ITRACE
    char asm_buf[128];
    uint32_t inst = top->inst; 
    disassemble(asm_buf, sizeof(asm_buf), top->pc, (uint8_t *)&inst, 4);
    trace_log("[itrace] 0x%08x: 0x%08x  %s\n", top->pc, inst, asm_buf);
#endif
}

// ============================ mtrace =============================
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
            case 4: return "lbu"; // funct3 为 100 是 lbu
            case 5: return "lhu"; // funct3 为 101 是 lhu
            default: return "l?";
        }
    }
}

void log_mtrace(uint32_t addr, uint32_t data, int len, int is_write) {
#ifdef CONFIG_MTRACE
    const char *op_name = get_mop_name(top->inst, is_write);
    
    if (!is_write) {
        trace_log("[mtrace] pc:0x%08x %-3s  x%-2d <- mem[0x%08x] = 0x%08x\n", 
                  top->pc, op_name, top->rd, addr, data);
    } else {
        trace_log("[mtrace] pc:0x%08x %-3s  mem[0x%08x] <- x%-2d = 0x%08x\n", 
                  top->pc, op_name, addr, top->rs2, data);
    }
#endif
}