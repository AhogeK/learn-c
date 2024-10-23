//
// Created by AhogeK on 10/23/24.
//

#include <stdio.h>
#include <stdbool.h>

int buf = 0;
bool is_buf_full = false;

int getch(void)
{
    int ch;
    if (is_buf_full)
    {
        is_buf_full = false;
        ch = buf;
        printf("getch: 返回压回的%s '%c'\n",
               (ch == EOF) ? "EOF" : "字符",
               (ch == EOF) ? ' ' : ch);
    }
    else
    {
        do
        {
            ch = getchar();
        }
        while (ch == '\n'); // 忽略换行符
        if (ch != EOF)
        {
            printf("getch: 从输入读取字符 '%c'\n", ch);
        }
        else
        {
            printf("getch: 读取到 EOF\n");
        }
    }
    return ch;
}

int ungetch(int c)
{
    if (is_buf_full)
    {
        printf("ungetch: 错误，已经有一个压回的%s '%c'\n",
               buf == EOF ? "EOF" : "字符",
               buf == EOF ? ' ' : buf);
        return 0;
    }
    buf = c;
    is_buf_full = true;
    printf("ungetch: 成功压回%s '%c'\n",
           (c == EOF) ? "EOF" : "字符",
           (c == EOF) ? ' ' : c);
    return 1;
}

void test_getch_ungetch()
{
    int c;
    printf("输入字符（按Ctrl+D或Ctrl+Z结束输入）：\n");

    while ((c = getch()) != EOF)
    {
        printf("尝试压回字符 '%c'\n", c);
        if (ungetch(c))
        {
            printf("第一次压回成功，现在尝试第二次压回\n");
            if (ungetch(c))
            {
                printf("错误：第二次压回不应该成功\n");
            }
            else
            {
                printf("正确：第二次压回失败\n");
            }
        }
        else
        {
            printf("错误：第一次压回应该成功\n");
        }

        getch(); // 读取压回的字符
    }

    printf("检测到 EOF，尝试压回 EOF\n");
    if (ungetch(EOF))
    {
        printf("成功压回 EOF，现在尝试读取\n");
        int eof_char = getch();
        if (eof_char == EOF)
        {
            printf("正确：读取到压回的 EOF\n");
        }
        else
        {
            printf("错误：应该读取到 EOF，但读取到 '%c'\n", eof_char);
        }
    }
    else
    {
        printf("错误：压回 EOF 应该成功\n");
    }

    printf("测试结束\n");
}

int main()
{
    test_getch_ungetch();
    return 0;
}
