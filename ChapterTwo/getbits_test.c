//
// Created by Ahoge Knight on 2022/12/8.
//

#include <printf.h>

/* getbits函数：返回x中从第p位开始的n位 */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

void bin(unsigned n) {
    for (unsigned i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}

int main() {
    bin(getbits(90, 3, 3));
}