#include <stdio.h>
#include "ChapterTwo/exercise_2.h"

int main() {
    char *test[] = {
            "F00",
            "bar",
            "0100",
            "0x1",
            "0XA",
            "0X0C0BE",
            "abcdef",
            "123456",
            "0x123456",
            "deadbeef",
            "zog_c"
    };
    char *a = test[0];
    printf("Hello, World!\n");
    printf("%d, %d\n", &a[-1], test[0]);
    _2_1();
//    exercise_1_23(fopen("/home/ahogek/CLionProjects/learn-c/main.c","r"));
//    exercise_1_22(fopen("/home/ahogek/Downloads/test.txt", "r"));
    return 0;
}