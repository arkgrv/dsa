#include <vector>
#include "sorting.h"

void merge(std::vector<int>& vec, std::vector<int>& res, int left, int middle, int right)
{
    int i = left;
    int j = middle;
    for (int k = left; k < right; ++k)
    {
        if (i < middle && (j >= right || vec[i] <= vec[j]))
        {
            res[k] = vec[i];
            ++i;
        }
        else
        {
            res[k] = vec[j];
            ++j;
        }
    }
}

void split(std::vector<int>& vec, std::vector<int>& res, int left, int right)
{
    if (right - left <= 1)
    {
        return;
    }

    int middle = left + (right - left) / 2;
    split(res, vec, left, middle);
    split(res, vec, middle, right);
    merge(res, vec, left, middle, right);
}

void merge_sort(std::vector<int>& vec)
{
    std::vector<int> res(vec);
    split(res, vec, 0, vec.size());
    vec = res;
}