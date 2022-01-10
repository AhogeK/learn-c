//
// Created by ahogek on 1/10/22.
//

#include <stdio.h>

/* strlen函数：返回s的长度 */
int strlen_test(char s[]) {
    int i;

    i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

int main() {
    printf("%d", strlen_test("hello"));
}