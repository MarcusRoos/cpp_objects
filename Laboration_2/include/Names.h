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
 */
class Names
{
private:
    std::string firstName, lastName; // Class members
public:
    Names(); //Pre-determined constructor
    // Initialized constructor, take param firstName and lastName
    Names(std::string pFirstName, std::string pLastName);
    void setFirstName(std::string pFirstName); // Return nothing, param string
    void setLastName(std::string pLastName); // Return nothing, param string
    std::string getFirstName() const; // Return string, no param
    std::string getLastName() const; // Return string, no param
}; // End of class Names definition

void printNames(Names const &names); // Returns nothing, param class Names
#endif