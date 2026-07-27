#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// 首次适应自由链表分配器：malloc 从 heap 区分配，free 归还并合并相邻空闲块

#define MHDR_SZ  ((int)sizeof(BlockHeader))
#define ALIGN(n) (((n) + 7) & ~7)

typedef struct BlockHeader {
  int  size;
  struct BlockHeader *next;
} BlockHeader;

static BlockHeader *free_list = NULL;
// 独立的初始化标志。不能用 free_list == NULL 代替：它同时也是"堆已耗尽"的合法状态，
// 复用会导致堆用光后把整个 heap 重新当成空闲块，把已分配的内存二次发出去。
static bool heap_inited = false;

// 把整个 heap 铺成一个空闲块，只在第一次 malloc 时执行一次
static void heap_init(void) {
  int total = (int)((char *)heap.end - (char *)heap.start);
  if (total < MHDR_SZ + 8) return;  // 堆太小连一个可用块都放不下，free_list 保持 NULL
  BlockHeader *init = (BlockHeader *)heap.start;
  init->size = total;
  init->next = NULL;
  free_list = init;
}

// 将空闲块按地址顺序插入 free_list，并合并前后相邻块
static void insert_free(BlockHeader *blk) {
  blk->size = blk->size > 0 ? blk->size : -blk->size;
  blk->next = NULL;

  if (free_list == NULL) {
    free_list = blk;
    return;
  }

  BlockHeader **pp = &free_list;
  while (*pp && (*pp) < blk) pp = &(*pp)->next;
  blk->next = *pp;
  *pp = blk;

  if (blk->next && (char *)blk + blk->size == (char *)blk->next) {
    blk->size += blk->next->size;
    blk->next = blk->next->next;
  }

  BlockHeader *prev = free_list;
  while (prev && prev->next != blk) prev = prev->next;
  if (prev && (char *)prev + prev->size == (char *)blk) {
    prev->size += blk->size;
    prev->next = blk->next;
  }
}

static unsigned long int next = 1;

// 返回一个伪随机整数
int rand(void) {
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

// 设置伪随机数种子
void srand(unsigned int seed) {
  next = seed;
}

// 返回 x 的绝对值
int abs(int x) {
  return (x < 0 ? -x : x);
}

#define LONG_MAX  __LONG_MAX__
#define LONG_MIN  (-__LONG_MAX__ - 1L)

// isspace() 的全集：空格与 \t \n \v \f \r（后五个在 ASCII 中连续，为 0x09~0x0d）
static bool is_space(char c) {
  return c == ' ' || (c >= '\t' && c <= '\r');
}

// 把一个字符按 base 进制解释成数值，非法则返回 -1
static int digit_value(char c, int base) {
  int v;
  if      (c >= '0' && c <= '9') v = c - '0';
  else if (c >= 'a' && c <= 'z') v = c - 'a' + 10;
  else if (c >= 'A' && c <= 'Z') v = c - 'A' + 10;
  else return -1;
  return (v < base) ? v : -1;
}

// 将字符串按 base 进制转换为 long（C99 §7.20.1.4）。
// base 为 0 时按前缀自动判断：0x/0X 为十六进制，前导 0 为八进制，否则十进制。
// endptr 非 NULL 时回填"解析停在哪里"；一个数字都没读到则回填原始 nptr。
// ⚠️ 与标准的唯一偏离：溢出时钳到 LONG_MAX / LONG_MIN 但**不设置 errno**
//    ——klib 没有 errno。因此调用方无法区分"真的等于 LONG_MAX"和"溢出了"。
long strtol(const char *nptr, char **endptr, int base) {
  const char *p = nptr;

  while (is_space(*p)) p++;

  bool neg = false;
  if (*p == '-' || *p == '+') {
    neg = (*p == '-');
    p++;
  }

  if (base == 0) {
    if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) { base = 16; p += 2; }
    else if (p[0] == '0')                            { base = 8;  p += 1; }
    else                                             { base = 10; }
  } else if (base == 16 && p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) {
    p += 2;
  }

  // 在无符号域累加，容量比 long 大一档，才能表示 -LONG_MIN
  unsigned long acc = 0;
  unsigned long limit = neg ? (unsigned long)LONG_MAX + 1 : (unsigned long)LONG_MAX;
  bool any = false, overflow = false;

  for (int d; (d = digit_value(*p, base)) >= 0; p++) {
    any = true;
    if (overflow) continue;                       // 已溢出，只需继续吃掉剩下的数字
    if (acc > (limit - d) / base) { overflow = true; continue; }
    acc = acc * base + d;
  }

  if (endptr) {
    // 一个有效数字都没有时，按标准把 endptr 指回最初的位置（连符号和前缀都不算消耗）
    *endptr = (char *)(any ? p : nptr);
  }

  if (!any) return 0;
  if (overflow) return neg ? LONG_MIN : LONG_MAX;

  // 取负必须在无符号域完成再转回来。若写成 -(long)acc，当 acc 等于 LONG_MAX+1
  // （即解析 LONG_MIN 时）先转 long 就已经越界，再取负是有符号溢出。
  // 无符号取负是标准定义的模 2^N 运算，转回 long 则按二补码原样解释。
  return (long)(neg ? -acc : acc);
}

// 将十进制字符串转换为 int。
// 标准把它定义为"除出错行为外等价于 strtol(nptr, NULL, 10)"，这里就照此实现——
// 手写一份独立的累加循环正是此前漏掉符号处理、且 INT_MIN 无法正确解析的原因。
int atoi(const char *nptr) {
  return (int)strtol(nptr, NULL, 10);
}

// 从 heap 分配至少 size 字节的内存，首次适应策略
void *malloc(size_t size) {
  if (size == 0) return NULL;

  int need = ALIGN((int)size + MHDR_SZ);

  if (!heap_inited) {
    heap_inited = true;
    heap_init();
  }

  BlockHeader *prev = NULL;
  BlockHeader *cur  = free_list;
  while (cur) {
    if (cur->size >= need) {
      if (prev) prev->next = cur->next;
      else      free_list = cur->next;

      int remain = cur->size - need;
      if (remain >= MHDR_SZ + 8) {
        BlockHeader *split = (BlockHeader *)((char *)cur + need);
        split->size = remain;
        split->next = NULL;
        insert_free(split);
        cur->size = need;
      }

      cur->size = -cur->size;
      return (char *)cur + MHDR_SZ;
    }
    prev = cur;
    cur = cur->next;
  }

  return NULL;
}

// 释放 ptr 指向的内存块，自动合并相邻空闲块
void free(void *ptr) {
  if (ptr == NULL) return;

  BlockHeader *blk = (BlockHeader *)((char *)ptr - MHDR_SZ);

  if (blk->size > 0) return;

  insert_free(blk);
}

// 已分配块中可供调用者使用的字节数（块总长减去块头）
static size_t payload_size(void *ptr) {
  BlockHeader *blk = (BlockHeader *)((char *)ptr - MHDR_SZ);
  int sz = blk->size < 0 ? -blk->size : blk->size;
  return (size_t)sz - MHDR_SZ;
}

// 分配 nmemb 个 size 字节的元素并清零
void *calloc(size_t nmemb, size_t size) {
  if (nmemb == 0 || size == 0) return NULL;
  // 溢出检查：nmemb * size 若回绕，会分配出远小于请求的内存，随后被越界写穿
  if (nmemb > (size_t)-1 / size) return NULL;

  size_t total = nmemb * size;
  void *p = malloc(total);
  if (p) memset(p, 0, total);
  return p;
}

// 把 ptr 指向的块改成 size 字节，内容保留 min(旧长, 新长) 字节。
// ⚠️ 与标准的偏离：size == 0 时释放并返回 NULL。C99 允许这一行为，但 C17 起
//    改为未定义，故调用方不要依赖它——要释放就直接写 free()。
void *realloc(void *ptr, size_t size) {
  if (ptr == NULL) return malloc(size);
  if (size == 0) { free(ptr); return NULL; }

  size_t old = payload_size(ptr);
  if (size <= old) return ptr;   // 原地够用就不搬，也不缩

  void *p = malloc(size);
  if (p == NULL) return NULL;    // 失败时原块必须保持有效，不能先 free
  memcpy(p, ptr, old);
  free(ptr);
  return p;
}

#endif
