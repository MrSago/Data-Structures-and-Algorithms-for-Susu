
#include "lab4/tasks.hpp"

#include <fstream>
#include <iostream>
#include <string>

#include "lab4/hash/hash_table.hpp"
#include "tools/other.hpp"

void FirstTask() {
    const int ALPH_LEN = 26;
    HashTable<char, size_t> table(ALPH_LEN);

    std::cout << "Enter string: ";
    std::string str;
    std::getline(std::cin, str);

    for (auto& c : str) {
        ++table[c];
    }

    std::cout << "Hash Table:\n";
    for (auto& [key, value] : table) {
        if (!key || !value) { continue; }
        std::cout << '['<< key << " : "
                        << value << "]\n";
    }

    std::cout << "Enter symbol for searching: ";
    std::getline(std::cin, str);

    if (table.Contains(str[0])) {
        std::cout << "Found symbol: " << str[0] << '\n'
                  << "Count in string: " << table[str[0]] << '\n';
    } else {
        std::cout << "Not found\n";
    }
}

void SecondTask() {
    const char fname[] = "task2.txt";
    std::ifstream file(fname);
    if (file.fail()) {
        std::cout << "Error open file: " << fname << '\n';
        return;
    }

    std::cout << "Enter hash table size: ";
    size_t table_size = ReadNumber<size_t>();

    HashTable<std::string, size_t> table(table_size);

    std::string str;
    while (file >> str) {
        ++table[str];
    }

    std::cout << "Hash Table:\n";
    for (auto& [key, value] : table) {
        if (key.empty() || !value) { continue; }
        std::cout << '['<< key << " : "
                        << value << "]\n";
    }

    std::cout << "\nEnter word for search: ";
    std::getline(std::cin, str);
    std::cout
        << '\"' << str << "\" "
        << (table.Contains(str)
        ? "contains"
        : "not contains")
        << " in hash table\n";

    std::cout << "\nEnter symbol for delete: ";
    std::getline(std::cin, str);
    for (auto& [key, value] : table) {
        if (key.empty() || !value) { continue; }
        if (key[0] == str[0]) {
            table.Erase(key);
        }
    }

    std::cout << "Hash Table:\n";
    for (auto& [key, value] : table) {
        if (key.empty() || !value) { continue; }
        std::cout << '['<< key << " : "
                        << value << "]\n";
    }
}

void ThirdTask() {
    const char fname[] = "task3.txt";
    std::ifstream file(fname);
    if (file.fail()) {
        std::cout << "Error open file: " << fname << '\n';
        return;
    }

    const size_t table_size = 1000;
    HashTable<int, size_t> table(table_size);

    int number;
    while (file >> number) {
        ++table[number];
    }

    std::cout << "Enter number for search: ";
    int search = ReadNumber<int>();

    if (table.Contains(search)) {
        std::cout << "Found number\n"
                  << "Count in file: " << table[search] << '\n';
    } else {
        std::cout << "Not found\n";
    }
}
