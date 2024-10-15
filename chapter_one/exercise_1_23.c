//
// 编写一个程序，删除C语言程序中所有的注释语句。要正确处理带引号的字符串与字符常量。在C语言中，注释不允许嵌套。
// Created by AhogeK on 10/15/24.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

void remove_comments(FILE* input);
void handle_quoted_content(const char* line, char* output, int* i, int* output_index, char quote_char);

int main()
{
    // 编译目录外的文件
    const char* filename = "../chapter_one/exercise_1_23.c";

    FILE* input = fopen(filename, "r");
    if (input == NULL)
    {
        printf("无法打开文件 %s。\n", filename);
        return 1;
    }

    /*
     * 这是用于检测多行注释
     * 删除注释
     */
    remove_comments(input);

    fclose(input);

    return 0;
}

void remove_comments(FILE* input)
{
    char line[MAX_LINE_LENGTH];
    int in_block_comment = 0; // 是否在多行注释中
    int last_line_was_comment = 0; // 标记上一行是否是注释

    while (fgets(line, sizeof(line), input) != NULL)
    {
        char output[MAX_LINE_LENGTH] = ""; //用于存储处理后的文本
        int output_index = 0;
        int i = 0;
        int line_has_content = 0; // 当前行是否有内容
        int original_line_empty = 1; // 原本的行是否是空行

        // 检查原本的行是否是空行
        for (int j = 0; line[j] != '\0'; j++)
        {
            if (!isspace(line[j]))
            {
                original_line_empty = 0;
                break;
            }
        }

        // 文本处理主逻辑
        while (line[i] != '\0')
        {
            // 多行注释处理
            if (in_block_comment)
            {
                if (line[i] == '*' && line[i + 1] == '/')
                {
                    in_block_comment = 0;
                    i += 2;
                }
                else
                {
                    i++;
                }
                continue;
            }

            if (line[i] == '"' || line[i] == '\'')
            {
                handle_quoted_content(line, output, &i, &output_index, line[i]);
                line_has_content = 1;
            }
            else if (line[i] == '/' && line[i + 1] == '/')
            {
                break;
            }
            else if (line[i] == '/' && line[i + 1] == '*')
            {
                in_block_comment = 1;
                i += 2;
            }
            else
            {
                output[output_index++] = line[i++];
                if (!isspace(line[i - 1]))
                {
                    line_has_content = 1;
                }
            }
        }

        // 删除行尾空格
        while (output_index > 0 && isspace(output[output_index - 1]))
        {
            output_index--;
        }
        output[output_index] = '\0';

        // 是否输出该行
        if (line_has_content || original_line_empty)
        {
            if (!(last_line_was_comment && output_index == 0))
            {
                printf("%s\n", output);
            }
            last_line_was_comment = 0;
        }
        else
        {
            last_line_was_comment = 1;
        }
    }
}

// 处理字符串或字符常量的通用函数
void handle_quoted_content(const char* line, char* output, int* i, int* output_index, char quote_char)
{
    output[(*output_index)++] = line[(*i)++]; // 复制开始的引号或单引号
    while (line[*i] != '\0')
    {
        output[(*output_index)++] = line[(*i)];
        if (line[*i] == quote_char && line[*i - 1] != '\\')
        {
            // 检测结束
            (*i)++;
            break;
        }
        (*i)++;
    }
}
