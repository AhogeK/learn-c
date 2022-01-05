# learn-c

> C 语言学习。学习材料为 《C 程序设计语言 第二版新版》内容主要为材料中的案例与练习

## C 程序设计语言

### 第一章

#### 1.2 华氏温度与摄氏温度对照表

```c
/*
 * 当 fahr = 0, 20, ..., 300时，分别打印华氏温度与摄氏温度对照表
 */
void fahrAndCelsius()
{
int fahr, celsius;
int lower, upper, step;

lower = 0;
upper = 300;
step = 20;

fahr = lower;
printf("%s\n", "不带浮点数的表");
while (fahr <= upper)
{
celsius = 5 * (fahr - 32) / 9;
printf("%d\t%d\n", fahr, celsius);
fahr = fahr + step;
}
}
```

```c
/*
 * 浮点版本
 */
void floatFahrAndCelsius()
{
float fahrenheit, celsius;
int lower, upper, step;

lower = 0;
upper = 300;
step = 20;

fahrenheit = lower;
printf("%s\n", "带浮点数的表");
while (fahrenheit <= upper)
{
celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
printf("%3.0f %6.1f\n", fahrenheit, celsius);
fahrenheit = fahrenheit + step;
}
}
```

#### 练习 1-4

> 编写一个程序打印摄氏度温度转转为相应华氏温度的转换表

```c
/**
 * 摄氏度转华氏
 */
void celsiusToFahrenheit()
{
float fahrenheit, celsius;
int lower, upper, step;

lower = -20;
upper = 40;
step = 5;

celsius = lower;
printf("%s\n", "打印摄氏度转华氏表");
while (celsius <= upper)
{
fahrenheit = celsius * 9 / 5 + 32;
printf("%3.0f %3.1f\n", celsius, fahrenheit);
celsius += step;
}
}
```

#### 1.3 for 循环打印华氏温度 - 摄氏温度对照表

```c
void forLoopPrint()
{
    int fahrenheit;

    for (fahrenheit = 0; fahrenheit <= 300; fahrenheit = fahrenheit + 20)
        printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
}
```

```c
/**
 * for 循环打印 摄氏度-华氏对照表
 */
void forLoopCelsiusToFahrenheit()
{
for (int celsius = -20; celsius <= 40; celsius += 5)
printf("%3d %6.1f\n", celsius, celsius * (9.0 / 5.0) + 32);
}
```

#### 1.4 符号常量

```c
#include <stdio.h>

#define LOWER  0    /* 温度表的下限 */
#define UPPER 300   /* 温度表的上限 */
#define STEP 20     /* 步长 */
/**
 * 符号常量
 */
void symbolConstants()
{
    int fahrenheit;

    for (fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit += STEP)
        printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
}
```

#### 1.5 文件字符的输入输出

```c
void firstInputAndOutput(FILE *pFile)
{
//    char c = getchar();
    putchar(fgetc(pFile));
    printf("\n");
}
```

#### 1.5 文件复制

```c
void fileCopy(FILE *pFile)
{
int c;

while ((c = fgetc(pFile)) != EOF)
{
putchar(c);
}
printf("\n");
}
```

#### 练习 1-6

> 验证表达式 getchar() != EOF 的值是0还是1

```c
void verifyGetchar(FILE *pFile)
{
    int value;
    value = (fgetc(pFile) != EOF);
    printf("%d\n", value);
}
```

#### 练习 1-7

> 编写一个打印EOF值的程序

```c
void printEOF()
{
    printf("This is EOF: %d\n", EOF);
}
```

#### 1.5.2 字符计数版本1

```c
void charCount(FILE *pFile)
{
    long nc;
    nc = 0;
    while (fgetc(pFile) != EOF)
        ++nc;
    printf("%ld\n", nc);
}
```

#### 1.5.2 字符计数版本2

```c
void charCountV2(FILE *pFile)
{
    int nc;
    for (nc = 0; fgetc(pFile) != EOF; ++nc);
    printf("%d\n", nc);
}
```

#### 1.5.3 行计数

```c
void rowCount()
{
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
```

#### 练习 1-8

> 编写一个统计空格 制表符与换行符个数的程序

```c
void statistic()
{
    long c, sn, bn, nn;
    sn, bn, nn = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++sn;
        if (c == '\b')
            ++bn;
        if (c == '\n')
            ++nn;
    }
    printf("空格数量：%ld\t退格数量：%ld\t换行数量：%ld\n", sn, bn, nn);
}
```

#### 练习 1-9

> 编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替

```c
void copyOutput()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            putchar(c);
            while ((c = getchar()) == ' ');
        }
        if (c == EOF)
            break;
        putchar(c);
    }
}
```

#### 练习 1-10

> 编写一个将输入复制到输出的程序，并将其中的制表符替换为\t，将回退符替换为\b，将反斜杠替换为\\。这样可以将制表符和回退符以可见的方式显示出来

```c
void toEscString()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
            case '\t':
                putchar(ESC_CHAR);
                putchar('t');
                break;
            case '\b':
                putchar(ESC_CHAR);
                putchar('b');
                break;
            case ESC_CHAR:
                putchar(ESC_CHAR);
                putchar(ESC_CHAR);
            default:
                putchar(c);
                break;
        }
    }
}
```

#### 1.5.4 单词计数

```c
void wordCount()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("行数：%d\t\t单词数：%d\t字符数：%d\n", nl, nw, nc);
}
```

#### 练习 1-11

> 你准备如何测试单词计数程序？如果程序中存在某种错误，那么什么样的输入最可能发现这类错误呢？

```c
void unitTest(void)
{
    FILE *f;
    unsigned long i;
    static char *al = "abcdefghijklmnopqrstuvwxyz";

    /* 输入一个没有字符的文件 */
    f = fopen("test0", "w");
    assert(f != NULL);
    fclose(f);

    /* 输入一个巨大的单词没有换行的文件 */
    f = fopen("test1", "w");
    assert(f != NULL);
    for (i = 0; i < ((66000ul / 26) + 1); i++)
        fputs(al, f);
    fclose(f);

    /* 输入一个包含大量空行的文件 */
    f = fopen("test2", "w");
    assert(f != NULL);
    for (i = 0; i < 66000; i++)
        fputc('\n', f);
    fclose(f);
}
```

#### 练习 1-12

> 编写一个程序，以每一行一个单词的形式打印其输入。

```c
void exercise_1_12()
{
    int c, state;
    state = IN;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            putchar('\n');
            putchar(c);
        }
        else
            putchar(c);
    }
}
```

#### 1.6 统计数字，空白符及其他字符出现的次数

```c
void array_1_6(FILE *f)
{
int c, i, nwhite, nother;
int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;


    while ((c = getc(f)) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
    fclose(f);
}
```

#### 练习 1-13

> 编写一个程序，打印输入中单词长度的直方图。水平方向的直方图比较容易绘制，垂直方向的直方图要困难些

```c
#define MAXWL 5         /* 最长单词长度 */
#define MAXNO 12        /* 总单词数 */

// 水平
void exercise_1_13(FILE *f)
{
    int c, temp;
    while ((c = fgetc(f)) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (temp != ' ' && temp != '\n' && temp != '\t')
            {
                putchar('\n');
                temp = c;
            }
        } else
        {
            putchar('*');
            temp = c;
        }
    }
}

// 垂直
void exercise_1_13_2(FILE *f)
{
    int word[MAXNO];
    int i, c, j, nc, nw;

    for (i = 0; i < MAXNO; ++i)
        word[i] = 0;

    nc = nw = 0;

    int temp;
    while ((c = fgetc(f)) != EOF)
    {
        ++nc;
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (temp != ' ' && temp != '\n' && temp != '\t')
            {
                /* 在单词长度中不包含空 */
                word[nw] = nc - 1;
                ++nw;
                /* 为下个重置单词长度 */
                nc = 0;
                temp = c;
            }
        } else
            temp = c;
    }
    for (i = MAXWL; i >= 1; --i)
    {
        for (j = 0; j <= nw; ++j)
        {
            if (i <= word[j])
                putchar('*');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}
```

#### 练习-14

> 编写一个程序，打印输入中各个字符出现频读的直方图

```c
#define TOTAL_CHARS 128 /* 字符数的总长为128, 0 - 127 */

void exercise_1_14(FILE *f)
{
    int c, i, j;

    int _char[TOTAL_CHARS];
    for (i = 0; i < TOTAL_CHARS; ++i)
        _char[i] = 0;

    while ((c = fgetc(f)) != EOF)
        _char[c] = _char[c] + 1;

    for (i = 0; i < TOTAL_CHARS; ++i)
    {
        putchar(i);

        for(j = 0; j < _char[i]; ++j)
            putchar('*');

        putchar('\n');
    }
}
```