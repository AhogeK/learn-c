//
// Created by ahogek on 1/17/22.
//

#include <stdio.h>

/* getbits函数: 返回x中从第p位开始的n位 */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

void printBinary(unsigned n, int len) {
    for (int i = len - 1; i != -1; i--)
        printf("%d", (n & (1 << i)) >> i );
    putc('\n', stdout);
}

int main() {
    printBinary(getbits(40, 4, 3), 3);
    return 0;
}