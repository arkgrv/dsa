#include "sorting.h"

void bubble_sort(void *base, size_t nitems, size_t s, int (*comp)(const void*, const void*))
{
    if (nitems == 0)
        return;
        
    // base as char*
    char *base_ptr = (char*) base;

    size_t i, j;
    for (i = 0; i < nitems; ++i) {
        for (j = 0; j < nitems - i - 1; ++j) {
            char *pos = (base_ptr + (s * j));
            char *pos_next = (base_ptr + (s * (j + 1)));
            if (comp((void*) pos, (void*) pos_next) > 0)
                SWAP((void*) pos, (void*) pos_next, s);
        }
    }
}