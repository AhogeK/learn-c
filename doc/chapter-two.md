## 第二章 类型、运算符与表达式

ANSI标准，所有整形都包含 ``signed``(带符号) ``unsigned``(无符号)。可以表示无符号常量与十六进制字符常量。
ANSI标准的C还支持枚举类型。对象可以声明为``const``(常量)

### 2.1 变量名

名字是由字母和数字组成的序列，第一个字符必须是字母。``_`` 被看作为字母，通常用于较长的变量名，库例程通常以下划线开头，因此变量名不要使用下划线开头

x与X是两个不同的变量名

变量名使用小写字母，常量全部使用大写字母

对于内部名而言，至少前31个字符是有效的。函数名与外部变量名可能小于31，因为汇编程序和加载程序可能会使用这些外部名，而语言本法没法控制加载和
汇编程序

对于外部名，ANSI标准仅保证前6个字符的唯一性，不区分大小写。

关键字本身不能作为变量名，所有关键字字母都必须小写

变量名尽量从字面上表达其含义，局部变量建议使用较短的变量名，尤其循环变量；外部则建议使用较长的名字

### 2.2 数据类型及长度

* char 字符型 一字节
* int 整型 反应所用机器整数的最自然长度
* float 单精读浮点型
* double 双精读浮点型

此外基本数据类型前可以加限定符，例如short与long

```c
short int sh;
long int counter;
```

short与int类型至少为16位，而long类型至少为32位，并且short类型不长于int类型，而int类型不长于long类型

unsigned类型数总是正值或0，并且遵守算数模2^n定律，其中n是数的位数

有关这些类型长度定义的符号常量以及其他机器和编译器有关的属性可以在标准头文件``<limits.h>`` ``<float.h>`` 中找到。

#### 练习 2-1

> 编写一个程序以确定分别由signed及unsigned限定的char, short, int 与 long类类型变量的取值范围。采用打印标准头文件中的相应值以及直接
> 计算两种方式实现。后一种方法的实现困难一些，因为要确定各种浮点类型的取值范围。

```c
#include <limits.h>
#include <printf.h>

int main() {
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

### 2.3 常量

``long``类型的常量以字母``l``或``L``结尾。

无符号常量以字母``u``或``U``结尾。后缀``ul``或``UL``表明得失``unsigned long``类型。

没有后缀的浮点数常量为``double``类型。后缀``f``或``F``表示``float``类型，而后缀``l``或``L``则表示``long double``类型

带前缀``0``的整型常量表示它为八进制形式；前缀``0x``或``0X``表示它为十六进制形式。

八进制/十六进制的常量也可以使用后缀``L``表示``long``类型，``U``表示``unsigned``类型。

字符在机器字符集中的数值就是字符常量的值。字符常量一般用来与其他字符进行比较，但也可以像其他整数一样参与运算。

某些字符可以通过转义字符序列表示为字符和字符串常量。转移字符看起来像多个字符，但只表示一个字符。

可以通过八进制或者十六进制的方式书写转义字符序列

```c
#define VTAB '\013' /* 八进制ASCII纵向制表符 */
#define BELL '\007' /* 八进制ASCII响铃符 */
```

```c
#define VTAB '\x0b' /* 十六进制ASCII纵向制表符 */
#define BELL '\x07' /* 十六进制ASCII响铃符 */
```

ANSI C语言中的全部转义字符序列

| 转义字符     | 含义         |
|----------|------------|
| ``\a``   | 响铃符        |
| ``\b``   | 退格符        |
| ``\f``   | 换页符        |
| ``\n``   | 换行符        |
| ``\r``   | 回车符        |
| ``\t``   | 制表符        |
| ``\v``   | 垂直制表符      |
| ``\0``   | 空字符        |
| ``\xhh`` | 十六进制ASCII码 |
| ``\ooo`` | 八进制ASCII码  |
| ``\?``   | 字符集中的其他字符  |
| ``\nnn`` | 字符集中的其他字符  |
| ``\\``   | 反斜杠符       |
| ``\'``   | 单引号        |
| ``"``    | 双引号        |

``'\0'``表示值为0的字符，也就是空字符 (null)

常量表达式是仅仅包含常量的表达式。这种表达式在编译时求值，而不在运行时求值。

字符串常量也叫字符串字面值，例如

```c
"I am a string"
```

或

```c
"" /* 空字符串 */
```

双引号不是字符串的一部分，它只用于限定字符串。

从技术角度看，字符串常量就是字符数组。字符串的内部表示使用一个空字符'\0'作为串的结尾，因此，存储字符串的物理存储单元数比括在双引号中的字符数多一个。
这种表示方法也说明，C语言对字符串的长度没有限制，但程序必须扫描完整字符串后才能确定字符串的长度。标准库函数``strlen(s)``
可以返回字符串参数
s 的长度，但长度不包括末尾的``'/0'``.

*strlen函数*

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
```

标准头文件``<string.h>``中声明了strlen和其他字符串函数

枚举常量是另外一种类型的常量。枚举是一个常量整型值的列表

```c
enum boolean { NO, YES };
```

在没有显式说明的情况下，enum类型中第一个枚举名的值为0，第二个为1，以此推类。如果指定了部分枚举名的值，那么未指定值的枚举名的值将依着最后一个指定值向后递增

```c
enum escapes {
    BELL = '\a',
    BACKSPACE = '\b',
    TAB = '\t',
    NEWLINE = '\n',
    VTAB = '\v',
    RETURN = '\r'
};

/* FEB的值为2，MAR的值为3，依此推类 */
enum months {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};
```

不同枚举中的名字必须互不相同。同一枚举中不同的名字可以具有相同的值。

相对于``#define``语句来说，枚举的优势在于常量值可以自动生成。

尽管可以声明``enum``类型的变量，但编译器不检查这种类型的变量中存储的值是否为该枚举的有效值。

枚举变量提供上述的检查，因此枚举比``#define``更具优势。此外调试程序可以以符号形式打印出枚举变量的值。

### 2.4 声明

所有的变量必须先声明后使用。一个生命指定一种变量类型，后面所带的变量表可以包含一个或多个该类型的变量。

```c
int lower, upper, step;
char c, line[1000];
```

一个声明语句中的多个变量可以拆分在多个声明语句中声明。

```c
int lower;
int upper;
int step;
char c;
char line[1000];
```

这样的方式虽然占了多行，但更便于在各声明中添加注释，也便于以后修改。

在声明变量的同时可以进行初始化：

```c
char esc = '\\';
int i = 0;
int limit = MAXLINE + 1;
float eps = 1.0e-5;
```

当变量不是自动变量，只能进行一次初始化，在程序开始执行之前进行，初始化表达式必须为常量表达式。外部变量与静态变量会被初始化为0，未经显式初始化的自动变量的值为未定义值也就是无效值。

任何变量声明都可以使用``const``限定符限定。其代表变量的值不能被修改。对数组而言，代表数组所有元素的值不能被修改。

```c
const double e = 2.71828182845905;
const char msg[] = "warning:  ";
```

### 2.5 算数运算符

二元算数运算符包括: ``+ - * / %(取模运算符)``。整数除法会截去小数部分。

判断闰年:

```c
if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    printf("%d is a leap year\n", year);
else
    printf("%d is not a leap year\n", year);
```

取模运算符不能应用于 float 或 double 类型

### 2.6 关系运算符与逻辑运算符

关系运算符 ``> >= < <=``

关系运算符的优先级比算数运算符运算符低。

逻辑运算符 ``&& ||``，他们连接的表达式按从左到右的顺序进行求值，且在知道结果值为真或为假后立即停止运算。

运算符 ``&&`` 的优先级比 ``||`` 高，但两者都比关系运算符和相等性运算符的优先级低。

根据定义，在关系表达式或逻辑表达式中，如果关系为*真*，则表达式的结果值为数值*1*；如果为*假*，则结果值为数值*0*。

逻辑非 ``!`` 进行取反

#### 练习 2-2

> 在不使用运算符 ``&&`` 或 ``||`` 的条件下编写一个与下面 ``for`` 循环语句等价的循环语句。

```c
for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
```

题解：

```c
for (i = 0; i < lim - 1; i++) {
    if ((c = getchar()) != '\n') {
        if (c != EOF) {
            s[i] = c;
        }
    }
}
```

### 2.7 类型转换

自动转换是指把“比较窄的”操作数转换为“比较宽的”操作数，且不丢失信息的转换。

针对可能导致信息丢失的表达式，编译器会给出警告，但这些表达式并非非法。

#### atoi函数

[atoi_test.c](../ChapterTwo/atoi_test.c)

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

#### lower函数

[lower_test.c](../ChapterTwo/lower_test.c)

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

标准头文件 ``<ctype.h>`` 定义了一组与字符集无关的测试和转换函数。

C语言的定义保证了机器的标准打印字符集中的字符不会是负值，在表达式中这些字符总是正值。但，存储在字符变量中的位模式在某些机器中可能是负数，另一些则为正数。为了保证程序的可移植性，char 类型的变量中存储非字符数据，最好指定 signed 或 unsigned 限定符。

转换规则：

* 如果其中一个操作数类型为 long double，则将另一个操作数转换为 long double 类型；
* 如果其中一个操作数的类型为 double，则将另一个操作数转化为 double 类型；
* 如果其中一个操作数的类型为 float，则将另一个操作数转化为 float 类型；
* 将 char 与 short 类型的操作数转化为 int 类型；
* 如果其中一个操作数的类型为 long，则将另一个操作数也转换为 long 类型。

**float类型的操作数不回自动转换为double类型**, 一般数学计算使用双精度类型的变量，使用float类型主要是为了在使用较大的数组时节省存储空间，有时也为了节省机器执行时间（双精度算数运算特别费时）。

当表达式中包含了unsigned类型的操作数时，转换会变得复杂。原因在于带符号的运算会与机器相关，他们取决机器不同整数类型的大小。例如，假定int类型为16位，long为32位，那么，-1L<1U，这是因为unsigned int类型会被转换为signed long类型。但-1L>1UL，因为signed long会被转换为unsigned long类型。

赋值运算符右边的值需要转换为左边变量的类型，左边变量的类型即赋值表达式结果的类型。

无论是否进行符号扩展，字符型变量都将被转换为整形变量。

强制类型转换 ``(类型名)表达式``

#### rand与srand函数

[rand_test.c](../ChapterTwo/rand_test.c)

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

#### 练习2-3

> 编写函数htoi(s), 把由十六进制数字组成的字符串(包含可选的前缀0x或0X)转换为与之等价的整型值。
> 字符串中允许包含的数字包括: 0 ~ 9, a ~ f 以及 A ~ F。

```c
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int htoi(const char s[]) {
    unsigned long size = strlen(s);
    if (size == 2) {
        printf("%s 不是十六进制字符串", s);
        exit(0);
    }
    int sum = 0;
    int index = 0;
    for (int i = (int) size - 1; i >= 0; i--) {
        int dec = 0;
        if ((i == 0 && s[i] !='0') || (i == 1 && s[i] != 'x' && s[i] != 'X')) {
            printf("%s 不是十六进制字符串", s);
            exit(0);
        }  else if (i > 1) {
            if (!(s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'f' || s[i] >= 'A' && s[i] <= 'F')) {
                printf("%s 不是十六进制字符串", s);
                exit(0);
            }
            // 开始计算十六进制
            if (s[i] >= '0' && s[i] <= '9') {
                dec = s[i] - '0';
            } else {
                char c = (char) toupper(s[i]);
                switch (c) {
                    case 'A':
                        dec = 10;
                        break;
                    case 'B':
                        dec = 11;
                        break;
                    case 'C':
                        dec = 12;
                        break;
                    case 'D':
                        dec = 13;
                        break;
                    case 'E':
                        dec = 14;
                        break;
                    case 'F':
                        dec = 15;
                        break;
                    default:
                        // do nothing
                        break;
                }
            }
            sum += dec * (int) pow(16, index);
            index++;
        }
    }
    return sum;
}

int main() {
    char s[] = "0xFFFF";
    printf("%s转换为十进制为：%d", s, htoi(s));
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
void custom_strcat(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0') /* 判断是否为字符串 s 的尾部 */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* 拷贝 t */
        ;
}

int main() {
    char s[100];
    char t[] = "custom_strcat";
    custom_strcat(s, t);
    printf("%s", s);
}
```

#### 2.8 练习 2-4

```c
void _2_4(char s1[], const char s2[]) {
    int i, j, k;
    int instr;

    for (i = j = 0; s1[i] != '\0'; i++) {
        instr = 0;
        for (k = 0; s2[k] != '\0' && !instr; k++) {
            if (s2[k] == s1[i]) {
                instr = 1;
            }
        }

        if (!instr) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
```

#### 2.8 练习2-5

```c
int _2_5(const char s1[], const char s2[]) {
    int i;
    int j;
    int pos;

    pos = -1;

    for (i = 0; pos == -1 && s1[i] != '\0'; i++) {
        for (j = 0; pos == -1 && s2[j] != '\0'; j++) {
            if (s2[j] == s1[i]) {
                pos = i;
            }
        }
    }

    return pos;
}
```

#### 2.9 getbits 函数

```c
#include <stdio.h>

/* getbits函数: 返回x中从第p位开始的n位 */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

void printBinary(unsigned n, int len) {
    for (int i = len - 1; i != -1; i--)
        printf("%d", (n & (1 << i)) >> i );
    putc('\n', stdout);
}

int main() {
    printBinary(getbits(40, 4, 3), 3);
    return 0;
}
```