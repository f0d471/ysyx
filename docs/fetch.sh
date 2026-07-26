#!/usr/bin/env bash
# ============================================================
# docs 知识库抓取脚本
#
# 只抓取官方发布、且允许自由下载的材料。有版权的商业书籍不在此列，
# 见 README.md 的「纸质书单」一节。
#
# 用法：
#   bash docs/fetch.sh              # 抓取全部
#   bash docs/fetch.sh 05           # 只抓某个领域，用编号
#   bash docs/fetch.sh embedded     # 也可用关键字
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
    if curl -fsSL --retry 3 --retry-delay 2 --connect-timeout 25 \
            -o "$dir/$name.part" "$url"; then
        mv -f "$dir/$name.part" "$dir/$name"
        printf '  ok    %s\n' "$dir/$name"; ok=$((ok + 1))
    else
        rm -f "$dir/$name.part"
        printf '  FAIL  %s\n        <- %s\n' "$dir/$name" "$url"; fail=$((fail + 1))
    fi
}

# want <编号> <关键字...>
want() {
    [ "$ONLY" = "all" ] && return 0
    for k in "$@"; do [ "$ONLY" = "$k" ] && return 0; done
    return 1
}

# ------------------------------------------------------------
# 01 指令集规范
#    NEMU 写指令、NPC 写译码器、difftest 判对错，都以此为准
# ------------------------------------------------------------
if want 01 isa riscv; then
echo "[01] 指令集规范"
D=01-isa-riscv
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
# 02 数字设计与 HDL 编码规范
#    NPC 的 RTL 怎么写才是工业界能接受的写法
# ------------------------------------------------------------
if want 02 hdl digital; then
echo "[02] 数字设计与 HDL"
D=02-digital-hdl
fetch "$D" "https://raw.githubusercontent.com/lowRISC/style-guides/master/VerilogCodingStyle.md" \
      "lowRISC-Verilog-Coding-Style.md"
fi

# ------------------------------------------------------------
# 03 处理器微架构与体系结构
# ------------------------------------------------------------
if want 03 arch cpu; then
echo "[03] 处理器与体系结构"
D=03-arch-cpu
fetch "$D" "https://www2.eecs.berkeley.edu/Pubs/TechRpts/2014/EECS-2014-146.pdf" \
      "Instruction-Sets-Should-Be-Free-The-Case-for-RISC-V.pdf"
fetch "$D" "https://www2.eecs.berkeley.edu/Pubs/TechRpts/2016/EECS-2016-1.pdf" \
      "Berkeley-RISC-V-Tech-Report.pdf"
fi

# ------------------------------------------------------------
# 04 总线协议与 SoC 互连
#    NPC 的 AXI4 重构、ysyxSoC 内部的 TileLink
# ------------------------------------------------------------
if want 04 bus soc; then
echo "[04] 总线与 SoC 互连"
D=04-bus-soc
fetch "$D" "https://static.dev.sifive.com/docs/tilelink/tilelink-spec-1.7-draft.pdf" \
      "TileLink-Spec-1.7.pdf"
fetch "$D" "https://cdn.opencores.org/downloads/wbspec_b4.pdf" \
      "Wishbone-B4-Spec.pdf"
fi

# ------------------------------------------------------------
# 05 嵌入式外设与驱动
#    Phase 6~10 全在这里：UART / Flash XIP / PSRAM / SDRAM / 中断
# ------------------------------------------------------------
if want 05 embedded periph; then
echo "[05] 嵌入式外设与驱动"
D=05-embedded-periph
fetch "$D" "https://raw.githubusercontent.com/riscv/riscv-plic-spec/master/riscv-plic.adoc" \
      "RISC-V-PLIC-Spec.adoc"
fetch "$D" "https://raw.githubusercontent.com/riscv/riscv-aclint/main/riscv-aclint.adoc" \
      "RISC-V-ACLINT-Spec.adoc"
# 注：UART16550 与 SPI 的 datasheet 仓库里本来就有，不重复下载：
#   ysyxSoC/perip/uart16550/doc/UART_spec.pdf
#   ysyxSoC/perip/spi/doc/spi.pdf
fi

# ------------------------------------------------------------
# 06 验证方法学
#    difftest 之外，工业界还用什么手段证明 RTL 是对的
# ------------------------------------------------------------
if want 06 verif verification; then
echo "[06] 验证方法学"
D=06-verification
fetch "$D" "https://www.accellera.org/images/downloads/standards/uvm/uvm_users_guide_1.2.pdf" \
      "UVM-1.2-Users-Guide.pdf"
fetch "$D" "https://symbiyosys.readthedocs.io/_/downloads/en/latest/pdf/" \
      "SymbiYosys-Formal-Verification.pdf"
fi

# ------------------------------------------------------------
# 07 数字后端与 EDA 流程
#    综合、静态时序分析、布局布线
# ------------------------------------------------------------
if want 07 backend eda; then
echo "[07] 数字后端与 EDA"
D=07-backend-eda
fetch "$D" "https://openroad.readthedocs.io/_/downloads/en/latest/pdf/" \
      "OpenROAD-Flow-Docs.pdf"
fi

# ------------------------------------------------------------
# 08 编译、汇编、链接、调试信息
#    AM 的 Makefile 体系、linker script、objcopy、ftrace 符号解析
# ------------------------------------------------------------
if want 08 toolchain link; then
echo "[08] 工具链与目标文件格式"
D=08-toolchain-link
fetch "$D" "https://www.gnu.org/software/make/manual/make.pdf"      "GNU-Make-Manual.pdf"
fetch "$D" "https://sourceware.org/binutils/docs/ld.pdf"            "GNU-ld-Linker-Manual.pdf"
fetch "$D" "https://sourceware.org/binutils/docs/as.pdf"            "GNU-as-Assembler-Manual.pdf"
fetch "$D" "https://refspecs.linuxfoundation.org/elf/elf.pdf"       "ELF-Format-Spec.pdf"
fetch "$D" "https://dwarfstd.org/doc/DWARF5.pdf"                    "DWARF5-Debugging-Format.pdf"
fetch "$D" "https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.pdf" "GNU-C-Manual.pdf"
fi

# ------------------------------------------------------------
# 09 操作系统与实时系统
#    nanos-lite、AM 的 CTE/VME、RT-Thread
# ------------------------------------------------------------
if want 09 os rtos; then
echo "[09] 操作系统与实时系统"
D=09-os-rtos
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
# 10 图形、字体与多媒体
#    navy-apps 那一整层：libminiSDL / libSDL_* / libvorbis / libbdf
# ------------------------------------------------------------
if want 10 graphics media; then
echo "[10] 图形与多媒体"
D=10-graphics-media
fetch "$D" "https://xiph.org/vorbis/doc/Vorbis_I_spec.pdf" \
      "Vorbis-I-Audio-Codec-Spec.pdf"
fetch "$D" "https://adobe-type-tools.github.io/font-tech-notes/pdfs/5005.BDF_Spec.pdf" \
      "BDF-Bitmap-Font-Spec.pdf"
fi

# ------------------------------------------------------------
# 11 模拟器与建模方法学
#    QEMU / gem5 / SystemC-TLM / C-model 这一族
# ------------------------------------------------------------
if want 11 sim model; then
echo "[11] 模拟器与建模"
D=11-sim-model
fetch "$D" "https://arxiv.org/pdf/2007.03152" \
      "The-gem5-Simulator-Version-20-Plus.pdf"
fetch "$D" "https://www.accellera.org/images/downloads/standards/systemc/TLM2_Whitepaper.pdf" \
      "SystemC-TLM-2.0-Whitepaper.pdf"
fetch "$D" "https://www.accellera.org/images/downloads/standards/systemc/SystemC_Synthesis_Subset_1_4_7.pdf" \
      "SystemC-Synthesis-Subset.pdf"
fi

echo
echo "============================================"
printf "新增 %d 个，跳过 %d 个，失败 %d 个\n" "$ok" "$skip" "$fail"
[ "$fail" -gt 0 ] && echo "失败项多为上游改名或临时不可达，重跑一次即可。"
echo "============================================"
exit 0
