# BUG-03　malloc：`free_list == NULL` 身兼两职，堆耗尽后把整个堆二次发出去

| 项 | 值 |
| --- | --- |
| 文件 | `abstract-machine/klib/src/stdlib.c` |
| 函数 | `malloc()` |
| 缺陷类型 | 状态编码歧义 → 堆元数据破坏（heap corruption） |
| 严重度 | 🔴 最高——本次复盘里最危险的一个 |
| 引入于 | `240bdc0` "feat: implement malloc/free with first-fit free-list allocator" |
| 发现于 | 2026-07-27 abstract-machine 全量复盘 |

---

## 一、题目

```c
static BlockHeader *free_list = NULL;

void *malloc(size_t size) {
  if (size == 0) return NULL;
  int need = ALIGN((int)size + MHDR_SZ);

  if (free_list == NULL) {                 // ← 看这里
    BlockHeader *init = (BlockHeader *)heap.start;
    int total = (int)((char *)heap.end - (char *)heap.start);
    if (total < need + MHDR_SZ) return NULL;
    init->size = total;
    init->next = NULL;
    free_list = init;
  }

  /* ...first-fit 遍历，找到就摘链返回... */
}
```

这是一个首次适应分配器的惰性初始化。找出它的问题。

<details>
<summary>答案</summary>

`free_list == NULL` 表达了**两件完全不同的事**：

1. 「还没初始化」——第一次调用 `malloc`；
2. 「初始化过了，但空闲块全用光了」——一个完全合法的运行时状态。

代码只处理了第一种，于是第二种发生时，它会**把已经分配给别人的整个堆重新铺成一个空闲块，再发一遍**。

</details>

---

## 二、触发条件与最小复现

`free_list` 变成 `NULL` 的第二条路径，藏在分裂逻辑里：

```c
int remain = cur->size - need;
if (remain >= MHDR_SZ + 8) {      // 剩余不足 16 字节就不分裂，整块给出去
  /* ...分裂，把尾巴插回 free_list... */
}
/* 若不分裂，free_list = cur->next 之后可能就是 NULL 了 */
```

所以只要**最后一个空闲块被整块取走**（申请大小恰好使 `remain < 16`），`free_list` 就回到 `NULL`。下一次 `malloc` 立刻重新初始化。

```c
// 假设 heap 共 1024 字节
void *a = malloc(1000);   // need = ALIGN(1008) = 1008, remain = 16 → 分裂
void *b = malloc(4);      // 从剩下的 16 字节里拿，remain = 0 → 不分裂，free_list = NULL
void *c = malloc(8);      // 💥 free_list == NULL → 重新把整个 heap 铺成空闲块
                          //    c == a！两个指针指向同一块内存
```

`c` 和 `a` 指向同一处。写 `c` 就等于悄悄改掉 `a` 的内容。

---

## 三、原理：为什么这是最阴险的一类 bug

### 3.1 破坏是延迟的、非局部的

分配器返回的指针本身看起来完全正常——非 NULL、地址在堆内、对齐也对。**崩溃不会发生在 `malloc` 里**，而是发生在后来某个读到被改写数据的地方：

- 一个链表节点的 `next` 被别人当 buffer 写了半个字符串进去 → 遍历时跳到野地址；
- 一个字符串被覆盖 → 打印出乱码，看起来像"UART 时序不对"；
- `free()` 时读到的 `blk->size` 是别人的数据 → `insert_free` 里的指针算术算出堆外地址，链表彻底断掉。

**病灶（`malloc`）和症状（任意位置）之间没有任何可见联系。** 在 NPC 上你会先怀疑 CPU、再怀疑 difftest、最后才怀疑 klib——这个顺序会浪费很多天。

### 3.2 它对"堆大小"敏感，因此会诈尸

触发要求"最后一块被整块取走"，这取决于**申请序列**和**堆总大小**的组合。于是：

- 在 NEMU（堆 128MB）上几乎永远不触发；
- 在 NPC（`_heap_start` 到 `PMEM_END`，取决于程序有多大）上，**多链进一个 .o、堆就变小一点，某天就突然触发了**；
- 加一行 `printf` 调试 → 程序变大 → 堆变小 → 症状变了。经典的海森堡 bug。

### 3.3 根因分类：状态编码歧义

抽象地讲，这是**用一个变量的"哨兵值"去编码两种语义**：

| `free_list` 的值 | 想表达 | 实际可能是 |
| --- | --- | --- |
| 非 NULL | 有空闲块 | ✅ 无歧义 |
| NULL | 还没初始化 | ❌ **也可能是"堆已耗尽"** |

哨兵值编码状态本身不是错，错在**选了一个在正常运行中也会自然出现的值当哨兵**。同类反例遍地都是：

- 用 `-1` 表示"未设置"，而 `-1` 恰好也是合法数据；
- 用空字符串表示"未配置"，而空字符串是合法配置；
- 用 `0` 表示"无效句柄"，而 fd 0 是 stdin。

---

## 四、修复

用一个**独立的**布尔量表达初始化状态，让两个语义各占一个变量：

```c
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

void *malloc(size_t size) {
  if (size == 0) return NULL;
  int need = ALIGN((int)size + MHDR_SZ);

  if (!heap_inited) {
    heap_inited = true;
    heap_init();
  }

  /* ...first-fit 遍历不变... */
}
```

三个改动点，每个都有理由：

1. **`heap_inited` 独立成变量。** 核心修复。此后 `free_list == NULL` 只剩一个含义：没有空闲块，`malloc` 应当返回 NULL。

2. **`heap_init()` 拆成函数，且不再依赖 `need`。** 原来的 `if (total < need + MHDR_SZ) return NULL;` 把"堆够不够大"和"这次申请多大"耦合在了一起——同样是初始化，会因为第一次申请的大小不同而产生不同结果。拆开后 `heap_init` 只关心堆本身，「这次申请能不能满足」交给下面的 first-fit 循环自然判断（找不到就返回 NULL）。**一个函数只回答一个问题。**

3. **先置 `heap_inited = true` 再调用 `heap_init()`。** 这样即使堆小到 `heap_init` 直接返回（`free_list` 仍为 NULL），也不会每次 `malloc` 都重试一遍初始化。

---

## 五、怎么测它（比修它更难）

这个缺陷的触发点很刁钻：必须让 `free_list` 恰好变成 `NULL`，而堆有 128MB。回归测试见
`am-kernels/tests/cpu-tests/tests/klib-bugfix.c`，其中的推理值得单独记下来。

### 关键不变量

> **`malloc(8)` 失败 ⟺ `free_list == NULL`**

证明：分裂只在 `remain >= MHDR_SZ + 8`（即 16 字节）时发生，分裂出的块 `size = remain >= 16`；
初始块更是远大于 16。故**空闲链上任何块都 ≥ 16 字节**。而 `malloc(8)` 的
`need = ALIGN(8 + 8) = 16`，只要链上还有任何一块就一定能满足。所以它失败当且仅当链表为空。

有了这条，就不必真的去猜"申请多大才能把最后一块整取走"——只要 `malloc(8)` 开始失败，
就确知已经站在触发点上，此时再探一次 `malloc(8)`：修复后返回 `NULL`，修复前会重新
初始化整个堆并返回与首块重叠的地址。

### 怎么快速抽干 128MB

逐 8 字节地磨要 1600 万次，仿真上不可接受。用**递减的尺寸阶梯**：首级取 `heap/64`，
失败就折半，直到 8。第一级约 64 次吃掉绝大部分，之后每级至多一两次（因为上一级失败
意味着残留已小于上一级尺寸）。总计约 90 次分配即可触达触发点。

### ⚠️ 首轮验证栽的坑：阶梯必须落在 8 上

首版测试写的是 `size_t sz = heap_size / 64;`。`128MB / 64 = 2093750`，**不是 2 的幂**，
折半走成 `… → 31 → 15 → 7` 而**跳过了 8**：

- `malloc(15)` 需要 `ALIGN(15 + 8) = 24` 字节
- `malloc(8)` 只需要 `16` 字节
- 残留块恰为 16~23 字节时，前者失败、后者仍能成功

于是链表尚未抽干，循环就因 `sz < 8` 退出了，探针拿到非 NULL → **误报**。

修法是把首级向下取整到 2 的幂：

```c
size_t sz = 8;
while (sz * 2 <= heap_size / 64) sz *= 2;
```

**教训**：上面那条不变量是对的，但它有个隐含前提——"阶梯真的会走到 8"。
证明了不变量却没检查前提是否成立，就是这次误报的全部原因。**用到一条 ⟺ 时，
要同时确认自己真的处在它的适用条件上。**

### 设计上的另一个考虑：让判据互相独立

测试里同时下了四条判据：分配次数上限、发出总量不超堆容量、探针返回 NULL、逐块戳记
未被覆写。首轮验证正是靠"三条 OK、只有探针 FAIL"这个**不一致的组合**，一眼判定问题
出在测试而非被测代码——如果只写探针一条，就会误以为修复失败而去改本来正确的代码。

> 多下几条彼此独立的判据，代价很低，但它能把"哪儿错了"从猜测变成推理。

---

## 六、举一反三（缺陷本身）

自查清单——写任何带惰性初始化的模块时问自己：

- [ ] 我用来判断"是否已初始化"的那个值，**在正常运行中会不会自然地再次出现**？
- [ ] 如果会，它出现时代码的行为是什么？（通常是"重新初始化"，通常是灾难）
- [ ] 这个状态需要几个 bit？如果是 2 个独立的是非题，就该有 2 个变量。

本仓库内的同类高危模式（后续复盘时重点看）：

- `nemu/src/device/` 里各设备的 `init` 标志；
- `npc/csrc/` 的 difftest 初始化——`ref_so_handle == NULL` 是不是也兼职了？
- 任何 `static T *cache = NULL;` 形式的单例缓存。

### 一个更强的做法

如果这个分配器将来要认真用，比 `bool` 更好的是**让"未初始化"从状态空间里消失**：在 `_start` 或 `main` 之前的 CRT 初始化里显式调用一次 `heap_init()`，`malloc` 里连判断都不要。**能在构造期解决的，不要留到运行期判断。**

没有现在就这么做，是因为 AM 的启动流程（`start.S` → `_trm_init`）跨平台，改动面比这次修复大得多，属于重构而非修 bug。记在 `note/todo/`。

---

## 七、遗留（本次未处理，但要知道它们存在）

这个分配器还有几处已知薄弱点，本次刻意**没有**动（只修"错的"，不动"可改进的"），但列在这里以免下次踩到时以为是新 bug：

1. **`heap.start` 未对齐。** `ALIGN` 是 8 字节，但代码直接把 `heap.start` 当作第一个 `BlockHeader` 的地址，没有先向上对齐。链接脚本目前给出的 `_heap_start` 是对齐的，所以现在没事——**属于"靠外部保证"而非"自己保证"**。RV32 上未对齐访问会触发 misaligned exception。

2. **用 `size` 的符号位表示"已分配"。** `cur->size = -cur->size;` 是个省空间的技巧，但让 `size` 字段身兼两职（又是长度又是标志），可读性差，而且和 BUG-03 本身是同一类"一个变量两种语义"的思路。更清晰的做法是用 `size` 的最低位当标志（因为 8 字节对齐，低 3 位恒为 0，本来就是浪费的）。

3. **`free()` 没有有效性校验。** 只检查了 `blk->size > 0`（防重复 free），但对野指针、对"指向堆中间的指针"毫无防御。加一个 magic 字段可以在 debug 构建下抓到大部分误用。

4. **`insert_free` 只合并直接相邻的前后各一块。** 正确但不彻底，长期运行会有碎片。对 PA 的负载来说够用。

5. **`int size` 限制堆 < 2GB。** 在 NPC/NEMU（128MB）上无所谓，但如果 `__NATIVE_USE_KLIB__` 在 native 上启用，堆可能更大。

6. **没有 `calloc` / `realloc`。** `klib.h` 里也没声明。navy-apps 的某些库可能需要，等报错再补。

---

**相关**：[BUG-02](./02-append-char-size-underflow.md)（同属"同一个不变量维护了两遍"的家族）
