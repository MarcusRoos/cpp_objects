//
// Created by Marcus on 2020-02-01.
//

#ifndef DT019G_MANAGEMENT_H
#define DT019G_MANAGEMENT_H
#include "Address.h"
#include "Names.h"
#include "Person.h"

#include <limits>

/**
* Function to print person as constant of Person
*
* @param Reference to class Person.
* @return None.
*/
void printPerson(Person const &person);

/**
* Main menu, lets user tell the program what to do, either add a new person, or
* print every person stored, or quit the program.
*
* @param None.
* @return integer choice.
*/
int mainMenu();

/**
* Pause function, awaits user input before proceeding, will print a text
* message before to tell user what happened and why it paused.
*
* @param string text.
* @return None.
*/
void pauseFunction(const std::string& text);

/**
* Function to add person to the vector, will request user to input values which
* will later be stored in another vector and returned.
*
* @param Vector of type Person, called input.
* @return Vector of type Person.
*/
std::vector<Person>addPerson(std::vector<Person>input);

/**
* Function to validate user input, will only allow alphabetic characters and
* spaces to be entered, otherwise a loop will start until input is valid.
*
* @param String called input.
* @return String called with valid input.
*/
std::string validate(std::string input);

/**
 * Prints the class Person and its class members.
 *
 * @param Constant class Person.
 * @return None.
 */
void print(const std::vector<Person>&printVec);

/**
 * Clears the console of text.
 *
 * @param None.
 * @return None.
 */
void clearScreen();

std::string validateFileName(std::string input);

#endif //DT019G_MANAGEMENT_H
