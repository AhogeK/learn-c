//
// Created by Ahoge Knight on 2023/2/7.
//

#include <stdio.h>

#define forever for(;;)
#define max(A, B) ((A) > (B) ? (A) : (B))

int main()
{
    // 苹果m1 用不用都一样
    register int i = 10;
    int j = 20;
    printf("%d\n", i);
    printf("%d\n", j);
    printf("max i j: %d \n", max(i, j));
    getchar();
    forever;
}