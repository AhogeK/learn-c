//
// Created by ahogek on 1/11/22.
//

#include <stdio.h>

/* squeeze函数: 从字符串s中删除字符c */
void squeeze(char s[], int c) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

int main() {
    char s[] = "squeeze";
    squeeze(s, 'q');
    printf("via squeeze: %s\n", s);
    return 0;
}