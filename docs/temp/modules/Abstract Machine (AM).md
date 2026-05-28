# Abstract Machine (AM)

## Introduction

The **Abstract Machine (AM)** is a hardware abstraction layer that provides a uniform, platform-independent programming interface for system-level software. It serves as the foundational layer between hardware (real or simulated) and higher-level software components such as operating system kernels (e.g., Nanos-lite), user applications (Navy Apps), and benchmark suites (AM Kernels).

The AM defines five abstract machine models, each encapsulating a specific set of hardware capabilities:

| Model | Name | Purpose |
|-------|------|---------|
| **TRM** | Turing Machine | Minimal computation: heap, putch, halt |
| **IOE** | I/O Devices | Device access: UART, timer, keyboard, GPU, audio, disk, network |
| **CTE** | Context and Trap Extension | Interrupt/exception handling and context switching |
| **VME** | Virtual Memory Extension | Address space management and page mapping |
| **MPE** | Multi-Processing Extension | Multi-core CPU support and atomic operations |

The AM is designed for the **YSYX ("一生一芯")** educational project, where it runs on top of various hardware simulators (NEMU, NPC) and real hardware (QEMU, Spike, native platform), enabling the same software stack to execute across different ISAs (x86, RISC-V, MIPS32, LoongArch32r) without modification.

---

## Architecture Overview

The AM module follows a layered architecture where platform-independent abstractions sit above platform-specific implementations.

```mermaid
graph TB
    subgraph "Application / OS Layer"
        NANOS[Nanos-lite OS]
        NAVY[Navy Apps]
        AMK[AM Kernels]
    end

    subgraph "Abstract Machine API"
        TRM["TRM<br/>Turing Machine"]
        IOE["IOE<br/>I/O Devices"]
        CTE["CTE<br/>Context & Traps"]
        VME["VME<br/>Virtual Memory"]
        MPE["MPE<br/>Multi-Processing"]
    end

    subgraph "Platform Abstraction"
        NEMU_PLAT["NEMU Platform"]
        QEMU_PLAT["QEMU Platform"]
        NATIVE_PLAT["Native Platform"]
        NPC_PLAT["NPC Platform"]
        SPIKE_PLAT["Spike Platform"]
    end

    subgraph "ISA Abstraction"
        X86["x86"]
        RISCV["RISC-V"]
        MIPS["MIPS32"]
        LOONGARCH["LoongArch32r"]
    end

    subgraph "Hardware / Simulator"
        NEMU["NEMU Emulator"]
        QEMU["QEMU"]
        NPC["NPC Simulator"]
        SPIKE["Spike Simulator"]
        HOST["Host OS"]
    end

    NANOS --> TRM
    NANOS --> IOE
    NANOS --> CTE
    NANOS --> VME
    NAVY --> TRM
    NAVY --> IOE
    AMK --> TRM
    AMK --> IOE

    TRM --> NEMU_PLAT
    TRM --> QEMU_PLAT
    TRM --> NATIVE_PLAT
    IOE --> NEMU_PLAT
    IOE --> QEMU_PLAT
    IOE --> NATIVE_PLAT
    CTE --> X86
    CTE --> RISCV
    CTE --> MIPS
    CTE --> LOONGARCH
    VME --> X86
    VME --> RISCV
    MPE --> NEMU_PLAT
    MPE --> NATIVE_PLAT

    NEMU_PLAT --> X86
    NEMU_PLAT --> RISCV
    NEMU_PLAT --> MIPS
    NEMU_PLAT --> LOONGARCH
    QEMU_PLAT --> X86
    NATIVE_PLAT --> HOST
    NPC_PLAT --> RISCV
    SPIKE_PLAT --> RISCV

    X86 --> NEMU
    X86 --> QEMU
    RISCV --> NEMU
    RISCV --> NPC
    RISCV --> SPIKE
    MIPS --> NEMU
    LOONGARCH --> NEMU
```

---

## Core Components

### 1. Core Data Structures

The AM defines several fundamental data structures that are shared across all models.

```mermaid
classDiagram
    class Area {
        +void* start
        +void* end
    }

    class Event {
        +enum event_type event
        +uintptr_t cause
        +uintptr_t ref
        +const char* msg
    }

    class Context {
        <<arch-dependent>>
        +uintptr_t gpr[]
        +uintptr_t mcause/mepc/mstatus
        +void* cr3
        +int irq
    }

    class AddrSpace {
        +int pgsize
        +Area area
        +void* ptr
    }

    Event --> Context : handler receives
    AddrSpace --> Area : contains
```

#### `Area`
Represents a contiguous memory region `[start, end)`. Used throughout the AM to describe memory ranges such as the heap, kernel stacks, and address space boundaries.

```c
typedef struct {
  void *start, *end;
} Area;
```

#### `Event`
Describes an event that triggers a context switch or trap. The event type determines how the handler should process it.

```c
typedef struct {
  enum {
    EVENT_NULL = 0,
    EVENT_YIELD, EVENT_SYSCALL, EVENT_PAGEFAULT, EVENT_ERROR,
    EVENT_IRQ_TIMER, EVENT_IRQ_IODEV,
  } event;
  uintptr_t cause, ref;
  const char *msg;
} Event;
```

#### `Context`
An **architecture-dependent** structure that holds the full CPU register state during a context switch. Each ISA defines its own `Context` layout:

- **x86 (NEMU)**: `esi, ebx, eax, eip, edx, eflags, ecx, cs, esp, edi, ebp, cr3, irq`
- **RISC-V**: `gpr[NR_REGS], mcause, mstatus, mepc` (with `pdir` aliased to `gpr[0]`)
- **Native**: `ksp, vm_head, ucontext_t` (wraps host OS `ucontext`)

#### `AddrSpace`
Represents a protected address space with virtual memory support. Contains the page size, user memory area, and an architecture-dependent pointer (typically a page table/directory pointer).

```c
typedef struct {
  int pgsize;
  Area area;
  void *ptr;
} AddrSpace;
```

---

### 2. TRM: Turing Machine

The **Turing Machine** model provides the minimal set of operations required for computation: a heap memory area, character output, and program termination.

```mermaid
graph LR
    subgraph "TRM API"
        HEAP[heap Area]
        PUTCH[putch char]
        HALT[halt int]
    end

    HEAP -->|global variable| APP[Application]
    PUTCH -->|output| SERIAL[Serial Port]
    HALT -->|terminate| TRAP[Trap to Simulator]
```

**Key Components:**

| Component | Description |
|-----------|-------------|
| `heap` | Global `Area` defining the available heap memory (from `_heap_start` to `PMEM_END`) |
| `putch(char ch)` | Outputs a single character to the serial port (or stdout on native) |
| `halt(int code)` | Terminates the program with an exit code via a simulator trap |

**Implementation (NEMU platform):**
```c
Area heap = RANGE(&_heap_start, PMEM_END);

void putch(char ch) {
  outb(SERIAL_PORT, ch);  // Write to serial port MMIO
}

void halt(int code) {
  nemu_trap(code);  // Trigger simulator trap
  while (1);
}
```

**Startup Flow:**
```mermaid
sequenceDiagram
    participant HW as Hardware/Simulator
    participant START as _start (start.S)
    participant TRM as _trm_init (trm.c)
    participant MAIN as main()

    HW->>START: Reset vector
    START->>START: Set up stack pointer
    START->>TRM: call _trm_init
    TRM->>MAIN: ret = main(mainargs)
    MAIN->>TRM: return
    TRM->>HW: halt(ret) -> nemu_trap
```

---

### 3. IOE: Input/Output Devices

The **I/O Devices** model provides a uniform interface for accessing hardware devices through a register-based read/write mechanism.

```mermaid
graph TB
    subgraph "IOE API"
        IOE_INIT[ioe_init]
        IOE_READ[ioe_read reg, buf]
        IOE_WRITE[ioe_write reg, buf]
    end

    subgraph "Device Register Map"
        UART["UART<br/>AM_UART_CONFIG/TX/RX"]
        TIMER["Timer<br/>AM_TIMER_CONFIG/RTC/UPTIME"]
        INPUT["Input<br/>AM_INPUT_CONFIG/KEYBRD"]
        GPU["GPU<br/>AM_GPU_CONFIG/STATUS/FBDRAW"]
        AUDIO["Audio<br/>AM_AUDIO_CONFIG/CTRL/STATUS/PLAY"]
        DISK["Disk<br/>AM_DISK_CONFIG/STATUS/BLKIO"]
        NET["Network<br/>AM_NET_CONFIG/STATUS/TX/RX"]
    end

    subgraph "Device MMIO Addresses (NEMU)"
        SERIAL[SERIAL_PORT 0xa00003f8]
        KBD[KBD_ADDR 0xa0000060]
        RTC[RTC_ADDR 0xa0000048]
        VGA[VGACTL_ADDR 0xa0000100]
        AUDIO_MMIO[AUDIO_ADDR 0xa0000200]
        DISK_MMIO[DISK_ADDR 0xa0000300]
        FB[FB_ADDR 0xa1000000]
    end

    IOE_INIT -->|initializes| GPU
    IOE_INIT -->|initializes| TIMER
    IOE_INIT -->|initializes| AUDIO
    IOE_READ -->|dispatches| UART
    IOE_READ -->|dispatches| TIMER
    IOE_READ -->|dispatches| INPUT
    IOE_READ -->|dispatches| GPU
    IOE_READ -->|dispatches| AUDIO
    IOE_READ -->|dispatches| DISK
    IOE_READ -->|dispatches| NET
    IOE_WRITE -->|dispatches| UART
    IOE_WRITE -->|dispatches| GPU
    IOE_WRITE -->|dispatches| AUDIO
    IOE_WRITE -->|dispatches| DISK
    IOE_WRITE -->|dispatches| NET

    UART --> SERIAL
    INPUT --> KBD
    TIMER --> RTC
    GPU --> VGA
    GPU --> FB
    AUDIO --> AUDIO_MMIO
    DISK --> DISK_MMIO
```

#### Device Register Definitions

Devices are defined using the `AM_DEVREG` macro, which generates both an enum constant and a typed struct for each register:

```c
#define AM_DEVREG(id, reg, perm, ...) \
  enum { AM_##reg = (id) }; \
  typedef struct { __VA_ARGS__; } AM_##reg##_T;
```

| ID | Register | Permission | Fields |
|----|----------|------------|--------|
| 1 | `UART_CONFIG` | RD | `bool present` |
| 2 | `UART_TX` | WR | `char data` |
| 3 | `UART_RX` | RD | `char data` |
| 4 | `TIMER_CONFIG` | RD | `bool present, has_rtc` |
| 5 | `TIMER_RTC` | RD | `int year, month, day, hour, minute, second` |
| 6 | `TIMER_UPTIME` | RD | `uint64_t us` |
| 7 | `INPUT_CONFIG` | RD | `bool present` |
| 8 | `INPUT_KEYBRD` | RD | `bool keydown; int keycode` |
| 9 | `GPU_CONFIG` | RD | `bool present, has_accel; int width, height, vmemsz` |
| 10 | `GPU_STATUS` | RD | `bool ready` |
| 11 | `GPU_FBDRAW` | WR | `int x, y; void *pixels; int w, h; bool sync` |
| 12 | `GPU_MEMCPY` | WR | `uint32_t dest; void *src; int size` |
| 13 | `GPU_RENDER` | WR | `uint32_t root` |
| 14 | `AUDIO_CONFIG` | RD | `bool present; int bufsize` |
| 15 | `AUDIO_CTRL` | WR | `int freq, channels, samples` |
| 16 | `AUDIO_STATUS` | RD | `int count` |
| 17 | `AUDIO_PLAY` | WR | `Area buf` |
| 18 | `DISK_CONFIG` | RD | `bool present; int blksz, blkcnt` |
| 19 | `DISK_STATUS` | RD | `bool ready` |
| 20 | `DISK_BLKIO` | WR | `bool write; void *buf; int blkno, blkcnt` |
| 21 | `NET_CONFIG` | RD | `bool present` |
| 22 | `NET_STATUS` | RD | `int rx_len, tx_len` |
| 23 | `NET_TX` | WR | `Area buf` |
| 24 | `NET_RX` | WR | `Area buf` |

#### Convenience Macros

```c
// Read a device register
#define io_read(reg) \
  ({ reg##_T __io_param; \
    ioe_read(reg, &__io_param); \
    __io_param; })

// Write a device register
#define io_write(reg, ...) \
  ({ reg##_T __io_param = (reg##_T) { __VA_ARGS__ }; \
    ioe_write(reg, &__io_param); })
```

#### IOE Dispatch Mechanism

The IOE uses a **lookup table** (`lut[128]`) indexed by register ID to dispatch read/write operations:

```mermaid
flowchart LR
    A[ioe_read/ioe_write] --> B{LUT[reg] exists?}
    B -->|Yes| C[Call handler function]
    B -->|No| D[Call fail handler]
    C --> E[Handler reads/writes MMIO]
    D --> F[panic: access nonexist register]
```

---

### 4. CTE: Context and Trap Extension

The **Context and Trap Extension** manages interrupt/exception handling and context switching between kernel and user mode.

```mermaid
graph TB
    subgraph "CTE API"
        CTE_INIT[cte_init handler]
        YIELD[yield]
        IENABLED[ienabled]
        ISET[iset enable]
        KCONTEXT[kcontext kstack, entry, arg]
    end

    subgraph "Trap Handling Flow"
        EVENT[Hardware Event] --> TRAP_VEC[Trap Vector]
        TRAP_VEC --> SAVE[Save Context]
        SAVE --> HANDLER[__am_irq_handle]
        HANDLER --> USER_HANDLER[User Handler]
        USER_HANDLER --> DECODE{Event Type}
        DECODE -->|EVENT_YIELD| YIELD_PROC[Yield processing]
        DECODE -->|EVENT_SYSCALL| SYSCALL_PROC[Syscall processing]
        DECODE -->|EVENT_ERROR| ERROR_PROC[Error handling]
        DECODE -->|EVENT_IRQ_TIMER| TIMER_PROC[Timer interrupt]
        DECODE -->|EVENT_IRQ_IODEV| IO_PROC[I/O interrupt]
        USER_HANDLER --> RESTORE[Restore Context]
        RESTORE --> RETURN[Return from trap]
    end

    KCONTEXT -->|creates| KERNEL_CTX[Kernel Context]
    KERNEL_CTX -->|used by| CTX_SWITCH[Context Switch]
```

#### Trap Handling (x86-NEMU)

```mermaid
sequenceDiagram
    participant CPU as CPU
    participant IDT as IDT
    participant TRAP as trap.S
    participant CTE as cte.c
    participant HANDLER as User Handler

    CPU->>IDT: Interrupt/Exception
    IDT->>TRAP: Jump to vector
    TRAP->>TRAP: push $irq
    TRAP->>TRAP: pushal (save regs)
    TRAP->>CTE: call __am_irq_handle
    CTE->>HANDLER: user_handler(ev, ctx)
    HANDLER->>CTE: return modified ctx
    CTE->>TRAP: return ctx
    TRAP->>TRAP: popal (restore regs)
    TRAP->>CPU: iret
```

#### Trap Handling (RISC-V-NEMU)

```mermaid
sequenceDiagram
    participant CPU as CPU
    participant TRAP as trap.S
    participant CTE as cte.c
    participant HANDLER as User Handler

    CPU->>TRAP: ecall/ebreak/interrupt
    TRAP->>TRAP: Save regs to stack
    TRAP->>TRAP: csrr mcause, mstatus, mepc
    TRAP->>CTE: mv a0, sp; call __am_irq_handle
    CTE->>HANDLER: user_handler(ev, ctx)
    HANDLER->>CTE: return modified ctx
    CTE->>TRAP: mv sp, a0
    TRAP->>TRAP: csrw mstatus, mepc
    TRAP->>TRAP: Restore regs from stack
    TRAP->>CPU: mret
```

#### Context Creation

The `kcontext()` function creates a kernel-mode context for a new thread:

```c
// RISC-V implementation
Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  Context *c = (Context *)((uintptr_t)kstack.end - sizeof(Context));
  memset(c, 0, sizeof(Context));
  c->mepc = (uintptr_t)entry;       // Entry point
  c->gpr[2] = (uintptr_t)kstack.end; // x2 = sp (stack pointer)
  c->gpr[10] = (uintptr_t)arg;       // x10 = a0 (first argument)
  c->mstatus = 0x1800;               // MIE=1, MPIE=1
  return c;
}
```

---

### 5. VME: Virtual Memory Extension

The **Virtual Memory Extension** provides address space management, page table manipulation, and user-mode context creation.

```mermaid
graph TB
    subgraph "VME API"
        VME_INIT[vme_init pgalloc, pgfree]
        PROTECT[protect as]
        UNPROTECT[unprotect as]
        MAP[map as, va, pa, prot]
        UCONTEXT[ucontext as, kstack, entry]
    end

    subgraph "Address Space Lifecycle"
        AS_INIT[Create Address Space] --> ALLOC_PT[Allocate Page Table]
        ALLOC_PT --> MAP_KERNEL[Map Kernel Space]
        MAP_KERNEL --> MAP_USER[Map User Pages]
        MAP_USER --> SWITCH[Switch Address Space]
        SWITCH --> RUN[Run User Process]
    end

    subgraph "Page Table Structure"
        PD[Page Directory]
        PT[Page Table]
        PD --> PT
        PT --> PAGE[Physical Page]
    end

    VME_INIT -->|initializes| KAS[Kernel Address Space]
    PROTECT -->|creates| USER_AS[User Address Space]
    MAP -->|modifies| PAGE_TABLE[Page Table]
    UCONTEXT -->|creates| USER_CTX[User Context]
```

#### VME Initialization (x86-NEMU)

```mermaid
flowchart LR
    A[vme_init] --> B[Allocate page directory]
    B --> C[Map kernel segments]
    C --> D[Set CR3 = page directory]
    D --> E[Set CR0.PG = 1]
    E --> F[Enable paging]
```

#### Address Space Protection

```c
void protect(AddrSpace *as) {
  PTE *updir = (PTE*)(pgalloc_usr(PGSIZE));
  as->ptr = updir;
  as->area = USER_SPACE;  // e.g., 0x40000000 - 0xc0000000
  as->pgsize = PGSIZE;    // 4096 bytes
  // Copy kernel page table entries
  memcpy(updir, kas.ptr, PGSIZE);
}
```

#### Context Switching with VME

The VME integrates with CTE to switch address spaces during context switches:

```c
void __am_get_cur_as(Context *c) {
  c->cr3 = (vme_enable ? (void *)get_cr3() : NULL);
}

void __am_switch(Context *c) {
  if (vme_enable && c->cr3 != NULL) {
    set_cr3(c->cr3);  // Switch page directory
  }
}
```

---

### 6. MPE: Multi-Processing Extension

The **Multi-Processing Extension** provides support for multi-core CPUs and atomic operations.

```mermaid
graph TB
    subgraph "MPE API"
        MPE_INIT[mpe_init entry]
        CPU_COUNT[cpu_count]
        CPU_CURRENT[cpu_current]
        ATOMIC_XCHG[atomic_xchg addr, newval]
    end

    subgraph "Multi-Core Execution"
        CPU0[CPU 0] --> ENTRY[entry function]
        CPU1[CPU 1] --> ENTRY
        CPU2[CPU 2] --> ENTRY
        CPU3[CPU 3] --> ENTRY
    end

    ATOMIC_XCHG -->|lock xchg| MEMORY[Shared Memory]
```

**Implementation (NEMU platform - single core):**
```c
bool mpe_init(void (*entry)()) {
  entry();                    // Run entry on single CPU
  panic("MPE entry returns"); // Should never return
}

int cpu_count() { return 1; }     // Single core
int cpu_current() { return 0; }   // Always CPU 0

int atomic_xchg(int *addr, int newval) {
  return atomic_exchange(addr, newval);  // C11 atomic
}
```

**Implementation (x86 with SMP):**
```c
static inline int xchg(int *addr, int newval) {
  int result;
  asm volatile ("lock xchg %0, %1":
    "+m"(*addr), "=a"(result) : "1"(newval) : "cc", "memory");
  return result;
}
```

---

## Platform Implementations

### NEMU Platform

The NEMU platform is the primary target for the YSYX project. It runs on the **NEMU emulator**, which simulates various ISAs.

**Memory Map (NEMU):**
| Region | Address | Size |
|--------|---------|------|
| Physical Memory | `0x80000000` | 128 MB |
| Framebuffer (FB) | `0xa1000000` | 2 MB |
| MMIO Region | `0xa0000000` | 4 KB |
| Serial Port | `0xa00003f8` | - |
| Keyboard | `0xa0000060` | - |
| RTC | `0xa0000048` | - |
| VGA Controller | `0xa0000100` | - |
| Audio | `0xa0000200` | - |
| Disk | `0xa0000300` | - |

**Source Files:**
| File | Purpose |
|------|---------|
| `platform/nemu/trm.c` | TRM implementation (heap, putch, halt) |
| `platform/nemu/ioe/ioe.c` | IOE dispatch and initialization |
| `platform/nemu/ioe/timer.c` | Timer device (uptime, RTC) |
| `platform/nemu/ioe/input.c` | Keyboard input device |
| `platform/nemu/ioe/gpu.c` | GPU framebuffer device |
| `platform/nemu/ioe/audio.c` | Audio playback device |
| `platform/nemu/ioe/disk.c` | Disk block I/O device |
| `platform/nemu/mpe.c` | Multi-processing (single core) |

### Native Platform

The native platform runs directly on the host OS (Linux/macOS) using POSIX APIs, enabling debugging and testing without a simulator.

**Source Files:**
| File | Purpose |
|------|---------|
| `native/trm.c` | TRM using `putchar` and `exit` |
| `native/cte.c` | CTE using `ucontext` for context switching |
| `native/vme.c` | VME using `mmap` for virtual memory |
| `native/ioe.c` | IOE using SDL for input/display |
| `native/mpe.c` | MPE using pthreads for multi-core |
| `native/trap.S` | Signal-based trap handling |

### ISA-Specific Implementations

Each ISA provides architecture-specific trap handling and context structures:

| ISA | Files | Context Structure |
|-----|-------|-------------------|
| **x86** | `x86/nemu/cte.c`, `trap.S`, `vme.c` | GPRs + cr3 + irq |
| **RISC-V** | `riscv/nemu/cte.c`, `trap.S`, `vme.c` | GPRs + mcause + mstatus + mepc |
| **MIPS32** | `mips/nemu/cte.c`, `trap.S`, `vme.c` | GPRs + cp0 registers |
| **LoongArch32r** | `loongarch/nemu/cte.c`, `trap.S`, `vme.c` | GPRs + CSR registers |

---

## Build System

The AM uses a sophisticated Makefile-based build system that supports cross-compilation for multiple architectures and platforms.

```mermaid
graph TB
    subgraph "Build Configuration"
        ARCH["ARCH variable<br/>e.g., x86-nemu, riscv32-nemu"]
        ISA["ISA extracted from ARCH<br/>e.g., x86, riscv32"]
        PLATFORM["Platform extracted from ARCH<br/>e.g., nemu, qemu, native"]
    end

    subgraph "Build Process"
        CFLAGS["CFLAGS<br/>-D__ISA__ -D__ARCH__ -D__PLATFORM__"]
        SRCS["AM_SRCS<br/>Platform + ISA source files"]
        LD["Linker Script<br/>scripts/linker.ld"]
    end

    subgraph "Output"
        ELF["$(NAME)-$(ARCH).elf<br/>ELF binary"]
        BIN["$(NAME)-$(ARCH).bin<br/>Raw binary image"]
        TXT["$(NAME)-$(ARCH).txt<br/>Disassembly"]
    end

    ARCH --> CFLAGS
    ARCH --> SRCS
    ARCH --> LD
    CFLAGS --> ELF
    SRCS --> ELF
    LD --> ELF
    ELF --> BIN
    ELF --> TXT
```

**Architecture-Specific Makefile Fragments:**
| File | Example Targets |
|------|----------------|
| `scripts/x86-nemu.mk` | x86 on NEMU emulator |
| `scripts/riscv32-nemu.mk` | RISC-V 32-bit on NEMU |
| `scripts/riscv64-nemu.mk` | RISC-V 64-bit on NEMU |
| `scripts/mips32-nemu.mk` | MIPS32 on NEMU |
| `scripts/loongarch32r-nemu.mk` | LoongArch32r on NEMU |
| `scripts/native.mk` | Native host execution |
| `scripts/x86-qemu.mk` | x86 on QEMU |
| `scripts/spike.mk` | RISC-V on Spike simulator |

---

## Dependencies and Relationships

### Internal Dependencies

```mermaid
graph LR
    subgraph "AM Internal"
        TRM -->|uses| KLIB[klib library]
        IOE -->|uses| KLIB
        CTE -->|uses| KLIB
        VME -->|uses| KLIB
        CTE -->|uses| TRM[halt for errors]
        VME -->|uses| TRM
        VME -->|uses| CTE[context switching]
    end

    subgraph "klib Library"
        KLIB_MACROS[klib-macros.h<br/>RANGE, LENGTH, io_read/write]
        KLIB_CORE[klib.h<br/>memset, memcpy, printf, assert]
    end

    TRM --> KLIB_MACROS
    IOE --> KLIB_MACROS
    CTE --> KLIB_CORE
    VME --> KLIB_CORE
```

### External Dependencies

```mermaid
graph TB
    subgraph "AM Module"
        AM[Abstract Machine]
    end

    subgraph "Consumers"
        NANOS[Nanos-lite OS]
        NAVY[Navy Apps]
        AMK[AM Kernels]
    end

    subgraph "Underlying Hardware/Simulators"
        NEMU[NEMU Emulator]
        QEMU[QEMU]
        NPC[NPC Simulator]
        SPIKE[Spike Simulator]
        HOST[Host OS]
    end

    NANOS --> AM
    NAVY --> AM
    AMK --> AM
    AM --> NEMU
    AM --> QEMU
    AM --> NPC
    AM --> SPIKE
    AM --> HOST
```

---

## Data Flow Examples

### Character Output Flow

```mermaid
sequenceDiagram
    participant APP as Application
    participant TRM as TRM (putch)
    participant PLAT as Platform (NEMU)
    participant HW as Hardware/Simulator

    APP->>TRM: putch('A')
    TRM->>PLAT: outb(SERIAL_PORT, 'A')
    PLAT->>HW: MMIO write to 0xa00003f8
    HW->>HW: Display character
```

### Keyboard Input Flow

```mermaid
sequenceDiagram
    participant HW as Hardware/Simulator
    participant IOE as IOE (input.c)
    participant APP as Application

    HW->>IOE: Keyboard interrupt (or poll)
    APP->>IOE: io_read(AM_INPUT_KEYBRD)
    IOE->>HW: inl(KBD_ADDR)
    HW->>IOE: raw keycode
    IOE->>IOE: Decode keydown + keycode
    IOE->>APP: Return AM_INPUT_KEYBRD_T
```

### Context Switch Flow

```mermaid
sequenceDiagram
    participant CPU as CPU
    participant TRAP as Trap Handler
    participant CTE as CTE
    participant HANDLER as User Handler
    participant SCHED as Scheduler

    CPU->>TRAP: Timer interrupt / ecall
    TRAP->>TRAP: Save CPU context
    TRAP->>CTE: __am_irq_handle(ctx)
    CTE->>CTE: Create Event from mcause/irq
    CTE->>HANDLER: user_handler(ev, ctx)
    HANDLER->>SCHED: Schedule next thread
    SCHED->>HANDLER: Return new context
    HANDLER->>CTE: Return modified context
    CTE->>TRAP: Return new context pointer
    TRAP->>TRAP: Restore CPU context
    TRAP->>CPU: mret/iret
```

---

## Key Macros and Utilities

The AM provides several utility macros through `klib-macros.h`:

| Macro | Description |
|-------|-------------|
| `RANGE(st, ed)` | Creates an `Area` from start and end pointers |
| `LENGTH(arr)` | Returns the number of elements in an array |
| `ROUNDUP(a, sz)` | Rounds up `a` to the nearest multiple of `sz` |
| `ROUNDDOWN(a, sz)` | Rounds down `a` to the nearest multiple of `sz` |
| `IN_RANGE(ptr, area)` | Checks if `ptr` is within `area` |
| `io_read(reg)` | Reads a device register |
| `io_write(reg, ...)` | Writes to a device register |
| `panic(s)` | Prints a message and halts |
| `panic_on(cond, s)` | Conditionally panics |
| `putstr(s)` | Prints a string using `putch` |
| `static_assert(const_cond)` | Compile-time assertion |

---

## References

- [NEMU Emulator](NEMU%20Emulator.md) - The primary emulator target for AM
- [NPC Simulator](NPC%20Simulator.md) - The RISC-V NPC simulator target
- [Nanos-lite](Nanos-lite.md) - The educational OS that runs on top of AM
- [AM Kernels](AM%20Kernels.md) - Benchmark and demo kernels using AM
- [klib Library](klib%20Library.md) - The minimal C library used by AM
- [RT-Thread Kernel](RT-Thread%20Kernel.md) - RTOS kernel with similar abstraction concepts
