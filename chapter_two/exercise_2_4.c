//
// Created by Ahoge Knight on 2022/11/19.
//

#include <stdio.h>

/* 练习2-4 重新编写函数 squeeze(s1, s2) 将字符串 s1 中任何与 s2 中的字符匹配的字符都删除 */
void squeeze(char s1[], const char s2[])
{
    int i, j, k;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        for (k = 0; s2[k] != '\0' && s2[k] != s1[i]; k++); // 简化内层循环
        if (s2[k] == '\0')
        {
            // s1[i] 不在 s2 中
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0'; // 添加字符串终止符，非常重要！
}

int main()
{
    char s1[] = "Hello World";
    char s2[] = " lo"; // 测试多个字符
    squeeze(s1, s2);
    printf("%s\n", s1); //  输出: HeWrd

    char s3[] = "abcdefg";
    char s4[] = "xyz"; // 测试不包含的字符
    squeeze(s3, s4);
    printf("%s\n", s3); // 输出: abcdefg

    return 0;
}
