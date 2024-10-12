//
// 编写一个程序，以每行一个单词的形式打印其输入。
// Created by Ahoge Knight on 2023/3/17.
//

#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    FILE* file;
    int c;
    int state = OUT;

    file = fopen("../test.txt", "r");
    if (file == NULL)
    {
        perror("无法打开文件");
        return 1;
    }

    while ((c = fgetc(file)) != EOF)
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

    fclose(file);

    return 0;
}
