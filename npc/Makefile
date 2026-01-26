TOPNAME = top

VERILATOR = verilator

VERILATOR_CFLAGS += -MMD --build -cc \
				-O3 --x-assign fast --x-initial fast --noassert \
				--trace 

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

TEST_BIN ?= ./test/new.bin  
ifeq ($(AM_IMAGE),)
  RUN_IMAGE = $(TEST_BIN)  
else
  RUN_IMAGE = $(AM_IMAGE)  
endif

$(shell mkdir -p $(BUILD_DIR))

VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")


CFLAGS   += -I$(abspath ./csrc) \
			-I$(abspath ./csrc/include) \
			-I$(abspath ./csrc/config) \
			-I$(abspath ./csrc/sdb) \
			-I$(OBJ_DIR)
# === capstone 路径设置 ===
CFLAGS   += -I$(abspath ../nemu/tools/capstone/repo/include)

LDFLAGS  += -lreadline -lncurses -ldl
LDFLAGS  += $(abspath ../nemu/tools/capstone/repo/libcapstone.so.5)

default: $(BIN)

$(BIN): $(VSRCS) $(CSRCS)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN)) \
		--LDFLAGS "$(LDFLAGS)" \
		--CFLAGS "$(CFLAGS)"

run: $(BIN)
	@echo "[NPC] Running with image: $(RUN_IMAGE)"  
	LD_LIBRARY_PATH=$(abspath ../nemu/tools/capstone/repo) $(BIN) $(RUN_IMAGE)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: default clean run