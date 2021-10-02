#include "sorting.h"

#include <string.h>
#include <memory.h>

void insertion_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*))
{
    if (nitems == 0)
        return;

    char *base_ptr = (char*) base;

    size_t i;
    for (i = 1; i < nitems; ++i) {
        char *key = (base_ptr + (size * i));
        size_t j = i - 1;
        char *cur = (base_ptr + (size * j));

        while (j >= 0 && comp((void*) cur, (void*) key) > 0) {
            char *next = (base_ptr + (size * (j + 1)));
            memcpy(next, cur, size);
            --j;
            cur = (base_ptr + (size * j));
        }

        memcpy((base_ptr + (size * (j + 1))), key, size);
    }
}