#include "sorting.h"

#include <memory.h>

void shell_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*))
{
    char *base_ptr = (char*) base;

    size_t gap = nitems / 2;
    for (; gap > 0; gap /= 2) {
        size_t i = gap;
        for (; i < nitems; ++i) {
            char *tmp = (base_ptr + (size * i));
            size_t j = i;
            while (j >= gap && comp((void*) (base_ptr + (size * (j - gap))), (void*) tmp) > 0) {
                memcpy((base_ptr + (size * j)), (base_ptr + (size * (j - gap))), size);
                j -= gap;
            }

            memcpy((base_ptr + (size * j)), tmp, size);
        }
    }
}