
#include "lab4/hash/hash_table.hpp"

#include "lab4/hash/hashrot13.hpp"

template<typename _TKey, typename _TVal>
HashTable<_TKey, _TVal>::HashTable(size_t sz) : size_(sz) {
    keys_ = new _TKey[size_];
    table_ = new _TVal[size_];
    used_ = new bool[size_];

    memset(keys_, 0, sizeof(_TKey) * size_);
    memset(table_, 0, sizeof(_TVal) * size_);
    //memset(used_, 0, sizeof(bool) * size_);
}

template<typename _TKey, typename _TVal>
HashTable<_TKey, _TVal>::~HashTable() {
    delete[] keys_;
    delete[] table_;
    delete[] used_;
}

template<typename _TKey, typename _TVal>
_TVal& HashTable<_TKey, _TVal>::operator[](_TKey key) {
    size_t index = HashRot13(key) % size_;

    if (!used_[index]) {
        keys_[index] = key;
        used_[index] = true;
    }

    return table_[index];
}
