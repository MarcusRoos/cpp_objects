//
// Created by Marcus Roos on 2020-02-11.
// Mittuniversitet
// StudentID: Maro1904
//
#include <iostream>
#include <limits>
#include "UserInterface.h"
#include "Management.h"

void UserInterface::run() {
    int choice=0;
    do {
    choice=menu();
    switch (choice) {
        case 0:
            pauseFunction("Program terminated, press any key to exit.");
        default:
            break;
        case 1:
            addPerson();
            break;
        case 2:
            displayPersons();
            break;
        case 3:
            saveToFile();
            break;
        case 4:
            readFromFile();
            break;
        case 5:
            sortByName();
            break;
        case 6:
            sortByPNr();
            break;
        case 7:
            sortByShoeSize();
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
    clearScreen();
    std::cout << "AddPerson\n";
    std::cout << "Enter the persons first name.\n";
    std::string tmpFirst;
    tmpFirst=validate(tmpFirst);
    std::cout << "Enter the persons last name.\n";
    std::string tmpLast;
    tmpLast=validate(tmpLast);
    std::cout << "Enter the persons street address.\n";
    std::string tmpStreet;
    std::getline(std::cin >> std::ws, tmpStreet);
    std::cout << "Enter the persons postcode.\n";
    std::string tmpCode;
    std::cin >> tmpCode;
    while (tmpCode.length() <5 || tmpCode.length() >5){
        std::cout << "Wrong input.\n";
        std::cin >> tmpCode;
    }
    std::cout << "Enter the persons city.\n";
    std::string tmpCity;
    tmpCity = validate(tmpCity);
    std::cout << "Enter the persons social security number.\n";
    std::string tmpNr;
    std::cin >> tmpNr;
    while (tmpNr.length() <4 || tmpNr.length() >4){
        std::cout << "Wrong input, 4 integers required, you entered " <<
        tmpNr.length() << " integers\n";
        std::cin >> tmpNr;
    }
    tmpNr += '|';
    std::cout << "Enter the persons shoe size.\n";
    int tmpSize=0;
    while (std::cin.fail() || tmpSize<15 || tmpSize>50) { // If fail, request new input
        std::cout << "You did not enter a correct shoe size between 15 and 50.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> tmpSize;
    }
    Names names(tmpFirst,tmpLast);
    Address address(tmpStreet,tmpCode,tmpCity);
    Person person(names, address, tmpNr, tmpSize);
    personList.addPerson(person);
}

void UserInterface::displayPersons(){
    clearScreen();
    std::cout << "Printed list of persons.\n";
    Person person;
    personList.personListSize();
    if (personList.personListSize() == 0)
        std::cout << "Empty list\n";
    else {
        std::cout << "The list currently contain \"" << personList.personListSize()
        << "\" elements.\n\n";
        for (size_t idx = 0; idx < personList.personListSize(); idx++) {
            person = personList.showPerson(idx);
            std::cout  << person << std::endl;
        }
    }
    pauseFunction("Press any key to return to main menu.");
    clearScreen();
}

void UserInterface::saveToFile(){
    clearScreen();
    std::cout << "SAVE TO FILE.\n";
    std::string fileName;
    std::cout << "Enter name of the file to save to.\n";
    fileName = validateFileName(fileName);
    personList.setFileName(fileName);
    personList.writeToFile();
    std::cout << "List has been successfully saved to " << fileName << "!\n";
    pauseFunction("Press any key to continue.\n");
    clearScreen();
}

void UserInterface::readFromFile(){
    clearScreen();
    std::cout << "LOAD FROM FILE.\n";
    std::cout << "Enter the name of the file to load from.\n";
    std::string fileName;
    std::cin >> fileName;
    personList.setFileName(fileName);
    personList.readFromFile();
    if (personList.personListSize()==0) {
        pauseFunction("Requested file is void of elements, "
                      "loading unsuccessful.\n");
        clearScreen();
    }
    else{
        std::cout << "List has been loaded from file \"" << fileName <<
        "\" successfully!\n";
        std::cout << "This list contains " << personList.personListSize()
                  << " elements.\n";
        pauseFunction("Press any key to continue.");
        clearScreen();
    }
}

void UserInterface::sortByName(){
    clearScreen();
    std::cout << "Sorted list by name.\n";
    personList.sortByName();
}

void UserInterface::sortByPNr(){
    clearScreen();
    std::cout << "Sorted list by social security number.\n";
    personList.sortByNr();
}

void UserInterface::sortByShoeSize(){
    clearScreen();
    std::cout << "Sort listed by shoe size.\n";
    personList.sortByShoe();
}

UserInterface::UserInterface() = default;
