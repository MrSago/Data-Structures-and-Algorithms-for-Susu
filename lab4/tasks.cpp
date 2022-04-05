
#include "lab4/tasks.hpp"

#include <iostream>
#include <unordered_map>

void FirstTask() {
    std::unordered_map<char, size_t> m;

    std::cout << "Enter string: ";
    std::string s;
    std::getline(std::cin, s);

    for (auto& c : s) {
        ++m[c];
    }

    std::cout << "Map table:\n";
    std::cout << "[Key : Value]\n";
    for (auto& [key, value] : m) {
        std::cout << '[' << key << " : " << value << "]\n";
    }

    std::cout << "Enter symbol for searching: ";
    std::getline(std::cin, s);

    if (m.count(s[0])) {
        std::cout << "Found symbol: " << s[0] << '\n';
        std::cout << "Count symbols in string: " << m[s[0]] << '\n';
    } else {
        std::cout << "Not found\n";
    }
}

void SecondTask() {
    ifstream file("test.txt");

    std::unordered_map<std::string, bool> m;

    while (!file.eof()) {
        std::string s;
        file >> s;
        m[s] = true;
    }

    std::cout << "Table of words:\n";
    for (auto& [key, value] : m) {
        std::cout << key << '\n';
    }
}

void ThirdTask() {
    
}
