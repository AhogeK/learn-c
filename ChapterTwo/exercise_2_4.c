//
// Created by Ahoge Knight on 2022/11/19.
//

#include <stdio.h>

/* 练习2-4 重新编写函数 squeeze(s1, s2) 将字符串 s1 中任何与 s2 中的字符匹配的字符都删除 */
void squeeze_exercise_2_4(char s1[], const char s2[]) {
    // 初始化
    int i = 0;
    int j = 0;
    int k = 0;
    int instr2;

    // 遍历字符串 s1
    while (s1[i] != '\0') {
        // 默认该字符不在 s2 中
        instr2 = 0;
        // 遍历 s2, 当只有不是包含字符时，j 才赋值下标 i 的字符
        while (s2[k] != '\0' && !instr2)
            if (s2[k++] == s1[i]) {
                instr2 = 1;
                k = 0;
            }
        if (!instr2)
            s1[j++] = s1[i];
        k = 0;
        i++;
    }
    s1[j] = '\0';
}

int main() {
    char s1[] = "Hello World";
    char s2[] = " ";
    squeeze_exercise_2_4(s1, s2);
    printf("%s", s1);
}