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

void *malloc(size_t size) {
  if (size == 0) return NULL;

  int need = ALIGN((int)size + MHDR_SZ);

  if (free_list == NULL) {
    BlockHeader *init = (BlockHeader *)heap.start;
    int total = (int)((char *)heap.end - (char *)heap.start);
    if (total < need + MHDR_SZ) return NULL;
    init->size = total;
    init->next = NULL;
    free_list = init;
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

void free(void *ptr) {
  if (ptr == NULL) return;

  BlockHeader *blk = (BlockHeader *)((char *)ptr - MHDR_SZ);

  if (blk->size > 0) return;

  insert_free(blk);
}

#endif
