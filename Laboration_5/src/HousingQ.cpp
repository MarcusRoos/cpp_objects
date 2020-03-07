//
// Created by Marcus Roos on 2020-02-25.
// Mittuniversitet
// StudentID: Maro1904
//

#include <fstream>
#include <limits>
#include "HousingQ.h"

HousingQ::HousingQ() {

}

void HousingQ::run() {
    using namespace std;
    cout << "Enter a filename to load/save the housing queue to: ";
    cin >> filename;
    ifstream file(filename);
    if(!file.is_open())
    {
        ofstream file(filename);
        cout << "No record of such a file, file will be saved.\n";
        cout << "File has been saved under the name of " << filename << ".\n";
    }
    else {
        ifstream file(filename);
        cout << "File " << filename << " currently exists.\n";
        cout << "File " << filename << " has been loaded.\n";
    }
    int choice;
    do {
        choice=Menu();
        switch (choice) {
            case 0:
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
                printPerson();
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
    std::cout << "Case 1 ADD\n";
}

void HousingQ::offerHousing() {
    std::cout << "Case 2 OFFER\n";
}

void HousingQ::printHouses() {
    std::cout << "Case 3 PRINTHOUSE\n";
}

void HousingQ::printPerson() {
    std::cout << "Case 4 PRINTPERSON\n";
}

void HousingQ::removePerson() {
    std::cout << "Case 5 REMOVE\n";
}

void HousingQ::save() {
    std::cout << "Case 6 SAVE\n";
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
