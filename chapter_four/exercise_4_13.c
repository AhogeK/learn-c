//
// Created by AhogeK on 10/23/24.
//

#include <stdio.h>
#include <string.h>

// 递归函数：反转字符串的子函数
void reverse_recursive(char s[], int left, int right)
{
    if (left >= right)
    {
        return; // 递归终止条件：当左右索引相遇或交错时
    }

    // 交换左右两端的字符
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    // 递归反转子字符串
    reverse_recursive(s, left + 1, right - 1);
}

// 包装函数：提供更简单的接口
void reverse(char s[])
{
    int len = strlen(s); // 获取字符串长度
    if (len > 0)
    {
        reverse_recursive(s, 0, len - 1); // 调用递归反转函数
    }
}

int main()
{
    char str1[] = "Hello, World!";
    reverse(str1);
    printf("反转后的字符串: %s\n", str1);

    char str2[] = "abcd";
    reverse(str2);
    printf("反转后的字符串: %s\n", str2);

    char str3[] = "12345";
    reverse(str3);
    printf("反转后的字符串: %s\n", str3);

    return 0;
}
