//
// Created by AhogeK on 10/24/24.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINES 5000     /* 最大行数 */
#define MAXLEN 1000      /* 每行最大长度 */
#define STORSIZE 10000   /* 存储空间大小 */

/* 读取一行输入 */
int get_line(char* line, int max)
{
    int c = 0, i;
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return c == EOF && i == 0 ? 0 : i;
}

/* 使用动态分配方式读取所有行 */
int readlines_orig(char* lineptr[], int maxlines)
{
    int len, nlines = 0;
    char line[MAXLEN];

    while ((len = get_line(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines)
            return -1;
        char* p = malloc(len);
        if (p == NULL)
            return -1;
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

/* 使用预分配数组方式读取所有行 */
int readlines_new(char* lineptr[], char* linestor, int maxlines)
{
    int len, nlines = 0;
    char* p = linestor;
    char line[MAXLEN];

    while ((len = get_line(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || p + len > linestor + STORSIZE)
            return -1;
        strcpy(p, line);
        lineptr[nlines++] = p;
        p += len;
    }
    return nlines;
}

/* 打印所有行 */
void writelines(char* lineptr[], int nlines)
{
    for (int i = 0; i < nlines; i++)
        printf("%s", lineptr[i]);
}

/* 清空输入缓冲区并重新打开stdin */
void reset_input()
{
    clearerr(stdin); // 清除EOF标志
    printf("\n按回车键继续...");
    while (getchar() != '\n'); // 等待用户按回车
}

int main()
{
    char* lineptr[MAXLINES];
    char linestor[STORSIZE];
    int nlines;
    clock_t start, end;
    double time_used;

    /* 测试原始版本 */
    printf("=== 测试原始版本（动态分配） ===\n");
    printf("请输入多行文本 (按Ctrl+D结束):\n");

    start = clock();
    nlines = readlines_orig(lineptr, MAXLINES);
    end = clock();

    if (nlines >= 0)
    {
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\n读取了 %d 行\n", nlines);
        printf("用时: %f 秒\n", time_used);
        printf("内容如下:\n");
        writelines(lineptr, nlines);

        /* 释放内存 */
        for (int i = 0; i < nlines; i++)
            free(lineptr[i]);
    }
    else
    {
        printf("错误：输入行数过多\n");
        return 1;
    }

    /* 重置输入流 */
    reset_input();

    /* 测试新版本 */
    printf("\n=== 测试新版本（预分配数组） ===\n");
    printf("请输入多行文本 (按Ctrl+D结束):\n");

    start = clock();
    nlines = readlines_new(lineptr, linestor, MAXLINES);
    end = clock();

    if (nlines >= 0)
    {
        time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\n读取了 %d 行\n", nlines);
        printf("用时: %f 秒\n", time_used);
        printf("内容如下:\n");
        writelines(lineptr, nlines);
    }
    else
    {
        printf("错误：输入行数过多或存储空间不足\n");
        return 1;
    }

    return 0;
}
