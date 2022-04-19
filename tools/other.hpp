
#ifndef _OTHER_HPP_
#define _OTHER_HPP_

#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

template<typename T>
T ReadNumber() {
    std::string input;
    std::getline(std::cin, input);
    return static_cast<T>(std::atoll(input.c_str()));
}

template<typename T>
void PrintVector(std::vector<T>& vec) {
    std::ranges::for_each(vec,
        [](auto& x) { std::cout << x << ' '; }
    );
}

#endif // _OTHER_HPP_
