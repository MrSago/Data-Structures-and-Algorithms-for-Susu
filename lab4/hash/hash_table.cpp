
#include "lab4/hash/hash_table.hpp"

#include <cstddef>
#include <cstring>
#include <concepts>
#include <string>

#include "lab4/hash/hashrot13.hpp"

template<typename _TKey, typename _TVal>
HashTable<_TKey, _TVal>::HashTable(size_t sz) : size_(sz) {
    table_ = new Hash<_TKey, _TVal>[size_];
    used_ = new bool[size_];
    memset(table_, 0, sizeof(Hash<_TKey, _TVal>) * size_);
    memset(used_, 0, sizeof(bool) * size_);
}

template<typename _TKey, typename _TVal>
HashTable<_TKey, _TVal>::~HashTable() {
    delete[] table_;
    delete[] used_;
}

template<typename _TKey, typename _TVal>
_TVal& HashTable<_TKey, _TVal>::operator[](_TKey& key) {
    size_t index = HashRot13(key) % size_;
    if (!used_[index]) {
        table_[index].key = key;
        used_[index] = true;
    }
    return table_[index].value;
}

template<typename _TKey, typename _TVal>
size_t HashTable<_TKey, _TVal>::Size() {
    return size_;
}

template<typename _TKey, typename _TVal>
bool HashTable<_TKey, _TVal>::Contains(_TKey key) {
    size_t index = HashRot13(key) % size_;
    return used_[index];
}

template<class T>
concept Clearable =
requires (T& container) { container.clear(); };
template<Clearable T>
void ClearValue(T& c) {
    c.clear();
}

template<typename T>
concept Integral = std::is_integral<T>::value;
template<Integral T>
void ClearValue(T& t) {
    t = static_cast<T>(0);
}

template<typename _TKey, typename _TVal>
bool HashTable<_TKey, _TVal>::Erase(_TKey key) {
    size_t index = HashRot13(key) % size_;
    if (!used_[index]) { return false; }
    ClearValue(table_[index].key);
    ClearValue(table_[index].value);
    return true;
}

template<typename _TKey, typename _TVal>
Hash<_TKey, _TVal>* HashTable<_TKey, _TVal>::begin() {
    return table_;
}

template<typename _TKey, typename _TVal>
Hash<_TKey, _TVal>* HashTable<_TKey, _TVal>::end() {
    return table_ + size_;
}

template class HashTable<char, size_t>;
template class HashTable<std::string, size_t>;
template class HashTable<int, size_t>;
