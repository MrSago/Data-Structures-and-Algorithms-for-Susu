
#include <iostream>
#include <random>

struct FileInfo {
    std::string dir;
    std::string name;
    std::string ext;
    int created;
};

struct FileList {
    FileInfo info;
    struct FileList* next;
};

class RandomString {
    private:
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<char> uid;

    public:
        RandomString() : rd(), gen(rd()), uid('a', 'z') {}
        std::string GetString(int n) {
            std::string s;
            s.resize(n);
            std::generate(s.begin(), s.end(),
                [](auto& c) { return uid(gen); }
            );
            return s;
        }
};

int main() {
    RandomString rs;
    std::cout << rs.GetString(10) << '\n';
    return 0;
}
