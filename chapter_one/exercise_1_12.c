//
// Created by Ahoge Knight on 2023/3/17.
//

#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c;
    int state = OUT;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
            {
                putchar('\n');
            }
            state = OUT;
        }
        else
        {
            state = IN;
            putchar(c);
        }
    }

    return 0;
}