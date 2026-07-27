// AM / klib 缺陷回归测试（临时，验证通过后删除）
//
// 覆盖 2026-07-27 第二轮修复中可自动断言的全部项目，详见
// note/bug/abstract-machine/。上一轮的四项（BUG-01/02/03/05）一并保留为防回归。
//
// 运行：
//   cd am-kernels/tests/cpu-tests
//   make run ARCH=riscv32-nemu ALL=klib-bugfix
//
// 无法在此断言、需另行确认的：
//   BUG-04  GPU 热路径调试 printf  → 跑 kernels/slider 看串口与帧率
//   BUG-06  GPR1 在 RV32E 下的越界 → make run ARCH=riscv32e-nemu ALL=klib-bugfix
//           （本文件里的 yield 测试在该架构下才真正检验到那条修复）

#include "trap.h"

static int failed = 0;

__attribute__((noinline))
static void expect(bool cond, const char *what) {
  printf(cond ? "  [ OK ] %s\n" : "  [FAIL] %s\n", what);
  if (!cond) failed++;
}

static char buf[256];

// ============================================================ stdio：格式化
static void test_stdio(void) {
  // ---- BUG-01：格式串以单个 '%' 结尾不得越界扫描 ----
  // 格式串放进栈数组而非字面量：一来避开 -Wformat（配合 -Werror 会编译不过），
  // 二来在终止符后布置哨兵 "ZZZ"，把越界读变成可观测且不崩溃的行为
  char fmt[16];
  memset(fmt, 0, sizeof(fmt));
  fmt[0] = '1'; fmt[1] = '0'; fmt[2] = '0'; fmt[3] = '%'; fmt[4] = '\0';
  fmt[5] = 'Z'; fmt[6] = 'Z'; fmt[7] = 'Z'; fmt[8] = '\0';
  int len = snprintf(buf, sizeof(buf), fmt);
  expect(len == 4 && strcmp(buf, "100%") == 0, "BUG-01 格式串以 % 结尾不越界扫描");

  // ---- BUG-02：n == 0 时一个字节都不写，返回值仍是"本该写多少" ----
  char small[32];
  memset(small, 'X', sizeof(small));
  volatile size_t zero = 0;   // 经 volatile 传入，否则 -Wformat-truncation 会报警
  len = snprintf(small, zero, "hello world");
  bool untouched = true;
  for (size_t i = 0; i < sizeof(small); i++) if (small[i] != 'X') untouched = false;
  expect(untouched && len == 11, "BUG-02 n==0 时不写缓冲区且返回应写长度");

  // ---- 基本转换符不回归 ----
  sprintf(buf, "%d|%s|%c|%%", -42, "ab", 'Z');
  expect(strcmp(buf, "-42|ab|Z|%") == 0, "stdio 基本转换符 %d %s %c %%");

  // ---- 新增：%u ----
  sprintf(buf, "%u", 4294967295u);
  expect(strcmp(buf, "4294967295") == 0, "新增 %u 无符号十进制");
  sprintf(buf, "%u", 0u);
  expect(strcmp(buf, "0") == 0, "新增 %u 零值");

  // ---- 新增：%x / %X ----
  sprintf(buf, "%x", 0xdeadbeefu);
  expect(strcmp(buf, "deadbeef") == 0, "%x 十六进制");

  // ---- 新增：%p 带 0x 前缀 ----
  sprintf(buf, "%p", (void *)0x1234);
  expect(strcmp(buf, "0x1234") == 0, "新增 %p 带 0x 前缀");

  // ---- 新增：长度修饰 ----
  sprintf(buf, "%ld", (long)-123456);
  expect(strcmp(buf, "-123456") == 0, "新增 %ld");
  sprintf(buf, "%lld", (long long)-8589934592LL);   // 超出 32 位
  expect(strcmp(buf, "-8589934592") == 0, "新增 %lld 支持 64 位");
  sprintf(buf, "%zu", (size_t)4096);
  expect(strcmp(buf, "4096") == 0, "新增 %zu");

  // ---- 宽度与填充 ----
  sprintf(buf, "[%5d]", 42);
  expect(strcmp(buf, "[   42]") == 0, "宽度 右对齐空格填充");
  sprintf(buf, "[%05d]", 42);
  expect(strcmp(buf, "[00042]") == 0, "宽度 零填充");
  sprintf(buf, "[%05d]", -42);
  expect(strcmp(buf, "[-0042]") == 0, "零填充时负号在前而非 000-42");
  sprintf(buf, "[%5s]", "ab");
  expect(strcmp(buf, "[   ab]") == 0, "字符串宽度 右对齐");

  // ---- 新增：'-' 左对齐 ----
  sprintf(buf, "[%-5d]", 42);
  expect(strcmp(buf, "[42   ]") == 0, "新增 %- 左对齐 整数");
  sprintf(buf, "[%-5s]", "ab");
  expect(strcmp(buf, "[ab   ]") == 0, "新增 %- 左对齐 字符串");
  sprintf(buf, "[%-05d]", 42);
  expect(strcmp(buf, "[42   ]") == 0, "左对齐时忽略 0 标志");

  // ---- 边界：INT_MIN 不因取反溢出而出错 ----
  sprintf(buf, "%d", (int)0x80000000);
  expect(strcmp(buf, "-2147483648") == 0, "INT_MIN 格式化正确");

  // ---- 截断行为 ----
  char tiny[6];
  memset(tiny, 'X', sizeof(tiny));
  len = snprintf(tiny, sizeof(tiny), "abcdefgh");
  expect(len == 8 && strcmp(tiny, "abcde") == 0, "截断：写 n-1 字符并补 \\0，返回全长");

  // ---- %s 传 NULL 不崩 ----
  sprintf(buf, "%s", (char *)NULL);
  expect(strcmp(buf, "(null)") == 0, "%s 传 NULL 输出 (null)");
}

// ============================================================ stdlib：字符串转数
static void test_strtol(void) {
  // ---- BUG-05：符号与空白 ----
  expect(atoi("-5") == -5,       "BUG-05 atoi 识别负号");
  expect(atoi("+7") == 7,        "BUG-05 atoi 识别正号");
  expect(atoi("\t42") == 42,     "BUG-05 atoi 跳过制表符");
  expect(atoi("  -123") == -123, "BUG-05 atoi 空白后接负号");
  expect(atoi("abc") == 0,       "BUG-05 atoi 非数字返回 0");
  expect(atoi("- 5") == 0,       "BUG-05 atoi 符号与数字间不许有空格");
  expect(atoi("12abc") == 12,    "atoi 遇非数字停止");

  // ---- 新增：atoi 改为 strtol 薄包装后，INT_MIN 可正确解析 ----
  expect(atoi("-2147483648") == (int)0x80000000, "新增 atoi 正确解析 INT_MIN");

  // ---- 新增：strtol 的进制 ----
  expect(strtol("ff", NULL, 16) == 255,      "新增 strtol base=16");
  expect(strtol("0x1A", NULL, 16) == 26,     "新增 strtol base=16 接受 0x 前缀");
  expect(strtol("777", NULL, 8) == 511,      "新增 strtol base=8");
  expect(strtol("1011", NULL, 2) == 11,      "新增 strtol base=2");
  expect(strtol("0x10", NULL, 0) == 16,      "新增 strtol base=0 按 0x 判为十六进制");
  expect(strtol("010", NULL, 0) == 8,        "新增 strtol base=0 按前导 0 判为八进制");
  expect(strtol("10", NULL, 0) == 10,        "新增 strtol base=0 默认十进制");

  // ---- 新增：endptr ----
  const char *s = "  42abc";
  char *end = NULL;
  long v = strtol(s, &end, 10);
  expect(v == 42 && end == s + 4, "新增 strtol endptr 指向停止位置");

  const char *bad = "xyz";
  end = NULL;
  v = strtol(bad, &end, 10);
  expect(v == 0 && end == bad, "新增 strtol 无有效数字时 endptr 回到起点");

  // ---- 新增：溢出钳位 ----
  expect(strtol("99999999999999999999", NULL, 10) == __LONG_MAX__,
         "新增 strtol 正溢出钳到 LONG_MAX");
  expect(strtol("-99999999999999999999", NULL, 10) == (-__LONG_MAX__ - 1L),
         "新增 strtol 负溢出钳到 LONG_MIN");
}

// ============================================================ stdlib：内存分配
#define MAX_ALLOC 256
static void *blk[MAX_ALLOC];

static void test_alloc(void) {
  // ---- 新增：calloc 清零 ----
  int *z = (int *)calloc(16, sizeof(int));
  bool zeroed = (z != NULL);
  if (z) for (int i = 0; i < 16; i++) if (z[i] != 0) zeroed = false;
  expect(zeroed, "新增 calloc 分配并清零");

  // ---- 新增：calloc 的乘法溢出必须被拦下 ----
  expect(calloc((size_t)-1 / 2, 4) == NULL, "新增 calloc 拦下 nmemb*size 溢出");

  // ---- 新增：realloc 保留原内容 ----
  char *p = (char *)malloc(16);
  expect(p != NULL, "malloc 基本分配");
  if (p) {
    strcpy(p, "hello");
    char *q = (char *)realloc(p, 128);
    expect(q != NULL && strcmp(q, "hello") == 0, "新增 realloc 扩容后内容保留");
    if (q) free(q);
  }
  if (z) free(z);

  // ---- 新增：realloc(NULL, n) 等价于 malloc ----
  char *r = (char *)realloc(NULL, 32);
  expect(r != NULL, "新增 realloc(NULL, n) 等价 malloc");
  if (r) free(r);

  // ---- BUG-03：堆耗尽后不得二次分配（放最后，会把堆抽干） ----
  size_t heap_size = (char *)heap.end - (char *)heap.start;
  size_t got = 0;
  int n = 0;

  // 首级块大小取 heap/64，但必须向下取整到 2 的幂，折半阶梯才能正好落在 8 上；
  // 首轮验证就栽在这里（heap/64 不是 2 的幂 → 阶梯跳过 8 → 链表没抽干 → 误报）
  size_t sz = 8;
  while (sz * 2 <= heap_size / 64) sz *= 2;

  while (sz >= 8 && n < MAX_ALLOC) {
    void *b = malloc(sz);
    if (b == NULL) { sz /= 2; continue; }
    blk[n] = b;
    *(volatile uint32_t *)b = (uint32_t)(n + 1);   // 盖戳，事后查是否被重复发出
    n++;
    got += sz;
  }

  expect(n < MAX_ALLOC,      "BUG-03 分配次数未失控");
  expect(got <= heap_size,   "BUG-03 分配总量不超过堆容量");

  // 此刻 free_list 必为 NULL（malloc(8) 失败 ⟺ 链表空），正是缺陷触发点
  expect(malloc(8) == NULL,  "BUG-03 堆耗尽后返回 NULL 而非二次分配");

  bool stamps_ok = true;
  for (int i = 0; i < n; i++) {
    if (*(volatile uint32_t *)blk[i] != (uint32_t)(i + 1)) stamps_ok = false;
  }
  expect(stamps_ok, "BUG-03 已分配块未被重复发出");
}

// ============================================================ CTE：yield
static volatile int yield_count = 0;

static Context *ev_handler(Event e, Context *c) {
  if (e.event == EVENT_YIELD) yield_count++;
  return c;
}

// BUG-06：__am_irq_handle 曾硬编码 gpr[17]（a7）。在 RV32E 下 NR_REGS 只有 16，
// gpr[17] 越过数组读到 mstatus，于是 yield 被误判成 EVENT_SYSCALL。
// 改用 arch/riscv.h 提供的 GPR1 抽象后，两种 ABI 都正确。
// ⚠️ 本用例在 riscv32-nemu 上恒过；真正检验 BUG-06 要跑 ARCH=riscv32e-nemu。
static void test_yield(void) {
  cte_init(ev_handler);
  yield();
  yield();
  yield();
  expect(yield_count == 3, "BUG-06 yield 被识别为 EVENT_YIELD（RV32E 下才是关键）");
}

int main() {
  printf("AM/klib regression\n");

  test_stdio();
  test_strtol();
  test_yield();
  test_alloc();     // 会耗尽堆，必须放最后

  if (failed == 0) printf("all passed\n");
  else             printf("%d check(s) FAILED\n", failed);
  printf("(BUG-04 需人工确认: 跑 kernels/slider，串口不应出现 SYNC triggered)\n");

  return failed;
}
