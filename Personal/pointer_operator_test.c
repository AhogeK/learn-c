//
// Created by ahogek on 9/16/21.
//
#include "stdio.h"

void pointer_op_test() {
    int x = 5;
    int *pointer_to_x = &x;
    *pointer_to_x = 6;
    int normal_x = x;
    normal_x = 7;
    printf("x: %d\nnormal_x: %d", x, normal_x);
}