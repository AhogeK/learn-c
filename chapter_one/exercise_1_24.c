//
// 编写一个程序，查找C语言程序中的基本语法错误，如圆括号、方括号、花括号不配对等。要正确处理引号（包括单引号和双引号）、转义字符序列与注释。
// ps. 不准备写的很详细，就新手水平的代码。
// Created by AhogeK on 10/16/24.
//

#include <stdio.h>

#define MAX_LINE_LENGTH 1000

void check_syntax_errors(FILE* input);

int main()
{
    const char* filename = "../test_wrong_c.c";

    FILE* input = fopen(filename, "r");
    if (input == NULL)
    {
        printf("无法打开文件 %s。\n", filename);
        return 1;
    }

    check_syntax_errors(input);

    fclose(input);
    return 0;
}

void check_syntax_errors(FILE* input)
{
    char line[MAX_LINE_LENGTH];
    int parentheses = 0, brackets = 0, braces = 0; // 不同类型括号计数
    int in_string = 0, in_char = 0, in_multiline_comment = 0; // 判断是否在特殊语法结构内
    int line_number = 0;

    // 不匹配行号记录
    int unmatched_parentheses_line = -1;
    int unmatched_brackets_line = -1;
    int unmatched_braces_line = -1;

    while (fgets(line, sizeof(line), input) != NULL)
    {
        line_number++;

        for (int i = 0; line[i] != '\0'; i++)
        {
            if (in_multiline_comment)
            {
                if (line[i] == '*' && line[i + 1] == '/')
                {
                    in_multiline_comment = 0;
                    i++;
                }
                continue;
            }

            if (line[i] == '/' && line[i + 1] == '/')
            {
                // 单行注释，忽略本行剩余部分
                break;
            }

            if (line[i] == '/' && line[i + 1] == '*')
            {
                in_multiline_comment = 1;
                i++;
                continue;
            }

            if (in_string)
            {
                if (line[i] == '"' && line[i - 1] != '\\')
                {
                    in_string = 0;
                }
                continue;
            }

            if (in_char)
            {
                if (line[i] == '\'' && line[i - 1] != '\\')
                {
                    in_char = 0;
                }
                continue;
            }

            if (line[i] == '"')
            {
                in_string = 1;
            }
            else if (line[i] == '\'')
            {
                in_char = 1;
            }
            else if (line[i] == '(')
            {
                if (parentheses == 0)
                {
                    unmatched_parentheses_line = line_number;
                }
                parentheses++;
            }
            else if (line[i] == ')')
            {
                parentheses--;
                if (parentheses == 0)
                {
                    unmatched_parentheses_line = -1;
                }
                else if (parentheses < 0)
                {
                    printf("缺少左圆括号，在第 %d 行。\n", line_number);
                    parentheses = 0;
                }
            }
            else if (line[i] == '[')
            {
                if (brackets == 0)
                {
                    unmatched_brackets_line = line_number;
                }
                brackets++;
            }
            else if (line[i] == ']')
            {
                brackets--;
                if (brackets == 0)
                {
                    unmatched_brackets_line = -1;
                }
                else if (brackets < 0)
                {
                    printf("缺少左方括号，在第 %d 行。\n", line_number);
                    brackets = 0;
                }
            }
            else if (line[i] == '{')
            {
                if (braces == 0)
                {
                    unmatched_braces_line = line_number;
                }
                braces++;
            }
            else if (line[i] == '}')
            {
                braces--;
                if (braces == 0)
                {
                    unmatched_braces_line = -1;
                }
                else if (braces < 0)
                {
                    printf("缺少左花括号，在第 %d 行。\n", line_number);
                    braces = 0;
                }
            }
        }
    }

    if (parentheses > 0)
    {
        printf("缺少右圆括号，问题可能出现在第 %d 行或之后。\n", unmatched_parentheses_line);
    }
    if (brackets > 0)
    {
        printf("缺少右方括号，问题可能出现在第 %d 行或之后。\n", unmatched_brackets_line);
    }
    if (braces > 0)
    {
        printf("缺少右花括号，问题可能出现在第 %d 行或之后。\n", unmatched_braces_line);
    }
    if (parentheses == 0 && brackets == 0 && braces == 0)
    {
        printf("没有发现括号匹配错误。\n");
    }
}
