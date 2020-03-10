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
    // Class members
    QList list; // Creates object of QList
    int amt; // Counter to keep track of how big the list is
    std::string filename; // Name of file to save to/load from

/**
* addPerson()
* Lets user input data to add a person to the queue
* @param None.
* @return None.
*/
    void addPerson();
    /**
* offerHousing()
* Deque the oldest person in the queue by offering them a house
* @param None.
* @return None.
*/
    void offerHousing();
    /**
* printHouses()
* Prints all people in the queue
* @param None.
* @return None.
*/
    void printHouses();
    /**
* printInfo()
* Lets user input social security number to look up a specific person,
     * afterwards prints all info belonging to this person.
* @param None.
* @return None.
*/
    void printInfo();
    /**
* removePerson()
* Removes a person from the queue specified by users input, social security nr
* @param None.
* @return None.
*/
    void removePerson();
    /**
* save()
* Saves the list to the file, filename is determined at the start of the program
* @param None.
* @return None.
*/
    void save();
public:
    /**
* Constructor for HousingQ
* Sets values of the members
* @param None.
* @return None.
*/
    HousingQ();
    /**
* run()
* Handles all the function calling, contains a switch to determine which function
     * to call
* @param None.
* @return None.
*/
    void run();
    /**
* Menu()
* Added for clearness, the above run() function will call menu and print
     * out the options available, user inputs an integer which is sent
     * back to the run() function to determine which function to call
* @param None.
* @return Integer.
*/
    int Menu(); // Menu function, added a separate one to make it cleaner.
};

#endif //DT019G_HOUSINGQ_H
