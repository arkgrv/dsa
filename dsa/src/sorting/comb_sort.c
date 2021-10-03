#include "sorting.h"

size_t get_next_gap(size_t gap, size_t size)
{
    gap = (gap * size * 10) / 13;

    if (gap < size)
        return size;
    return gap;
}

void comb_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*))
{
    size_t gap = nitems;
    int swapped = 1;

    char *base_ptr = (char*) base;

    while (swapped) {
        gap = get_next_gap(gap, size);
        swapped = 0;

        size_t i;
        for (i = 0; i < nitems * size - gap; i += size) {
            if (comp(base_ptr + i, base_ptr + (i + gap)) > 0) {
                SWAP(base_ptr + i, base_ptr + (i + gap), size);
                swapped = 1;
            }
        }
    }
}
