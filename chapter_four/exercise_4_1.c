//
// Created by AhogeK on 10/20/24.
//

#include <stdio.h>
#include <string.h>

// 函数声明
int strrindex(const char* s, const char* t);

int main()
{
    const char* s = "this is a test string, testing string functions";
    const char* t = "string";
    int position = strrindex(s, t);

    if (position != -1)
    {
        printf("The last occurrence of '%s' in '%s' is at index %d.\n", t, s, position);
    }
    else
    {
        printf("The string '%s' is not found in '%s'.\n", t, s);
    }

    return 0;
}

// 函数定义
int strrindex(const char* s, const char* t)
{
    int i, j, k;
    int last_position = -1;
    int len_s = strlen(s);
    int len_t = strlen(t);

    // 从字符串 s 的开头开始扫描
    for (i = 0; i <= len_s - len_t; i++)
    {
        // 检查从位置 i 开始的子字符串是否与 t 匹配
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);

        // 如果匹配成功，记录位置
        if (k > 0 && t[k] == '\0')
        {
            last_position = i;
        }
    }

    return last_position;
}
