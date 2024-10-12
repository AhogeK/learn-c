//
// Created by Ahoge Knight on 2022/4/16.
//

#include <stdio.h>

/*
 * 当 fahrenheit = 0, 20, ..., 300时, 分别
 * 打印华氏温度与摄氏温度对照表
 */
int main()
{
    int fahrenheit;
    int celsius;
    int lower;
    int upper;
    int step;

    lower = 0; /* 温度表的下限 */
    upper = 300; /* 温度表的上限 */
    step = 20; /* 步长 */

    fahrenheit = lower;
    while (fahrenheit <= upper)
    {
        celsius = 5 * (fahrenheit - 32) / 9;
        printf("%d\t%d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}
