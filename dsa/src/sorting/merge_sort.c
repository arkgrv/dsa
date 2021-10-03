#include "sorting.h"

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void merge(void *base, void *res, size_t size, size_t left, size_t middle, size_t right, int (*comp)(const void*, const void*))
{
    size_t i = left;
    size_t j = middle;
    size_t k;

    char *base_ptr = (char*) base;
    char *res_ptr = (char*) res;

    for (k = left; k < right; ++k) {
        if (i < middle && (j >= right || comp((void*) (base_ptr + (size * i)), (void*) (base_ptr + (size * j))) <= 0)) {
            SWAP((res_ptr + (size * k)), (base_ptr + (size * i)), size);
            ++i;
        } else {
            SWAP((res_ptr + (size * k)), (base_ptr + (size * j)), size);
            ++j;
        }
    }
}

void split(void *base, void *res, size_t size, size_t left, size_t right, int (*comp)(const void*, const void*))
{
    if (right - left <= 1)
        return;

    size_t middle = left + (right - left) / 2;
    split(res, base, size, left, right, comp);
    split(res, base, size, middle, right, comp);
    merge(res, base, size, left, middle, right, comp);
}

void merge_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*))
{
    void *res = malloc(nitems * size);
    if (res == NULL) {
        fprintf(stderr, "Error: unable to allocate memory buffer\n");
        return;
    }

    split(res, base, size, 0, nitems, comp);
    // copying result
    memcpy(base, res, size * nitems);
    free(res);
}