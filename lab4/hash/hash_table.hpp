
#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

#include <cstddef>

template<typename _TKey, typename _TVal>
struct Hash {
    _TKey key;
    _TVal value;
};

template<typename _TKey, typename _TVal>
class HashTable {
    private:
        const size_t size_;
        Hash<_TKey, _TVal>* table_;
        bool* used_;

    public:
        HashTable(size_t sz);
        ~HashTable();
        _TVal& operator[](_TKey& key);
        size_t Size();
        bool Contains(_TKey key);
        bool Erase(_TKey key);
        Hash<_TKey, _TVal>* begin();
        Hash<_TKey, _TVal>* end();
};

#endif //_HASH_TABLE_HPP_
