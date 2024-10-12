//
// Created by Ahoge Knight on 2022/10/12.
//

#include <printf.h>

/* atoi函数: 将字符串s转换为相应的整型数 */
int atoi(const char s[])
{
    int n;

    n = 0;

    for (int i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int main()
{
    printf("%d", atoi("15"));
}
