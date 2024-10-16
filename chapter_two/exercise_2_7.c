//
// Created by AhogeK on 10/17/24.
//

#include <stdio.h>
#include <stdint.h>
#include <assert.h>

uint32_t invert(uint32_t x, size_t p, size_t n);
void print_binary(uint32_t num);

/*
 * 编写一个函数invert(x, p, n)，该函数返回对x执行下列操作后的结果值：
 * 将x中从第p位开始的n个（二进制）位求反（即1变成0，0变成1），x的其余各位保持不变。
 */
int main()
{
    uint32_t x = 0b11110000111100001111000011110000;
    size_t p = 15; // 从右边数，第16位开始（包括第16位）
    size_t n = 8; // 反转8位

    printf("原始 x   = ");
    print_binary(x);

    uint32_t result = invert(x, p, n);

    printf("结果     = ");
    print_binary(result);

    printf("p = %zu, n = %zu\n", p, n);

    return 0;
}

uint32_t invert(uint32_t x, size_t p, size_t n)
{
    assert(p < 32 && n <= p + 1 && "p 和 n 的值不合法");

    // 创建一个掩码，其中要修改的位为1，其他位为0
    uint32_t mask = ~(~0u << n) << p + 1 - n;
    return x ^ mask;
}

void print_binary(uint32_t num)
{
    for (int i = 31; i >= 0; i--)
    {
        putchar(num & 1u << i ? '1' : '0');
        if (i % 8 == 0 && i > 0)
        {
            putchar(' ');
        }
    }
    putchar('\n');
}
