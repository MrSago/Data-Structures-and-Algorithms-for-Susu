
#include "lab4/tasks.hpp"

#include <fstream>
#include <iostream>
#include <string>

#include "lab4/hash/hash_table.hpp"
#include "tools/other.hpp"
#include "lab4/hash/hashrot13.hpp"

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
                        << HashRot13(key) << " : "
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
                        << HashRot13(key) << " : "
                        << value << "]\n";
    }

    std::cout << "\nEnter word for search: ";
    std::getline(std::cin, str);
    if (table.Contains(str)) {
        std::cout << '\"' << str << "\" contains in hash table\n"
                  << "Count words in file: " << table[str] << '\n';
    } else {
        std::cout << "Word not contains\n";
    }

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
                        << HashRot13(key) << " : "
                        << value << "]\n";
    }
    std::cout << '\n';
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

    std::cout << "Hash Table:\n";
    for (auto& [key, value] : table) {
        if (!key || !value) { continue; }
        std::cout << '['<< key << " : "
                        << HashRot13(key) << " : "
                        << value << "]\n";
    }

    std::cout << "Enter number for search: ";
    int search = ReadNumber<int>();

    if (table.Contains(search)) {
        std::cout << '\"' << search << "\" found in hash table\n"
                  << "Count in file: " << table[search] << '\n';
    } else {
        std::cout << "Not found\n";
    }
}
