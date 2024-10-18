//
// Created by AhogeK on 10/18/24.
//

#include <stdio.h>

int main() /* 统计数字、空白符及其他字符 */
{
    FILE* file;
    int c, i, nwhite, nother, ndigit[10];

    file = fopen("../test.txt", "r");
    if (file == NULL)
    {
        printf("无法打开文件\n");
        return 1;
    }

    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;
    while ((c = fgetc(file)) != EOF)
    {
        switch (c)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            ndigit[c - '0']++;
            break;
        case ' ':
        case '\n':
        case '\t':
            nwhite++;
            break;
        default:
            nother++;
            break;
        }
    }

    fclose(file);

    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
    return 0;
}
