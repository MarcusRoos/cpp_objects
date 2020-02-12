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
    personNumber = std::move(pPersonNumber);
    shoeSize = pShoeSize;
    name = std::move(pName);
    address = std::move(pAddress);
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

void Person::setPersonNumber(std::string pPersonNumber){
    personNumber = std::move(pPersonNumber);
}
void Person::setShoeSize(int pShoeSize){
    shoeSize = pShoeSize;
}
void Person::setNames(Names pName){
    name = std::move(pName);
}
void Person::setAddress(Address pAddress){
    address = pAddress;
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
