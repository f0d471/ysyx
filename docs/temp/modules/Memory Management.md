# Memory Management Module

## Introduction

The Memory Management (MM) module is a core subsystem of the RT-Thread operating system that provides comprehensive memory management services across multiple layers of abstraction. It encompasses both **kernel-level memory allocators** (small memory, slab, memheap, mempool) for dynamic memory allocation within the kernel, and **virtual memory management** (address spaces, page allocator, MMU management) for systems with Memory Management Units (MMU) — primarily used in RT-Thread Smart for process isolation.

The module is designed to be highly configurable and scalable, supporting:
- **MCU-based systems**: Simple heap allocators (small memory, memheap) and fixed-size memory pools
- **MPU-based systems**: Slab allocator for efficient object caching
- **MMU-based systems (RT-Thread Smart)**: Full virtual address space management with page-based allocation, demand paging, copy-on-write (COW), and memory-mapped files

---

## Architecture Overview

The Memory Management module is organized into three distinct layers, each building upon the services of the layer below.

```mermaid
graph TB
    subgraph "User Space / Application Layer"
        APP[User Applications]
        LIBC[libc malloc/free]
    end

    subgraph "Kernel Heap Allocators"
        SMALL[Small Memory Manager<br/>src/mem.c]
        SLAB[Slab Allocator<br/>src/slab.c]
        MEMHEAP[Memory Heap<br/>src/memheap.c]
        MEMPOOL[Memory Pool<br/>src/mempool.c]
    end

    subgraph "Virtual Memory Management (MMU)"
        ASPACE[Address Space<br/>mm_aspace.c/h]
        VAREA[Virtual Memory Area<br/>mm_aspace.h]
        PAGE[Page Allocator<br/>mm_page.c/h]
        FAULT[Page Fault Handler<br/>mm_fault.c/h]
        KERNEL_MAP[Kernel Memory Map<br/>mm_kmem.c]
        IOREMAP[I/O Remap<br/>ioremap.c/h]
        OBJ_MAP[Memory Object Mapper<br/>mm_object.c]
    end

    subgraph "Data Structures"
        AVL[AVL Tree<br/>util_avl / avl_adpt]
        BUDDY[Buddy Allocator<br/>mm_page.c]
        LIST[Linked Lists<br/>rt_list_t]
    end

    subgraph "Hardware Abstraction"
        MMU_HAL[MMU HAL<br/>mmu.h / tlb.h]
        CPU_HAL[CPU HAL<br/>rthw.h]
    end

    APP --> LIBC
    LIBC --> SMALL
    LIBC --> SLAB
    LIBC --> MEMHEAP

    SMALL --> ASPACE
    SLAB --> ASPACE
    MEMHEAP --> ASPACE
    MEMPOOL --> ASPACE

    ASPACE --> VAREA
    ASPACE --> PAGE
    ASPACE --> FAULT
    ASPACE --> KERNEL_MAP
    ASPACE --> IOREMAP
    ASPACE --> OBJ_MAP

    VAREA --> AVL
    PAGE --> BUDDY
    FAULT --> MMU_HAL
    KERNEL_MAP --> MMU_HAL
    MMU_HAL --> CPU_HAL
```

### Component Relationships

| Component | File(s) | Role |
|-----------|---------|------|
| **Small Memory** | `src/mem.c` | dlmalloc-like best-fit heap allocator for small systems |
| **Slab Allocator** | `src/slab.c` | Object-caching allocator for frequent same-size allocations |
| **Memory Heap** | `src/memheap.c` | Multiple independent heap regions with mutex protection |
| **Memory Pool** | `src/mempool.c` | Fixed-size block allocator with thread suspension |
| **Address Space** | `components/mm/mm_aspace.c/h` | Virtual address space management (MMU mode) |
| **Virtual Memory Area** | `components/mm/mm_aspace.h` | Contiguous virtual memory region descriptor |
| **Page Allocator** | `components/mm/mm_page.c/h` | Buddy system physical page allocator |
| **Page Fault Handler** | `components/mm/mm_fault.c/h` | MMU page fault resolution |
| **Kernel Memory Map** | `components/mm/mm_kmem.c` | Kernel virtual-to-physical mapping |
| **Memory Object** | `components/mm/mm_object.c` | Default page fault handler (dummy mapper) |
| **I/O Remap** | `components/mm/ioremap.c/h` | I/O memory remapping |
| **AVL Adapter** | `components/mm/avl_adpt.c/h` | AVL tree wrapper for varea management |
| **MM Flags** | `components/mm/mm_flag.h` | Memory mapping flag definitions |

---

## 1. Kernel Heap Allocators

RT-Thread provides four distinct heap allocation algorithms, selectable at compile time via Kconfig options. The system heap (`rt_malloc`/`rt_free`) is backed by one of these algorithms.

### 1.1 Small Memory Manager (`RT_USING_SMALL_MEM`)

The small memory manager is a dlmalloc-derived best-fit allocator, suitable for resource-constrained MCU systems.

```mermaid
classDiagram
    class rt_memory {
        +rt_object parent
        +const char* algorithm
        +rt_ubase_t address
        +rt_size_t total
        +rt_size_t used
        +rt_size_t max
    }

    class rt_small_mem {
        +rt_memory parent
        +rt_uint8_t* heap_ptr
        +rt_small_mem_item* heap_end
        +rt_small_mem_item* lfree
        +rt_size_t mem_size_aligned
    }

    class rt_small_mem_item {
        +rt_ubase_t pool_ptr
        +rt_size_t next
        +rt_size_t prev
    }

    rt_small_mem --|> rt_memory : inherits
    rt_small_mem --> rt_small_mem_item : manages
```

**Key Characteristics:**
- **Algorithm**: Best-fit with immediate coalescing on free (`plug_holes()`)
- **Minimum block size**: 12 bytes (32-bit) / 24 bytes (64-bit)
- **Overhead**: One `rt_small_mem_item` header per allocated block (2 pointers + 1 flag)
- **Magic number**: `0x1ea0` for integrity checking
- **Memory tracing**: Optional thread name tracking per allocation (`RT_USING_MEMTRACE`)

**Key APIs:**
- `rt_smem_init()` / `rt_smem_detach()`: Initialize/detach a small memory heap
- `rt_smem_alloc()`: Allocate a block (best-fit search from `lfree`)
- `rt_smem_free()`: Free a block with coalescing
- `rt_smem_realloc()`: Resize an allocated block

**Allocation Flow:**
```mermaid
flowchart TD
    A[rt_smem_alloc size] --> B[Align size to RT_ALIGN_SIZE]
    B --> C{size smaller than MIN_SIZE?}
    C -->|Yes| D[Set size = MIN_SIZE_ALIGNED]
    C -->|No| E{size greater than mem_size_aligned?}
    E -->|Yes| F[Return NULL]
    E -->|No| G[Search from lfree]
    G --> H{Found free block with enough space?}
    H -->|No| I[Return NULL]
    H -->|Yes| J{Can split? free_size >= size + header + min}
    J -->|Yes| K[Split block, create new free block]
    J -->|No| L[Use entire block]
    K --> M[Update used/max stats]
    L --> M
    M --> N[Mark block as used]
    N --> O[Update lfree if needed]
    O --> P[Return data pointer]
```

### 1.2 Slab Allocator (`RT_USING_SLAB`)

The slab allocator is derived from the DragonFly BSD kernel and is optimized for frequent allocation and deallocation of objects of similar sizes. It reduces fragmentation by grouping objects into zones.

```mermaid
classDiagram
    class rt_slab {
        +rt_memory parent
        +rt_ubase_t heap_start
        +rt_ubase_t heap_end
        +rt_slab_memusage* memusage
        +rt_slab_zone* zone_array[72]
        +rt_slab_zone* zone_free
        +rt_uint32_t zone_free_cnt
        +rt_uint32_t zone_size
        +rt_uint32_t zone_limit
        +rt_uint32_t zone_page_cnt
        +rt_slab_page* page_list
    }

    class rt_slab_zone {
        +rt_uint32_t z_magic
        +rt_uint32_t z_nfree
        +rt_uint32_t z_nmax
        +rt_slab_zone* z_next
        +rt_uint8_t* z_baseptr
        +rt_uint32_t z_uindex
        +rt_uint32_t z_chunksize
        +rt_uint32_t z_zoneindex
        +rt_slab_chunk* z_freechunk
    }

    class rt_slab_chunk {
        +rt_slab_chunk* c_next
    }

    class rt_slab_memusage {
        +rt_uint32_t type: 2
        +rt_uint32_t size: 30
    }

    class rt_slab_page {
        +rt_slab_page* next
        +rt_size_t page
    }

    rt_slab --> rt_slab_zone : zone_array[]
    rt_slab --> rt_slab_memusage : memusage[]
    rt_slab --> rt_slab_page : page_list
    rt_slab_zone --> rt_slab_chunk : z_freechunk
```

**Zone Size Classes (72 zones total):**

| Size Range | Chunk Size | Number of Zones |
|------------|------------|-----------------|
| 0–127 | 8 | 16 |
| 128–255 | 16 | 8 |
| 256–511 | 32 | 8 |
| 512–1023 | 64 | 8 |
| 1024–2047 | 128 | 8 |
| 2048–4095 | 256 | 8 |
| 4096–8191 | 512 | 8 |
| 8192–16383 | 1024 | 8 |

**Key Characteristics:**
- **Zone size**: Auto-tuned between 32KB and 128KB based on heap size
- **Zone limit**: Allocations >= zone_limit (max 16KB) go directly to page allocator
- **Page types**: `PAGE_TYPE_FREE` (0x00), `PAGE_TYPE_SMALL` (0x01), `PAGE_TYPE_LARGE` (0x02)
- **Per-page metadata**: `rt_slab_memusage` array tracks page type and allocation size
- **Page allocator**: Embedded buddy-like allocator for slab pages

**Key APIs:**
- `rt_slab_init()` / `rt_slab_detach()`: Initialize/detach a slab heap
- `rt_slab_alloc()`: Allocate from slab (zone-based for small, page-based for large)
- `rt_slab_free()`: Free memory back to slab
- `rt_slab_realloc()`: Resize an allocation
- `rt_slab_page_alloc()` / `rt_slab_page_free()`: Low-level page allocation

### 1.3 Memory Heap (`RT_USING_MEMHEAP`)

The memory heap manager supports multiple independent heap regions, each protected by a semaphore for thread safety.

```mermaid
classDiagram
    class rt_memheap {
        +rt_object parent
        +void* start_addr
        +rt_size_t pool_size
        +rt_size_t available_size
        +rt_size_t max_used_size
        +rt_memheap_item* block_list
        +rt_memheap_item* free_list
        +rt_memheap_item free_header
        +rt_semaphore lock
        +rt_bool_t locked
    }

    class rt_memheap_item {
        +rt_uint32_t magic
        +rt_memheap* pool_ptr
        +rt_memheap_item* next
        +rt_memheap_item* prev
        +rt_memheap_item* next_free
        +rt_memheap_item* prev_free
    }

    rt_memheap --> rt_memheap_item : manages
    rt_memheap_item --> rt_memheap : pool_ptr
```

**Key Characteristics:**
- **Magic number**: `0x1ea01ea0` for integrity checking
- **Free list**: Doubly linked list of free blocks with header sentinel
- **Block list**: Doubly linked list of all blocks (used + free)
- **Splitting**: Blocks are split when remaining space >= header + minimum allocation
- **Coalescing**: Adjacent free blocks are merged during free
- **Thread safety**: Semaphore-based locking with external lock support

**Key APIs:**
- `rt_memheap_init()` / `rt_memheap_detach()`: Initialize/detach a memheap
- `rt_memheap_alloc()`: Allocate from a specific heap
- `rt_memheap_free()`: Free to a specific heap
- `rt_memheap_realloc()`: Resize an allocation (can expand into adjacent free space)

### 1.4 Memory Pool (`RT_USING_MEMPOOL`)

The memory pool provides fixed-size block allocation with thread suspension support.

```mermaid
classDiagram
    class rt_mempool {
        +rt_object parent
        +void* start_address
        +rt_size_t size
        +rt_size_t block_size
        +rt_uint8_t* block_list
        +rt_size_t block_total_count
        +rt_size_t block_free_count
        +rt_list_t suspend_thread
    }

    rt_mempool --> rt_list_t : suspend_thread
```

**Key Characteristics:**
- **Fixed block size**: All blocks are identical size (aligned to `RT_ALIGN_SIZE`)
- **Free list**: Singly linked list embedded in free blocks (each free block stores pointer to next)
- **Thread suspension**: Threads waiting for a block are suspended on `suspend_thread` list
- **Timeout support**: Configurable wait time via `rt_mp_alloc(time)`
- **Static/Dynamic**: Can be statically initialized (`rt_mp_init`) or dynamically created (`rt_mp_create`)

**Key APIs:**
- `rt_mp_init()` / `rt_mp_detach()`: Static initialization/detachment
- `rt_mp_create()` / `rt_mp_delete()`: Dynamic creation/deletion (heap-backed)
- `rt_mp_alloc()`: Allocate a block (with timeout)
- `rt_mp_free()`: Return a block to the pool

---

## 2. Virtual Memory Management (MMU Mode)

The virtual memory management subsystem is used in RT-Thread Smart to provide process isolation through MMU-based virtual addressing. It manages address spaces, virtual memory areas (vareas), physical page frames, and page faults.

### 2.1 Address Space (`rt_aspace`)

An address space represents a virtual address range with an associated page table. The kernel has its own address space (`rt_kernel_space`), and each user process has its own.

```c
struct rt_aspace
{
    void *start;                    // Start of virtual address range
    rt_size_t size;                 // Size of virtual address range
    void *page_table;               // MMU page table pointer
    mm_spinlock pgtbl_lock;         // Page table lock
    struct _aspace_tree tree;       // AVL tree of vareas
    struct rt_mutex bst_lock;       // BST (AVL tree) lock
    rt_uint64_t asid;               // Address Space ID
};
```

**Key APIs:**
- `rt_aspace_create()` / `rt_aspace_init()`: Create/initialize an address space
- `rt_aspace_delete()` / `rt_aspace_detach()`: Delete/detach an address space
- `rt_aspace_map()`: Map a memory object into the address space
- `rt_aspace_map_phy()`: Map physical memory into the address space
- `rt_aspace_unmap()`: Remove mappings in a range
- `rt_aspace_control()`: Change MMU attributes of a mapping
- `rt_aspace_load_page()` / `rt_aspace_offload_page()`: Load/offload pages
- `rt_aspace_traversal()`: Traverse all vareas in an address space

### 2.2 Virtual Memory Area (`rt_varea`)

A varea represents a contiguous virtual memory region within an address space. It is the fundamental unit of memory mapping.

```c
struct rt_varea
{
    void *start;                    // Start virtual address
    rt_size_t size;                 // Size of the region
    rt_size_t offset;               // Offset within backing store (in pages)
    rt_size_t attr;                 // MMU attributes (cache, read/write, etc.)
    rt_size_t flag;                 // Mapping flags (MMF_*)
    struct rt_aspace *aspace;       // Parent address space
    struct rt_mem_obj *mem_obj;     // Backing memory object
    struct _aspace_node node;       // AVL tree node (embedded)
    struct rt_page *frames;         // Allocated page frames
    void *data;                     // Private data
};
```

**Varea Flags (`mm_flag.h`):**

| Flag | Description |
|------|-------------|
| `MMF_MAP_PRIVATE` | Private mapping (COW potential) |
| `MMF_COW` | Copy-on-Write mapping |
| `MMF_MAP_FIXED` | Fixed address mapping (POSIX MAP_FIXED) |
| `MMF_PREFETCH` | Pre-allocate and map pages immediately |
| `MMF_HUGEPAGE` | Use huge pages if available |
| `MMF_TEXT` | Text (code) segment mapping |
| `MMF_STATIC_ALLOC` | Statically allocated varea (no free on uninstall) |
| `MMF_NONLOCKED` | Pages can be swapped out (reserved for future) |
| `MMF_REQUEST_ALIGN` | Request specific alignment for the mapping |

### 2.3 Memory Object (`rt_mem_obj`)

A memory object defines the behavior of a varea through callback functions. It acts as a backing store interface.

```c
struct rt_mem_obj
{
    void (*hint_free)(rt_mm_va_hint_t hint);           // Modify mapping hint
    void (*on_page_fault)(struct rt_varea *varea,      // Handle page fault
                          struct rt_aspace_fault_msg *msg);
    void (*on_varea_open)(struct rt_varea *varea);     // Varea opened
    void (*on_varea_close)(struct rt_varea *varea);    // Varea closed
    void (*on_page_offload)(struct rt_varea *varea,    // Offload pages
                            void *vaddr, rt_size_t size);
    const char *(*get_name)(rt_varea_t varea);         // Get varea name
};
```

**Built-in Memory Objects:**

| Object | Description |
|--------|-------------|
| `rt_mm_dummy_mapper` | Default mapper: allocates pages on fault, frees on close |
| `mm_page_mapper` | Master Page Record mapper: handles MPR page faults |

### 2.4 Page Allocator (Buddy System)

The page allocator uses a **buddy system** algorithm to manage physical page frames. It maintains two sets of free lists: one for low memory (below 4GB) and one for high memory (above 4GB).

```mermaid
graph TD
    subgraph "Page Allocator Structure"
        PL_LOW[page_list_low<br/>RT_PAGE_MAX_ORDER lists]
        PL_HIGH[page_list_high<br/>RT_PAGE_MAX_ORDER lists]
        MPR[Master Page Record<br/>rt_page array]
    end

    subgraph "Buddy System"
        ORDER_0[Order 0: 4KB pages]
        ORDER_1[Order 1: 8KB pages]
        ORDER_2[Order 2: 16KB pages]
        ORDER_N[Order N: 2^N * 4KB pages]
    end

    subgraph "Page Structure"
        PG[rt_page]
        PG_NEXT[+ next]
        PG_PRE[+ pre]
        PG_SIZE[+ size_bits]
        PG_REF[+ ref_cnt]
    end

    PL_LOW --> ORDER_0
    PL_LOW --> ORDER_1
    PL_LOW --> ORDER_2
    PL_LOW --> ORDER_N
    PL_HIGH --> ORDER_0
    PL_HIGH --> ORDER_1
    PL_HIGH --> ORDER_2
    PL_HIGH --> ORDER_N
    ORDER_0 --> PG
    PG --> PG_NEXT
    PG --> PG_PRE
    PG --> PG_SIZE
    PG --> PG_REF
```

**Key Characteristics:**
- **Page size**: 4KB (`ARCH_PAGE_SIZE`)
- **Maximum order**: `RT_PAGE_MAX_ORDER` (typically 11, supporting up to 8MB contiguous allocation)
- **Master Page Record (MPR)**: A contiguous array of `rt_page` structures, one per physical page frame
- **Dual lists**: Separate free lists for low (≤4GB) and high (>4GB) physical memory
- **Reference counting**: Each page group has a reference count for shared mappings
- **Page leak tracing**: Optional debug feature to track unfreed pages

**Key APIs:**
- `rt_page_init()`: Initialize the page allocator with a memory region
- `rt_page_install()`: Install additional page frames at runtime
- `rt_pages_alloc()` / `rt_pages_alloc_ext()`: Allocate contiguous pages
- `rt_pages_free()`: Free pages (decrements ref count, returns to buddy on zero)
- `rt_page_ref_inc()` / `rt_page_ref_get()`: Increment/get page reference count
- `rt_page_addr2page()` / `rt_page_page2addr()`: Convert between page struct and address
- `rt_page_bits()`: Calculate order bits for a given size

**Allocation Flow:**
```mermaid
flowchart TD
    A[rt_pages_alloc size_bits] --> B[Select page list low or high]
    B --> C[Disable interrupts]
    C --> D{Free block at requested order?}
    D -->|Yes| E[Remove from free list]
    D -->|No| F[Search higher orders]
    F --> G{Found at higher order?}
    G -->|No| H[Fall back to low list]
    H --> I{Found?}
    I -->|No| J[Return NULL]
    I -->|Yes| K[Split block down to requested order]
    G -->|Yes| K
    E --> L[Set size_bits = ALLOCATED]
    K --> L
    L --> M[Set ref_cnt = 1]
    M --> N[Enable interrupts]
    N --> O[Return page address]
```

### 2.5 Page Fault Handling

The page fault handler resolves MMU page faults by delegating to the varea's memory object.

```c
struct rt_aspace_fault_msg
{
    enum rt_mm_fault_op fault_op;       // READ, WRITE, or EXECUTE
    enum rt_mm_fault_type fault_type;   // ACCESS_FAULT, PAGE_FAULT, BUS_ERROR
    rt_size_t off;                      // Offset within backing store
    void *fault_vaddr;                  // Faulting virtual address
    struct rt_mm_fault_res response;    // Response from handler
};

struct rt_mm_fault_res
{
    void *vaddr;                        // Physical/virtual address of resolved page
    rt_size_t size;                     // Size of resolved region
    int status;                         // MM_FAULT_STATUS_OK, OK_MAPPED, or UNRECOVERABLE
};
```

**Fault Resolution Flow:**
```mermaid
flowchart TD
    A[Page Fault Occurs] --> B[rt_aspace_fault_try_fix]
    B --> C[Search AVL tree for varea<br/>containing fault address]
    C --> D{Varea found?}
    D -->|No| E[Return UNRECOVERABLE]
    D -->|Yes| F[Calculate offset within varea]
    F --> G[Call mem_obj->on_page_fault]
    G --> H{Response status?}
    H -->|MM_FAULT_STATUS_OK| I[Map provided page frame<br/>into page table]
    H -->|MM_FAULT_STATUS_OK_MAPPED| J[Handler already mapped page]
    H -->|MM_FAULT_STATUS_UNRECOVERABLE| K[Return error]
    I --> L[Invalidate TLB]
    J --> L
    L --> M[Return success]
```

### 2.6 Kernel Memory Mapping

The kernel memory mapping subsystem manages the kernel's virtual address space (`rt_kernel_space`).

**Key APIs:**
- `rt_kmem_pvoff()` / `rt_kmem_pvoff_set()`: Get/set the physical-to-virtual offset
- `rt_kmem_map_phy()`: Map physical memory into kernel space
- `rt_kmem_v2p()`: Convert kernel virtual address to physical address
- `rt_kmem_list()`: List all vareas in kernel space (Finsh command: `list_kmem`)

---

## 3. Data Flow and Usage Patterns

### 3.1 Kernel Heap Allocation Flow

```mermaid
sequenceDiagram
    participant App as Application
    participant API as rt_malloc(size)
    participant Heap as Heap Allocator
    participant Page as Page Allocator

    App->>API: rt_malloc(1024)
    API->>Heap: rt_smem_alloc / rt_slab_alloc / rt_memheap_alloc
    Heap->>Heap: Search free list for best-fit block
    Heap->>Heap: Split block if large enough
    Heap-->>API: Return data pointer
    API-->>App: Allocated memory

    App->>API: rt_free(ptr)
    API->>Heap: rt_smem_free / rt_slab_free / rt_memheap_free
    Heap->>Heap: Mark block as free
    Heap->>Heap: Coalesce with adjacent free blocks
    Heap-->>API: OK
    API-->>App: Memory freed
```

### 3.2 Virtual Memory Mapping Flow

```mermaid
sequenceDiagram
    participant App as Application
    participant LWP as LWP Manager
    participant ASPACE as Address Space
    participant AVL as AVL Tree
    participant MMU as MMU HAL
    participant PAGE as Page Allocator

    App->>LWP: mmap(addr, length, ...)
    LWP->>ASPACE: rt_aspace_map(aspace, &addr, length, attr, flags, mem_obj, offset)
    ASPACE->>AVL: _aspace_bst_search_overlap(range)
    AVL-->>ASPACE: No overlap
    ASPACE->>AVL: _aspace_bst_insert(varea)
    AVL-->>ASPACE: OK
    ASPACE-->>LWP: Mapped address
    LWP-->>App: mmap returns address

    Note over App: Later, page fault occurs on access

    App->>MMU: Access mapped address
    MMU->>ASPACE: Page fault
    ASPACE->>AVL: _aspace_bst_search(fault_addr)
    AVL-->>ASPACE: varea
    ASPACE->>PAGE: rt_pages_alloc(0)
    PAGE-->>ASPACE: New page frame
    ASPACE->>MMU: rt_hw_mmu_map(aspace, vaddr, paddr, size, attr)
    MMU-->>ASPACE: Mapped
    ASPACE->>MMU: rt_hw_tlb_invalidate
    MMU-->>App: Fault resolved, retry instruction
```

### 3.3 Page Fault Resolution Flow

```mermaid
sequenceDiagram
    participant CPU as CPU/MMU
    participant FAULT as Fault Handler
    participant ASPACE as Address Space
    participant VAREA as Varea
    participant MEMOBJ as Memory Object
    participant PAGE as Page Allocator

    CPU->>FAULT: Page fault exception
    FAULT->>ASPACE: rt_aspace_fault_try_fix(&msg)
    ASPACE->>ASPACE: Search AVL tree for varea
    ASPACE-->>FAULT: Found varea
    FAULT->>VAREA: Calculate offset
    FAULT->>MEMOBJ: on_page_fault(varea, &msg)
    MEMOBJ->>PAGE: rt_pages_alloc_ext(0, PAGE_ANY_AVAILABLE)
    PAGE-->>MEMOBJ: New page frame
    MEMOBJ->>MEMOBJ: Zero page (if needed)
    MEMOBJ-->>FAULT: MM_FAULT_STATUS_OK
    FAULT->>FAULT: Map page into page table
    FAULT->>CPU: Invalidate TLB
    CPU-->>CPU: Retry faulting instruction
```

---

## 4. Integration with Other Modules

### 4.1 LWP (Light Weight Process)

The LWP module is the primary consumer of the virtual memory management subsystem. Each user process has its own address space (`lwp->aspace`) and uses the MM APIs for:
- **Process creation**: `lwp_user_space_init()` creates and initializes the address space
- **ELF loading**: `load_elf()` maps text and data segments using `rt_aspace_map()`
- **Heap management**: `lwp_brk()` extends the process heap
- **Memory mapping**: `lwp_mmap2()` / `lwp_munmap()` implement POSIX mmap/munmap
- **Shared memory**: `lwp_shm.c` uses the page allocator for shared memory segments
- **Copy-on-Write**: Page faults on private mappings trigger COW handling

For more details, see [LWP (Light Weight Process)](LWP%20%28Light%20Weight%20Process%29.md).

### 4.2 AVL Tree

The AVL tree (`util_avl`) is the core data structure for organizing vareas within an address space. The `avl_adpt.c/h` adapter provides BST operations (search, insert, remove) specifically tailored for address space management.

For more details, see [AVL Tree](AVL%20Tree.md).

### 4.3 VMM (Virtual Machine Manager)

The VMM module uses the MM subsystem for managing guest physical memory and I/O mappings.

For more details, see [VMM (Virtual Machine Manager)](VMM%20%28Virtual%20Machine%20Manager%29.md).

### 4.4 Device Drivers

Device drivers use the kernel heap allocators (`rt_malloc`/`rt_free`) for dynamic memory allocation, and the I/O remap functions (`ioremap.h`) for mapping device memory into the kernel address space.

---

## 5. Configuration Options

The memory management subsystem is highly configurable via Kconfig:

| Option | Description | Default |
|--------|-------------|---------|
| `RT_USING_HEAP` | Enable heap allocators | Enabled |
| `RT_USING_SMALL_MEM` | Small memory manager | Enabled (if no SLAB) |
| `RT_USING_SLAB` | Slab allocator | Disabled |
| `RT_USING_MEMHEAP` | Multiple memory heaps | Disabled |
| `RT_USING_MEMPOOL` | Memory pool support | Disabled |
| `RT_USING_MEMTRACE` | Memory allocation tracing | Disabled |
| `RT_MM_PAGE_SIZE` | Page size (4096) | 4096 |
| `RT_PAGE_MAX_ORDER` | Maximum buddy order | 11 |
| `RT_KERNEL_MALLOC` | Custom kernel malloc macro | `rt_malloc` |
| `RT_KERNEL_FREE` | Custom kernel free macro | `rt_free` |

---

## 6. Performance Considerations

### Heap Allocator Comparison

| Allocator | Best For | Fragmentation | Speed | Overhead |
|-----------|----------|---------------|-------|----------|
| **Small Memory** | General purpose, small systems | Medium (best-fit) | Medium | Low (12-24 bytes/block) |
| **Slab** | Frequent same-size allocations | Low (zone-based) | Fast | Medium (zone headers) |
| **MemHeap** | Multiple independent heaps | Medium | Medium | Low (header per block) |
| **MemPool** | Fixed-size blocks, real-time | None | Very fast | Low (1 pointer/block) |

### Virtual Memory Performance Tips

1. **Use `MMF_PREFETCH`** for performance-critical mappings to avoid page fault latency
2. **Use huge pages** (`MMF_HUGEPAGE`) for large contiguous mappings to reduce TLB pressure
3. **Minimize TLB invalidations** by batching operations when possible
4. **Use `rt_aspace_map_static()`** when the varea is pre-allocated to avoid malloc overhead
5. **The buddy allocator** provides O(log n) allocation and O(1) free for power-of-2 sizes

---

## 7. Debugging and Diagnostics

### Finsh Commands

| Command | Description |
|---------|-------------|
| `list_mem` | List memory usage statistics |
| `list_memheap` | List all memheap objects |
| `list_page` | List free page frames by order |
| `list_kmem` | List kernel virtual memory areas |
| `rt_page_leak_trace_start` | Start page leak tracing |
| `rt_page_leak_trace_stop` | Stop page leak tracing and report leaks |

### Memory Statistics

The `rt_memory` base structure tracks:
- `total`: Total managed memory size
- `used`: Currently allocated memory
- `max`: Peak memory usage (high watermark)

---

## 8. Related Documentation

- [RT-Thread Kernel](RT-Thread%20Kernel.md) — Core kernel types and infrastructure
- [LWP (Light Weight Process)](LWP%20%28Light%20Weight%20Process%29.md) — Process-level memory management
- [AVL Tree](AVL%20Tree.md) — Data structure for varea organization
- [VMM (Virtual Machine Manager)](VMM%20%28Virtual%20Machine%20Manager%29.md) — Virtual machine memory management
- [FAL (Flash Abstraction Layer)](FAL%20%28Flash%20Abstraction%20Layer%29.md) — Flash memory abstraction
