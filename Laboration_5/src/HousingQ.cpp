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
/**
The default constructor, will initialize amt by 0, and filename blank.
*/
HousingQ::HousingQ() {
    amt=0;
    filename="";
}
/**
The run function, the user will be prompted to insert a filename, if said
 file name exists the file will be loaded in using the overloaded >> operator
 from the Person class. If the file does not exist it will be created.
 Afterwards the run function will call a menu where the user will be presented
 by a list of tasks the program may perform. Depending on what the user insert
 the value will be sent back from the menu into a local variable and call
 the appropriate switch case. Within the case the relevant function will be
 called.
*/
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

/**
Function addPerson(), will allow a person to enter a persons credentials to
 be added to the list. The function is a copy paste from the previous
 "laboration 3" with only minor tweaks to cater to the needs of a list instead
 of a vector. All relevant user input will be validated, and if not valid will
 enter a loop until input is acceptable. For each person added the amt
 member of HousingQ will increase by 1 to accommodate for a new node spawning
 inside the list.
*/
void HousingQ::addPerson() {
    using namespace std;
    cout << "Add a person.\n";
    cout << "**********************************************\n";
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
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> tmpNr;
    }
    tmpNr += '|';
    std::cout << "Enter the persons shoe size.\n";
    int tmpSize=0;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> tmpSize;
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
    cout << "Person added successfully!\n";
}

/**
Function offerHousing() will offer a first person in the queue a house.
 If the list is empty the function will inform the user, otherwise it will
 call another function to deque the first person in the queue and inform the
 user which person got a house.
*/
void HousingQ::offerHousing() {
    std::cout << "Offer housing.\n";
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

/**
Function printHouses(), will print the entire list of persons currently
 in the housing queue, if the queue is empty the user will be informed.
 Otherwise every single person in the queue will be printed with all
 their information as well as their placement within the queue.
*/
void HousingQ::printHouses() {
    std::cout << "Print information.\n";
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

/**
Function printInfo(), will look a specific person in the queue, the user will
 be asked to enter a social security number as search key. If a match is
 found the information about this person will be printed on the screen as well
 as their placement in the queue. If the queue is empty the user will be
 informed.
*/
void HousingQ::printInfo() {
    std::cout << "Look up a person.\n";
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

/**
Function removePerson(), will remove a specific person from the queue. The
 user will be asked to enter a persons social security number and if
  a match is found the person will be deleted from the queue regardless of
  their current placement. If the list is empty the user will be informed,
  otherwise the person whose social security number was previously
  entered will be deleted and the user will be informed.
*/
void HousingQ::removePerson() {
    std::cout << "Delete a person.\n";
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
        if (PNr == tmp) {
            printPerson(p);
            if (list.del(p)) {
                std::cout << "Person deleted." << std::endl;
                amt--;
                return;
            }
        }
    }
}

/**
Function save(), will save the current queue to the computer using the
 overloaded >> operator from the Person class. Filename will be determined
 depending on what the user entered at the start of the program.
*/
void HousingQ::save() {
    std::cout << "File \"" << filename << "\" has been saved\n";
    std::ofstream outFile(filename, std::ios::out);
    for (const auto& person : list){
        outFile << person << std::endl;
    }
    outFile.close();
}

/**
Function Menu(), prints a menu for the user to see what they are selecting,
 requests an input in form of an integer from the user which will be
 validated. If the number is not within the interval 0<6 the user
 will be informed and requested to try again. Once an acceptable integer
 has been entered the menu will return this value.
*/
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