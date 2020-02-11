//
// Created by Marcus on 2020-01-30.
//

#ifndef DT018G_Names_H
#define DT018G_Names_H
#include <string>
#include <iostream>

//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
/**
 Class Names

 Registers the name belonging to a person, the members of this class would
 be first and last name. The public members are used to both set these
 class members, as well as get them, to either give them a value or to show
 this value.
 */
class Names
{
private:
    std::string firstName, lastName; // Class members of type string
public:
    /**
    * Default constructor of the class Names
    *
    * @param None.
    * @return None.
    */
    Names();
/**
 * Constructor for initialization of class Names
 *
 * @param String pFirstName, pLastName.
 * @return None.
 */
    Names(std::string pFirstName, std::string pLastName);

    /**
    * Sets value for class member firstName
    *
    * @param String pFirstName.
    * @return None.
    */
    void setFirstName(std::string pFirstName);

    /**
    * Sets value for class member lastName
    *
    * @param String pLastName.
    * @return None.
    */
    void setLastName(std::string pLastName);

    /**
    * Returns value for class member firstName
    *
    * @param None.
    * @return firstName.
    */
    std::string getFirstName() const;

    /**
    * Returns value for class member lastName
    *
    * @param None.
    * @return lastName.
    */
    std::string getLastName() const;
}; // End of class Names definition

/**
 * Prints the class Names and its class members.
 *
 * @param Constant class Names.
 * @return None.
 */
void printNames(Names const &names);

std::ostream &operator<<(std::ostream &os, const Names &names);
std::istream &operator>>(std::istream &is, Names &names);
#endif