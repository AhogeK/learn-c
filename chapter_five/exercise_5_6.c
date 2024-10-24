//
// Created by AhogeK on 10/24/24.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000    // 最大输入行长度
#define NUMBER '0'      // 表示找到一个数字的信号

// getline：读取一行输入到s中，返回长度
int getline_pointer(char* s, int lim)
{
    const char* start = s; // 保存起始位置
    int c = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';

    return s - start; // 返回长度
}

// atoi：将字符串s转换为整数
int atoi_pointer(char* s)
{
    int n = 0;

    // 跳过空白符
    while (isspace(*s))
        s++;

    // 处理符号
    const int sign = *s == '-' ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;

    // 转换数字
    while (isdigit(*s))
        n = 10 * n + (*s++ - '0');

    return sign * n;
}

// itoa：将数字n转换为字符串存入s中
void itoa_pointer(int n, char* s)
{
    char* start = s; // 保存起始位置
    int sign;

    if ((sign = n) < 0) // 记录符号
        n = -n; // 使n成为正数

    do
    {
        // 生成数字（反向）
        *s++ = n % 10 + '0';
    }
    while ((n /= 10) > 0);

    if (sign < 0)
        *s++ = '-';

    *s = '\0';

    // 反转字符串
    char* end = s - 1; // 指向最后一个字符
    s = start; // 重置s到开始位置
    while (s < end)
    {
        const char temp = *s;
        *s++ = *end;
        *end-- = temp;
    }
}

// reverse：反转字符串
void reverse_pointer(char* s)
{
    char* end = s + strlen(s) - 1; // 指向最后一个字符

    while (s < end)
    {
        const char temp = *s;
        *s++ = *end;
        *end-- = temp;
    }
}

// strindex：返回t在s中最右边出现的位置
int strindex_pointer(char* s, char* t)
{
    char* s1 = s + strlen(s) - strlen(t); // 从可能的最右位置开始

    while (s1 >= s)
    {
        char* original_s1 = s1;
        const char* t1 = t;
        while (*t1 != '\0' && *s1 == *t1)
        {
            s1++;
            t1++;
        }
        if (*t1 == '\0') // 找到匹配
            return original_s1 - s;
        s1 = original_s1 - 1;
    }
    return -1;
}

// getop：获取下一个运算符或数值操作数
int getop_pointer(char* s)
{
    static char* p = NULL; // 用于保持输入缓冲的位置
    char* original_s = s; // 保存起始位置

    // 跳过空白符
    while ((*s = getchar()) == ' ' || *s == '\t');

    *(s + 1) = '\0'; // 预先放置字符串结束符

    if (!isdigit(*s) && *s != '.')
        return *s; // 不是数字

    if (isdigit(*s)) // 收集整数部分
        while (isdigit(*++s = getchar()))
        {
        }

    if (*s == '.') // 收集小数部分
        while (isdigit(*++s = getchar()))
        {
        }

    *s = '\0';
    return NUMBER;
}

// 测试函数
int main()
{
    char line[MAXLINE];
    char s[100];

    // 测试 getline_pointer
    printf("输入一行文本：");
    const int len = getline_pointer(line, MAXLINE);
    printf("读取的行（长度 %d）：%s", len, line);

    // 测试 atoi_pointer
    printf("\n测试atoi_pointer：\n");
    printf("'123' => %d\n", atoi_pointer("123"));
    printf("'-456' => %d\n", atoi_pointer("-456"));

    // 测试 itoa_pointer
    printf("\n测试itoa_pointer：\n");
    itoa_pointer(12345, s);
    printf("12345 => %s\n", s);
    itoa_pointer(-67890, s);
    printf("-67890 => %s\n", s);

    // 测试 reverse_pointer
    printf("\n测试reverse_pointer：\n");
    strcpy(s, "Hello, World!");
    printf("原字符串：%s\n", s);
    reverse_pointer(s);
    printf("反转后：%s\n", s);

    // 测试 strindex_pointer
    printf("\n测试strindex_pointer：\n");
    char* text = "hello world hello";
    char* pattern = "hello";
    const int pos = strindex_pointer(text, pattern);
    printf("'%s' 在 '%s' 中最右出现的位置：%d\n",
           pattern, text, pos);

    // 测试 getop_pointer
    printf("\n测试getop_pointer：\n");
    printf("输入一个数字或运算符：");
    const int type = getop_pointer(s);
    if (type == NUMBER)
        printf("获取到数字：%s\n", s);
    else
        printf("获取到运算符：%c\n", type);

    return 0;
}
