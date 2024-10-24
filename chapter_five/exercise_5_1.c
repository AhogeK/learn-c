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
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: 缓冲区已满\n");
    else
        buf[bufp++] = c;
}

/* getint: 将输入中的下一个整数赋值给*pn */
int getint(int* pn)
{
    int c;

    /* 跳过空白字符 */
    while (isspace(c = getch()))
    {
    }

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
        return 0; /* 不是数字，直接返回，不需要ungetch */

    const int sign = c == '-' ? -1 : 1;

    if (c == '+' || c == '-')
    {
        int d = getch();
        if (!isdigit(d))
        {
            /* 符号后面不是数字 */
            ungetch(d); /* 送回非数字字符 */
            ungetch(c); /* 送回符号 */
            return 0;
        }
        c = d;
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;

    if (c != EOF)
        ungetch(c);
    return c;
}

int main()
{
    int c, n, ret;

    printf("请输入一些整数（可以带符号），用空格分隔：\n");
    while ((ret = getint(&n)) != EOF)
    {
        if (ret > 0) /* 成功读取到一个数字 */
            printf("读取到数字: %d\n", n);
        else if (ret == 0)
        {
            printf("读取到非法输入，跳过\n");
            /* 跳过当前非法字符 */
            while ((c = getch()) != EOF && !isspace(c));
        }
    }

    return 0;
}
