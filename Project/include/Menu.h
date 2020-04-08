//
// Created by Marcus Roos on 2020-03-19.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_MENU_H
#define DT019G_MENU_H

#include "MenuItem.h"
#include <vector>

class Menu {
private:
std::vector<MenuItem>menuItem;
std::string menuTitle;
public:
    Menu();
    Menu(std::vector<MenuItem>pmenuItem, std::string pmenuTitle);
    ~Menu()=default;
    void setTitle(std::string ptitle);
    void setenableMenu();
    std::string getTitle() const;
    void printMenuItems() const;
    int menuChoice();
    void addItem(const std::string &pmenuText, bool penabler);
};
#endif //DT019G_MENU_H
