
#include "lab2-2/stack_functions.hpp"

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

std::stack<int> InputStack(int N) {
    std::string input;
    getline(std::cin, input);

    std::stringstream ss;
    ss << input;    

    std::stack<int> st;

    for (int x; N-- && ss >> x; ) {
        st.push(x);
    }

    return st;
}

void OutputStack(std::stack<int> st) {
    std::stack<int> reverse;
    while (!st.empty()) {
        reverse.push(st.top());
        st.pop();
    }

    while (!reverse.empty()) {
        std::cout << reverse.top() << ' ';
        reverse.pop();
    }
    std::cout << std::endl;
}

std::pair<int64_t, int64_t> CalcSumProdStack(std::stack<int> st) {
    int64_t sum = 0, prod = 1;

    while (!st.empty()) {
        sum += st.top();
        prod *= st.top();
        st.pop();
    }

    return std::make_pair(sum, prod);
}
