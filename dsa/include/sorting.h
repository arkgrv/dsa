#ifndef DSA_SORTING_H
#define DSA_SORTING_H

#include <stdint.h>
#include <stddef.h>

#define SWAP(a, b, size) { \
    uint8_t *a_ptr = (uint8_t*)(a); \
    uint8_t *b_ptr = (uint8_t*)(b); \
    uint8_t tmp; \
    size_t i; \
    for (i = 0; i < (size); ++i) { \
        tmp = *a_ptr; \
        *a_ptr++ = *b_ptr; \
        *b_ptr++ = tmp; \
    } \
}

void bubble_sort(void *base, size_t nitems, size_t s, int (*comp)(const void*, const void*));

void insertion_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

void selection_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

void quick_sort(void *base, size_t nitems, size_t size, size_t left, size_t right, int (*comp)(const void*, const void*));

void merge_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

void shell_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

void heap_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

void comb_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*));

#endif
