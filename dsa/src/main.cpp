#include <iostream>
#include <vector>

#include "sorting.h"

void randomize(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = rand() % 90 + 10;
    }
}

void print(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }

    std::cout << "\n";
}

int main()
{
    srand(time(nullptr));

    int n = 20;
    std::vector<int> vec(n);

    std::cout << "Bubble Sort:\n";
    randomize(vec);
    print(vec);
    
    bubble_sort(vec);
    print(vec);

    std::cout << "\n";

    std::cout << "Insertion Sort:\n";
    randomize(vec);
    print(vec);
    
    insertion_sort(vec);
    print(vec);

    std::cout << "\n";

    std::cout << "Selection Sort:\n";
    randomize(vec);
    print(vec);
    
    selection_sort(vec);
    print(vec);

    std::cout << "\n";

    std::cout << "Shell Sort:\n";
    randomize(vec);
    print(vec);

    shell_sort(vec);
    print(vec);

    std::cout << "\n";

    std::cout << "Comb Sort:\n";
    randomize(vec);
    print(vec);

    comb_sort(vec);
    print(vec);

    std::cout << "\n";

    std::cout << "Quick Sort:\n";
    randomize(vec);
    print(vec);
    
    quick_sort(vec, 0, vec.size() - 1);
    print(vec);

    std::cout << "\n";

    std::cout << "Merge Sort:\n";
    randomize(vec);
    print(vec);
    
    merge_sort(vec);
    print(vec);

    std::cout << "\n";

    std::cout << "Heap Sort:\n";
    randomize(vec);
    print(vec);
    
    heap_sort(vec);
    print(vec);

    std::cout << "\n";

    std::cout << "Counting Sort:\n";
    randomize(vec);
    print(vec);
    
    counting_sort(vec);
    print(vec);

    std::cout << "\n";

    std::cout << "Bucket Sort:\n";
    randomize(vec);
    print(vec);
    
    bucket_sort(vec, 10);
    print(vec);

    std::cout << "\n";

    std::cout << "Radix Sort:\n";
    randomize(vec);
    print(vec);

    radix_sort(vec);
    print(vec);

    int a = 0;
    std::cin >> a;
}