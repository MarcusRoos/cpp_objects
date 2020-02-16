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

 Registers the name belonging to a person, the members of this class would
 be person number and shoe size, as well as their names and address pulled from
 two other classes called Address and Names.
 The public members are used to both set these
 class members, as well as get them, to either give them a value or to show
 this value. This is done strictly by a constructor which initialize these
 class members and assign their values to the class.
 */
class Person
{
private: // Class members
    Names name; // Type Names, called name
    Address address; // Type Address, called address
    std::string personNumber; // Type string called personNumber
    int shoeSize; // Type integer called shoeSize
public:

/**
* Default constructor of the class Person
*
* @param None.
* @return None.
*/
    Person();
/**
* Constructor for initialization of class Person
*
* @param String name, address, pPersonNumber, pShoeSize.
* @return None.
*/
    Person(Names name, Address address, std::string pPersonNumber, int pShoeSize);

/**
* Returns value for class member personNumber
*
* @param None.
* @return personNumber.
*/
    std::string getPersonNumber() const;

/**
* Returns value for class member shoeSize
*
* @param None.
* @return shoeSize.
*/
    int getShoeSize() const;

/**
* Returns value for class member name
*
* @param None.
* @return name.
*/
    Names getNames() const;

/**
* Returns value for class member address
*
* @param None.
* @return address.
*/
    Address getAddress() const;
    void setPersonNumber(std::string pPersonNumber);
    void setShoeSize(int pShoeSize);
    void setNames(Names pName);
    void setAddress(Address pAddress);

    bool operator < (const Person& a) const;
    bool operator == (const Person& a) const;

}; // End of class Person definition
std::ostream &operator<<(std::ostream &os, const Person &person);
std::istream &operator>>(std::istream &is, Person &person);
/**
 * mainProgram, will bind together all the functions and act as a switch to
 * call functions in between each other.
 *
 * @param None.
 * @return None.
 */
void mainProgram();
#endif
