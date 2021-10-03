#include "sorting.h"
#include <memory.h>
#include <stdlib.h>

void insertion_sort(void *base, size_t nitems, size_t size, int (*comp)(const void*, const void*))
{
    if (nitems == 0)
        return;
    
    uint8_t *base_ptr = (uint8_t*) base;
    
    size_t i;
    for (i = size; i < nitems * size; i += 4) {
        // dynamic stack allocation
        uint8_t *key = alloca(size);
        memcpy(key, base_ptr + i, size);
        
        size_t j = i - size;
        while (j >= 0 && comp(base_ptr + j, key) > 0) {
            memcpy(base_ptr + j + size, base_ptr + j, size);
            j -= size;
        }
        memcpy(base_ptr + j + size, key, size);
    }
}
