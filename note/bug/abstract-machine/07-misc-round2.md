# BUG-07　第二轮零散修复合辑

第二轮复盘中确认、但单独成篇不划算的项目。每条按「是什么 → 为什么错 → 怎么改」压缩记录。
主线的两条（`GPR1` 抽象被绕开、双平台漂移）见 [BUG-06](./06-cte-gpr1-abstraction-bypassed.md)。

---

## 一、`halt` 的内联汇编没声明破坏 a0

**位置**：`am/src/riscv/npc/trm.c`　**类型**：靠运气对

```c
void halt(int code) {
  asm volatile ("mv a0, %0; ebreak" : : "r"(code));   // ❌
  while (1);
}
```

### 为什么错

GCC 的内联汇编语法是 `asm(模板 : 输出 : 输入 : 破坏列表)`。**编译器只知道你在破坏列表里告诉它的东西**——它不会去读汇编模板猜你改了哪些寄存器。

这里的模板明明写了 `mv a0, ...`（改写 a0），破坏列表却是空的。于是编译器仍然认为 a0 在这条语句前后保持不变，可能：

- 把某个还要用的值一直存在 a0 里，指望语句执行完还在；
- 把 `code` 本身分配到 a0，然后生成 `mv a0, a0` 这种自我覆盖。

现在没出事，纯粹因为 `halt` 永不返回、后面只有 `while(1)`——**没有"之后"，所以没人发现 a0 被改了**。

### 怎么改

```c
void halt(int code) {
  // 用 register 变量把 code 直接绑定到 a0，让"a0 承载退出码"成为编译器知道的事实
  register int a0 asm("a0") = code;
  asm volatile ("ebreak" : : "r"(a0));
  while (1);
}
```

这比补一个 `: "a0"` 破坏列表更好：破坏列表只是告诉编译器"这个寄存器我用坏了"，而 `register ... asm("a0")` 是告诉它"**这个值就该放在 a0**"，语义更准确，也不需要额外的 `mv`。

> 📌 **原则：内联汇编里改动的每一个寄存器、内存，都必须让编译器知道。** 编译器不读你的汇编。

---

## 二、`print_string` 的宽度计算走了无符号回绕

**位置**：`klib/src/stdio.c`　**类型**：靠运气对

```c
size_t len = strlen(s);
int pad_len = width - len;      // ❌ width 被提升为 size_t
```

`len` 是 `size_t`（无符号），按 C 的**通常算术转换**，`width`（`int`）会被提升为 `size_t`，减法在无符号域进行。当 `len > width` 时结果是个天文数字，再隐式转回 `int` 才碰巧变成负数。

结果是对的，但**对得靠实现定义行为**（有符号溢出的转换在 C99 里是 implementation-defined）。

```c
int pad_len = width - (int)strlen(s);   // ✅ 显式转换，全程在有符号域
```

同根问题见 [BUG-02](./02-append-char-size-underflow.md)——那一条已经因此写坏过一次缓冲区。

---

## 三、`vsnprintf` 的格式符缺口

**位置**：`klib/src/stdio.c`　**类型**：功能不完整

补齐了下列转换，之前它们会落到 `default` 分支被**原样打印出来**（例如 `%u` 打出 "%u"），是一种静默的错误输出：

| 新增 | 说明 |
| --- | --- |
| `%u` | 无符号十进制。**最该补的一个**——它长得太像 `%d`，写错零提示 |
| `%X` | 大写十六进制（目前与 `%x` 同为小写输出，见遗留） |
| `%ld` `%lu` `%lx` | `long` |
| `%lld` 等 | `long long`，在 RV32 上是真正的 64 位 |
| `%zu` | `size_t` |
| `%hd` `%hhd` | 吃掉修饰符即可——实参经默认参数提升后本就是 `int` |
| `%-` | 左对齐标志 |

同时修正了两处已有行为：

- **`%p` 现在带 `0x` 前缀**，且按 `void *` 取参。之前按 `unsigned int` 取，在 64 位平台上会截断指针；
- **`%d` 对 `INT_MIN` 不再依赖有符号取反**。原来写 `uval = -val`，`val` 为最小值时取反溢出（有符号溢出是未定义行为）。改成先转无符号再取反：`neg ? -(unsigned long long)v : (unsigned long long)v`。

### 顺带整理的结构

原来 `print_num` 有 `width` / `pad` 两个平行参数，加了左对齐后会变成三个、四个。改成传一个 `FmtSpec` 结构体：

```c
typedef struct { int width; char pad; bool left; } FmtSpec;
```

以及把"按什么宽度从 `va_list` 取参"抽成 `fetch_signed` / `fetch_unsigned`，避免每个转换符里重复一遍 `switch (len)`。

**填充顺序也是一个易错点**，值得记一笔：

```
%5d   →  "   42"    空格填充在符号之前
%05d  →  "-0042"    零填充在符号之后
                    ——写反了会得到 "000-42" 这种第三种错误形态
```

---

## 四、`atoi` 改为 `strtol` 的薄包装

**位置**：`klib/src/stdlib.c`　**类型**：结构性修复

上一轮修 [BUG-05](./05-atoi-missing-sign.md) 时手写了符号处理，当时留下两个遗留：不检测溢出、`INT_MIN` 无法正确解析（因为在正数域累加，中间值要先达到 2147483648）。

这一轮实现了 `strtol`，`atoi` 随之退化成一行：

```c
int atoi(const char *nptr) {
  return (int)strtol(nptr, NULL, 10);
}
```

**这正是 C 标准对 `atoi` 的定义**：「除出错时的行为外，等价于 `strtol(nptr, NULL, 10)`」。回头看，上一轮"手写一份独立的累加循环"本身就是偏离——**当标准告诉你 A 等价于 B 时，就该让 A 调用 B，而不是把 B 再实现一遍**。这和 [BUG-06](./06-cte-gpr1-abstraction-bypassed.md) 的 `GPR1` 是同一个教训。

`strtol` 的要点：

- 支持 `base` 为 2~36，以及 `base = 0` 时按前缀自动判断（`0x`→16，前导 `0`→8，否则 10）；
- 在**无符号域**累加，容量比 `long` 大一档，因此能正确表示 `-LONG_MIN`；
- 溢出检测用 `acc > (limit - d) / base`——先除后比，避免"先乘出溢出值再检查"的经典错误；
- `endptr` 在一个有效数字都没读到时回填**原始** `nptr`（连符号和前缀都不算消耗），这是标准规定的。

⚠️ **与标准的唯一偏离**：溢出时钳到 `LONG_MAX`/`LONG_MIN` 但**不设置 `errno`**——klib 没有 `errno`。因此调用方无法区分"真的等于 `LONG_MAX`"和"溢出了"。已写在函数注释里。

---

## 五、新增 `calloc` / `realloc`

**位置**：`klib/src/stdlib.c`　**类型**：补齐缺口

两个都是薄封装，但各有一个必须写对的地方：

**`calloc` 的乘法溢出**

```c
if (nmemb > (size_t)-1 / size) return NULL;
```

`calloc(nmemb, size)` 要分配 `nmemb * size` 字节。如果不检查，这个乘法会**无符号回绕**成一个很小的数 → 分配到一小块内存 → 调用方按原始尺寸写入 → 越界写穿堆。这是 CVE 里的常客。检查方式是"先除后比"，同样避免制造出溢出值再判断。

**`realloc` 失败时不能先释放原块**

```c
void *p = malloc(size);
if (p == NULL) return NULL;    // 原块必须保持有效
memcpy(p, ptr, old);
free(ptr);
```

标准规定 `realloc` 失败时返回 NULL 且**原块不变**。若写成"先 free 再 malloc"，分配失败时调用方手里的指针就成了悬垂指针——而调用方按标准是有权继续用它的。

"旧块有多大"从块头拿：`|blk->size| - MHDR_SZ`。这也是块头设计的额外好处之一。

⚠️ **偏离**：`realloc(ptr, 0)` 这里实现为"释放并返回 NULL"。C99 允许，但 **C17 起改为未定义行为**，已在注释里注明，调用方不要依赖。

---

## 六、卫生与规范

| 项 | 位置 | 改动 |
| --- | --- | --- |
| `Context` 的 union 无注释 | `am/include/arch/riscv.h` | 补注释说明 `pdir` 借用 `gpr[0]` 槽位成立的前提：x0 恒零、`trap.S` 的寄存器列表从 `f(1)` 开始 |
| 相对路径逃出 include 目录 | `npc/include/npc.h` | `#include "../../riscv.h"` → `<riscv/riscv.h>`（`am/Makefile` 已把 `am/src` 放进 `INC_PATH`） |
| `gdb` 目标不 cp `.elf` | `scripts/platform/npc.mk` | 补上——`run` 有而 `gdb` 没有，可 `gdb` 才是更需要符号的那个 |
| 4 空格缩进 | `npc/timer.c` | 改回 AM 全仓的 2 空格 |
| 缺行尾换行 3 处、行尾空格若干 | 本轮涉及的文件 | 清理 |
| 多余空行 | `scripts/minirv-npc.mk` | 去掉 |

### ⚠️ 这里犯了个错，值得记下来

清理行尾空格时图省事，对 `git ls-files abstract-machine` 的**全部** `.c/.h/.S/.mk` 跑了一遍 `sed`，结果一次改动了 **130 个文件**——其中绝大多数是 x86 / MIPS / LoongArch / native / spike / tools 下与本次工作毫无关系的上游文件。

这正是第一轮复盘里批评过的第 13 条「注释翻译混进功能 commit」的同一种错误，只是这次犯的人是我自己。**批量格式化必须限定在本次真正改动的文件范围内**，否则：

- diff 里 95% 是噪声，review 变得不可能；
- 与上游的差异凭空扩大，将来 rebase 到新版 ics 会全文冲突；
- 真正的改动被淹没。

已全部回退，最终改动集为 19 改 + 4 删 + 2 新。

**副产物一条**：回退时写的循环没生效——

```bash
git diff --name-only ... | while read f; do git checkout -- "$f"; done   # ❌ 只还原了第一个
```

`git checkout` 会读 stdin，把管道里剩下的文件名全吃光了。这是 shell 的经典坑，修法是 `git checkout -- "$f" </dev/null` 或改用进程替换 `< <(...)`。

**副产物二条**：`git status` 一度显示 120 个文件被修改，而 `git diff --name-only` 只有 19 个。原因是工作区是 CRLF、索引是 LF，`.gitattributes` 的 `text=auto eol=lf` 会在比较时归一化，**`git diff` 看的是归一化后的内容，`git status` 报的是 stat 脏标记**。`git update-index --refresh` 之后两者一致。判断"到底改了什么"要以 `git diff` 为准。

### 同一个根因，第三轮又犯了一次，而且更严重

收敛注释风格时，为了清掉源码里混进来的 markdown 强调号，跑了：

```bash
sed -i 's/\*\*//g' <一批 .c/.h/.S>
```

结果把 **C 语言的二级指针一起吃掉了**：

```c
static LenMod parse_spec(const char **fmt, ...)   →   (const char fmt, ...)
BlockHeader **pp = &free_list;                    →   BlockHeader pp = ...
long strtol(const char *nptr, char **endptr, ...) →   (..., char endptr, ...)
```

三处全是编译错误级别的破坏。**比第一次严重**：上一次只是改动面过大（噪声），这次是**语义损坏**，而且损坏的形态很像手误——如果没被发现，排查时极难联想到是批量替换干的。

两次的根因完全相同：**用纯文本工具批量改代码，而匹配模式没有被限定在"只可能出现在注释里"的范围内**。`**` 在 markdown 里是强调，在 C 里是二级指针；`sed` 不区分。

补上的防线（这次真正起作用的）：

```bash
# 除有意重构的文件外，其余文件"剥掉注释与空行后应与 HEAD 逐字相同"
strip() { grep -vE '^\s*(//|/\*|\*/|\*[^/])' | grep -vE '^\s*$'; }
diff <(git show HEAD:$f | strip) <(strip < $f)
```

11 个文件跑一遍，立刻定位到 `stdlib.c` 有代码行差异；`stdio.c` 因为确实抽了 `parse_spec` 需要人工核对，逐一比对了签名、`*fmt = p` 回写、调用点三处。

> **规矩：批量修改代码时，必须有一个"预期不变的集合"，并在事后机械验证它确实没变。**
> 只靠"我改的是注释"这个意图是不够的——工具不知道你的意图。

---

## 七、本轮未做（连同理由）

- **klib/stdio 的 sink 抽象**：`printf` 仍是"先格式化进 2048 字节栈缓冲区再逐字符 putch"，代价是重栈帧 + 超长静默截断 + 格式化引擎与输出目标耦合。这是重构而非修 bug，且改动面覆盖全部五个入口函数，单独排期。
- **`gpu.c`/`input.c`/`timer.c` 的合并**：理由见 [BUG-06 第五节](./06-cte-gpr1-abstraction-bypassed.md)，已用 diff 检查兜底。
- **把那条 diff 检查接进 `make`**：目前要人工跑。
- **CFLAGS 加 `-Wextra` / `-nostdinc`**：前者能静态抓出本文第二条那类符号混用，后者能让"引错头文件"变成编译错误。会引出一批既有告警，单独处理。
- **`%X` 仍输出小写**：`print_num` 的数字表是写死的小写。补一个 upper 参数即可，但目前无调用方。
- **malloc 的其余弱点**：`heap.start` 未对齐、用 `size` 符号位当已分配标志、`free` 无有效性校验。见 [BUG-03 第七节](./03-malloc-freelist-null-double-meaning.md)。
