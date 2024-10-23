//
// Created by AhogeK on 10/23/24.
//

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

/* getop：获取下一个运算符或数值操作数 */
int getop(char s[])
{
    int i, c;
    static int lastc = 0; // 静态变量，用于存储上一个字符

    // 如果lastc中没有存储的字符，则读取新的输入
    if (lastc == 0)
    {
        c = getchar();
    }
    else
    {
        c = lastc;
        lastc = 0; // 使用后清除存储的字符
    }

    // 跳过空白字符
    while ((s[0] = c) == ' ' || c == '\t')
        c = getchar();
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c; // 不是数字

    i = 0;
    // 处理负号：检查是否是负数
    if (c == '-')
    {
        c = getchar();
        if (!isdigit(c))
        {
            // 如果-后面不是数字
            lastc = c; // 存储读取的字符
            return '-'; // 返回减号
        }
        s[++i] = c; // 是负数，保存负号和数字
    }

    // 收集整数部分
    if (isdigit(c))
        while (isdigit(s[++i] = c = getchar()));

    // 收集小数部分
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()));

    s[i] = '\0';

    if (c != EOF)
        lastc = c; // 存储最后读取的字符

    return NUMBER;
}

/* 简单的测试程序 */
int main()
{
    char s[100];
    int type;

    printf("输入数字和运算符（按Ctrl+D结束）：\n");
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            printf("数字：%s\n", s);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            printf("运算符：%c\n", type);
            break;
        case ' ':
        case '\t':
        case '\n':
            break;
        default:
            printf("未知字符：%c\n", type);
            break;
        }
    }
    return 0;
}
