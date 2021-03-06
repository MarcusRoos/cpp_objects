//
// Created by Marcus on 2020-01-30.
//

#include "Names.h"

#include <utility>
#include <cstring>

using std::cout;
using std::endl;

// Default constructor
Names::Names()
{
    firstName = "N/A"; lastName = "N/A";
}

// Initilizing constructor
Names::Names(std::string pFirstName, std::string pLastName)
{
    firstName = std::move(pFirstName); lastName = std::move(pLastName);
}

// Sets first name
void Names::setFirstName(std::string pFirstName)
{
    firstName = std::move(pFirstName);
}

// Sets last name
void Names::setLastName(std::string pLastName)
{
    lastName = std::move(pLastName);
}

// Gets first name
std::string Names::getFirstName() const
{
    return "Firstname: "+firstName;
}

// Gets last name
std::string Names::getLastName() const
{
    return "Surname: "+lastName;
}

// Prints class names
void printNames(Names const &names)
{
    cout << endl;
    cout << "NAME:" << endl;
    cout << "First name: " << names.getFirstName() << endl;
    cout << "Last name: " << names.getLastName() << endl;
}

// Defines operator <<, used for out stream
std::ostream &operator<<(std::ostream &os, const Names &names){
    os << names.getFirstName() << '|' << names.getLastName() << '|';

    return os;
}

// Defines operator >>, used for in stream
std::istream &operator>>(std::istream &is, Names &names){
    std::string tmpString;
    getline(is,tmpString,'|');
    names.setFirstName(tmpString);
    getline(is,tmpString,'|');
    names.setLastName(tmpString);

    return is;
}

// Defines operator <
bool Names::operator < (const Names& a) const
{
    if (lastName == a.lastName) { // Comparison, if true;
        return firstName < a.firstName; // Return first name in descending order
    }
    else {
        return lastName < a.lastName; // If not true, return last name
    }
}

// Defines operator ==
bool Names::operator == (const Names& a) const
{
    return lastName == a.lastName && firstName == a.firstName; // If equals true
}