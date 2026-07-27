// klib 缺陷回归测试（临时）
//
// 一次性验证 2026-07-27 abstract-machine 复盘中修复的 4 个可自动检测的缺陷。
// 每条的原理、复现与修法见 note/bug/abstract-machine/。
//
//   BUG-01  vsnprintf  格式串以单个 '%' 结尾时越界扫描
//   BUG-02  append_char  n == 0 时无符号下溢击穿缓冲区
//   BUG-03  malloc  free_list == NULL 身兼两职，堆耗尽后二次分配
//   BUG-05  atoi  不识别正负号
//
// BUG-04（NEMU GPU 热路径上的调试 printf）无法在 cpu-tests 里自动断言——它的
// 症状是串口输出与帧率，需要跑 am-kernels/kernels/slider 用肉眼确认。
//
// 运行（只跑这一个）：
//   cd am-kernels/tests/cpu-tests
//   make run ARCH=riscv32-nemu ALL=klib-bugfix
//   make run ARCH=riscv32-npc  ALL=klib-bugfix
//
// 验证通过后即可删除本文件。

#include "trap.h"

static int failed = 0;

__attribute__((noinline))
static void expect(bool cond, const char *what) {
  printf(cond ? "  [ OK ] %s\n" : "  [FAIL] %s\n", what);
  if (!cond) failed++;
}

// ---------------------------------------------------------------- BUG-01
// 修复前：吃掉 '%' 后 *fmt 已是 '\0'，switch 落到 default，末尾的 fmt++ 跨过
// 终止符，外层 while 继续扫描字符串之外的内存。
static void test_bug01_trailing_percent(void) {
  // 格式串放进栈数组而非字面量，有两个目的：
  //   1. 避开 GCC 的 -Wformat（CFLAGS 带 -Werror，字面量里的 spurious trailing
  //      '%' 会直接让测试编译不过）；
  //   2. 在终止符之后布置哨兵 "ZZZ"，把修复前那次不可控的越界读变成可观测、
  //      不崩溃的行为——这样测试能报出 FAIL，而不是把自己跑挂。
  char fmt[16];
  memset(fmt, 0, sizeof(fmt));
  fmt[0] = '1'; fmt[1] = '0'; fmt[2] = '0'; fmt[3] = '%'; fmt[4] = '\0';
  fmt[5] = 'Z'; fmt[6] = 'Z'; fmt[7] = 'Z'; fmt[8] = '\0';

  char buf[64];
  memset(buf, 0, sizeof(buf));
  int len = snprintf(buf, sizeof(buf), fmt);

  // 修复后：输出 "100%"，扫描停在 fmt[4]，len == 4
  // 修复前：越过 fmt[4] 继续把哨兵当格式串扫描，输出 "100%\0ZZZ"，len == 8
  expect(len == 4, "BUG-01 格式串以 % 结尾不越界扫描");
  expect(strcmp(buf, "100%") == 0, "BUG-01 输出内容正确");
}

// ---------------------------------------------------------------- BUG-02
// 修复前：size_t 无符号，n - 1 回绕成 SIZE_MAX 使守卫恒真，从 out[0] 起一路写。
static void test_bug02_zero_size(void) {
  // buf 开得比格式化结果长得多：即使守卫失效、越界写也仍落在 buf 内部，
  // 测试可以安全地把"到底写没写"检测出来，不会破坏别的数据。
  char buf[32];
  memset(buf, 'X', sizeof(buf));

  // 用 volatile 传 0：否则 GCC 的 -Wformat-truncation（-Wall 自带）会看出
  // 输出必然被截断而报警，配合 -Werror 会让测试编译不过。
  volatile size_t zero = 0;
  int len = snprintf(buf, zero, "hello world");

  bool untouched = true;
  for (size_t i = 0; i < sizeof(buf); i++) {
    if (buf[i] != 'X') { untouched = false; break; }
  }

  // 修复后：一个字节都不写；返回值是"假如缓冲区足够大本该写多少" = 11
  // 修复前：从 buf[0] 起写入 11 个字节
  expect(untouched, "BUG-02 n==0 时一个字节都不写");
  expect(len == 11, "BUG-02 n==0 时仍返回应写长度");
}

// ---------------------------------------------------------------- BUG-03
// 修复前：free_list == NULL 同时表示"未初始化"和"堆已耗尽"，后者发生时会把
// 整个 heap 重新铺成空闲块，把已分配的内存二次发出去。
//
// 抽干堆的办法：用递减的尺寸阶梯，大块快速消耗、失败就折半，直到 8 字节也
// 申请不到。此时空闲链表必然为空——分裂只在剩余 >= 16 字节时发生，所以链上
// 任何块都 >= 16 字节，而 malloc(8) 只需要 16 字节；申请不到即等价于链表空。
// 这样只要约 100 次分配就能触达触发点，不必逐 8 字节地磨。
#define MAX_ALLOC 256   // 上述阶梯的合法分配次数约 100，256 已很宽松
static void *blk[MAX_ALLOC];

static void test_bug03_heap_exhaustion(void) {
  size_t heap_size = (char *)heap.end - (char *)heap.start;
  size_t got = 0;
  int n = 0;

  // 首级块大小取 heap/64（使总次数与堆大小无关），但必须向下取整到 2 的幂，
  // 折半阶梯才能正好落在 8 上。首轮 VM 验证就栽在这里：heap/64 = 2093750 不是
  // 2 的幂，阶梯走成 ... 31 → 15 → 7 而跳过了 8，而 malloc(15) 需要
  // ALIGN(15+8) = 24 字节、malloc(8) 只需 16 字节——残留块为 16~23 字节时前者
  // 失败、后者仍能成功，于是链表尚未抽干循环就退出，探针误报。
  size_t sz = 8;
  while (sz * 2 <= heap_size / 64) sz *= 2;

  while (sz >= 8 && n < MAX_ALLOC) {
    void *p = malloc(sz);
    if (p == NULL) { sz /= 2; continue; }
    blk[n] = p;
    *(volatile uint32_t *)p = (uint32_t)(n + 1);   // 盖戳，用于事后查重叠
    n++;
    got += sz;
  }

  // 次数超过上限，说明分配器在源源不断地发内存——已经在重复分配了
  expect(n < MAX_ALLOC, "BUG-03 分配次数未失控");
  // 发出去的总量不可能超过堆容量
  expect(got <= heap_size, "BUG-03 分配总量不超过堆容量");

  // 关键探针：此刻 free_list 必为 NULL，正是缺陷的触发点。
  // 修复后返回 NULL；修复前重新初始化整个堆，返回的地址与 blk[0] 重叠。
  void *probe = malloc(8);
  expect(probe == NULL, "BUG-03 堆耗尽后返回 NULL 而非二次分配");

  // 独立的旁证：所有戳都还在原位，说明没有任何一块被二次发出去后覆写
  bool stamps_ok = true;
  for (int i = 0; i < n; i++) {
    if (*(volatile uint32_t *)blk[i] != (uint32_t)(i + 1)) { stamps_ok = false; break; }
  }
  expect(stamps_ok, "BUG-03 已分配块未被重复发出");
}

// ---------------------------------------------------------------- BUG-05
static void test_bug05_atoi_sign(void) {
  expect(atoi("-5") == -5,           "BUG-05 atoi 识别负号");
  expect(atoi("+7") == 7,            "BUG-05 atoi 识别正号");
  expect(atoi("\t42") == 42,         "BUG-05 atoi 跳过制表符");
  expect(atoi("  -123") == -123,     "BUG-05 atoi 空白后接负号");
  expect(atoi("42") == 42,           "BUG-05 atoi 无符号情形不受影响");
  expect(atoi("abc") == 0,           "BUG-05 atoi 非数字仍返回 0");
  expect(atoi("- 5") == 0,           "BUG-05 atoi 符号与数字间不许有空格");
}

int main() {
  printf("klib bugfix regression\n");

  test_bug01_trailing_percent();
  test_bug02_zero_size();
  test_bug05_atoi_sign();
  test_bug03_heap_exhaustion();   // 会耗尽堆，放最后

  if (failed == 0) {
    printf("all passed\n");
  } else {
    printf("%d check(s) FAILED\n", failed);
  }
  printf("(BUG-04 需人工确认: 跑 kernels/slider，串口不应出现 SYNC triggered)\n");

  return failed;
}
