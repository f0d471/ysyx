.PHONY: all run gdb clean latest selfcheck $(ALL)

RESULT = .result
$(shell > $(RESULT))

COLOR_RED   = \033[1;31m
COLOR_GREEN = \033[1;32m
COLOR_NONE  = \033[0m

# 自动发现 tests/ 下所有 .c 文件，提取测试名
ALL = $(basename $(notdir $(shell find tests/. -name "*.c")))

all: $(addprefix Makefile., $(ALL))
	@echo "test list [$(words $(ALL)) item(s)]:" $(ALL)

$(ALL): %: Makefile.%

# 批量回归必须无人值守，故 run 时传 BATCH=1，由各平台的 .mk 翻译成模拟器的 -b。
# gdb 目标不传，保留交互能力。
BATCH_FLAG = $(if $(filter run,$(MAKECMDGOALS)),BATCH=1)

# 每个测试生成临时 Makefile，递归调用子 make 完成编译+运行，根据退出码记录 PASS/FAIL
Makefile.%: tests/%.c latest
	@/bin/echo -e "NAME = $*\nSRCS = $<\ninclude $${AM_HOME}/Makefile" > $@
	@if make -s -f $@ ARCH=$(ARCH) $(BATCH_FLAG) $(MAKECMDGOALS); then \
		printf "[%14s] $(COLOR_GREEN)PASS$(COLOR_NONE)\n" $* >> $(RESULT); \
	else \
		printf "[%14s] $(COLOR_RED)***FAIL***$(COLOR_NONE)\n" $* >> $(RESULT); \
	fi
	-@rm -f Makefile.$*

# ---------------------------------------------------------------- 框架自检
#
# 一张全绿的结果表，只有在"框架确实报得出错"的前提下才有意义。selfcheck/ 下的两个
# 程序分别以 0 和 1 退出，本目标断言框架对它们的判定恰好是 PASS 和 FAIL——即同时
# 验证阳性与阴性两个方向。任一不符即说明退出码链路断了，整张结果表不可信。
#
# 这两个程序放在 selfcheck/ 而非 tests/，因此不会被 ALL 自动发现，不会在常规回归
# 里显示成一条刺眼的 ***FAIL***。
#
# 编译与运行分两步：编译失败也会让 run 返回非零，若混在一起，expect-fail 会因为
# "根本没编出来"而假性通过。
#
# 输出不做重定向，与上面 Makefile.% 规则的既有行为一致——编译过程与模拟器输出本身
# 就是信息（首次跑某个 ARCH 要编 AM 与 klib，NPC 还要让 Verilator 把整个 RTL 转成
# C++ 再编译，是分钟级的，静默会让人以为卡死）。只在每个程序前后加一行标注，说明
# 这一段属于自检、以及它的预期结果是什么。
selfcheck:
	@echo "== harness self-check [$(ARCH)] =="
	@rc=0; \
	for t in expect-pass expect-fail; do \
	  case $$t in \
	    expect-pass) want=PASS; note="正常结束，框架应判 PASS";; \
	    *)           want=FAIL; note="故意以非零码结束，框架应判 FAIL；下面出现的 make Error 是预期的";; \
	  esac; \
	  echo ""; \
	  echo "---- selfcheck: $$t —— $$note ----"; \
	  /bin/echo -e "NAME = $$t\nSRCS = selfcheck/$$t.c\ninclude $${AM_HOME}/Makefile" > Makefile.$$t; \
	  if ! make -s -f Makefile.$$t ARCH=$(ARCH) image; then \
	    printf "  [%12s] $(COLOR_RED)BUILD ERROR$(COLOR_NONE)\n" $$t; rc=1; \
	    rm -f Makefile.$$t; continue; \
	  fi; \
	  if make -s -f Makefile.$$t ARCH=$(ARCH) BATCH=1 run; then got=PASS; else got=FAIL; fi; \
	  rm -f Makefile.$$t; \
	  if [ "$$got" = "$$want" ]; then \
	    printf "  [%12s] want %-4s got %-4s $(COLOR_GREEN)OK$(COLOR_NONE)\n" $$t $$want $$got; \
	  else \
	    printf "  [%12s] want %-4s got %-4s $(COLOR_RED)BROKEN$(COLOR_NONE)\n" $$t $$want $$got; rc=1; \
	  fi; \
	done; \
	echo ""; \
	if [ $$rc -ne 0 ]; then \
	  printf "$(COLOR_RED)自检未通过：PASS/FAIL 判定不可信，下面的结果表没有意义$(COLOR_NONE)\n"; \
	fi; \
	exit $$rc

# run 先自检再回归：框架坏掉时宁可停下，也好过给出一张看起来全绿的假表。
# 依赖按顺序处理（串行 make 的既有行为，本目录的 $(RESULT) 追加本来也假定串行）
run: selfcheck all
	@cat $(RESULT)
	@rm $(RESULT)

gdb: all

clean:
	rm -rf Makefile.* build/ $(RESULT)

latest:
