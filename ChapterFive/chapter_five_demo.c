//
// Created by Ahoge Knight on 2023/2/8.
//

#include <stdio.h>

void pointer() {
    int var = 10;
    int *ptr;
    ptr = &var;

    printf("var: %d\n", var);
    printf("ptr: %p\n", ptr);
    printf("*ptr: %d\n", *ptr);

    *ptr = 20;
    printf("change 20 ptr: %p\n", ptr);
    printf("change 20 *ptr: %d\n", *ptr);

    int v[] = {100, 200, 300};
    int *vPtr;
    vPtr = v;
    // 上两行的操作相当于 ``int *vPtr = &v[i]``
    // vPtr same can use vPtr[0] vPtr[1] vPtr[2]
    for (int i = 0; i < 3; i++) {
        printf("Pointer saved address vPtr: %p\n", vPtr);
        printf("Pointer *vPtr: %d\n", *vPtr);
        vPtr++;
    }

    // void pointer
    void const *voidPointer = NULL;
    printf("The size of voidPointer: %lu\n", sizeof(voidPointer));

    // null pointer
    int const *nullPointer = NULL;
    printf("This is NULL pointer: %x\n", nullPointer);

    // wild pointer (野指针)
    // int *wildPointer;
    // will segmentation fault
    // printf("%d\n", *wildPointer);
}

int main() {
    pointer();
}