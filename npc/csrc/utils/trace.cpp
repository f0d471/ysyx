#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>

#include "trace.h"
#include "ftrace.h"

static FILE *trace_fp = NULL;
static char trace_filename[512];

void init_trace(const char *filename) {
    if (trace_fp != NULL) return;

    strncpy(trace_filename, filename, sizeof(trace_filename) - 1);
    trace_filename[sizeof(trace_filename) - 1] = '\0';

    char tmp_name[512];
    snprintf(tmp_name, sizeof(tmp_name), "%s.tmp", filename);
    trace_fp = fopen(tmp_name, "w");
    if (!trace_fp) {
        perror("fopen trace file failed");
        exit(1);
    }
}

void TRACE_LOG(const char *fmt, ...) {
    if (!trace_fp) return;

    va_list args;
    va_start(args, fmt);
    vfprintf(trace_fp, fmt, args);
    va_end(args);

    fflush(trace_fp);
}

void trace_close() {
    if (!trace_fp) return;

    // 1. 关闭临时文件
    fclose(trace_fp);
    trace_fp = NULL;

    // 2. 读取临时文件中的 I/M/D trace 内容
    char tmp_name[512];
    snprintf(tmp_name, sizeof(tmp_name), "%s.tmp", trace_filename);

    FILE *tmp_fp = fopen(tmp_name, "r");
    long tmp_size = 0;
    char *tmp_content = NULL;

    if (tmp_fp) {
        fseek(tmp_fp, 0, SEEK_END);
        tmp_size = ftell(tmp_fp);
        if (tmp_size > 0) {
            rewind(tmp_fp);
            tmp_content = (char *)malloc(tmp_size + 1);
            fread(tmp_content, 1, tmp_size, tmp_fp);
            tmp_content[tmp_size] = '\0';
        }
        fclose(tmp_fp);
    }

    // 3. 打开最终文件，组装输出
    FILE *final_fp = fopen(trace_filename, "w");
    if (!final_fp) {
        remove(tmp_name);
        free(tmp_content);
        return;
    }

#ifdef CONFIG_FTRACE
    ftrace_buf_flush(final_fp);
    fprintf(final_fp, "\n========== FTRACE END / I/M/D TRACE START ==========\n\n");
#endif

    if (tmp_content) {
        fputs(tmp_content, final_fp);
        free(tmp_content);
    }

    fclose(final_fp);
    remove(tmp_name);
}
