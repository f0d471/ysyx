#include <cstdio>
#include <cstring>
#include <cstdarg>

#include "utils.h"

// ==================== iringbuf — F/I/M/D 共用环形缓冲区 ====================
#define IRINGBUF_SIZE 2056

static char iringbuf[IRINGBUF_SIZE][256];
static int iringbuf_w = 0;
static int iringbuf_cnt = 0;

void iringbuf_push(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsnprintf(iringbuf[iringbuf_w], 256, fmt, args);
    va_end(args);

    iringbuf_w = (iringbuf_w + 1) % IRINGBUF_SIZE;
    if (iringbuf_cnt < IRINGBUF_SIZE) iringbuf_cnt++;
}

static void iringbuf_flush(FILE *fp) {
    if (iringbuf_cnt == 0) return;

    int count = iringbuf_cnt;
    int start = (count < IRINGBUF_SIZE) ? 0 : iringbuf_w;

    fprintf(fp, "\n========== TRACE RINGBUF (%d/%d entries) ==========\n",
            count, IRINGBUF_SIZE);
    for (int i = 0; i < count; i++) {
        int idx = (start + i) % IRINGBUF_SIZE;
        fputs(iringbuf[idx], fp);
    }
    fprintf(fp, "========== TRACE END ==========\n");
}

// ==================== 文件管理 ====================
static char trace_filename[512];

void init_trace(const char *filename) {
    strncpy(trace_filename, filename, sizeof(trace_filename) - 1);
    trace_filename[sizeof(trace_filename) - 1] = '\0';
}

void trace_close() {
    FILE *fp = fopen(trace_filename, "w");
    if (!fp) return;

    iringbuf_flush(fp);

    fclose(fp);
}
