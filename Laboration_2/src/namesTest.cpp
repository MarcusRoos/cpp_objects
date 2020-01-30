//
// Created by Marcus on 2020-01-30.
//
#include "Names.h"

//#include "memstat.hpp"

int main() {
    Names names;
    std::cout << "\nPre-determined constructor";
    printNames(names);

    Names names1("Olof","Olofsson");
    std::cout << "\nInitialized constructor, hardcoded";
    printNames(names1);

    names.setFirstName("Adam");
    names.setLastName("Adamsson");
    std::cout << "\nSetting names using names.set";
    printNames(names);

    std::string inFirstName, inLastName;
    std::cout << "Enter the first name of the person\n";
    std::cin >> inFirstName;
    names.setFirstName(inFirstName);
    std::cout << "Enter the last name of the person\n";
    std::cin >> inLastName;
    names.setLastName(inLastName);
    std::cout << "\nInitialized constructor, with user input.";
    printNames(names);

    return 0;
}
