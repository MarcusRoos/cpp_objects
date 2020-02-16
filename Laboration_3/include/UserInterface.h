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
// Default constructor
    UserInterface();
// Void function to launch program
    void run();
private:
    // Creates object of class PersonList
    PersonList personList;

/**
* Main menu
*
* @param None.
* @return Integer.
*/
    int menu();

/**
* Adds person
*
* @param None.
* @return None.
*/
    void addPerson();

/**
* Prints person
*
* @param None.
* @return None.
*/
    void displayPersons();

/**
* Saves to file
*
* @param None.
* @return None.
*/
    void saveToFile();

/**
* Reads from file
*
* @param None.
* @return None.
*/
    void readFromFile();

/**
* Sorts by name
*
* @param None.
* @return None.
*/
    void sortByName();

/**
* Sorts by social security number
*
* @param None.
* @return None.
*/
    void sortByPNr();

/**
* Sorts by Shoe size
*
* @param None.
* @return None.
*/
    void sortByShoeSize();


}; // End of class UserInterface definition


#endif //DT019G_USERINTERFACE_H
