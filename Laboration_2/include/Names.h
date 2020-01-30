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
class Names
{
private:
    std::string firstName, lastName; // Datamedlemmar string lastName;
public:
    Names(); //Förvald konstruktor
    Names(std::string pFirstName, std::string pLastName);
    void setFirstName(std::string pFirstName); // Medlemsfunktioner som sätter void setLastName(string pLastName); // värden på datamedlemmar void setAccountNr(string pAccountNr);
    void setLastName(std::string pLastName);
    std::string getFirstName() const; // Medlemsfunktioner som returnerar string getLastName() const; // datamedlemmars värden
    std::string getLastName() const;
}; // Avslutar definitionen av klassen Account

void printNames(Names const &names);
#endif