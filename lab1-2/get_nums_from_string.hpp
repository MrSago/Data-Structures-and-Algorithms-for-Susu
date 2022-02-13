
#ifndef _GET_NUMS_FROM_TRING_HPP_
#define _GET_NUMS_FROM_TRING_HPP_

#include <ranges>
#include <regex>
#include <vector>

template<typename T>
std::vector<T> GetNumsFromString(std::string& s) {
    std::regex re("\\d+");
    auto start = std::sregex_iterator(s.begin(), s.end(), re);
    auto end = std::sregex_iterator();

    std::vector<T> v;
    std::ranges::for_each(start, end, [&v](auto match) {
        v.push_back(static_cast<T>(std::stoll(match.str())));
    });

    return v;
}

#endif // _GET_NUMS_FROM_TRING_HPP_
