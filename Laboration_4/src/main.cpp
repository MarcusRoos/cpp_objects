#include "Prototypes.h"
//#include "memstat.hpp" Doesn't work on W10 64bit.
#include <iostream>
#include <iomanip>
#include <chrono>

int main() {
    const size_t five = 5000, ten=10000, fifteen=15000, twenty=20000,
            twentyfive=25000, thirty=30000, thirtyfive=35000, forty=40000;
    int sort=0;
    /* Will call the function 8 times per lap, to get every size for every
     * sorting method. */
    while (sort<4) {
        assignmentFunction(five, sort);
        assignmentFunction(ten, sort);
        assignmentFunction(fifteen, sort);
        assignmentFunction(twenty, sort);
        assignmentFunction(twentyfive, sort);
        assignmentFunction(thirty, sort);
        assignmentFunction(thirtyfive, sort);
        assignmentFunction(forty, sort);
        sort++;
    }
    // Inform user the program is done, request key press to exit.
    pauseFunction("Press any key to exit the program.");
    return 0;
}
