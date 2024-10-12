//
// 编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替。
// Created by Ahoge Knight on 2023/3/2.
//

#include <stdio.h>

int main()
{
    FILE* file;
    int c;
    int last_char_was_space = 0; // 上一个字符是否是空格
    int index = 0;

    file = fopen("../test.txt", "r");
    if (file == NULL)
    {
        perror("无法打开文件");
        return 1;
    }

    while ((c = fgetc(file)) != EOF)
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

    fclose(file);

    return 0;
}
