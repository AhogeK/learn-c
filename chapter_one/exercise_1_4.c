//
// 编写一个程序打印摄氏温度转换为相应华氏温度的转换表
// Created by Ahoge Knight on 2023/3/17.
//

#include <printf.h>

int main()
{
    int celsius;
    int fahrenheit;
    int lower;
    int upper;
    int step;

    lower = -30; /* 温度的下限 */
    upper = 30; /* 温度的上限 */
    step = 10; /* 每行的温差（步长） */

    printf("%-6s\t%-6s\n", "摄氏度", "华氏度"); /* 标题 */

    celsius = lower;
    while (celsius <= upper)
    {
        fahrenheit = 9 * celsius / 5 + 32;
        printf("%-6d\t%-6d\n", celsius, fahrenheit);
        celsius = celsius + step;
    }

    return 0;
}