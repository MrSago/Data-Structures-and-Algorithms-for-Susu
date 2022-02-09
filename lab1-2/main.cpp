
#include <iostream>
#include <regex>
#include <vector>

std::vector<int> GetNumsFromString(std::string& s) {
    std::regex re("\\d+");
    auto start = std::sregex_iterator(s.begin(), s.end(), re);
    auto end = std::sregex_iterator();

    std::vector<int> v;
    for (auto i = start; i != end; ++i) {
        v.push_back(std::stoi((*i).str()));
    }

    return v;
}

int main() {
    std::string s;
    getline(std::cin, s);

    std::vector<int> arr = GetNumsFromString(s);

    for (auto& i : arr) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}
