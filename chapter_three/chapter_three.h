//
// Created by ahogek on 10/10/21.
//

#ifndef LEARN_C_CHAPTER_THREE_H
#define LEARN_C_CHAPTER_THREE_H

#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_ELEMENT 20000

void exercise_3_1();

int binsearch1(int, int[], int);

int binsearch2(int, int[], int);

void listen_3_4(FILE *f);

void escape(char *s, char *t);

void unescape(char *s, char *t);

void exercise_3_2();

int atoi_3_5(char s[]);

void shellsort(int v[], int n);

void shellsort_test();

void reverse_3_5(char s[]);

void itoa_3_6(int n, char s[]);

int trim_3_7(char s[]);

#endif //LEARN_C_CHAPTER_THREE_H
