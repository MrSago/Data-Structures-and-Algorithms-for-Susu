
#include "lab1-1/functions_menu.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <ranges>
#include <sstream>
#include <vector>

#include "lab1-1/sum_first_last_neg.hpp"
#include "tools/other.hpp"

void CallFunction() {
    std::cout << "\nEnter N: ";
    size_t N = ReadNumber<size_t>();
    if (N <= 0) {
        std::cout << "Input error!\n";
        return;
    }

    std::cout << "Enter array: ";
    std::string input;
    std::getline(std::cin, input);
    std::stringstream ss;
    ss << input;

    std::vector<int> arr(N);
    size_t cnt_entered = 0;
    std::ranges::for_each(arr, [&ss, &cnt_entered](auto& x) {
        if (ss >> x) ++cnt_entered;
    });

    if (cnt_entered < N) {
        std::cout << "Few numbers in array!\n";
        return;
    }

    std::cout << "Result: " << SumFirstLastNeg(arr) << '\n';
}

void RunTestFile() {
    const char test_fname[] = "test.txt";
    std::ifstream test(test_fname);
    if (test.fail()) {
        std::cout << "Error opening file: " << test_fname << '\n';
        return;
    }

    std::cout << "\nTest from file: " << test_fname << "\n\n";
    for (int i = 1; !test.eof(); ++i) {
        std::cout << "Test #" << i << '\n';

        size_t N; test >> N;
        std::cout << "N = " << N << '\n';

        std::cout << "Array: ";
        std::vector<int> arr(N);
        std::ranges::for_each(arr, [&test](auto& x) {
            test >> x;
            std::cout << x << ' ';
        });
        std::cout << '\n';

        int answer; test >> answer;
        std::cout << "Answer: " << answer << '\n';

        int result = SumFirstLastNeg(arr);
        std::cout << "Result: " << result << '\n';

        std::cout
            << "Verdict: "
            << (answer == result ? "Accepted" : "Rejected")
            << "\n\n";
    }
}

void RandomTest() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> uid(-100, 100);

    std::cout << "\nEnter N: ";
    size_t N = ReadNumber<size_t>();
    if (N <= 0) {
        std::cout << "Input error!\n";
        return;
    }

    std::cout << "Array: ";
    std::vector<int> arr(N);
    std::ranges::generate(arr, [&uid, &gen]() {
        int x = uid(gen);
        std::cout << x << ' ';
        return x;
    });
    std::cout << '\n';

    int result = SumFirstLastNeg(arr);
    std::cout << "Result: " << result << '\n';
}
