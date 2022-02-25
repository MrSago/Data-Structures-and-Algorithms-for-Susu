
#include "lab2-2/stack_functions.hpp"

#include <iostream>
#include <stack>

std::stack<int> InputStack(int n) {
    std::stack<int> st;
    while (n--) {
        int x;
        std::cin >> x;
        st.push(x);
    }
    return st;
}

void OutputStack(std::stack<int>& st) {
    while (!st.empty()) {
        std::cout << st.top() << ' ';
        st.pop();
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
