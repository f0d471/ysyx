// 框架自检（阴性对照）：以非零码结束的程序，回归框架必须判为 FAIL。
//
// 这一半才是关键。一张全绿的结果表，只有在框架**确实报得出错**的前提下才有意义；
// 而"框架报不出错"在本仓库已经真实发生过两次：
//   - NEMU：NEMUFLAGS 缺 -b，make run 掉进交互式 sdb，手敲的 q 让 NEMU 以 0 退出
//     （nemu/src/utils/state.c 把 NEMU_QUIT 算作 good），于是一律记 PASS；
//   - NPC ：main() 恒 return 0，且 trap() 无条件把状态置为 NPC_END，
//     连 HIT BAD TRAP 都会被记成正常结束。
// 两次都是"绿得毫无意义"，而只跑正向用例永远发现不了。
//
// 若本程序被判成 PASS，说明退出码没有从模拟器传上来，整张回归结果表都不可信。

#include "trap.h"

int main() {
  printf("selfcheck: exiting with code 1 ON PURPOSE (expect the harness to report FAIL)\n");
  return 1;
}
