#include <vector>
#include <algorithm>
#include "sorting.h"

void counting_sort(std::vector<int>& vec)
{
    int max = *std::max_element(vec.begin(), vec.end());
    int min = *std::min_element(vec.begin(), vec.end());
    int range = max - min + 1;

    std::vector<int> count(range);
    // For stable sort
    std::vector<int> output(vec.size());
    for (int i = 0; i < vec.size(); ++i)
    {
        ++count[vec[i] - min];
    }

    for (int i = 1; i < count.size(); ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = vec.size() - 1; i >= 0; --i)
    {
        int countIndex = vec[i] - min;
        int newIndex = count[countIndex] - 1;

        output[newIndex] = vec[i];
        --count[countIndex];
    }

    vec = output;
}