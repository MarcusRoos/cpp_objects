//
// Created by Marcus on 2020-01-30.
//

#ifndef DT018G_Person_H
#define DT018G_Person_H

#include "Address.h"
#include "Names.h"
#include <string>
#include <vector>


class Person
{
private:
    Names name;
    Address address;
    std::string personNumber;
    int shoeSize;
public:
    Person(); //Förvald konstruktor
    Person(Names name, Address address, std::string pPersonNumber, int pShoeSize);
    void setName(Names pName);
    void setAddress(Address pAddress);
    void setPersonNumber(std::string pPersonNumber);
    void setShoeSize(int pShoeSize);
    std::string getPersonNumber() const;
    int getShoeSize() const;
    Names getNames() const;
    Address getAddress() const;
};

void printPerson(Person const &person);
void mainProgram();
int mainMenu();
void pauseFunction(const std::string& text);
std::vector<Person>addPerson(std::vector<Person>input);

#endif  // DT018G_PROTOTYPES_H
