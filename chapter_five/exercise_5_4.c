//
// Created by AhogeK on 10/24/24.
//

#include <stdio.h>

/* strend: 如果字符串t出现在字符串s的尾部，返回1；否则返回0 */
int strend(const char* s, const char* t)
{
    const char* s_start = s;
    const char* t_start = t;

    // 移动s和t到各自字符串的末尾
    while (*s)
        s++;
    while (*t)
        t++;

    // 从后向前比较
    while (t >= t_start && s >= s_start && *t == *s)
    {
        t--;
        s--;
    }

    // 如果t已经比较完并匹配，返回1；否则返回0
    return t < t_start;
}

int main()
{
    const char* s = "hello world";
    const char* t = "world";

    if (strend(s, t))
        printf("字符串 \"%s\" 出现在 \"%s\" 的尾部\n", t, s);
    else
        printf("字符串 \"%s\" 没有出现在 \"%s\" 的尾部\n", t, s);

    return 0;
}
