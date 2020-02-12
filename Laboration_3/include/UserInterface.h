//
// Created by Marcus Roos on 2020-02-11.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_USERINTERFACE_H
#define DT019G_USERINTERFACE_H

#include "PersonList.h"
#include "Management.h"

class UserInterface
{
public:
    UserInterface();
    void run();
private:
    PersonList personList;
    int menu();
    void addPerson();
    void displayPersons();
    void saveToFile();
    void readFromFile();
    void sortByName();
    void sortByPNr();
    void sortByShoeSize();


}; // End of class Address definition


#endif //DT019G_USERINTERFACE_H
