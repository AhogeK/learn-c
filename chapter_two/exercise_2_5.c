//
// Created by Ahoge Knight on 2022/11/19.
//

#include <stdio.h>
#include <string.h>

/* 练习 2-5: 编写函数 any(s1, s2), 将字符串 s2 中的任一字符在字符串 s1 中第一次出现的位置作为结果返回。不包含则返回 -1。 */
int any(const char s1[], const char s2[])
{
    if (s1 == NULL || s2 == NULL || *s1 == '\0' || *s2 == '\0')
    {
        return -1; // 处理空字符串或 NULL 指针
    }

    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (strchr(s2, s1[i]) != NULL)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char s1[] = "Hello World";
    char s2[] = "o";
    printf("Test 1: %d\n", any(s1, s2)); // 应该返回 4

    char s3[] = "Programming";
    char s4[] = "xyz";
    printf("Test 2: %d\n", any(s3, s4)); // 应该返回 -1

    char s5[] = "";
    char s6[] = "a";
    printf("Test 3: %d\n", any(s5, s6)); // 应该返回 -1

    printf("Test 4: %d\n", any(s1, "")); // 应该返回 -1

    return 0;
}
