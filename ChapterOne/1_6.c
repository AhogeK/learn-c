//
// Created by ahogek on 9/16/21.
//
#include <stdio.h>

#define MAXWL 5         /* 最长单词长度 */
#define MAXNO 12        /* 总单词数 */
#define TOTAL_CHARS 128 /* 字符数的总长为128, 0 - 127 */

void array_1_6(FILE *f)
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;


    while ((c = getc(f)) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
    fclose(f);
}

void exercise_1_13(FILE *f)
{
    int c, temp;
    while ((c = fgetc(f)) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (temp != ' ' && temp != '\n' && temp != '\t')
            {
                putchar('\n');
                temp = c;
            }
        } else
        {
            putchar('*');
            temp = c;
        }
    }
}

void exercise_1_13_2(FILE *f)
{
    int word[MAXNO];
    int i, c, j, nc, nw;

    for (i = 0; i < MAXNO; ++i)
        word[i] = 0;

    nc = nw = 0;

    int temp;
    while ((c = fgetc(f)) != EOF)
    {
        ++nc;
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (temp != ' ' && temp != '\n' && temp != '\t')
            {
                /* 在单词长度中不包含空 */
                word[nw] = nc - 1;
                ++nw;
                /* 为下个重置单词长度 */
                nc = 0;
                temp = c;
            }
        } else
            temp = c;
    }
    for (i = MAXWL; i >= 1; --i)
    {
        for (j = 0; j <= nw; ++j)
        {
            if (i <= word[j])
                putchar('*');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

void exercise_1_14(FILE *f)
{
    int c, i, j;

    int _char[TOTAL_CHARS];
    for (i = 0; i < TOTAL_CHARS; ++i)
        _char[i] = 0;

    while ((c = fgetc(f)) != EOF)
        _char[c] = _char[c] + 1;

    for (i = 0; i < TOTAL_CHARS; ++i) {
        putchar(i);

        for (j = 0; j < _char[i]; ++j)
            putchar('*');

        putchar('\n');
    }
}

int main() {
    FILE *fptr;
    fptr = (fopen("../test.txt", "r"));
    array_1_6(fptr);
    fclose(fptr);
}