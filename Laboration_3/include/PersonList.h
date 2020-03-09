//
// Created by Marcus Roos on 2020-02-11.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_PERSONLIST_H
#define DT019G_PERSONLIST_H
#include <string>
#include <vector>
#include <Person.h>
#include <fstream>

class PersonList {
private:
std::vector<Person>personList; // Class member, type vector of class Person
std::string FileName; // Class member, type string

public:
/**
* Adds person to vector
*
* @param Constant reference to class Person.
* @return None.
*/
    void addPerson(const Person &person);

/**
* Prints vector
*
* @param Index of type size_t.
* @return Person.
*/
    Person showPerson(size_t idx);

/**
* Reads from file
*
* @param None.
* @return None.
*/
    void readFromFile();

/**
* Writes to file
*
* @param None.
* @return None.
*/
    void writeToFile();
    int personListSize();

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
    void sortByNr();

/**
* Sorts by shoe size
*
* @param None.
* @return None.
*/
    void sortByShoe();

/**
* Sets file name
*
* @param String.
* @return None.
*/
    void setFileName(std::string tmpFile);

/**
* Gets file name, however never used for this task
*
* @param None.
* @return String.
*/
    std::string getFileName() const;

}; // End of class PersonList definition

#endif //DT019G_PERSONLIST_H
