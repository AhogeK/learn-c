//
// Created by AhogeK on 10/17/24.
//

#include <stdio.h>
#include <stdint.h>
#include <assert.h>

uint32_t rightrot(uint32_t x, unsigned int n);
void print_binary(uint32_t num);

/*
 * 编写一个C程序函数rightrot(x,n)，该函数返回将x循环右移
 * （即从最右端移出的位将从最左端移入）n（二进制）位后所得到的值
 */
int main(void)
{
    uint32_t x = 0b00000000000000000000000000001111;
    unsigned int n = 4;

    printf("原始 x   = ");
    print_binary(x);

    uint32_t result = rightrot(x, n);

    printf("右移 %2u位 = ", n);
    print_binary(result);

    return 0;
}

uint32_t rightrot(uint32_t x, unsigned int n)
{
    assert(n < 32 && "n 的值不合法");

    // 确保 n 在 0-31 范围内
    n = n % 32;

    // 如果 n 为 0，不需要移动
    if (n == 0)
    {
        return x;
    }

    // 执行循环右移
    return x >> n | x << 32 - n;
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
