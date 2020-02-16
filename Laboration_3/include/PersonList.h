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
std::vector<Person>personList;
std::string FileName;

public:
    void addPerson(const Person &person);
    Person showPerson(size_t idx);
    void readFromFile();
    void writeToFile();
    int personListSize();
    void sortByName();
    void sortByNr();
    void sortByShoe();
    void setFileName(std::string tmpFile);
    std::string getFileName() const;

};

#endif //DT019G_PERSONLIST_H
