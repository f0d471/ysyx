#include <common.h>
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCS 1024 // 假设程序中最多有 1024 个函数

// 保存函数信息
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

void init_ftrace(const char *elf_file) {
    if (elf_file == NULL) {
        Log("No ELF file given, ftrace will not work.");
        return;
    }

    FILE *fp = fopen(elf_file, "rb");
    Assert(fp, "Can not open '%s'", elf_file);

    // 读取 ELF 头 (ELF Header)
    Elf32_Ehdr ehdr;
    if (fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp) != 1) {
        panic("Failed to read ELF header");
    }

    if (*(uint32_t *)ehdr.e_ident != 0x464c457f) {
        panic("Not a valid ELF file: %s", elf_file);
    }

    // 读取节头表 (Section Headers)
    Elf32_Shdr *shdrs = malloc(ehdr.e_shentsize * ehdr.e_shnum);
    assert(shdrs);
    fseek(fp, ehdr.e_shoff, SEEK_SET);
    if (fread(shdrs, ehdr.e_shentsize, ehdr.e_shnum, fp) != ehdr.e_shnum) {
        panic("Failed to read Section Headers");
    }

    // 寻找符号表 (.symtab) 和对应的字符串表 (.strtab)
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
        Log("No symbol table found in %s", elf_file);
        free(shdrs);
        fclose(fp);
        return;
    }

    // 把字符串表整个读进内存
    char *strtab = malloc(strtab_shdr->sh_size);
    assert(strtab);
    fseek(fp, strtab_shdr->sh_offset, SEEK_SET);
    if (fread(strtab, 1, strtab_shdr->sh_size, fp) != strtab_shdr->sh_size) {
        panic("Failed to read string table");
    }

    // 读取符号表，并提取所有的函数 (STT_FUNC)
    int sym_num = symtab_shdr->sh_size / symtab_shdr->sh_entsize;
    Elf32_Sym *syms = malloc(symtab_shdr->sh_size);
    assert(syms);
    fseek(fp, symtab_shdr->sh_offset, SEEK_SET);
    if (fread(syms, symtab_shdr->sh_entsize, sym_num, fp) != sym_num) {
        panic("Failed to read symbol table");
    }

    for (int i = 0; i < sym_num; i++) {
        // 如果这个符号的类型是函数 (FUNC)
        if (ELF32_ST_TYPE(syms[i].st_info) == STT_FUNC) {
            FuncSymbol *f = &func_syms[func_sym_cnt++];
            f->addr = syms[i].st_value;
            f->size = syms[i].st_size;
            strncpy(f->name, strtab + syms[i].st_name, sizeof(f->name) - 1);
            f->name[sizeof(f->name) - 1] = '\0'; 

            if (func_sym_cnt >= MAX_FUNCS) {
                Log("Warning: Too many functions, truncating!");
                break;
            }
        }
    }

    Log("Loaded %d functions from %s for ftrace.", func_sym_cnt, elf_file);

    free(syms);
    free(strtab);
    free(shdrs);
    fclose(fp);
}

// 给定一个地址，查字典找函数名
const char* ftrace_get_func_name(paddr_t addr) {
    for (int i = 0; i < func_sym_cnt; i++) {
        if (addr >= func_syms[i].addr && addr < func_syms[i].addr + func_syms[i].size) {
            return func_syms[i].name;
        }
    }
    return "???";
}

// 记录 Call 操作 
void log_ftrace_call(paddr_t pc, paddr_t dnpc) {
#ifdef CONFIG_FTRACE
    if (likely(!FTRACE_COND)) return;

    const char* func_name = ftrace_get_func_name(dnpc);
    TRACE_LOG("[FTRACE] 0x%08x: %*scall [%s@0x%08x]\n", pc, ftrace_depth * 2, "", func_name, dnpc);
    ftrace_depth++;
#endif
}

// 记录 Ret 操作 
void log_ftrace_ret(paddr_t pc) {
#ifdef CONFIG_FTRACE
    if (likely(!FTRACE_COND)) return;

    ftrace_depth--;
    if (ftrace_depth < 0) ftrace_depth = 0; // 防止深度为负
    
    const char* func_name = ftrace_get_func_name(pc);
    TRACE_LOG("[FTRACE] 0x%08x: %*sret  [%s]\n", pc, ftrace_depth * 2, "", func_name);
#endif
}