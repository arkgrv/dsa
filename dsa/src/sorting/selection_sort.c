#include "sorting.h"

void selection_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*))
{
    if (nitems == 0)
        return;

    char *base_ptr = (char*) base;

    size_t i;
    for (i = 0; i < nitems - 1; ++i) {
        size_t min_idx = i;
        size_t j;
        for (j = i + 1; j < nitems; ++j) {
            char *pos = (base_ptr + (size * j));
            char *pos_min = (base_ptr + (size * min_idx));
            if (comp(pos, pos_min) < 0)
                min_idx = j;
        }

        SWAP((base_ptr + (size * i)), (base_ptr + (size * min_idx)), size);
    }
}