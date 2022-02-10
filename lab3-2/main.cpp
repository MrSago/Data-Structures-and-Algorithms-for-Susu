
#include <iostream>
#include <queue>
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
	if (l > r || r >= q.size()) return;
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
	q = s;
}

void PrintQueue(std::queue<int> q) {
	while (!q.empty()) {
		std::cout << q.front() << ' ';
		q.pop();
	}
	std::cout << std::endl;
}

int main() {
	size_t N;
	std::cin >> N;
	std::queue<int> q = RandomQueue(N);
	PrintQueue(q);

	size_t left, right;
	std::cin >> left >> right;
	EraseQueueRange(q, left, right);
	PrintQueue(q);

	return 0;
}
