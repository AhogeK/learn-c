//
// Created by ahogek on 9/13/21.
//
#include <stdio.h>
#include <assert.h>

#define ESC_CHAR '\\'
#define IN 1 /* 在单词内 */
#define OUT 0 /* 在单词外 */

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
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}

/**
 * 统计空格，制表符，换行符
 */
void statistic()
{
    long c, sn, bn, nn;
    sn, bn, nn = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++sn;
        if (c == '\b')
            ++bn;
        if (c == '\n')
            ++nn;
    }
    printf("空格数量：%ld\t退格数量：%ld\t换行数量：%ld\n", sn, bn, nn);
}

/**
 * 输入复制到输出
 */
void copyOutput()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            putchar(c);
            while ((c = getchar()) == ' ');
        }
        if (c == EOF)
            break;
        putchar(c);
    }
}

/**
 * 转译符号转转译字符串
 */
void toEscString()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
            case '\t':
                putchar(ESC_CHAR);
                putchar('t');
                break;
            case '\b':
                putchar(ESC_CHAR);
                putchar('b');
                break;
            case ESC_CHAR:
                putchar(ESC_CHAR);
                putchar(ESC_CHAR);
            default:
                putchar(c);
                break;
        }
    }
}

/**
 * 单词计数
 */
void wordCount()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("行数：%d\t\t单词数：%d\t字符数：%d\n", nl, nw, nc);
}

/**
 * 1.5.4 练习 1-11 单元测试
 */
void unitTest(void)
{
    FILE *f;
    unsigned long i;
    static char *ws = " \f\t\v";
    static char *al = "abcdefghijklmnopqrstuvwxyz";
    static char *i5 = "a b c d e f g h i j k l m "
                      "n o p q r s t u v w x y z "
                      "a b c d e f g h i j k l m "
                      "n o p q r s t u v w x y z "
                      "a b c d e f g h i j k l m "
                      "n\n";
    /* 输入一个没有字符的文件 */
    f = fopen("test0", "w");
    assert(f != NULL);
    fclose(f);

    /* 输入一个巨大的单词没有换行的文件 */
    f = fopen("test1", "w");
    assert(f != NULL);
    for (i = 0; i < ((66000ul / 26) + 1); i++)
        fputs(al, f);
    fclose(f);

    /* 输入一个包含大量空行的文件 */
    f = fopen("test2", "w");
    assert(f != NULL);
    for (i = 0; i < 66000; i++)
        fputc('\n', f);
    fclose(f);
}
