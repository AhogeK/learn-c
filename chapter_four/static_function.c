//
// Created by Ahoge Knight on 2023/2/7.
//

#include <stdio.h>

static void count()
{
    static int callCount = 0;
    ++callCount;
    printf("The function \"count()\" was called %d times.\n", callCount);
}

void count2()
{
    static int callCount = 0;
    ++callCount;
    printf("The function \"count()\" was called %d times.\n", callCount);
}
