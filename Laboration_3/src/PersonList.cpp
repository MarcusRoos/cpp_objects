//
// Created by Marcus Roos on 2020-02-11.
// Mittuniversitet
// StudentID: Maro1904
//


#include "PersonList.h"
#include <iostream>
#include <utility>
#include <algorithm>

// Add person to vector
void PersonList::addPerson(const Person& person)
{
    personList.push_back(person);
}

// Prints person list of persons
Person PersonList::showPerson(size_t idx){
    if (idx<personList.size()){
        return personList[idx];
    }
    else { // If index out of bounds, throw error
        throw std::out_of_range("Index is out of bounds");
    }
}

// Writes to file
void PersonList::writeToFile(){
    using namespace std;
    ofstream outFile(FileName, ios::out);

    for (const auto& person : personList){
        outFile << person << endl;
    }
    outFile.close();
}

// Reads from file
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

// Returns size of vector
int PersonList::personListSize() {
    return personList.size();
}

// Sets file name
void PersonList::setFileName(std::string tmpFile) {
    FileName = std::move(tmpFile);
}

// Gets file name, however unused for this task
std::string PersonList::getFileName() const
{
    return FileName;
}

// Sorts by name
void PersonList::sortByName(){
    std::sort(personList.begin(), personList.end());
}

// Sorts by social security number
void PersonList::sortByNr(){
    sort(personList.begin(), personList.end(),
            [](const Person& a, const Person& b) {
        return a.getPersonNumber() < b.getPersonNumber();
    });
}

// Sorts by shoe size
void PersonList::sortByShoe(){
    sort(personList.begin(), personList.end(),
            [](const Person& a, const Person& b) {
        return a.getShoeSize() < b.getShoeSize();
    });
}

