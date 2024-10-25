//
// Created by AhogeK on 10/25/24.
//

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // 非闰年
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} // 闰年
};

/* 判断是否为闰年 */
int is_leap_year(int year)
{
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

/* day_of_year: 将月日转换为一年中的第几天 */
int day_of_year(int year, int month, int day)
{
    if (year < 1)
    {
        return -1;
    }

    if (month < 1 || month > 12)
    {
        return -2;
    }

    int leap = is_leap_year(year);

    if (day < 1 || day > daytab[leap][month])
    {
        return -3;
    }

    int i;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: 将一年中的第几天转换为月和日 */
int month_day(int year, int yearday, int* pmonth, int* pday)
{
    if (year < 1)
    {
        return -1;
    }

    if (pmonth == NULL || pday == NULL)
    {
        return -2;
    }

    int leap = is_leap_year(year);
    int max_days = leap ? 366 : 365;

    if (yearday < 1 || yearday > max_days)
    {
        return -3;
    }

    int i;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
    return 0;
}

/* 打印day_of_year的测试结果 */
void print_day_of_year_result(const char* test_name, int year, int month, int day)
{
    printf("\n测试用例: %s\n", test_name);
    printf("输入: %d年%d月%d日\n", year, month, day);

    int result = day_of_year(year, month, day);
    switch (result)
    {
    case -1:
        printf("结果: 错误 - 年份必须大于0\n");
        break;
    case -2:
        printf("结果: 错误 - 月份必须在1到12之间\n");
        break;
    case -3:
        printf("结果: 错误 - 日期无效（超出当月天数范围）\n");
        break;
    default:
        printf("结果: 是一年中的第 %d 天\n", result);
    }
    printf("----------------------------------------\n");
}

/* 打印month_day的测试结果 */
void print_month_day_result(const char* test_name, int year, int yearday)
{
    printf("\n测试用例: %s\n", test_name);
    printf("输入: %d年的第%d天\n", year, yearday);

    int month, day;
    int result = month_day(year, yearday, &month, &day);

    switch (result)
    {
    case -1:
        printf("结果: 错误 - 年份必须大于0\n");
        break;
    case -2:
        printf("结果: 错误 - 无效的指针\n");
        break;
    case -3:
        printf("结果: 错误 - 一年中的天数无效（%d年的天数范围为1-%d）\n",
               year, is_leap_year(year) ? 366 : 365);
        break;
    default:
        printf("结果: %d月%d日\n", month, day);
    }
    printf("----------------------------------------\n");
}

int main()
{
    printf("\n=== day_of_year 函数测试 ===\n");

    print_day_of_year_result(
        "正常闰年日期",
        2024, 2, 29
    );

    print_day_of_year_result(
        "非闰年2月29日",
        2023, 2, 29
    );

    print_day_of_year_result(
        "无效月份",
        2023, 13, 1
    );

    print_day_of_year_result(
        "超出当月天数",
        2023, 4, 31
    );

    print_day_of_year_result(
        "无效年份",
        0, 1, 1
    );

    printf("\n=== month_day 函数测试 ===\n");

    print_month_day_result(
        "正常闰年日期",
        2024, 60
    );

    print_month_day_result(
        "无效年份",
        0, 60
    );

    print_month_day_result(
        "非闰年超出天数",
        2023, 366
    );

    printf("\n测试用例: 空指针测试\n");
    printf("输入: 传入NULL指针\n");
    int result = month_day(2023, 60, NULL, NULL);
    printf("结果: %s\n", result == -2 ? "错误 - 无效的指针" : "未知错误");
    printf("----------------------------------------\n");

    return 0;
}
