//
// Created by Marcus Roos on 2020-02-11.
// Mittuniversitet
// StudentID: Maro1904
//


#include "PersonList.h"
#include "Management.h"
#include <iostream>
#include <utility>
#include <algorithm>


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
    while (inFile >> tmpPerson) {
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
    std::sort(personList.begin(), personList.end());
}
void PersonList::sortByNr(){
    sort(personList.begin(), personList.end(), [](const Person& a, const Person& b) {
        return a.getPersonNumber() < b.getPersonNumber();
    });
}

void PersonList::sortByShoe(){
    sort(personList.begin(), personList.end(), [](const Person& a, const Person& b) {
        return a.getShoeSize() < b.getShoeSize();
    });
}

