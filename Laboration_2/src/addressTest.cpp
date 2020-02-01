//
// Created by Marcus on 2020-01-30.
//
#include "Address.h"

//#include "memstat.hpp" Doesn't work on W10, 64bit Clion, refuses to compile.

int main() {
    Address address;
    std::cout << "\nPre-determined constructor";
    printAddress(address);

    Address address1("Random Street 1","157 30","TownCity");
    std::cout << "\nInitialized constructor, hardcoded";
    printAddress(address1);

    address.setStreet("Street Streeson");
    address.setPostcode("800 00");
    address.setCity("TownTown");
    std::cout << "\nSetting names using names.set";
    printAddress(address);

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
    printAddress(address);

    return 0;
}
