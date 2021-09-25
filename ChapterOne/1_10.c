//
// 1.10 外部变量与作用域
// Created by ahogek on 9/25/21.
//

#include <stdio.h>

#define MAXLINE 1000    /* 允许的输入行的最大长度 */
#define TABINC 4

int max;                /* 到目前为止发现的最长行长度 */
char line[MAXLINE];     /* 当前的输入行 */
char longest[MAXLINE];   /* 用于保存最长的行 */

int get_line2(FILE*);

void copy2(void);

/* 打印最长的输入行; 特别版本 */
void external_variable_and_scope(FILE *f)
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while((len = get_line2(f)) > 0)
        if (len > max)
        {
            max = len;
            copy2();
        }
    if (max > 0)
        printf("%s", longest);
}

/* get_line: 外部变量版 */
int get_line2(FILE *f)
{
    int c, i;
    extern char line[];
    for (i = 0; i< MAXLINE - 1 && (c = fgetc(f)) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: 外部变量版本 */
void copy2()
{
    int i;
    extern char line[], longest[];
    i =0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}

/**
 * 编写程序 detab，将输入中的制表符替换成适当数目的空格,使空格充满到下一个制表符终止位的地方。
 *
 * @param f 文本文件
 */
void exercise_1_20(FILE *f)
{
    int nb, pos, c;
    nb = 0;
    pos = 1;

    while ((c = fgetc(f)) != EOF)
    {
        if (c == '\t')
        {
            nb = TABINC;

            while (nb > 0)
            {
                putchar('#');
                ++pos;
                --nb;
            }
        }
        else if(c == '\n')
        {
            putchar(c);
            pos = 1;
        }
        else
        {
            putchar(c);
            ++pos;
        }
    }
}