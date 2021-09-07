#include <vector>
#include <algorithm>
#include "sorting.h"

void radix_counting_sort(std::vector<int>& vec, int exp)
{
    int max = *std::max_element(vec.begin(), vec.end());
    int min = *std::min_element(vec.begin(), vec.end());

    std::vector<int> count(10);
    // For stable sort
    std::vector<int> output(vec.size());
    for (int i = 0; i < vec.size(); ++i)
    {
        ++count[(vec[i] / exp) % 10];
    }

    for (int i = 1; i < count.size(); ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = vec.size() - 1; i >= 0; --i)
    {
        int countIndex = (vec[i] / exp) % 10;
        int newIndex = count[countIndex] - 1;

        output[newIndex] = vec[i];
        --count[countIndex];
    }

    vec = output;
}

void radix_sort(std::vector<int>& vec)
{
    int max = *std::max_element(vec.begin(), vec.end());

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        radix_counting_sort(vec, exp);
    }
}