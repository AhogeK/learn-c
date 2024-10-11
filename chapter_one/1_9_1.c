//
// 1.9 字符数组
// Created by AhogeK on 10/10/24.
//

#include <stdio.h>
#define MAXLINE 1000 /* 允许输入行的最大长度 */

int get_line(char line[], int maxline, FILE* file);
void copy(char to[], char from[]);

/* 打印最长的输入行 */
int main()
{
    FILE* file;
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    file = fopen("../test.txt", "r");
    if (file == NULL)
    {
        perror("无法打开文件");
        return 1;
    }

    max = 0;
    while ((len = get_line(line, MAXLINE, file)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) /* 存在这样的行 */
    {
        printf("%s", longest);
    }

    fclose(file);

    return 0;
}

/* getLine函数：将一行读入到s中并返回其长度 */
int get_line(char line[], int maxline, FILE* file)
{
    int c, i;

    for (i = 0; i < maxline - 1 && (c = fgetc(file)) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy函数：将from复制到to；这里假定to足够大 */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}