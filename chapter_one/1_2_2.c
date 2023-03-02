//
// Created by Ahoge Knight on 2022/4/16.
//

#include <stdio.h>

/*
 * 当 fahrenheit = 0, 20, ..., 300时, 分别
 * 打印华氏温度与摄氏温度对照表
 * 浮点数版本
 */
int main()
{

    float fahrenheit;
    float celsius;
    float lower;
    float upper;
    float step;

    lower = 0;   /* 温度表的下限 */
    upper = 300; /* 温度表的上限 */
    step = 20;   /* 步长 */

    fahrenheit = lower;
    while (fahrenheit <= upper)
    {
        celsius = (5.0f / 9.0f) * (fahrenheit - 32.0f);
        printf("%3.0f %6.1f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}