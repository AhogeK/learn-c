//
// Created by AhogeK on 10/25/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXSTACK 100
double stack[MAXSTACK];
int sp = 0;

void push(double f)
{
    if (sp < MAXSTACK)
        stack[sp++] = f;
    else
    {
        fprintf(stderr, "错误：栈满\n");
        exit(1);
    }
}

double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    fprintf(stderr, "错误：栈空\n");
    exit(1);
}

int is_number(const char* s)
{
    if (*s == '+' || *s == '-')
        s++;

    int saw_digit = 0, saw_dot = 0;
    while (*s)
    {
        if (isdigit(*s))
            saw_digit = 1;
        else if (*s == '.' && !saw_dot)
            saw_dot = 1;
        else
            return 0;
        s++;
    }
    return saw_digit;
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        fprintf(stderr, "用法: expr 数字和运算符\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        if (is_number(argv[i]))
        {
            push(atof(argv[i]));
        }
        else if (strlen(argv[i]) == 1)
        {
            double op2, op1;
            switch (argv[i][0])
            {
            case '+':
                op2 = pop();
                op1 = pop();
                push(op1 + op2);
                break;
            case '*':
                op2 = pop();
                op1 = pop();
                push(op1 * op2);
                break;
            case '-':
                op2 = pop();
                op1 = pop();
                push(op1 - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 == 0.0)
                {
                    fprintf(stderr, "错误：除数为零\n");
                    return 1;
                }
                op1 = pop();
                push(op1 / op2);
                break;
            default:
                fprintf(stderr, "错误：未知运算符 %s\n", argv[i]);
                return 1;
            }
        }
        else
        {
            fprintf(stderr, "错误：非法输入 %s\n", argv[i]);
            return 1;
        }
    }

    if (sp != 1)
    {
        fprintf(stderr, "错误：表达式不完整\n");
        return 1;
    }

    printf("%.8g\n", pop());
    return 0;
}
