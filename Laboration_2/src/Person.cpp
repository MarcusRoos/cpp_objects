//
// Created by Marcus on 2020-01-30.
//
#include "Person.h"
#include <iostream>

using std::cout;
using std::endl;

void mainProgram(){
    std::vector<Person> pVector;
    Names names1("Olof","Olofsson");
    Address address1("Street 1","157 30","TownCity");
    Person person1(names1, address1, "9784", 41);
    Names names2("Adam","Adamsson");
    Address address2("Street 2","167 50","Stockholm");
    Person person2(names2, address2, "6431", 42);
    Names names3("Stefan","Gren");
    Address address3("Street 3","157 30","New York");
    Person person3(names3, address3, "9753", 43);

    size_t vecSize=0;
    pVector.push_back(person1);
    vecSize++;
    pVector.push_back(person2);
    vecSize++;
    pVector.push_back(person3);
    vecSize++;

    int choice=0;
    bool loop=true;
    while (loop) {
        choice = mainMenu();
        switch (choice) {
            case 1:
                std::cout << "1\n";
                pVector = addPerson(pVector);
                vecSize++;
                break;
            case 2:
                std::cout << "2\n";
                for (const auto &i : pVector) {
                    printPerson(i);
                }
                break;
            case 3:
                std::cout << "3\n";
                loop = false;
            default:
                break;
        }
    }
}

int mainMenu(){
    cout << "What would you like to do?\n\n";
    cout << "1. Add a person.\n";
    cout << "2. List all persons.\n";
    cout << "3. Quit.\n";
    int choice=0;
    std::cin >> choice;
    while (choice<1 || choice>3){
        std::cout << "Wrong input\n";
        std::cin >> choice;
    }
    return choice;
}

std::vector<Person>addPerson(std::vector<Person>input){

    std::cout << "Enter the persons first name.\n";
    std::string firstName;
    std::cin >> firstName;
    std::cout << "Enter the persons last name.\n";
    std::string lastName;
    std::cin >> lastName;
    std::cout << "Enter the persons street address.\n";
    std::string street;
    std::cin >> street;
    std::cout << "Enter the persons postcode.\n";
    std::string postcode;
    std::cin >> postcode;
    std::cout << "Enter the persons city.\n";
    std::string city;
    std::cin >> city;
    std::cout << "Enter the persons social security number (4 digits).\n";
    std::string personNumber;
    std::cin >> personNumber;
    std::cout << "Enter the persons shoesize.\n";
    int shoeSize;
    std::cin >> shoeSize;

    Names names(firstName,lastName);
    Address address(street,postcode,city);
    Person person(names, address, personNumber, shoeSize);
    input.push_back(person);

 return {std::move(input)};
}

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

void pauseFunction(const std::string& text){ /* Function used when program
 * should wait for user input before it continues */
    std::cout << text; // Prints function parameter on screen
    std::cin.clear(); // Clear stream
    std::cin.sync(); // Synchronizes the input stream
    std::cin.get(); // Waits for user input before it continues
    std::cin.clear(); // Clear stream once again to remove leftovers
    std::cin.sync(); // Synchronizes the input stream
}