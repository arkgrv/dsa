#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "sorting.h"

#define SIZE 20

int compare_ints(const void *a, const void *b)
{
    int f = *(const int *) a;
    int s = *(const int *) b;
    if (f > s) return 1;
    if (f < s) return -1;
    return 0;
}

void randomize(int *a, size_t size)
{
    size_t i;
    for (i = 0; i < size; ++i)
        a[i] = rand() % 90 + 10;
}

void print(int *a, size_t size)
{
    size_t i;
    for (i = 0; i < size; ++i)
        printf("%d ", a[i]);

    printf("\n");
}

int main(int argc, char** argv)
{
    srand(time(NULL));
    int array[SIZE], to_sort[SIZE];

    // Randomizing
    printf("Bubble sort: \n");
    randomize(array, SIZE);
    print(array, SIZE);

    memcpy(to_sort, array, sizeof(int) * SIZE);
    bubble_sort(to_sort, SIZE, sizeof(int), compare_ints);
    print(to_sort, SIZE);
    
    printf("\n");

    printf("Insertion sort: \n");
    memcpy(to_sort, array, sizeof(int) * SIZE);
    print(to_sort, SIZE);

    insertion_sort(to_sort, SIZE, sizeof(int), compare_ints);
    print(to_sort, SIZE);

    printf("\n");

    printf("Selection sort: \n");
    memcpy(to_sort, array, sizeof(int) * SIZE);
    print(to_sort, SIZE);

    selection_sort(to_sort, SIZE, sizeof(int), compare_ints);
    print(to_sort, SIZE);

    printf("\n");

//    printf("Shell sort: \n");
//    memcpy(to_sort, array, sizeof(int) * SIZE);
//    print(to_sort, SIZE);
//
//    shell_sort(to_sort, SIZE, sizeof(int), compare_ints);
//    print(to_sort, SIZE);
//
//    printf("\n");
//
//    printf("Comb sort: \n");
//    memcpy(to_sort, array, sizeof(int) * SIZE);
//    print(to_sort, SIZE);
//
//    comb_sort(to_sort, SIZE, sizeof(int), compare_ints);
//    print(to_sort, SIZE);
//
//    printf("\n");
//
//    printf("Quick sort: \n");
//    memcpy(to_sort, array, sizeof(int) * SIZE);
//    print(to_sort, SIZE);
//
//    quick_sort(to_sort, SIZE, sizeof(int), 0, SIZE - 1, compare_ints);
//    print(to_sort, SIZE);
//
//    printf("\n");
//
//    printf("Merge sort: \n");
//    memcpy(to_sort, array, sizeof(int) * SIZE);
//    print(to_sort, SIZE);
//
//    heap_sort(to_sort, SIZE, sizeof(int), compare_ints);
//    print(to_sort, SIZE);

    printf("\n");

    getchar();

    return 0;
}
