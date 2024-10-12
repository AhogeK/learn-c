//
// Created by Ahoge Knight on 2022/4/18.
//

#include <stdio.h>

/*
 * 打印华氏温度-摄氏温度对照表
 */
int main()
{
    for (int fahrenheit = 0; fahrenheit <= 300; fahrenheit = fahrenheit + 20)
        printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
}
