
#include "lab2-2/stack_functions.hpp"

#include <iostream>
#include <stack>
#include <sstream>

std::stack<int> InputStack(int n) {
    std::string input;
    getline(std::cin, input);

    std::stringstream ss;
    ss << input;    

    std::stack<int> st;

    for (int x; n-- && ss >> x; ) {
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

std::pair<int, int> CalcSumProdStack(std::stack<int>& st) {
    int sum = 0, prod = 1;

    while (!st.empty()) {
        int x = st.top();
        st.pop();
        sum += x;
        prod *= x;
    }

    return std::make_pair(sum, prod);
}
