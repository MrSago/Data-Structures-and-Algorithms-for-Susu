
#include <iostream>

struct Date;

struct FileInfo {
	std::string dir;
	std::string name;
	std::string ext;
	Date created;
};

struct FileList {
	FileInfo info;
	struct FileList* next;
}

class RandomString {
	private const std::random_device rd;
	private std::mt19937 gen(rd);
	private std::uniform_int_distribution<char> uid('a', 'z');

	public RandomString() {}
	public std::string GetString(int n) {
		std::string s(n);
		std::generate(s.begin(), s.end(),
			[&uid, &gen](auto& c) { return uid(gen); }
		);
		return s;
	}

int main() {
	
	return 0;
}
