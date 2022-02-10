
#include <iostream>
#include <ranges>
#include <regex>
#include <vector>

std::vector<int> GetNumsFromString(std::string& s) {
    std::regex re("\\d+");
    auto start = std::sregex_iterator(s.begin(), s.end(), re);
    auto end = std::sregex_iterator();

    std::vector<int> v;
    std::ranges::for_each(start, end, [&v](auto match) {
        v.push_back(std::stoi(match.str()));
    });

    return v;
}

int main() {
    std::string s;
    getline(std::cin, s);

    std::vector<int> arr = GetNumsFromString(s);

    std::ranges::for_each(arr, [](auto& v) { std::cout << v << ' '; });
    std::cout << std::endl;

    return 0;
}
