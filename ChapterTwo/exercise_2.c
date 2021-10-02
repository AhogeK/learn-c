//
// Created by ahogek on 9/28/21.
//

#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "exercise_2.h"

void _2_1() {
    signed char sc_max = SCHAR_MAX;
    unsigned char uc_max = UCHAR_MAX;
    signed short ss_max = SHRT_MAX;
    unsigned short us_max = USHRT_MAX;
    long sl_max = LONG_MAX;
    unsigned long ul_max = ULONG_MAX;

    printf("signed max char = %hhd\nunsigned max char = %hhu\nsigned max short = %hd\nunsigned max short = %hu\n"
           "signed max long = %ld\nunsigned max long = %lu", sc_max, uc_max, ss_max, us_max, sl_max, ul_max);
}

void _2_2() {
    int lim = 10;
    int c;
    for (int i = 0;; i++) {
        if (i < lim - 1) {
            if ((c = getchar()) != 'n') {
                if (c != EOF) {
                    // do something
                }
            }
        }
        break;
    }
}

/* 将16进制的字符转换为十进制值 */
long hchartoi(char hexdig, int pos) {
    char hexdigits[] = "0123456789ABCDEF";
    // 16进制下标下的字符
    char *p = &hexdigits[0];
    // 遍历的下标
    long deci = 0;
    int i;

    while (*p != toupper(hexdig) && deci < 16) {
        ++p;
        ++deci;
    }
    // 如果字符就是传入的字符,求十进制值
    if (*p == toupper(hexdig)) {
        for (i = 0; i < pos; i++)
            deci *= 16;
        return deci;
    }
    return -1;
}

/* 将16进制数组成的字符串转换为整形值 */
long htoi(char hexstring[]) {
    /* 取最后一个字符 *p */
    char *p = &hexstring[strlen(hexstring) - 1];
    /* deci为最终值，dig为字符串元素字符转换后的十进制值 */
    long deci = 0, dig;
    /* 位数 */
    int pos = 0;

    /*
     * p指针为 hexstring指针指向下的元素，所以p指针转成的整数会大于等于hexstring指针转成的整数，其中p下标为0的指针与hexstring指针
     * 相同，说明数组的指针指向的是第一个元素的指针，且有序排列
     **/
    while (p >= hexstring) {
        if ((dig = hchartoi(*p, pos)) < 0) {
            printf("Error\n");
            return -1;
        }
        deci += dig;
        /* 当下标为-1的数组指针必定小于hestring的指针，便会退出循环 */
        --p;
        ++pos;
    }
    return deci;
}

/**
 * 练习2-3 编写函数htoi(s), 把由十六进制数字组成的字符串转换为与之等价的整型值
 */
void _2_3() {
    /* 最后被转转换的字符串指针 */
    char *endp = NULL;
    /* 用于测试的十六进制数组 */
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

    /* 与之等价的整型值 */
    long int result;

    /* 被字符串转换的整型值 */
    long int check;

    /* size_t是sizeof的一个无符号整型类型结果 */
    size_t numtests = sizeof test / sizeof test[0];

    size_t thistest;

    for (thistest = 0; thistest < numtests; thistest++) {
        /* htoi 与 strtol 作用相同用于判断确认 */
        result = htoi(test[thistest]);
        /*
         * strtol用于转换String为 long int
         * test[thistest] - 一个需要转成 long int 的字符串指针
         * &endp - 用于指示 strtol 函数何时停止转换 (指针指向被转换的字符串)
         * 16 - 要被转换数字的基数
         **/
        check = strtol(test[thistest], &endp, 16);
        if ((*endp != '\0' && result == -1) || result == check) {
            printf("Testing %s. Correct. %ld\n", test[thistest], result);
        } else {
            printf("Testing %s. Incorrect. %ld\n", test[thistest], result);
        }
    }
}

void _2_4(char s1[], const char s2[]) {
    int i, j, k;
    int instr;

    for (i = j = 0; s1[i] != '\0'; i++) {
        instr = 0;
        for (k = 0; s2[k] != '\0' && !instr; k++) {
            if (s2[k] == s1[i]) {
                instr = 1;
            }
        }

        if (!instr) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}