#ifdef CONFIG_SDB

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <readline/readline.h>
#include <readline/history.h>

#include "common.h"
#include "sdb.h"

void init_sdb() {
    printf("SDB initialized. Type 'help' for instructions.\n");
}

static char* rl_gets() {
    static char *line_read = NULL;

    if (line_read) {
        free(line_read);
        line_read = NULL;
    }

    line_read = readline("(npc) ");

    if (line_read && *line_read) {
        add_history(line_read);
    }

    return line_read;
}

void sdb_mainloop() {
    for (char *str; (str = rl_gets()) != NULL; ) {
        char *str_end = str + strlen(str);

        char *cmd = strtok(str, " ");
        if (cmd == NULL) { continue; } 

        char *args = str + strlen(cmd) + 1;
        if (args >= str_end) {
            args = NULL;
        } else {
            while (*args == ' ') args++;
            if (*args == '\0') args = NULL;
        }

        int i;
        for (i = 0; i < NR_CMD; i++) {
            if (strcmp(cmd, cmd_table[i].name) == 0) {
                if (cmd_table[i].handler(args) < 0) { return; } 
                break;
            }
        }

        if (i == NR_CMD) { 
            printf("Unknown command '%s'\n", cmd); 
        }
    }
}

#endif