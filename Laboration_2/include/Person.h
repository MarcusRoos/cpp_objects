//
// Created by Marcus on 2020-01-30.
//

#ifndef DT018G_Person_H
#define DT018G_Person_H

#include "Address.h"
#include "Names.h"
#include <string>
#include <vector>
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class Person
 */
class Person
{
private: // Class members
    Names name; // Type Names, called name
    Address address; // Type Address, called address
    std::string personNumber; // Type string called personNumber
    int shoeSize; // Type integer called shoeSize
public:
    Person(); //Förvald konstruktor
    // Initialized constructor, param name, address, pPersonNumber & pShoeSize
    Person(Names name, Address address, std::string pPersonNumber, int pShoeSize);
    std::string getPersonNumber() const; // Return string, no param
    int getShoeSize() const; // Return int, no param
    Names getNames() const; // Return Names, no param
    Address getAddress() const; // Return Address, no param
}; // End of class Person definition

void mainProgram(); // Return nothing, param, starts main program

#endif // DT018G_PROTOTYPE&S_H
