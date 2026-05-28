#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// 向输出缓冲区安全追加一个字符，超出容量则丢弃
static void append_char(char *out, size_t n, size_t *pos, char c) {
  if (*pos < n - 1) {
    out[*pos] = c;
  }
  (*pos)++;
}

// 将整数按指定进制、宽度和填充符格式化到输出缓冲区
static void print_num(char *out, size_t n, size_t *pos, long long val, int base, int width, char pad) {
  char buf[32];
  int i = 0;
  unsigned long long uval = (unsigned long long)val;
  int sign = 0;

  if (base == 10 && val < 0) {
    sign = 1;
    uval = -val;
  }

  if (uval == 0) {
    buf[i++] = '0';
  } else {
    while (uval > 0) {
      int digit = uval % base;
      buf[i++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
      uval /= base;
    }
  }

  int real_len = i + sign;
  int pad_len = width - real_len;

  if (sign && pad == '0') {
    append_char(out, n, pos, '-');
    sign = 0;
  }

  while (pad_len > 0) {
    append_char(out, n, pos, pad);
    pad_len--;
  }

  if (sign) {
    append_char(out, n, pos, '-');
  }

  while (i > 0) {
    append_char(out, n, pos, buf[--i]);
  }
}

// 将字符串按指定宽度右对齐格式化到输出缓冲区
static void print_string(char *out, size_t n, size_t *pos, const char *s, int width) {
  size_t len = strlen(s);
  int pad_len = width - len;

  while (pad_len > 0) {
    append_char(out, n, pos, ' ');
    pad_len--;
  }

  while (*s) {
    append_char(out, n, pos, *s++);
  }
}

// 核心格式化引擎：解析 fmt 字符串，将结果写入 out，返回写入字符数（不含 '\0'）
int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  size_t pos = 0;

  while (*fmt) {
    if (*fmt != '%') {
      append_char(out, n, &pos, *fmt++);
      continue;
    }

    fmt++;

    char pad = ' ';
    if (*fmt == '0') {
      pad = '0';
      fmt++;
    }

    int width = 0;
    while (*fmt >= '0' && *fmt <= '9') {
      width = width * 10 + (*fmt - '0');
      fmt++;
    }

    switch (*fmt) {
      case 'd': {
        int val = va_arg(ap, int);
        print_num(out, n, &pos, val, 10, width, pad);
        break;
      }
      case 'x':
      case 'p': {
        unsigned int val = va_arg(ap, unsigned int);
        print_num(out, n, &pos, val, 16, width, pad);
        break;
      }
      case 's': {
        const char *s = va_arg(ap, const char *);
        if (!s) s = "(null)";
        print_string(out, n, &pos, s, width);
        break;
      }
      case 'c': {
        char c = (char)va_arg(ap, int);
        append_char(out, n, &pos, c);
        break;
      }
      case '%': {
        append_char(out, n, &pos, '%');
        break;
      }
      default:
        append_char(out, n, &pos, '%');
        append_char(out, n, &pos, *fmt);
    }
    fmt++;
  }

  if (n > 0) {
    if (pos < n) out[pos] = '\0';
    else out[n - 1] = '\0';
  }

  return pos;
}

// 格式化字符串到 out（无长度限制）
int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsnprintf(out, INT32_MAX, fmt, ap);
  va_end(ap);
  return ret;
}

// 格式化字符串到 out，最多写入 n-1 个字符加 '\0'
int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsnprintf(out, n, fmt, ap);
  va_end(ap);
  return ret;
}

// 格式化字符串到 out，使用已有的 va_list
int vsprintf(char *out, const char *fmt, va_list ap) {
  return vsnprintf(out, INT32_MAX, fmt, ap);
}

// 格式化输出到串口：先格式化到栈缓冲区，再逐字符通过 putch 输出
int printf(const char *fmt, ...) {
  char buf[2048];
  va_list ap;
  va_start(ap, fmt);
  int len = vsnprintf(buf, sizeof(buf), fmt, ap);
  va_end(ap);

  for (int i = 0; i < len && i < sizeof(buf) - 1; i++) {
    putch(buf[i]);
  }
  return len;
}

#endif
