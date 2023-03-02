//
// Created by Ahoge Knight on 2022/10/12.
//

#include <printf.h>

unsigned long int next = 1;

/* rand函数: 返回值取为 0~32767 的伪随机数 */
unsigned int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}

/* srand函数: 为 rand 函数设置种子数 */
void srand(unsigned int seed)
{
    next = seed;
}

int main()
{
    srand(11111111);
    printf("%d", rand());
}