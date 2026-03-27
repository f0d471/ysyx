#include <cstdio>
#include <cstdlib>   
#include <cstring>   
#include <cassert>   
#include <cstdarg>
#include <elf.h>

#include "common.h"

typedef uint32_t paddr_t;

// ===================== log =============================
// Trace 使用内存环形缓冲区，程序结束时一次性写入文件。
// 这样可以严格控制 trace 文件大小，始终保留最近的 N 条记录。

#ifndef CONFIG_TRACE_BUF_LINES
#define CONFIG_TRACE_BUF_LINES 4096   // 环形缓冲区容纳的最大行数
#endif

#ifndef CONFIG_TRACE_LINE_LEN
#define CONFIG_TRACE_LINE_LEN  256    // 每行最大字节数（含 '\0'）
#endif

static char  trace_ring_buf[CONFIG_TRACE_BUF_LINES][CONFIG_TRACE_LINE_LEN];
static int   trace_ring_head = 0;   // 下一次写入的位置（0-based，循环）
static int   trace_ring_count = 0;  // 当前缓冲区中有效行数
static char  trace_filename[256] = "npc-trace.txt";

// 初始化：仅记录文件名，不打开文件
void init_trace(const char *filename) {
#if defined(CONFIG_ITRACE) || defined(CONFIG_MTRACE) || defined(CONFIG_FTRACE) || defined(CONFIG_DTRACE)
    if (filename) {
        strncpy(trace_filename, filename, sizeof(trace_filename) - 1);
        trace_filename[sizeof(trace_filename) - 1] = '\0';
    }
    trace_ring_head  = 0;
    trace_ring_count = 0;
    printf("[trace] Ring buffer initialized: max %d lines x %d bytes, output -> %s\n",
           CONFIG_TRACE_BUF_LINES, CONFIG_TRACE_LINE_LEN, trace_filename);
#endif
}

// 统一的写日志接口：写入环形缓冲区，超过上限时自动覆盖最旧的行
void TRACE_LOG(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsnprintf(trace_ring_buf[trace_ring_head], CONFIG_TRACE_LINE_LEN, fmt, args);
    va_end(args);

    trace_ring_head = (trace_ring_head + 1) % CONFIG_TRACE_BUF_LINES;
    if (trace_ring_count < CONFIG_TRACE_BUF_LINES) {
        trace_ring_count++;
    }
    // 当 count == BUF_LINES 时，head 已经绕回，下次写入将覆盖最旧的行
}

// 将环形缓冲区内容按时间顺序 dump 到文件
// 若缓冲区未满，从 0 开始顺序输出；若已满，从 head（最旧）开始循环输出
void trace_close() {
    if (trace_ring_count == 0) return;

    FILE *fp = fopen(trace_filename, "w");
    if (!fp) {
        perror("[trace] fopen trace file failed");
        return;
    }

    int start;
    int total = trace_ring_count;

    if (trace_ring_count < CONFIG_TRACE_BUF_LINES) {
        // 缓冲区未满：从 0 到 count-1 顺序输出
        start = 0;
    } else {
        // 缓冲区已满：head 指向最旧的行
        start = trace_ring_head;
        fprintf(fp, "[trace] NOTE: buffer full (%d lines), oldest entries discarded.\n",
                CONFIG_TRACE_BUF_LINES);
        total = CONFIG_TRACE_BUF_LINES;
    }

    for (int i = 0; i < total; i++) {
        int idx = (start + i) % CONFIG_TRACE_BUF_LINES;
        fputs(trace_ring_buf[idx], fp);
    }

    fclose(fp);
    printf("[trace] Dumped %d lines to %s\n", total, trace_filename);
}

// ============================ itrace =============================
void log_itrace() {
#ifdef CONFIG_ITRACE
    char asm_buf[128];
    uint32_t inst = top->instr; 
    disassemble(asm_buf, sizeof(asm_buf), top->pc, (uint8_t *)&inst, 4);
    TRACE_LOG("[itrace] 0x%08x: 0x%08x  %s\n", top->pc, inst, asm_buf);
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

void log_mtrace(uint32_t addr, uint32_t data, int is_write) {
#ifdef CONFIG_MTRACE
    const char *op_name = get_mop_name(top->instr, is_write);

    uint32_t rd  = (top->instr >> 7) & 0x1F;
    uint32_t rs2 = (top->instr >> 20) & 0x1F;

    if (!is_write) {
        TRACE_LOG("[mtrace] pc:0x%08x %-3s  x%-2d <- mem[0x%08x] = 0x%08x\n", 
                  top->pc, op_name, rd, addr, data);
    } else {
        TRACE_LOG("[mtrace] pc:0x%08x %-3s  mem[0x%08x] <- x%-2d = 0x%08x\n", 
                  top->pc, op_name, addr, rs2, data);
    }
#endif
}

//=========================== dtrace ==================================== 
void log_dtrace(char type, uint32_t addr, int len, uint32_t data) {
#ifdef CONFIG_DTRACE
    const char* dev_name = "unknown";
    if (addr == 0xa00003f8) dev_name = "serial";
    else if (addr == 0xa0000048) dev_name = "rtc";
    
    TRACE_LOG("[DTRACE] %c  addr=0x%08x len=%d val=0x%08x device=%s\n", type, addr, len, data, dev_name);
#endif
}

//=========================== ftrace ==================================== 
#define MAX_FUNCS 1024 // 假设程序中最多有 1024 个函数

typedef struct {
    char name[64];
    paddr_t addr;
    uint32_t size;
} FuncSymbol;

static FuncSymbol func_syms[MAX_FUNCS];
static int func_sym_cnt = 0;

#ifdef CONFIG_FTRACE
    static int ftrace_depth = 0;
#endif

#ifndef FTRACE_COND
#define FTRACE_COND 1
#endif

void init_ftrace(const char *elf_file) {
    if (elf_file == NULL) {
        printf("No ELF file given, ftrace will not work.\n");
        return;
    }

    FILE *fp = fopen(elf_file, "rb");
    if (!fp) {
        fprintf(stderr, "Can not open '%s'\n", elf_file);
        exit(1);
    }

    // 1. 读取 ELF 头 (ELF Header)
    Elf32_Ehdr ehdr;
    if (fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp) != 1) {
        fprintf(stderr, "Failed to read ELF header\n");
        exit(1);
    }

    // 简单校验一下 Magic Number (7f 45 4c 46 -> "\x7fELF")
    if (*(uint32_t *)ehdr.e_ident != 0x464c457f) {
        fprintf(stderr, "Not a valid ELF file: %s\n", elf_file);
        exit(1);
    }

    // 2. 读取所有的节头表 (Section Headers)
    Elf32_Shdr *shdrs = (Elf32_Shdr *)malloc(ehdr.e_shentsize * ehdr.e_shnum);
    assert(shdrs);
    fseek(fp, ehdr.e_shoff, SEEK_SET);
    if (fread(shdrs, ehdr.e_shentsize, ehdr.e_shnum, fp) != ehdr.e_shnum) {
        fprintf(stderr, "Failed to read Section Headers\n");
        exit(1);
    }

    // 3. 寻找符号表 (.symtab) 和对应的字符串表 (.strtab)
    Elf32_Shdr *symtab_shdr = NULL;
    Elf32_Shdr *strtab_shdr = NULL;

    for (int i = 0; i < ehdr.e_shnum; i++) {
        if (shdrs[i].sh_type == SHT_SYMTAB) {
            symtab_shdr = &shdrs[i];
            strtab_shdr = &shdrs[symtab_shdr->sh_link]; 
            break;
        }
    }

    if (!symtab_shdr || !strtab_shdr) {
        printf("No symbol table found in %s\n", elf_file);
        free(shdrs);
        fclose(fp);
        return;
    }

    // 4. 把字符串表整个读进内存
    char *strtab = (char *)malloc(strtab_shdr->sh_size);
    assert(strtab);
    fseek(fp, strtab_shdr->sh_offset, SEEK_SET);
    if (fread(strtab, 1, strtab_shdr->sh_size, fp) != strtab_shdr->sh_size) {
        fprintf(stderr, "Failed to read string table\n");
        exit(1);
    }

    // 5. 读取符号表，并提取所有的函数 (STT_FUNC)
    int sym_num = symtab_shdr->sh_size / symtab_shdr->sh_entsize;
    Elf32_Sym *syms = (Elf32_Sym *)malloc(symtab_shdr->sh_size);
    assert(syms);
    fseek(fp, symtab_shdr->sh_offset, SEEK_SET);
    if (fread(syms, symtab_shdr->sh_entsize, sym_num, fp) != sym_num) {
        fprintf(stderr, "Failed to read symbol table\n");
        exit(1);
    }

    for (int i = 0; i < sym_num; i++) {
        if (ELF32_ST_TYPE(syms[i].st_info) == STT_FUNC) {
            FuncSymbol *f = &func_syms[func_sym_cnt++];
            f->addr = syms[i].st_value;
            f->size = syms[i].st_size;
            strncpy(f->name, strtab + syms[i].st_name, sizeof(f->name) - 1);
            f->name[sizeof(f->name) - 1] = '\0'; // 确保字符串结尾有 \0

            if (func_sym_cnt >= MAX_FUNCS) {
                printf("Warning: Too many functions, truncating!\n");
                break;
            }
        }
    }

    printf("Loaded %d functions from %s for ftrace.\n", func_sym_cnt, elf_file);

    free(syms);
    free(strtab);
    free(shdrs);
    fclose(fp);
}

const char* ftrace_get_func_name(paddr_t addr) {
    for (int i = 0; i < func_sym_cnt; i++) {
        if (addr >= func_syms[i].addr && addr < func_syms[i].addr + func_syms[i].size) {
            return func_syms[i].name;
        }
    }
    return "???";
}

// ================= 解耦封装：记录 Call 操作 =================
void log_ftrace_call(paddr_t pc, paddr_t dnpc) {
#ifdef CONFIG_FTRACE
    if (!FTRACE_COND) return;

    const char* func_name = ftrace_get_func_name(dnpc);
    TRACE_LOG("[FTRACE] 0x%08x: %*scall [%s@0x%08x]\n", pc, ftrace_depth * 2, "", func_name, dnpc);
    ftrace_depth++;
#endif
}

// ================= 解耦封装：记录 Ret 操作 =================
void log_ftrace_ret(paddr_t pc) {
#ifdef CONFIG_FTRACE
    if (!FTRACE_COND) return;

    ftrace_depth--;
    if (ftrace_depth < 0) ftrace_depth = 0; // 防止深度为负
    
    const char* func_name = ftrace_get_func_name(pc);
    TRACE_LOG("[FTRACE] 0x%08x: %*sret  [%s]\n", pc, ftrace_depth * 2, "", func_name);
#endif
}

// ================= 解耦封装：分析指令并触发 FTrace =================
void do_ftrace(paddr_t pc, paddr_t dnpc, uint32_t inst) {
#ifdef CONFIG_FTRACE
    if (!FTRACE_COND) return;

    uint32_t opcode = inst & 0x7F;
    uint32_t rd  = (inst >> 7) & 0x1F;
    uint32_t rs1 = (inst >> 15) & 0x1F;

    bool is_jal  = (opcode == 0x6f); // 1101111
    bool is_jalr = (opcode == 0x67); // 1100111

    // 标准 RISC-V 调用约定: call 通常是 jal/jalr 且目标寄存器 rd 是 x1 (ra)
    if ((is_jal || is_jalr) && rd == 1) {
        log_ftrace_call(pc, dnpc);
    }
    // 标准 RISC-V 调用约定: ret 通常是 jalr 且源寄存器 rs1 是 x1 (ra), rd 是 x0
    else if (is_jalr && rs1 == 1 && rd == 0) {
        log_ftrace_ret(pc);
    }
#endif
}
