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
