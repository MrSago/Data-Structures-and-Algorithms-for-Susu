
#include <iostream>
#include <set>
#include <ranges>
#include <algorithm>

bool IfDigit(char c) {
	return (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*';
}

int main() {
	std::string s;
	std::getline(std::cin, s);

	std::multiset<int> ms;
	for (auto& i : s | std::views::filter(IfDigit)) {
		ms.insert(i);
	}

	std::cout << ms.size() << std::endl;

	return 0;
}
