#include "sorting.h"
#include <stdint.h>

void bubble_sort(void *base, size_t nitems, size_t s, int (*comp)(const void*, const void*))
{
    if (nitems == 0)
        return;
        
    // base as char*
    uint8_t *base_ptr = (uint8_t*) base;

    size_t i, j;
    for (i = 0; i < nitems; ++i) {
        for (j = 0; j < nitems - i - 1; ++j) {
            uint8_t *pos = base_ptr + (s * j);
            uint8_t *pos_next = base_ptr + (s * (j + 1));
            
            if (comp(pos, pos_next) > 0)
                SWAP(pos, pos_next, s);
        }
    }
}
