//
// Created by AhogeK on 10/20/24.
//

#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int min_width);
void reverse(char s[]);

int main()
{
    char buffer[100];
    int number = -123;
    int min_width = 10;

    itoa(number, buffer, min_width);
    printf("Formatted string: '%s'\n", buffer);

    return 0;
}

void itoa(int n, char s[], int min_width)
{
    int i = 0, sign;

    if ((sign = n) < 0)
        n = -n; // 处理负数

    do
        s[i++] = n % 10 + '0';
    while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);

    int len = strlen(s);

    if (len < min_width)
    {
        memmove(s + (min_width - len), s, len + 1);
        for (int j = 0; j < min_width - len; j++)
            s[j] = ' ';
    }
}

void reverse(char s[])
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
