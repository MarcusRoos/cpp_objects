//
// Created by Marcus Roos on 2020-03-19.
// Mittuniversitet
// StudentID: Maro1904
//

#include "Menu.h"

#include <iostream>
#include <utility>

Menu::Menu() {
    menuTitle="";
}

Menu::Menu(std::vector<MenuItem> pmenuItem, std::string pmenuTitle) {
    menuTitle = std::move(pmenuTitle);
    menuItem = std::move(pmenuItem);
}

void Menu::setTitle(std::string ptitle) {
    menuTitle = std::move(ptitle);
}

void Menu::addItem(std::string pmenuText, bool penabler) {
   menuItem.emplace_back(pmenuText, penabler);
}

void Menu::printMenuItems() const {
    using namespace std;
    cout << "****************************************************\n";
    cout << "****             1.  File...                    ****\n";
    cout << "***              2.  Add an album                ***\n";
    cout << "**               3.  Delete an album              **\n";
    cout << "***              4.  Print...                    ***\n";
    cout << "****             5.  Exit                       ****\n";
    cout << "****************************************************\n";
}

