
#ifndef _LIBRARY_HPP_
#define _LIBRARY_HPP_

#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <ranges>
#include <sstream>
#include <vector>

struct Book {
    std::string number;
    std::string surname;

    std::tm date;
    int c_days;

    std::string author;
    std::string name;
    std::string year;
    int cost;

    void Print();
};

struct Node {
    Book* info;
    Node* next;
    Node(Book* _info) : info(_info), next(nullptr) {}
};

Book* InitBookFromStream(std::istream& is);

Node* InitListFromFile(const char filename[]);

class Library {
   private:
    Node* head_;

   public:
    Library(Node* list) : head_(list) {}

    ~Library();

    std::function<int(Book*, std::string)> EqNumber =
        [](Book* b, std::string val) { return b->number == val; };

    std::function<int(Book*, Book*)> CmpNumber = [](Book* b1, Book* b2) {
        return b1->number < b2->number;
    };

    std::function<int(Book*, std::string)> EqAuthor =
        [](Book* b, std::string val) { return b->author == val; };

    std::function<int(Book*, Book*)> CmpAuthor = [](Book* b1, Book* b2) {
        return b1->author < b2->author;
    };

    void Print();

    void Sort(std::function<int(Book*, Book*)> cmp);

    std::vector<Book*> Search(std::string value,
                              std::function<int(Book*, std::string)> cmp);
};

#endif  // _LIBRARY_HPP_
