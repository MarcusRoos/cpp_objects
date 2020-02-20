#include "Prototypes.h"
//#include "memstat.hpp" Doesn't work on W10 64bit.
#include <iostream>
#include <iomanip>
#include <chrono>

int main() {
    const size_t five = 5000, ten=10000, fifteen=15000, twenty=20000,
            twentyfive=25000, thirty=30000, thirtyfive=35000, forty=40000;

    for (int sort=0; sort<4; sort++) {
        assignmentFunction(five, sort);
        assignmentFunction(ten, sort);
        assignmentFunction(fifteen, sort);
        assignmentFunction(twenty, sort);
        assignmentFunction(twentyfive, sort);
        assignmentFunction(thirty, sort);
        assignmentFunction(thirtyfive, sort);
        assignmentFunction(forty, sort);
    }

    return 0;
}
