//
// 编写C程序 练习2-3  编写函数htoi(s)，把由十六进制数组组成的字符串（包含可选的前缀“0x”或“0X”）
// 转换为与之等价的整型值。字符串中允许包含的数字包括：0～9、a～f以及A~F
// Created by Ahoge Knight on 2022/10/13.
//

#include <string.h>
#include <stdio.h>
#include <limits.h>

#define HEX_ERROR UINT_MAX

unsigned int htoi(const char s[])
{
    size_t size = strlen(s);
    if (size < 1)
    {
        printf("%s 不是有效的十六进制字符串\n", s);
        return HEX_ERROR;
    }

    unsigned int sum = 0;
    int start = 0;

    // 检查前缀
    if (size > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        start = 2;
    }

    for (int i = start; s[i] != '\0'; i++)
    {
        unsigned int dec;
        if (s[i] >= '0' && s[i] <= '9')
        {
            dec = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            dec = s[i] - 'a' + 10;
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            dec = s[i] - 'A' + 10;
        }
        else
        {
            printf("%s 包含无效的十六进制字符\n", s);
            return HEX_ERROR;
        }

        // 检查溢出
        if (sum > (UINT_MAX - dec) / 16)
        {
            printf("转换结果溢出\n");
            return HEX_ERROR;
        }

        sum = sum << 4 | dec;
    }

    return sum;
}

int main()
{
    char s1[] = "0x3FAE";
    char s2[] = "3FAE";
    char s3[] = "0xG123"; // 无效输入
    char s4[] = "0xFFFFFFFF"; // 最大32位无符号整数

    printf("%s 转换为十进制为：%u\n", s1, htoi(s1));
    printf("%s 转换为十进制为：%u\n", s2, htoi(s2));
    printf("%s 转换为十进制为：%u\n", s3, htoi(s3));
    printf("%s 转换为十进制为：%u\n", s4, htoi(s4));

    return 0;
}
