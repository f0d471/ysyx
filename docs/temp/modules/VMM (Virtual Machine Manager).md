# VMM (Virtual Machine Manager) Module

## Introduction

The **Virtual Machine Manager (VMM)** module enables RT-Thread to run as a **guest operating system** alongside a **host operating system** (typically Linux) on ARM Cortex-A platforms. This dual-system architecture allows RT-Thread to leverage the rich ecosystem of Linux while maintaining its real-time capabilities for time-critical tasks.

The VMM module implements a lightweight virtualization layer that allows RT-Thread and Linux to share the same physical hardware, with memory protection via ARM domain-based isolation and a virtual interrupt (vIRQ) mechanism for interrupt delegation between the two systems.

---

## Architecture Overview

The VMM module is designed around a **co-operative dual-kernel** model where:

- **Linux** acts as the **host OS**, booting first and managing hardware resources
- **RT-Thread** runs as a **guest OS** within a reserved memory region
- A **shared memory region** facilitates communication between the two systems
- **ARM Domain protection** provides memory isolation between host and guest
- A **virtual IRQ (vIRQ) mechanism** allows interrupt delegation between systems

```mermaid
graph TB
    subgraph "Physical Hardware (ARM Cortex-A)"
        HW[Hardware Resources]
        GIC[GIC Interrupt Controller]
        MMU[ARM MMU with Domain Support]
    end

    subgraph "Linux Host OS"
        LH[Linux Kernel]
        LVMM[Linux VMM Module]
        LDRV[Linux Device Drivers]
    end

    subgraph "Shared Memory Region"
        SHM[Shared Memory]
        CTX[vmm_context]
        IOMAP["vmm_iomap[]"]
    end

    subgraph "RT-Thread Guest OS"
        RTVMM[RT-Thread VMM Module]
        RTRT[RT-Thread Kernel]
        RTAPP[RT-Thread Applications]
    end

    HW --> LH
    HW --> RTVMM
    LH --> LVMM
    LVMM <--> SHM
    RTVMM <--> SHM
    LVMM --> GIC
    RTVMM --> GIC
    RTRT --> RTVMM
    RTAPP --> RTRT
```

---

## Core Components

### 1. VMM Entry Point (`vmm.c`)

The main entry point for the VMM guest system. When Linux boots RT-Thread, it calls `vmm_entry()` which initializes the RT-Thread kernel as a guest OS.

**Key Functions:**

| Function | Description |
|----------|-------------|
| `vmm_entry()` | Main entry point called by Linux to start RT-Thread as a guest |
| `vmm_thread_init()` | Initializes the VMM management thread |
| `vmm_entry_glue()` | Transitions from VMM initialization to the RT-Thread scheduler |
| `vmm_create_monitor()` | Creates a monitoring thread for guest verification |

**Initialization Flow:**

```mermaid
sequenceDiagram
    participant Linux as Linux Host
    participant VMM as VMM Module
    participant RT as RT-Thread Kernel
    participant HW as Hardware

    Linux->>VMM: vmm_entry(param)
    VMM->>VMM: vmm_iomap_init(param->iomap)
    VMM->>VMM: vmm_context_init(&RT_VMM_SHARE->ctx)
    VMM->>HW: rt_hw_interrupt_init()
    VMM->>VMM: vmm_vector_init()
    VMM->>HW: rt_hw_board_init()
    VMM->>RT: rt_system_timer_init()
    VMM->>RT: rt_system_heap_init()
    VMM->>RT: rt_system_scheduler_init()
    VMM->>RT: rt_application_init()
    VMM->>VMM: vmm_thread_init(&vmm_thread, "vmm")
    VMM->>RT: rt_schedule() (via vmm_entry_glue)
    Note over VMM,RT: Domain protection activated
    RT->>RT: First scheduling starts
```

### 2. VMM Context Management (`vmm_context.c` / `vmm_context.h`)

Manages the shared context between Linux and RT-Thread, including virtual interrupt state and ARM domain protection.

**Key Data Structures:**

```c
// From Linux patch (vmm_virhw.h)
struct vmm_context {
    volatile unsigned long virq_status;    // Virtual IRQ status (0=enabled, 1=disabled)
    volatile unsigned long virq_pended;    // Has interrupt pended on guest
    volatile unsigned long virq_pending[]; // Bitmap of pending virtual IRQs
};

// From RT-Thread side
struct rt_vmm_share_layout rt_vmm_share;  // Shared layout instance
```

**Key Functions:**

| Function | Description |
|----------|-------------|
| `vmm_context_init()` | Initializes the shared VMM context structure |
| `vmm_context_init_domain()` | Configures ARM domain protection values |
| `vmm_virq_pending()` | Marks a virtual IRQ as pending for the guest |
| `vmm_virq_update()` | Triggers a virtual IRQ if conditions are met |
| `vmm_virq_check()` | Checks if guest should handle a pending IRQ |
| `vmm_verify_guest_status()` | Monitors guest OS status for anomalies |
| `vmm_show_guest()` | Debug function to display guest state |

### 3. IO Map Management (`vmm_iomap.c`)

Manages the I/O memory mapping table that translates between physical addresses and virtual addresses for device access.

**Key Data Structures:**

```c
struct vmm_iomap {
    const char *name;  // Device name
    unsigned long pa;  // Physical address
    unsigned long va;  // Virtual address
};
```

**Key Functions:**

| Function | Description |
|----------|-------------|
| `vmm_iomap_init()` | Initializes the I/O map from parameters passed by Linux |
| `vmm_find_iomap()` | Finds virtual address by device name |
| `vmm_find_iomap_by_pa()` | Finds virtual address by physical address |

### 4. Vector/Interrupt Management (`vmm_vector.c`)

Handles the virtual interrupt vector installation for the guest system.

**Key Functions:**

| Function | Description |
|----------|-------------|
| `vmm_vector_init()` | Installs the virtual IRQ handler |
| `vmm_guest_isr()` | Guest interrupt handler (clears interrupt, lets guest OS handle it) |

### 5. Linux-Side VMM Components (from `linux_patch-v3.8`)

The Linux kernel is patched with VMM support to act as the host. Key components include:

| Component | Description |
|-----------|-------------|
| `vmm.c` (Linux) | Manages VMM status and context pointer |
| `vmm_virq.c` | Implements virtual IRQ save/restore/enable/disable |
| `vmm_traps.c` | Sets up trap vectors for IRQ/FIQ forwarding |
| `vmm_virhw.h` | Defines `vmm_context` structure and hardware IRQ helpers |

---

## Data Flow

### Virtual IRQ Flow

```mermaid
sequenceDiagram
    participant HW as Hardware
    participant GIC as GIC Controller
    participant LVMM as Linux VMM
    participant SHM as Shared Memory
    participant RVMM as RT-Thread VMM
    participant RT as RT-Thread Kernel

    HW->>GIC: Physical IRQ occurs
    GIC->>LVMM: Interrupt to Linux
    LVMM->>LVMM: Check if IRQ is for guest
    LVMM->>SHM: Set virq_pending[irq/32] |= (1 << irq%32)
    LVMM->>SHM: Set virq_pended = 1
    LVMM->>LVMM: Mask IRQ in host GIC
    Note over LVMM: Guest suspended, safe to set bits
    LVMM->>GIC: Raise soft IRQ (RTT_VMM_IRQ_TRIGGER)
    GIC->>RVMM: Soft IRQ triggers guest entry
    RVMM->>SHM: Read virq_pending bitmap
    RVMM->>RT: Handle virtual IRQ
    RT->>RT: Process interrupt
    RT->>RVMM: Return from interrupt
    RVMM->>LVMM: Guest resumes
```

### Memory Layout

```mermaid
graph LR
    subgraph "Physical Memory"
        LINUX[Linux Kernel Space]
        SHARED["Shared Memory Region (vmm_context + vmm_iomap)"]
        RTVMM["RT-Thread VMM Space (Code + Data + Heap)"]
    end

    subgraph "ARM Domain Protection"
        D0[Domain 0: IO]
        D1[Domain 1: Linux Kernel]
        D2[Domain 2: Linux User]
        D3[Domain 3: RT-Thread VMM]
        D4[Domain 4: Shared Memory]
    end

    LINUX --> D1
    SHARED --> D4
    RTVMM --> D3
```

---

## Component Interaction Diagram

```mermaid
graph TB
    subgraph "RT-Thread Side"
        VMM_ENTRY[vmm_entry]
        VMM_CTX[vmm_context_init]
        VMM_IOMAP[vmm_iomap_init]
        VMM_VEC[vmm_vector_init]
        VMM_MON[vmm_create_monitor]
        VMM_GLUE[vmm_entry_glue]
    end

    subgraph "Shared Structures"
        SHARE[rt_vmm_share_layout]
        CTX[vmm_context]
        IOMAP["vmm_iomap[]"]
    end

    subgraph "Linux Side"
        L_VMM[Linux VMM Module]
        L_VIRQ[vmm_virq.c]
        L_TRAPS[vmm_traps.c]
        L_GIC[GIC Handler]
    end

    VMM_ENTRY --> VMM_CTX
    VMM_ENTRY --> VMM_IOMAP
    VMM_ENTRY --> VMM_VEC
    VMM_ENTRY --> VMM_MON
    VMM_ENTRY --> VMM_GLUE
    
    VMM_CTX --> CTX
    VMM_IOMAP --> IOMAP
    
    CTX --> L_VIRQ
    IOMAP --> L_VMM
    
    L_VIRQ --> L_GIC
    L_TRAPS --> L_GIC
    
    SHARE --> CTX
    SHARE --> IOMAP
```

---

## Dependencies

### Internal Dependencies

| Component | Depends On | Description |
|-----------|------------|-------------|
| `vmm.c` | `vmm.h`, `vmm_context.h`, `board.h` | Main entry depends on context and board init |
| `vmm_context.c` | `vmm.h`, `vmm_context.h`, `rthw.h`, `rtthread.h` | Context management uses kernel APIs |
| `vmm_iomap.c` | `vmm.h`, `rtthread.h` | IO map uses string comparison |
| `vmm_vector.c` | `vmm.h`, `rthw.h`, `interrupt.h` | Vector init uses hardware interrupt API |

### External Dependencies

| Module | Relationship |
|--------|--------------|
| [RT-Thread Kernel](RT-Thread%20Kernel.md) | Core kernel services (threading, scheduling, timers, heap) |
| [Memory Management](Memory%20Management.md) | Heap initialization and memory allocation |
| [LWP (Light Weight Process)](LWP%20(Light%20Weight%20Process).md) | Shares ARM architecture context structures (`rt_hw_stack`) |
| [Finsh Shell](Finsh%20Shell.md) | Debug commands via `FINSH_FUNCTION_EXPORT_ALIAS` |

---

## Configuration Options

The VMM module is configured via Kconfig options (defined in the Linux patch):

| Option | Description | Default |
|--------|-------------|---------|
| `RT_USING_VMM` | Enable VMM support | N |
| `RT_VMM_USING_DOMAIN` | Enable ARM domain protection | N |
| `VMM_VERIFY_GUEST` | Enable guest status monitoring | Y |
| `HOST_VMM_ADDR_END` | End address of VMM space | 0xE0000000 |
| `HOST_VMM_SIZE` | Size of VMM space | 0x400000 (4MB) |
| `RTVMM_SHARED_SIZE` | Size of shared memory | 0x100000 (1MB) |

---

## ARM Domain Protection

When `RT_VMM_USING_DOMAIN` is enabled, the VMM uses ARM's domain-based memory protection to isolate the guest and host:

```mermaid
graph TD
    subgraph "Domain Access Control (DAC) Register"
        D0["Domain 0 (IO): 3=Manager"]
        D1["Domain 1 (Linux Kernel): 3=Manager"]
        D2["Domain 2 (Linux User): 3=Manager"]
        D3["Domain 3 (VMM): 1=Client"]
        D4["Domain 4 (Shared): 1=Client"]
    end

    subgraph "Domain Values"
        GUEST[guest_domain_val: Linux original DAC]
        VMM[vmm_domain_val: VMM's view]
        SUPER[super_domain_val: Access both sides]
    end

    GUEST --> D0
    GUEST --> D1
    GUEST --> D2
    VMM --> D3
    VMM --> D4
    SUPER --> D1
    SUPER --> D2
    SUPER --> D3
    SUPER --> D4
```

---

## Debug and Monitoring

The VMM module includes several debugging features:

- **`vmm_verify_guest_status()`**: Periodically checks the guest's CPSR register for anomalies (bad modes, disabled IRQs, etc.)
- **`vmm_show_guest()`**: Displays guest register state, virtual IRQ status, and domain configuration
- **`vmm_dump_virq()`**: Dumps the virtual IRQ pending bitmap
- **Finsh command**: `vmm` command registered via `FINSH_FUNCTION_EXPORT_ALIAS` for interactive debugging

---

## Linux Patch Integration

The VMM module includes patches for Linux kernel v3.8 that modify:

1. **GIC driver**: Intercept IRQ handling to check for virtual IRQs
2. **IRQ flags**: Replace direct CPSR manipulation with VMM-aware functions
3. **MMU initialization**: Reserve memory for VMM and create page table entries with proper domain attributes
4. **Exception handling**: Modify entry/exit paths to manage virtual IRQ state
5. **Domain configuration**: Add new domain definitions for VMM and shared memory

---

## Summary

The VMM module enables a powerful dual-OS architecture where RT-Thread runs alongside Linux on ARM Cortex-A platforms. Key design highlights:

- **Co-operative model**: Both OSes are aware of each other and collaborate
- **ARM domain isolation**: Hardware-enforced memory protection between systems
- **Virtual IRQ mechanism**: Efficient interrupt delegation via soft IRQs
- **Shared memory communication**: Simple, low-latency inter-OS communication
- **Minimal overhead**: Lightweight virtualization without full hypervisor complexity
