//
// Created by Marcus on 2020-03-06.
//

#ifndef DT019G_MANAGEMENT_H
#define DT019G_MANAGEMENT_H

#include <string>
#include <vector>
#include "Person.h"

void pauseFunction(const std::string& text);
std::vector<Person>addPerson(std::vector<Person>input);
std::string validate(std::string input);
std::string validateFileName(std::string input);

#endif //DT019G_MANAGEMENT_H
