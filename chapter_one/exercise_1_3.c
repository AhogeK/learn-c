//
// 修改温度转换程序，使之能在转换表的顶部打印一个标题。
// Created by Ahoge Knight on 2023/3/17.
//

#include <printf.h>

int main()
{
    int fahrenheit;
    int celsius;
    int lower;
    int upper;
    int step;

    lower = -100; /* 温度的下限 */
    upper = 100; /* 温度的上限 */
    step = 20; /* 每行的温差（步长） */

    printf("%-6s\t%-6s\n", "华氏度", "摄氏度"); /* 标题 */

    fahrenheit = lower;
    while (fahrenheit <= upper)
    {
        celsius = 5 * (fahrenheit - 32) / 9;
        printf("%-6d\t%-6d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }

    return 0;
}
