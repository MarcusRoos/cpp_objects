//
// Created by Marcus on 2020-02-01.
//

#include "Management.h"
using std::cout;

int mainMenu(){
    cout << "What would you like to do?\n\n";
    cout << "1. Add a person.\n";
    cout << "2. List all persons.\n";
    cout << "3. Quit.\n";
    int choice=0;
    std::cin >> choice;
    while (choice<1 || choice>3){
        std::cout << "Wrong input\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;
    }
    return choice;
}

std::vector<Person>addPerson(std::vector<Person>input){

    std::cout << "Enter the persons first name.\n";
    std::string firstName;
    firstName=validate(firstName);
    std::cout << "Enter the persons last name.\n";
    std::string lastName;
    lastName=validate(lastName);
    std::cout << "Enter the persons street address.\n";
    std::string street;
    std::getline(std::cin >> std::ws, street);
    std::cout << "Enter the persons postcode (5 characters).\n";
    std::string postcode;
    std::cin >> postcode;
    while (postcode.length() <5 || postcode.length() >5){
        std::cout << "Wrong input.\n";
        std::cin >> postcode;
    }
    std::cout << "Enter the persons city.\n";
    std::string city;
    city=validate(city);
    std::cout << "Enter the persons social security number (4 characters).\n";
    std::string personNumber;
    std::cin >> personNumber;
    while (personNumber.length() <4 || personNumber.length() >4){
        std::cout << "Wrong input.\n";
        std::cin >> personNumber;
    }
    std::cout << "Enter the persons shoesize.\n";
    int shoeSize;
    std::cin >> shoeSize;
    while (std::cin.fail() || shoeSize<15 || shoeSize>50) { // If fail, request new input
        cout << "You did not enter a positive int, please retry.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> shoeSize;
    }

    Names names(firstName,lastName);
    Address address(street,postcode,city);
    Person person(names, address, personNumber, shoeSize);
    input.push_back(person);

    return {std::move(input)};
}

void print(const std::vector<Person>&printVec){
    for (const auto &i : printVec) {
        printPerson(i);
    }
}