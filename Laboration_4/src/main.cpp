#include "Prototypes.h"
#include "FillArray.h"
//#include "memstat.hpp" Doesn't work on W10 64bit.
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>

int main() {

    std::cout << "Measuring ten times." << std::endl;
    FillFive();
    for (int i=0; i<10; i++) {
        auto timeStart = std::chrono::high_resolution_clock::now();
        auto timeEnd = std::chrono::high_resolution_clock::now();
        std::cout << std::fixed << std::setprecision(6);
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                timeEnd - timeStart).count();
        double seconds = 1.0 * duration / 1000;
        std::cout << "Duration = "
                  << seconds
                  << " [s]" << std::endl;
    }
    return 0;
}
