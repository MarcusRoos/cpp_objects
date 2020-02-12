//
// Created by Marcus Roos on 2020-02-11.
// Mittuniversitet
// StudentID: Maro1904
//
#include <iostream>
#include <limits>
#include "UserInterface.h"

void UserInterface::run() {
    int choice=0;
    do {
    choice=menu();
    switch (choice) {
        case 0:
            std::cout << "Program terminated.\n";
        default:
            break;
        case 1:
            std::cout << "1 Add\n";
            addPerson();
            break;
        case 2:
            std::cout << "2 - Display\n";
            displayPersons();
            break;
        case 3:
            std::cout << "3 - Save\n";
            break;
        case 4:
            std::cout << "4 - Load\n";
            break;
        case 5:
            std::cout << "5 - SortName\n";
            break;
        case 6:
            std::cout << "6 - SortNumber\n";
            break;
        case 7:
            std::cout << "7 - SortShoe\n";
            break;
    }
    }while(choice!=0);
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
    bool loop;
    do {
        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 7) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
            loop = true;
            cout << "Invalid option." << "\n";
        }
        else {
            loop = false;
        }
    }while(loop);

    return choice;
}

void UserInterface::addPerson(){
    std::cout << "AddPerson\n";
    std::cout << "Enter the persons first name.\n";
    std::string tmpFirst;
    std::cin >> tmpFirst;
    std::cout << "Enter the persons last name.\n";
    std::string tmpLast;
    std::cin >> tmpLast;
    std::cout << "Enter the persons street address.\n";
    std::string tmpStreet;
    std::cin >> tmpStreet;
    std::cout << "Enter the persons postcode.\n";
    std::string tmpCode;
    std::cin >> tmpCode;
    std::cout << "Enter the persons city.\n";
    std::string tmpCity;
    std::cin >> tmpCity;
    std::cout << "Enter the persons social security number.\n";
    std::string tmpNr;
    std::cin >> tmpNr;
    tmpNr += '|';
    std::cout << "Enter the persons shoe size.\n";
    int tmpSize;
    std::cin >> tmpSize;
    Names names(tmpFirst,tmpLast);
    Address address(tmpStreet,tmpCode,tmpCity);
    Person person(names, address, tmpNr, tmpSize);
    personList.addPerson(person);
}

void UserInterface::displayPersons(){
    std::cout << "Enter index to return a person.\n";
    Person person;
    size_t idx=0;
    std::cin >> idx;
    person=personList.showPerson(idx);
    std::cout << "\n"<< person << std::endl;
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
