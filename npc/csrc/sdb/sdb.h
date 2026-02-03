#include "common.h"  

#ifdef CONFIG_SDB

#ifndef __SDB_H__
#define __SDB_H__


typedef int (*CmdHandler)(char *args);  

struct Command {
    const char *name;         
    const char *description; 
    CmdHandler handler;      
};

extern Command cmd_table[];
extern const int NR_CMD;

#endif // __SDB_H__

#endif