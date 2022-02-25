
#include "lab2-2/functions_menu.hpp"

#include <fstream>
#include <iostream>
#include <random>
#include <ranges>
#include <vector>
#include <stack>

#include "lab2-2/stack_functions.hpp"
#include "tools/other.hpp"

void CallFunction() {
    std::cout << "\nEnter N: ";
    size_t N = ReadNumber<size_t>();

    std::stack<int> stack = InputStack(N);
    auto res = CalcSumProdStack(stack);

    std::cout << "Result: ";
    OutputStack(stack);
    std::cout << '\n';
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

        std::string input;
        std::getline(test, input);
        std::cout << "String: " << input << '\n';

        std::vector<int> result = GetNumsFromString<int>(input);

        std::cout << "Result: ";
        PrintVector(result);
        std::cout << '\n';

        std::cout << "Answer: ";
        std::getline(test, input);
        std::cout << input << "\n\n";
    }
}

void RandomTest() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> uid(1, 100);

    std::string str;
    str.resize(uid(gen));
    std::ranges::generate(str, [&uid, &gen]() {
        switch (uid(gen) % 3) {
            case 0:
                return 'a' + uid(gen) % ('z' - 'a');
            case 1:
                return '0' + uid(gen) % 10;
            case 2:
                return (int)' ';
            default:
                break;
        }
        return 0;
    });

    std::cout << "\nString: " << str << '\n';

    std::vector<int> arr = GetNumsFromString<int>(str);

    std::cout << "Result: ";
    PrintVector(arr);
    std::cout << '\n';
}
