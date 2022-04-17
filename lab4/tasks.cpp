
#include "lab4/tasks.hpp"

#include <iostream>

#include "lab4/hash/hash_table.hpp"

void FirstTask() {
    const int ALPH_LEN = 26;
    HashTable<char, size_t> table(ALPH_LEN);

    std::cout << "Enter string: ";
    std::string str;
    std::getline(std::cin, str);

    for (auto& c : str) {
        ++table[c];
    }

    std::cout << "Map table:\n";
    std::cout << "[Key : Value]\n";
    for (char c = 'a'; c <= 'z'; ++c) {
        std::cout << '[' << c << " : "
                  << table[c] << "]\n";
    }

    std::cout << "Enter symbol for searching: ";
    std::getline(std::cin, str);

    if (table[str[0]] > 0) {
        std::cout << "Found symbol: " << str[0] << '\n';
        std::cout << "Count symbols in string: " << table[str[0]] << '\n';
    } else {
        std::cout << "Not found\n";
    }
}

void SecondTask() {

}

void ThirdTask() {
    
}
