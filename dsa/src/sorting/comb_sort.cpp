#include <vector>
#include "sorting.h"

int get_next_gap(int gap)
{
    gap = (gap * 10) / 13;

    if (gap < 1)
    {
        return 1;
    }
    return gap;
}

void comb_sort(std::vector<int>& vec)
{
    int gap = vec.size();
    bool swapped = true;

    while (swapped)
    {
        gap = get_next_gap(gap);
        swapped = false;

        for (int i = 0; i < vec.size() - gap; ++i)
        {
            if (vec[i] > vec[i + gap])
            {
                std::swap(vec[i], vec[i + gap]);
                swapped = true;
            }
        }
    }
}