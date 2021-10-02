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
     */
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
         */
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

int _2_5(const char s1[], const char s2[]) {
    int i;
    int j;
    int pos;

    pos = -1;

    for (i = 0; pos == -1 && s1[i] != '\0'; i++) {
        for (j = 0; pos == -1 && s2[j] != '\0'; j++) {
            if (s2[j] == s1[i]) {
                pos = i;
            }
        }
    }

    return pos;
}

/*
 * 编写一个函数 setbits(x,p,n,y)，该函数返回对x执行下列操作后的结果值：将x中从第p位开始的n个（二进制）位设置为y中最右边n位的值，
 * x的其余各位保持不变
 */
unsigned _2_6(unsigned x, int p, int n, unsigned y) {
    /* 先把x需要改变的地方清0, 然后把y不需要改变的清0，两者求按位或既可替换需要替换的地方*/
    return (x & ((~0 << (p + 1)) | (~(~0 << (p + 1 - n))))) | ((y & ~(~0 << n)) << (p + 1 - n));
}

unsigned _2_7(unsigned x, int p, int n) {
    /*准备需要取反的位数设为1其余为0的二进制值,再跟需要取反的x进行按位异或操作*/
    return x ^ (~(~0U << n) << p);
}

unsigned _2_8(unsigned x, unsigned n) {
    while (n > 0) {
        /*如果为true说明最后一位是1*/
        if ((x & 1) == 1)
            /*如果是1，右移的1需要到首位，现将0取反右移将首位为0再取反只有首位1，这样右移的x与该二进制按位或就能将首位置为1*/
            x = (x >> 1) | ~(~0U >> 1);
        else
            /*是0直接右移即可*/
            x = (x >> 1);
        n--;
    }
    return x;
}

int _2_9(unsigned x) {
    int b;
    /*
     * 只要不等于0就说明x中还包含1,计数b自增然后去掉一个1为0,只需要将x 按位与 (x - 1) 便能去除x中的一位1,因为当一个二进制减1时从右数
     * 最先出现的1必将被减去，位与运算时就算是借位过去的1还是会是0,只会保留还未被减去使用靠左的1
     */
    for (b = 0; x != 0; x &= (x - 1)) {
        b++;
    }
    return b;
}

int _2_10(int c) {
    /* 因为 a < A 如果 A <= c <= Z 那么 c = c + a - A 即 c - A - a */
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}