
#include "lab3-1/count_digits.hpp"

#include <cstddef>
#include <ranges>
#include <set>
#include <string>

bool IfDigit(char c) {
	return (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' || c == '=';
}

size_t CountDigits(std::string& str) {
	std::multiset<int> ms;

	for (auto& i : str | std::views::filter(IfDigit)) {
		ms.insert(i);
	}

    return ms.size();
}
