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

void PersonList::writeToFile(){
    using namespace std;
    ofstream outFile(fileName, ios::out);

    for (auto person : personList){
        outFile << person << endl;
    }
    outFile.close();
}


void PersonList::readFromFile(){
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
}

std::istream &operator>>(std::istream &is, Person &person){

}
