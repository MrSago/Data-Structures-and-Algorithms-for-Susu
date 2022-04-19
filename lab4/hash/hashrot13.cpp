
#include "lab4/hash/hashrot13.hpp"

#include <cstddef>
#include <string>

size_t HashRot13(std::string& str) {
    size_t hash = 0;
    for (auto& c : str) {
        hash += static_cast<size_t>(c);
        hash -= (hash << 13) | (hash >> 19);
    }
    return hash;
}

template<typename T>
size_t HashRot13(T input) {
    size_t hash = static_cast<size_t>(input);
    hash -= (hash << 13) | (hash >> 19);
    return hash;
}

template size_t HashRot13<char>(char input);
template size_t HashRot13<int>(int input);
