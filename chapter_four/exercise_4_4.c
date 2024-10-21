//
// Created by AhogeK on 10/21/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXSTACK 100
#define MAXBUFFER 100

typedef struct
{
    long long values[MAXSTACK];
    int top;
} Stack;

void stack_init(Stack* s)
{
    s->top = -1;
}

int stack_push(Stack* s, long long value)
{
    if (s->top >= MAXSTACK - 1)
    {
        printf("错误：栈已满\n");
        return -1;
    }
    s->values[++s->top] = value;
    return 0;
}

int stack_pop(Stack* s, long long* value)
{
    if (s->top < 0)
    {
        printf("错误：栈已空\n");
        return -1;
    }
    *value = s->values[s->top--];
    return 0;
}

int stack_peek(const Stack* s, long long* value)
{
    if (s->top < 0)
    {
        printf("错误：栈已空\n");
        return -1;
    }
    *value = s->values[s->top];
    return 0;
}

int stack_duplicate(Stack* s)
{
    if (s->top < 0)
    {
        printf("错误：栈已空\n");
        return -1;
    }
    return stack_push(s, s->values[s->top]);
}

int stack_swap(Stack* s)
{
    if (s->top < 1)
    {
        printf("错误：栈中的元素不足以交换\n");
        return -1;
    }
    long long temp = s->values[s->top];
    s->values[s->top] = s->values[s->top - 1];
    s->values[s->top - 1] = temp;
    return 0;
}

void stack_clear(Stack* s)
{
    s->top = -1;
}

int parse_number(const char* str, long long* result)
{
    char* endptr;
    errno = 0;
    *result = strtoll(str, &endptr, 10);
    if (errno != 0 || *endptr != '\0')
    {
        return -1;
    }
    return 0;
}

int perform_operation(Stack* s, char op)
{
    long long op1, op2, result;
    switch (op)
    {
    case '+':
        if (stack_pop(s, &op1) != 0 || stack_pop(s, &op2) != 0) return -1;
        result = op2 + op1;
        return stack_push(s, result);
    case '-':
        if (stack_pop(s, &op1) != 0 || stack_pop(s, &op2) != 0) return -1;
        result = op2 - op1;
        return stack_push(s, result);
    case '*':
        if (stack_pop(s, &op1) != 0 || stack_pop(s, &op2) != 0) return -1;
        result = op2 * op1;
        return stack_push(s, result);
    case '/':
        if (stack_pop(s, &op1) != 0 || stack_pop(s, &op2) != 0) return -1;
        if (op1 == 0)
        {
            printf("错误：除数不能为0\n");
            return -1;
        }
        result = op2 / op1;
        return stack_push(s, result);
    case '%':
        if (stack_pop(s, &op1) != 0 || stack_pop(s, &op2) != 0) return -1;
        if (op1 == 0)
        {
            printf("错误：模数不能为0\n");
            return -1;
        }
        result = op2 % op1;
        return stack_push(s, result);
    default:
        printf("错误：未知操作符 %c\n", op);
        return -1;
    }
}

int evaluate_rpn(const char* expression, long long* result)
{
    Stack stack;
    stack_init(&stack);

    char buf[MAXBUFFER];
    strncpy(buf, expression, MAXBUFFER - 1);
    buf[MAXBUFFER - 1] = '\0'; // 确保字符串以 null 结尾
    char* token = strtok(buf, " ");

    while (token != NULL)
    {
        long long num;
        if (parse_number(token, &num) == 0)
        {
            if (stack_push(&stack, num) != 0)
            {
                return -1;
            }
        }
        else if (strlen(token) == 1)
        {
            char op = token[0];
            if (strchr("+-*/%", op))
            {
                if (perform_operation(&stack, op) != 0)
                {
                    return -1;
                }
            }
            else if (op == 'p')
            {
                // Print top
                if (stack_peek(&stack, &num) == 0)
                {
                    printf("栈顶元素: %lld\n", num);
                }
            }
            else if (op == 'd')
            {
                // Duplicate top
                if (stack_duplicate(&stack) != 0)
                {
                    return -1;
                }
            }
            else if (op == 's')
            {
                // Swap top two
                if (stack_swap(&stack) != 0)
                {
                    return -1;
                }
            }
            else if (op == 'c')
            {
                // Clear stack
                stack_clear(&stack);
                printf("栈已清空\n");
            }
            else
            {
                printf("错误：无效的命令 '%s'\n", token);
                return -1;
            }
        }
        else
        {
            printf("错误：无效的标记 '%s'\n", token);
            return -1;
        }
        token = strtok(NULL, " ");
    }

    if (stack.top != 0)
    {
        printf("错误：表达式不完整\n");
        return -1;
    }

    return stack_pop(&stack, result);
}

int main()
{
    const char* tests[] = {
        "15 7 1 1 + - / 3 * 2 1 1 + + -",
        "5 1 2 + 4 * + 3 -",
        "100 200 + 2 / 5 * 7 +",
        "10 6 9 3 + -11 * / * 17 + 5 +",
        "20 5 %",
        "-20 3 %",
        "5 4 p", // Print top: 4
        "10 2 d + p", // Duplicate top, add: Print top: 22
        "6 2 s +", // Swap, add: 8
        "3 4 5 c", // Clear stack
    };

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        printf("表达式 %d: %s\n", i + 1, tests[i]);
        long long result;
        if (evaluate_rpn(tests[i], &result) == 0)
        {
            printf("结果: %lld\n\n", result);
        }
        else
        {
            printf("计算失败\n\n");
        }
    }

    return 0;
}
