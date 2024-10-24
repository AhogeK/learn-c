//
// Created by AhogeK on 10/24/24.
//

#include <stdio.h>

/* 将字符串t连接到字符串s的尾部 */
void mystrcat(char *s, char *t) {
    // 先将s指针移动到字符串s的末尾
    while (*s)
        s++;

    // 将t指向的字符串复制到s的尾部
    while ((*s++ = *t++))
        ;
}

int main() {
    char s[100] = "Hello, ";  // 确保s有足够空间容纳连接后的字符串
    char *t = "World!";

    printf("原始字符串s: %s\n", s);
    printf("要连接的字符串t: %s\n", t);

    mystrcat(s, t);

    printf("连接后的字符串: %s\n", s);

    return 0;
}