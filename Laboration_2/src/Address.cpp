//
// Created by Marcus on 2020-01-30.
//

#include "Address.h"

using std::cout;
using std::endl;

Address::Address() // Default constructor
{
    street = "N/A"; postcode = "N/A"; city="N/A";
}

// Constructor for initialization of class members
Address::Address(std::string pStreet, std::string pPostcode, std::string pCity)
{
    street = pStreet; postcode = pPostcode; city = pCity;
}

// Sets value from parameter
void Address::setStreet(std::string pStreet)
{
    street = pStreet;
}

// Sets value from parameter
void Address::setPostcode(std::string pPostcode)
{
    postcode = pPostcode;
}

// Sets value from parameter
void Address::setCity(std::string pCity)
{
    city = pCity;
}

// Returns value from input
std::string Address::getStreet() const
{
    return street;
}

// Returns value from input
std::string Address::getPostcode() const
{
    return postcode;
}

// Returns value from input
std::string Address::getCity() const
{
    return city;
}

// Prints class Address
void printAddress(Address const &Address)
{
    cout << endl;
    cout << "ADDRESS:" << endl;
    cout << "Street: " << Address.getStreet() << endl;
    cout << "Postcode: " << Address.getPostcode() << endl;
    cout << "City: " << Address.getCity() << endl;
}