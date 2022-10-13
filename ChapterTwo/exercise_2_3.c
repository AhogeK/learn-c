//
// Created by Ahoge Knight on 2022/10/13.
//

#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int htoi(const char s[]) {
    unsigned long size = strlen(s);
    if (size == 2) {
        printf("%s 不是十六进制字符串", s);
        exit(0);
    }
    int sum = 0;
    int index = 0;
    for (int i = (int) size - 1; i >= 0; i--) {
        int dec = 0;
        if ((i == 0 && s[i] !='0') || (i == 1 && s[i] != 'x' && s[i] != 'X')) {
            printf("%s 不是十六进制字符串", s);
            exit(0);
        }  else if (i > 1) {
            if (!(s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'f' || s[i] >= 'A' && s[i] <= 'F')) {
                printf("%s 不是十六进制字符串", s);
                exit(0);
            }
            // 开始计算十六进制
            if (s[i] >= '0' && s[i] <= '9') {
                dec = s[i] - '0';
            } else {
                char c = (char) toupper(s[i]);
                switch (c) {
                    case 'A':
                        dec = 10;
                        break;
                    case 'B':
                        dec = 11;
                        break;
                    case 'C':
                        dec = 12;
                        break;
                    case 'D':
                        dec = 13;
                        break;
                    case 'E':
                        dec = 14;
                        break;
                    case 'F':
                        dec = 15;
                        break;
                    default:
                        // do nothing
                        break;
                }
            }
            sum += dec * (int) pow(16, index);
            index++;
        }
    }
    return sum;
}

int main() {
    char s[] = "0xFFFF";
    printf("%s转换为十进制为：%d", s, htoi(s));
}