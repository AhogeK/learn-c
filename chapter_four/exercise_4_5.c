//
// Created by AhogeK on 10/21/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>  // 引入数学库

#define MAXSTACK 100
#define MAXBUFFER 100

typedef struct {
    double values[MAXSTACK];  // 使用 double 以支持小数运算
    int top;
} Stack;

void stack_init(Stack *s) {
    s->top = -1;
}

int stack_push(Stack *s, double value) {
    if (s->top >= MAXSTACK - 1) {
        printf("错误：栈已满\n");
        return -1;
    }
    s->values[++s->top] = value;
    return 0;
}

int stack_pop(Stack *s, double *value) {
    if (s->top < 0) {
        printf("错误：栈已空\n");
        return -1;
    }
    *value = s->values[s->top--];
    return 0;
}

int stack_peek(const Stack *s, double *value) {
    if (s->top < 0) {
        printf("错误：栈已空\n");
        return -1;
    }
    *value = s->values[s->top];
    return 0;
}

int stack_duplicate(Stack *s) {
    if (s->top < 0) {
        printf("错误：栈已空\n");
        return -1;
    }
    return stack_push(s, s->values[s->top]);
}

int stack_swap(Stack *s) {
    if (s->top < 1) {
        printf("错误：栈中的元素不足以交换\n");
        return -1;
    }
    double temp = s->values[s->top];
    s->values[s->top] = s->values[s->top - 1];
    s->values[s->top - 1] = temp;
    return 0;
}

void stack_clear(Stack *s) {
    s->top = -1;
}

int parse_number(const char *str, double *result) {
    char *endptr;
    errno = 0;
    *result = strtod(str, &endptr);  // 使用 strtod 以支持小数
    if (errno != 0 || *endptr != '\0') {
        return -1;
    }
    return 0;
}

int perform_operation(Stack *s, const char *op) {
    double op1, op2, result;
    if (strcmp(op, "+") == 0) {
        if (stack_pop(s, &op1) != 0 || stack_pop(s, &op2) != 0) return -1;
        result = op2 + op1;
        return stack_push(s, result);
    } else if (strcmp(op, "-") == 0) {
        if (stack_pop(s, &op1) != 0 || stack_pop(s, &op2) != 0) return -1;
        result = op2 - op1;
        return stack_push(s, result);
    } else if (strcmp(op, "*") == 0) {
        if (stack_pop(s, &op1) != 0 || stack_pop(s, &op2) != 0) return -1;
        result = op2 * op1;
        return stack_push(s, result);
    } else if (strcmp(op, "/") == 0) {
        if (stack_pop(s, &op1) != 0 || stack_pop(s, &op2) != 0) return -1;
        if (op1 == 0) {
            printf("错误：除数不能为0\n");
            return -1;
        }
        result = op2 / op1;
        return stack_push(s, result);
    } else if (strcmp(op, "sin") == 0) {
        if (stack_pop(s, &op1) != 0) return -1;
        result = sin(op1);  // sin函数
        return stack_push(s, result);
    } else if (strcmp(op, "exp") == 0) {
        if (stack_pop(s, &op1) != 0) return -1;
        result = exp(op1);  // exp函数
        return stack_push(s, result);
    } else if (strcmp(op, "pow") == 0) {
        if (stack_pop(s, &op1) != 0 || stack_pop(s, &op2) != 0) return -1;
        result = pow(op2, op1);  // pow函数
        return stack_push(s, result);
    } else {
        printf("错误：未知操作符 %s\n", op);
        return -1;
    }
}

int evaluate_rpn(const char *expression, double *result) {
    Stack stack;
    stack_init(&stack);

    char buf[MAXBUFFER];
    strncpy(buf, expression, MAXBUFFER - 1);
    buf[MAXBUFFER - 1] = '\0';
    char *token = strtok(buf, " ");

    while (token != NULL) {
        double num;
        if (parse_number(token, &num) == 0) {
            if (stack_push(&stack, num) != 0) {
                return -1;
            }
        } else {
            if (perform_operation(&stack, token) != 0) {
                return -1;
            }
        }
        token = strtok(NULL, " ");
    }

    if (stack.top != 0) {
        printf("错误：表达式不完整\n");
        return -1;
    }

    return stack_pop(&stack, result);
}

int main() {
    const char *tests[] = {
        "90 sin",          // 计算 sin(90)
        "2.718281828 exp", // 计算 exp(2.718281828)
        "2 3 pow",         // 计算 2^3
        "5 1 2 + 4 * + 3 -", // 原有测试用例
    };

    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        printf("表达式 %d: %s\n", i + 1, tests[i]);
        double result;
        if (evaluate_rpn(tests[i], &result) == 0) {
            printf("结果: %f\n\n", result);
        } else {
            printf("计算失败\n\n");
        }
    }

    return 0;
}