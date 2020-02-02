//
// Created by Marcus on 2020-01-30.
//

#include "Address.h"

#include <utility>

using std::cout;
using std::endl;


Address::Address()
{
    street = "N/A"; postcode = "N/A"; city="N/A";
}

Address::Address(std::string pStreet, std::string pPostcode, std::string pCity)
{
    street = std::move(pStreet); postcode = std::move(pPostcode); city = std::move(pCity);
}

void Address::setStreet(std::string pStreet)
{
    street = std::move(pStreet);
}

void Address::setPostcode(std::string pPostcode)
{
    postcode = std::move(pPostcode);
}

void Address::setCity(std::string pCity)
{
    city = std::move(pCity);
}

std::string Address::getStreet() const
{
    return street;
}

std::string Address::getPostcode() const
{
    return postcode;
}

std::string Address::getCity() const
{
    return city;
}

void printAddress(Address const &Address)
{
    cout << endl;
    cout << "ADDRESS:" << endl;
    cout << "Street: " << Address.getStreet() << endl;
    cout << "Postcode: " << Address.getPostcode() << endl;
    cout << "City: " << Address.getCity() << endl;
}