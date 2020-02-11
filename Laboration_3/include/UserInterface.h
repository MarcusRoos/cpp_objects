//
// Created by Marcus Roos on 2020-02-11.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_USERINTERFACE_H
#define DT019G_USERINTERFACE_H

#include "PersonList.h"

class UserInterface
{
private:
    void menu();
    void addPerson();
    void printList();
    void saveToFile();
    void readFromFile();
    void sortByName();
    void sortByPNr();
    void sortByShoeSize();

public:
    PersonList run();
}; // End of class Address definition


#endif //DT019G_USERINTERFACE_H
