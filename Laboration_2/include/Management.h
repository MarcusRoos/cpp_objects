//
// Created by Marcus on 2020-02-01.
//

#ifndef DT019G_MANAGEMENT_H
#define DT019G_MANAGEMENT_H
#include "Address.h"
#include "Names.h"
#include "Person.h"

#include <limits>

void printPerson(Person const &person); // Return nothing, param Person
int mainMenu(); // Return int, no param
void pauseFunction(const std::string& text); // Return nothing, param string
// Return vector, param vector
std::vector<Person>addPerson(std::vector<Person>input);
std::string validate(std::string input); // Return string, param string
void print(const std::vector<Person>&printVec); // Return nothing, param vector

#endif //DT019G_MANAGEMENT_H
