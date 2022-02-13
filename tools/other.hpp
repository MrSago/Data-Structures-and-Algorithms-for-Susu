
#ifndef _OTHER_HPP_
#define _OTHER_HPP_

#include <iostream>

template<typename T>
T ReadNumber() {
    std::string input;
    std::getline(std::cin, input);
    return static_cast<T>(std::atoll(input.c_str()));
}

#endif // _OTHER_HPP_
