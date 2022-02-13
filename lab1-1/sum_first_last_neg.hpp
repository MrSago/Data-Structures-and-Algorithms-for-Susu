
#ifndef _SUM_FIRST_LAST_NEG_HPP_
#define _SUM_FIRST_LAST_NEG_HPP_

#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>

template <typename T>
T SumFirstLastNeg(std::vector<T>& v) {
    auto neg = [](auto& x) { return x < 0; };
    auto pos = [](auto& x) { return x > 0; };

    auto first_it = find_if(v.begin(), v.end(), neg);
    auto last_it = find_if(v.rbegin(), v.rend(), neg);

    if (first_it == v.end() || last_it == v.rend() ||
        first_it + 1 >= (last_it + 1).base()) {
        return 0;
    }

    auto it = std::ranges::subrange(first_it + 1, (last_it + 1).base()) |
              std::views::filter(pos);

    return std::accumulate(it.begin(), it.end(), 0);
}

#endif // _SUM_FIRST_LAST_NEG_HPP_
