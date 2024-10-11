//
// Created by AhogeK on 10/11/24.
//

#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

void reverse(char s[]);

/* 编写一个reverse(s),将字符串s中的字符顺序颠倒过来。使用该函数编写一个程序每次颠倒一个输入行中的字符顺序 */
int main()
{
    char line[MAX_LINE];

    while (fgets(line, MAX_LINE, stdin) != NULL)
    {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

void reverse(char s[])
{
    int i, j;
    char temp;

    int length = strlen(s);
    if (s[length - 1] == '\n')
    {
        length--;
    }

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
