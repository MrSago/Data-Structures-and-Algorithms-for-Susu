
#ifndef _SORT_HPP
#define _SORT_HPP

#include <chrono>
#include <cstring>
#include <algorithm>

template<typename T>
int __partition(T* arr, size_t low, size_t high) {
    T pi = arr[(low + high) / 2];
    for (size_t i = low, j = high; ; ++i, --j) {
        while (arr[i] < pi) {
            ++i;
        }
        while (arr[j] > pi) {
            --j;
        }
        if (i >= j) {
            return j;
        }
        T tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    throw std::runtime_error("Search partition error");
}

template<typename T>
void __rec_qs(T* arr, size_t low, size_t high) {
    while (low < high) {
        size_t p = __partition(arr, low, high);
        if (p - low < high - p) {
            __rec_qs(arr, low, p);
            low = p + 1;
        } else {
            __rec_qs(arr, p + 1, high);
            high = p;
        }
    }
}

template<typename T>
int __partition_worst(T* arr, size_t low, size_t high) {
    T pi = arr[high - 1];
    for (size_t i = low, j = high; ; ++i, --j) {
        while (arr[i] < pi) {
            ++i;
        }
        while (arr[j] > pi) {
            --j;
        }
        if (i >= j) {
            return j;
        }
        T tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    throw std::runtime_error("Search partition error");
}

template<typename T>
void __rec_qs_worst(T* arr, size_t low, size_t high) {
    while (low < high) {
        size_t p = __partition_worst(arr, low, high);
        if (p - low < high - p) {
            __rec_qs_worst(arr, low, p);
            low = p + 1;
        } else {
            __rec_qs_worst(arr, p + 1, high);
            high = p;
        }
    }
}

template<typename T>
bool CheckSort(T* arr, size_t sz) {
    for (size_t i = 1; i < sz; ++i) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

template<typename T>
long long QuickSort(T* arr, size_t sz) {
    auto start = std::chrono::high_resolution_clock::now();
    __rec_qs(arr, 0, sz - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    return (stop - start).count();
}

template<typename T>
long long QuickSortWorst(T* arr, size_t sz) {
    auto start = std::chrono::high_resolution_clock::now();
    __rec_qs_worst(arr, 0, sz - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    return (stop - start).count();
}

template<typename T>
void __recMergeSort(T* arr, size_t sz) {
    if (sz > 1) {
        size_t left_size = sz / 2;
        size_t right_size = sz - left_size;

        __recMergeSort(arr, left_size);
        __recMergeSort(arr + left_size, right_size);        

        size_t l = 0, r = left_size, i = 0;
        T* tmp = new T[sz];

        while (l < left_size || r < sz) {
            if (arr[l] < arr[r]) {
                tmp[i++] = std::move(arr[l++]);
            } else {
                tmp[i++] = std::move(arr[r++]);
            }

            if (l == left_size) {
                std::copy(std::make_move_iterator(arr + r),
                          std::make_move_iterator(arr + sz),
                          tmp + i);
                break;
            }
            if (r == sz) {
                std::copy(std::make_move_iterator(arr + l),
                          std::make_move_iterator(arr + left_size),
                          tmp + i);
                break;
            }
        }

        std::copy(std::make_move_iterator(tmp),
                  std::make_move_iterator(tmp + sz),
                  arr);
        delete[] tmp;
    }
}

template<typename T>
long long MergeSort(T* arr, size_t sz) {
    auto start = std::chrono::high_resolution_clock::now();
    __recMergeSort(arr, sz);
    auto stop = std::chrono::high_resolution_clock::now();
    return (stop - start).count();
}

#endif //_SORT_HPP
