#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// pos 无论是否真的写入都要自增：返回值是"假如缓冲区足够大本该写多少"
static void append_char(char *out, size_t n, size_t *pos, char c) {
  // n == 0 必须单独判断：size_t 是无符号数，n - 1 会回绕成 SIZE_MAX 使判断恒真
  if (n > 0 && *pos < n - 1) {
    out[*pos] = c;
  }
  (*pos)++;
}

static void append_str(char *out, size_t n, size_t *pos, const char *s) {
  while (*s) append_char(out, n, pos, *s++);
}

typedef struct {
  int  width;
  char pad;     // ' ' 或 '0'
  bool left;    // '-' 标志，此时 pad 强制为 ' '
} FmtSpec;

typedef enum { LEN_INT, LEN_LONG, LEN_LLONG, LEN_SIZE } LenMod;

// 解析 %[-][0][width][l|ll|z|h|hh]，fmt 前进到转换符处
static LenMod parse_spec(const char **fmt, FmtSpec *f) {
  const char *p = *fmt;

  *f = (FmtSpec) { .width = 0, .pad = ' ', .left = false };
  for (;;) {
    if      (*p == '-') { f->left = true; p++; }
    else if (*p == '0') { f->pad  = '0';  p++; }
    else break;
  }
  if (f->left) f->pad = ' ';   // 左对齐时补零无意义，标准规定忽略 '0'

  while (*p >= '0' && *p <= '9') {
    f->width = f->width * 10 + (*p - '0');
    p++;
  }

  LenMod len = LEN_INT;
  if (*p == 'l') {
    p++;
    if (*p == 'l') { len = LEN_LLONG; p++; }
    else             len = LEN_LONG;
  } else if (*p == 'z') {
    len = LEN_SIZE;
    p++;
  } else if (*p == 'h') {
    // h / hh：实参经默认参数提升后本就是 int，吃掉修饰符即可
    p++;
    if (*p == 'h') p++;
  }

  *fmt = p;
  return len;
}

// neg 表示要在前面加负号，prefix 是紧跟符号之后的固定前缀（%p 的 "0x"），无则传 NULL
static void print_num(char *out, size_t n, size_t *pos,
                      unsigned long long uval, bool neg, int base,
                      const char *prefix, const FmtSpec *f) {
  char digits[32];   // 64 位十进制最多 20 位，十六进制 16 位
  int ndigit = 0;

  if (uval == 0) {
    digits[ndigit++] = '0';
  } else {
    while (uval > 0) {
      int d = uval % base;
      digits[ndigit++] = (d < 10) ? (d + '0') : (d - 10 + 'a');
      uval /= base;
    }
  }

  int prefix_len = 0;
  for (const char *p = prefix; p && *p; p++) prefix_len++;

  int pad_len = f->width - (ndigit + (neg ? 1 : 0) + prefix_len);

  // 空格填充在符号之前，零填充在符号之后——写反会打出 "000-5" 这种第三种形态
  if (!f->left && f->pad == ' ') {
    while (pad_len-- > 0) append_char(out, n, pos, ' ');
  }

  if (neg) append_char(out, n, pos, '-');
  if (prefix) append_str(out, n, pos, prefix);

  if (!f->left && f->pad == '0') {
    while (pad_len-- > 0) append_char(out, n, pos, '0');
  }

  while (ndigit > 0) append_char(out, n, pos, digits[--ndigit]);

  if (f->left) {
    while (pad_len-- > 0) append_char(out, n, pos, ' ');
  }
}

static void print_string(char *out, size_t n, size_t *pos, const char *s, const FmtSpec *f) {
  // strlen 返回 size_t，必须显式转 int。写成 width - strlen(s) 会把 width 提升为
  // 无符号，len > width 时先回绕成天文数字再转回 int 才碰巧变负
  int pad_len = f->width - (int)strlen(s);

  if (!f->left) {
    while (pad_len-- > 0) append_char(out, n, pos, ' ');
  }

  append_str(out, n, pos, s);

  if (f->left) {
    while (pad_len-- > 0) append_char(out, n, pos, ' ');
  }
}

static long long fetch_signed(va_list *ap, LenMod len) {
  switch (len) {
    case LEN_LONG:  return va_arg(*ap, long);
    case LEN_LLONG: return va_arg(*ap, long long);
    case LEN_SIZE:  return (long long)va_arg(*ap, size_t);
    default:        return va_arg(*ap, int);
  }
}

static unsigned long long fetch_unsigned(va_list *ap, LenMod len) {
  switch (len) {
    case LEN_LONG:  return va_arg(*ap, unsigned long);
    case LEN_LLONG: return va_arg(*ap, unsigned long long);
    case LEN_SIZE:  return va_arg(*ap, size_t);
    default:        return va_arg(*ap, unsigned int);
  }
}

// 支持 %[-][0][width][l|ll|z|h](d|i|u|x|X|p|c|s|%)。
// 返回"假如缓冲区足够大本该写入的字符数"（不含 '\0'）而非实际写入数——
// 这条语义让 snprintf(NULL, 0, ...) 量长度的惯用法得以成立
int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  size_t pos = 0;

  while (*fmt) {
    if (*fmt != '%') {
      append_char(out, n, &pos, *fmt++);
      continue;
    }
    fmt++;

    FmtSpec f;
    LenMod len = parse_spec(&fmt, &f);

    switch (*fmt) {
      case 'd':
      case 'i': {
        long long v = fetch_signed(&ap, len);
        bool neg = v < 0;
        // 先转无符号再取反，避免 -LLONG_MIN 这种有符号溢出
        unsigned long long uv = neg ? -(unsigned long long)v : (unsigned long long)v;
        print_num(out, n, &pos, uv, neg, 10, NULL, &f);
        break;
      }
      case 'u':
        print_num(out, n, &pos, fetch_unsigned(&ap, len), false, 10, NULL, &f);
        break;
      case 'x':
      case 'X':
        print_num(out, n, &pos, fetch_unsigned(&ap, len), false, 16, NULL, &f);
        break;
      case 'p': {
        // 按 void * 取参，按 unsigned int 取会在 64 位平台上截断
        uintptr_t v = (uintptr_t)va_arg(ap, void *);
        print_num(out, n, &pos, v, false, 16, "0x", &f);
        break;
      }
      case 's': {
        const char *s = va_arg(ap, const char *);
        print_string(out, n, &pos, s ? s : "(null)", &f);
        break;
      }
      case 'c': {
        // 不能包成字符串走 print_string：'\0' 会被 strlen 当成空串丢掉，
        // 而 printf("%c", '\0') 按标准应输出一个 NUL 字节
        char c = (char)va_arg(ap, int);
        int pad_len = f.width - 1;
        if (!f.left) { while (pad_len-- > 0) append_char(out, n, &pos, ' '); }
        append_char(out, n, &pos, c);
        if (f.left)  { while (pad_len-- > 0) append_char(out, n, &pos, ' '); }
        break;
      }
      case '%':
        append_char(out, n, &pos, '%');
        break;
      default:
        append_char(out, n, &pos, '%');
        // 格式串在 '%' 之后就结束了：不能再 fmt++ 跨过终止符，否则外层 while
        // 会继续扫描字符串之外的内存。continue 交给外层条件退出循环
        if (*fmt == '\0') continue;
        append_char(out, n, &pos, *fmt);
    }
    fmt++;
  }

  if (n > 0) {
    out[pos < n ? pos : n - 1] = '\0';
  }

  return pos;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int ret = vsnprintf(out, INT32_MAX, fmt, ap);
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

// 先格式化进栈缓冲区再逐字符输出，代价是 2KB 栈帧且超长会被静默截断。
// 更好的做法是把输出目标抽象成 sink，以 putch 为 sink 时零缓冲、无长度上限
int printf(const char *fmt, ...) {
  char buf[2048];
  va_list ap;
  va_start(ap, fmt);
  int len = vsnprintf(buf, sizeof(buf), fmt, ap);
  va_end(ap);

  // len 是"本该写多少"，可能超过缓冲区
  int emit = (len < (int)sizeof(buf) - 1) ? len : (int)sizeof(buf) - 1;
  for (int i = 0; i < emit; i++) {
    putch(buf[i]);
  }
  return len;
}

#endif
