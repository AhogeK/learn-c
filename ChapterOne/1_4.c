//
// Created by ahogek on 9/13/21.
//

#include <stdio.h>

#define LOWER  0    /* 温度表的下限 */
#define UPPER 300   /* 温度表的上限 */
#define STEP 20     /* 步长 */

/**
 * 符号常量
 */
void symbolConstants() {
    int fahrenheit;

    for (fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit += STEP)
        printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
}

int main() {
    symbolConstants();
}