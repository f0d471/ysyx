# AbstractMachine 内核与库的顶层 Makefile

### 通过 `make html` 获得更易读的版本（需要 python-markdown）
html:
	cat Makefile | sed 's/^\([^#]\)/    \1/g' | markdown_py > Makefile.html
.PHONY: html

## 1. 基本设置与校验

### 默认目标：创建裸机内核镜像
ifeq ($(MAKECMDGOALS),)
  MAKECMDGOALS  = image
  .DEFAULT_GOAL = image
endif

### `make clean/clean-all/html` 时跳过后续校验
ifeq ($(findstring $(MAKECMDGOALS),clean|clean-all|html),)

### 打印构建信息
$(info # Building $(NAME)-$(MAKECMDGOALS) [$(ARCH)])

### 校验：环境变量 `$AM_HOME` 必须指向合法的 AM 仓库
ifeq ($(wildcard $(AM_HOME)/am/include/am.h),)
  $(error $$AM_HOME must be an AbstractMachine repo)
endif

### 校验：环境变量 `$ARCH` 必须在支持列表中
ARCHS = $(basename $(notdir $(shell ls $(AM_HOME)/scripts/*.mk)))
ifeq ($(filter $(ARCHS), $(ARCH)), )
  $(error Expected $$ARCH in {$(ARCHS)}, Got "$(ARCH)")
endif

### 从 `$ARCH` 中提取指令集架构(`ISA`)和平台(`PLATFORM`)。示例: `ARCH=x86_64-qemu -> ISA=x86_64; PLATFORM=qemu`
ARCH_SPLIT = $(subst -, ,$(ARCH))
ISA        = $(word 1,$(ARCH_SPLIT))
PLATFORM   = $(word 2,$(ARCH_SPLIT))

### 校验：是否有待编译的源文件
ifeq ($(flavor SRCS), undefined)
  $(error Nothing to build)
endif

### 校验到此结束
endif

## 2. 通用编译目标

### 创建目标输出目录（`build/$ARCH`）
WORK_DIR  = $(shell pwd)
DST_DIR   = $(WORK_DIR)/build/$(ARCH)
$(shell mkdir -p $(DST_DIR))

### 编译产物（二进制镜像或静态库）
IMAGE_REL = build/$(NAME)-$(ARCH)
IMAGE     = $(abspath $(IMAGE_REL))
ARCHIVE   = $(WORK_DIR)/build/$(NAME)-$(ARCH).a

### 收集待链接的文件：目标文件(`.o`)和库文件(`.a`)
OBJS      = $(addprefix $(DST_DIR)/, $(addsuffix .o, $(basename $(SRCS))))
LIBS     := $(sort $(LIBS) am klib) # lazy evaluation ("=") causes infinite recursions
LINKAGE   = $(OBJS)  # library archives are added by LIB_TEMPLATE below

## 3. 通用编译参数

### (交叉)编译器，例如 mips-linux-gnu-g++
AS        = $(CROSS_COMPILE)gcc
CC        = $(CROSS_COMPILE)gcc
CXX       = $(CROSS_COMPILE)g++
LD        = $(CROSS_COMPILE)ld
AR        = $(CROSS_COMPILE)ar
OBJDUMP   = $(CROSS_COMPILE)objdump
OBJCOPY   = $(CROSS_COMPILE)objcopy
READELF   = $(CROSS_COMPILE)readelf

### 编译参数
INC_PATH += $(WORK_DIR)/include $(addsuffix /include/, $(addprefix $(AM_HOME)/, $(LIBS)))
INCFLAGS += $(addprefix -I, $(INC_PATH))

ARCH_H := arch/$(ARCH).h
CFLAGS   += -O2 -MMD -Wall -Werror $(INCFLAGS) \
            -D__ISA__=\"$(ISA)\" -D__ISA_$(shell echo $(ISA) | tr a-z A-Z)__ \
            -D__ARCH__=$(ARCH) -D__ARCH_$(shell echo $(ARCH) | tr a-z A-Z | tr - _) \
            -D__PLATFORM__=$(PLATFORM) -D__PLATFORM_$(shell echo $(PLATFORM) | tr a-z A-Z | tr - _) \
            -DARCH_H=\"$(ARCH_H)\" \
            -fno-asynchronous-unwind-tables -fno-builtin -fno-stack-protector \
            -Wno-main -U_FORTIFY_SOURCE -fvisibility=hidden
CXXFLAGS +=  $(CFLAGS) -ffreestanding -fno-rtti -fno-exceptions
ASFLAGS  += -MMD $(INCFLAGS)
LDFLAGS  += -z noexecstack $(addprefix -T, $(LDSCRIPTS))

## 4. 架构相关配置

### 加载架构相关配置（例如 `scripts/x86_64-qemu.mk`），-前缀表示文件不存在也不报错
-include $(AM_HOME)/scripts/$(ARCH).mk

## 5. 编译规则

### 规则(编译)：单个 `.c` → `.o`（gcc）
$(DST_DIR)/%.o: %.c
	@mkdir -p $(dir $@) && echo + CC $<
	@$(CC) -std=gnu11 $(CFLAGS) -c -o $@ $(realpath $<)

### 规则(编译)：单个 `.cc` → `.o`（g++）
$(DST_DIR)/%.o: %.cc
	@mkdir -p $(dir $@) && echo + CXX $<
	@$(CXX) -std=c++17 $(CXXFLAGS) -c -o $@ $(realpath $<)

### 规则(编译)：单个 `.cpp` → `.o`（g++）
$(DST_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@) && echo + CXX $<
	@$(CXX) -std=c++17 $(CXXFLAGS) -c -o $@ $(realpath $<)

### 规则(编译)：单个 `.S` → `.o`（gcc，先预处理再调汇编器）
$(DST_DIR)/%.o: %.S
	@mkdir -p $(dir $@) && echo + AS $<
	@$(AS) $(ASFLAGS) -c -o $@ $(realpath $<)

ifeq ($(MAKECMDGOALS),archive)
### 规则(打包)：目标文件(`*.o`) → `ARCHIVE.a`（ar）
$(ARCHIVE): $(OBJS)
	@echo + AR "->" $(shell realpath $@ --relative-to .)
	@$(AR) rcs $@ $^
else
# $(1)：库名称
define LIB_TEMPLATE =
$$(AM_HOME)/$(1)/build/$(1)-$$(ARCH).a: force
	@$$(MAKE) -s -C $$(AM_HOME)/$(1) archive
LINKAGE += $$(AM_HOME)/$(1)/build/$(1)-$$(ARCH).a
endef

### 规则(递归 make)：构建依赖库（am, klib, ...）
$(foreach lib, $(LIBS), $(eval $(call LIB_TEMPLATE,$(lib))))
endif

### Rule (link): objects (`*.o`) and libraries (`*.a`) -> `IMAGE.elf`, the final ELF binary to be packed into image (ld)
$(IMAGE).elf: $(LINKAGE) $(LDSCRIPTS)
	@echo \# Creating image [$(ARCH)]
	@echo + LD "->" $(IMAGE_REL).elf
ifneq ($(filter $(ARCH),native),)
	@$(CXX) -o $@ -Wl,--whole-archive $(LINKAGE) -Wl,-no-whole-archive $(LDFLAGS_CXX)
else
	@$(LD) $(LDFLAGS) -o $@ --start-group $(LINKAGE) --end-group
endif

### 规则(`#include`依赖)：汇入 gcc 通过 `-MMD` 生成的 `.d` 文件，自动追踪头文件变更
-include $(addprefix $(DST_DIR)/, $(addsuffix .d, $(basename $(SRCS))))

## 6. 杂项

### 构建顺序控制
image: image-dep
archive: $(ARCHIVE)
image-dep: $(IMAGE).elf
.PHONY: image image-dep archive run

### 强制重编的假目标——作为子库 .a 的依赖，让子库每次都递归检查
force:
.PHONY: force

### 清理单个项目（删除 `build/` 目录）
clean:
	rm -rf Makefile.html $(WORK_DIR)/build/
.PHONY: clean

### 清理深度为 2 以内的所有子项目（忽略错误）
CLEAN_ALL = $(dir $(shell find . -mindepth 2 -name Makefile))
clean-all: $(CLEAN_ALL) clean
$(CLEAN_ALL):
	-@$(MAKE) -s -C $@ clean
.PHONY: clean-all $(CLEAN_ALL)
