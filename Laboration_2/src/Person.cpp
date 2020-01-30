//
// Created by Marcus on 2020-01-30.
//
#include "Person.h"
#include <iostream>
using std::cout;
using std::endl;

Person::Person()
{
    personNumber = "";
    shoeSize = 0;
}

Person::Person(Names pName, Address pAddress, std::string pPersonNumber, int pShoeSize)
{
    personNumber = pPersonNumber;
    shoeSize = pShoeSize;
    name = pName;
    address = pAddress;
}
void Person::setName(Names pNames)
{
    name = pNames;
}
void Person::setAddress(Address pAddress)
{
    address = pAddress;
}
void Person::setPersonNumber(std::string pPersonNumber)
{
    personNumber = pPersonNumber;
}

void Person::setShoeSize(int pShoeSize)
{
    shoeSize = pShoeSize;
}

std::string Person::getPersonNumber() const
{
    return personNumber;
}

int Person::getShoeSize() const
{
    return shoeSize;
}
Names Person::getNames() const
{
    return name;
}
Address Person::getAddress() const
{
    return address;
}

void printPerson(Person const &Person)
{
    cout << "PERSON:";
    printNames(Person.getNames());
    printAddress(Person.getAddress());
    cout << "\n";
    cout << "Social Security Number: " << Person.getPersonNumber() << endl;
    cout << "Shoe size: " << Person.getShoeSize() << endl << endl;

}
