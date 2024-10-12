//
// 编写一个将输入复制到输出的程序，并将其中的制表符替换为\t，将回退符替换为\b，将反斜杠替换为\\。这样可以将制表符和回退符以可见的方式显示出来。
// Created by Ahoge Knight on 2023/3/2.
//

#include <stdio.h>

int main()
{
    FILE* file;
    int c;

    file = fopen("../test.txt", "r");
    if (file == NULL)
    {
        perror("无法打开文件");
        return 1;
    }

    while ((c = fgetc(file)) != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
        }
        else if (c == '\b')
        {
            printf("\\b");
        }
        else if (c == '\\')
        {
            printf("\\\\");
        }
        else
        {
            putchar(c);
        }
    }

    fclose(file);

    return 0;
}
