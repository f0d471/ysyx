#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

/* =========================================================================
 * 简易 free-list 分配器
 *
 * 每个块（空闲或已分配）前都有一个 BlockHeader：
 *   ┌──────────┬──────────┬─────────────────────────────┐
 *   │  size    │  free    │        用户数据区             │
 *   │ (含头)    │ (标志)    │       (malloc 返回这里)       │
 *   └──────────┴──────────┴─────────────────────────────┘
 *
 * 空闲块通过 next 指针串成单向链表。已分配块没有 next 字段。
 * ========================================================================= */

#define MHDR_SZ  ((int)sizeof(BlockHeader))
#define ALIGN(n) (((n) + 7) & ~7)  // 8 字节对齐

typedef struct BlockHeader {
  int  size;       // 本块总大小（含 header），正数=空闲，负数=-size=已分配
  struct BlockHeader *next;  // 仅空闲块有效：下一块
} BlockHeader;

static BlockHeader *free_list = NULL;

// 将一块内存插入 free_list（保持地址递增顺序，便于合并相邻块）
static void insert_free(BlockHeader *blk) {
  blk->size = blk->size > 0 ? blk->size : -blk->size;  // 确保为正
  blk->next = NULL;

  if (free_list == NULL) {
    free_list = blk;
    return;
  }

  // 按地址排序插入
  BlockHeader **pp = &free_list;
  while (*pp && (*pp) < blk) pp = &(*pp)->next;
  blk->next = *pp;
  *pp = blk;

  // 尝试与后一块合并
  if (blk->next && (char *)blk + blk->size == (char *)blk->next) {
    blk->size += blk->next->size;
    blk->next = blk->next->next;
  }

  // 尝试与前一块合并
  BlockHeader *prev = free_list;
  while (prev && prev->next != blk) prev = prev->next;
  if (prev && (char *)prev + prev->size == (char *)blk) {
    prev->size += blk->size;
    prev->next = blk->next;
  }
}

static unsigned long int next = 1;

int rand(void) {
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

int abs(int x) {
  return (x < 0 ? -x : x);
}

int atoi(const char *nptr) {
  int x = 0;
  while (*nptr == ' ') { nptr++; }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr++;
  }
  return x;
}

/* ---- 首次适应 (first-fit) malloc ---- */
void *malloc(size_t size) {
  if (size == 0) return NULL;

  int need = ALIGN((int)size + MHDR_SZ);

  // 首次调用：用 heap 的整个范围初始化 free_list
  if (free_list == NULL) {
    BlockHeader *init = (BlockHeader *)heap.start;
    int total = (int)((char *)heap.end - (char *)heap.start);
    if (total < need + MHDR_SZ) return NULL;
    init->size = total;
    init->next = NULL;
    free_list = init;
  }

  // 遍历 free_list，找第一块足够大的
  BlockHeader *prev = NULL;
  BlockHeader *cur  = free_list;
  while (cur) {
    if (cur->size >= need) {
      // 从链表摘下
      if (prev) prev->next = cur->next;
      else      free_list = cur->next;

      // 如果剩余空间够再放一个最小块（header+8字节），则分裂
      int remain = cur->size - need;
      if (remain >= MHDR_SZ + 8) {
        BlockHeader *split = (BlockHeader *)((char *)cur + need);
        split->size = remain;
        split->next = NULL;
        insert_free(split);
        cur->size = need;
      }

      cur->size = -cur->size;  // 负数标记"已分配"
      return (char *)cur + MHDR_SZ;
    }
    prev = cur;
    cur = cur->next;
  }

  return NULL;  // 没找到足够大的空闲块
}

/* ---- free + 合并相邻空闲块 ---- */
void free(void *ptr) {
  if (ptr == NULL) return;

  BlockHeader *blk = (BlockHeader *)((char *)ptr - MHDR_SZ);

  // 防御：如果已经是空闲状态，说明 double-free，直接忽略
  if (blk->size > 0) return;

  insert_free(blk);
}

#endif
