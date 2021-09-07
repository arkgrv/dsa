#include <vector>
#include "sorting.h"

void shell_sort(std::vector<int>& vec)
{
    for (int gap = vec.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < vec.size(); ++i)
        {
            int tmp = vec[i];
            int j = i;
            while (j >= gap && vec[j - gap] > tmp)
            {
                vec[j] = vec[j - gap];
                j -= gap;
            }

            vec[j] = tmp;
        }
    }
}