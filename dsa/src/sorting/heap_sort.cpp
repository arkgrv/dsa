#include <vector>
#include "sorting.h"

void heapify(std::vector<int>& vec, int n, int rootIndex)
{
    int largestIndex = rootIndex;
    int leftIndex = rootIndex * 2 + 1;
    int rightIndex = rootIndex * 2 + 2;

    if (leftIndex < n && vec[leftIndex] > vec[largestIndex])
    {
        largestIndex = leftIndex;
    }

    if (rightIndex < n && vec[rightIndex] > vec[largestIndex])
    {
        largestIndex = rightIndex;
    }

    if (largestIndex != rootIndex)
    {
        std::swap(vec[rootIndex], vec[largestIndex]);
        heapify(vec, n, largestIndex);
    }
}

void heap_sort(std::vector<int>& vec)
{
    for (int i = vec.size() / 2 - 1; i >= 0; --i)
    {
        heapify(vec, vec.size(), i);
    }

    for (int i = vec.size() - 1; i > 0; --i)
    {
        std::swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}