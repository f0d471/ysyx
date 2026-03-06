#include <amtest.h>

void putch_test() {
    // 1. 最底层的直接输出测试 
    putch('N');
    putch('P');
    putch('C');
    putch('-');
    putch('U');
    putch('A');
    putch('R');
    putch('T');
    putch('\n');

    // 2. 高级的格式化输出测试 
    printf("=======================================\n");
    printf("Hello, World! This is NPC serial port.\n");
    printf("If you see this, MMIO is working!\n");
    printf("=======================================\n");
}