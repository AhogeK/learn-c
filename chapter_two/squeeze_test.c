//
// Created by Ahoge Knight on 2022/11/2.
//

#include <stdio.h>

/* squeeze函数: 从字符串s中删除字符c */
void squeeze(char s[], char c)
{
    int i = 0;
    int j = 0;
    for (; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

int main()
{
    char testStr[] = "hello world";
    squeeze(testStr, 'l');
    printf("%s", testStr);
}
