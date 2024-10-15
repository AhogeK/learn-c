//
// 在不使用运算符&&或||的条件下编写一个与上面的for循环语句等价的循环语句
// Created by AhogeK on 10/16/24.
//

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void original_loop(const char* input, char* output, int lim);
void modified_loop(const char* input, char* output, int lim);

int main()
{
    char input[MAX_LENGTH];
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];
    int lim = 11; // 处理10个字符，最后一个字符为字符串结束符

    printf("请输入一个字符串: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    printf("\n原始循环处理结果: \n");
    original_loop(input, s1, lim);

    printf("\n修改后的循环处理结果: \n");
    modified_loop(input, s2, lim);

    printf("\n比较结果: \n");
    printf("原始循环处理结果: %s (长度: %lu)\n", s1, strlen(s1));
    printf("修改后的循环处理结果: %s (长度: %lu)\n", s2, strlen(s2));

    return 0;
}

void original_loop(const char* input, char* output, int lim)
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = input[i]) != '\0' && c != '\n'; ++i)
        output[i] = c;
    output[i] = '\0';
    printf("处理的字符数: %d\n", i);
}

void modified_loop(const char* input, char* output, int lim)
{
    int i, c;
    for (i = 0; ; ++i)
    {
        if (i >= lim - 1)
        {
            printf("(达到最大长度) ");
            break;
        }
        c = input[i];
        if (c == '\0')
        {
            printf("(遇到字符串结束符) ");
            break;
        }
        if (c == '\n')
        {
            printf("(遇到换行符) ");
            break;
        }
        output[i] = c;
    }
    output[i] = '\0';
    printf("处理的字符数: %d\n", i);
}
