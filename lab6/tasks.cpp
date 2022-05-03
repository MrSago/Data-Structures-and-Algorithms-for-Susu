
#include "lab6/tasks.hpp"

#include <set>
#include <vector>

#include "tools/other.hpp"
#include "tools/gen_vector.hpp"

template<typename T>
size_t BinSearch(T* arr, size_t sz, T number) {
    size_t l = 0, r = sz;
    while (l < r - 1) {
        size_t mid = (l + r) >> 1;
        if (number < arr[mid]) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return arr[r - 1] == number ? r - 1 : UINT64_MAX;
}

template<typename T>
std::set<size_t> SearchIndexes(T* arr, T number, size_t index) {
    std::set<size_t> indexes;
    indexes.insert(index);

    size_t l = index - 1, r = index + 1;
    while (arr[l] == number) indexes.insert(l--);
    while (arr[r] == number) indexes.insert(r++);

    return indexes;
}

void FirstTask() {
    std::cout << "Enter array size: ";
    size_t N = ReadNumber<size_t>();

    std::vector<int> arr = RandomVectorInt<int>(N);
    std::cout << "Random array: ";
    PrintVector(arr);
    std::cout << '\n';

    std::sort(arr.begin(), arr.end());
    std::cout << "Sorted array: ";
    PrintVector(arr);
    std::cout << '\n';

    std::cout << "Enter number for search: ";
    int search = ReadNumber<int>();

    size_t ix = BinSearch<int>(arr.data(), arr.size(), search);
    if (ix == UINT64_MAX) {
        std::cout << "Number not found\n";
        return;
    }

    std::set<size_t> indexes = SearchIndexes<int>(arr.data(), search, ix);
    std::cout << "Counts: " << indexes.size() << '\n';
    std::cout << "Indexes: ";
    for (auto& it : indexes) {
        std::cout << it << ' ';
    }
    std::cout << '\n';
}

void SecondTask() {
    
}

void ThirdTask() {
    
}
