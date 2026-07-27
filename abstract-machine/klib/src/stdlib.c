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

// 将十进制字符串转换为 int，跳过前导空白，识别可选的 '+' / '-' 符号
int atoi(const char *nptr) {
  int x = 0;
  int neg = 0;

  // isspace() 的全集：空格与 \t \n \v \f \r（后者在 ASCII 中是连续的 0x09~0x0d）
  while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r')) { nptr++; }

  if (*nptr == '-' || *nptr == '+') {
    neg = (*nptr == '-');
    nptr++;
  }

  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr++;
  }

  return neg ? -x : x;
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

#endif
