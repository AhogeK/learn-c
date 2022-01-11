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

#### 练习 1-14

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

#### 1.7 测试power函数

```c
int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

main()
{
    int i;
    
    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}
```

#### 练习 1-15

> 重新编写1.2节中的温度转换程序，使用函数实现温度转换计算。

```c
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
```

#### 1.8 power函数 版本2

```c
int powerv2(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}
```

#### 1.9 打印最长的输入行

```c
#include <stdio.h>

#define MAXLINE 1000 /* 允许的输入行的最大长度 */

/* get_line函数：将一行读入s中并返回其长度 */
int get_line(char s[], int lim, FILE *f);

/* copy函数: 将from复制到to;这里假定to足够大 */
void copy(char to[], char from[]);

/* 打印最长的输入行 */
void char_array(FILE *f)
{
    int len; /* 当前行长度 */
    int max; /* 目前为止发现的最长行长度 */
    char line[MAXLINE]; /* 当前的输入行 */
    char longest[MAXLINE]; /* 用于保存最长的行 */

    max = 0;
    while ((len = get_line(line, MAXLINE, f)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* 存在这样的行 */
        printf("%s", longest);
}

int get_line(char s[], int lim, FILE *f)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = fgetc(f)) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
```

#### 练习 1-16

> 修改打印最长文本行的程序的主程序main，使之可以打印任意长度的输入行的长度，并尽可能多地打印文本。

```c
#define MAXLINE 1000 /* 允许的输入行的最大长度 */

int mgetline(char s[], int lim, FILE *f);

void exercise_1_6(FILE *f)
{
    int len, max;
    char line[MAXLINE], maxline[MAXLINE];

    max = 0;

    while ((len = mgetline(line, MAXLINE, f)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(maxline, line);
        }
    }
    if (max > 0)
        printf("%s", maxline);
}

int mgetline(char s[], int lim, FILE *f)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = fgetc(f)) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
```

#### 练习 1-17

> 编写一个程序，打印长度大于80个字符的所有输入行。

```c
#define MAXLINE 1000 /* 允许的输入行的最大长度 */

int ngetline(char line[], int lim, FILE *f)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void exercise_1_17(FILE *f)
{
    int len;
    char line[MAXLINE];

    while ((len = ngetline(line, MAXLINE, f)) > 0)
    {
        if (len > LIMIT)
            printf("%s", line);
    }
}
```

#### 练习 1-18

> 编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行

```c
#define MAXLINE 1000 /* 允许的输入行的最大长度 */

/* 用于删除空格与制表符 */
int removetrail(char rline[])
{
    int i;

    for (i = 0; rline[i] != '\n'; ++i);
        --i; /* 除去最后的 \n */

    for (i > 0; ((rline[i] == ' ') || (rline[i] == '\t')); --i); /* 除去空格及制表符号 */

    if (i >= 0) /* 说明不是空行 */
    {
        ++i;
        rline[i] = '\n';
        ++i;
        rline[i] = '\0';
    }
    return i;
}

void exercise_1_18(FILE *f)
{
    int len;
    char line[MAXLINE];

    while ((len = mgetline(line, MAXLINE, f)) > 0)
        if (removetrail(line) > 0)
            printf("%s", line);
}
```

#### 练习 1-19

> 编写函数 reverse(s)，将字符串s中的字符串顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序

```c
void reverse(char rline[])
{
    int i, j;
    char temp;

    for (i = 0; rline[i] != '\0'; ++i)
        ;

    --i; /* 获取 rline 的长度 i */

    if (rline[i] == '\n') --i; /* 去除换行符 */

    j = 0;
    while (j < i)
    {
        temp = rline[j];
        rline[j] = rline[i];
        rline[i] = temp;
        --i;
        ++j;
    }
}

void exercise_1_19(FILE *f)
{
    int len;
    char line[MAXLINE];

    while ((len = mgetline(line, MAXLINE, f)) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
}
```

#### 1.10 打印最长的输入行: 特别版本

```c
#include <stdio.h>

#define MAXLINE 1000    /* 允许的输入行的最大长度 */

int max;                /* 到目前为止发现的最长行长度 */
char line[MAXLINE];     /* 当前的输入行 */
char longest[MAXLINE];   /* 用于保存最长的行 */

int get_line2(FILE *);

void copy2(void);

/* 打印最长的输入行; 特别版本 */
void external_variable_and_scope(FILE *f) {
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = get_line2(f)) > 0)
        if (len > max) {
            max = len;
            copy2();
        }
    if (max > 0)
        printf("%s", longest);
}

/* get_line: 外部变量版 */
int get_line2(FILE *f) {
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 && (c = fgetc(f)) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: 外部变量版本 */
void copy2() {
    int i;
    extern char line[], longest[];
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
```

#### 练习 1-20

> 编写程序 detab，将输入中的制表符替换成适当数目的空格,使空格充满到下一个制表符终止位的地方。

```c
#define TABINC 4

void exercise_1_20(FILE *f) {
    int nb, pos, c;
    nb = 0;
    pos = 1;

    while ((c = fgetc(f)) != EOF) {
        if (c == '\t') {
            nb = TABINC;

            while (nb > 0) {
                putchar('#');
                ++pos;
                --nb;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }
}
```

#### 练习 1-21

> 编写程序entab, 将空格串替换为最少数量的制表符和空格，但要保持单词之间的间隔不变。

```c
void exercise_1_21(FILE *f) {
    int i, t;
    int spacecount, len;

    while ((len = get_line2(f)) > 0) {
        spacecount = 0;
        for (i = 0; i < len; i++) {
            if (line[i] == ' ')
                spacecount++; /* 每一个空格 + 1 */
            if (line[i] != ' ')
                spacecount = 0; /* 重置数量 */
            /*
             * 如果为true就说明有足够的空格为一个退格
             */
            if (spacecount == TABINC) {
                /*
                 * 因为我们要将4个空格替换为一个退格，因为我们需要回退三个字节并将一个空格替换为退格
                 */
                i -= 3;
                len -= 3;
                line[i] = '\t';
                /*
                 * 现在移动所有的字符向左移动三位，即i后的每一位为该位的+3位
                 */
                for (t = i + 1; t < len; t++)
                    line[t] = line[t + 3];
                /*
                 * 现在重置空格数量为0,并将该行的最后一个字符为\0
                 */
                spacecount = 0;
                line[len] = '\0';
            }
        }
        printf("%s", line);
    }
}
```

#### 练习 1-22

> 编写一个程序，把较长的输入行"折"成短一些的两行或多行，折行位置在输入行的第n列之前的最后一个非空之后。

```c
void exercise_1_22(FILE *f) {
    int t, len;
    int location, spaceholder;
    const int FOLDLENGTH = 70; /* 每行最长长度，多出换行 */

    while ((len = get_line2(f)) > 0) {
        if (len < FOLDLENGTH) {

        } else {
            /*
             * 如果该行超长，我们就循环替换离 FOLDLENGTH 最近的空格为换行符
             */
            t = 0;
            location = 0;
            spaceholder = 0;
            while (t < len) {
                if (line[t] == ' ' || line[t] == '\t')
                    spaceholder = t;

                if (location == FOLDLENGTH) {
                    if (spaceholder != 0) {
                        line[spaceholder] = '\n';
                        location = 0;
                    }
                }
                location++;
                t++;
            }
        }
        printf("%s", line);
    }
}
```

### 第二章

#### 练习 2-1

> 编写一个程序以确定分别由signed及unsigned限定的char, short, int 与 long类类型变量的取值范围。采用打印标准头文件中的相应值以及直接
> 计算两种方式实现。后一种方法的实现困难一些，因为要确定各种浮点类型的取值范围。

```c++
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
```

#### 2.3 strlen函数

```c
#include <stdio.h>

/* strlen函数：返回s的长度 */
int strlen_test(char s[]) {
    int  i;

    i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

int main() {
    printf("%d", strlen_test("hello"));
}
```

#### 2.6 练习 2-2

> 在不使用运算符&&或||的条件下编写一个与上面的for循环语句等价的循环语句

```c
void _2_2() {
    int lim = 10;
    int c;
    for (int i = 0;; i++) {
        if (i < lim - 1) {
            if ((c = getchar()) != 'n') {
                if (c != EOF) {
                    // do something
                }
            }
        }
        break;
    }
}
```

#### 2.7 atoi函数

```c
#include <stdio.h>

/* atoi函数：将字符串s转换为相应的整型数 */
int atoi(char s[]) {
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int main() {
    printf("%d", atoi("15"));
}
```

#### 2.7 lower函数

```c
#include <stdio.h>

/* lower函数：把字符c转换为小写形式;只对ASCII字符集有效 */
int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int main() {
    printf("%c", lower('C'));
}
```

#### 2.7 rand与srand函数

```c
#include <stdio.h>

unsigned long int next = 1;

/* rand函数: 返回取值为0~32767的伪随机数 */
int rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

/* srand函数: 为rand()函数设置种子数 */
void srand(unsigned int seed) {
    next = seed;
}

int main() {
    srand(11111111);
    printf("%d", rand());
}
```

#### 2.7 练习2-3

> 编写函数htoi(s), 把由十六进制数字组成的字符串(包含可选的前缀0x或0X)转换为与之等价的整型值. 字符串中允许包含的数字包括: 0~9, a~f以及A~F.

```c
/* 将16进制的字符转换为十进制值 */
long hchartoi(char hexdig, int pos) {
    char hexdigits[] = "0123456789ABCDEF";
    // 16进制下标下的字符
    char *p = &hexdigits[0];
    // 遍历的下标
    long deci = 0;
    int i;
    
    while (*p != toupper(hexdig) && deci < 16) {
        ++p;
        ++deci;
    }
    // 如果字符就是传入的字符,求十进制值
    if (*p == toupper(hexdig)) {
        for (i = 0; i < pos; i++)
            deci *= 16;
        return deci;
    }
    return -1;
}

/* 将16进制数组成的字符串转换为整形值 */
long htoi(char hexstring[]) {
    /* 取最后一个字符 *p */
    char *p = &hexstring[strlen(hexstring) - 1];
    /* deci为最终值，dig为字符串元素字符转换后的十进制值 */
    long deci = 0, dig;
    /* 位数 */
    int pos = 0;
    
    /*
     * p指针为 hexstring指针指向下的元素，所以p指针转成的整数会大于等于hexstring指针转成的整数，其中p下标为0的指针与hexstring指针
     * 相同，说明数组的指针指向的是第一个元素的指针，且有序排列
     */
    while (p >= hexstring) {
        if ((dig = hchartoi(*p, pos)) < 0) {
            printf("Error\n");
            return -1;
        }
        deci += dig;
        /* 当下标为-1的数组指针必定小于hestring的指针，便会退出循环 */
        --p;
        ++pos;
    }
    return deci;
}
```

#### 2.8 squeeze函数

```c
#include <stdio.h>

/* squeeze函数: 从字符串s中删除字符c */
void squeeze(char s[], int c) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

int main() {
    char s[] = "squeeze";
    squeeze(s, 'q');
    printf("via squeeze: %s\n", s);
    return 0;
}
```

#### 2.8 strcat函数

```c
#include <stdio.h>

/* strcat函数: 将字符串t连接到字符串s的尾部; s必须有足够大的空间 */
void strcat(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0') /* 判断是否为字符串 s 的尾部 */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* 拷贝 t */
        ;
}

int main() {
    char s[100];
    char t[] = "strcat";
    strcat(s, t);
    printf("%s", s);
}
```