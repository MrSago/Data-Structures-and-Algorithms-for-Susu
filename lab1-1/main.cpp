
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

constexpr int INVALID_INDEX = -1;

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);

    int ix, jx;
    ix = jx = INVALID_INDEX;
    for (auto i : std::views::iota(0, N)) {
        std::cin >> arr[i];
        if (arr[i] < 0) {
            jx = i;
            if (ix == INVALID_INDEX) {
                ix = i;
            }
        }
    }

    if (ix == INVALID_INDEX || jx == INVALID_INDEX) {
        std::cout << 0 << std::endl;
    }

    auto v = std::views::counted(arr.begin() + ix + 1, jx - ix - 1) |
             std::views::filter([](auto& v) { return v > 0; });
    std::cout << std::accumulate(v.begin(), v.end(), 0) << std::endl;

    return 0;
}
