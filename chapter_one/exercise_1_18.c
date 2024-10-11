//
// Created by AhogeK on 10/10/24.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

void trim_trailing_whitespace(char* line);
int is_empty_line(const char* line);

/* 删除每个输入行末尾的空格及制表符，并删除完全是空格的行 */
int main()
{
    char line[MAX_LINE_LENGTH];
    FILE* input_file = fopen("../test.txt", "r");

    if (input_file == NULL)
    {
        perror("无法打开文件\n");
        return 1;
    }

    while (fgets(line, sizeof(line), input_file) != NULL)
    {
        trim_trailing_whitespace(line);
        if (!is_empty_line(line))
        {
            printf("%s", line);
        }
    }

    fclose(input_file);

    return 0;
}

void trim_trailing_whitespace(char* line)
{
    int i = strlen(line) - 1;
    while (i >= 0 && (isspace(line[i]) || line[i] == '\n'))
    {
        line[i] ='\0';
        --i;
    }
    strcat(line, "\n");
}

int is_empty_line(const char* line)
{
    while (*line)
    {
        if (!isspace(*line) && *line != '\n')
        {
            return 0;
        }
        line++;
    }
    return 1;
}
