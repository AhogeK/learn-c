//
// Created by Ahoge Knight on 2022/10/12.
//

#include <printf.h>

/* lower函数: 把字符 c 转换为消协形式; 只对 ASCII 字符集有效 */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    return c;
}

int main()
{
    printf("%c", lower('C'));
}
