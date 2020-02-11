//
// Created by Marcus Roos on 2020-02-11.
// Mittuniversitet
// StudentID: Maro1904
//


#include "PersonList.h"
#include <iostream>


void PersonList::addPerson(const Person& person)
{
    personList.push_back(person);
}

Person PersonList::showPerson(size_t idx){
    if (idx<personList.size()){
        return personList[idx];
    }
    else {
        throw std::out_of_range("Index is out of bounds");
    }
}

void PersonList::writeToFile(std::string& fileName){
    using namespace std;
    ofstream outFile(fileName, ios::out);

    for (const auto& person : personList){
        outFile << person << endl;
    }
    outFile.close();
}


void PersonList::readFromFile(std::string& fileName){
    using namespace std;
ifstream inFile(fileName, ios::in);
personList.clear();

Person tmpPerson;
while (inFile >> tmpPerson){
    personList.push_back(tmpPerson);
}
inFile.close();
}

std::ostream &operator<<(std::ostream &os, const Person &person){
    os << person.getAddress();
    os << person.getNames();
    os << person.getPersonNumber();
    os << person.getShoeSize();
    return os;
}

std::istream &operator>>(std::istream &is, Person &person){
    std::string tmpString;
    Address tmpAddress;
    Names tmpNames;
    getline(is,tmpString,'|');
    person.setAddress(tmpAddress);
    getline(is,tmpString,'|');
    person.setNames(tmpNames);
    getline(is,tmpString,'|');
    person.setPersonNumber(tmpString);
    int tmpInt;
    is >> tmpInt;
    is.get();
    person.setShoeSize(tmpInt);

    return is;
}
