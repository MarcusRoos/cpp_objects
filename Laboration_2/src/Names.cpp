//
// Created by Marcus on 2020-01-30.
//

#include "Names.h"

using std::cout;
using std::endl;

Names::Names()
{
    firstName = "N/A"; lastName = "N/A";
}

Names::Names(std::string pFirstName, std::string pLastName)
{
    firstName = pFirstName; lastName = pLastName;
}

void Names::setFirstName(std::string pFirstName)
{
    firstName = pFirstName;
}

void Names::setLastName(std::string pLastName)
{
    lastName = pLastName;
}

std::string Names::getFirstName() const
{
    return firstName;
}

std::string Names::getLastName() const
{
    return lastName;
}

void printNames(Names const &names)
{
    cout << endl;
    cout << "Namelist:" << endl;
    cout << "First name: " << names.getFirstName() << endl;
    cout << "Last name: " << names.getLastName() << endl;
}