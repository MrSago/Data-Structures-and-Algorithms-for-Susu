
#include "lab2-2/functions_menu.hpp"

#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <ranges>
#include <sstream>
#include <stack>
#include <vector>

#include "lab2-2/stack_functions.hpp"
#include "tools/other.hpp"

void CallFunction() {
    std::cout << "\nEnter N: ";
    size_t N = ReadNumber<size_t>();

    auto stack = InputStack(N);
    auto result = CalcSumProdStack(stack);

    std::cout << "Stack: ";
    OutputStack(stack);

    std::cout << "Sum = " << result.first << '\n'
              << "Product = " << result.second << "\n\n";
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
        size_t N;
        std::string input;
        std::stringstream ss;

        std::getline(test, input);
        ss << input;

        if (!(ss >> N)) { continue; }
        ss.clear();

        std::getline(test, input);
        ss << input;

        std::stack<int> stack;
        for (int x; N-- && ss >> x; ) {
            stack.push(x);
        }

        std::cout << "Test #" << i << '\n';

        std::cout << "Stack: ";
        OutputStack(stack);

        auto result = CalcSumProdStack(stack);
        std::cout << "Sum = " << result.first << '\n'
                  << "Product = " << result.second << "\n\n";
    }
}

void RandomTest() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> uid(-20, 20);

    std::cout << "Enter N: ";
    size_t N = ReadNumber<size_t>();

    std::stack<int> stack;
    while (N--) {
        stack.push(uid(gen));
    }

    std::cout << "Stack: ";
    OutputStack(stack);

    auto result = CalcSumProdStack(stack);
    std::cout << "Sum = " << result.first << '\n'
              << "Product = " << result.second << "\n\n";
}
