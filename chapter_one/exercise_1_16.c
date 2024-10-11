//
// Created by AhogeK on 10/10/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 1000

char* get_line(FILE* file, int* len);
char* resizeBuffer(char* buffer, int* capacity);

/* 修改 1_9_1.c 代码，使之可以打印任意长度的输入行的长度，并尽可能多地打印文本 */
int main()
{
    char* line = NULL;
    char* longest = NULL;
    int len, max = 0;

    FILE* file = fopen("../test.txt", "r");
    if (file == NULL)
    {
        perror("无法打开文件");
        return 1;
    }

    while ((line = get_line(file, &len)) != NULL)
    {
        printf("行长度：%d\n", len);
        printf("行内容：%s\n", line);

        if (len > max)
        {
            max = len;
            free(longest);
            longest = strdup(line);
        }
        free(line);
    }

    if (max > 0)
    {
        printf("\n最长的行长度：%d\n", max);
        printf("最长的行内容：%s\n", longest);
    }

    free(longest);
    fclose(file);

    return 0;
}

char* get_line(FILE* file, int* len)
{
    int capacity = INITIAL_BUFFER_SIZE;
    char* buffer = malloc(capacity);
    if (!buffer) return NULL;

    int i = 0;
    int c;
    while ((c = fgetc(file)) != EOF && c != '\n')
    {
        if (i >= capacity - 1)
        {
            buffer = resizeBuffer(buffer, &capacity);
            if (!buffer) return NULL;
        }
        buffer[i++] = c;
    }

    if (c == '\n')
    {
        buffer[i++] = c;
    }

    if (i == 0 && c == EOF)
    {
        free(buffer);
        return NULL;
    }

    buffer[i] = '\0';
    *len = i;
    return buffer;
}

char* resizeBuffer(char* buffer, int* capacity)
{
    *capacity *= 2;
    char* newBuffer = realloc(buffer, *capacity);
    if (!newBuffer)
    {
        free(buffer);
        return NULL;
    }
    return newBuffer;
}
