// 框架自检（阳性对照）：正常结束的程序，回归框架必须判为 PASS。
//
// 与 selfcheck/expect-fail.c 配对使用，见 cpu-tests/Makefile 的 selfcheck 目标。
// 本文件不在 tests/ 下，因而不会被 ALL 自动发现，不污染常规回归的结果表。

#include "trap.h"

int main() {
  printf("selfcheck: exiting with code 0 (expect the harness to report PASS)\n");
  return 0;
}
