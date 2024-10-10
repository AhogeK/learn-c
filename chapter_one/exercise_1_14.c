//
// Created by AhogeK on 10/10/24.
//

#include <stdio.h>

#define TOTAL_CHARS 128 // ASCII
#define LABEL_WIDTH 4   // 标签宽度，用于对齐

void print_char(int c)
{
    // 检查并打印转义字符的字符串表示
    switch (c)
    {
    case '\n':
        printf("%-*s", LABEL_WIDTH, "\\n");
        break;
    case '\t':
        printf("%-*s", LABEL_WIDTH, "\\t");
        break;
    case '\b':
        printf("%-*s", LABEL_WIDTH, "\\b");
        break;
    case '\r':
        printf("%-*s", LABEL_WIDTH, "\\r");
        break;
    case '\f':
        printf("%-*s", LABEL_WIDTH, "\\f");
        break;
    case '\v':
        printf("%-*s", LABEL_WIDTH, "\\v");
        break;
    case '\\':
        printf("%-*s", LABEL_WIDTH, "\\\\");
        break;
    default:
        if (c < 32 || c == 127)
        {
            // 打印不可见字符的ASCII码
            printf("%-*s", LABEL_WIDTH, "\\x");
        }
        else
        {
            // 打印可见字符
            printf("%-*c", LABEL_WIDTH, c);
        }
    }
}

/* 编写一个程序，打印输入中各个字符出现频度的直方图 */
int main()
{
    FILE* file;
    int c;
    int char_count[TOTAL_CHARS] = {0};

    file = fopen("../test.txt", "r");
    if (file == NULL)
    {
        perror("无法打开文件");
        return 1;
    }

    // 读取输入并统计每个字符的出现次数
    while ((c = fgetc(file)) != EOF)
    {
        if (c < TOTAL_CHARS)
        {
            char_count[c]++;
        }
    }

    // 打印直方图
    printf("字符频度直方图:\n");
    for (int i = 0; i < TOTAL_CHARS; ++i)
    {
        if (char_count[i] > 0)
        {
            print_char(i);
            printf(": ");
            for (int j = 0; j < char_count[i]; ++j)
            {
                printf("#");
            }
            printf("\n");
        }
    }

    fclose(file);

    return 0;
}
