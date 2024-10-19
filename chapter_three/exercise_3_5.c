//
// Created by AhogeK on 10/20/24.
//

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    char buffer[100];
    int number = 255;
    int base = 16;

    itob(number, buffer, base);
    printf("Number %d in base %d is: %s\n", number, base, buffer);

    return 0;
}

void itob(int n, char s[], int b)
{
    int i = 0, sign;
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (b < 2 || b > 36) {
        s[i] = '\0'; // 不支持的进制
        return;
    }

    if ((sign = n) < 0) {
        n = -n; // 处理负数
    }

    do {
        s[i++] = digits[n % b]; // 提取当前位并转换为字符
    } while ((n /= b) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}