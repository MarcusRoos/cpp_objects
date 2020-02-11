//
// Created by Marcus on 2020-01-30.
//

#include "Names.h"

#include <utility>

using std::cout;
using std::endl;

Names::Names()
{
    firstName = "N/A"; lastName = "N/A";
}

Names::Names(std::string pFirstName, std::string pLastName)
{
    firstName = std::move(pFirstName); lastName = std::move(pLastName);
}

void Names::setFirstName(std::string pFirstName)
{
    firstName = std::move(pFirstName);
}


void Names::setLastName(std::string pLastName)
{
    lastName = std::move(pLastName);
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
    cout << "NAME:" << endl;
    cout << "First name: " << names.getFirstName() << endl;
    cout << "Last name: " << names.getLastName() << endl;
}

std::ostream &operator<<(std::ostream &os, const Names &names){
    os << names.getFirstName() << '|' << names.getLastName() << '|';

    return os;
}

std::istream &operator>>(std::istream &is, Names &names){
    std::string tmpString;
    getline(is,tmpString,'|');
    names.setFirstName(tmpString);
    getline(is,tmpString,'|');
    names.setLastName(tmpString);

    return is;
}