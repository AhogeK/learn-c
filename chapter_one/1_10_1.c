//
// 1.10 外部变量与作用域
// Created by AhogeK on 10/11/24.
//

#include <stdio.h>

#define MAX_LINE 1000

int max;
char line[MAX_LINE];
char longest[MAX_LINE];
FILE* file;

int get_line(void);
void copy(void);

/* 打印最长的输入行，特别版本 */
int main()
{
    int len;
    extern int max;
    extern char longest[];
    extern FILE* file;

    file = fopen("../test.txt", "r");
    if (file == NULL)
    {
        perror("无法打开文件");
        return 1;
    }

    max = 0;
    while ((len = get_line()) > 0)
        if (len > max)
        {
            max = len;
            copy();
        }
    if (max > 0)
        printf("%s", longest);

    fclose(file);
    return 0;
}

int get_line()
{
    int c, i;
    extern char line[];
    extern FILE *file;

    for (i = 0; i < MAX_LINE - 1 && (c = fgetc(file)) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy()
{
    int i;
    extern char line[], longest[];

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
