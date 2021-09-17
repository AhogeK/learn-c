//
// Created by ahogek on 9/17/21.
//
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void fahrtocelsius();

void celsiustofahr();

int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

void exercise_1_15()
{
    int c;

    printf("Temperature Conversion Table\n");
    printf("1 - Fahrenheit to Celsius Conversion \n");
    printf("2 - Celsius to Fahrenheit Conversion \n");
    printf("- Enter your Choice\n");

    c = getchar();

    if (c == '1')
        fahrtocelsius();
    else if (c == '2')
        celsiustofahr();
    else
        printf("Invalid Choice \n");
}

void celsiustofahr()
{
    float celsius;

    for (celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP)
        printf("%3.0f%6.1f\n", celsius, (9.0 * celsius) / 5.0 + 32);
}

void fahrtocelsius()
{
    float fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3.0f%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
}