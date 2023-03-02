//
// Created by Ahoge Knight on 2023/2/7.
//

#include <stdio.h>

#define STR_PRINT(x) #x
#define STR_CONCAT(x, y) x ## _ ## y

#if !defined(SIZE)
#define SIZE 100
#endif

int main()
{
    printf(STR_PRINT(This is a string without double quotes));
    int x_y = 2050;
    printf("\n%d\n", STR_CONCAT(x, y));

#if SIZE > 99
    printf("For 100 plus elements.\n");
#else
    printf("For less then 100 elements.\n");
#endif
}