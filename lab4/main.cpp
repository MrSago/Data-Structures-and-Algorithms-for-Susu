
#include <iostream>
#include <string>

#include "lab4/tasks.hpp"
#include "tools/console_menu.hpp"

int main() {
    std::cout << "lab4 by Gordeev Alexander KE-201\n";

    ConsoleMenu menu(DictFun {
        { "1", { FirstTask, "First task" } },
        { "2", { SecondTask, "Second task" } },
        { "3", { ThirdTask, "Third task" } }
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
