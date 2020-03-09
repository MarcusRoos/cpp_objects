//
// Created by Marcus Roos on 2020-02-25.
// Mittuniversitet
// StudentID: Maro1904
//

#include <fstream>
#include <limits>
#include "HousingQ.h"
#include "Management.h"
#include <algorithm>

HousingQ::HousingQ() {
    amt=0;
    filename="";
}

void HousingQ::run() {
    Item database;
    std::cout << "Enter a filename to load/save the housing queue to: ";
    std::cin >> filename;
    std::ifstream file(filename);
    if(!file.is_open())
    {
        std::ofstream file(filename);
        std::cout << "No record of such a file, file will be created.\n";
        std::cout << "File has been created under the name of " << filename << ".\n";
    }
    else {
        std::ifstream file(filename);
        std::ifstream inFile(filename, std::ios::in);
        Item tmpPerson;
        while (inFile >> tmpPerson) {
            list.enque(tmpPerson);
            amt++;
        }
        std::cout << "File " << filename << " currently exists.\n";
        std::cout << "File " << filename << " has been loaded.\n";
    }
    int choice;
    do {
        choice=Menu();
        switch (choice) {
            case 0:
            default:
                pauseFunction("Program terminated, press any key to exit.");
                break;
            case 1:
                addPerson();
                break;
            case 2:
                offerHousing();
                break;
            case 3:
                printHouses();
                break;
            case 4:
                printInfo();
                break;
            case 5:
                removePerson();
                break;
            case 6:
                save();
                break;
        }
    }while(choice!=0);
}

void HousingQ::addPerson() {
    using namespace std;
    cout << "Case 1 ADD\n";
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
    Item person(names, address, tmpNr, tmpSize);
    list.enque(person);
    amt++;
    printPerson(person);
}

void HousingQ::offerHousing() {
    std::cout << "Case 2 OFFER\n";
    Item person;
        if (list.deque(person)) {
            std::cout << "House offered to next person in queue\n";
            std::cout << "**********************************************\n";
            printPerson(person);
            std::cout << "Person was offered housing\n";
            amt--;
        } else
            std::cout << std::endl << "The list is empty!\n";
}

void HousingQ::printHouses() {
    std::cout << "Case 3 PRINTHOUSE\n";
    std::cout << "The housing queue contains " << amt << " persons.\n";
    int tmpCount=0;
    if (list.isEmpty())
        std::cout << "The list is empty!\n";
    for (auto & p : list){
        tmpCount++;
        std::cout << "Placement " << tmpCount << "\n";
        printPerson(p);
    }
}

void HousingQ::printInfo() {
    std::cout << "Case 4 PRINTPERSON\n";
    std::cout << "Enter the persons social security number to search for: ";
    std::string PNr, tmp;
    int tmpCount=0;
    std::cin >> PNr;
    if (list.isEmpty())
        std::cout << "The list is empty!\n";
    for (auto & p : list){
        tmp = p.getPersonNumber();
        tmpCount++;
        tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());
        tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
        if (tmp == PNr) {
            std::cout << "Placement: "<< tmpCount << std::endl;
            printPerson(p);
        }
    }
}

void HousingQ::removePerson() {
    std::cout << "Enter the persons social security number to search for: ";
    std::string PNr, tmp;
    int tmpCount=0;
    std::cin >> PNr;
    if (list.isEmpty())
        std::cout << "The list is empty!\n";
    for (auto & p : list){
        tmp = p.getPersonNumber(); /* Keeps crashing here if trying to delete
 * the first node. I have no idea why.*/
        tmpCount++;
        tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());
        tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
        if (tmp == PNr) {
            printPerson(p);
            if (list.del(p)) {
                std::cout << "Placement: " << tmpCount << std::endl;
                std::cout << "tmp: " << tmp << " PNr: " << PNr << std::endl;
                break;
            }
        }
    }
}

void HousingQ::save() {
    std::cout << "File \"" << filename << "\" has been saved\n";
    std::ofstream outFile(filename, std::ios::out);
    for (const auto& person : list){
        outFile << person << std::endl;
    }
    outFile.close();
}

int HousingQ::Menu() {
    using namespace std;
    cout << "**********************************************\n";
    cout << "*       0. Exit program                      *\n";
    cout << "*       1. Add person to housing queue       *\n";
    cout << "*       2. Offer housing to person           *\n";
    cout << "*       3. Display housing queue             *\n";
    cout << "*       4. Display person information        *\n";
    cout << "*       5. Remove person from housing queue  *\n";
    cout << "*       6. Save housing queue                *\n";
    cout << "**********************************************\n";
    cout << "Input a number from available choices in the menu: ";
    int choice=0;
    bool loop;
    do {
         cin >> choice;
        if (cin.fail() || choice < 0 || choice > 6) {
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