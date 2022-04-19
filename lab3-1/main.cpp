
#include <iostream>
#include <string>

#include "lab3-1/functions_menu.hpp"
#include "tools/console_menu.hpp"

int main() {
    std::cout << "lab3-1 by Gordeev Alexander KE-201\n";

    ConsoleMenu menu(DictFun {
        { "1", { CallFunction, "Simple call function" } },
        { "2", { RunTestFile, "Run test from file" } },
    });

    for (;;) {
        std::cout << menu.GetDescription()
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
