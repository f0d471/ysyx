#ifndef __TRACE_H__
#define __TRACE_H__

void init_trace(const char *filename);
void trace_close();
void TRACE_LOG(const char *fmt, ...);

#endif
