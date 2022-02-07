
#include <iostream>
#include <regex>
#include <vector>

int main() {
	std::vector<int> arr;

	std::string s;
	getline(std::cin, s);

	std::regex re("\\d+");
	auto start = std::sregex_iterator(s.begin(), s.end(), re);
	auto end = std::sregex_iterator();

	for (auto i = start; i != end; ++i){
		arr.push_back(std::stoi((*i).str()));
	}

	for (auto& i : arr) {
		std::cout << i << ' ';
	}
	std::cout << std::endl;

	return 0;
}

