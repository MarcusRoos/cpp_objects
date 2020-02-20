#include "Prototypes.h"
//#include "memstat.hpp" Doesn't work on W10 64bit.
#include <iostream>
#include <iomanip>
#include <chrono>

int main() {
    const size_t five = 5000, ten=10000, fifteen=15000, twenty=20000,
            twentyfive=25000, thirty=30000, thirtyfive=35000, forty=40000;
    size_t size=0;

    for (size_t k=0; k<8; k++) {
        if (k == 0)
            size = five;
        if (k == 1)
            size = ten;
        if (k == 2)
            size = fifteen;
        if (k == 3)
            size = twenty;
        if (k == 4)
            size = twentyfive;
        if (k == 5)
            size = thirty;
        if (k == 6)
            size = thirtyfive;
        if (k == 7)
            size = forty;
        assignmentFunction(size);
    }
    return 0;
}
