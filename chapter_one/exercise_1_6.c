//
// 验证表达式 getchar() != EOF 的值是 0 还是 1。
// Created by Jonah Shi on 10/9/24.
//

#include <stdio.h>

int main()
{
    int c;
    int result;

    printf("请输入字符，然后 Ctrl+D （Unit/Linux）或 Ctrl+Z（Windows）结束输入：\n");

    while (1)
    {
        c = getchar();
        result = (c != EOF);
        printf("getchar() != EOF 的值为：%d\n", result);

        if (result == 0)
        {
            break;
        }
    }

    return 0;
}
