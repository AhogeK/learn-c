//
// Created by AhogeK on 10/20/24.
//

#include <ctype.h>
#include <stdio.h>

// 函数声明
double atof(const char s[]);

int main()
{
    const char str[] = "123.45e-6";
    double result = atof(str);
    printf("The converted floating-point number is: %g\n", result);
    return 0;
}

// 函数定义
double atof(const char s[])
{
    double val, power;
    int i, sign, exp_sign, exp;

    // 跳过空白字符
    for (i = 0; isspace(s[i]); i++);

    // 处理符号
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    // 处理整数部分
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    // 处理小数部分
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    // 处理科学计数法的指数部分
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
        if (exp_sign == -1)
            while (exp-- > 0)
                power *= 10.0;
        else
            while (exp-- > 0)
                power /= 10.0;
    }

    return sign * val / power;
}
