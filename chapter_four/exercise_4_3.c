//
// Created by AhogeK on 10/20/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTACK 100
#define MAXBUFFER 100

int stack[MAXSTACK];
int sp = 0; // 栈指针

void push(int val)
{
    if (sp < MAXSTACK)
        stack[sp++] = val;
    else
        printf("错误：栈已满\n");
}

int pop()
{
    if (sp > 0)
        return stack[--sp];
    printf("错误：栈已空\n");
    return 0;
}

void evaluate_rpn(const char* expression)
{
    int i = 0, op2;
    char buf[MAXBUFFER];

    while (expression[i] != '\0')
    {
        if (isdigit(expression[i]) || (expression[i] == '-' && isdigit(expression[i + 1])))
        {
            int j = 0;
            if (expression[i] == '-')
            {
                buf[j++] = expression[i++];
            }
            while (isdigit(expression[i]))
            {
                buf[j++] = expression[i++];
            }
            buf[j] = '\0';
            push(atoi(buf));
        }
        else if (isspace(expression[i]))
        {
            i++;
        }
        else
        {
            int op1 = pop();
            op2 = pop();
            switch (expression[i])
            {
            case '+':
                push(op2 + op1);
                break;
            case '-':
                push(op2 - op1);
                break;
            case '*':
                push(op2 * op1);
                break;
            case '/':
                if (op1 != 0)
                    push(op2 / op1);
                else
                    printf("错误: 分母不能为0\n");
                break;
            case '%':
                if (op1 != 0)
                    push(op2 % op1);
                else
                    printf("错误: 错误分母不能为0\n");
                break;
            default:
                printf("错误: 未知操作符 %c\n", expression[i]);
                break;
            }
            i++;
        }
    }
}

int main()
{
    const char* tests[] = {
        "15 7 1 1 + - / 3 * 2 1 1 + + -", // Example: ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5
        "5 1 2 + 4 * + 3 -", // Example: 5 + ((1 + 2) * 4) - 3 = 14
        "100 200 + 2 / 5 * 7 +", // Example: ((100 + 200) / 2 * 5) + 7 = 757
        "10 6 9 3 + -11 * / * 17 + 5 +", // Complex: 10 * (6 / ((9 + 3) * -11)) + 17 + 5 = 22
        "20 5 %", // Example: 20 % 5 = 0
        "-20 3 %", // Example with negative: -20 % 3 = -2
    };

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        printf("表达式 %d: %s\n", i + 1, tests[i]);
        evaluate_rpn(tests[i]);
        printf("结果: %d\n\n", pop());
    }

    return 0;
}
