
#include "lab2-1/library.hpp"

void Book::Print() {
    std::cout << "--------------------\n\n"
              << number << '\n'
              << surname << '\n'
              << date.tm_mday << '.' << date.tm_mon << '.' << date.tm_year << '\n'
              << c_days << '\n'
              << author << '\n'
              << name << '\n'
              << year << '\n'
              << cost << '\n'
              << "\n--------------------\n\n";
}

Book* InitBookFromStream(std::istream& is) {
    Book* book = new Book;
    std::string input;

    std::getline(is, book->number);
    std::getline(is, book->surname);

    std::getline(is, input);
    sscanf(input.c_str(), "%d.%d.%d",
           &book->date.tm_mday, &book->date.tm_mon, &book->date.tm_year);

    std::getline(is, input);
    sscanf(input.c_str(), "%d", &book->c_days);

    std::getline(is, book->author);
    std::getline(is, book->name);
    std::getline(is, book->year);

    std::getline(is, input);
    sscanf(input.c_str(), "%d", &book->cost);

    return book;
}

Node* InitListFromFile(const char filename[]) {
    std::ifstream file(filename);
    if (file.fail()) {
        return nullptr;
    }

    std::string input;
    std::stringstream ss;
    size_t N;

    std::getline(file, input);
    ss << input;
    ss >> N;
    ss.clear();

    Node* head = new Node(InitBookFromStream(file));
    Node* tail = head;

    for (size_t i : std::views::iota(0ULL, N - 1)) {
        tail = tail->next = new Node(InitBookFromStream(file));
    }

    return head;
}

Library::~Library() {
    Node *cur = head_, *prev;

    while (cur) {
        prev = cur;
        delete cur->info;
        cur = cur->next;
        delete prev;
    }
}

void Library::Print() {
    std::cout << "\nPrint list:\n\n";
    Node* tail = head_;

    while (tail) {
        Book* book = tail->info;
        book->Print();
        tail = tail->next;
    }
}

void Library::Sort(std::function<int(Book*, Book*)> cmp) {
    Node* new_node = nullptr;

    while (head_ != nullptr) {
        Node* node = head_;
        head_ = head_->next;

        if (new_node == nullptr || cmp(node->info, new_node->info)) {
            node->next = new_node;
            new_node = node;
        } else {
            Node* current = new_node;

            while (current->next != nullptr &&
                   !(cmp(node->info, current->next->info))) {
                current = current->next;
            }

            node->next = current->next;
            current->next = node;
        }
    }

    head_ = new_node;
}

std::vector<Book*> Library::Search(std::string value,
                                   std::function<int(Book*, std::string)> cmp) {
    std::vector<Book*> search_books;
    Node* cur = head_;

    while (cur) {
        if (cmp(cur->info, value)) {
            search_books.push_back(cur->info);
        }
        cur = cur->next;
    }

    return search_books;
}
