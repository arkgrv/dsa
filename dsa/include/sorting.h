#ifndef DSA_SORTING_H
#define DSA_SORTING_H

#include <stdint.h>
#include <stddef.h>

#define SWAP(a, b, size) \
    do {\
        size_t size_ = (size); \
        char *a_ = (char*)(a), *b_ = (char*)(b); \
        do { \
            char tmp_ = *a_; \
            *a_++ = *b_; \
            *b_++ = tmp_; \
        } while (--size_ > 0); \
    } while (0)

void bubble_sort(void *base, size_t nitems, size_t s, int (*comp)(const void*, const void*));

void insertion_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

void selection_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

void quick_sort(void *base, size_t nitems, size_t size, int left, int right, int (*comp)(const void*, const void*));

void merge_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

void shell_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

void heap_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

void comb_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

void counting_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

void bucket_sort(void *base, size_t nitems, size_t size, int b_count, int (*comp)(const void*, const void*));

void radix_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

#endif