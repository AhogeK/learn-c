//
// Created by AhogeK on 10/10/24.
//

#include <stdio.h>

#define MAX_WORD_LENGTH 10

void print_horizontal_histogram(int word_length[], int max_length)
{
    printf("水平直方图\n");
    for (int i = 1; i <= max_length; ++i)
    {
        printf("%2d: ", i);
        for (int j = 0; j < word_length[i]; ++j)
        {
            printf("#");
        }
        printf("\n");
    }
}

void print_vertical_histogram(int word_lengths[], int max_length)
{
    int max_count = 0;
    for (int i = 1; i <= max_length; ++i)
    {
        if (word_lengths[i] > max_count)
        {
            max_count = word_lengths[i];
        }
    }

    printf("垂直直方图：\n");
    for (int i = max_count; i > 0; --i)
    {
        for (int j = 1; j <= max_length; ++j)
        {
            if (word_lengths[j] >= i)
            {
                printf(" # ");
            }
            else
            {
                printf("   ");
            }
        }
        putchar('\n');
    }

    for (int i = 1; i <= max_length; ++i)
    {
        printf("---");
    }
    putchar('\n');
    for (int i = 1; i <= max_length; ++i)
    {
        printf("%2d ", i);
    }
    putchar('\n');
}

/* 编写一个程序， 打印输入中单词长度的直方图。水平方向的直方图比较容易绘制，垂直方向则要困难些 */
int main()
{
    FILE* file;
    int c, length = 0;
    int word_lengths[MAX_WORD_LENGTH + 1] = {0};

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
            if (length > 0)
            {
                if (length > MAX_WORD_LENGTH)
                {
                    length = MAX_WORD_LENGTH;
                }
                ++word_lengths[length];
                length = 0;
            }
        }
        else
        {
            ++length;
        }
    }

    fclose(file);

    // 打印
    print_horizontal_histogram(word_lengths, MAX_WORD_LENGTH);
    print_vertical_histogram(word_lengths, MAX_WORD_LENGTH);

    return 0;
}
