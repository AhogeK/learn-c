//
// Created by ahogek on 9/13/21.
//
#include <stdio.h>

void firstInputAndOutput()
{
    char c = getchar();
    putchar(c);
}

/**
 * 文件复制
 */
void fileCopy()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
}

/**
 * 练习 1-6 验证表达式getchar()!=EOF的值是0还是1
 */
void verifyGetchar()
{
    char value;
    value = (getchar() != EOF);
    printf("%d\n", value);
}

/**
 * 练习1-7 编写一个打印EOF值的程序
 */
void printEOF()
{
    printf("This is EOF: %d", EOF);
}

/**
 * 统计输入的字符数：版本1
 */
void charCount()
{
    long nc;
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}

/**
 * 统计输入的字符数：版本2
 */
void charCountV2()
{
    double nc;
    for (nc = 0; getchar() != EOF; ++nc);
    printf("%.0f\n", nc);
}

/**
 * 统计输入的行数
 */
void rowCount()
{
    int c, nl;
    nl = 0;
    while((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}