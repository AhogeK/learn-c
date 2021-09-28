//
// Created by ahogek on 9/28/21.
//

#include <limits.h>
#include <stdio.h>
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