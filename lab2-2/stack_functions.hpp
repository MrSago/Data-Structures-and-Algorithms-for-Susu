
#ifndef _STACK_FUNCTIONS_HPP_
#define _STACK_FUNCTIONS_HPP_

#include <cstdint>
#include <stack>

std::stack<int> InputStack(int n);
void OutputStack(std::stack<int> st);
std::pair<int64_t, int64_t> CalcSumProdStack(std::stack<int> st);

#endif // _STACK_FUNCTIONS_HPP_
