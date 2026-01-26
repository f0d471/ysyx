#include <cstdio>
#include <cstring>
#include <cstdlib>

#include "common.h" 
#include "sdb.h"

static int cmd_c(char *args) {
    if (npc_state == NPC_END) {
        printf(ANSI_FG_RED "Program already ended. Restart NPC to run again.\n" ANSI_NONE);
        return 0;
    }
    cpu_exec(-1); 
    return 0;
}

static int cmd_si(char *args) {
    if (npc_state == NPC_END) {
        printf(ANSI_FG_RED "Program already ended. Restart NPC to run again.\n" ANSI_NONE);
        return 0;
    }
    
    uint64_t step = 1;
    if (args != NULL) {
        char *endptr;
        step = strtoull(args, &endptr, 10);
        if (*endptr != '\0') { 
            printf(ANSI_FG_RED "Invalid step count: %s\n" ANSI_NONE, args);
            return 0;
        }
    }
    
    cpu_exec(step);
    printf(ANSI_FG_GREEN "pc: 0x%08x" ANSI_NONE " inst: 0x%08x\n", top->pc, top->inst);
    return 0;
}

static int cmd_q(char *args) {
    npc_state = NPC_END;
    return -1; 
}

static int cmd_x(char *args) {
    char* arg_n = strtok(args, " ");
    char* arg_addr = strtok(NULL, " ");

    if (arg_n == NULL || arg_addr == NULL) {
        printf(ANSI_FG_RED "Usage: x [N] [EXPR/ADDR]\n" ANSI_NONE);
        return 0;
    }

    int len = strtoul(arg_n, NULL, 10);
    uint32_t addr = strtoul(arg_addr, NULL, 16); 

    if (len > 1024) { 
        printf(ANSI_FG_RED "Length too large, limit to 1024.\n" ANSI_NONE);
        len = 1024;
    }

    for (int i = 0; i < len; i++) {
        if (i % 4 == 0) printf("0x%08x: ", addr);
        printf("0x%08x ", pmem_read(addr, 4));
        addr += 4;
        if ((i + 1) % 4 == 0 || i == len - 1) printf("\n");
    }
    return 0;
}

static int cmd_info(char *args) {
    if (args == NULL) {
        printf(ANSI_FG_RED "Missing argument. Usage: info r\n" ANSI_NONE);
    } else if (strcmp(args, "r") == 0) {
        isa_reg_display(top);
    } else {
        printf(ANSI_FG_RED "Unknown info target: %s\n" ANSI_NONE, args);
    }
    return 0;
}

static int cmd_help(char *args); 

// =================== 命令注册表 ===================
Command cmd_table[] = {
    { "help", "Display information about all supported commands", cmd_help },
    { "c",    "Continue the execution of the program", cmd_c },
    { "q",    "Exit NEMU", cmd_q },
    { "si",   "Step into the program: si [N]", cmd_si },
    { "info", "Print register status: info r", cmd_info },
    { "x",    "Scan memory: x [N] [ADDR]", cmd_x }
};

const int NR_CMD = sizeof(cmd_table) / sizeof(cmd_table[0]);

static int cmd_help(char *args) {
    char *arg = strtok(NULL, " ");

    if (arg == NULL) {
        for (int i = 0; i < NR_CMD; i++) {
            printf("%-10s - %s\n", cmd_table[i].name, cmd_table[i].description);
        }
    } else {
        for (int i = 0; i < NR_CMD; i++) {
            if (strcmp(arg, cmd_table[i].name) == 0) {
                printf("%-10s - %s\n", cmd_table[i].name, cmd_table[i].description);
                return 0;
            }
        }
        printf(ANSI_FG_RED "Unknown command '%s'\n" ANSI_NONE, arg);
    }
    return 0;
}