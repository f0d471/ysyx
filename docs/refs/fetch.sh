#!/usr/bin/env bash
# ============================================================
# docs/refs 参考资料抓取脚本
#
# 只抓取官方发布、且允许自由下载的材料。有版权的商业书籍不在此列，
# 见 README.md 的「纸质书单」一节。
#
# 用法：
#   bash docs/refs/fetch.sh          # 抓取全部
#   bash docs/refs/fetch.sh os       # 只抓某一类（isa/arch/toolchain/os/hdl）
#
# 已存在且非空的文件会跳过，可安全重复运行。
# ============================================================
set -uo pipefail
cd "$(dirname "$0")" || exit 1

ONLY="${1:-all}"
ok=0; skip=0; fail=0

fetch() {
    local dir="$1" url="$2" name="${3:-$(basename "$url")}"
    mkdir -p "$dir"
    if [ -s "$dir/$name" ]; then
        printf '  skip  %s\n' "$dir/$name"; skip=$((skip + 1)); return 0
    fi
    if curl -fsSL --retry 3 --retry-delay 2 --connect-timeout 20 \
            -o "$dir/$name.part" "$url"; then
        mv -f "$dir/$name.part" "$dir/$name"
        printf '  ok    %s\n' "$dir/$name"; ok=$((ok + 1))
    else
        rm -f "$dir/$name.part"
        printf '  FAIL  %s\n        <- %s\n' "$dir/$name" "$url"; fail=$((fail + 1))
    fi
}

want() { [ "$ONLY" = "all" ] || [ "$ONLY" = "$1" ]; }

# ------------------------------------------------------------
# 1. ISA 与体系结构规范
#    对应 ysyx：NEMU 指令实现、NPC 译码器、difftest 的判据来源
# ------------------------------------------------------------
if want isa; then
echo "[1/5] ISA 规范"
D=1-isa-riscv
fetch "$D" "https://github.com/riscv/riscv-isa-manual/releases/latest/download/riscv-spec.pdf" \
      "RISC-V-ISA-Manual.pdf"
fetch "$D" "https://github.com/riscv-non-isa/riscv-elf-psabi-doc/releases/latest/download/riscv-abi.pdf" \
      "RISC-V-ELF-psABI.pdf"
fetch "$D" "https://github.com/riscv-non-isa/riscv-asm-manual/releases/latest/download/riscv-asm.pdf" \
      "RISC-V-Assembly-Manual.pdf"
fetch "$D" "http://riscvbook.com/chinese/RISC-V-Reader-Chinese-v2p1.pdf" \
      "RISC-V手册-中文版.pdf"
fi

# ------------------------------------------------------------
# 2. 处理器设计与体系结构
#    对应 ysyx：NPC 五级流水线、总线、SoC 集成
# ------------------------------------------------------------
if want arch; then
echo "[2/5] 处理器设计"
D=2-arch-cpu
fetch "$D" "https://www2.eecs.berkeley.edu/Pubs/TechRpts/2014/EECS-2014-146.pdf" \
      "Instruction-Sets-Should-Be-Free-The-Case-for-RISC-V.pdf"
fetch "$D" "https://www2.eecs.berkeley.edu/Pubs/TechRpts/2016/EECS-2016-1.pdf" \
      "Berkeley-RISC-V-Tech-Report.pdf"
fi

# ------------------------------------------------------------
# 3. 工具链：编译、汇编、链接、调试信息
#    对应 ysyx：Makefile 体系、AM 的 linker script、objcopy/objdump、ftrace
# ------------------------------------------------------------
if want toolchain; then
echo "[3/5] 工具链与目标文件格式"
D=3-toolchain-link
fetch "$D" "https://www.gnu.org/software/make/manual/make.pdf"      "GNU-Make-Manual.pdf"
fetch "$D" "https://sourceware.org/binutils/docs/ld.pdf"            "GNU-ld-Linker-Manual.pdf"
fetch "$D" "https://sourceware.org/binutils/docs/as.pdf"            "GNU-as-Assembler-Manual.pdf"
fetch "$D" "https://refspecs.linuxfoundation.org/elf/elf.pdf"       "ELF-Format-Spec.pdf"
fetch "$D" "https://dwarfstd.org/doc/DWARF5.pdf"                    "DWARF5-Debugging-Format.pdf"
fetch "$D" "https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf" "GNU-C-Manual.pdf"
fi

# ------------------------------------------------------------
# 4. 操作系统
#    对应 ysyx：nanos-lite、AM 的 CTE/VME、RT-Thread
# ------------------------------------------------------------
if want os; then
echo "[4/5] 操作系统"
D=4-os
fetch "$D" "https://pdos.csail.mit.edu/6.828/2023/xv6/book-riscv-rev3.pdf" \
      "xv6-a-simple-Unix-like-teaching-OS.pdf"

# OSTEP —— 威斯康星大学 Remzi 夫妇的《Operating Systems: Three Easy Pieces》
# 作者提供全部章节免费下载。按虚拟化 / 并发 / 持久化三部分组织。
OSTEP_BASE="https://pages.cs.wisc.edu/~remzi/OSTEP"
OSTEP_CH=(
    preface toc intro
    dialogue-virtualization cpu-dialogue cpu-intro cpu-api cpu-mechanisms
    cpu-sched cpu-sched-mlfq cpu-sched-lottery cpu-sched-multi
    dialogue-vm vm-dialogue vm-intro vm-api vm-mechanism vm-segmentation
    vm-freespace vm-paging vm-tlbs vm-smalltables vm-beyondphys
    vm-beyondphys-policy vm-complete
    dialogue-vmm vmm-intro
    dialogue-concurrency threads-dialogue threads-intro threads-api
    threads-locks threads-locks-usage threads-cv threads-sema
    threads-bugs threads-events dialogue-monitors threads-monitors
    dialogue-persistence file-dialogue file-devices file-disks file-raid
    file-intro file-implementation file-ffs file-journaling file-lfs
    file-ssd file-integrity
    dialogue-distribution dist-dialogue dist-intro dist-nfs dist-afs
    dialogue-security security-intro security-authentication
    security-access security-crypto security-distributed
    dialogue-labs lab-tutorial lab-projects-systems lab-projects-xv6
    dedication
)
for c in "${OSTEP_CH[@]}"; do
    fetch "$D/OSTEP" "$OSTEP_BASE/$c.pdf" "$c.pdf"
done
fi

# ------------------------------------------------------------
# 5. HDL 与验证规范
#    对应 ysyx：NPC 的 RTL 编码规范、Verilator 仿真
# ------------------------------------------------------------
if want hdl; then
echo "[5/5] HDL 与验证"
D=5-hdl-verif
fetch "$D" "https://raw.githubusercontent.com/lowRISC/style-guides/master/VerilogCodingStyle.md" \
      "lowRISC-Verilog-Coding-Style.md"
fi

echo
echo "============================================"
printf "新增 %d 个，跳过 %d 个，失败 %d 个\n" "$ok" "$skip" "$fail"
[ "$fail" -gt 0 ] && echo "失败项多为上游改名或临时不可达，重跑一次即可。"
echo "============================================"
exit 0
