#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// ============================================================================
// 1. 基础工具函数：向 buffer 安全写入字符
// ============================================================================
static void append_char(char *out, size_t n, size_t *pos, char c) {
  if (*pos < n - 1) { // 留一个位置给 '\0'
    out[*pos] = c;
  }
  (*pos)++;
}

// ============================================================================
// 2. 核心逻辑：打印数字 (支持进制、宽度、补零)
// ============================================================================
static void print_num(char *out, size_t n, size_t *pos, long long val, int base, int width, char pad) {
  char buf[32]; // 足够存 64 位整数
  int i = 0;
  unsigned long long uval = (unsigned long long)val;
  int sign = 0;

  // 处理负数 (仅限十进制)
  if (base == 10 && val < 0) {
    sign = 1;
    uval = -val;
  }

  // 1. 转换数字为字符串 (逆序)
  if (uval == 0) {
    buf[i++] = '0';
  } else {
    while (uval > 0) {
      int digit = uval % base;
      // 支持十六进制小写
      buf[i++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a'); 
      uval /= base;
    }
  }

  // 2. 计算实际需要的长度 (数字位数 + 符号位)
  int real_len = i + sign;

  // 3. 计算需要填充的字符数
  int pad_len = width - real_len;

  // 4. 打印逻辑 (注意：如果 pad 是 '0'，符号要写在 padding 之前)
  if (sign && pad == '0') {
    append_char(out, n, pos, '-');
    sign = 0; // 符号已处理
  }

  // 打印前导填充
  while (pad_len > 0) {
    append_char(out, n, pos, pad);
    pad_len--;
  }

  // 打印符号 (如果 pad 是空格，符号紧贴数字)
  if (sign) {
    append_char(out, n, pos, '-');
  }

  // 打印数字 (逆序输出)
  while (i > 0) {
    append_char(out, n, pos, buf[--i]);
  }
}

// ============================================================================
// 3. 核心逻辑：打印字符串 (支持宽度对齐)
// ============================================================================
static void print_string(char *out, size_t n, size_t *pos, const char *s, int width) {
  size_t len = strlen(s);
  int pad_len = width - len;
  
  // 打印前导空格 (默认右对齐)
  while (pad_len > 0) {
    append_char(out, n, pos, ' ');
    pad_len--;
  }

  while (*s) {
    append_char(out, n, pos, *s++);
  }
}

// ============================================================================
// 4. 全能格式化函数 vsnprintf
// ============================================================================
int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  size_t pos = 0;

  while (*fmt) {
    if (*fmt != '%') {
      append_char(out, n, &pos, *fmt++);
      continue;
    }

    fmt++; // 跳过 '%'

    // --- 解析 Flags (补零 '0') ---
    char pad = ' ';
    if (*fmt == '0') {
      pad = '0';
      fmt++;
    }

    // --- 解析 Width (宽度) ---
    int width = 0;
    while (*fmt >= '0' && *fmt <= '9') {
      width = width * 10 + (*fmt - '0');
      fmt++;
    }

    // --- 解析 Specifier (类型) ---
    switch (*fmt) {
      case 'd': {
        int val = va_arg(ap, int);
        print_num(out, n, &pos, val, 10, width, pad);
        break;
      }
      case 'x':
      case 'p': { // 指针和十六进制都按 hex 处理
        unsigned int val = va_arg(ap, unsigned int); // 这里简化为 32 位，若需 64 位可用 unsigned long long
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
      default: // 未知格式，原样输出
        append_char(out, n, &pos, '%');
        append_char(out, n, &pos, *fmt);
    }
    fmt++;
  }

  // 确保字符串以 '\0' 结尾
  if (n > 0) {
    if (pos < n) out[pos] = '\0';
    else out[n - 1] = '\0';
  }

  return pos;
}

// ============================================================================
// 5. 包装函数 (Wrapper)
// ============================================================================

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsnprintf(out, INT32_MAX, fmt, ap); // 假设足够大
  va_end(ap);
  return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsnprintf(out, n, fmt, ap);
  va_end(ap);
  return ret;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  return vsnprintf(out, INT32_MAX, fmt, ap);
}

int printf(const char *fmt, ...) {
  char buf[2048]; // 增大缓冲区以防溢出
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