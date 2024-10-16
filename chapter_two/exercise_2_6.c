//
// 编写一个函数setbits(x, p, n, y)，该函数返回对x执行下列操作后的结果值：
// 将x中从第p位开始的n个（二进制）位设置为y中最右边n位的值，x中的其余各位保持不变。
// Created by AhogeK on 10/16/24.
//

#include <stdio.h>
#include <stdint.h>
#include <assert.h>

uint32_t setbits(uint32_t x, size_t p, size_t n, uint32_t y);
void print_binary(uint32_t num);

int main(void)
{
    uint32_t x = 0b00101111;
    uint32_t y = 0b11001100;
    size_t p = 7;
    size_t n = 4;

    uint32_t result = setbits(x, p, n, y);

    printf("x     = ");
    print_binary(x);

    printf("y     = ");
    print_binary(y);

    printf("结果  = ");
    print_binary(result);

    printf("p = %zu, n = %zu\n", p, n);

    return 0;
}

uint32_t setbits(uint32_t x, size_t p, size_t n, uint32_t y)
{
    assert(p < 32 && n <= p + 1 && "p 和 n 的值不合法");

    // 创建一个掩码，其中要修改的位为1，其他位为0
    uint32_t mask = ~(~0u << n) << p + 1 - n;

    // 清除x中要修改的位
    x = x & ~mask;

    // 从y中提取最右边的n位，并移动到正确的位置
    uint32_t y_bits = (y & ~(~0u << n)) << p + 1 - n;

    // 将修改后的位与x组合
    return x | y_bits;
}

void print_binary(uint32_t num)
{
    for (int i = 31; i >= 0; i--)
    {
        putchar((num & (1u << i)) ? '1' : '0');
        if (i % 8 == 0 && i > 0)
        {
            putchar(' ');
        }
    }
    putchar('\n');
}
