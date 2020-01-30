//
// Created by Marcus on 2020-01-30.
//

#ifndef DT018G_Address_H
#define DT018G_Address_H
    #include <string>
    #include <iostream>
//------------------------------------------------------------------------------
// Class definition
//------------------------------------------------------------------------------
class Address
{
private:
    std::string street, postcode, city; // Class members
public:
    Address(); //Förvald konstruktor
    Address(std::string pStreet, std::string pPostcode, std::string pCity);
    void setStreet(std::string pStreet); // Medlemsfunktioner som sätter void setLastName(string pLastName); // värden på datamedlemmar void setAccountNr(string pAccountNr);
    void setPostcode(std::string pPostcode);
    void setCity(std::string pCity);
    std::string getStreet() const; // Medlemsfunktioner som returnerar string getLastName() const; // datamedlemmars värden
    std::string getPostcode() const;
    std::string getCity() const;
}; // Avslutar definitionen av klassen Account

void printAddress(Address const &address);
#endif