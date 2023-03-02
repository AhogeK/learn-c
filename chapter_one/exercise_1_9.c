//
// Created by Ahoge Knight on 2023/3/2.
//

#include <stdio.h>

int main()
{
    int c;
    int last_char_was_space = 0; // 上一个字符是否是空格
    int index = 0;

    while ((c = getchar()) != EOF)
    {
        if (index == 0)
        {
            putchar('\n');
        }
        index++;
        if (c == ' ')
        {
            if (last_char_was_space == 0)
            {
                putchar(c);
                last_char_was_space = 1;
            }
        }
        else
        {
            putchar(c);
            last_char_was_space = 0;
        }
    }
    return 0;
}