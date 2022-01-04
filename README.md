# learn-c
> C 语言学习。学习材料为 《C 程序设计语言 第二版新版》内容主要为材料中的案例与练习

## C 程序设计语言
### 第一章
#### 1.2 华氏温度与摄氏温度对照表

```c
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
```

```c
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
```

#### 练习 1-4

> 编写一个程序打印摄氏度温度转转为相应华氏温度的转换表

```c
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
```

#### 1.3 for 循环打印华氏温度 - 摄氏温度对照表

```c
void forLoopPrint()
{
    int fahrenheit;

    for (fahrenheit = 0; fahrenheit <= 300; fahrenheit = fahrenheit + 20)
        printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
}
```

```c
/**
 * for 循环打印 摄氏度-华氏对照表
 */
void forLoopCelsiusToFahrenheit()
{
    for (int celsius = -20; celsius <= 40; celsius += 5)
        printf("%3d %6.1f\n", celsius, celsius * (9.0 / 5.0) + 32);
}
```

#### 1.4 符号常量

```c
#include <stdio.h>

#define LOWER  0    /* 温度表的下限 */
#define UPPER 300   /* 温度表的上限 */
#define STEP 20     /* 步长 */
/**
 * 符号常量
 */
void symbolConstants()
{
    int fahrenheit;

    for (fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit += STEP)
        printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
}
```