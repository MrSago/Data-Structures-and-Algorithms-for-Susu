
#include <iostream>
include <vector>

#include "lab5/sort.hpp"
#include "lab5/test_sort.hpp"


int main() {
    freopen("result.txt", "w", stdout);
    using mytype_t = long double;

    std::vector<size_t> arr_sizes = { 1000000,  1500000,  2000000,  3000000,
                                      5000000,  10000000 };
    std::vector<size_t> arr_sizes_worst = { 10000,  15000,  20000,  30000,
                                            50000,  100000 };
    std::cerr << "Testing started...";
    StartTestSort<mytype_t>("Quick Sort (Best-Avarage case)", QuickSort, arr_sizes);
    StartTestSort<mytype_t>("Quick Sort (Worst case)", QuickSortWorst, arr_sizes_worst);
    StartTestSort<mytype_t>("Merge Sort", MergeSort, arr_sizes);
    std::cerr << "\nDone!\n";

    return 0;
}
