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

void Menu::addItem(const std::string& pmenuText, bool penabler) {
   menuItem.emplace_back(pmenuText, penabler);
}

void Menu::printMenuItems() const {
    using namespace std;
    int i = 0;
    for (auto e : menuItem){
        i++;
        cout << i << ".  " << e.getMenuText() << "  ";
        if (e.getEnabled())
            cout << "       Enabled\n";
        if (!e.getEnabled())
            cout << "       Disabled\n";
    }
}

int Menu::menuChoice() {
    using namespace std;
    int choice;
    cout << "Choice...";
    cin >> choice;
    bool test;
    while (choice <1 || choice >5){
        std::cout << "Wrong input.\n";
        cin >> choice;
    }
    return choice;
}

