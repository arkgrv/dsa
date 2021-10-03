#include "sorting.h"

void heapify(void *base, size_t nitems, size_t size, size_t root_idx, int (*comp)(const void*, const void*))
{
    size_t l_idx = root_idx;
    size_t left_idx = root_idx * 2 + 1;
    size_t right_idx = root_idx * 2 + 2;

    char *base_ptr = (char*) base;

    if (left_idx < nitems && comp((void*) (base_ptr + (size * left_idx)), (void*) (base_ptr + (size * l_idx))) > 0)
        l_idx = left_idx;

    if (right_idx < nitems && comp((void*) (base_ptr + (size * right_idx)), (void*) (base_ptr + (size * l_idx))) > 0)
        l_idx = right_idx;

    if (l_idx != root_idx) {
        SWAP((base_ptr + (size * root_idx)), (base_ptr + (size * l_idx)), size);
        heapify(base, nitems, size, l_idx, comp);
    }
}

void heap_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*))
{
    char *base_ptr = (char*) base;

    size_t i;
    for (i = nitems / 2 - 1; i >= 0; --i)
        heapify(base, nitems, size, i, comp);
    
    for (i = nitems / - 1; i > 0; --i) {
        SWAP(base_ptr, (base_ptr + (size * i)), size);
        heapify(base, i, size, 0, comp);
    }
}