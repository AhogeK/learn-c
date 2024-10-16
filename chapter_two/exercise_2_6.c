//
// 编写一个函数setbits(x, p, n, y)，该函数返回对x执行下列操作后的结果值：
// 将x中从第p位开始的n个（二进制）位设置为y中最右边n位的值，x中的其余各位保持不变。
// Created by AhogeK on 10/16/24.
//

#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);
void print_binary(unsigned int num);

int main()
{
    unsigned int x = 0b00101111;
    unsigned int y = 0b11001100;
    int p = 7;
    int n = 4;

    unsigned int result = setbits(x, p, n, y);

    printf("x     = ");
    print_binary(x);

    printf("y     = ");
    print_binary(y);

    printf("结果  = ");
    print_binary(result);

    printf("p = %d, n = %d\n", p, n);

    return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    // 创建一个掩码，其中要修改的位为1，其他位为0
    unsigned int mask = ~(~0 << n) << p + 1 - n;

    // 清除x中要修改的位
    x = x & ~mask;

    // 从y中提取最右边的n位
    unsigned int y_bits = y & ~(~0 << n);

    // 将y的位移动到正确的位置
    y_bits = y_bits << (p + 1 - n);

    // 将修改后的位与x组合
    return x | y_bits;
}

void print_binary(unsigned int num)
{
    int i;
    unsigned int mask = 1U << 31; // 假设是32位整数

    for (i = 0; i < 32; i++)
    {
        putchar((num & mask) ? '1' : '0');
        mask >>= 1;
        if ((i + 1) % 8 == 0 && i < 31)
        {
            putchar(' '); // 每8位添加一个空格，提高可读性
        }
    }
    putchar('\n');
}
