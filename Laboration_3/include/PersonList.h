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

public:
    void addPerson(const Person &person);
    Person showPerson(size_t idx);
    void readFromFile(std::string& fileName);
    void writeToFile(std::string& fileName);
};

std::ostream &operator<<(std::ostream &os, const Person &person);
std::istream &operator>>(std::istream &is, Person &person);

#endif //DT019G_PERSONLIST_H
