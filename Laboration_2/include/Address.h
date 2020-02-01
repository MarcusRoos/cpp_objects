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
/**
 Class Address
 */
class Address
{
private:
    std::string street, postcode, city; // Class members
public:
    Address(); //Default constructor
    //Initialized constructor, take 3 values, street, postcode and city, string.
    Address(std::string pStreet, std::string pPostcode, std::string pCity);
    void setStreet(std::string pStreet); // Returns nothing, require string
    void setPostcode(std::string pPostcode); // Returns nothing, require string
    void setCity(std::string pCity); // Returns nothing, require string
    std::string getStreet() const; // Returns string street, no parameter.
    std::string getPostcode() const; // Returns string street, no parameter.
    std::string getCity() const; // Returns string street, no parameter.
}; // End of class Address definition

void printAddress(Address const &address);  // Returns nothing, Address parameter.
#endif