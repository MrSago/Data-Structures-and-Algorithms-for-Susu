
#include <iostream>

#include "lab3-2/queue.hpp"

int main() {
	std::cout << "lab1-1 by Gordeev Alexander KE-201\n";

	std::cout << "Enter count elements: ";
	size_t N;
	std::cin >> N;

	auto q = RandomQueue(N);
	std::cout << "Random queue:\n";
	PrintQueue(q);

	std::cout << "Enter range for delete [0, " << N - 1 << "]: ";
	size_t left, right;
	std::cin >> left >> right;

	EraseQueueRange(q, left, right);
	std::cout << "Result:\n";
	PrintQueue(q);

	return 0;
}
