# B2 SoC计算机系统

> **所属阶段**: B阶段（SoC阶段）
> **原始来源**: [https://ysyx.oscc.cc/docs/2407/b/2.html](https://ysyx.oscc.cc/docs/2407/b/2.html)
> **爬取时间**: 2026-03-27

---

# B2 SoC计算机系统

#### 总线讲义更新

我们在2023年11月29日在总线部分的讲义中追加了UART和CLINT的练习, 完成它们有利于接下来SoC的接入.

实现总线之后, 我们就可以将NPC接入到"一生一芯"的SoC环境中, 为流片做好准备! SoC是System On Chip的缩写, 这意味着SoC不仅仅只包含一个处理器, 还有诸多的外围设备, 以及连接处理器和外围设备之间的总线. 在这里, 我们把存储器也看成一种广义的设备, 毕竟对于SoC来说, 存储器和其他狭义的设备没有区别, 都是一段可以访问的地址空间.

## ysyxSoC

我们提供一个可以在verilator上运行的SoC环境, 称为ysyxSoC. 我们提前让大家接入ysyxSoC, 一方面是为了让大家学习其中的细节, 另一方面也是尽早在SoC环境中测试你的NPC, 从而帮助你缩短从完成流片考核到提交代码之间的时间. 当然, 在接入ysyxSoC后你还需要完成一些优化工作, 才能达成B阶段的流片指标.

### ysyxSoC介绍

我们先给出ysyxSoC包含的外围设备和相应的地址空间.

| 设备 | 地址空间 |
| --- | --- |
| CLINT | `0x0200_0000~0x0200_ffff` |
| SRAM | `0x0f00_0000~0x0fff_ffff` |
| UART16550 | `0x1000_0000~0x1000_0fff` |
| SPI master | `0x1000_1000~0x1000_1fff` |
| GPIO | `0x1000_2000~0x1000_200f` |
| PS2 | `0x1001_1000~0x1001_1007` |
| MROM | `0x2000_0000~0x2000_0fff` |
| VGA | `0x2100_0000~0x211f_ffff` |
| Flash | `0x3000_0000~0x3fff_ffff` |
| ChipLink MMIO | `0x4000_0000~0x7fff_ffff` |
| PSRAM | `0x8000_0000~0x9fff_ffff` |
| SDRAM | `0xa000_0000~0xbfff_ffff` |
| ChipLink MEM | `0xc000_0000~0xffff_ffff` |
| Reserved | 其他 |

图中除了AXI以外, 还有[APB](), [wishbone]()和[SPI]()这些总线. 不过这些总线都比AXI简单, 甚至比AXI4-Lite还简单. 你已经了解AXI4-Lite了, 因此学习这些总线协议也并不难, 需要时可查阅相关手册.

#### 一些设备和地址空间在将来可能会产生变化

为了获得更好的展示效果, “一生一芯”项目组正在重新设计SoC, 一些设备和地址空间可能会在将来发生变化, 最终的设备地址空间分配情况以流片版本为准. 不过这并不影响目前的学习, 你可以安全地忽略这一情况.

#### 获取ysyxSoC的代码

你需要克隆[ysyxSoC]()项目:

    cd ysyx-workbench
    git clone git@github.com:OSCPU/ysyxSoC.git
    
接下来你将会使用ysyxSoC提供的设备进行仿真, 来验证NPC可以正确访问SoC中的设备. 我们将在下文介绍具体如何接入.

需要注意的是, ysyxSoC与最终流片使用的SoC仍有一定差异. 因此, 通过ysyxSoC的测试并不代表最终也能通过流片SoC仿真环境的测试. 但即使这样, 也可以借助ysyxSoC项目提前暴露一部分问题, 若将来接入流片SoC时仍有问题, 则可重点关注两者差异带来的影响.

对大家来说, ysyxSoC项目有两部分值得大家关注. 第一部分是ysyxSoC的总线部分, 我们主要借助开源社区[rocket-chip]()项目的[diplomacy]()框架来实现它, 相关代码在`ysyxSoC/src/`目录下. 借助diplomacy, 我们可以很容易地将一个具备总线接口的设备接入ysyxSoC. 例如, 我们只需要改动以下两行Chisel代码, 即可实例化一个AXI接口的MROM设备, 同时指定其地址空间为`0x2000_0000~0x2000_0fff`, 并将其连接到AXI Xbar的下游. 如果采用传统的Verilog方式来接入, 仅仅是端口声明就要添加将近100行代码, 这还没计算对AXI Xbar的修改.

    diff --git a/src/SoC.scala b/src/SoC.scala
    index dd84776c..758fb8d1 100644
    --- a/src/SoC.scala
    +++ b/src/SoC.scala
    @@ -39,9 +39,10 @@ class ysyxSoCASIC(implicit p: Parameters) extends LazyModule {
         AddressSet.misaligned(0x10001000, 0x1000) ++    // SPI controller
         AddressSet.misaligned(0x30000000, 0x10000000)   // XIP flash
       ))
    +  val lmrom = LazyModule(new AXI4MROM(AddressSet.misaligned(0x20000000, 0x1000)))
    
       List(lspi.node, luart.node).map(_ := apbxbar)
    -  List(chiplinkNode, apbxbar := AXI4ToAPB()).map(_ := xbar)
    +  List(chiplinkNode, apbxbar := AXI4ToAPB(), lmrom.node).map(_ := xbar)
       xbar := cpu.masterNode
    
       override lazy val module = new Impl
    
第二部分是ysyxSoC的设备部分, 我们收集了一些设备控制器的开源项目, 相关代码在`ysyxSoC/perip/`目录下. 部分设备通过直接实例化rocket-chip项目中的IP来实现, 这部分设备并不在`ysyxSoC/perip/`目录下, 具体可以参考`ysyxSoC/src/`中的相关代码.

### 接入ysyxSoC

由于SoC中包含多个设备, 这些设备的属性可能有所不同, 这将会带来一些新问题. 例如, `ysyxSoC/perip/uart16550/rtl/uart_defines.v`中有如下代码:

    // Register addresses
    `define UART_REG_RB `UART_ADDR_WIDTH\'d0  // receiver buffer
    `define UART_REG_IE `UART_ADDR_WIDTH\'d1  // Interrupt enable
    `define UART_REG_II `UART_ADDR_WIDTH\'d2  // Interrupt identification
    `define UART_REG_LC `UART_ADDR_WIDTH\'d3  // Line Control
    
上述代码定义了UART中一些设备寄存器的地址, 由于UART位于`0x1000_0000`, 因此上述4个寄存器的地址分别是`0x1000_0000`, `0x1000_0001`, `0x1000_0002`, `0x1000_0003`. 假设UART通过AXI4-Lite总线连接Xbar, 考虑通过AXI4-Lite读取receiver buffer中的内容. 显然, `araddr`信号应为`0x1000_0000`, 但如果要读取4字节, 是否会同时读出后面3个设备寄存器的内容呢?

我们之前没有考虑"读多长"的问题, 是因为对内存进行读操作时, 并不会改变内存中存储数据的状态, 因此无论CPU期望读出多少字节, 总线都可以一次读出4字节或8字节, 让CPU从中选出目标数据. 这甚至有助于一些带有缓存的CPU提高性能: 从内存中读取一次数据一般需要较长时间, 如果能充分利用总线的带宽, 一次多读出一些数据, 就有可能减少将来真正访问内存的次数.

不过对于设备的访问, 上述前提不再成立: 访问设备寄存器可能会改变设备的状态! 这意味着, 对于设备来说, 读出1字节和读出4字节, 最终导致的行为可能不同. 如果我们没有按照设备寄存器的约定来访问它们, 可能会导致设备进入不可预测的状态. 因此在通过总线访问设备时, 我们需要仔细地处理这个问题.

但是, AXI4-Lite总线并不能解决上述问题, 其AR通道中没有足够的信号用于编码读取长度信息, 设备只能认为实际访问的数据位宽与AXI4-Lite总线的数据位宽相同. 因此, 若AXI4-Lite总线上的单个读请求覆盖多个设备寄存器, 则可能导致设备状态出错. 也正因为这个原因, 并非所有设备都适合通过AXI4-Lite总线接入.

例如, 上述UART就不能通过数据位宽为32位的AXI4-Lite总线接入, 因为UART中设备寄存器的间隔只有1字节, 这意味着通过AXI4-Lite读出其中的一个设备寄存器, 也会影响相应的设备寄存器的状态, 这并不是我们期望的. 对于另一款设备寄存器地址空间如下的UART, 则可以通过数据位宽为32位的AXI4-Lite总线接入, 因为这些寄存器的间隔为4字节, 正好能在不影响相邻寄存器状态的情况下读出其中某个寄存器.

    // Register addresses
    `define UART_REG_RB `UART_ADDR_WIDTH\'d0  // receiver buffer
    `define UART_REG_IE `UART_ADDR_WIDTH\'d4  // Interrupt enable
    `define UART_REG_II `UART_ADDR_WIDTH\'d8  // Interrupt identification
    `define UART_REG_LC `UART_ADDR_WIDTH\'d12 // Line Control
    
为了解决AXI4-Lite的上述问题, 完整的AXI总线协议通过`arsize`/`awsize`信号来指示实际访问的数据位宽, 同时引入"窄传输"的概念, 用于指示"实际数据位宽小于总线数据位宽"的情况. 这两个"数据位宽"的概念并非完全一致, 具体地, 总线数据位宽是在硬件设计时静态决定的, 它表示一次传输中可以传输的最大数据量; 而窄传输中的数据位宽则表示实际传输的数据量. 例如, 对于一个32位的AXI总线, 如果只传输1个字节的数据, 那么`arsize`/`awsize`就会指示数据位宽为1字节, 此时总线会进行"窄传输".

### 总结

本章主要介绍了ysyxSoC的组成以及如何接入ysyxSoC. 重点强调了在SoC中访问设备时需要注意的问题, 特别是AXI4-Lite总线在处理窄传输时的局限性. 为了解决这些问题, 完整的AXI总线协议引入了`arsize`/`awsize`信号和"窄传输"的概念, 以便更灵活地控制数据传输的位宽.

下一章我们将继续深入探讨时序分析和优化.