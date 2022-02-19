
#ifndef _CONSOLE_MENU_HPP_
#define _CONSOLE_MENU_HPP_

#include <functional>
#include <map>
#include <string>

struct MenuInfo {
    std::function<void(void)> function;
    std::string description;
    MenuInfo(std::function<void(void)> _function, std::string _description)
    : function(_function),  description(_description) {}
};

using DictFun = std::map<std::string, MenuInfo>;

class ConsoleMenu {
    public:
        ConsoleMenu(DictFun&& dict)
        : menu_(dict) {
            for (auto& [key, value] : menu_) {
                description_ += key + ". " + value.description + '\n';
            }
        }
        bool Invoke(std::string& key);
        std::string& GetDescription();

    private:
        DictFun menu_;
        std::string description_;
        ConsoleMenu();
};

#endif // _CONSOLE_MENU_HPP_
