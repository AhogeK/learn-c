//
// Created by Ahoge Knight on 2022/4/20.
//

#include <stdio.h>

/* 统计输入的行数 */
int main()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
