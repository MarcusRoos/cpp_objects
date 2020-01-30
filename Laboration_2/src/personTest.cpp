//
// Created by Marcus on 2020-01-30.
//
#include "Person.h"
using std::vector;
using std::cout;

int main() {
    vector<Person> pVector;
    Names names1("Olof","Olofsson");
    Address address1("Street 1","157 30","TownCity");
    Person person1(names1, address1, "9784", 41);
    Names names2("Adam","Adamsson");
    Address address2("Street 2","167 50","Stockholm");
    Person person2(names2, address2, "6431", 42);
    Names names3("Stefan","Gren");
    Address address3("Street 3","157 30","New York");
    Person person3(names3, address3, "9753", 43);

    pVector.push_back(person1);
    pVector.push_back(person2);
    pVector.push_back(person3);
    cout << "Vector 1\n";
    printPerson(pVector[0]);
    cout << "Vector 2\n";
    printPerson(pVector[1]);
    cout << "Vector 3\n";
    printPerson(pVector[2]);


    return 0;
}