//
// Created by Marcus on 2020-02-01.
//

#ifndef DT019G_MANAGEMENT_H
#define DT019G_MANAGEMENT_H
#include "Address.h"
#include "Names.h"
#include "Person.h"

#include <limits>

void printPerson(Person const &person);
int mainMenu();
void pauseFunction(const std::string& text);
std::vector<Person>addPerson(std::vector<Person>input);
std::string validate(std::string input);
void print(const std::vector<Person>&printVec);

#endif //DT019G_MANAGEMENT_H
