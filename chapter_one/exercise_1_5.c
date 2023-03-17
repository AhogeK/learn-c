//
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

    lower = 0; /* 温度的下限 */
    upper = 300; /* 温度的上限 */
    step = 20; /* 每行的温差（步长） */

    printf("%-6s\t%-6s\n", "华氏度", "摄氏度"); /* 标题 */

    fahrenheit = upper;
    while (fahrenheit >= lower)
    {
        celsius = 5 * (fahrenheit - 32) / 9;
        printf("%-6d\t%-6d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit - step;
    }

    return 0;
}