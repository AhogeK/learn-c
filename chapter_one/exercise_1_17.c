//
// Created by AhogeK on 10/10/24.
//

#include <stdio.h>
#define MAX_LINE 1000
#define MIN_LEN 80

int getLine(char line[], int maxLine, FILE* file);
int copy(char to[], char from[]);

/* 打印长度大于80个字符的所有输入行 */
int main()
{
    int len;
    char line[MAX_LINE];
    char longest[MAX_LINE];

    FILE* file = fopen("../test.txt", "r");

    while ((len = getLine(line, MAX_LINE, file)) > 0)
        if (len > MIN_LEN)
            printf("%s", line);

    fclose(file);

    return 0;
}

int getLine(char line[], int maxLine, FILE* file)
{
    int i, c;

    for (i = 0; i < maxLine - 1 && (c = fgetc(file)) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}