
#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

#include <cstddef>

template<typename _TKey, typename _TVal>
class HashTable {
    private:
        const size_t size_;
        _TKey* keys_;
        _TVal* table_;
        bool* used_;

    public:
        HashTable(size_t sz);
        ~HashTable();
        _TVal& operator[](_TKey key);
        size_t GetSize();
};

#endif //_HASH_TABLE_HPP_
