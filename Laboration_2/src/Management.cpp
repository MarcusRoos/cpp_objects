//
// Created by Marcus on 2020-02-01.
//

#include "Management.h"
using std::cout;

/**
 * Main Menu, request user input and returns the answer as an integer, using
 * built in validation to make sure the integer is either 1, 2 or 3.
 * If input is invalid, enter a loop and loop until input is valid.
 **/
int mainMenu(){
    cout << "What would you like to do?\n\n";
    cout << "1. Add a person.\n";
    cout << "2. List all persons.\n";
    cout << "3. Quit.\n";
    int choice=0;
    std::cin >> choice;
    while (choice<1 || choice>3){
        std::cout << "Wrong input\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;
    }
    return choice;
}

/**
 * Add person function, requests user to input several different values which
 * will be stored in the parameters vector. Will validate every input to make
 * sure it is valid, if input is not valid it will enter a loop until it is,
 * afterwards continue to the next input until everything has been answered.
 * Returns vector once done.
 **/
std::vector<Person>addPerson(std::vector<Person>input){

    std::cout << "Enter the persons first name.\n";
    std::string firstName;
    firstName=validate(firstName); // Call function to validate
    std::cout << "Enter the persons last name.\n";
    std::string lastName;
    lastName=validate(lastName); // Call function to validate
    std::cout << "Enter the persons street address.\n";
    std::string street;
    std::getline(std::cin >> std::ws, street); // Read until EOL
    std::cout << "Enter the persons postcode (5 characters).\n";
    std::string postcode;
    std::cin >> postcode;
    while (postcode.length() <5 || postcode.length() >5){
        std::cout << "Wrong input.\n";
        std::cin >> postcode;
    }
    std::cout << "Enter the persons city.\n";
    std::string city;
    city=validate(city); // Call function to validate
    std::cout << "Enter the persons social security number (4 characters).\n";
    std::string personNumber;
    std::cin >> personNumber;
    while (personNumber.length() <4 || personNumber.length() >4){
        std::cout << "Wrong input.\n";
        std::cin >> personNumber;
    }
    std::cout << "Enter the persons shoesize.\n";
    int shoeSize;
    std::cin >> shoeSize;
    while (std::cin.fail() || shoeSize<15 || shoeSize>50) { // If fail, request new input
        cout << "You did not enter a correct shoe size between 15 and 50.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> shoeSize;
    }

    Names names(firstName,lastName);
    Address address(street,postcode,city);
    Person person(names, address, personNumber, shoeSize);
    input.push_back(person);

    // Move vector as to reduce strain on memory
    return {std::move(input)};
}

/**
 * Function to print elements within the vector, will use the parameter vector
 * as a constant and iterate through it to print out all the elements.
 **/
void print(const std::vector<Person>&printVec){
    for (const auto &i : printVec) {
        printPerson(i); // Call function to print class
    }
}

/**
 * Pause function, will take parameter string and print out as text, pauses
 * program until user press a key.
 **/
void pauseFunction(const std::string& text){ /* Function used when program
 * should wait for user input before it continues */
    std::cout << text; // Prints function parameter on screen
    std::cin.clear(); // Clear stream
    std::cin.sync(); // Synchronizes the input stream
    std::cin.get(); // Waits for user input before it continues
    std::cin.clear(); // Clear stream once again to remove leftovers
    std::cin.sync(); // Synchronizes the input stream
}

/**
 * Validates user input, will take a string as parameter, run it through the
 * chain to make sure it only contain alphabetic characters or spaces. If
 * everything is fine it will return the input as a string, if not, it will
 * continue the loop and request new user input.
 **/
std::string validate(std::string input){ // Validate input
    bool valid;
    do {
        std::getline(std::cin >> std::ws, input);
        valid = true;
        for (std::size_t i{}; i < input.length() && valid; ++i) { /*Iterates
 * through inputs length, checks if input is either a letter or a space,
 * anything else is considered invalid*/
            if (!(std::isalpha(static_cast<unsigned char>(input[i])) ||
                  std::isspace(static_cast<unsigned char>(input[i])))) {
                valid = false;
                std::cout << "Invalid input\n";
            }
        }
    } while (!valid);
    return input;
}