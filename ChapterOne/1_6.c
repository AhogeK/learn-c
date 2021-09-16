//
// Created by ahogek on 9/16/21.
//
#include <stdio.h>

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