
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

constexpr int INVALID_INDEX = -1;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (auto& i : arr) {
        std::cin >> i;
    }

    auto neg = [](int& v) { return v < 0; };
    auto ix = find_if(arr.begin(), arr.end(), neg);
    auto jx = find_if(arr.rbegin(), arr.rend(), neg);

    if (ix == arr.end() || jx == arr.rend()) {
        std::cout << 0 << std::endl;
    }

    auto v = std::ranges::subrange(ix + 1, (jx + 1).base()) |
             std::views::filter([](auto& v) { return v > 0; });
    std::cout << std::accumulate(v.begin(), v.end(), 0) << std::endl;

    return 0;
}
