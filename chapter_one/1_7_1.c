//
// 1.7 函数
// Created by AhogeK on 10/10/24.
//

#include <stdio.h>

int power(int m, int n);

/* 测试power函数 */
int main()
{
    int i;
    for (i = 0; i < 10; ++i)
        printf("%d 2^%d=%d -3^%d=%d\n", i, i, power(2, i), i, power(-3, i));
    return 0;
}

/* power函数：求底数的n次幂；其中n >= 0 */
int power(int base, int n)
{
    int i, p;
    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
