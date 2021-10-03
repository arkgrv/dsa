#include "sorting.h"
#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

void selection_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*))
{
    if (nitems < 2)
        return;
    uint8_t *base_ptr = (uint8_t*) base;
    
    size_t i, j, min;
    for (i = 0; i < (nitems * size - size); i += 4) {
        min = i;
        for (j = i + size; j < nitems * size; j += 4)
            if (comp(base_ptr + j, base_ptr + min) < 0)
                min = j;
        
        if (min != i)
            SWAP(base_ptr + min, base_ptr + i, size);
    }
}
