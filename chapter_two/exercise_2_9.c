//
// 在求二进制补码时，表达式 x &= (x - 1) 可以删除x中最右边值为1的一个二进制位。
// 请解释这样做的道理。用这一方法重写bitcount函数，以加快其执行速度。
// 这个操作的妙处在于，它可以在一步之内清除最右边的 1，而不需要遍历所有位。
// Created by AhogeK on 10/17/24.
//

#include <stdio.h>

int bitcount(unsigned int x);

int main()
{
    unsigned int test_cases[] = {0, 1, 15, 16, 255, 256, 0xFFFFFFFF};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; ++i)
    {
        printf("Number of 1s in %u: %d\n", test_cases[i], bitcount(test_cases[i]));
    }

    return 0;
}

/* 计算 x 的二进制表示中 1 的个数 */
int bitcount(unsigned int x)
{
    int b = 0;
    while (x != 0)
    {
        x &= x - 1; // 清除最右边的1 (Brian Kernighan 算法)
        b++;
    }
    return b;
}
