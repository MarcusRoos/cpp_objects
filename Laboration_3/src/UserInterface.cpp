//
// Created by Marcus Roos on 2020-02-11.
// Mittuniversitet
// StudentID: Maro1904
//
#include <iostream>
#include "UserInterface.h"

void UserInterface::run() {
    menu();
}

int UserInterface::menu(){
    using namespace std;
    cout << "**********************************************\n";
    cout << "*       0. Exit program                      *\n";
    cout << "*       1. Add person                        *\n";
    cout << "*       2. Display persons                   *\n";
    cout << "*       3. Save to file                      *\n";
    cout << "*       4. Load from file                    *\n";
    cout << "*       5. Sort by name                      *\n";
    cout << "*       6. Sort by social security number    *\n";
    cout << "*       7. Sort by shoe size                 *\n";
    cout << "**********************************************\n";
    int choice=0;
    cin >> choice;
    return choice;
}

void UserInterface::addPerson(){
std::cout << "AddPerson\n";
}

void UserInterface::displayPersons(){
    std::cout << "displayPersons\n";
}

void UserInterface::saveToFile(){
    std::cout << "saveToFile\n";
}

void UserInterface::readFromFile(){
    std::cout << "readFromFile\n";
}

void UserInterface::sortByName(){
    std::cout << "sortByName\n";
}

void UserInterface::sortByPNr(){
    std::cout << "SortByPNr\n";
}

void UserInterface::sortByShoeSize(){
    std::cout << "sortByShoeSize\n";
}

UserInterface::UserInterface() = default;
