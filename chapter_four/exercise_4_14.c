//
// Created by AhogeK on 10/23/24.
//

#include <stdio.h>

// 定义 swap 宏
#define swap(t, x, y) do { \
            t temp = (x); \
            (x) = (y); \
            (y) = temp; \
        } while(0)

int main()
{
    // 测试整数交换
    int a = 5, b = 10;
    printf("交换前: a = %d, b = %d\n", a, b);
    swap(int, a, b);
    printf("交换后: a = %d, b = %d\n\n", a, b);

    // 测试浮点数交换
    double c = 3.14, d = 2.718;
    printf("交换前: c = %f, d = %f\n", c, d);
    swap(double, c, d);
    printf("交换后: c = %f, d = %f\n\n", c, d);

    // 测试字符交换
    char e = 'X', f = 'Y';
    printf("交换前: e = %c, f = %c\n", e, f);
    swap(char, e, f);
    printf("交换后: e = %c, f = %c\n", e, f);

    return 0;
}
