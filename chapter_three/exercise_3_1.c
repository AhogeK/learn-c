//
// 练习3-1 在上面有关折半查找的例子中，while循环语句内共执行了两次测试，
// 其实只要一次就足够了（代价是将更多的测试在循环外执行）。
// 重写该函数，使得在循环内部只执行一次测试。比较两种版本的函数的运行时间。
// Created by AhogeK on 10/17/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 1000000
#define SEARCHES 1000000

int original_binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int optimized_binsearch(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return v[low] == x ? low : -1;
}

// 生成有序数组
void generate_sorted_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i * 2; // 生成偶数序列
    }
}

// 测试函数
void test_search(int (*search_func)(int, int [], int), const char* func_name, int arr[], int n)
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int i = 0; i < SEARCHES; i++)
    {
        int x = rand() % (2 * MAX_ELEMENTS); // 随机搜索值
        search_func(x, arr, n);
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%s took %f seconds\n", func_name, cpu_time_used);
}


int main()
{
    srand(time(NULL)); // 初始化随机数生成器
    int arr[MAX_ELEMENTS];
    generate_sorted_array(arr, MAX_ELEMENTS);

    printf("Running %d searches on an array of %d elements\n", SEARCHES, MAX_ELEMENTS);

    test_search(original_binsearch, "Original binary search", arr, MAX_ELEMENTS);
    test_search(optimized_binsearch, "Optimized binary search", arr, MAX_ELEMENTS);

    return 0;
}
