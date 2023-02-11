//
// Created by Ahoge Knight on 2023/2/8.
//

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int *larger(int *, int *);

int sum(int x, int y);

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

void mallocDemo() {
    // This pointer will hold the base address of the block created
    int *ptr;
    int n, i;

    // Get the number of elements for the array;
    printf("Enter number of elements:");
    // scanf("%d", &n);
    n = 10;
    printf("Entered number of elements: %d\n", n);

    // Dynamically allocate memory using malloc()
    ptr = (int *) malloc(n * sizeof(int));

    // Check if the memory has been successfully allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
        // Memory has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }
    free(ptr);
}

void callocDemo() {
    // This pointer will hold the
    // base address of the block created
    int *ptr;
    int n, i;

    // Get the number of elements for the array
    n = 5;
    printf("Enter number of elements: %d\n", n);

    // Dynamically allocate memory using calloc()
    ptr = (int *) calloc(n, sizeof(int));

    // Check if the memory has been successfully
    // allocated by calloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {

        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }
    }
    free(ptr);
}

void reallocDemo() {
    // This pointer will hold the
    // base address of the block created
    int *ptr;
    int n, i;

    // Get the number of elements for the array
    n = 5;
    printf("Enter number of elements: %d\n", n);

    // Dynamically allocate memory using calloc()
    ptr = (int *) calloc(n, sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {

        // Memory has been successfully allocated
        printf("Memory successfully allocated using calloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }

        // Get the new size for the array
        n = 10;
        printf("\n\nEnter the new size of the array: %d\n", n);

        // Dynamically re-allocate memory using realloc()
        ptr = realloc(ptr, n * sizeof(int));

        // Memory has been successfully allocated
        printf("Memory successfully re-allocated using realloc.\n");

        // Get the new elements of the array
        for (i = 5; i < n; ++i) {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }

        free(ptr);
    }
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

    // Functions returning Pointer Variables
    int a = 15;
    int b = 92;
    int const *p;
    p = larger(&a, &b);
    printf("\n\n%d is larger\n", *p);

    // Pointer to Function
    int (*fp)(int, int);
    fp = sum;
    int s = fp(10, 15);
    printf("\nSum is %d\n", s);

    // Pointer and Array

    // Array declaration and initialization
    int arr[5] = {3, 5, 7, 9, 11};
    // printing the addresses and values represented by arr, &arr and &arr[0]
    printf("\n\narr : %p, Value : %d\n", arr, *arr);
    printf("&arr : %p, Value : %d\n", &arr, *(arr));
    printf("&arr[0] : %p, Value : %d\n", &arr[0], *(&arr[0]));

    for (int i = 0; i < 5; i++) {
        // printing the elements address and value at
        // arr[i] using *(arr + i) syntax
        printf("[index %d] Address : %p, Value : %d\n", i, (arr + i), *(arr + i));
    }
    // both `arr` and `&arr` return the address of the first element of the array.
    int *ptr = arr;
    // printing the elements of array using addition arithmetic on pointer
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n\n\n");

    // Dynamic Memory Allocation in C using malloc(), calloc(), free() and realloc()
    mallocDemo();
    callocDemo();
    reallocDemo();
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

int *larger(int *x, int *y) {
    if (*x > *y) {
        return x;
    } else {
        return y;
    }
}

int sum(int x, int y) {
    return x + y;
}