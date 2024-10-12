//
// 编写程序entab，将空格串替换为最少数量的制表符和空格，但要保持单词之间的间隔不变。
// 假设制表符终止位的位置与练习1-20代码的detab程序的情况相同。
// 当使用一个制表符或者一个空格都可以到达下一个制表符终止位时，选用哪种替换字符比较好？
// 当两者都可以达到下一个制表符终止位时，通常选择制表符，因为它可以减少字符数，从而节省存储空间。
//
// Created by AhogeK on 10/11/24.
//

#include <stdio.h>

#define TAB_WIDTH 4

void entab(void);
void print_with_tabs(char* line);

int main()
{
    printf("请输入文本（按Ctrl（Command）+D结束输入）：\n");
    entab();
    return 0;
}

void entab()
{
    int c, space_count, column;
    char line[1024]; // 存储一行输入
    int line_index = 0;

    space_count = 0;
    column = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            space_count++;
        }
        else
        {
            while (space_count > 0)
            {
                if (space_count >= TAB_WIDTH - (column % TAB_WIDTH))
                {
                    line[line_index++] = '\t'; // 将制表符存储到line中
                    space_count -= TAB_WIDTH - (column % TAB_WIDTH);
                    column += TAB_WIDTH - (column % TAB_WIDTH);
                }
                else
                {
                    line[line_index++] = ' '; // 将空格存储到line中
                    space_count--;
                    column++;
                }
            }
            line[line_index++] = c; // 将其他字符存储到line中
            if (c == '\n')
            {
                line[line_index] = '\0'; // 添加字符串终止符
                printf("%s", line); // 打印原始行
                print_with_tabs(line); // 打印带\t的行
                line_index = 0; // 重置line_index
                column = 0;
            }
            else if (c == '\t')
            {
                column += TAB_WIDTH - (column % TAB_WIDTH);
            }
            else
            {
                column++;
            }
        }
    }
}

void print_with_tabs(char* line)
{
    while (*line != '\0')
    {
        if (*line == '\t')
        {
            printf("\\t"); // 将制表符显示为\t
        }
        else
        {
            putchar(*line);
        }
        line++;
    }
    printf("\n");
}
