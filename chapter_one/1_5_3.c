//
// Created by Ahoge Knight on 2022/4/20.
//

#include <stdio.h>

/* 统计输入字符数： 版本1 */
int main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld \n", nc);
}
