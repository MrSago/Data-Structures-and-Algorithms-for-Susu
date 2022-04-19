
#ifndef _HASHROT13_HPP_
#define _HASHROT13_HPP_

#include <cstddef>
#include <string>

size_t HashRot13(std::string& str);

template<typename T>
size_t HashRot13(T input);

#endif // _HASHROT13_HPP_
