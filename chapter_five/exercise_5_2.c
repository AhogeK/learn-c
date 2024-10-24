//
// Created by AhogeK on 10/24/24.
//

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

static char buf[BUFSIZE]; /* 用于ungetch函数的缓冲区 */
static int bufp = 0; /* buf中下一个空闲位置 */

/* getch: 获取一个字符（可能是缓冲的字符）*/
int getch(void)
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

/* ungetch: 把字符送回输入中 */
void ungetch(const int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: 缓冲区已满\n");
    else
        buf[bufp++] = c;
}

/* getfloat: 将输入中的下一个浮点数赋值给*pn */
int getfloat(double* pn)
{
    int c;

    /* 跳过空白字符 */
    while (isspace(c = getch()))
    {
    }

    if (c == EOF)
        return EOF;

    if (!isdigit(c) && c != '+' && c != '-' && c != '.')
        return 0; /* 不是数字 */

    const int sign = c == '-' ? -1 : 1;

    if (c == '+' || c == '-')
    {
        const int d = getch();
        if (!isdigit(d) && d != '.')
        {
            /* 符号后面既不是数字也不是小数点 */
            ungetch(d); /* 送回非数字字符 */
            ungetch(c); /* 送回符号 */
            return 0;
        }
        c = d;
    }

    /* 处理整数部分 */
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');

    /* 处理小数部分 */
    if (c == '.')
    {
        double power;
        c = getch();
        for (power = 1.0; isdigit(c); c = getch())
        {
            *pn = 10.0 * *pn + (c - '0');
            power *= 10.0;
        }
        *pn /= power;
    }

    /* 处理科学计数法 (例如: 1.23e-4 或 1.23E+4) */
    if (c == 'e' || c == 'E')
    {
        c = getch();
        const int exp_sign = c == '-' ? -1 : 1;

        if (c == '+' || c == '-')
            c = getch();

        /* 读取指数部分 */
        if (isdigit(c))
        {
            int exp = 0;
            for (exp = 0; isdigit(c); c = getch())
                exp = 10 * exp + (c - '0');

            /* 应用指数 */
            if (exp_sign > 0)
            {
                while (exp-- > 0)
                    *pn *= 10.0;
            }
            else
            {
                while (exp-- > 0)
                    *pn /= 10.0;
            }
        }
        else
        {
            ungetch(c); /* 不是有效的指数，回退字符 */
            if (exp_sign == -1)
                ungetch('-');
            else
                ungetch('+');
            ungetch('e'); /* 回退'e'或'E' */
            return 0;
        }
    }

    if (!isspace(c) && c != EOF)
    {
        ungetch(c);
        return 0;
    }

    *pn *= sign;
    return c == EOF ? EOF : 1;
}

int main()
{
    double num;
    int ret;

    printf("请输入浮点数（支持科学计数法，如1.23e-4），用空格分隔：\n");
    while ((ret = getfloat(&num)) != EOF)
    {
        if (ret > 0) /* 成功读取到一个浮点数 */
            printf("读取到浮点数: %g\n", num);
        else
        {
            printf("读取到非法输入，跳过\n");
            /* 跳过当前非法字符直到空白字符 */
            int c;
            while ((c = getch()) != EOF && !isspace(c));
        }
    }
    printf("\n读取结束\n");
    return 0;
}
