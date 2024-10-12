//
// Created by Ahoge Knight on 2022/11/19.
//

#include <stdio.h>

/* strcat 函数: 将字符串 t 连接到字符串 s 的尾部; s 必须有足够大的空间 */
void strcat_test(char s[], const char t[])
{
    int i;
    int j;

    i = 0;
    j = 0;

    while (s[i] != '\0') /* 判断是否为字符串的尾部 */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* 拷贝t */
        ;
}

int main()
{
    char testStr[1000] = "Hello World!";
    char testStr2[] = "林滋剑";
    strcat_test(testStr, testStr2);
    printf("%s", testStr);
}
