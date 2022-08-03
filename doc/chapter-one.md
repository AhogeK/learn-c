# 导言

[TOC]

## 变量与算数表达式

在 C 语言中，所有变量都必须先声明后使用，声明用于说明变量的属性。

一个程序包括了注释、声明、变量、算术表达式、循环、以及格式化输出

[1_2_1.c](../ChapterOne/1_2_1.c)

```c
#include <stdio.h>

/*
 * 当 fahr = 0, 20, ..., 300时, 分别
 * 打印华氏温度与摄氏温度对照表
 */
int main() {

    int fahr;
    int celsius;
    int lower;
    int upper;
    int step;

    lower = 0;   /* 温度表的下限 */
    upper = 300; /* 温度表的上限 */
    step = 20;   /* 步长 */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

其中

```c
/*
 * 当 fahr = 0, 20, ..., 300时, 分别
 * 打印华氏温度与摄氏温度对照表
 */
```

属于注释

在 C 语言中，所有的变量都需要先声明后使用，声明用于说明变量的属性

```c
int fahr, celsius;
int lower, uper, step;
```

其中 ``int`` 代表数据类型，类似的还有 ``float`` 等等，C 语言在不同的计算机可能相同的数据类型会有不同范围，
对于 int 类型通常为16位，float 类型通常是32位。

``while`` 循环体如果只有一条语句可以省略花括号

```c
while (i < j)
    i = 2 * i;
```

这样的缩进方式为了突出逻辑结构，建议每行只写一条语句，运算符两边各加一个空格字符。学会养成一直使用一种风格的好习惯

```c
celsius = 5 * (fahr - 32) / 9
```

在 C 语言中及许多其他语言中，整数除法操作将执行舍位，结果中的任何小数部分都会被舍弃。

在代码中可以看到 ``%d`` 的符号，其指代整型参数

```c
printf("%d\t%d\n", fahr, celsius);
```

ANSI标准定义了``printf``函数的行为

相关的知识你可以查阅 [wiki百科](https://en.wikipedia.org/wiki/Printf_format_string) 关于 printf format string 的内容

代码中的 ``printf`` 是可以指明打印的参数，如下

```c
printf("%3d %6d\n", fahr, celsius);
```

因为上述的代码中我们用的是整型类型的数值导致计算后摄氏度失去了精度，因此下面对代码进行了修改

[1_2_2.c](../ChapterOne/1_2_2.c)
```c
#include <stdio.h>

/*
 * 当 fahr = 0, 20, ..., 300时, 分别
 * 打印华氏温度与摄氏温度对照表
 * 浮点数版本
 */
int main() {

    float fahr;
    float celsius;
    float lower;
    float upper;
    float step;

    lower = 0;   /* 温度表的下限 */
    upper = 300; /* 温度表的上限 */
    step = 20;   /* 步长 */

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0f / 9.0f) * (fahr - 32.0f);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
```

[关于温度的转换](https://en.wikipedia.org/wiki/Conversion_of_scales_of_temperature)

在算术运算中如果有一浮点数，那么其结果就会为浮点类型

``%3.0f`` 表明打印浮点数，且至少占3个字符宽，且不带小数部分

``%6.1f`` 表明打印浮点数，且至少占6个字符宽，且带一位小数部分

在浮点数打印中，有类似``%.2f``这样的写法，这代表带有两位小数且宽度不受限制

| 格式    | 说明                        |
|-------|---------------------------|
| %d    | 按照十进制整数打印                 |
| %6d   | 按照十进制整数打印，至少6个字符宽         |
| %f    | 按照浮点数打印                   |
| %6f   | 按照浮点数打印，至少6个字符宽           |
| %.2f  | 按照浮点数打印，小数点后有两位小数         |
| %6.2f | 按照浮点数打印，至少6个字符宽，小数点后有两位小数 |

## for 语句

对于某种特定任务，我们可以采用多种方法来编写程序，上小节中，我们使用了 while 来打印温度转换，
同样的我们也可以使用 for 循环来打印

[1_3_1.c](../ChapterOne/1_3_1.c)

```c
#include <stdio.h>

/*
 * 打印华氏温度-摄氏温度对照表
 */
int main() {
    for (int fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
```

## 符号常量

在程序代码中经常使用类似 300 20 等这样类似的"幻数"并不是一个好习惯，处理这种幻数的一种方法是赋予他们有意义的名字。
``#define`` 指令就是一种方式

```c
#define 名字 替换文本
```

例如如下代码案例：

```c
#include <stdio.h>

#define LOWER 0     /* 温度表的下限 */
#define UPPER 300   /* 温度表的上限 */
#define STEP  20     /* 步长 */

/*
 * 打印华氏温度-摄氏温度对照表
 */
int main() {
    for (int fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
```

符号常量通常用大写字母拼写，注意 ``#define`` 指令行的末尾没有分号

## 字符输入/输出

标准库提供的输入/输出模型，其输入/输出都是按照字符流的方式处理。

标准库提供了一次读/写一个字符的函数 ``getchar``/``putchar``

```c
c = getchar();
putchar(c);
```

### 文件复制

编写一个程序，将输入复制到输出

[1_5_1.c](../ChapterOne/1_5_1.c)

```c
#include <stdio.h>

/*
 * 将输入复制到输出: 版本1
 */
int main() {
    int c;

    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
```

字符在任何地方以什么形式展现，它在机器内都会以位模式存储。``char``专门用来存储这种类型数据，当然任何整型(int)也可以用于存储这类数据。

上述代码中可以看到一个 ``EOF`` 符号，这个符号称之为 (end of file，文件结束)。代表的是一个输入的结束符，上述中为什么使用 ``int`` 的一个重要的原因就是这个 c
要有足够空间存储所有的可以的字符包括 ``EOF``，而它定义在 ``<stdio.h>`` 中，并且是一个整型数。

上述的代码可以将为c赋值的操作放在while循环语句的测试部分中

[1_5_2.c](../ChapterOne/1_5_2.c)

```c
#include <stdio.h>

/*
 * 将输入复制到输出: 版本2
 */
int main() {
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);
}
```

赋值表达式两边的圆括号不能省略。不等于运算符 ``!=`` 的优先级比赋值运算符 ``=`` 的优先级要高

### 字符计数

下列程序用于对字符进行计数

[1_5_3.c](../ChapterOne/1_5_3.c)

```c
#include <stdio.h>

/* 统计输入字符数： 版本1 */
int main() {
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld \n", nc);
}
```

这里引用了新的运算符 ``++``，可以用语句 ``nc = nc + 1`` 代替。但 ``++nc`` 更加精炼

该计数程序使用了 ``long`` 类型，long为整数型号（长整型）至少要占用32位存储单元

上述代码中，出现了 ``%ld`` 它告诉printf函数其对应的参数是long整型

使用 ``double`` （双精度浮点数）类型可以处理更大的数字。下面的代码将被通过for循环语句来展示另外一种写法

[1_5_4.c](../ChapterOne/1_5_4.c)

```c
#include <stdio.h>

/* 统计输入的字符数：版本2 */
int main() {
    double nc;

    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}
```

``%.0f`` 强制不打印小数点和小数部分，因此小数部分的位数为0

上述代码中，for循环语句的循环体是空的，这是因为所有工作都会在条件中完成。单独的分号称之为空语句，它正好可以满足for语句必须要一个循环体的要求

### 行计数

接下来的程序用于统计输入的行数。统计行数等价于统计换行符的个数

```c
#include <stdio.h>

/* 统计输入的行数 */
int main() {
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}
```

'\n'是一个仅包含一个字符的字符串常量

### 单词计数

这里将统计任何不包含空格、制表符或换行符的字符序列的个数

```c
#include <stdio.h>

#define IN 1  /* 在单词内 */
#define OUT 0 /* 在单词外 */

/* 统计输入的行数、单词数与字符数 */
int main() {
    int c;
    int nl;
    int nw;
    int nc;
    int state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}
```

代码中 ``nl = nw = nc = 0`` 赋值结合次序是由右至左
