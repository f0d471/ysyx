#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// 向输出缓冲区安全追加一个字符，超出容量则丢弃
// pos 无论是否真的写入都要自增：vsnprintf 的返回值是"假如缓冲区足够大本该写多少"
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

// 一次转换的格式属性，避免在函数间传一长串平行参数
typedef struct {
  int   width;    // 最小字段宽度
  char  pad;      // 填充字符：' ' 或 '0'
  bool  left;     // '-' 标志：左对齐（此时 pad 强制为 ' '）
} FmtSpec;

// 将无符号整数按指定进制格式化。neg 表示需要在前面加负号（有符号转换用），
// prefix 是紧跟在符号之后的固定前缀（%p 的 "0x"），没有则传 NULL。
static void print_num(char *out, size_t n, size_t *pos,
                      unsigned long long uval, bool neg, int base,
                      const char *prefix, const FmtSpec *f) {
  // 64 位二进制最多 64 位，十进制最多 20 位，32 字节足够
  char digits[32];
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

  // 空格填充在符号之前，零填充在符号之后——否则会打出 "  -5" 与 "-005" 之外的
  // 第三种错误形态 "000-5"
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
  // strlen 返回 size_t（无符号），必须显式转成 int 再参与减法。
  // 若写成 width - len，width 会被提升为 size_t，len > width 时先在无符号域回绕成
  // 天文数字，再隐式转回 int 才碰巧变负——结果对，但对得靠实现定义行为。
  int pad_len = f->width - (int)strlen(s);

  if (!f->left) {
    while (pad_len-- > 0) append_char(out, n, pos, ' ');
  }

  append_str(out, n, pos, s);

  if (f->left) {
    while (pad_len-- > 0) append_char(out, n, pos, ' ');
  }
}

// 长度修饰符，决定从 va_list 里按什么宽度取参数
typedef enum { LEN_INT, LEN_LONG, LEN_LLONG, LEN_SIZE } LenMod;

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

// 核心格式化引擎：解析 fmt 字符串，将结果写入 out。
// 返回"假如缓冲区足够大本该写入的字符数"（不含 '\0'），而非实际写入数——
// 这条语义让 snprintf(NULL, 0, ...) 量长度的惯用法得以成立。
//
// 支持 %[-][0][width][l|ll|z](d|i|u|x|X|p|c|s|%)
int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  size_t pos = 0;

  while (*fmt) {
    if (*fmt != '%') {
      append_char(out, n, &pos, *fmt++);
      continue;
    }

    fmt++;  // 吃掉 '%'

    // ---- 标志 ----
    FmtSpec f = { .width = 0, .pad = ' ', .left = false };
    for (;;) {
      if (*fmt == '-')      { f.left = true; fmt++; }
      else if (*fmt == '0') { f.pad  = '0'; fmt++; }
      else break;
    }
    if (f.left) f.pad = ' ';   // 左对齐时补零没有意义，标准规定忽略 '0'

    // ---- 宽度 ----
    while (*fmt >= '0' && *fmt <= '9') {
      f.width = f.width * 10 + (*fmt - '0');
      fmt++;
    }

    // ---- 长度修饰 ----
    LenMod len = LEN_INT;
    if (*fmt == 'l') {
      fmt++;
      if (*fmt == 'l') { len = LEN_LLONG; fmt++; }
      else             { len = LEN_LONG; }
    } else if (*fmt == 'z') {
      len = LEN_SIZE;
      fmt++;
    } else if (*fmt == 'h') {
      // h / hh：实参经默认参数提升后本就是 int，直接吃掉修饰符即可
      fmt++;
      if (*fmt == 'h') fmt++;
    }

    // ---- 转换符 ----
    switch (*fmt) {
      case 'd':
      case 'i': {
        long long v = fetch_signed(&ap, len);
        bool neg = v < 0;
        // 先转成无符号再取反，避免 -LLONG_MIN 溢出（有符号溢出是未定义行为）
        unsigned long long uv = neg ? -(unsigned long long)v : (unsigned long long)v;
        print_num(out, n, &pos, uv, neg, 10, NULL, &f);
        break;
      }
      case 'u': {
        print_num(out, n, &pos, fetch_unsigned(&ap, len), false, 10, NULL, &f);
        break;
      }
      case 'x':
      case 'X': {
        print_num(out, n, &pos, fetch_unsigned(&ap, len), false, 16, NULL, &f);
        break;
      }
      case 'p': {
        // 指针按 void* 取，不能按 unsigned int——在 64 位平台上会截断
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
        // 字符经默认参数提升后是 int。
        // 不能包成 "字符串" 再走 print_string——'\0' 会被 strlen 当成空串而丢失，
        // 而 printf("%c", '\0') 按标准应当输出一个 NUL 字节
        char c = (char)va_arg(ap, int);
        int pad_len = f.width - 1;
        if (!f.left) { while (pad_len-- > 0) append_char(out, n, &pos, ' '); }
        append_char(out, n, &pos, c);
        if (f.left)  { while (pad_len-- > 0) append_char(out, n, &pos, ' '); }
        break;
      }
      case '%': {
        append_char(out, n, &pos, '%');
        break;
      }
      default:
        // 不认识的转换符：原样吐出 '%' 和它，便于发现格式串写错
        append_char(out, n, &pos, '%');
        // 格式串在 '%' 之后就结束了：此时 *fmt 已经是 '\0'，不能再 fmt++ 跨过终止符，
        // 否则外层 while 会继续扫描字符串之外的内存。continue 交给外层条件退出循环。
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

// 格式化字符串到 out（无长度限制，调用者需自行保证缓冲区足够大）
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

// 格式化输出到串口。
// 这里先格式化进栈缓冲区再逐字符 putch，代价是 2KB 栈帧且超长会被截断；
// 更好的做法是把"输出目标"抽象成 sink，printf 直接以 putch 为 sink、零缓冲。
// 该重构记在 note/todo/，本轮未做。
int printf(const char *fmt, ...) {
  char buf[2048];
  va_list ap;
  va_start(ap, fmt);
  int len = vsnprintf(buf, sizeof(buf), fmt, ap);
  va_end(ap);

  // len 是"本该写多少"，可能超过缓冲区，实际能输出的以缓冲区为准
  int emit = (len < (int)sizeof(buf) - 1) ? len : (int)sizeof(buf) - 1;
  for (int i = 0; i < emit; i++) {
    putch(buf[i]);
  }
  return len;
}

#endif
