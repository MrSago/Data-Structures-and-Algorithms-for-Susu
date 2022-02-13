
#include "tools/console_menu.hpp"

bool ConsoleMenu::Invoke(std::string& key) {
    if (functions_.contains(key)) {
        functions_[key]();
        return true;
    }
    return false;
}
