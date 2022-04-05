
#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>

#include "tools/console_menu.hpp"
#include "lab2-1/library.hpp"

int main() {
    std::cout << "lab2-1 by Gordeev Alexander KE-201\n";

    Library lib(InitListFromFile("test.txt"));

    auto search = [&lib](std::function<int(Book*, std::string)> eq) {
        std::cout << "Enter value: ";
        std::string s;
        std::getline(std::cin, s);
        auto list = lib.Search(s, eq);
        std::cout << "\nFound list:\n\n";
        std::ranges::for_each(list, [](auto& node) {
            node->Print();
        });
    };

    ConsoleMenu menu(DictFun{
        {"1", {[&lib]() { lib.Print(); }, "Print list"}},
        {"2", {[&lib]() { lib.Sort(lib.CmpNumber); }, "Sort by number"}},
        {"3", {[&lib]() { lib.Sort(lib.CmpAuthor); }, "Sort by author"}},
        {"4", {[&lib, &search]() { search(lib.EqNumber); }, "Search by number"}},
        {"5", {[&lib, &search]() { search(lib.EqAuthor); }, "Search by author"}},
        {"6", {[&lib]() { lib.PrintExpired(); }, "Print expired"}}
    });

    for (;;) {
        std::cout << menu.GetDescription() << "0. Exit program\n";

        std::string input;
        std::getline(std::cin, input);
        if (input == "0") {
            break;
        }

        if (!menu.Invoke(input)) {
            std::cout << "Unknown parameter: " << input << '\n';
        }
    }

    return 0;
}
