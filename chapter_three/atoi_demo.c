//
// Created by Ahoge Knight on 2023/1/30.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char buffer[256];
    printf("Enter a number: ");
    fgets(buffer, 256, stdin);
    i = atoi(buffer);
    printf("The value entered is %d. Its double is %d. \n", i, i * 2);
}
