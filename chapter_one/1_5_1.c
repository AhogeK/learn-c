//
// Created by Ahoge Knight on 2022/4/20.
//

#include <stdio.h>

/*
 * 将输入复制到输出: 版本1
 */
int main()
{
    int c;

    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
}
