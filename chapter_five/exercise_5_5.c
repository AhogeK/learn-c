//
// Created by AhogeK on 10/24/24.
//

#include <stdio.h>

/* strncpy: 将t中最多前n个字符复制到s中 */
char *mystrncpy(char *s, const char *t, size_t n) {
    char *original_s = s;  // 保存s的起始位置

    // 复制最多n个字符
    while (n > 0 && *t != '\0') {
        *s++ = *t++;
        n--;
    }

    // 如果n还大于0，用'\0'填充剩余空间
    while (n > 0) {
        *s++ = '\0';
        n--;
    }

    return original_s;
}

/* strncat: 将t中最多前n个字符连接到s末尾 */
char *mystrncat(char *s, const char *t, size_t n) {
    char *original_s = s;  // 保存s的起始位置

    // 找到s的末尾
    while (*s != '\0')
        s++;

    // 复制最多n个字符
    while (n > 0 && *t != '\0') {
        *s++ = *t++;
        n--;
    }

    *s = '\0';  // 确保结果字符串以'\0'结尾
    return original_s;
}

/* strncmp: 比较s和t的最多前n个字符 */
int mystrncmp(const char *s, const char *t, size_t n) {
    // 当n大于0且两个字符串都未结束时继续比较
    while (n > 0 && *s == *t && *s != '\0') {
        n--;
        s++;
        t++;
    }

    // 如果已经比较完n个字符或两个字符串相等
    if (n == 0 || *s == *t)
        return 0;

    // 返回当前字符的差值
    return *(unsigned char *)s - *(unsigned char *)t;
}

int main() {
    char s1[50] = "Hello";
    char s2[50] = "Hello";
    char s3[50] = "Hello";
    const char *t = "World";

    // 测试 strncpy
    printf("测试 mystrncpy:\n");
    printf("复制前: s1 = \"%s\"\n", s1);
    mystrncpy(s1, t, 3);
    printf("复制后: s1 = \"%s\"\n\n", s1);

    // 测试 strncat
    printf("测试 mystrncat:\n");
    printf("连接前: s2 = \"%s\"\n", s2);
    mystrncat(s2, t, 3);
    printf("连接后: s2 = \"%s\"\n\n", s2);

    // 测试 strncmp
    printf("测试 mystrncmp:\n");
    printf("比较 \"%s\" 和 \"%s\" 的前3个字符: %d\n",
           s3, t, mystrncmp(s3, t, 3));
    printf("比较 \"%s\" 和 \"%s\" 的前3个字符: %d\n",
           "Hello", "Help", mystrncmp("Hello", "Help", 3));

    return 0;
}