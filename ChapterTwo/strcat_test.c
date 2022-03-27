//
// Created by ahogek on 1/11/22.
//

#include <stdio.h>

/* strcat函数: 将字符串t连接到字符串s的尾部; s必须有足够大的空间 */
void custom_strcat(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0') /* 判断是否为字符串 s 的尾部 */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* 拷贝 t */
        ;
}

int main() {
    char s[100];
    char t[] = "custom_strcat";
    custom_strcat(s, t);
    printf("%s", s);
}