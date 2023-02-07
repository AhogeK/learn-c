//
// Created by Ahoge Knight on 2023/2/4.
//

#include <printf.h>

extern int x = 32;
int b;

int main() {
    auto int a = 28;
    printf("The value of auto variable : %d \n", a);
    printf("The value of extern variables x and b : %d,%d \n", x, b);
    x = 15;
    b = 16;
    printf("The value of modified extern variable x : %d %d\n", x, b);
    return 0;
}