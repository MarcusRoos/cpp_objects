//
// Created by Marcus on 2020-01-30.
//
#include "Person.h"
using std::vector, std::cout;

int main() {
    vector<Person> pVector;
    Names names1("Olof","Olofsson");
    Address address1("Street 1","157 30","TownCity");
    Person person1(names1, address1, "9784", 41);
    Names names2("Adam","Adamsson");
    Address address2("Street 2","167 50","Stockholm");
    Person person2(names2, address2, "6431", 42);
    Names names3("Olof","Olofsson");
    Address address3("Street 3","157 30","New York");
    Person person3(names2, address2, "9753", 43);

    pVector[0] = person1;
    pVector[1] = person2;
    pVector[2] = person3;

    cout << person1;

    return 0;
}