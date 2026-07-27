# BUG-02　append_char：`n == 0` 时 `n - 1` 无符号下溢，缓冲区被击穿

| 项 | 值 |
| --- | --- |
| 文件 | `abstract-machine/klib/src/stdio.c` |
| 函数 | `append_char()` |
| 缺陷类型 | 无符号整数下溢 → 越界写（out-of-bounds **write**） |
| 严重度 | 🔴 高——越界**写**比越界读危险一个量级 |
| 引入于 | `0168dce` "device"（PA2 写 klib 时） |
| 发现于 | 2026-07-27 abstract-machine 全量复盘 |

---

## 一、题目

```c
static void append_char(char *out, size_t n, size_t *pos, char c) {
  if (*pos < n - 1) {
    out[*pos] = c;
  }
  (*pos)++;
}
```

这个函数的意图是"缓冲区还有空位就写，没空位就只计数不写"。它在 `n` 取什么值时会写到缓冲区外面？

<details>
<summary>答案</summary>

`n == 0`。而且不是"多写一个字节"，是**从 `out[0]` 开始一路写下去，直到格式化内容耗尽为止**。

</details>

---

## 二、最小复现

```c
char buf[8];
int len = snprintf(buf, 0, "hello world");  // 标准要求：一个字节都不许写
// 实际：buf[0..10] 全被写了，越界 3 字节，且 buf 本不该被碰
```

`snprintf(NULL, 0, fmt, ...)` 更致命——这是 C 里**测量格式化后长度**的标准惯用法：

```c
int need = snprintf(NULL, 0, "%s=%d", key, val);   // 先量长度
char *p = malloc(need + 1);                        // 再按需分配
snprintf(p, need + 1, "%s=%d", key, val);          // 最后真正格式化
```

第一行会往地址 `0` 开始写。在有 MMU 的系统上是段错误，**在 NPC / NEMU 这种没有内存保护的裸机上，地址 0 是一段合法的物理内存**——它会静静地把那里的东西改掉，然后程序在完全无关的地方崩溃。

---

## 三、原理：`size_t` 是无符号数

`n` 的类型是 `size_t`，在 RV32 上是 `unsigned int`（32 位无符号）。

无符号整数**没有负数**。当 `n == 0` 时：

```
n - 1  =  0 - 1
       =  0x00000000 - 0x00000001
       =  0xFFFFFFFF          ← 回绕（wrap around），不是 -1
       =  4294967295 = SIZE_MAX
```

这是 C 标准明确规定的行为（无符号运算按模 2^N 进行，**不是** UB，所以编译器不会警告，`-Wall -Werror` 也拦不住）。

于是判断变成：

```c
if (*pos < 4294967295)     // 对任何现实中的 *pos 都恒真
```

守卫彻底失效，`out[*pos] = c` 无条件执行，`*pos` 每次加一，**一路写下去**。

### 为什么会写成这样

`n - 1` 的本意是"给结尾的 `'\0'` 留一个位置"，这个想法本身是对的。错在**把"留一格"这个减法直接做在了无符号类型上，而没有先保证被减数不为零**。

### 一个佐证：作者其实想到过 n == 0

同一个文件的末尾写着：

```c
if (n > 0) {                       // ← 这里想到了
  if (pos < n) out[pos] = '\0';
  else out[n - 1] = '\0';
}
```

写终止符的地方老老实实判断了 `n > 0`，写正文的地方却漏了。**这说明问题不是"不知道 n 可能为 0"，而是"同一个不变量在两处分别手写，只维护了一处"**——见第六节。

---

## 四、修复

```c
// pos 无论是否真的写入都要自增：vsnprintf 的返回值是"假如缓冲区足够大本该写多少"
static void append_char(char *out, size_t n, size_t *pos, char c) {
  // n == 0 必须单独判断：size_t 是无符号数，n - 1 会回绕成 SIZE_MAX 使判断恒真
  if (n > 0 && *pos < n - 1) {
    out[*pos] = c;
  }
  (*pos)++;
}
```

`&&` 的短路求值保证 `n == 0` 时右边的 `n - 1` 根本不会求值，既修了 bug 也不多花指令。

**注意 `(*pos)++` 必须留在 `if` 外面。** 这不是笔误而是必需的：`vsnprintf` 的返回值语义是"**假如缓冲区足够大**，本应写入的字符数"，而不是"实际写入的字符数"。正是这条语义让上面那个 `snprintf(NULL, 0, ...)` 量长度的惯用法能成立。

### 等价写法的取舍

也可以写成 `if (*pos + 1 < n)`，避开减法。不采用，因为把下溢换成了上溢——`*pos` 接近 `SIZE_MAX` 时 `*pos + 1` 会回绕成 0，虽然现实中到不了，但同类问题只是换了个方向。`n > 0 &&` 的写法把"n 非零"这个前提**显式写了出来**，读代码的人一眼能看到守卫在哪儿。

---

## 五、举一反三

**铁律：`size_t`（以及任何 `unsigned`）参与减法时，先证明被减数 ≥ 减数。**

C 里这类下溢的高频形态：

```c
for (size_t i = 0; i < n - 1; i++)          // n == 0 时循环 40 亿次
for (size_t i = n - 1; i >= 0; i--)         // 恒真，无限循环
if (strlen(s) - 1 > 0)                      // s 为空串时恒真
if (end - start < len)                      // end < start 时恒假
memcpy(dst, src, buf_end - p)               // p 越过 buf_end 时拷贝天文数字
```

已在本次复盘中发现的同类隐患（同文件 `print_string`，尚未修）：

```c
int pad_len = width - len;    // len 是 size_t，width 是 int
```

`width - len` 会把 `width` 提升为 `size_t` 后在无符号域计算，`len > width` 时得到巨大正数，再隐式转回 `int` 才碰巧变成负数。**结果对，但对得靠实现定义行为**（有符号溢出转换在 C99 里是 implementation-defined）。正确写法是 `width - (int)len`。

### 编译器帮不上忙这件事

`-Wall -Werror` 已经开了，为什么没报？因为：

- 无符号回绕是**标准定义的良好行为**，不是 UB，编译器没有理由警告；
- `-Wsign-compare`（有符号/无符号混比）不在 `-Wall` 里，要 `-Wextra` 才开。

👉 **待办**：给 AM 的 CFLAGS 加 `-Wextra`（配合 `-Wno-unused-parameter` 压掉噪声），能静态揪出上面 `print_string` 那一类。记在 `note/todo/` 里。

---

## 六、更深一层：不变量不该手写两遍

`append_char` 和 `vsnprintf` 结尾的收尾代码，本质上在维护**同一个不变量**：「`out` 的可写范围是 `[0, n-1)`，第 `n-1` 格留给 `'\0'`，`n == 0` 时一格都没有」。

这个不变量在代码里被手写了两遍，于是维护了一遍、漏了一遍。这正是复盘报告里提到的 **sink 抽象**要解决的问题——如果输出目标是一个结构体：

```c
typedef struct {
  char  *buf;      // NULL 表示直接 putch
  size_t cap;
  size_t pos;
} sink_t;
```

那么"还能不能写"只在 `sink_put()` 一个地方判断，收尾的 `'\0'` 只在 `sink_finish()` 一个地方写，**不变量就只有一份，不存在"漏改一处"**。

同时它还顺手解决了 `printf` 那个 2048 字节栈缓冲区的问题（`sink.buf == NULL` 时直接 `putch`，零缓冲、无长度上限）。

这项重构没有包含在本次修复里（本次只修"错的"，不动"丑的"），单独记在 `note/todo/klib-stdio-sink重构.md`。

---

**相关**：[BUG-01](./01-vsnprintf-trailing-percent.md)（同文件，格式串越界扫描）
