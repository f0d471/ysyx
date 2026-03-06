#include <capstone/capstone.h>
#include <cstdio>
#include <cstring>
#include <cassert>

// 静态的 Capstone 句柄
static csh capstone_handle;

// 使用 extern "C" 让 C++ 暴露 C 风格的接口，防止链接时由于符号修饰找不到函数
extern "C" void init_disasm() {
    // 初始化 Capstone 为 RISC-V 32位 架构
    if (cs_open(CS_ARCH_RISCV, CS_MODE_RISCV32, &capstone_handle) != CS_ERR_OK) {
        fprintf(stderr, "Failed to initialize Capstone disassembler!\n");
        assert(0);
    }
}

extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
    cs_insn *insn;
    // 调用 Capstone 进行反汇编
    size_t count = cs_disasm(capstone_handle, code, nbyte, pc, 0, &insn);
    
    if (count > 0) {
        // 反汇编成功，格式化为 "指令名 操作数" 的字符串
        snprintf(str, size, "%s %s", insn[0].mnemonic, insn[0].op_str);
        cs_free(insn, count);
    } else {
        // 反汇编失败（遇到非法指令）
        snprintf(str, size, "???");
    }
}