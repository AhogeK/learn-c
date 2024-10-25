//
// Created by AhogeK on 10/25/24.
//

#include <stdio.h>

// 声明每月天数的数组（非闰年和闰年）
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // 非闰年
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} // 闰年
};

/* 判断是否为闰年 */
int is_leap_year(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

/* 原始版本：使用数组下标 */
int day_of_year_orig(int year, int month, int day)
{
    if (year < 1 || month < 1 || month > 12)
        return -1;

    int leap = is_leap_year(year);

    if (day < 1 || day > daytab[leap][month])
        return -1;

    for (int i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* 指针版本：将月日转换为一年中的第几天 */
int day_of_year(int year, int month, int day)
{
    if (year < 1 || month < 1 || month > 12)
        return -1;

    int leap = is_leap_year(year);
    char* p = *(daytab + leap) + 1; // 指向当前年份的1月

    if (day < 1 || day > *(p + month - 1))
        return -1;

    // 累加之前月份的天数
    while (--month > 0)
        day += *p++;

    return day;
}

/* 原始版本：使用数组下标 */
void month_day_orig(int year, int yearday, int* pmonth, int* pday)
{
    if (year < 1 || !pmonth || !pday)
    {
        *pmonth = *pday = -1;
        return;
    }

    int leap = is_leap_year(year);
    int max_days = leap ? 366 : 365;

    if (yearday < 1 || yearday > max_days)
    {
        *pmonth = *pday = -1;
        return;
    }

    int i;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}

/* 指针版本：将一年中的第几天转换为月和日 */
void month_day(int year, int yearday, int* pmonth, int* pday)
{
    if (year < 1 || !pmonth || !pday)
    {
        *pmonth = *pday = -1;
        return;
    }

    int leap = is_leap_year(year);
    int max_days = leap ? 366 : 365;

    if (yearday < 1 || yearday > max_days)
    {
        *pmonth = *pday = -1;
        return;
    }

    char* p = *(daytab + leap) + 1; // 指向当前年份的1月

    while (yearday > *p)
    {
        yearday -= *p++;
    }

    *pmonth = p - (*(daytab + leap)); // 计算月份
    *pday = yearday;
}

/* 测试函数 */
void test_functions()
{
    // 测试用例数组
    struct
    {
        int year;
        int month;
        int day;
        int yearday;
    } tests[] = {
            {2024, 2, 29, 60}, // 闰年
            {2023, 12, 31, 365}, // 非闰年最后一天
            {2024, 1, 1, 1}, // 年初第一天
            {2023, 6, 15, 166}, // 普通日期
            {2024, 13, 1, -1}, // 无效月份
            {2023, 2, 29, -1}, // 非闰年2月29日
        };

    int month, day;

    printf("\n=== 测试 day_of_year 函数 ===\n");
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        int result = day_of_year(tests[i].year, tests[i].month, tests[i].day);
        printf("输入: %d年%d月%d日\n", tests[i].year, tests[i].month, tests[i].day);
        if (result > 0)
        {
            printf("结果: 是一年中的第 %d 天\n", result);
        }
        else
        {
            printf("结果: 无效日期\n");
        }
        printf("----------------------------------------\n");
    }

    printf("\n=== 测试 month_day 函数 ===\n");
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (tests[i].yearday > 0)
        {
            month_day(tests[i].year, tests[i].yearday, &month, &day);
            printf("输入: %d年的第%d天\n", tests[i].year, tests[i].yearday);
            if (month > 0 && day > 0)
            {
                printf("结果: %d月%d日\n", month, day);
            }
            else
            {
                printf("结果: 无效日期\n");
            }
            printf("----------------------------------------\n");
        }
    }
}

int main()
{
    test_functions();
    return 0;
}
