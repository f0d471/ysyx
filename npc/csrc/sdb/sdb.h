#ifndef __SDB_H__
#define __SDB_H__

#include "config.h"

#ifdef CONFIG_SDB

typedef int (*CmdHandler)(char *args);

struct Command {
    const char *name;
    const char *description;
    CmdHandler handler;
};

extern Command cmd_table[];
extern const int NR_CMD;

void init_sdb();
void sdb_mainloop();

#endif
#endif
