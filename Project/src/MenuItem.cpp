//
// Created by Marcus Roos on 2020-03-19.
// Mittuniversitet
// StudentID: Maro1904
//

#include "MenuItem.h"
#include <utility>

MenuItem::MenuItem() {
    menutext = "";
    enabler = false;
}

MenuItem::MenuItem(std::string pmenutext, bool penabler) {
    menutext = std::move(pmenutext);
    enabler = penabler;
}

void MenuItem::setEnabled(bool penabler) {
    enabler = penabler;
}

std::string MenuItem::getMenuText() const {
    return menutext;
}

bool MenuItem::getEnabled() const {
    return enabler;
}


