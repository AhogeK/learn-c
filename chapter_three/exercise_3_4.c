//
// Created by AhogeK on 10/19/24.
//

#include <stdio.h>
#include <string.h>
#include <limits.h> // 包含 INT_MIN 和 INT_MAX

#define MAX_LINE 1000

void itoa(int n, char s[]);
void reverse(char s[]);

/*
 * 在标准的 itoa 实现中，通常会将负数转换为正数来处理。然而，对于最大的负数，
 * 直接取反会导致溢出，因为它的绝对值无法在正数范围内表示。这就是为什么标准的
 * itoa 函数无法处理最大的负数。
 */
int main()
{
    int number = INT_MIN;
    char str[MAX_LINE];
    printf("Integer %d printed as\nString: ", number);
    itoa(number, str);
    printf("%s\n", str);
    return 0;
}

void itoa(int n, char s[])
{
    int i = 0;
    int sign = n;

    // 处理负数的特殊情况
    if (n == INT_MIN)
    {
        n = -(n + 1); // 先加1避免溢出
        s[i++] = n % 10 + 1 + '0'; //处理最后一位
        n /= 10;
    }
    else
        n = n < 0 ? -n : n;

    do
        s[i++] = n % 10 + '0';
    while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
