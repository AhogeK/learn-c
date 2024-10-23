//
// Created by AhogeK on 10/22/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <ctype.h>

#define MAXSTACK 100
#define MAXBUFFER 100

typedef struct
{
    double values[MAXSTACK];
    int top;
} Stack;

void stack_init(Stack* s)
{
    s->top = -1;
}

int stack_push(Stack* s, double value)
{
    if (s->top >= MAXSTACK - 1)
    {
        printf("错误：栈已满\n");
        return -1;
    }
    s->values[++s->top] = value;
    return 0;
}

int stack_pop(Stack* s, double* value)
{
    if (s->top < 0)
    {
        printf("错误：栈已空\n");
        return -1;
    }
    *value = s->values[s->top--];
    return 0;
}

int parse_number(const char* str, double* result)
{
    char* endptr;
    errno = 0;
    *result = strtod(str, &endptr);
    if (errno != 0 || *endptr != '\0')
    {
        return -1;
    }
    return 0;
}

double variables[26] = {0};
int variable_set[26] = {0}; // 用于跟踪变量是否已被赋值
double last_printed_value = 0;

int perform_operation(Stack* s, const char* op)
{
    double op1, op2, result = 0;
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "*") == 0 || strcmp(op, "/") == 0)
    {
        if (stack_pop(s, &op1) != 0 || stack_pop(s, &op2) != 0) return -1;
        if (strcmp(op, "+") == 0) result = op2 + op1;
        else if (strcmp(op, "-") == 0) result = op2 - op1;
        else if (strcmp(op, "*") == 0) result = op2 * op1;
        else if (strcmp(op, "/") == 0)
        {
            if (op1 == 0)
            {
                printf("错误：除数不能为0\n");
                return -1;
            }
            result = op2 / op1;
        }
        if (stack_push(s, result) != 0) return -1;
    }
    else if (isalpha(op[0]) && strlen(op) == 1)
    {
        int index = tolower(op[0]) - 'a';
        if (variable_set[index])
        {
            if (stack_push(s, variables[index]) != 0) return -1;
        }
        else
        {
            printf("错误：变量 %c 未赋值\n", op[0]);
            return -1;
        }
    }
    else if (strcmp(op, "pow") == 0 || strcmp(op, "sin") == 0 || strcmp(op, "exp") == 0 || strcmp(op, "last") == 0)
    {
        if (strcmp(op, "pow") == 0)
        {
            if (stack_pop(s, &op1) != 0 || stack_pop(s, &op2) != 0) return -1;
            result = pow(op2, op1);
            if (stack_push(s, result) != 0) return -1;
        }
        else if (strcmp(op, "sin") == 0)
        {
            if (stack_pop(s, &op1) != 0) return -1;
            result = sin(op1);
            if (stack_push(s, result) != 0) return -1;
        }
        else if (strcmp(op, "exp") == 0)
        {
            if (stack_pop(s, &op1) != 0) return -1;
            result = exp(op1);
            if (stack_push(s, result) != 0) return -1;
        }
        else if (strcmp(op, "last") == 0)
        {
            if (stack_push(s, last_printed_value) != 0) return -1;
        }
    }
    else
    {
        printf("错误：未知操作符 %s\n", op);
        return -1;
    }

    return 0;
}

int evaluate_rpn(const char* expression, double* result)
{
    Stack stack;
    stack_init(&stack);

    char buf[MAXBUFFER];
    strncpy(buf, expression, MAXBUFFER - 1);
    buf[MAXBUFFER - 1] = '\0';

    char* token = strtok(buf, " ");
    double num;
    int token_count = 0;
    char* tokens[MAXBUFFER];

    // 先统计token数量
    while (token != NULL)
    {
        tokens[token_count++] = token;
        token = strtok(NULL, " ");
    }

    // 如果只有两个token且是一个数字一个字母，则进行赋值
    if (token_count == 2)
    {
        if (parse_number(tokens[0], &num) == 0 && isalpha(tokens[1][0]) && strlen(tokens[1]) == 1)
        {
            int index = tolower(tokens[1][0]) - 'a';
            variables[index] = num;
            variable_set[index] = 1;
            *result = num;
            last_printed_value = num;
        }
        if (isalpha(tokens[0][0]) && strlen(tokens[0]) == 1 && parse_number(tokens[1], &num) == 0)
        {
            int index = tolower(tokens[0][0]) - 'a';
            variables[index] = num;
            variable_set[index] = 1;
            *result = num;
            last_printed_value = num;
        }
        return 0;
    }

    // 进行逆波兰计算
    for (int i = 0; i < token_count; i++)
    {
        token = tokens[i];
        if (parse_number(token, &num) == 0)
        {
            if (stack_push(&stack, num) != 0) return -1;
        }
        else if (strlen(token) == 1 && isalpha(token[0]))
        {
            int index = tolower(token[0]) - 'a';
            if (variable_set[index])
            {
                if (stack_push(&stack, variables[index]) != 0) return -1;
            }
            else
            {
                printf("错误：变量 %c 未赋值\n", token[0]);
                return -1;
            }
        }
        else
        {
            if (perform_operation(&stack, token) != 0) return -1;
        }
    }

    if (stack.top == 0)
    {
        if (stack_pop(&stack, result) == 0)
        {
            last_printed_value = *result;
            return 0;
        }
    }
    else if (stack.top > 0)
    {
        printf("错误：表达式不完整\n");
        return -1;
    }
    else
    {
        printf("错误：栈已空(表达式求值结束时)\n");
        return -1;
    }

    return 0;
}

int main()
{
    last_printed_value = 0.0;

    const char* tests[] = {
        "5 a",
        "z 2",
        "a z +",
        "Z A +",
        "last 2 *",
        "2 3 pow",
        "90 sin",
        "10 c",
        "c"
    };

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        printf("表达式 %d: %s\n", i + 1, tests[i]);
        double result;
        if (evaluate_rpn(tests[i], &result) == 0)
        {
            printf("结果: %f\n\n", result);
        }
        else
        {
            printf("计算失败\n\n");
        }
    }

    return 0;
}
