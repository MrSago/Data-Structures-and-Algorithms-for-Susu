
#ifndef _CONSOLE_MENU_HPP_
#define _CONSOLE_MENU_HPP_

#include <functional>
#include <map>
#include <string>

using DictFun = std::map<std::string, std::function<void(void)>>;

class ConsoleMenu {
    public:
        ConsoleMenu(DictFun&& functions) : functions_(functions) {}
        bool Invoke(std::string& key);

    private:
        DictFun functions_;
        ConsoleMenu();
};

#endif // _CONSOLE_MENU_HPP_
