//
// Created by Marcus on 2020-01-30.
//
#include "Address.h"

//#include "memstat.hpp" Doesn't work on W10, 64bit Clion, refuses to compile.

int main() {
    Address address; // Creates an object from the class Address
    std::cout << "\nPre-determined constructor";
    printAddress(address); // Prints address with pre-determined constructor

    /*Use initializing constructor to assign values to the class members*/
    Address address1("Random Street 1","157 30","TownCity");
    std::cout << "\nInitialized constructor, hardcoded";
    printAddress(address1); // Prints address1

    /*
     * Changes the values of object listed below, writes over the previous
     *values the objects members had.
     */
    address.setStreet("Street Streeson");
    address.setPostcode("800 00");
    address.setCity("TownTown");
    std::cout << "\nSetting names using names.set";
    printAddress(address); // Prints address once more, with new values

    /*
     * Allows user to enter values which will be stored in the object.
     */
    std::string inStreet, inPostcode, inCity;
    std::cout << "Enter your street\n";
    std::getline(std::cin >> std::ws, inStreet);
    address.setStreet(inStreet);
    std::cout << "Enter your postcode\n";
    std::getline(std::cin >> std::ws, inPostcode);
    address.setPostcode(inPostcode);
    std::cout << "Enter your city\n";
    std::getline(std::cin >> std::ws, inCity);
    address.setCity(inCity);
    std::cout << "\nInitialized constructor, with user input.";
    printAddress(address); // Prints address once more, with new values

    return 0;
}
