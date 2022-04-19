
#include "lab3-1/functions_menu.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

#include "lab3-1/count_digits.hpp"

void CallFunction() {
    std::cout << "Enter string: ";
    std::string input;
    std::getline(std::cin, input);
    std::cout << "Count digits: " << CountDigits(input) << '\n';
}

void RunTestFile() {
    const char test_fname[] = "test.txt";
    std::ifstream test(test_fname);
    if (test.fail()) {
        std::cout << "\nError opening file: " << test_fname << '\n';
        return;
    }

    std::cout << "\nTest from file: " << test_fname << "\n\n";
    for (int i = 1; !test.eof(); ++i) {
        std::cout << "Test #" << i << '\n';

        std::string str;
        std::getline(test, str);
        std::cout << "String: " << str << '\n';

        size_t cnt = CountDigits(str);

        std::getline(test, str);
        std::stringstream ss; ss << str;
        size_t ans; ss >> ans;

        std::cout << "Result: " << cnt << '\n';
        std::cout
            << "Verdict: "
            << (ans == cnt ? "Accepted" : "Rejected")
            << "\n\n";
    }
}
