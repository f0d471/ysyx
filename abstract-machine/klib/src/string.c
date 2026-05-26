#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// 返回字符串长度（不含结尾 '\0'）
size_t strlen(const char *s) {
  const char *p = s;
  while (*p) p++;
  return p - s;
}

// 将 src 字符串拷贝到 dst（含 '\0'），返回 dst
char *strcpy(char *dst, const char *src) {
  char *p = dst;
  while ((*p++ = *src++) != '\0') {}
  return dst;
}

// 将 src 最多 n 个字符拷贝到 dst，不足部分补 '\0'
char *strncpy(char *dst, const char *src, size_t n) {
  char *p = dst;
  size_t i;
  for (i = 0; i < n && src[i]; i++) {
    p[i] = src[i];
  }
  for (; i < n; i++) {
    p[i] = '\0';
  }
  return dst;
}

// 将 src 追加到 dst 末尾，返回 dst
char *strcat(char *dst, const char *src) {
  char *p = dst + strlen(dst);
  while ((*p++ = *src++) != '\0') {}
  return dst;
}

// 比较 s1 和 s2，返回差值
int strcmp(const char *s1, const char *s2) {
  while (*s1 != '\0' && *s1 == *s2) {
    s1++;
    s2++;
  }
  return (uint8_t)*s1 - (uint8_t)*s2;
}

// 比较 s1 和 s2 的前 n 个字符，返回差值
int strncmp(const char *s1, const char *s2, size_t n) {
  size_t i = 0;
  for (; i < n; i++) {
    if (s1[i] != s2[i] || s1[i] == '\0') {
      return (uint8_t)s1[i] - (uint8_t)s2[i];
    }
  }
  return 0;
}

// 将 s 的前 n 字节设为 c，返回 s
void *memset(void *s, int c, size_t n) {
  unsigned char *p = s;
  unsigned char uc = (unsigned char)c;
  for (size_t i = 0; i < n; i++) {
    p[i] = uc;
  }
  return s;
}

// 在重叠区间安全地拷贝 n 字节从 src 到 dst
void *memmove(void *dst, const void *src, size_t n) {
  unsigned char *d = dst;
  const unsigned char *s = src;
  if (d < s) {
    for (size_t i = 0; i < n; i++) {
      d[i] = s[i];
    }
  } else if (d > s) {
    for (size_t i = n; i > 0; i--) {
      d[i - 1] = s[i - 1];
    }
  }
  return dst;
}

// 将 src 的 n 字节拷贝到 dst（区间不可重叠）
void *memcpy(void *out, const void *in, size_t n) {
  unsigned char *d = out;
  const unsigned char *s = in;
  for (size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return out;
}

// 比较 s1 和 s2 的前 n 字节，返回差值
int memcmp(const void *s1, const void *s2, size_t n) {
  const unsigned char *p1 = s1, *p2 = s2;
  for (size_t i = 0; i < n; i++) {
    if (p1[i] != p2[i]) {
      return p1[i] - p2[i];
    }
  }
  return 0;
}

#endif
