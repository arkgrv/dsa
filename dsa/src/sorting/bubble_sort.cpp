#include <vector>
#include "sorting.h"

void bubble_sort(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        for (int j = 0; j < vec.size() - i - 1; ++j)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}