//
// Created by Jonah Shi on 10/10/24.
//

#include <stdio.h>

/* 统计各个数字、空白符及其他字符出现次数 */
int main() {
    FILE *file;
    int c, i, nwhite, nother;
    int ndigit[10];

    file = fopen("../test.txt", "r");
    if (file == NULL) {
        perror("无法打开文件");
        return 1;
    }

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = fgetc(file)) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);

    fclose(file);
    return 0;
}