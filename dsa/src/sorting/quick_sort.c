#include "sorting.h"

size_t partition(void *base, size_t left, size_t right, size_t size, int (*comp)(const void*, const void*))
{
    size_t middle = left + (right - left) / 2;
    char *base_ptr = (char*) base;

    char *pivot = (base_ptr + (size * middle));

    size_t i = left - 1;
    size_t j = right + 1;

    while (1) {
        do {
            ++i;
        } while (comp((void*) (base_ptr + (size * i)), (void*) pivot) < 0);

        do {
            --j;
        } while (comp((void*) (base_ptr + (size * j)), (void*) pivot) > 0);

        if (i >= j)
            return j;

        SWAP((base_ptr + (size + i)), (base_ptr + (size * j)), size);
    }
}

void quick_sort(void *base, size_t nitems, size_t size, size_t left, size_t right, int (*comp)(const void*, const void*))
{
    if (left >= 0 && right >= 0) {
        if (left < right) {
            size_t idx = partition(base, left, right, size, comp);
            quick_sort(base, nitems, size, left, right, comp);
            quick_sort(base, nitems, size, idx + 1, right, comp);
        }
    }
}