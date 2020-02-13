//
// Created by Marcus Roos on 2020-02-11.
// Mittuniversitet
// StudentID: Maro1904
//


#include "PersonList.h"
#include "Management.h"
#include <iostream>
#include <utility>


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
    ofstream outFile(FileName, ios::out);

    for (const auto& person : personList){
        outFile << person << endl;
    }
    outFile.close();
}


void PersonList::readFromFile(){
    using namespace std;
ifstream inFile(FileName, ios::in);
personList.clear();

Person tmpPerson;

while (inFile >> tmpPerson){
    personList.push_back(tmpPerson);
}

inFile.close();
}

int PersonList::personListSize() {
    return personList.size();
}

void PersonList::setFileName(std::string tmpFile) {
    FileName = std::move(tmpFile);
}

std::string PersonList::getFileName() const
{
    return FileName;
}

void PersonList::sortByName(){

}
void PersonList::sortByNr(){

}
void PersonList::sortByShoe(){

}

std::ostream &operator<<(std::ostream &os, const Person &person){
    os << person.getNames();
    os << person.getAddress();
    os << person.getPersonNumber();
    os << person.getShoeSize();
    return os;
}

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
