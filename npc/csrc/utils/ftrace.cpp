#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <elf.h>

#include "utils.h"

#ifdef CONFIG_FTRACE

typedef uint32_t paddr_t;

#define MAX_FUNCS 1024

// ==================== ELF 符号解析 ====================

typedef struct {
    char name[64];
    paddr_t addr;
    uint32_t size;
} FuncSymbol;

static FuncSymbol func_syms[MAX_FUNCS];
static int func_sym_cnt = 0;

static const char* ftrace_get_func_name(paddr_t addr) {
    for (int i = 0; i < func_sym_cnt; i++) {
        if (addr >= func_syms[i].addr && addr < func_syms[i].addr + func_syms[i].size) {
            return func_syms[i].name;
        }
    }
    return "???";
}

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

    Elf32_Ehdr ehdr;
    if (fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp) != 1) {
        fprintf(stderr, "Failed to read ELF header\n");
        exit(1);
    }

    if (*(uint32_t *)ehdr.e_ident != 0x464c457f) {
        fprintf(stderr, "Not a valid ELF file: %s\n", elf_file);
        exit(1);
    }

    Elf32_Shdr *shdrs = (Elf32_Shdr *)malloc(ehdr.e_shentsize * ehdr.e_shnum);
    assert(shdrs);
    fseek(fp, ehdr.e_shoff, SEEK_SET);
    if (fread(shdrs, ehdr.e_shentsize, ehdr.e_shnum, fp) != ehdr.e_shnum) {
        fprintf(stderr, "Failed to read Section Headers\n");
        exit(1);
    }

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

    char *strtab = (char *)malloc(strtab_shdr->sh_size);
    assert(strtab);
    fseek(fp, strtab_shdr->sh_offset, SEEK_SET);
    if (fread(strtab, 1, strtab_shdr->sh_size, fp) != strtab_shdr->sh_size) {
        fprintf(stderr, "Failed to read string table\n");
        exit(1);
    }

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
            f->name[sizeof(f->name) - 1] = '\0';

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

// ==================== call / ret 记录 ====================

static int ftrace_depth = 0;

static void log_ftrace_call(paddr_t pc, paddr_t dnpc) {
    const char* func_name = ftrace_get_func_name(dnpc);
    iringbuf_push("[ftrace] 0x%08x: %*scall [%s@0x%08x]\n",
                  pc, ftrace_depth * 2, "", func_name, dnpc);
    ftrace_depth++;
}

static void log_ftrace_ret(paddr_t pc) {
    ftrace_depth--;
    if (ftrace_depth < 0) ftrace_depth = 0;

    const char* func_name = ftrace_get_func_name(pc);
    iringbuf_push("[ftrace] 0x%08x: %*sret  [%s]\n",
                  pc, ftrace_depth * 2, "", func_name);
}

// ==================== 指令分析 ====================

static void do_ftrace(paddr_t pc, paddr_t dnpc, uint32_t inst) {
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
}

void ftrace_on_commit(uint32_t pc, uint32_t inst) {
    static uint32_t last_pc = 0, last_inst = 0;
    static bool has_last = false;

    if (has_last) {
        do_ftrace(last_pc, pc, last_inst);
    }
    last_pc   = pc;
    last_inst = inst;
    has_last  = true;
}

#endif // CONFIG_FTRACE
