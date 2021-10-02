#ifndef DSA_SORTING_H
#define DSA_SORTING_H

#include <vector>

void bubble_sort(std::vector<int>& vec);
void insertion_sort(std::vector<int>& vec);
void selection_sort(std::vector<int>& vec);
void quick_sort(std::vector<int>& vec, int left, int right);
void merge_sort(std::vector<int>& vec);
void shell_sort(std::vector<int>& vec);
void heap_sort(std::vector<int>& vec);
void comb_sort(std::vector<int>& vec);
void counting_sort(std::vector<int>& vec);
void bucket_sort(std::vector<int>& vec, int bucketsCount);
void radix_sort(std::vector<int>& vec);

#endif