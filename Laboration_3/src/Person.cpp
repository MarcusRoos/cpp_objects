//
// Created by Marcus on 2020-01-30.
//
#include "Person.h"
#include "Management.h"
#include <iostream>
#include <utility>

using std::cout;
using std::endl;

Person::Person()
{
    personNumber = "";
    shoeSize = 0;
}

Person::Person(Names pName, Address pAddress, std::string pPersonNumber, int pShoeSize)
{
    name = std::move(pName);
    address = std::move(pAddress);
    personNumber = std::move(pPersonNumber);
    shoeSize = pShoeSize;
}

Names Person::getNames() const
{
    return name;
}
std::string Person::getPersonNumber() const
{
    return personNumber;
}

int Person::getShoeSize() const
{
    return shoeSize;
}

Address Person::getAddress() const
{
    return address;
}
void Person::setNames(Names pName){
    name = std::move(pName);
}
void Person::setPersonNumber(std::string pPersonNumber){
    personNumber = std::move(pPersonNumber);
}
void Person::setShoeSize(int pShoeSize){
    shoeSize = pShoeSize;
}
void Person::setAddress(Address pAddress){
    address = std::move(pAddress);
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

bool Person::operator < (const Person& a) const
{
    if (name == a.name)
        return address < a.address;
    else
        return (name < a.name);
}

bool Person::operator == (const Person& a) const
{
    return true;
}