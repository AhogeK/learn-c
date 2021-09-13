//Fahrenheit
// Created by ahogek on 9/11/21.
//

#include <stdio.h>

/*
 * 当 fahr = 0, 20, ..., 300时，分别打印华氏温度与摄氏温度对照表
 */
void fahrAndCelsius()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%s\n", "不带浮点数的表");
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

/*
 * 浮点版本
 */
void floatFahrAndCelsius()
{
    float fahrenheit, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahrenheit = lower;
    printf("%s\n", "带浮点数的表");
    while (fahrenheit <= upper)
    {
        celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
        printf("%3.0f %6.1f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}

/**
 * 摄氏度转华氏
 */
void celsiusToFahrenheit()
{
    float fahrenheit, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 40;
    step = 5;

    celsius = lower;
    printf("%s\n", "打印摄氏度转华氏表");
    while (celsius <= upper)
    {
        fahrenheit = celsius * 9 / 5 + 32;
        printf("%3.0f %3.1f\n", celsius, fahrenheit);
        celsius += step;
    }
}

/**
 * for 循环打印华氏温度 - 摄氏温度对照表
 */
void forLoopPrint()
{
    int fahrenheit;

    for (fahrenheit = 0; fahrenheit <= 300; fahrenheit = fahrenheit + 20)
        printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
}

void forLoopCelsiusToFahrenheit()
{
    for (int celsius = -20; celsius <= 40; celsius += 5)
        printf("%3d %6.1f\n", celsius, celsius * (9.0 / 5.0) + 32);
}