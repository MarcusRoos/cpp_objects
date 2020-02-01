//
// Created by Marcus on 2020-01-30.
//
#include "Names.h"

//#include "memstat.hpp"

int main() {
    Names names; // Creates an object from the class Names
    std::cout << "\nPre-determined constructor";
    printNames(names); // Prints names with pre-determined constructor

    /*Use initializing constructor to assign values to the class members*/
    Names names1("Olof","Olofsson");
    std::cout << "\nInitialized constructor, hardcoded";
    printNames(names1); // Prints names1

    /*
     * Changes the values of object listed below, writes over the previous
     *values the objects members had.
     */
    names.setFirstName("Adam");
    names.setLastName("Adamsson");
    std::cout << "\nSetting names using names.set";
    printNames(names); // Prints names

    /*
     * Allows user to enter values which will be stored in the object.
     */
    std::string inFirstName, inLastName;
    std::cout << "Enter the first name of the person\n";
    std::cin >> inFirstName;
    names.setFirstName(inFirstName);
    std::cout << "Enter the last name of the person\n";
    std::cin >> inLastName;
    names.setLastName(inLastName);
    std::cout << "\nInitialized constructor, with user input.";
    printNames(names); // Prints names

    return 0;
}
