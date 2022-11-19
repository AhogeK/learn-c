//
// Created by Ahoge Knight on 2022/11/19.
//

#include <stdio.h>

/* 练习 2-5: 编写函数 any(s1, s2), 将字符串 s2 中的任一字符在字符串 s1 中第一次出现的位置作为结果返回。不包含则返回 -1。 */
int any(const char s1[], const char s2[]) {
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    char s1[] = "Hello World";
    char s2[] = " ";
    printf("%d", any(s1, s2));
}