//
// Created by AhogeK on 10/25/24.
//

#include <stdio.h>

struct aligned
{
    char c;
    int i;
    char c2;
};

#pragma pack(1)
struct packed
{
    char c;
    int i;
    char c2;
};
#pragma pack()

int main()
{
    printf("默认对齐的结构大小: %zu\n", sizeof(struct aligned));
    printf("紧凑布局的结构大小: %zu\n", sizeof(struct packed));

    return 0;
}
