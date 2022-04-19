
#include "lab3-2/queue.hpp"

#include <iostream>
#include <random>
#include <stack>

std::queue<int> RandomQueue(size_t n) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uid(-100, 100);
	std::queue<int> q;
	while (n--) {
		q.push(uid(gen));
	}
	return q;
}

void EraseQueueRange(std::queue<int>& q, size_t l, size_t r) {
    if (l > r) {
        std::swap(l, r);
    }

    l = std::clamp(l, 0ULL, q.size() - 1);
    r = std::clamp(r, 0ULL, q.size() - 1);

	size_t count = r - l + 1;

	std::queue<int> s;
	while (l--) {
		s.push(q.front());
		q.pop();
	}
	while (count--) {
		q.pop();
	}
	while (!q.empty()) {
		s.push(q.front());
		q.pop();
	}
	std::swap(q, s);
}

void PrintQueue(std::queue<int> q) {
	while (!q.empty()) {
		std::cout << q.front() << ' ';
		q.pop();
	}
	std::cout << std::endl;
}
