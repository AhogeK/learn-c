//
// Created by AhogeK on 10/23/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAXOP 100   // 操作数或运算符的最大长度
#define NUMBER '0'  // 标识找到一个数

// 用于堆栈的全局变量
double stack[MAXOP];
int sp = 0;

// 函数声明
void push(double f);
double pop(void);
int getop(char* s);

/* 这里仅在普通的逆波兰上进行4-10的练习 */
int main()
{
    char* line = NULL;
    size_t len = 0;
    double op2;

    printf("请输入逆波兰表达式（如：3 4 +）：\n");

    while (getline(&line, &len, stdin) != -1)
    {
        char* token = strtok(line, " \t\n");
        while (token != NULL)
        {
            switch (getop(token))
            {
            case NUMBER:
                {
                    char* endptr;
                    errno = 0; // 重置错误标志
                    double num = strtod(token, &endptr);

                    if (errno == ERANGE)
                        printf("错误：数值超出范围 %s\n", token);
                    else if (endptr == token)
                        printf("错误：无效的数字 %s\n", token);
                    else if (*endptr != '\0')
                        printf("警告：数字后有额外字符 %s\n", token);
                    else
                        push(num);
                }
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("错误：除零\n");
                break;
            default:
                printf("错误：未知的命令 %s\n", token);
                break;
            }
            token = strtok(NULL, " \t\n");
        }
        if (sp > 0)
        {
            printf("结果：%.8g\n", pop());
            if (sp > 0)
                printf("警告：堆栈中还有剩余数值\n");
        }
        printf("请输入下一个逆波兰表达式：\n");
    }

    free(line);
    return 0;
}

void push(double f)
{
    if (sp < MAXOP)
        stack[sp++] = f;
    else
        printf("错误：堆栈满，无法压入 %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    printf("错误：堆栈空\n");
    return 0.0;
}

int getop(char* s)
{
    if (isdigit(s[0]) || (s[0] == '-' && s[1] != '\0')) // 处理负数
        return NUMBER;
    return s[0];
}
