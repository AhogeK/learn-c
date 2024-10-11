//
// 编写程序detab，将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止位的地方。假设制表符终止位的位置是固定的，
// 比如每隔n列就会出现一个制表符终止位。n应该作为变量还是符号常量呢？
// 符号常量更好：
// 1. 可读性更好：使用有意义的名称如 TAB_WIDTH 比单纯的 n 更清晰。
// 2. 易于修改：如果需要改变制表符宽度，只需在一处修改。
// 3. 防止意外修改：符号常量不能被程序中的其他部分意外修改。
//
// Created by AhogeK on 10/11/24.
//

#include <stdio.h>

#define TAB_WIDTH 4

void detab()
{
    int c, column;
    column = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            int spaces = TAB_WIDTH - (column % TAB_WIDTH);
            int i;
            for (i = 0; i < spaces; ++i)
            {
                putchar(' ');
                ++column;
            }
        } else
        {
            putchar(c);
            column++;
            if (c == '\n')
                column = 0;
        }
    }

}

int main()
{
    printf("请输入文本（按Ctrl（Command）+D结束输入）：\n");
    detab();
    return 0;
}