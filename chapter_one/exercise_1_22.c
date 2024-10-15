//
// 编写一个程序，把较长的输入行“折”成短一些的两行或多行，折行的位置在输入行的第n列之前的最后一个非空格之后。
// 要保证程序能智能地处理输入行很长以及在制定的列前没有空格或制表符的情况。
// Created by AhogeK on 10/14/24.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LINE_LENGTH 1000
#define DEFAULT_WRAP_COLUMN 80

void wrap_text(char* text, int wrap_column);

int main()
{
    char text[MAX_LINE_LENGTH];
    int wrap_column = DEFAULT_WRAP_COLUMN;

    printf("请输入要折行的文本（最多 %d 个字符）：\n", MAX_LINE_LENGTH - 1);
    if (fgets(text, sizeof(text), stdin) == NULL)
    {
        printf("读取输入时发生错误。程序退出。\n");
        return 1;
    }

    // 删除换行符
    text[strcspn(text, "\n")] = 0;

    int valid_input = 0;
    while (!valid_input)
    {
        printf("请输入折行的列数（默认为 %d）：\n", DEFAULT_WRAP_COLUMN);
        char input[20];
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("读取输入时发生错误。使用默认值。\n");
            break;
        }

        input[strcspn(input, "\n")] = 0;

        // 检查是否是空输入
        if (strlen(input) == 0)
        {
            printf("使用默认值 %d。\n", DEFAULT_WRAP_COLUMN);
            break;
        }

        char* endptr;
        long value = strtol(input, &endptr, 10);

        if (*endptr != '\0')
            printf("无效输入。请输入一个正整数。\n");
        else if (value <= 0 || value > INT_MAX)
            printf("请输入一个在1到%d之间的数。\n", INT_MAX);
        else
        {
            wrap_column = (int)value;
            valid_input = 1;
        }
    }

    wrap_text(text, wrap_column);

    printf("\n折行后的文本：\n%s\n", text);

    return 0;
}

void wrap_text(char* text, int wrap_column)
{
    int line_length = strlen(text);
    int current_position = 0;
    int last_space = -1;
    int chars_since_last_break = 0;

    while (current_position < line_length)
    {
        // 检查当前字符是否为空格
        if (isspace(text[current_position]))
        {
            last_space = current_position;
        }

        chars_since_last_break++;

        // 如果达到或超过折行列
        if (chars_since_last_break >= wrap_column)
        {
            if (last_space != -1 && last_space > current_position - chars_since_last_break)
            {
                // 在上一个空格处折行
                text[last_space] = '\n';
                chars_since_last_break = current_position - last_space;
                last_space = -1;
            }
            else
            {
                // 如果没有合适的空格，向后查找下一个空格
                int next_space = current_position;
                while (next_space < line_length && !isspace(text[next_space]))
                {
                    next_space++;
                }
                if (next_space < line_length)
                {
                    text[next_space] = '\n';
                    chars_since_last_break = current_position - next_space;
                    current_position = next_space;
                }
                else
                {
                    // 如果没有找到空格，强制在当前位置折行
                    text[current_position] = '\n';
                    chars_since_last_break = 0;
                }
            }
        }

        ++current_position;
    }
}
