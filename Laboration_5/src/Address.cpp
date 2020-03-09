//
// Created by Marcus on 2020-02-29.
//

#include "Address.h"

#include <utility>

using std::cout;
using std::endl;

// Default constructor
Address::Address()
{
    street = "N/A"; postcode = "N/A"; city="N/A";
}

// Initializing constructor
Address::Address(std::string pStreet, std::string pPostcode, std::string pCity)
{
    street = std::move(pStreet); postcode = std::move(pPostcode); city = std::move(pCity);
}

// Sets street address
void Address::setStreet(std::string pStreet)
{
    street = std::move(pStreet);
}

// Sets postcode
void Address::setPostcode(std::string pPostcode)
{
    postcode = std::move(pPostcode);
}

// Sets city
void Address::setCity(std::string pCity)
{
    city = std::move(pCity);
}

// Gets street
std::string Address::getStreet() const
{
    return street;
}

// Gets postcode
std::string Address::getPostcode() const
{
    return postcode;
}

// Gets city
std::string Address::getCity() const
{
    return city;
}

// Prints class Address
void printAddress(Address const &Address)
{
    cout << "Street: " << Address.getStreet() << endl;
    cout << "Postcode: " << Address.getPostcode() << endl;
    cout << "City: " << Address.getCity() << endl;
}

// Defines operator <<, used for out stream
std::ostream &operator<<(std::ostream &os, const Address &address){
    os << address.getStreet() << '|' << address.getPostcode() << '|'
       << address.getCity() << '|';
    return os;
}

// Defines operator >>, used for in stream
std::istream &operator>>(std::istream &is, Address &address){
    std::string tmpString;
    getline(is,tmpString,'|');
    address.setStreet(tmpString);
    getline(is,tmpString,'|');
    address.setPostcode(tmpString);
    getline(is,tmpString,'|');
    address.setCity(tmpString);

    return is;
}

// Defines operator <
bool Address::operator < (const Address& a) const
{
    if (city == a.city) { // Comparison, if true;
        return street < a.street; // Return street in descending order
    }
    else {
        return city < a.city; // If not true, return city
    }
}

// Defines operator ==
bool Address::operator == (const Address& a) const
{
    return city == a.city && street == a.street; // If equals true
}