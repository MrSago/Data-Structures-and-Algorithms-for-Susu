
#include <iostream>

#include "lab1-1/functions_menu.hpp"
#include "tools/console_menu.hpp"

int main() {
    std::cout << "lab1-1 by Gordeev Alexander KE-201\n";

    ConsoleMenu menu(DictFun {
        { "1", CallFunction },
        { "2", RunTestFile },
        { "3", RandomTest }
    });

    for (;;) {
        std::cout
            << '\n'
            << "1. Simple call function\n"
            << "2. Run test from file\n"
            << "3. Generate random test\n"
            << "0. Exit program\n";

        std::string input;
        std::getline(std::cin, input);
        if (input == "0") { break; }

        if (!menu.Invoke(input)) {
            std::cout << "Unknown parameter: " << input << '\n';
        }
    }

    return 0;
}
