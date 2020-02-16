//
// Created by Marcus on 2020-01-30.
//
#include "Person.h"
#include "Management.h"
#include <iostream>
#include <utility>

using std::cout;
using std::endl;

// Default constructor
Person::Person()
{
    personNumber = "";
    shoeSize = 0;
}

// Initilizing constructor
Person::Person(Names pName, Address pAddress, std::string pPersonNumber, int pShoeSize)
{
    name = std::move(pName);
    address = std::move(pAddress);
    personNumber = std::move(pPersonNumber);
    shoeSize = pShoeSize;
}

// Gets name
Names Person::getNames() const
{
    return name;
}

// Gets social security number
std::string Person::getPersonNumber() const
{
    return personNumber;
}

// Gets shoe size
int Person::getShoeSize() const
{
    return shoeSize;
}

// Gets address
Address Person::getAddress() const
{
    return address;
}

// Sets name
void Person::setNames(Names pName){
    name = std::move(pName);
}

// Sets social security number
void Person::setPersonNumber(std::string pPersonNumber){
    personNumber = std::move(pPersonNumber);
}

// Sets shoe size
void Person::setShoeSize(int pShoeSize){
    shoeSize = pShoeSize;
}

// Sets address
void Person::setAddress(Address pAddress){
    address = std::move(pAddress);
}

// Prints class person
void printPerson(Person const &Person)
{
    cout << "PERSON:";
    printNames(Person.getNames());
    printAddress(Person.getAddress());
    cout << "\n";
    cout << "Social Security Number: " << Person.getPersonNumber() << endl;
    cout << "Shoe size: " << Person.getShoeSize() << endl << endl;
}

// Defines operator <
bool Person::operator < (const Person& a) const {
    if (name == a.name) { // Comparison, if true;
        return address < a.address; // Return address in descending order
    } else {
        return name < a.name; // If not true, return name
    }
}

// Defines operator ==
bool Person::operator == (const Person& a) const
{
    return true; // Returns true if comparison is a match
}

// Defines operator <<, used for out stream
std::ostream &operator<<(std::ostream &os, const Person &person){
    os << person.getNames();
    os << person.getAddress();
    os << person.getPersonNumber();
    os << person.getShoeSize();
    return os;
}

/** Defines operator >>, used for in stream, will go through string until
 * it finds a '|', will then set the class object and keep searching the
 * string. **/
std::istream &operator>>(std::istream &is, Person &person){
    std::string tmpString;
    Address tmpAddress;
    Names tmpNames;
    getline(is,tmpString,'|');
    tmpNames.setFirstName(tmpString);
    getline(is,tmpString,'|');
    tmpNames.setLastName(tmpString);
    getline(is,tmpString,'|');
    tmpAddress.setStreet(tmpString);
    getline(is,tmpString,'|');
    tmpAddress.setPostcode(tmpString);
    getline(is,tmpString,'|');
    tmpAddress.setCity(tmpString);
    getline(is,tmpString,'|');
    person.setNames(tmpNames);
    person.setAddress(tmpAddress);
    tmpString += '|';
    person.setPersonNumber(tmpString);
    int tmpInt;
    is >> tmpInt;
    is.get();
    person.setShoeSize(tmpInt);

    return is;
}