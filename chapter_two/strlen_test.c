//
// Created by Ahoge Knight on 2022/10/12.
//
#include <printf.h>

unsigned long strlen(const char s[])
{
    int i;

    i = 0;

    while (s[i] != '\0')
        ++i;
    return i;
}

int main()
{
    char s[] = "Hello World!";
    printf("'Hello World!' length: %lu", strlen(s));
}
