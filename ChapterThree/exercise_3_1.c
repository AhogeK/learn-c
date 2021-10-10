//
// Created by ahogek on 10/10/21.
//

#include "exercise_3_1.h"

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