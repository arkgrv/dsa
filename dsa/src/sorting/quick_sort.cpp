#include <vector>
#include <iostream>
#include "sorting.h"

int partition(std::vector<int>& vec, int left, int right)
{
    int middle = left + (right - left) / 2;
    int pivot = vec[middle];

    int i = left - 1;
    int j = right + 1;

    while (true)
    {
        do
        {
            ++i;
        } while (vec[i] < pivot);

        do
        {
            --j;
        } while (vec[j] > pivot);

        if (i >= j)
        {
            return j;
        }

        std::swap(vec[i], vec[j]);
    }
}

void quick_sort(std::vector<int>& vec, int left, int right)
{
    if (left >= 0 && right >= 0)
    {
        if (left < right)
        {
            int index = partition(vec, left, right);
            quick_sort(vec, left, index);
            quick_sort(vec, index + 1, right);
        }
    }
}