#include <cstdio>
#include <cstdlib>   
#include <cstring>   
#include <cassert>   
#include <cstdarg>
#include <elf.h>

#include "common.h"

typedef uint32_t paddr_t;

// ===================== log =============================
static FILE *trace_fp = NULL;

// 初始化
void init_trace(const char *filename) {
#if defined(CONFIG_ITRACE) || defined(CONFIG_MTRACE) || defined(CONFIG_FTRACE) || defined(CONFIG_DTRACE)
    if (trace_fp != NULL) return;  
    trace_fp = fopen(filename, "w");
    if (!trace_fp) {
        perror("fopen trace file failed");
        exit(1);
    }
#endif
}

// 统一的写日志接口 (大写 TRACE_LOG)
void TRACE_LOG(const char *fmt, ...) {
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
    uint32_t inst = top->debug_instr;
    disassemble(asm_buf, sizeof(asm_buf), top->debug_pc, (uint8_t *)&inst, 4);
    TRACE_LOG("[itrace] 0x%08x: 0x%08x  %s\n", top->debug_pc, inst, asm_buf);
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
    const char *op_name = get_mop_name(top->debug_instr, is_write);

    uint32_t rd  = (top->debug_instr >> 7) & 0x1F;
    uint32_t rs2 = (top->debug_instr >> 20) & 0x1F;

    if (!is_write) {
        TRACE_LOG("[mtrace] pc:0x%08x %-3s  x%-2d <- mem[0x%08x] = 0x%08x\n", 
                  top->debug_pc, op_name, rd, addr, data);
    } else {
        TRACE_LOG("[mtrace] pc:0x%08x %-3s  mem[0x%08x] <- x%-2d = 0x%08x\n", 
                  top->debug_pc, op_name, addr, rs2, data);
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
static void do_ftrace(paddr_t pc, paddr_t dnpc, uint32_t inst) {
#ifdef CONFIG_FTRACE
    if (!FTRACE_COND) return;

    uint32_t opcode = inst & 0x7F;
    uint32_t rd  = (inst >> 7) & 0x1F;
    uint32_t rs1 = (inst >> 15) & 0x1F;

    bool is_jal  = (opcode == 0x6f);
    bool is_jalr = (opcode == 0x67);

    if ((is_jal || is_jalr) && rd == 1) {
        log_ftrace_call(pc, dnpc);
    }
    else if (is_jalr && rs1 == 1 && rd == 0) {
        log_ftrace_ret(pc);
    }
#endif
}

void ftrace_on_commit(uint32_t pc, uint32_t inst) {
#ifdef CONFIG_FTRACE
    static uint32_t last_pc = 0, last_inst = 0;
    static bool has_last = false;

    if (has_last) {
        do_ftrace(last_pc, pc, last_inst);
    }
    last_pc   = pc;
    last_inst = inst;
    has_last  = true;
#endif
}