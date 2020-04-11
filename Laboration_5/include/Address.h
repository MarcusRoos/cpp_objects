//
// Created by Marcus on 2020-02-23.
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

 Registers the address belonging to a person, the members of this class would
 be street, postcode and city. The public members are used to both set these
 class members, as well as get them, to either give them a value or to show
 this value.
 */
class Address
{
private:
    std::string street, postcode, city; // Class members of type string
public:

    /**
    * Default constructor of the class Address
    *
    * @param None.
    * @return None.
    */
    Address();

    /**
    * Constructor for initialization of class Address
    *
    * @param String pStreet, pPostcode, pCity.
    * @return None.
    */
    Address(std::string pStreet, std::string pPostcode, std::string pCity);

    /**
    * Sets value for class member street
    *
    * @param String pStreet.
    * @return None.
    */
    void setStreet(std::string pStreet);

    /**
    * Sets value for class member postcode
    *
    * @param String pPostcode.
    * @return None.
    */
    void setPostcode(std::string pPostcode);

    /**
    * Sets value for class member street
    *
    * @param String pCity.
    * @return None.
    */
    void setCity(std::string pCity);

    /**
    * Returns value for class member street
    *
    * @param None.
    * @return street.
    */
    std::string getStreet() const;

    /**
    * Returns value for class member postcode
    *
    * @param None.
    * @return postcode.
    */
    std::string getPostcode() const;

    /**
    * Returns value for class member city
    *
    * @param None.
    * @return city.
    */
    std::string getCity() const;

/**
* Overloads operator < ( less than )
*
* @param Constant reference of class Address.
* @return 0/1.
*/
    bool operator < (const Address& a) const;

/**
* Overloads operator == ( comparison )
*
* @param Constant reference of class Address.
* @return 0/1.
*/
    bool operator == (const Address& a) const;

}; // End of class Address definition

/**
 * Prints the class Address and its class members.
 *
 * @param Constant class Address.
 * @return None.
 */
void printAddress(Address const &address);

/**
* Overloads operator << ( out stream )
*
* @param Constant reference of class Address, out stream os.
* @return os.
*/
std::ostream &operator<<(std::ostream &os, const Address &address);

/**
* Overloads operator >> ( in stream )
*
* @param Constant reference of class Address, in stream is.
* @return is.
*/
std::istream &operator>>(std::istream &is, const Address &address);

#endif