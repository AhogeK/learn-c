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

void verifyGetchar()
{
    char value;
    value = (getchar() != EOF);
    printf("%d\n", value);
}

void printEOF()
{
    printf("This is EOF: %d", EOF);
}