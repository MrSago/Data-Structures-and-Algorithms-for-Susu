
#include "tools/console_menu.hpp"

bool ConsoleMenu::Invoke(std::string& key) {
    if (menu_.contains(key)) {
        menu_[key].function();
        return true;
    }
    return false;
}

std::string& ConsoleMenu::GetDescription() {
    return description_;
}
