//
// Created by Ahoge Knight on 2023/2/8.
//

#include <stdio.h>

void swap(int *a, int *b);

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

    // Pointers as Function Argument in C
    int m = 10;
    int n = 20;
    printf("\n\nm = %d\n", m);
    printf("n = %d\n", n);
    // passing address of m and n to the swap function
    swap(&m, &n);
    printf("After Swapping: \n\n");
    printf("m = %d\n", m);
    printf("n = %d\n", n);
    return 0;
}

/**
 * pointer 'a' and pointer 'b' holds and points to  the address of 'm' and 'n'
 *
 * @param a to swap b
 * @param b  to swap a
 */
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}