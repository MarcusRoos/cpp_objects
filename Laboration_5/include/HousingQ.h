//
// Created by Marcus Roos on 2020-02-25.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT019G_HOUSINGQ_H
#define DT019G_HOUSINGQ_H

#include "queue.h"
#include <string>
#include "Management.h"
#include "Person.h"
#include <iomanip>

class HousingQ{
private:
    QList list;
    int amt;
    std::string filename;
    void addPerson();
    void offerHousing();
    void printHouses();
    void printInfo();
    void removePerson();
    void save();
public:
    HousingQ();
    void run();
    int Menu(); // Menu function, added a separate one to make it cleaner.
};

#endif //DT019G_HOUSINGQ_H
