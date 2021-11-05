//
// Created by ahogek on 10/10/21.
//

#include "chapter_three.h"

/*
 * Outputs approximation of processor time required for our two binary search functions. We search for the element - 1,
 * to time the functions' worst case performance (i.e. element not found in test data)
 */
void exercise_3_1() {
    int testdata[MAX_ELEMENT];
    int index; /* Index of found element in test data */
    int n = 100;
    int i;
    clock_t time_taken;

    /* Initialize test data */
    for (i = 0; i < MAX_ELEMENT; ++i)
        testdata[i] = i;

    /* Output approximation of time taken for 100,000 iterations of binsearch1() */
    for (i = 0, time_taken = clock(); i < 100000; ++i) {
        index = binsearch1(n, testdata, MAX_ELEMENT);
    }
    time_taken = clock() - time_taken;

    if (index < 0)
        printf("Element %d not found.\n", n);
    else
        printf("Element %d found at index %d.\n", n, index);
    printf("binsearch1() took %lu clocks (%lu seconds)\n", time_taken, time_taken / CLOCKS_PER_SEC);

    /*
     * Output approximation of time taken for 100,000 iterations of binsearch2()
     */
    for (i = 0, time_taken = clock(); i < 100000; ++i) {
        index = binsearch2(n, testdata, MAX_ELEMENT);
    }
    time_taken = clock() - time_taken;
    if (index < 0)
        printf("Element %d not found. \n", n);
    else
        printf("element %d found at index %d.\n", n, index);
    printf("binsearch2() took %lu clocks (%lu seconds)\n", time_taken, time_taken / CLOCKS_PER_SEC);
}

int binsearch1(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid]) high = mid - 1;
        else low = mid + 1;
        mid = (low + high) / 2;
    }
    if (x == v[mid]) return mid;
    else return -1;
}

/*
 * 3.4 switch语句
 * 统计数字、空白符和其他字符
 */
void listen_3_4(FILE *f) {
    int c, i, nwhite, nother, ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;
    while ((c = fgetc(f)) != EOF) {
        switch (c) {
            case '0':
            case '1' :
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
            case '7' :
            case '8' :
            case '9' :
                ndigit[c - '0']++;
                break;
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;
            default:
                nother++;
                break;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf("white spaces: %d, other: %d\n", nwhite, nother);
}

void escape(char *s, char *t) {
    int i, j;
    i = j = 0;
    while (t[i]) {
        /*  Translate the special character, if we have one  */
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            case '\a':
                s[j++] = '\\';
                s[j] = 'a';
                break;
            case '\b':
                s[j++] = '\\';
                s[j] = 'b';
                break;
            case '\f':
                s[j++] = '\\';
                s[j] = 'f';
                break;
            case '\r':
                s[j++] = '\\';
                s[j] = 'r';
                break;
            case '\v':
                s[j++] = '\\';
                s[j] = 'v';
                break;
            case '\\':
                s[j++] = '\\';
                s[j] = '\\';
                break;
            case '\"':
                s[j++] = '\\';
                s[j] = '\"';
                break;
            default:
                /*  This is not a special character, so just copy it  */
                s[j] = t[i];
                break;
        }
        ++i;
        ++j;
    }
    s[j] = t[i];    /*  Don't forget the null character  */
}

void unescape(char *s, char *t) {
    int i, j;
    i = j = 0;
    while (t[i]) {
        switch (t[i]) {
            case '\\':
                /*  We've found an escape sequence, so translate it  */
                switch (t[++i]) {
                    case 'n':
                        s[j] = '\n';
                        break;
                    case 't':
                        s[j] = '\t';
                        break;
                    case 'a':
                        s[j] = '\a';
                        break;
                    case 'b':
                        s[j] = '\b';
                        break;
                    case 'f':
                        s[j] = '\f';
                        break;
                    case 'r':
                        s[j] = '\r';
                        break;
                    case 'v':
                        s[j] = '\v';
                        break;
                    case '\\':
                        s[j] = '\\';
                        break;
                    case '\"':
                        s[j] = '\"';
                        break;
                    default:
                        /*  We don't translate this escape
                            sequence, so just copy it verbatim  */
                        s[j++] = '\\';
                        s[j] = t[i];
                }
                break;
            default:
                /*  Not an escape sequence, so just copy the character  */
                s[j] = t[i];
        }
        ++i;
        ++j;
    }
    s[j] = t[i];    /*  Don't forget the null character  */
}

void exercise_3_2() {
    char text1[50] = "\aHello,\n\tWorld! Mistakee\b was \"Extra 'e'\"!\n";
    char text2[51];

    printf("Original string:\n%s\n", text1);

    escape(text2, text1);
    printf("Escaped string:\n%s\n", text2);

    unescape(text1, text2);
    printf("Unescaped string:\n%s\n", text1);
}

/* atoi函数：将s转换为整型数 */
int atoi_3_5(char *s) {
    int i, n, sign;
    // 跳过空白符
    for (i = 0; isspace(s[i]); i++) ;
    sign = (s[i] == '-') ? -1 : 1;
    // 跳过符号
    if (s[i] == '+' || s[i] == '-') i++;
    for (n = 0; isdigit(s[i]); i++) n = 10 * n + (s[i] - '0');
    return sign * n;
}

/* shellsort函数: 按递增顺序对v[0]...v[n-1]进行排序 */
void shellsort(int *v, int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j-= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}

void shellsort_test() {
    int v[] = {1, 10, 7, 8, 4, 3, 9, 2, 5, 6};
    shellsort(v, 10);
}

/* reverse函数: 倒置字符串s中各个字符的位置 */
void reverse_3_5(char *s) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        /*
        c = s[i];
        s[i] = s[j];
        s[j] = c;
         */
        c = s[i], s[i] = s[j], s[j] = c;
    }
}

/* itoa函数: 将数字n转换为字符串并保存到s中 */
void itoa_3_6(int n, char *s) {
    int i, sign;
    if ((sign = n) < 0) /* 记录符号 */
        n = -n; /* 使n成为正数 */
    i = 0;
    do {
        s[i++] = n % 10 + '0'; /* 取下一个数字 */
    } while ((n /= 10) > 0); /* 删除该数字 */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse_3_5(s);
}

int trim_3_7(char *s) {
    int n;

    for (n = strlen(s) - 1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n+1] = '\0';
    return n;
}

