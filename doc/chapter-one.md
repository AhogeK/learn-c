# 导言

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

在算术运算中如果有一浮点数，那么其结果就会为浮点类型

``%3.0f`` 表明打印浮点数，且至少占3个字符宽，且不带小数部分

``%6.1f`` 表明打印浮点数，且至少占6个字符款，且带一位小数部分

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