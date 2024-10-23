//
// Created by AhogeK on 10/23/24.
//

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE]; // 用于ungetch函数的缓冲区
int bufp = 0; // buf中下一个空闲位置

// 获取一个字符（可能是压回的字符）
int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

// 压回一个字符
void ungetch(const char c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: 缓冲区已满\n");
    else
        buf[bufp++] = c;
}

// 将整个字符串压回到输入中
void ungets(char s[])
{
    unsigned long len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);
}

// 读取输入直到遇到换行符
void read_line(char s[], const int lim)
{
    char c = EOF;
    int i;
    for (i = 0; i < lim - 1 && (c = (char)getch()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
}

int main()
{
    char line[BUFSIZE];
    char test_string[] = "Hello, World!";

    printf("原始输入：");
    read_line(line, BUFSIZE);
    printf("读取的行：%s", line);

    printf("\n压回字符串：%s\n", test_string);
    ungets(test_string);

    printf("再次读取：");
    read_line(line, BUFSIZE);
    printf("读取的行：%s", line);

    printf("\n原始输入：");
    read_line(line, BUFSIZE);
    printf("读取的行：%s", line);

    return 0;
}
