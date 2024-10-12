//
// Created by AhogeK on 10/10/24.
//

#include <stdio.h>

// 定义一个函数用于将华氏温度转换为摄氏温度
int fahrenheit_to_celsius(int fahrenheit)
{
    return 5 * (fahrenheit - 32) / 9;
}

/* 重新编写1.2节中的温度转换程序，使用函数实现温度转换计算 */
int main()
{
    int fahrenheit;
    int celsius;
    int lower;
    int upper;
    int step;

    lower = 0;
    upper = 300;
    step = 20;

    fahrenheit = lower;
    while (fahrenheit <= upper)
    {
        celsius = fahrenheit_to_celsius(fahrenheit);
        printf("%d\t%d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }

    return 0;
}
