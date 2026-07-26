# docs —— 学习资料

这个仓库虽然是一生一芯的原生工程环境，但真正在学的是一套**方法论**：构建系统、编译与
链接、指令集模拟、处理器 RTL 设计、运行时环境、操作系统。`docs/` 因此分成两层——
一层是这个项目怎么做，一层是这类问题在工业界和学术界怎么想。

```
docs/
├── ysyx/     一生一芯 + NJU PA 官方讲义离线副本（原 docs/讲义）
│   ├── PA/       PA0 ~ PA4
│   └── YSYX/     B ~ F 阶段
└── refs/     经典著作、官方规范、学术论文
    ├── README.md    资料索引 + 与 ysyx 各环节的对应关系 + 纸质书单
    ├── fetch.sh     一键抓取脚本
    └── 1-isa-riscv/ 2-arch-cpu/ 3-toolchain-link/ 4-os/ 5-hdl-verif/
```

## 快速上手

```bash
bash docs/refs/fetch.sh          # 抓取全部参考资料
bash docs/refs/fetch.sh toolchain   # 或只抓某一类
```

`refs/` 下的 PDF 不纳入 git（脚本和索引纳入），详见 `refs/README.md` 开头的说明。

## 两层资料怎么配合

遇到问题时的一般顺序：

1. **`ysyx/`** —— 先看讲义要求你做什么、验收标准是什么
2. **`refs/` 里的规范** —— 涉及"到底该是什么行为"时查规范（ISA 手册、ELF、psABI），
   这类问题规范是唯一判据，不要靠猜或靠试
3. **`refs/` 里的经典** —— 涉及"为什么这么设计"时读经典（OSTEP、xv6、CSAPP），
   这类问题讲义通常只给结论不给来龙去脉

`refs/README.md` 里有一张对应表，把 Makefile / NEMU / NPC / AM / nanos-lite 各环节
分别该查哪份材料列了出来。
