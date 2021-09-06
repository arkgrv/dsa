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

    randomize(vec);
    print(vec);

    bubble_sort(vec);
    print(vec);

    std::cout << "\n";

    randomize(vec);
    print(vec);

    insertion_sort(vec);
    print(vec);

    std::cout << "\n";

    randomize(vec);
    print(vec);

    selection_sort(vec);
    print(vec);

    std::cout << "\n";

    randomize(vec);
    print(vec);

    quick_sort(vec, 0, vec.size() - 1);
    print(vec);

    int a = 0;
    std::cin >> a;
}