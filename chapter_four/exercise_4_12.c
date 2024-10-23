//
// Created by AhogeK on 10/23/24.
//

#include <limits.h>
#include <stdio.h>

void itoa_recursive(int n, char s[], int* i)
{
    // 只在第一次调用时处理负号
    if (*i == 0 && n < 0)
    {
        s[(*i)++] = '-';
        // 特殊处理 INT_MIN
        if (n == INT_MIN)
        {
            long long temp = -(long long)n;
            itoa_recursive(temp / 10, s, i);
            s[(*i)++] = temp % 10 + '0';
            return;
        }
        n = -n;
    }

    // 递归处理
    if (n >= 10)
    {
        itoa_recursive(n / 10, s, i);
    }

    s[(*i)++] = n % 10 + '0';
    s[*i] = '\0';
}

void itoa(int n, char s[])
{
    int i = 0;
    itoa_recursive(n, s, &i);
}

int main()
{
    char buffer[20];
    itoa(-12345, buffer);
    printf("转换后的字符串: %s\n", buffer);

    // 测试更多情况
    itoa(12345, buffer);
    printf("转换后的字符串: %s\n", buffer);

    itoa(INT_MIN, buffer);
    printf("转换后的字符串: %s\n", buffer);

    itoa(0, buffer);
    printf("转换后的字符串: %s\n", buffer);

    return 0;
}
