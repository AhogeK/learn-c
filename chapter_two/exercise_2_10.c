//
// Created by AhogeK on 10/17/24.
//

#include <stdio.h>

int lower(int c);

/* 练习2-10: 重写编写将大写字符转换为小写字母的函数lower，并用条件表达式替换其中的if-else结构。 */
int main()
{
    char test_chars[] = {'A', 'Z', 'a', 'z', '0', '9', '@', '[', '`', '{', '\0'};

    printf("原始     ||      小写\n");
    printf("---------|----------\n");

    for (int i = 0; test_chars[i] != '\0'; i++)
    {
        printf("   %c     |    %c\n", test_chars[i], lower(test_chars[i]));
    }

    return 0;
}

/* lower: 将大写字母转换为小写字母 */
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
