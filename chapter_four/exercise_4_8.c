//
// Created by AhogeK on 10/23/24.
//

#include <stdio.h>

int buf = EOF; // 用于存储单个压回字符，初始化为EOF表示没有压回的字符

// 获取一个字符（可能是压回的字符）
int getch(void)
{
    int ch;
    if (buf != EOF)
    {
        ch = buf;
        buf = EOF; // 重置buf
        printf("getch: 返回压回的字符 '%c'\n", ch);
    }
    else
    {
        ch = getchar();
        printf("getch: 从输入读取字符 '%c'\n", ch);
    }
    return ch;
}

// 压回一个字符
int ungetch(int c)
{
    if (buf != EOF)
    {
        printf("ungetch: 错误，已经有一个压回的字符 '%c'\n", buf);
        return 0; // 返回0表示压回失败
    }
    buf = c;
    printf("ungetch: 成功压回字符 '%c'\n", c);
    return 1; // 返回1表示压回成功
}

void test_getch_ungetch()
{
    int c;
    printf("输入字符（按Enter键后Ctrl+D结束）：\n");

    while ((c = getch()) != EOF)
    {
        if (c == '\n')
        {
            printf("检测到换行，继续下一个输入\n");
            continue;
        }

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

        // 读取压回的字符
        getch();
    }

    printf("输入结束\n");
}

int main()
{
    test_getch_ungetch();
    return 0;
}
