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
    string title;
    title = getTitle();
    cout << title << endl;
    for (const auto& e : menuItem){
        i++;
        cout << i << ".  " << e.getMenuText() << "\n";
    }
}

int Menu::menuChoice() {
    using namespace std;
    int choice;
    cout << "Choice...";
    cin >> choice;
    if (!menuItem[choice-1].getEnabled())
        cout << "Menu currently disabled\n";
    if (menuItem[choice-1].getEnabled()) {
        cout << "Menu is enabled\n";

    }
    while (choice <1 || choice >6){
        std::cout << "Wrong input.\n";
        cin >> choice;
    }
    if (menuItem[choice-1].getEnabled())
    return choice;
}

std::string Menu::getTitle() const {
    return menuTitle;
}

void Menu::setenableMenu() {
    for (auto &e : menuItem)
        e.setEnabled(true);
}
