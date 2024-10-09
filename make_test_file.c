//
// 创建测试文本文件
// Created by Jonah Shi on 10/9/24.
//

#include <stdio.h>

int main() {
    FILE *file;
    const char *filename = "../test.txt";

    file = fopen(filename, "w");
    if (file == NULL) {
        perror("无法创建文件");
        return 1;
    }

    // 写入多行文本，包括空格、制表符、连续空格、回退符和反斜杠
    fprintf(file, "This is the first line with spaces\n");
    fprintf(file, "This is the second line with a tab character\t\n");
    fprintf(file, "This is the third line with  consecutive spaces\n");
    fprintf(file, "This is the fourth line with a backspace character\b\n");
    fprintf(file, "This is the fifth line with a backslash \\\n");

    fclose(file);

    printf("文件 %s 创建成功\n", filename);

    return 0;
}