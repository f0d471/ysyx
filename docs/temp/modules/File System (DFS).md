# File System (DFS)

## Introduction

The Device File System (DFS) module is the virtual file system (VFS) layer of the RT-Thread operating system. It provides a **POSIX-compliant** file system abstraction that allows applications to interact with various underlying file systems and storage devices through a unified API. DFS acts as an intermediary between user applications and the actual file system implementations, enabling multiple file system types to coexist under a single mount hierarchy.

DFS supports two versions:
- **DFS v1**: The legacy version (located in `components/dfs/dfs_v1/`)
- **DFS v2**: The current, actively maintained version (located in `components/dfs/dfs_v2/`)

This documentation covers **DFS v2**, which is the recommended version for new designs.

---

## Architecture Overview

DFS follows a layered architecture with clear separation of concerns:

```mermaid
graph TB
    subgraph "User Space / POSIX API Layer"
        POSIX["POSIX APIs<br/>open, read, write, close,<br/>stat, mkdir, opendir, etc."]
    end

    subgraph "DFS Core (VFS Layer)"
        DFS_CORE["dfs.c / dfs_fs.c / dfs_file.c<br/>Core VFS Management"]
        FDT["File Descriptor Table<br/>fdtable management"]
        VNODE["Virtual Node (vnode)<br/>Hash table management"]
        FS_TBL["Filesystem Table<br/>Mount point management"]
        OPS_TBL["Filesystem Operation Table<br/>Registered filesystem types"]
    end

    subgraph "Filesystem Implementations"
        ROMFS["ROMFS<br/>Read-Only Memory FS"]
        RAMFS["RAMFS<br/>RAM-based FS"]
        TMPFS["TMPFS<br/>Temporary FS"]
        DEVFS["DEVFS<br/>Device FS"]
        ELMFAT["elmFAT<br/>FAT12/16/32"]
        NFS["NFS v3<br/>Network FS"]
        CROMFS["CROMFS<br/>Compressed ROMFS"]
    end

    subgraph "Device Driver Layer"
        BLKDEV["Block Devices<br/>SD/MMC, USB, MTD, etc."]
    end

    subgraph "Hardware Layer"
        HW["Physical Storage<br/>Flash, SD Card, Disk, etc."]
    end

    POSIX --> DFS_CORE
    DFS_CORE --> FDT
    DFS_CORE --> VNODE
    DFS_CORE --> FS_TBL
    DFS_CORE --> OPS_TBL
    OPS_TBL --> ROMFS
    OPS_TBL --> RAMFS
    OPS_TBL --> TMPFS
    OPS_TBL --> DEVFS
    OPS_TBL --> ELMFAT
    OPS_TBL --> NFS
    OPS_TBL --> CROMFS
    ELMFAT --> BLKDEV
    BLKDEV --> HW
```

---

## Core Data Structures

### 1. File Descriptor Table (`dfs_fdtable`)

The file descriptor table manages all open file descriptors for a process. In RT-Thread's Smart mode (with LWP support), each process has its own fdtable; otherwise, a global fdtable is used.

```c
struct dfs_fdtable
{
    uint32_t maxfd;           /* Maximum number of file descriptors */
    struct dfs_file **fds;    /* Array of file descriptor pointers */
};
```

### 2. Virtual Node (`dfs_vnode`)

The vnode (virtual node) is the core abstraction representing an open file or directory within the VFS layer. Vnodes are cached in a hash table for efficient lookup.

```c
struct dfs_vnode
{
    uint16_t type;                      /* Type: FT_REGULAR, FT_DIRECTORY, FT_DEVICE, etc. */
    char *path;                         /* Path below mount point */
    char *fullpath;                     /* Full absolute path (hash key) */
    int ref_count;                      /* Reference count */
    rt_list_t list;                     /* Hash table linked list node */
    struct dfs_filesystem *fs;          /* Pointer to mounted filesystem */
    const struct dfs_file_ops *fops;    /* File operations for this vnode */
    uint32_t flags;                     /* Self flags */
    size_t size;                        /* File size in bytes */
    void *data;                         /* Filesystem-specific private data */
};
```

### 3. File Descriptor (`dfs_file`)

Represents an open file instance, holding the current state (position, flags) and a reference to its vnode.

```c
struct dfs_file
{
    uint16_t magic;              /* Magic number (DFS_FD_MAGIC = 0xfdfd) */
    uint32_t flags;              /* Descriptor flags (open, directory, EOF, error) */
    int ref_count;               /* Reference count */
    off_t pos;                   /* Current file position */
    struct dfs_vnode *vnode;     /* Associated vnode */
    void *data;                  /* FD-specific private data */
};
```

### 4. File Operations (`dfs_file_ops`)

The file operations structure defines the interface that each filesystem must implement for file-level operations.

```c
struct dfs_file_ops
{
    int (*open)     (struct dfs_file *fd);
    int (*close)    (struct dfs_file *fd);
    int (*ioctl)    (struct dfs_file *fd, int cmd, void *args);
    int (*read)     (struct dfs_file *fd, void *buf, size_t count);
    int (*write)    (struct dfs_file *fd, const void *buf, size_t count);
    int (*flush)    (struct dfs_file *fd);
    int (*lseek)    (struct dfs_file *fd, off_t offset);
    int (*getdents) (struct dfs_file *fd, struct dirent *dirp, uint32_t count);
    int (*poll)     (struct dfs_file *fd, struct rt_pollreq *req);
};
```

### 5. Filesystem Operations (`dfs_filesystem_ops`)

Defines the interface for registering, mounting, and managing a filesystem type.

```c
struct dfs_filesystem_ops
{
    char *name;                          /* Filesystem name (e.g., "elm", "rom", "devfs") */
    uint32_t flags;                      /* Flags (e.g., DFS_FS_FLAG_FULLPATH) */
    const struct dfs_file_ops *fops;     /* File operations for this filesystem */

    int (*mount)    (struct dfs_filesystem *fs, unsigned long rwflag, const void *data);
    int (*unmount)  (struct dfs_filesystem *fs);
    int (*mkfs)     (rt_device_t dev_id, const char *fs_name);
    int (*statfs)   (struct dfs_filesystem *fs, struct statfs *buf);
    int (*unlink)   (struct dfs_filesystem *fs, const char *pathname);
    int (*stat)     (struct dfs_filesystem *fs, const char *filename, struct stat *buf);
    int (*rename)   (struct dfs_filesystem *fs, const char *oldpath, const char *newpath);
};
```

### 6. Mounted Filesystem (`dfs_filesystem`)

Represents a mounted filesystem instance, binding a device to a mount point.

```c
struct dfs_filesystem
{
    rt_device_t dev_id;                         /* Attached block device */
    char *path;                                 /* Mount point path */
    const struct dfs_filesystem_ops *ops;       /* Filesystem operations */
    void *data;                                 /* Filesystem-specific data */
};
```

### 7. Partition Table (`dfs_partition`)

Used for parsing MBR partition tables on block devices.

```c
struct dfs_partition
{
    uint8_t type;        /* Partition type */
    off_t  offset;       /* Partition start offset (in sectors) */
    size_t size;         /* Partition size (in sectors) */
    rt_sem_t lock;
};
```

### 8. Mount Table (`dfs_mount_tbl`)

Used for automatic mounting of filesystems during system initialization.

```c
struct dfs_mount_tbl
{
    const char   *device_name;
    const char   *path;
    const char   *filesystemtype;
    unsigned long rwflag;
    const void   *data;
};
```

### 9. Memory-Mapped I/O Arguments (`dfs_mmap2_args`)

```c
struct dfs_mmap2_args
{
    void *addr;
    size_t length;
    int prot;
    int flags;
    off_t pgoffset;
    void *ret;
};
```

---

## Class Diagram

```mermaid
classDiagram
    class dfs_fdtable {
        +uint32_t maxfd
        +struct dfs_file** fds
    }

    class dfs_file {
        +uint16_t magic
        +uint32_t flags
        +int ref_count
        +off_t pos
        +struct dfs_vnode* vnode
        +void* data
    }

    class dfs_vnode {
        +uint16_t type
        +char* path
        +char* fullpath
        +int ref_count
        +rt_list_t list
        +struct dfs_filesystem* fs
        +const struct dfs_file_ops* fops
        +uint32_t flags
        +size_t size
        +void* data
    }

    class dfs_filesystem {
        +rt_device_t dev_id
        +char* path
        +const struct dfs_filesystem_ops* ops
        +void* data
    }

    class dfs_filesystem_ops {
        +char* name
        +uint32_t flags
        +const struct dfs_file_ops* fops
        +mount()
        +unmount()
        +mkfs()
        +statfs()
        +unlink()
        +stat()
        +rename()
    }

    class dfs_file_ops {
        +open()
        +close()
        +ioctl()
        +read()
        +write()
        +flush()
        +lseek()
        +getdents()
        +poll()
    }

    class dfs_partition {
        +uint8_t type
        +off_t offset
        +size_t size
        +rt_sem_t lock
    }

    class dfs_mount_tbl {
        +const char* device_name
        +const char* path
        +const char* filesystemtype
        +unsigned long rwflag
        +const void* data
    }

    class dfs_vnode_mgr {
        +struct rt_mutex lock
        +rt_list_t head[128]
        +bkdr_hash()
        +dfs_vnode_find()
    }

    dfs_fdtable --> dfs_file : manages
    dfs_file --> dfs_vnode : references
    dfs_vnode --> dfs_filesystem : belongs to
    dfs_vnode --> dfs_file_ops : uses
    dfs_filesystem --> dfs_filesystem_ops : uses
    dfs_filesystem_ops --> dfs_file_ops : contains
    dfs_vnode_mgr --> dfs_vnode : caches
```

---

## Data Flow

### File Open Flow

```mermaid
sequenceDiagram
    participant APP as Application
    participant POSIX as POSIX API (open)
    participant DFS as DFS Core
    participant VNODE as Vnode Manager
    participant FS as Filesystem
    participant DEV as Block Device

    APP->>POSIX: open("/path/file", O_RDONLY)
    POSIX->>DFS: fd_new() - allocate fd
    POSIX->>DFS: dfs_file_open(fd, path, flags)
    DFS->>DFS: dfs_normalize_path() - resolve absolute path
    DFS->>VNODE: dfs_vnode_find(fullpath) - check cache
    alt Vnode found in cache
        VNODE-->>DFS: vnode (ref_count++)
    else Vnode not found
        DFS->>FS: dfs_filesystem_lookup(fullpath) - find mounted FS
        FS-->>DFS: filesystem
        DFS->>DFS: rt_calloc() - allocate new vnode
        DFS->>DFS: Set vnode->fs, vnode->fops
        DFS->>VNODE: rt_list_insert_after() - add to hash table
    end
    DFS->>FS: vnode->fops->open(fd) - call filesystem open
    FS->>DEV: rt_device_open() / read() (if needed)
    DEV-->>FS: data
    FS-->>DFS: result
    DFS-->>POSIX: result
    POSIX-->>APP: fd (file descriptor)
```

### File Read Flow

```mermaid
sequenceDiagram
    participant APP as Application
    participant POSIX as POSIX API (read)
    participant DFS as DFS Core
    participant FS as Filesystem

    APP->>POSIX: read(fd, buf, count)
    POSIX->>DFS: fd_get(fd) - get file struct
    DFS-->>POSIX: dfs_file*
    POSIX->>DFS: dfs_file_read(fd, buf, len)
    DFS->>FS: fd->vnode->fops->read(fd, buf, len)
    FS-->>DFS: bytes_read
    alt read < 0
        DFS->>DFS: fd->flags |= DFS_F_EOF
    end
    DFS-->>POSIX: result
    POSIX-->>APP: bytes_read
```

### File Write Flow

```mermaid
sequenceDiagram
    participant APP as Application
    participant POSIX as POSIX API (write)
    participant DFS as DFS Core
    participant FS as Filesystem
    participant DEV as Block Device

    APP->>POSIX: write(fd, buf, count)
    POSIX->>DFS: fd_get(fd)
    POSIX->>DFS: dfs_file_write(fd, buf, len)
    DFS->>FS: fd->vnode->fops->write(fd, buf, len)
    FS->>DEV: rt_device_write() (for block-based FS)
    DEV-->>FS: bytes_written
    FS-->>DFS: result
    DFS-->>POSIX: result
    POSIX-->>APP: bytes_written
```

### Mount Flow

```mermaid
sequenceDiagram
    participant APP as Application
    participant DFS as DFS Core
    participant FS_OPS as Filesystem Ops Table
    participant FS_TBL as Filesystem Table
    participant DEV as Block Device

    APP->>DFS: dfs_mount("sd0", "/", "elm", 0, NULL)
    DFS->>DFS: rt_device_find("sd0") - find device
    alt Device not found
        DFS-->>APP: -1 (ENODEV)
    end
    DFS->>FS_OPS: Search for "elm" filesystem
    alt Filesystem not registered
        DFS-->>APP: -1 (ENODEV)
    end
    DFS->>DFS: dfs_normalize_path("/") - resolve mount path
    DFS->>FS_TBL: Find empty slot
    alt No empty slot
        DFS-->>APP: -1 (ENOSPC)
    end
    DFS->>FS_TBL: Register mount (path, ops, dev_id)
    DFS->>DEV: rt_device_open(dev_id, RDWR)
    DEV-->>DFS: OK
    DFS->>FS_OPS: ops->mount(fs, rwflag, data)
    FS_OPS->>DEV: Read superblock / init FS structures
    DEV-->>FS_OPS: OK
    FS_OPS-->>DFS: 0 (success)
    DFS-->>APP: 0 (success)
```

---

## Component Interaction

### Vnode Manager (Hash Table)

The vnode manager maintains a hash table of all open vnodes, keyed by their full path. This allows efficient lookup and prevents duplicate opens of the same file.

```mermaid
graph LR
    subgraph "Vnode Hash Table (128 buckets)"
        H0["bucket[0]"]
        H1["bucket[1]"]
        H2["bucket[...]"]
        H127["bucket[127]"]
    end

    subgraph "Hash Chain Example"
        V1["vnode<br/>path=/etc/config<br/>ref_count=2"]
        V2["vnode<br/>path=/etc/hosts<br/>ref_count=1"]
    end

    subgraph "BKDR Hash Function"
        BKDR["hash = hash * 131 + char<br/>hash % 128"]
    end

    BKDR --> H1
    H1 --> V1
    V1 --> V2
```

### Filesystem Registration and Mount Table

```mermaid
graph TB
    subgraph "Filesystem Operation Table"
        FSO0["[0] elm (FAT)"]
        FSO1["[1] romfs"]
        FSO2["[2] devfs"]
        FSO3["[3] tmpfs"]
    end

    subgraph "Filesystem Table (Mount Points)"
        FST0["[0] / → elm on sd0"]
        FST1["[1] /dev → devfs"]
        FST2["[2] /tmp → tmpfs"]
        FST3["[3] (empty)"]
    end

    subgraph "Mount Table (Auto-mount)"
        MT0["sd0 / elm 0 NULL"]
        MT1["NULL /dev devfs 0 NULL"]
        MT2["NULL /tmp tmp 0 NULL"]
    end

    MT0 --> FST0
    MT1 --> FST1
    MT2 --> FST2
    FST0 --> FSO0
    FST1 --> FSO2
    FST2 --> FSO3
```

---

## Supported Filesystems

DFS v2 supports the following filesystem implementations:

| Filesystem | Name String | Type | Description |
|---|---|---|---|
| **elmFAT** | `elm` | Block-based | FAT12/16/32 filesystem (based on Chan's FAT FS) |
| **ROMFS** | `rom` | Memory-based | Read-only filesystem stored in ROM/flash |
| **RAMFS** | `ram` | Memory-based | RAM-based volatile filesystem |
| **TMPFS** | `tmp` | Memory-based | Temporary filesystem (similar to tmpfs) |
| **DEVFS** | `devfs` | Virtual | Device filesystem (exposes devices as files) |
| **NFS v3** | `nfs` | Network | Network File System v3 client |
| **CROMFS** | `cromfs` | Memory-based | Compressed ROM filesystem |

### Filesystem Characteristics

```mermaid
graph TB
    subgraph "Memory-based FS"
        ROMFS["ROMFS<br/>Read-only, stored in flash/ROM<br/>Simple directory structure"]
        RAMFS["RAMFS<br/>Volatile, RAM-backed<br/>Simple flat structure"]
        TMPFS["TMPFS<br/>Volatile, RAM-backed<br/>Full directory support"]
        CROMFS["CROMFS<br/>Compressed, read-only<br/>Efficient storage"]
    end

    subgraph "Block Device FS"
        ELMFAT["elmFAT<br/>FAT12/16/32<br/>Requires block device<br/>Widely compatible"]
    end

    subgraph "Virtual/Network FS"
        DEVFS["DEVFS<br/>Exposes devices as files<br/>No storage required"]
        NFS["NFS v3<br/>Remote file access<br/>Requires network stack"]
    end
```

---

## Key APIs

### Initialization and Configuration

| API | Description |
|---|---|
| `dfs_init()` | Initialize the DFS subsystem (vnode manager, locks, mount tables) |
| `dfs_register()` | Register a filesystem type in the operation table |
| `dfs_mount_table()` | Auto-mount all entries in the mount table (called at boot) |

### Filesystem Management

| API | Description |
|---|---|
| `dfs_mount()` | Mount a filesystem on a path |
| `dfs_unmount()` | Unmount a filesystem |
| `dfs_mkfs()` | Format a device with a filesystem |
| `dfs_statfs()` | Get filesystem statistics |
| `dfs_filesystem_lookup()` | Find the filesystem mounted at a path |
| `dfs_filesystem_get_partition()` | Parse MBR partition table |

### File Operations

| API | Description |
|---|---|
| `dfs_file_open()` | Open a file |
| `dfs_file_close()` | Close a file |
| `dfs_file_read()` | Read from a file |
| `dfs_file_write()` | Write to a file |
| `dfs_file_lseek()` | Seek to a position |
| `dfs_file_ioctl()` | I/O control operations |
| `dfs_file_flush()` | Flush file buffers |
| `dfs_file_getdents()` | Get directory entries |
| `dfs_file_stat()` | Get file status |
| `dfs_file_rename()` | Rename a file |
| `dfs_file_unlink()` | Delete a file |
| `dfs_file_ftruncate()` | Truncate a file |
| `dfs_file_mmap2()` | Memory-map a file |

### POSIX-Compatible APIs

| API | Description |
|---|---|
| `open()` / `creat()` | Open/create a file |
| `close()` | Close a file descriptor |
| `read()` / `write()` | Read/write from/to a file |
| `lseek()` | Reposition file offset |
| `stat()` / `fstat()` | Get file status |
| `unlink()` / `remove()` | Delete a file |
| `rename()` | Rename a file |
| `mkdir()` / `rmdir()` | Create/remove a directory |
| `opendir()` / `readdir()` / `closedir()` | Directory operations |
| `fcntl()` / `ioctl()` | File control operations |
| `ftruncate()` | Truncate a file |
| `fsync()` | Synchronize file data |
| `statfs()` / `fstatfs()` | Get filesystem statistics |
| `dup()` / `dup2()` | Duplicate file descriptors |

---

## Configuration Options

DFS behavior is configured through Kconfig options (see `components/dfs/Kconfig` and `components/dfs/dfs_v2/Kconfig`):

| Option | Default | Description |
|---|---|---|
| `RT_USING_DFS` | y | Enable DFS module |
| `DFS_FILESYSTEMS_MAX` | 4 | Maximum number of mounted filesystems |
| `DFS_FD_MAX` | 16 | Maximum number of open file descriptors |
| `DFS_PATH_MAX` | 256 | Maximum path length |
| `DFS_USING_WORKDIR` | y | Enable working directory support |
| `DFS_USING_POSIX` | y | Enable POSIX API wrappers |
| `RT_USING_DFS_ELMFAT` | n | Enable elmFAT filesystem |
| `RT_USING_DFS_ROMFS` | n | Enable ROMFS filesystem |
| `RT_USING_DFS_RAMFS` | n | Enable RAMFS filesystem |
| `RT_USING_DFS_TMPFS` | n | Enable TMPFS filesystem |
| `RT_USING_DFS_DEVFS` | n | Enable DEVFS filesystem |
| `RT_USING_DFS_NFS` | n | Enable NFS v3 client |
| `RT_USING_DFS_CROMFS` | n | Enable CROMFS filesystem |
| `RT_USING_DFS_MNTTABLE` | n | Enable auto-mount table support |

---

## Dependencies

DFS depends on the following RT-Thread kernel and driver components:

```mermaid
graph TB
    DFS["File System (DFS)"] --> KERNEL["RT-Thread Kernel"]
    DFS --> DEVICE["Device Driver Framework"]
    DFS --> LIBC["libc / POSIX Layer"]
    
    KERNEL --> MUTEX["rt_mutex (locking)"]
    KERNEL --> MEM["rt_malloc / rt_free (memory)"]
    KERNEL --> LIST["rt_list (linked lists)"]
    KERNEL --> THREAD["rt_thread (threading)"]
    
    DEVICE --> BLKDEV["Block Device Interface"]
    DEVICE --> RTC["RTC Device (for timestamps)"]
    
    ELMFAT --> BLKDEV
    NFS --> NET["Network Stack (lwIP)"]
    NFS --> RPC["RPC/XDR (built-in)"]
```

### Key Dependencies

- **[RT-Thread Kernel](RT-Thread%20Kernel.md)**: Core kernel services including:
  - `rt_mutex` for filesystem and fd table locking
  - `rt_malloc`/`rt_free`/`rt_calloc`/`rt_realloc` for dynamic memory allocation
  - `rt_list` for linked list management (vnode hash table)
  - `rt_device` for block device I/O
  - `rt_thread` for per-process fdtable (Smart mode)
  
- **Device Driver Framework**: Block device interface for filesystems that require persistent storage (elmFAT)

- **libc/POSIX Layer**: Provides the POSIX API wrappers and standard type definitions (`struct stat`, `struct statfs`, `struct dirent`, etc.)

---

## Internal Locking Mechanism

DFS uses three mutexes for thread-safe operation:

```mermaid
graph LR
    subgraph "Lock Hierarchy"
        FSLOCK["fslock<br/>Filesystem Table Lock<br/>dfs_lock() / dfs_unlock()"]
        FDLOCK["fdlock<br/>FD Table Lock<br/>dfs_file_lock() / dfs_file_unlock()"]
        FMLOCK["fm_lock<br/>Vnode Manager Lock<br/>dfs_fm_lock() / dfs_fm_unlock()"]
    end

    FSLOCK -->|protects| FSTBL["filesystem_table[]<br/>filesystem_operation_table[]"]
    FDLOCK -->|protects| FDTBL["_fdtab.fds[]<br/>fd allocation/release"]
    FMLOCK -->|protects| VHTBL["vnode hash table<br/>dfs_fm.head[]"]
```

---

## Error Handling

DFS uses negative errno values internally and converts them to POSIX errno for user-space APIs. Common error codes:

| Error | Description |
|---|---|
| `-ENOMEM` | Out of memory |
| `-ENOENT` | File or path not found |
| `-ENODEV` | Device or filesystem not found |
| `-ENOSYS` | Operation not supported |
| `-ENOSPC` | No space left (table full) |
| `-EBUSY` | Resource busy (file already open) |
| `-EINVAL` | Invalid argument |
| `-EXDEV` | Cross-device link (rename across filesystems) |
| `-EBADF` | Bad file descriptor |
| `-ENOTDIR` | Not a directory |

---

## Source File Structure

```
components/dfs/
├── Kconfig                          # Top-level DFS configuration
├── SConscript                       # Build script
├── dfs_v1/                          # Legacy DFS v1 (deprecated)
│   ├── include/
│   ├── src/
│   └── filesystems/
└── dfs_v2/                          # Current DFS v2
    ├── Kconfig                      # DFS v2 configuration
    ├── SConscript                   # Build script
    ├── include/
    │   ├── dfs.h                    # Core DFS definitions and APIs
    │   ├── dfs_file.h               # File and vnode structures
    │   ├── dfs_fs.h                 # Filesystem structures and mount APIs
    │   └── dfs_private.h            # Internal declarations
    ├── src/
    │   ├── dfs.c                    # Core VFS: init, fdtable, path normalization
    │   ├── dfs_file.c               # File operations: open, close, read, write, etc.
    │   ├── dfs_fs.c                 # Filesystem operations: register, mount, unmount, mkfs
    │   └── dfs_posix.c              # POSIX API wrappers: open, read, write, stat, etc.
    └── filesystems/
        ├── romfs/                   # Read-Only Memory Filesystem
        ├── ramfs/                   # RAM-based Filesystem
        ├── tmpfs/                   # Temporary Filesystem
        ├── devfs/                   # Device Filesystem
        ├── elmfat/                  # FAT12/16/32 (Chan's FAT FS)
        ├── nfs/                     # Network File System v3
        ├── cromfs/                  # Compressed ROM Filesystem
        └── skeleton/                # Template for new filesystem implementations
```

---

## How to Add a New Filesystem

DFS provides a skeleton template (`filesystems/skeleton/`) for implementing new filesystems. The steps are:

1. **Define `dfs_file_ops`**: Implement the file-level operations (open, close, read, write, etc.)
2. **Define `dfs_filesystem_ops`**: Implement the filesystem-level operations (mount, unmount, mkfs, statfs, etc.)
3. **Register the filesystem**: Call `dfs_register()` with the operations structure during initialization
4. **Mount the filesystem**: Use `dfs_mount()` to mount the filesystem on a path

```c
/* Example: Registering a new filesystem */
static const struct dfs_filesystem_ops myfs_ops =
{
    .name   = "myfs",
    .fops   = &myfs_file_ops,    /* Your file operations */
    .mount  = myfs_mount,
    .unmount = myfs_unmount,
    .mkfs   = myfs_mkfs,
    .statfs = myfs_statfs,
    .unlink = myfs_unlink,
    .stat   = myfs_stat,
    .rename = myfs_rename,
};

int myfs_init(void)
{
    dfs_register(&myfs_ops);
    return 0;
}
INIT_COMPONENT_EXPORT(myfs_init);
```

---

## References

- [RT-Thread Kernel](RT-Thread%20Kernel.md) - Core kernel services used by DFS
- [Device Drivers Framework](../Device%20Drivers%20Framework.md) - Block device interface for storage
- [LWP (Light Weight Process)](../LWP%20(Light%20Weight%20Process).md) - Per-process fdtable support in Smart mode
- [FAL (Flash Abstraction Layer)](../FAL%20(Flash%20Abstraction%20Layer).md) - Flash abstraction for block device layer
- [Finsh Shell](../Finsh%20Shell.md) - Shell commands for filesystem operations (ls, mkdir, etc.)
