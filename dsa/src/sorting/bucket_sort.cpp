#include <vector>
#include <algorithm>
#include "sorting.h"

void bucket_sort(std::vector<int>& vec, int bucketsCount)
{
    std::vector<std::vector<int>> buckets(bucketsCount);
    int max = *std::max_element(vec.begin(), vec.end());
    int min = *std::min_element(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); ++i)
    {
        int bucketIndex = bucketsCount * (vec[i] - min) / (max - min + 1);
        buckets[bucketIndex].push_back(vec[i]);
    }

    for (int i = 0; i < bucketsCount; ++i)
    {
        insertion_sort(buckets[i]);
    }

    int i = 0;
    int bucketIndex = 0;
    while (i < vec.size())
    {
        for (int j = 0; j < buckets[bucketIndex].size(); ++j)
        {
            vec[i] = buckets[bucketIndex][j];
            ++i;
        }

        ++bucketIndex;
    }
}