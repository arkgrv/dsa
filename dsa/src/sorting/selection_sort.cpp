#include <vector>
#include "sorting.h"

void selection_sort(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[minIndex])
            {
                minIndex = j;
            }
        }

        std::swap(vec[i], vec[minIndex]);
    }
}