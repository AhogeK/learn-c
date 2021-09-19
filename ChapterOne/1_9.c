//
// Created by ahogek on 9/17/21.
//
#include <stdio.h>

#define MAXLINE 1000 /* 允许的输入行的最大长度 */
#define LIMIT 80

/* get_line函数：将一行读入s中并返回其长度 */
int get_line(char s[], int lim, FILE *f);

/* copy函数: 将from复制到to;这里假定to足够大 */
void copy(char to[], char from[]);

int mgetline(char s[], int lim, FILE *f);

int ngetline(char line[], int lim, FILE *f);

/* 打印最长的输入行 */
void char_array(FILE *f)
{
    int len; /* 当前行长度 */
    int max; /* 目前为止发现的最长行长度 */
    char line[MAXLINE]; /* 当前的输入行 */
    char longest[MAXLINE]; /* 用于保存最长的行 */

    max = 0;
    while ((len = get_line(line, MAXLINE, f)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* 存在这样的行 */
        printf("%s", longest);
}

int get_line(char s[], int lim, FILE *f)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = fgetc(f)) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void exercise_1_6(FILE *f)
{
    int len, max;
    char line[MAXLINE], maxline[MAXLINE];

    max = 0;

    while ((len = mgetline(line, MAXLINE, f)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(maxline, line);
        }
    }
    if (max > 0)
        printf("%s", maxline);
}

int mgetline(char s[], int lim, FILE *f)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = fgetc(f)) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void exercise_1_17(FILE *f)
{
    int len;
    char line[MAXLINE];

    while ((len = ngetline(line, MAXLINE, f)) > 0)
    {
        if (len > LIMIT)
            printf("%s", line);
    }
}

int ngetline(char line[], int lim, FILE *f)
{
    int i, c;

    for (i = 0; i < lim - 1 && ( c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}