//
// 创建测试文本文件
// Created by Jonah Shi on 10/9/24.
//

#include <stdio.h>

int main()
{
    FILE* file;
    const char* filename = "../test.txt";

    file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("无法创建文件");
        return 1;
    }

    // 写入多行文本，包括空格、制表符、连续空格、回退符和反斜杠
    fprintf(file, "This is the first line with spaces\n");
    fprintf(file, "This is the second line with a tab character\t\n");
    fprintf(file, "This is the third line with  consecutive spaces\n");
    fprintf(file, "This is the fourth line with a backspace character\b\n");
    fprintf(file, "This is the fifth line with a backslash \\\n");
    fprintf(file, "0 11 222 3333 44444 555555 6666666 77777777 888888888 9999999999\n");
    fprintf(file, "The quick brown fox jumps over the lazy dog as the sun sets behind the distant mountains");
    fprintf(file, "This is a line with trailing spaces       \n");
    fprintf(file, "                            \n");

    fclose(file);

    printf("文件 %s 创建成功\n", filename);

    return 0;
}
