//
// Created by Ahoge Knight on 2022/4/18.
//

#include <stdio.h>

#define LOWER 0     /* 温度表的下限 */
#define UPPER 300   /* 温度表的上限 */
#define STEP  20     /* 步长 */

/*
 * 打印华氏温度-摄氏温度对照表
 */
int main()
{
    for (int fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit = fahrenheit + STEP)
        printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
}