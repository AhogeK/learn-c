//
// 编写一个统计空格·制表符·换行符个数的程序
// Created by Ahoge Knight on 2023/3/1.
//

#include <stdio.h>

int main()
{
    FILE *file;
    int c;
    int space_count = 0;
    int tab_count = 0;
    int newline_count = 0;

    file = fopen("../test.txt", "r");
    if (file == NULL) {
        perror("无法打开文件");
        return 1;
    }

    while ((c = fgetc(file)) != EOF)
    {
        if (c == ' ')
            space_count++;
        else if (c == '\t')
            tab_count++;
        else if (c == '\n')
            newline_count++;
    }

    fclose(file);

    printf("%-10s: %5d\n", "Spaces", space_count);
    printf("%-10s: %5d\n", "Tabs", tab_count);
    printf("%-10s: %5d\n", "Newlines", newline_count);

    return 0;
}