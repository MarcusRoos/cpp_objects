//
// Created by Marcus on 2020-01-30.
//
#include "Person.h"
#include "Management.h"
#include <iostream>
#include <utility>

using std::cout;
using std::endl;

void mainProgram(){
    // Create a vector of objects from class Person, name vector pVector
    std::vector<Person> pVector;
    // Give values to datamembers, store in 3 different objects
    Names names1("Olof","Olofsson");
    Address address1("Street 1","157 30","TownCity");
    Person person1(names1, address1, "9784", 41);
    Names names2("Adam","Adamsson");
    Address address2("Street 2","167 50","Stockholm");
    Person person2(names2, address2, "6431", 42);
    Names names3("Stefan","Gren");
    Address address3("Street 3","157 30","New York");
    Person person3(names3, address3, "9753", 43);

    // Store each object within the vector as 3 elements
    pVector.push_back(person1);
    pVector.push_back(person2);
    pVector.push_back(person3);

    // Loop to ensure input for the switch
    int choice=0;
    bool loop=true;
    while (loop) {
        // Calls main menu, loads return into int choice, go to relevant case
        choice = mainMenu();
        switch (choice) {
            case 1:
                // If 1 is chosen call function addPerson and store in pVector
                // Call by giving pVector as param
                pVector = addPerson(pVector);
                break;
            case 2:
                // If 2 is chosen, call print function, give pVector as param
                print(pVector);
                break;
            case 3:
                // If 3 is chosen, break loop and quit program
                loop = false;
            default:
                break;
        }
    }
}

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
