
#include "lab4/hash/hashrot13.hpp"

size_t HashRot13(char* p_str) {
    size_t hash = 0;
    for (; *p_str != '\0'; ++p_str) {
        hash += (size_t)(*p_str);
        hash -= (hash << 13) | (hash >> 19);
    }
    return hash;
}

size_t HashRot13(char c) {
    size_t hash = (size_t)c;
    hash -= (hash << 13) | (hash >> 19);
    return hash;
}
